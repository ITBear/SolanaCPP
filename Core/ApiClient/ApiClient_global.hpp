#pragma once

#include "../../../GPlatform/GpCore2/GpCore.hpp"
#include "../../../GPlatform/GpJson/GpJson.hpp"
#include "../../../GPlatform/GpNetwork/GpNetwork.hpp"
#include "../../../GPlatform/GpApi/GpApi.hpp"
#include "../../../GPlatform/GpApiHttp/GpApiHttp.hpp"
#include "../DataModel/Entities/Entities.hpp"
#include "../DataModel/Api/Api.hpp"

#if defined(SOL_CORE_API_CLIENT_LIBRARY)
    #define SOL_CORE_API_CLIENT_API GP_DECL_EXPORT
#else
    #define SOL_CORE_API_CLIENT_API GP_DECL_IMPORT
#endif

using namespace GPlatform;

using namespace GPlatform;
using namespace GPlatform::API::RPC;

namespace Sol::Core::API::RPC {}
