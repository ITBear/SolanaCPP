#pragma once

#include "../Api_global.hpp"

namespace Sol::Core::API::RPC {

//----------------------------- RQ -----------------------------
using getVersion_rq_data = GpApiVoidDesc::SP;

JSON_RPC_API_RQ(SOL_CORE_DATA_MODEL_API_API, getVersion, "c33b8cdf-273b-493c-ad57-40736b81c480"_sv)

//----------------------------- RS -----------------------------

using getVersion_rs_data = VersionDesc::SP;

JSON_RPC_API_RS(SOL_CORE_DATA_MODEL_API_API, getVersion, "59e206eb-22ec-4953-87ef-8a89b64d86d6"_sv)

}//namespace Sol::Core::API::RPC
