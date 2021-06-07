#pragma once

#include "Enentities_global.hpp"

namespace Sol::Core::DataModel {

GP_ENUM(SOL_CORE_DATA_MODEL_ENTITIES_API, NetworkType,
    MAINNET = 0,
    TESTNET = 1,
    DEVNET  = 2
);

}//namespace Sol::Core::DataModel
