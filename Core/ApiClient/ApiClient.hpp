#pragma once

#include "ApiClient_global.hpp"

namespace Sol::Core::API::RPC {

class SOL_CORE_API_CLIENT_API ApiClient final: public GPlatform::API::RPC::GpApiClient
{
public:
    CLASS_REMOVE_CTRS(ApiClient)
    CLASS_DECLARE_DEFAULTS(ApiClient)

public:
                                        ApiClient               (std::string_view aUrl);
    virtual                             ~ApiClient              (void) noexcept override final;

    //getRecentBlockhash
    getRecentBlockhash_rs_data          GetRecentBlockhash      (const getRecentBlockhash_rq_data& aRq);
    getRecentBlockhash_rs_data          GetRecentBlockhash      (const Commitment::EnumT aCommitment);

    //sendTransaction
    sendTransaction_rs_data             SendTransaction         (std::string_view aTxBase58);

    //requestAirdrop
    requestAirdrop_rs_data              RequestAirdrop          (const requestAirdrop_rq_data& aRq);
    requestAirdrop_rs_data              RequestAirdrop          (std::string_view   aAddrBase58,
                                                                 const lamport_t    aAmount);

    //getTransaction
    getTransaction_rs_data              GetTransaction          (const getTransaction_rq_data& aRq);
    getTransaction_rs_data              GetTransaction          (std::string_view           aTxSigBase58,
                                                                 const EncodingType::EnumT  aEncoding,
                                                                 const Commitment::EnumT    aCommitment);

protected:
    virtual void                        CheckRsResult           (const GpApiRsIfDesc&   aRsDesc,
                                                                 std::string_view       aMethodName) override final;
    virtual void                        OnBeforeRpcRQ           (GpApiRqIfDesc& aRq) override final;

private:
    GpHttpRqRs::SP                      iLastRqRs;
};

}//namespace Sol::Loyalty::API::RPC
