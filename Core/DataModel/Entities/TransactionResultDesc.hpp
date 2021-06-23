#pragma once

#include "TransactionResultMetaDesc.hpp"

namespace Sol::Core::DataModel {

class SOL_CORE_DATA_MODEL_ENTITIES_API TransactionResultDesc final: public GpTypeStructBase
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(TransactionResultDesc)
    CLASS_DECLARE_DEFAULTS(TransactionResultDesc)
    TYPE_STRUCT_DECLARE("9df1805d-bc4f-492e-8152-b15ca1d60732"_sv)

public:
                                    TransactionResultDesc   (void) noexcept;
    virtual                         ~TransactionResultDesc  (void) noexcept override final;

public:
    s_int_64                        slot    = 0;    //
    GpVector<std::string>           transaction;    //at[0]: Base64 encoded transaction, at[1]: "base64"
    unix_ts_s_t                     blockTime;      //TODO: make optional
    TransactionResultMetaDesc::SP   meta;
};

}//namespace Sol::Core::DataModel
