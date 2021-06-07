#pragma once

#include "../LightWalletCore_global.hpp"

namespace Sol::Core::LightWallet {

class SOL_CORE_LIGHT_WALLET_CORE_API Address final: public GpCryptoAddress
{
public:
    CLASS_REMOVE_CTRS(Address)
    CLASS_DECLARE_DEFAULTS(Address)

    using KeyPairT  = GpCryptoKeyPair_Ed25519;

public:
                            Address             (const GpUUID&          aUID,
                                                 GpCryptoKeyPair::CSP   aKeyPair) noexcept;
    virtual                 ~Address            (void) noexcept override final;

protected:
    virtual std::string     OnRecalcAddrStr     (void) const override final;
};

}//namespace Sol::Core::LightWallet
