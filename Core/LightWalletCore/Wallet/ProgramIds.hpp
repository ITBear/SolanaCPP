#pragma once

#include "../LightWalletCore_global.hpp"

namespace Sol::Core::LightWallet {

class SOL_CORE_LIGHT_WALLET_CORE_API ProgramIds
{
    CLASS_REMOVE_CTRS(ProgramIds);

public:
    static const GpBytesArray&  SId (Sol::Core::DataModel::BuiltinProgramId::EnumT aBuiltinProgramId);

private:
    static const GpArray<GpBytesArray, Sol::Core::DataModel::BuiltinProgramId::SCount().As<size_t>()>   sBuiltinProgramIds;
};

}//namespace Sol::Core::LightWallet
