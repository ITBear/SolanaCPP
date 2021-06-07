#pragma once

#include "../../../GPlatform/GpCore2/GpCore.hpp"
#include "../../../GPlatform/GpCryptoCore/GpCryptoCore.hpp"

#include "../DataModel/Entities/Entities.hpp"

#if defined(SOL_CORE_LIGHT_WALLET_CORE_LIBRARY)
    #define SOL_CORE_LIGHT_WALLET_CORE_API GP_DECL_EXPORT
#else
    #define SOL_CORE_LIGHT_WALLET_CORE_API GP_DECL_IMPORT
#endif

using namespace GPlatform;

namespace Sol::Core::LightWallet
{}
