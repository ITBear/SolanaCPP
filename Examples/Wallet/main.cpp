#include "Wallet_global.hpp"
#include <iostream>

using namespace GPlatform;
using namespace Sol::Core;
using namespace Sol::Core::LightWallet;
using namespace Sol::Core::API::RPC;

int main()
{
    std::cout << "************************************************************************\n";
    std::cout << "Init crypto core...\n";//--------------------------------------------
        GpCryptoCore::SInit();

    std::cout << "************************************************************************\n";
    std::cout << "Create new wallet...\n";//--------------------------------------------
        Wallet::SP wallet = MakeSP<Wallet>();

    std::cout << "************************************************************************\n";
    std::cout << "Create new address from random seed...\n";//--------------------------------------------
        GpCryptoAddress::SP address1 = wallet->GenerateNextRndAddr();
        address1->SetName("Random address 1"_sv);
        std::cout << "Address '" << address1->Name() << "': " << address1->AddrStr() << "\n";

    std::cout << "************************************************************************\n";
    std::cout << "Create new HD group from seed phrase...\n";//--------------------------------------------
        GpCryptoAddressGroup::SP hdGroup1 = wallet->AddHDGroup("duck cup organ letter broom enrich outdoor divorce skate damage repeat anchor match spot blouse produce observe army start lounge gauge simple tragic spray"_sv, ""_sv);

    std::cout << "************************************************************************\n";
    std::cout << "Create new address from HD group...\n";//--------------------------------------------
        GpCryptoAddress::SP address2 = wallet->GenerateNextHDAddr(hdGroup1->UID());
        address2->SetName("HD address 2"_sv);
        std::cout << "Address '" << address2->Name() << "': " << address2->AddrStr() << "\n";

    std::cout << "************************************************************************\n";
    std::cout << "Create API client...\n";//--------------------------------------------
        ApiClient::SP apiCli = MakeSP<ApiClient>("https://api.testnet.solana.com"_sv);

    std::cout << "************************************************************************\n";
    std::cout << "Claim airdrop from testnet...\n";//--------------------------------------------
    {
        std::string claimTxSigBase58 = apiCli->RequestAirdrop(address1->AddrStr(), 1000000000_lamport);

        TransactionDesc::SP claimTxDesc;

        while (claimTxDesc.IsNULL())
        {
            std::cout << "Wait for airdrop...\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            claimTxDesc = apiCli->GetTransaction(claimTxSigBase58, EncodingType::base64, Commitment::finalized);
        }
    }

    std::cout << "************************************************************************\n";
    std::cout << "Transfer SOL from '" << address1->AddrStr() << "' to '" << address2->AddrStr() + "'...\n";
    {
        //Get recent block hash desc (as nonce)
        GetRecentBlockhashRsData::SP recentBlockhashDesc = apiCli->GetRecentBlockhash(Commitment::finalized);

        //Make transfer transaciton
        Transaction::SP transaction = TransactionBuilder::SNew()
            .MessageHeader(1_cnt, 0_cnt, 1_cnt)
            .AddAccountKey(address1->Addr())
            .AddAccountKey(address2->Addr())
            .AddAccountKey(ProgramIds::SId(BuiltinProgramId::SYSTEM))
            .RecentBlockhash(GpBase58::SDecodeToByteArray(recentBlockhashDesc->value.blockhash, GpBase58Alphabet::NAKAMOTO))
            .InstructionBegin()
                .ProgramIdIndex(2_cnt)
                .AddAccountIdIndex(0_cnt)
                .AddAccountIdIndex(1_cnt)
                .Data(SystemDataBuilder::STransfer(1000_lamport))
            .InstructionEnd()
            .AddSign(address1.VC())
            .Build();

        //Serialize transaction
        GpBytesArray        txData = Serializator::SSerialize(transaction.VC());
        const std::string   txDataBase58 = GpBase58::SEncodeToStr(txData, GpBase58Alphabet::NAKAMOTO);
        std::string transferTxSigBase58 = apiCli->SendTransaction(txDataBase58);
    }

    std::cout << "************************************************************************\n";
    std::cout << "Destroy wallet...\n";
    wallet.Clear();

    std::cout << "************************************************************************\n";
    std::cout << "Clear crypto core...\n";
    GpCryptoCore::SClear();

    std::cout << "Done\n";
    std::cout.flush();

    return 0;
}
