#include "Wallet.hpp"

namespace Sol::Core::LightWallet {

Wallet::Wallet (void):
GpCryptoWallet(MakeSP<AddressFactory>())
{
}

Wallet::~Wallet (void) noexcept
{
}

}//namespace Sol::Core::LightWallet
