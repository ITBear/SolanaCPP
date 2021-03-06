#pragma once

#include "MessageDesc.hpp"

namespace Sol::Core::DataModel {

class SOL_CORE_DATA_MODEL_ENTITIES_API TransactionDesc final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(TransactionDesc)
    CLASS_DECLARE_DEFAULTS(TransactionDesc)
    TYPE_STRUCT_DECLARE("62006d2e-3586-4847-9e09-5cd5cce4a1d2"_sv)

public:
    using NetworkTypeT  = NetworkType;
    using NetworkTypeTE = NetworkTypeT::EnumT;

public:
                                TransactionDesc     (void) noexcept;
    virtual                     ~TransactionDesc    (void) noexcept override final;

public:
    GpVector<GpBytesArray>      signatures;
    MessageDesc                 message;
};

}//namespace Sol::Core::DataModel
