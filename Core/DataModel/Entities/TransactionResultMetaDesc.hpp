#pragma once

#include "Enentities_global.hpp"

namespace Sol::Core::DataModel {

class SOL_CORE_DATA_MODEL_ENTITIES_API TransactionResultMetaDesc final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(TransactionResultMetaDesc)
    CLASS_DECLARE_DEFAULTS(TransactionResultMetaDesc)
    TYPE_STRUCT_DECLARE("7e46a10c-8b46-48f3-9443-9cf7ad48667c"_sv)

public:
                                TransactionResultMetaDesc   (void) noexcept;
    virtual                     ~TransactionResultMetaDesc  (void) noexcept override final;

public:
};

}//namespace Sol::Core::DataModel
