#include "getBalance.hpp"

namespace Sol::Core::API::RPC {

//----------------------------- RQ -----------------------------
TYPE_STRUCT_IMPLEMENT(GetBalanceRqData, GP_MODULE_UUID)

GetBalanceRqData::GetBalanceRqData (void) noexcept
{
}

GetBalanceRqData::GetBalanceRqData
(
    std::string_view        aAddrBase58,
    const Commitment::EnumT aCommitment
):
addr_base58(aAddrBase58),
commitment(aCommitment)
{
}

GetBalanceRqData::~GetBalanceRqData (void) noexcept
{
}

void    GetBalanceRqData::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(addr_base58);
    PROP(commitment);
}

JSON_RPC_API_RQ_IMPL(getBalance)

//----------------------------- RS -----------------------------
TYPE_STRUCT_IMPLEMENT(GetBalanceRsData, GP_MODULE_UUID)

GetBalanceRsData::GetBalanceRsData (void) noexcept
{
}

GetBalanceRsData::~GetBalanceRsData (void) noexcept
{
}

void    GetBalanceRsData::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(context);
    PROP(value);
}

JSON_RPC_API_RS_IMPL(getBalance)

}//namespace Sol::Core::API::RPC
