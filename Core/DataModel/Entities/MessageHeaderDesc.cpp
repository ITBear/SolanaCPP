#include "MessageHeaderDesc.hpp"

namespace Sol::Core::DataModel {

TYPE_STRUCT_IMPLEMENT(MessageHeaderDesc, GP_MODULE_UUID)

MessageHeaderDesc::MessageHeaderDesc (void) noexcept
{
}

MessageHeaderDesc::MessageHeaderDesc (const MessageHeaderDesc& aMessageHeaderDesc) noexcept:
num_required_signatures(aMessageHeaderDesc.num_required_signatures),
num_readonly_signed_accounts(aMessageHeaderDesc.num_readonly_signed_accounts),
num_readonly_unsigned_accounts(aMessageHeaderDesc.num_readonly_unsigned_accounts)
{
}

MessageHeaderDesc::MessageHeaderDesc (MessageHeaderDesc&& aMessageHeaderDesc) noexcept:
num_required_signatures(std::move(aMessageHeaderDesc.num_required_signatures)),
num_readonly_signed_accounts(std::move(aMessageHeaderDesc.num_readonly_signed_accounts)),
num_readonly_unsigned_accounts(std::move(aMessageHeaderDesc.num_readonly_unsigned_accounts))
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

MessageHeaderDesc::~MessageHeaderDesc (void) noexcept
{
}

MessageHeaderDesc&  MessageHeaderDesc::operator= (const MessageHeaderDesc& aMessageHeaderDesc)
{
    num_required_signatures         = aMessageHeaderDesc.num_required_signatures;
    num_readonly_signed_accounts    = aMessageHeaderDesc.num_readonly_signed_accounts;
    num_readonly_unsigned_accounts  = aMessageHeaderDesc.num_readonly_unsigned_accounts;

    return *this;
}

MessageHeaderDesc&  MessageHeaderDesc::operator= (MessageHeaderDesc&& aMessageHeaderDesc) noexcept
{
    num_required_signatures         = std::move(aMessageHeaderDesc.num_required_signatures);
    num_readonly_signed_accounts    = std::move(aMessageHeaderDesc.num_readonly_signed_accounts);
    num_readonly_unsigned_accounts  = std::move(aMessageHeaderDesc.num_readonly_unsigned_accounts);

    return *this;
}

void    MessageHeaderDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(num_required_signatures);
    PROP(num_readonly_signed_accounts);
    PROP(num_readonly_unsigned_accounts);
}

}//namespace Sol::Core::DataModel
