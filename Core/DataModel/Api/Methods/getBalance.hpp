#pragma once

#include "../Api_global.hpp"

namespace Sol::Core::API::RPC {

//----------------------------- RQ -----------------------------
class SOL_CORE_DATA_MODEL_API_API GetBalanceRqData final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(GetBalanceRqData)
    CLASS_DECLARE_DEFAULTS(GetBalanceRqData)
    TYPE_STRUCT_DECLARE("e5118a79-ae90-4c73-a335-5a7eca6a2390"_sv)

public:
                        GetBalanceRqData        (void) noexcept;
                        GetBalanceRqData        (std::string_view           aAddrBase58,
                                                 const Commitment::EnumT    aCommitment);
    virtual             ~GetBalanceRqData       (void) noexcept override final;

public:
    std::string         addr_base58;    //Pubkey of account to query, as base-58 encoded string
    CommitmentDesc      commitment;     //Commitment
};

using getBalance_rq_data = GetBalanceRqData::SP;

JSON_RPC_API_RQ(SOL_CORE_DATA_MODEL_API_API, getBalance, "aff87481-0450-42dd-9887-07914157d878"_sv)

//----------------------------- RS -----------------------------
class SOL_CORE_DATA_MODEL_API_API GetBalanceRsData final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(GetBalanceRsData)
    CLASS_DECLARE_DEFAULTS(GetBalanceRsData)
    TYPE_STRUCT_DECLARE("f838381d-4124-438d-b787-fa892004a19c"_sv)

public:
                        GetBalanceRsData        (void) noexcept;
    virtual             ~GetBalanceRsData       (void) noexcept override final;

public:
    ContextDesc         context;        //context
    lamport_t           value;          //value
};

using getBalance_rs_data = GetBalanceRsData::SP;

JSON_RPC_API_RS(SOL_CORE_DATA_MODEL_API_API, getBalance, "e4fc64e8-3013-4ab7-a822-f1653d7932c7"_sv)

}//namespace Sol::Core::API::RPC
