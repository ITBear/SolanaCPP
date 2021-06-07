#include "Address.hpp"

namespace Sol::Core::LightWallet {

Address::Address
(
    const GpUUID&           aUID,
    GpCryptoKeyPair::CSP    aKeyPair
) noexcept:
GpCryptoAddress(aUID, aKeyPair)
{
}

Address::~Address (void) noexcept
{
}

std::string Address::OnRecalcAddrStr (void) const
{
    std::string addr = GpBase58::SEncodeToStr(KeyPair().PublicKey(), GpBase58Alphabet::NAKAMOTO);

    if (addr.size() < 44)
    {
        const size_t    paddingSize = 44 - addr.size();
        std::string     padding(paddingSize, '1');

        addr = padding + addr;
    }

    return addr;
}

}//namespace Sol::Core::LightWallet
