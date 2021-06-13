#pragma once

#include "MessageDesc.hpp"

namespace Sol::Core::DataModel {

class SOL_CORE_DATA_MODEL_ENTITIES_API TransactionDesc final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(TransactionDesc)
    CLASS_DECLARE_DEFAULTS(TransactionDesc)
    TYPE_STRUCT_DECLARE("9df1805d-bc4f-492e-8152-b15ca1d60732"_sv)

public:
    using NetworkTypeT  = NetworkType;
    using NetworkTypeTE = NetworkTypeT::EnumT;

public:
                                TransactionDesc     (void) noexcept;
    virtual                     ~TransactionDesc    (void) noexcept override final;

public:
};

}//namespace Sol::Core::DataModel
