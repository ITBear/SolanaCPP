#pragma once

#include "../../../../GPlatform/GpCore2/GpCore.hpp"
#include "../../../../GPlatform/GpNetwork/GpNetwork.hpp"
#include "../../../../GPlatform/GpJson/GpJson.hpp"
#include "../../../../GPlatform/GpApi/GpApi.hpp"

#include "../Entities/Entities.hpp"

#if defined(SOL_CORE_DATA_MODEL_API_LIBRARY)
    #define SOL_CORE_DATA_MODEL_API_API GP_DECL_EXPORT
#else
    #define SOL_CORE_DATA_MODEL_API_API GP_DECL_IMPORT
#endif

using namespace GPlatform;
using namespace GPlatform::API::RPC;

namespace Sol::Core::API::RPC
{}
