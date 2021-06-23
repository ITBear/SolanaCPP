#pragma once

#include "Enentities_global.hpp"

namespace Sol::Core::DataModel {

class SOL_CORE_DATA_MODEL_ENTITIES_API VersionDesc final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(VersionDesc)
    CLASS_DECLARE_DEFAULTS(VersionDesc)
    TYPE_STRUCT_DECLARE("ee251f29-6339-40b5-b2dc-39c4d3a81c64"_sv)

public:
                                VersionDesc     (void) noexcept;
    virtual                     ~VersionDesc    (void) noexcept override final;

public:
    s_int_64                    feature_set;
    std::string                 solana_core;
};

}//namespace Sol::Core::DataModel
