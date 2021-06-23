#pragma once

#include "../Api_global.hpp"

namespace Sol::Core::API::RPC {

//----------------------------- RQ -----------------------------
using getTransactionCount_rq_data = GpApiVoidDesc::SP;

JSON_RPC_API_RQ(SOL_CORE_DATA_MODEL_API_API, getTransactionCount, "6a4747ac-dc5b-46a2-9850-6e77cf8d4998"_sv)

//----------------------------- RS -----------------------------
using getTransactionCount_rs_data = count_t;

JSON_RPC_API_RS(SOL_CORE_DATA_MODEL_API_API, getTransactionCount, "ec771dc9-973d-437b-b5c6-c4ac590308fb"_sv)

}//namespace Sol::Core::API::RPC
