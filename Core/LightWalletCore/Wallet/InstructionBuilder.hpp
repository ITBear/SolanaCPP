#pragma once

#include "../LightWalletCore_global.hpp"

namespace Sol::Core::LightWallet {

class TransactionBuilder;

class SOL_CORE_LIGHT_WALLET_CORE_API InstructionBuilder
{
    CLASS_REMOVE_CTRS(InstructionBuilder);

public:
                            InstructionBuilder  (TransactionBuilder& aTransactionBuilder) noexcept;
                            ~InstructionBuilder (void) noexcept;

    Sol::Core::DataModel::InstructionDesc::SP
                            Build               (void) noexcept {return std::move(iInstruction);}

    InstructionBuilder&     ProgramIdIndex      (const count_t aProgramIdIndex);
    InstructionBuilder&     AddAccountIdIndex   (const count_t aAccountIdIndex);
    InstructionBuilder&     Data                (GpRawPtrByteR aData);

    TransactionBuilder&     InstructionEnd      (void) noexcept;

    Sol::Core::DataModel::InstructionDesc&
                            _Instruction        (void);

private:
    Sol::Core::DataModel::InstructionDesc::SP   iInstruction;
    TransactionBuilder&                         iTransactionBuilder;
};

}//namespace Sol::Core::LightWallet
