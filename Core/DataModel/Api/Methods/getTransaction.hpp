#pragma once

#include "../Api_global.hpp"

namespace Sol::Core::API::RPC {

//----------------------------- RQ -----------------------------
namespace GetTransactionRqRs {

    class SOL_CORE_DATA_MODEL_API_API ConfigDesc final: public GpTypeStructBase
    {
    public:
        CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(ConfigDesc)
        CLASS_DECLARE_DEFAULTS(ConfigDesc)
        TYPE_STRUCT_DECLARE("3416204d-03f8-45df-9023-5240a0d59473"_sv)

    public:
                            ConfigDesc      (void) noexcept;
                            ConfigDesc      (const EncodingType::EnumT  aEncoding,
                                             const Commitment::EnumT    aCommitment) noexcept;
        virtual             ~ConfigDesc     (void) noexcept override final;

    public:
        EncodingType        encoding;
        Commitment          commitment;
    };

}//namespace GetTransactionRqRs

class SOL_CORE_DATA_MODEL_API_API GetTransactionRqData final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(GetTransactionRqData)
    CLASS_DECLARE_DEFAULTS(GetTransactionRqData)
    TYPE_STRUCT_DECLARE("b5d0b2db-a35f-40d6-bf2a-89463712eb76"_sv)

public:
                        GetTransactionRqData        (void) noexcept;
                        GetTransactionRqData        (std::string_view           aTxSigBase58,
                                                     const Commitment::EnumT    aCommitment);
    virtual             ~GetTransactionRqData       (void) noexcept override final;

public:
    std::string                     tx_sig_base58;      //transaction signature as base-58 encoded string
    GetTransactionRqRs::ConfigDesc  config;
};

using getTransaction_rq_data = GetTransactionRqData::SP;

JSON_RPC_API_RQ(SOL_CORE_DATA_MODEL_API_API, getTransaction, "ab2ad679-ce70-49b6-8710-c22ca645827d"_sv)

//----------------------------- RS -----------------------------
using getTransaction_rs_data = TransactionResultDesc::SP;

JSON_RPC_API_RS(SOL_CORE_DATA_MODEL_API_API, getTransaction, "adc914ff-2f7a-44e9-ba73-39e93c7ab6ce"_sv)

}//namespace Sol::Core::API::RPC
