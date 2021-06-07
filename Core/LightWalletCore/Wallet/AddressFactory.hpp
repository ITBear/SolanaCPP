#pragma once

#include "../LightWalletCore_global.hpp"

namespace Sol::Core::LightWallet {

class SOL_CORE_LIGHT_WALLET_CORE_API AddressFactory final: public GpCryptoAddressFactory
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(AddressFactory)
    CLASS_DECLARE_DEFAULTS(AddressFactory)

public:
                                    AddressFactory  (void) noexcept {}
    virtual                         ~AddressFactory (void) noexcept override final {}

    virtual GpCryptoAddress::SP     Generate        (GpCryptoKeyFactory& aKeyFactory) override final;
};

}//namespace Sol::Core::LightWallet
