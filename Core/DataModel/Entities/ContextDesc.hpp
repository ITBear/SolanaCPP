#pragma once

#include "Commitment.hpp"

namespace Sol::Core::DataModel {

class SOL_CORE_DATA_MODEL_ENTITIES_API ContextDesc final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(ContextDesc)
    CLASS_DECLARE_DEFAULTS(ContextDesc)
    TYPE_STRUCT_DECLARE("1a7dcc78-a29f-4a65-8c6d-a586050dd388"_sv)

public:
                                ContextDesc     (void) noexcept;
                                ContextDesc     (const s_int_64 aSlot) noexcept;
    virtual                     ~ContextDesc    (void) noexcept override final;

public:
    s_int_64                    slot = 0;
};

}//namespace Sol::Core::DataModel
