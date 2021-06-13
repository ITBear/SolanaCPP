#pragma once

#include "../Api_global.hpp"

namespace Sol::Core::API::RPC {

//----------------------------- RQ -----------------------------
class SOL_CORE_DATA_MODEL_API_API RequestAirdropRqData final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(RequestAirdropRqData)
    CLASS_DECLARE_DEFAULTS(RequestAirdropRqData)
    TYPE_STRUCT_DECLARE("144c5e76-1763-4eed-87f9-9835e83b18dd"_sv)

public:
                        RequestAirdropRqData        (void) noexcept;
                        RequestAirdropRqData        (std::string_view   aPubkey,
                                                     const lamport_t    aAmount);
    virtual             ~RequestAirdropRqData       (void) noexcept override final;

public:
    std::string         pubkey;             //Pubkey of account to receive lamports, as base-58 encoded string
    lamport_t           amount;             //lamports
    //CommitmentDesc    commitment;         //(optional) Commitment (used for retrieving blockhash and verifying airdrop success)
};

using requestAirdrop_rq_data = RequestAirdropRqData::SP;

JSON_RPC_API_RQ(SOL_CORE_DATA_MODEL_API_API, requestAirdrop, "123cf918-9c5f-4fba-b8a2-0cd6673eca97"_sv)

//----------------------------- RS -----------------------------
using requestAirdrop_rs_data = std::string;

JSON_RPC_API_RS(SOL_CORE_DATA_MODEL_API_API, requestAirdrop, "8ef2b25c-0870-48f4-80bf-7e8980c4c149"_sv)

}//namespace Sol::Core::API::RPC
