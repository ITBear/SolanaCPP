#include "InstructionBuilder.hpp"
#include "TransactionBuilder.hpp"
#include "../Utils/Serializator.hpp"

namespace Sol::Core::LightWallet {

InstructionBuilder::InstructionBuilder (TransactionBuilder& aTransactionBuilder) noexcept:
iTransactionBuilder(aTransactionBuilder)
{
}

InstructionBuilder::~InstructionBuilder (void) noexcept
{
}

InstructionBuilder& InstructionBuilder::ProgramIdIndex (const count_t aProgramIdIndex)
{
    _Instruction().program_id_index = aProgramIdIndex;

    return *this;
}

InstructionBuilder& InstructionBuilder::AddAccountIdIndex (const count_t aAccountIdIndex)
{
    _Instruction().accounts.emplace_back(aAccountIdIndex);

    return *this;
}

InstructionBuilder& InstructionBuilder::Data (GpRawPtrByteR aData)
{
    _Instruction().data = GpBytesArrayUtils::SMake(aData);

    return *this;
}

TransactionBuilder& InstructionBuilder::InstructionEnd (void) noexcept
{
    iTransactionBuilder.AddInstruction(Build());

    return iTransactionBuilder;
}

Sol::Core::DataModel::InstructionDesc&  InstructionBuilder::_Instruction (void)
{
    if (iInstruction.IsNULL())
    {
        iInstruction = MakeSP<Sol::Core::DataModel::InstructionDesc>();
    }

    return iInstruction.Vn();
}

}//namespace Sol::Core::LightWallet
