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
    getRecentBlockhash_rs_data          getRecentBlockhash      (const getRecentBlockhash_rq_data& aRq);
    getRecentBlockhash_rs_data          getRecentBlockhash      (void);

    //sendTransaction
    sendTransaction_rs_data             sendTransaction         (std::string_view aTxBase58);


protected:
    virtual void                        CheckRsResult           (const GpApiRsIfDesc&   aRsDesc,
                                                                 std::string_view       aMethodName) override final;
    virtual void                        OnBeforeRpcRQ           (GpApiRqIfDesc& aRq) override final;

private:
    GpHttpRqRs::SP                      iLastRqRs;
};

}//namespace Sol::Loyalty::API::RPC
