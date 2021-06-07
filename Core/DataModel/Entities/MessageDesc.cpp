#include "MessageDesc.hpp"

namespace Sol::Core::DataModel {

TYPE_STRUCT_IMPLEMENT(MessageDesc, GP_MODULE_UUID)

MessageDesc::MessageDesc (void) noexcept
{
}

MessageDesc::MessageDesc (const MessageDesc& aMessageDesc):
header(aMessageDesc.header),
account_keys(aMessageDesc.account_keys),
recent_blockhash(aMessageDesc.recent_blockhash),
instructions(aMessageDesc.instructions)
{
}

MessageDesc::MessageDesc (MessageDesc&& aMessageDesc) noexcept:
header(std::move(aMessageDesc.header)),
account_keys(std::move(aMessageDesc.account_keys)),
recent_blockhash(std::move(aMessageDesc.recent_blockhash)),
instructions(std::move(aMessageDesc.instructions))
{
}

MessageDesc::MessageDesc
(
    const MessageHeaderDesc&            aHeader,
    const GpVector<GpBytesArray>&       aAccountKeys,
    const GpBytesArray&                 aRecentBlockhash,
    const InstructionDesc::C::Vec::SP&  aInstructions
):
header(aHeader),
account_keys(aAccountKeys),
recent_blockhash(aRecentBlockhash),
instructions(aInstructions)
{
}

MessageDesc::~MessageDesc (void) noexcept
{
}

MessageDesc&    MessageDesc::operator= (const MessageDesc& aMessageDesc)
{
    header              = aMessageDesc.header;
    account_keys        = aMessageDesc.account_keys;
    recent_blockhash    = aMessageDesc.recent_blockhash;
    instructions        = aMessageDesc.instructions;

    return *this;
}

MessageDesc&    MessageDesc::operator= (MessageDesc&& aMessageDesc) noexcept
{
    header              = std::move(aMessageDesc.header);
    account_keys        = std::move(aMessageDesc.account_keys);
    recent_blockhash    = std::move(aMessageDesc.recent_blockhash);
    instructions        = std::move(aMessageDesc.instructions);

    return *this;
}

void    MessageDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(header);
    PROP(account_keys);
    PROP(recent_blockhash);
    PROP(instructions);
}

}//namespace Sol::Core::DataModel
