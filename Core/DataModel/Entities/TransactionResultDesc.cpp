#include "TransactionResultDesc.hpp"

namespace Sol::Core::DataModel {

TYPE_STRUCT_IMPLEMENT(TransactionResultDesc, GP_MODULE_UUID)

TransactionResultDesc::TransactionResultDesc (void) noexcept
{
}

TransactionResultDesc::~TransactionResultDesc (void) noexcept
{
}

void    TransactionResultDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(slot);
    PROP(transaction);
    PROP(blockTime);
    PROP(meta);
}

}//namespace Sol::Core::DataModel
