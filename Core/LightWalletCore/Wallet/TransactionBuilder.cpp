#include "TransactionBuilder.hpp"
#include "../Utils/Serializator.hpp"

namespace Sol::Core::LightWallet {

TransactionBuilder::TransactionBuilder (void) noexcept:
iInstructionBuilder(*this)
{
}

TransactionBuilder::~TransactionBuilder (void) noexcept
{
}

Sol::Core::DataModel::TransactionDesc::SP   TransactionBuilder::Build (void)
{
    return std::move(iTransaction);
}

TransactionBuilder& TransactionBuilder::MessageHeader
(
    const count_t aNumRequiredSignatures,
    const count_t aNumReadonlySignedAccounts,
    const count_t aNumReadonlyUnsignedAccounts
)
{
    Sol::Core::DataModel::MessageHeaderDesc& header = _Transaction().message.header;

    header.num_required_signatures          = aNumRequiredSignatures;
    header.num_readonly_signed_accounts     = aNumReadonlySignedAccounts;
    header.num_readonly_unsigned_accounts   = aNumReadonlyUnsignedAccounts;

    return *this;
}

TransactionBuilder& TransactionBuilder::AddAccountKey (GpRawPtrByteR aPublicKey)
{
    _Transaction().message.account_keys.emplace_back(GpBytesArrayUtils::SMake(aPublicKey));

    return *this;
}

TransactionBuilder& TransactionBuilder::RecentBlockhash (const GpBytesArray& aRecentBlockhash)
{
    _Transaction().message.recent_blockhash = aRecentBlockhash;

    return *this;
}

InstructionBuilder& TransactionBuilder::InstructionBegin (void)
{
    return iInstructionBuilder;
}

TransactionBuilder& TransactionBuilder::AddInstruction (Sol::Core::DataModel::InstructionDesc::SP aInstruction)
{
    _Transaction().message.instructions.emplace_back(std::move(aInstruction));

    return *this;
}

TransactionBuilder& TransactionBuilder::AddSign (const GpCryptoAddress& aAddress)
{
    //Sign
    TransactionT& tx = _Transaction();
    tx.signatures.emplace_back(aAddress.SignData(SerializedMessage()));

    return *this;
}

Sol::Core::DataModel::TransactionDesc&  TransactionBuilder::_Transaction (void)
{
    if (iTransaction.IsNULL())
    {
        iTransaction = MakeSP<TransactionT>();
    }

    return iTransaction.Vn();
}

const GpBytesArray& TransactionBuilder::SerializedMessage (void)
{
    if (iSerializedData.size() == 0)
    {
        iSerializedData.reserve(2048);
        GpByteWriterStorageByteArray    dataStorage(iSerializedData);
        GpByteWriter                    dataWriter(dataStorage);

        Serializator::SSerialize(_Transaction().message, dataWriter);
    }

    return iSerializedData;
}

}//namespace Sol::Core::LightWallet
