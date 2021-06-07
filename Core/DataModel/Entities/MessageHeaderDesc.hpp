#pragma once

#include "Enentities_global.hpp"

namespace Sol::Core::DataModel {

class SOL_CORE_DATA_MODEL_ENTITIES_API MessageHeaderDesc final: public GpTypeStructBase
{
public:
    CLASS_DECLARE_DEFAULTS(MessageHeaderDesc)
    TYPE_STRUCT_DECLARE("a6451245-4d03-4531-883f-18154c3fcec3"_sv)

public:
                            MessageHeaderDesc       (void) noexcept;
                            MessageHeaderDesc       (const MessageHeaderDesc& aMessageHeaderDesc) noexcept;
                            MessageHeaderDesc       (MessageHeaderDesc&& aMessageHeaderDesc) noexcept;
                            MessageHeaderDesc       (const count_t aNumRequiredSignatures,
                                                     const count_t aNumReadonlySignedAccounts,
                                                     const count_t aNumReadonlyUnsignedAccounts) noexcept;
    virtual                 ~MessageHeaderDesc      (void) noexcept override final;

    MessageHeaderDesc&      operator=               (const MessageHeaderDesc& aMessageHeaderDesc);
    MessageHeaderDesc&      operator=               (MessageHeaderDesc&& aMessageHeaderDesc) noexcept;

public:
    count_t                 num_required_signatures         = 0_cnt;    //The number of signatures required for message to be considered valid
    count_t                 num_readonly_signed_accounts    = 0_cnt;    //The last iNumReadonlySignedAccounts of the signed keys are read-only accounts
    count_t                 num_readonly_unsigned_accounts  = 0_cnt;    //The last iNumReadonlySignedAccounts of the unsigned keys are read-only accounts
};

}//namespace Sol::Core::DataModel
