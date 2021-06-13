#pragma once

#include "../Api_global.hpp"

namespace Sol::Core::API::RPC {

//----------------------------- RQ -----------------------------
using sendTransaction_rq_data = GpVector<std::string>;

JSON_RPC_API_RQ(SOL_CORE_DATA_MODEL_API_API, sendTransaction, "08f1e052-1c32-4036-806b-6320faadfb5d"_sv)

//----------------------------- RS -----------------------------
using sendTransaction_rs_data = std::string;

JSON_RPC_API_RS(SOL_CORE_DATA_MODEL_API_API, sendTransaction, "7b70846e-6628-4fdc-ae66-6844e4621847"_sv)

}//namespace Sol::Core::API::RPC
