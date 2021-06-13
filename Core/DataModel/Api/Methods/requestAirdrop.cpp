#include "requestAirdrop.hpp"

namespace Sol::Core::API::RPC {

//----------------------------- RQ -----------------------------
TYPE_STRUCT_IMPLEMENT(RequestAirdropRqData, GP_MODULE_UUID)

RequestAirdropRqData::RequestAirdropRqData (void) noexcept
{
}

RequestAirdropRqData::RequestAirdropRqData
(
    std::string_view    aPubkey,
    const lamport_t     aAmount
):
pubkey(aPubkey),
amount(aAmount)
{
}

RequestAirdropRqData::~RequestAirdropRqData (void) noexcept
{
}

void    RequestAirdropRqData::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(pubkey);
    PROP(amount);
}

JSON_RPC_API_RQ_IMPL(requestAirdrop)

//----------------------------- RS -----------------------------
JSON_RPC_API_RS_IMPL(requestAirdrop)

}//namespace Sol::Core::API::RPC
