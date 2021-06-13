#include "getTransaction.hpp"

namespace Sol::Core::API::RPC {

//----------------------------- RQ -----------------------------
namespace GetTransactionRqRs {

TYPE_STRUCT_IMPLEMENT(ConfigDesc, GP_MODULE_UUID)

ConfigDesc::ConfigDesc (void) noexcept
{
}

ConfigDesc::ConfigDesc
(
    const EncodingType::EnumT   aEncoding,
    const Commitment::EnumT     aCommitment
) noexcept:
encoding(aEncoding),
commitment(aCommitment)
{
}

ConfigDesc::~ConfigDesc (void) noexcept
{
}

void    ConfigDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(encoding);
    PROP(commitment);
}

}//namespace GetTransactionRqRs

TYPE_STRUCT_IMPLEMENT(GetTransactionRqData, GP_MODULE_UUID)

GetTransactionRqData::GetTransactionRqData (void) noexcept
{
}

GetTransactionRqData::GetTransactionRqData
(
    std::string_view            aTxSigBase58,
    const EncodingType::EnumT   aEncoding,
    const Commitment::EnumT     aCommitment
):
tx_sig_base58(aTxSigBase58),
config(aEncoding, aCommitment)
{
}

GetTransactionRqData::~GetTransactionRqData (void) noexcept
{
}

void    GetTransactionRqData::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(tx_sig_base58);
    PROP(config);
}

JSON_RPC_API_RQ_IMPL(getTransaction)

//----------------------------- RS -----------------------------
JSON_RPC_API_RS_IMPL(getTransaction)

}//namespace Sol::Core::API::RPC
