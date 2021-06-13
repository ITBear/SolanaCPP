#pragma once

#include "Units.hpp"
#include "NetworkType.hpp"
#include "MessageHeaderDesc.hpp"
#include "InstructionDesc.hpp"

namespace Sol::Core::DataModel {

class SOL_CORE_DATA_MODEL_ENTITIES_API MessageDesc final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(MessageDesc)
    CLASS_DECLARE_DEFAULTS(MessageDesc)
    TYPE_STRUCT_DECLARE("a8f4bf2c-25c1-4d51-a69c-6bac03ee09b2"_sv)

public:
    using NetworkTypeT  = NetworkType;
    using NetworkTypeTE = NetworkTypeT::EnumT;

public:
                                MessageDesc     (void) noexcept;
                                MessageDesc     (const MessageHeaderDesc&           aHeader,
                                                 const GpVector<GpBytesArray>&      aAccountKeys,
                                                 const GpBytesArray&                aRecentBlockhash,
                                                 const InstructionDesc::C::Vec::SP& aInstructions);
    virtual                     ~MessageDesc    (void) noexcept override final;

public:
    MessageHeaderDesc           header;
    GpVector<GpBytesArray>      account_keys;
    GpBytesArray                recent_blockhash;
    InstructionDesc::C::Vec::SP instructions;
};

}//namespace Sol::Core::DataModel
