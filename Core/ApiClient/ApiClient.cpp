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

getRecentBlockhash_rs_data  ApiClient::GetRecentBlockhash (const getRecentBlockhash_rq_data& aRq)
{
    return ProcessRpcRQ<getRecentBlockhash_rq,
                        getRecentBlockhash_rs>(aRq, "getRecentBlockhash"_sv, std::nullopt, std::nullopt);
}

getRecentBlockhash_rs_data  ApiClient::GetRecentBlockhash (const Commitment::EnumT aCommitment)
{
    auto rq = MakeSP<GetRecentBlockhashRqData>(aCommitment);
    return GetRecentBlockhash(rq);
}

sendTransaction_rs_data ApiClient::SendTransaction (std::string_view aTxBase58)
{
    return ProcessRpcRQ<sendTransaction_rq,
                        sendTransaction_rs>({std::string(aTxBase58)}, "sendTransaction"_sv, std::nullopt, std::nullopt);
}

requestAirdrop_rs_data  ApiClient::RequestAirdrop (const requestAirdrop_rq_data& aRq)
{
    return ProcessRpcRQ<requestAirdrop_rq,
                        requestAirdrop_rs>(aRq, "requestAirdrop"_sv, std::nullopt, std::nullopt);
}

requestAirdrop_rs_data  ApiClient::RequestAirdrop
(
    std::string_view    aAddrBase58,
    const lamport_t     aAmount
)
{
    auto rq = MakeSP<RequestAirdropRqData>(aAddrBase58, aAmount);
    return RequestAirdrop(rq);
}

getTransaction_rs_data  ApiClient::GetTransaction (const getTransaction_rq_data& aRq)
{
    return ProcessRpcRQ<getTransaction_rq,
                        getTransaction_rs>(aRq, "getTransaction"_sv, std::nullopt, std::nullopt);
}

getTransaction_rs_data  ApiClient::GetTransaction
(
    std::string_view            aTxSigBase58,
    const Commitment::EnumT     aCommitment
)
{
    auto rq = MakeSP<GetTransactionRqData>(aTxSigBase58, aCommitment);
    return GetTransaction(rq);
}

getBalance_rs_data  ApiClient::GetBalance (const getBalance_rq_data& aRq)
{
    return ProcessRpcRQ<getBalance_rq,
                        getBalance_rs>(aRq, "getBalance"_sv, std::nullopt, std::nullopt);
}

getBalance_rs_data  ApiClient::GetBalance
(
    std::string_view        aAddrBase58,
    const Commitment::EnumT aCommitment
)
{
    auto rq = MakeSP<GetBalanceRqData>(aAddrBase58, aCommitment);
    return GetBalance(rq);
}

getTransactionCount_rs_data ApiClient::GetTransactionCount (const getTransactionCount_rq_data& aRq)
{
    return ProcessRpcRQ<getTransactionCount_rq,
                        getTransactionCount_rs>(aRq, "getTransactionCount"_sv, std::nullopt, std::nullopt);
}

getTransactionCount_rs_data ApiClient::GetTransactionCount (void)
{
    auto rq = MakeSP<GpApiVoidDesc>();
    return GetTransactionCount(rq);
}

//getVersion
getVersion_rs_data  ApiClient::GetVersion (const getVersion_rq_data& aRq)
{
    return ProcessRpcRQ<getVersion_rq,
                        getVersion_rs>(aRq, "getVersion"_sv, std::nullopt, std::nullopt);
}

getVersion_rs_data  ApiClient::GetVersion (void)
{
    auto rq = MakeSP<GpApiVoidDesc>();
    return GetVersion(rq);
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
