#include "CommitmentDesc.hpp"

namespace Sol::Core::DataModel {

TYPE_STRUCT_IMPLEMENT(CommitmentDesc, GP_MODULE_UUID)

CommitmentDesc::CommitmentDesc (void) noexcept
{
}

CommitmentDesc::CommitmentDesc (const CommitmentTE aCommitment) noexcept:
commitment(aCommitment)
{
}

CommitmentDesc::~CommitmentDesc (void) noexcept
{
}

void    CommitmentDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(commitment);
}

}//namespace Sol::Core::DataModel
