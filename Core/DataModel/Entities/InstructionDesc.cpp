#include "InstructionDesc.hpp"

namespace Sol::Core::DataModel {

TYPE_STRUCT_IMPLEMENT(InstructionDesc, GP_MODULE_UUID)

InstructionDesc::InstructionDesc (void) noexcept
{
}

InstructionDesc::InstructionDesc
(
    const count_t               aProgramIdIndex,
    const GpVector<count_t>&    aAccounts,
    const GpBytesArray&         aData
):
program_id_index(aProgramIdIndex),
accounts(aAccounts),
data(aData)
{
}

InstructionDesc::~InstructionDesc (void) noexcept
{
}

void    InstructionDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(program_id_index);
    PROP(accounts);
    PROP(data);
}

}//namespace Sol::Core::DataModel
