#pragma once

#include "Address.hpp"
#include "Transaction.hpp"
#include "InstructionBuilder.hpp"

namespace Sol::Core::LightWallet {

class SOL_CORE_LIGHT_WALLET_CORE_API TransactionBuilder
{
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(TransactionBuilder);

public:
                                TransactionBuilder      (void) noexcept;
                                ~TransactionBuilder     (void) noexcept;

    static TransactionBuilder   SNew                    (void) {return TransactionBuilder();}

    Transaction::SP             Build                   (void);

    TransactionBuilder&         MessageHeader           (const count_t aNumRequiredSignatures,
                                                         const count_t aNumReadonlySignedAccounts,
                                                         const count_t aNumReadonlyUnsignedAccounts);

    TransactionBuilder&         AddAccountKey           (GpRawPtrByteR aPublicKey);
    TransactionBuilder&         RecentBlockhash         (const GpBytesArray& aRecentBlockhash);
    InstructionBuilder&         InstructionBegin        (void);
    TransactionBuilder&         AddInstruction          (Sol::Core::DataModel::InstructionDesc::SP aInstruction);
    TransactionBuilder&         AddSign                 (const Address& aAddress);

    Transaction&                _Transaction            (void);

private:
    void                        SerializeMessage        (void);

private:
    Transaction::SP             iTransaction;
    InstructionBuilder          iInstructionBuilder;
};

}//namespace Sol::Core::LightWallet
