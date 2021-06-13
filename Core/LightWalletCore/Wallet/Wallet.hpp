#pragma once

#include "Address.hpp"
#include "AddressFactory.hpp"
#include "InstructionBuilder.hpp"
#include "SystemDataBuilder.hpp"
#include "Transaction.hpp"
#include "TransactionBuilder.hpp"
#include "ProgramIds.hpp"

namespace Sol::Core::LightWallet {

class SOL_CORE_LIGHT_WALLET_CORE_API Wallet final: public GpCryptoWallet
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(Wallet)
    CLASS_DECLARE_DEFAULTS(Wallet)

public:
                                Wallet      (void);
    virtual                     ~Wallet     (void) noexcept override final;

};

}//namespace Sol::Core::LightWallet
