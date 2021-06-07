#include "getRecentBlockhash.hpp"

namespace Sol::Core::API::RPC {

//----------------------------- RQ -----------------------------
TYPE_STRUCT_IMPLEMENT(GetRecentBlockhashRqData, GP_MODULE_UUID)

GetRecentBlockhashRqData::GetRecentBlockhashRqData (void) noexcept
{
}

GetRecentBlockhashRqData::GetRecentBlockhashRqData (std::string_view aCommitment):
commitment(aCommitment)
{
}

GetRecentBlockhashRqData::~GetRecentBlockhashRqData (void) noexcept
{
}

void    GetRecentBlockhashRqData::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(commitment);
}

JSON_RPC_API_RQ_IMPL(getRecentBlockhash)

//----------------------------- RS -----------------------------
namespace GetRecentBlockhashRqRs
{
    TYPE_STRUCT_IMPLEMENT(Context, GP_MODULE_UUID)

    Context::Context (void) noexcept
    {
    }

    Context::~Context (void) noexcept
    {
    }

    void    Context::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
    {
        PROP(slot);
    }

    TYPE_STRUCT_IMPLEMENT(FeeCalculator, GP_MODULE_UUID)

    FeeCalculator::FeeCalculator (void) noexcept
    {
    }

    FeeCalculator::~FeeCalculator (void) noexcept
    {
    }

    void    FeeCalculator::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
    {
        PROP(lamportsPerSignature);
    }

    TYPE_STRUCT_IMPLEMENT(Value, GP_MODULE_UUID)

    Value::Value (void) noexcept
    {
    }

    Value::~Value (void) noexcept
    {
    }

    void    Value::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
    {
        PROP(blockhash);
        PROP(feeCalculator);
    }
}

TYPE_STRUCT_IMPLEMENT(GetRecentBlockhashRsData, GP_MODULE_UUID)

GetRecentBlockhashRsData::GetRecentBlockhashRsData (void) noexcept
{
}

GetRecentBlockhashRsData::~GetRecentBlockhashRsData (void) noexcept
{
}

void    GetRecentBlockhashRsData::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(context);
    PROP(value);
}

JSON_RPC_API_RS_IMPL(getRecentBlockhash)

}//namespace Sol::Core::API::RPC
