#include "ContextDesc.hpp"

namespace Sol::Core::DataModel {

TYPE_STRUCT_IMPLEMENT(ContextDesc, GP_MODULE_UUID)

ContextDesc::ContextDesc (void) noexcept
{
}

ContextDesc::ContextDesc (const s_int_64 aSlot) noexcept:
slot(aSlot)
{
}

ContextDesc::~ContextDesc (void) noexcept
{
}

void    ContextDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(slot);
}

}//namespace Sol::Core::DataModel
