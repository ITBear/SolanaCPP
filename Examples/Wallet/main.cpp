#include "Wallet_global.hpp"
#include <iostream>

using namespace GPlatform;
using namespace Sol::Core;
using namespace Sol::Core::LightWallet;
using namespace Sol::Core::API::RPC;

int main()
{
    std::cout << "************************************************************************\n";
    std::cout << "Init crypto core...\n";
        GpCryptoCore::SInit();

    std::cout << "************************************************************************\n";
    std::cout << "Create new wallet...\n";
        Wallet::SP wallet = MakeSP<Wallet>();

    std::cout << "************************************************************************\n";
    std::cout << "Create new address from random seed...\n";
        GpCryptoAddress::SP address1 = wallet->GenerateNextRndAddr();
        address1->SetName("Random address 1"_sv);
        std::cout << "Address '" << address1->Name() << "': " << address1->AddrStr() << "\n";

    std::cout << "************************************************************************\n";
    std::cout << "Create new HD group from seed phrase...\n";
        GpCryptoAddressGroup::SP hdGroup1 = wallet->AddHDGroup("duck cup organ letter broom enrich outdoor divorce skate damage repeat anchor match spot blouse produce observe army start lounge gauge simple tragic spray"_sv, ""_sv);

    std::cout << "************************************************************************\n";
    std::cout << "Create new address from HD group...\n";
        GpCryptoAddress::SP address2 = wallet->GenerateNextHDAddr(hdGroup1->UID());
        address2->SetName("HD address 2"_sv);
        std::cout << "Address '" << address2->Name() << "': " << address2->AddrStr() << "\n";

    std::cout << "************************************************************************\n";
    std::cout << "Create API client...\n";
        ApiClient::SP apiCli = MakeSP<ApiClient>("https://api.testnet.solana.com"_sv);

    std::cout << "************************************************************************\n";
    std::cout << "Get Solana node version...\n";
        VersionDesc::SP version = apiCli->GetVersion();
        std::cout << "version: feature_set = " << version->feature_set << ", solana_core = " << version->solana_core << "\n";

    std::cout << "************************************************************************\n";
    std::cout << "Get node transactions count...\n";
        const count_t nodeTransactionsCount = apiCli->GetTransactionCount();
        std::cout << "node transactions count = " << nodeTransactionsCount.Value() << "\n";

    std::cout << "************************************************************************\n";
    std::cout << "Claim airdrop from testnet...\n";
    {
        std::string claimTxSigBase58 = apiCli->RequestAirdrop(address1->AddrStr(), 1000000000_lamport);

        TransactionResultDesc::SP claimTxResDesc;

        while (claimTxResDesc.IsNULL())
        {
            std::cout << "Wait for airdrop...\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            claimTxResDesc = apiCli->GetTransaction(claimTxSigBase58, Commitment::finalized);
        }
    }

    std::cout << "************************************************************************\n";
    std::cout << "Get balance '" << address1->AddrStr() << "'...\n";
    {
        GetBalanceRsData::SP balanceRes = apiCli->GetBalance(address1->AddrStr(), Commitment::finalized);
        std::cout << "Balance '" << address1->AddrStr() << "' = " << balanceRes->value.As<s_int_64>() << " lamports\n";
    }

    std::cout << "Get balance '" << address2->AddrStr() << "'...\n";
    {
        GetBalanceRsData::SP balanceRes = apiCli->GetBalance(address2->AddrStr(), Commitment::finalized);
        std::cout << "Balance '" << address2->AddrStr() << "' = " << balanceRes->value.As<s_int_64>() << " lamports\n";
    }

    std::cout << "************************************************************************\n";
    std::cout << "Transfer SOL from '" << address1->AddrStr() << "' to '" << address2->AddrStr() + "'...\n";
    {
        //Get recent block hash desc (as nonce)
        GetRecentBlockhashRsData::SP recentBlockhashDesc = apiCli->GetRecentBlockhash(Commitment::finalized);

        //Make transfer transaciton
        TransactionDesc::SP transaction = TransactionBuilder::SNew()
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
        GpBytesArray        txData              = Serializator::SSerialize(transaction.VC());
        const std::string   txDataBase58        = GpBase58::SEncodeToStr(txData, GpBase58Alphabet::NAKAMOTO);
        const std::string   transferTxSigBase58 = apiCli->SendTransaction(txDataBase58);

        //Wait for finalize
        TransactionResultDesc::SP txResDesc;

        while (txResDesc.IsNULL())
        {
            std::cout << "Wait for finalize...\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            txResDesc = apiCli->GetTransaction(transferTxSigBase58, Commitment::finalized);
        }
    }

    std::cout << "************************************************************************\n";
    std::cout << "Get balance '" << address1->AddrStr() << "'...\n";
    {
        GetBalanceRsData::SP balanceRes = apiCli->GetBalance(address1->AddrStr(), Commitment::finalized);
        std::cout << "Balance '" << address1->AddrStr() << "' = " << balanceRes->value.As<s_int_64>() << " lamports\n";
    }

    std::cout << "Get balance '" << address2->AddrStr() << "'...\n";
    {
        GetBalanceRsData::SP balanceRes = apiCli->GetBalance(address2->AddrStr(), Commitment::finalized);
        std::cout << "Balance '" << address2->AddrStr() << "' = " << balanceRes->value.As<s_int_64>() << " lamports\n";
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
