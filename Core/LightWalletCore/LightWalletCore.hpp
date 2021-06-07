#pragma once

#include "Utils/Utils.hpp"
#include "Wallet/Wallet.hpp"

namespace Sol::Core::LightWallet {

class SOL_CORE_LIGHT_WALLET_CORE_API LightWalletCore
{
    CLASS_REMOVE_CTRS(LightWalletCore)

public:
    static void         SInit                   (void);
    static void         SClear                  (void);
};

}//Sol::Core::LightWallet
