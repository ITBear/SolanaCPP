#pragma once

#include "Address.hpp"

namespace Sol::Core::LightWallet {

class SOL_CORE_LIGHT_WALLET_CORE_API ProgramBuilder
{
    CLASS_REMOVE_CTRS(ProgramBuilder);

public:
    static const GpBytesArray&  SBuiltinProgramId   (Sol::Core::DataModel::BuiltinProgramId::EnumT aBuiltinProgramId);

    //System Program: Create accounts and transfer lamports between them
    static GpBytesArray         SCreateAccount      (const lamport_t        aLamports,
                                                     const size_byte_t      aSpace,
                                                     const GpRawPtrByteR    aProgramId);

private:
    static const GpArray<GpBytesArray, Sol::Core::DataModel::BuiltinProgramId::SCount().As<size_t>()>   sBuiltinProgramIds;
};

}//namespace Sol::Core::LightWallet
