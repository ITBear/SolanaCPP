#include "MessageDesc.hpp"

namespace Sol::Core::DataModel {

TYPE_STRUCT_IMPLEMENT(MessageDesc, GP_MODULE_UUID)

MessageDesc::MessageDesc (void) noexcept
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

void    MessageDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(header);
    PROP(account_keys);
    PROP(recent_blockhash);
    PROP(instructions);
}

}//namespace Sol::Core::DataModel
