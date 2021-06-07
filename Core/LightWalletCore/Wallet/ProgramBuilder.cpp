#include "ProgramBuilder.hpp"

namespace Sol::Core::LightWallet {

const GpArray<GpBytesArray, Sol::Core::DataModel::BuiltinProgramId::SCount().As<size_t>()>  ProgramBuilder::sBuiltinProgramIds =
{
    //SYSTEM:  11111111111111111111111111111111
    GpBytesArray({std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00)}),

    //CONFIG: Config1111111111111111111111111111111111111
    GpBytesArray({std::byte(0x03),std::byte(0x06),std::byte(0x4a),std::byte(0xa3),std::byte(0x00),std::byte(0x2f),std::byte(0x74),std::byte(0xdc),std::byte(0xc8),std::byte(0x6e),std::byte(0x43),std::byte(0x31),std::byte(0x0f),std::byte(0x0c),std::byte(0x05),std::byte(0x2a),std::byte(0xf8),std::byte(0xc5),std::byte(0xda),std::byte(0x27),std::byte(0xf6),std::byte(0x10),std::byte(0x40),std::byte(0x19),std::byte(0xa3),std::byte(0x23),std::byte(0xef),std::byte(0xa0),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00)}),

    //STAKE: Stake11111111111111111111111111111111111111
    GpBytesArray({std::byte(0x06),std::byte(0xa1),std::byte(0xd8),std::byte(0x17),std::byte(0x91),std::byte(0x37),std::byte(0x54),std::byte(0x2a),std::byte(0x98),std::byte(0x34),std::byte(0x37),std::byte(0xbd),std::byte(0xfe),std::byte(0x2a),std::byte(0x7a),std::byte(0xb2),std::byte(0x55),std::byte(0x7f),std::byte(0x53),std::byte(0x5c),std::byte(0x8a),std::byte(0x78),std::byte(0x72),std::byte(0x2b),std::byte(0x68),std::byte(0xa4),std::byte(0x9d),std::byte(0xc0),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00)}),

    //VOTE: Vote111111111111111111111111111111111111111
    GpBytesArray({std::byte(0x07),std::byte(0x61),std::byte(0x48),std::byte(0x1d),std::byte(0x35),std::byte(0x74),std::byte(0x74),std::byte(0xbb),std::byte(0x7c),std::byte(0x4d),std::byte(0x76),std::byte(0x24),std::byte(0xeb),std::byte(0xd3),std::byte(0xbd),std::byte(0xb3),std::byte(0xd8),std::byte(0x35),std::byte(0x5e),std::byte(0x73),std::byte(0xd1),std::byte(0x10),std::byte(0x43),std::byte(0xfc),std::byte(0x0d),std::byte(0xa3),std::byte(0x53),std::byte(0x80),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00)}),

    //BPF_LOADER: BPFLoader1111111111111111111111111111111111
    GpBytesArray({std::byte(0x02),std::byte(0xa8),std::byte(0xf6),std::byte(0x91),std::byte(0x4e),std::byte(0x88),std::byte(0xa1),std::byte(0x6b),std::byte(0xbd),std::byte(0x23),std::byte(0x95),std::byte(0x85),std::byte(0x5f),std::byte(0x64),std::byte(0x04),std::byte(0xd9),std::byte(0xb4),std::byte(0xf4),std::byte(0x56),std::byte(0xb7),std::byte(0x82),std::byte(0x1b),std::byte(0xb0),std::byte(0x14),std::byte(0x57),std::byte(0x49),std::byte(0x42),std::byte(0x8c),std::byte(0x00),std::byte(0x00),std::byte(0x00),std::byte(0x00)}),

    //KECCAK_SECP2: KeccakSecp256k11111111111111111111111111111
    GpBytesArray({std::byte(0x04),std::byte(0xc6),std::byte(0xfc),std::byte(0x20),std::byte(0xf0),std::byte(0x50),std::byte(0xcc),std::byte(0xf0),std::byte(0x55),std::byte(0x84),std::byte(0xd7),std::byte(0x21),std::byte(0x1c),std::byte(0x9f),std::byte(0x8c),std::byte(0xf5),std::byte(0x9e),std::byte(0xc1),std::byte(0x47),std::byte(0x85),std::byte(0xbb),std::byte(0x16),std::byte(0x6a),std::byte(0x1e),std::byte(0x28),std::byte(0x30),std::byte(0xe8),std::byte(0x12),std::byte(0x20),std::byte(0x00),std::byte(0x00),std::byte(0x00)})
};

const GpBytesArray& ProgramBuilder::SBuiltinProgramId (Sol::Core::DataModel::BuiltinProgramId::EnumT aBuiltinProgramId)
{
    return sBuiltinProgramIds.at(size_t(aBuiltinProgramId));
}

GpBytesArray    ProgramBuilder::SCreateAccount
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
    dataWriter.UInt32(BitOps::H2N(0));

    //lamports (8 bytes)
    dataWriter.SInt64(BitOps::H2N(aLamports.As<s_int_64>()));

    //space (8 bytes)
    dataWriter.SInt64(BitOps::H2N(aSpace.As<s_int_64>()));

    //programId
    dataWriter.Bytes(aProgramId);

    return data;
}

}//namespace Sol::Core::LightWallet
