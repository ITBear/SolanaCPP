#pragma once

#include "../LightWalletCore_global.hpp"

namespace Sol::Core::LightWallet {

GP_ENUM(SOL_CORE_LIGHT_WALLET_CORE_API, SystemInstruction,
    CREATE_ACCOUNT          = 0,
    ASSIGN                  = 1,
    TRANSFER                = 2,
    CREATEACCOUNTWITHSEED   = 3,
    ADVANCENONCEACCOUNT     = 4,
    WITHDRAWNONCEACCOUNT    = 5,
    INITIALIZENONCEACCOUNT  = 6,
    AUTHORIZENONCEACCOUNT   = 7,
    ALLOCATE                = 8,
    ALLOCATEWITHSEED        = 9,
    ASSIGNWITHSEED          = 10,
    TRANSFERWITHSEED        = 11
);

}//namespace Sol::Core::LightWallet
