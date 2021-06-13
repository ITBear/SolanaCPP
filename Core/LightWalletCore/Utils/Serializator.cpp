#include "Serializator.hpp"

namespace Sol::Core::LightWallet {

GpBytesArray    Serializator::SSerialize (const Transaction& aTransaction)
{
    GpBytesArray                                serializedTransactionData;
    serializedTransactionData.reserve(2048);
    GpByteWriterStorageByteArray                serializedTransactionDataStorage(serializedTransactionData);
    GpByteWriter                                serializedTransactionDataWriter(serializedTransactionDataStorage);

    SSerialize(aTransaction, serializedTransactionDataWriter);

    return serializedTransactionData;
}

GpBytesArray    Serializator::SSerializeNoSig (const Transaction& aTransaction)
{
    GpBytesArray                                serializedTransactionData;
    serializedTransactionData.reserve(2048);
    GpByteWriterStorageByteArray                serializedTransactionDataStorage(serializedTransactionData);
    GpByteWriter                                serializedTransactionDataWriter(serializedTransactionDataStorage);

    SSerializeNoSig(aTransaction, serializedTransactionDataWriter);

    return serializedTransactionData;
}

void    Serializator::SSerialize
(
    const   Transaction&    aTransaction,
    GpByteWriter&           aWriter
)
{
    SSerialize(aTransaction.signatures, aWriter, false);
    SSerialize(aTransaction.message_serialized, aWriter, false);
}

void    Serializator::SSerializeNoSig
(
    const Transaction&  aTransaction,
    GpByteWriter&       aWriter
)
{
    SSerialize(aTransaction.message_serialized, aWriter, false);
}

void    Serializator::SSerialize
(
    const Sol::Core::DataModel::MessageDesc&    aMessage,
    GpByteWriter&                               aWriter
)
{
    SSerialize(aMessage.header, aWriter);
    SSerialize(aMessage.account_keys, aWriter, false);
    SSerialize(aMessage.recent_blockhash, aWriter, false);
    SSerialize(aMessage.instructions, aWriter);
}

void    Serializator::SSerialize
(
    const Sol::Core::DataModel::MessageHeaderDesc&  aMessageHeader,
    GpByteWriter&                                   aWriter
)
{
    aWriter.UInt8(aMessageHeader.num_required_signatures.As<u_int_8>());
    aWriter.UInt8(aMessageHeader.num_readonly_signed_accounts.As<u_int_8>());
    aWriter.UInt8(aMessageHeader.num_readonly_unsigned_accounts.As<u_int_8>());
}

void    Serializator::SSerialize
(
    const GpVector<Sol::Core::DataModel::InstructionDesc::SP>&  aInstructions,
    GpByteWriter&                                               aWriter
)
{
    aWriter.CompactUInt16(NumOps::SConvert<u_int_16>(aInstructions.size()));
    for (const Sol::Core::DataModel::InstructionDesc::SP& instruction: aInstructions)
    {
        SSerialize(instruction.VC(), aWriter);
    }
}

void    Serializator::SSerialize
(
    const Sol::Core::DataModel::InstructionDesc&    aInstruction,
    GpByteWriter&                                   aWriter
)
{
    aWriter.UInt8(aInstruction.program_id_index.As<u_int_8>());
    SSerialize(aInstruction.accounts, aWriter);
    SSerialize(aInstruction.data, aWriter, true);
}

void    Serializator::SSerialize
(
    const GpBytesArray& aByteBuffer,
    GpByteWriter&       aWriter,
    const bool          aWriteLen
)
{
    if (aWriteLen)
    {
        aWriter.CompactUInt16(NumOps::SConvert<u_int_16>(aByteBuffer.size()));
    }

    aWriter.Bytes(aByteBuffer);
}

void    Serializator::SSerialize
(
    const GpVector<GpBytesArray>&   aArrayOfBuffers,
    GpByteWriter&                   aWriter,
    const bool                      aWriteElementLen
)
{
    aWriter.CompactUInt16(NumOps::SConvert<u_int_16>(aArrayOfBuffers.size()));
    for (const GpBytesArray& buffer: aArrayOfBuffers)
    {
        SSerialize(buffer, aWriter, aWriteElementLen);
    }
}

void    Serializator::SSerialize
(
    const GpVector<count_t>&    aArrayOfIdx,
    GpByteWriter&               aWriter
)
{
    aWriter.CompactUInt16(NumOps::SConvert<u_int_16>(aArrayOfIdx.size()));
    for (const count_t& idx: aArrayOfIdx)
    {
        aWriter.UInt8(idx.As<u_int_8>());
    }
}

}//Sol::Core::LightWallet
