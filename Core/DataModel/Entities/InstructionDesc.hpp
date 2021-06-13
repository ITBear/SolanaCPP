#pragma once

#include "Enentities_global.hpp"

namespace Sol::Core::DataModel {

class SOL_CORE_DATA_MODEL_ENTITIES_API InstructionDesc final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(InstructionDesc)
    CLASS_DECLARE_DEFAULTS(InstructionDesc)
    TYPE_STRUCT_DECLARE("bd03ffdf-1e45-46fb-8368-9507e1163322"_sv)

public:
                            InstructionDesc     (void) noexcept;
                            InstructionDesc     (const count_t              aProgramIdIndex,
                                                 const GpVector<count_t>&   aAccounts,
                                                 const GpBytesArray&        aData);
    virtual                 ~InstructionDesc    (void) noexcept override final;

public:
    count_t                 program_id_index    = 0_cnt;
    GpVector<count_t>       accounts;
    GpBytesArray            data;
};

}//namespace Sol::Core::DataModel
