#include "AddressFactory.hpp"
#include "Address.hpp"

namespace Sol::Core::LightWallet {

GpCryptoAddress::SP AddressFactory::Generate (GpCryptoKeyFactory& aKeyFactory)
{
    return MakeSP<Address>(GpUUID::SGenRandom(), aKeyFactory.Generate());
}

}//namespace Sol::Core::LightWallet
