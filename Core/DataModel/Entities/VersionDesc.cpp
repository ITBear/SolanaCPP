#include "VersionDesc.hpp"

namespace Sol::Core::DataModel {

TYPE_STRUCT_IMPLEMENT(VersionDesc, GP_MODULE_UUID)

VersionDesc::VersionDesc (void) noexcept
{
}

VersionDesc::~VersionDesc (void) noexcept
{
}

void    VersionDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP_F(feature_set, (GpTypePropFlags{GpTypePropFlags::value_type{GpTypePropFlag::NAME, "feature-set"_sv}}));
    PROP_F(solana_core, (GpTypePropFlags{GpTypePropFlags::value_type{GpTypePropFlag::NAME, "solana-core"_sv}}));
}

}//namespace Sol::Core::DataModel
