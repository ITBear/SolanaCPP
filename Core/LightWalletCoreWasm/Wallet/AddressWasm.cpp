#include "AddressWasm.hpp"
#include "../WasmUtils/WasmUtils.hpp"

namespace Sol::Core::LightWallet {

AddressWasm::AddressWasm (void) noexcept
{
}

AddressWasm::AddressWasm (Address::SP aAddr) noexcept:
iAddr(std::move(aAddr))
{
}

AddressWasm::~AddressWasm (void) noexcept
{
}

emscripten::val AddressWasm::private_key (void) const
{
    return WasmExceptionCatcher([&]()
    {
        std::string privateBytesHex = StrOps::SFromBytesHex(iAddr->KeyPair().PrivateBytes().ViewR().R());

        return emscripten::val(privateBytesHex);
    });
}

emscripten::val AddressWasm::name (void) const
{
    return WasmExceptionCatcher([&]()
    {
        std::string name(iAddr->Name());
        return emscripten::val(name);
    });
}

emscripten::val AddressWasm::sign_data_base64 (const std::string aDataBase64) const
{
    return WasmExceptionCatcher([&]()
    {
        const GpBytesArray  data        = GpBase64::SDecodeToByteArray(aDataBase64);
        const GpBytesArray  sign        = iAddr->SignData(data);
        std::string         signBase64  = GpBase64::SEncodeToStr(sign, 0_cnt);

        return emscripten::val(signBase64);
    });
}

}//namespace Sol::Core::LightWallet

EMSCRIPTEN_BINDINGS(AddressWasm_bind)
{
    emscripten::class_<Sol::Core::LightWallet::AddressWasm>("Solana_Address")
        .smart_ptr_constructor("Solana_Address", &std::make_shared<Sol::Core::LightWallet::AddressWasm>)
        .function("private_key", &Sol::Core::LightWallet::AddressWasm::private_key)
        .function("name", &Sol::Core::LightWallet::AddressWasm::name)
        .function("sign_data_base64", &Sol::Core::LightWallet::AddressWasm::sign_data_base64)
        //.class_function("sGenerateNew",  &Sol::Core::LightWallet::AddressWasm::SGenerateNew)
    ;
};
