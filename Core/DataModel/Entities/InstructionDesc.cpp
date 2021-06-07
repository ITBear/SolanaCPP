#include "InstructionDesc.hpp"

namespace Sol::Core::DataModel {

TYPE_STRUCT_IMPLEMENT(InstructionDesc, GP_MODULE_UUID)

InstructionDesc::InstructionDesc (void) noexcept
{
}

InstructionDesc::InstructionDesc (const InstructionDesc& aInstructionDesc):
program_id_index(aInstructionDesc.program_id_index),
accounts(aInstructionDesc.accounts),
data(aInstructionDesc.data)
{
}

InstructionDesc::InstructionDesc (InstructionDesc&& aInstructionDesc) noexcept:
program_id_index(std::move(aInstructionDesc.program_id_index)),
accounts(std::move(aInstructionDesc.accounts)),
data(std::move(aInstructionDesc.data))
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

InstructionDesc&    InstructionDesc::operator= (const InstructionDesc& aInstructionDesc)
{
    program_id_index    = aInstructionDesc.program_id_index;
    accounts            = aInstructionDesc.accounts;
    data                = aInstructionDesc.data;

    return *this;
}

InstructionDesc&    InstructionDesc::operator= (InstructionDesc&& aInstructionDesc) noexcept
{
    program_id_index    = std::move(aInstructionDesc.program_id_index);
    accounts            = std::move(aInstructionDesc.accounts);
    data                = std::move(aInstructionDesc.data);

    return *this;
}

void    InstructionDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(program_id_index);
    PROP(accounts);
    PROP(data);
}

}//namespace Sol::Core::DataModel
