#include "ApiClient.hpp"

namespace Sol::Core::API::RPC {

ApiClient::ApiClient (std::string_view aUrl):
GpApiClient
(
    MakeSP<GPlatform::API::RPC::GpApiCliTransportHttpFactory>
    (
        aUrl,
        MakeSP<GpTypeMapperJsonFactory>(),
        MakeSP<GpHttpClientCurlFactory>()
    )->NewInstance()
)
{
}

ApiClient::~ApiClient (void) noexcept
{
}

getRecentBlockhash_rs_data  ApiClient::getRecentBlockhash (const getRecentBlockhash_rq_data& aRq)
{
    return ProcessRpcRQ<getRecentBlockhash_rq,
                        getRecentBlockhash_rs>(aRq, "getRecentBlockhash"_sv, std::nullopt, std::nullopt);
}

getRecentBlockhash_rs_data  ApiClient::getRecentBlockhash (void)
{
    auto rq = {MakeSP<GetRecentBlockhashRqData>()};
    return getRecentBlockhash(rq);
}

sendTransaction_rs_data ApiClient::sendTransaction (std::string_view aTxBase58)
{
    return ProcessRpcRQ<sendTransaction_rq,
                        sendTransaction_rs>({std::string(aTxBase58)}, "sendTransaction"_sv, std::nullopt, std::nullopt);
}

void    ApiClient::CheckRsResult
(
        const GpApiRsIfDesc&    aRsDesc,
        std::string_view        aMethodName
)
{
    GpApiRsResultDesc::CSP resCSP = aRsDesc.Result();

    if (resCSP.IsNULL())
    {
        return;
    }

    const GpApiRsJsonRpcDesc&   res         = static_cast<const GpApiRsJsonRpcDesc&>(aRsDesc);
    const auto                  errorCode   = res.error->code;

    THROW_GPE_COND
    (
        errorCode == 0,
        [&](){return "Solana API call return error. Method '"_sv + aMethodName + "', code " + errorCode + ", message: "_sv + res.error->message;}
    );
}

void    ApiClient::OnBeforeRpcRQ (GpApiRqIfDesc& /*aRq*/)
{
    //NOP
}

}//namespace Sol::Core::API::RPC
