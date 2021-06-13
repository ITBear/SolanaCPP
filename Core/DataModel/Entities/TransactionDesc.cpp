#include "TransactionDesc.hpp"

namespace Sol::Core::DataModel {

TYPE_STRUCT_IMPLEMENT(TransactionDesc, GP_MODULE_UUID)

TransactionDesc::TransactionDesc (void) noexcept
{
}

TransactionDesc::~TransactionDesc (void) noexcept
{
}

void    TransactionDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& /*aPropsOut*/)
{
    //PROP();
}

}//namespace Sol::Core::DataModel
