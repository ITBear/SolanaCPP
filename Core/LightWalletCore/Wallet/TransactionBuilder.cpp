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

Transaction::SP TransactionBuilder::Build (void)
{
    SerializeMessage();

    return std::move(iTransaction);
}

TransactionBuilder& TransactionBuilder::MessageHeader
(
    const count_t aNumRequiredSignatures,
    const count_t aNumReadonlySignedAccounts,
    const count_t aNumReadonlyUnsignedAccounts
)
{
    class Sol::Core::DataModel::MessageHeaderDesc& header = _Transaction().message.header;

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

TransactionBuilder& TransactionBuilder::AddSign (const Address& aAddress)
{
    SerializeMessage();

    //Sign
    Transaction& tx = _Transaction();
    tx.signatures.emplace_back(aAddress.SignData(tx.message_serialized));

    return *this;
}

Transaction&    TransactionBuilder::_Transaction (void)
{
    if (iTransaction.IsNULL())
    {
        iTransaction = MakeSP<Transaction>();
    }

    return iTransaction.Vn();
}

void    TransactionBuilder::SerializeMessage (void)
{
    Transaction& tx = _Transaction();

    if (tx.message_serialized.size() == 0)
    {
        tx.message_serialized.reserve(2048);
        GpByteWriterStorageByteArray    dataStorage(tx.message_serialized);
        GpByteWriter                    dataWriter(dataStorage);

        Serializator::SSerialize(tx.message, dataWriter);
    }
}

}//namespace Sol::Core::LightWallet
