#pragma once

#include "Enentities_global.hpp"

namespace Sol::Core::DataModel {

GP_ENUM(SOL_CORE_DATA_MODEL_ENTITIES_API, Commitment,
    finalized   = 0,
    confirmed   = 1,
    processed   = 2
);

}//namespace Sol::Core::DataModel
