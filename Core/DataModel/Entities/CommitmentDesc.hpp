#pragma once

#include "Commitment.hpp"

namespace Sol::Core::DataModel {

class SOL_CORE_DATA_MODEL_ENTITIES_API CommitmentDesc final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(CommitmentDesc)
    CLASS_DECLARE_DEFAULTS(CommitmentDesc)
    TYPE_STRUCT_DECLARE("4ecab43c-78d6-4592-a436-3ea80a3bdd51"_sv)

public:
    using CommitmentT   = Commitment;
    using CommitmentTE  = Commitment::EnumT;

public:
                                CommitmentDesc  (void) noexcept;
                                CommitmentDesc  (const CommitmentTE aCommitment) noexcept;
    virtual                     ~CommitmentDesc (void) noexcept override final;

public:
    Commitment                  commitment = Commitment::finalized;
};

}//namespace Sol::Core::DataModel
