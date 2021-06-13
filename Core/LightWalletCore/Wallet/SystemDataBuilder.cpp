#include "SystemDataBuilder.hpp"

namespace Sol::Core::LightWallet {

//https://docs.rs/solana-sdk/1.7.1/solana_sdk/system_instruction/enum.SystemInstruction.html

GpBytesArray    SystemDataBuilder::SCreateAccount
(
    const lamport_t     aLamports,
    const size_byte_t   aSpace,
    const GpRawPtrByteR aProgramId
)
{
    GpBytesArray                    data;
    GpByteWriterStorageByteArray    dataStorage(data);
    GpByteWriter                    dataWriter(dataStorage);

    //instruction (4 bytes)
    dataWriter.UInt32(BitOps::H2N(u_int_32(SystemInstruction::CREATE_ACCOUNT)));

    //lamports (8 bytes)
    dataWriter.SInt64(BitOps::H2N(aLamports.As<s_int_64>()));

    //space (8 bytes)
    dataWriter.SInt64(BitOps::H2N(aSpace.As<s_int_64>()));

    //programId
    dataWriter.Bytes(aProgramId);

    return data;
}

GpBytesArray    SystemDataBuilder::SAssign (const GpRawPtrByteR aProgramId)
{
    GpBytesArray                    data;
    GpByteWriterStorageByteArray    dataStorage(data);
    GpByteWriter                    dataWriter(dataStorage);

    //programId
    dataWriter.Bytes(aProgramId);

    return data;
}

GpBytesArray    SystemDataBuilder::STransfer (const lamport_t aLamports)
{
    GpBytesArray                    data;
    GpByteWriterStorageByteArray    dataStorage(data);
    GpByteWriter                    dataWriter(dataStorage);

    //instruction (4 bytes)
    dataWriter.UInt32(BitOps::H2N(u_int_32(SystemInstruction::TRANSFER)));

    //lamports (8 bytes)
    dataWriter.SInt64(BitOps::H2N(aLamports.As<s_int_64>()));

    return data;
}

}//namespace Sol::Core::LightWallet
