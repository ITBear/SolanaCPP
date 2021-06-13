#include "MessageHeaderDesc.hpp"

namespace Sol::Core::DataModel {

TYPE_STRUCT_IMPLEMENT(MessageHeaderDesc, GP_MODULE_UUID)

MessageHeaderDesc::MessageHeaderDesc (void) noexcept
{
}

MessageHeaderDesc::MessageHeaderDesc
(
    const count_t aNumRequiredSignatures,
    const count_t aNumReadonlySignedAccounts,
    const count_t aNumReadonlyUnsignedAccounts
) noexcept:
num_required_signatures(aNumRequiredSignatures),
num_readonly_signed_accounts(aNumReadonlySignedAccounts),
num_readonly_unsigned_accounts(aNumReadonlyUnsignedAccounts)
{   
}

MessageHeaderDesc::MessageHeaderDesc (const MessageHeaderDesc& aDesc) noexcept:
num_required_signatures(aDesc.num_required_signatures),
num_readonly_signed_accounts(aDesc.num_readonly_signed_accounts),
num_readonly_unsigned_accounts(aDesc.num_readonly_unsigned_accounts)
{
}

MessageHeaderDesc::~MessageHeaderDesc (void) noexcept
{
}

void    MessageHeaderDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(num_required_signatures);
    PROP(num_readonly_signed_accounts);
    PROP(num_readonly_unsigned_accounts);
}

}//namespace Sol::Core::DataModel
