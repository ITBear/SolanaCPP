#pragma once

#include "Enentities_global.hpp"

namespace Sol::Core::DataModel {

GP_ENUM(SOL_CORE_DATA_MODEL_ENTITIES_API, EncodingType,
    json        = 0,
    jsonParsed  = 1,
    base58      = 2,
    base64      = 3
);

}//namespace Sol::Core::DataModel
