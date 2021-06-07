#include "WalletWasm.hpp"
#include "../WasmUtils/WasmUtils.hpp"

namespace Sol::Core::LightWallet {

WalletWasm::WalletWasm (void) noexcept
{
}

WalletWasm::WalletWasm (Wallet::SP aWallet) noexcept:
iWallet(std::move(aWallet))
{
}

WalletWasm::~WalletWasm (void) noexcept
{
}

emscripten::val WalletWasm::generate_random_address (void)
{
    return WasmExceptionCatcher([&]()
    {
        Address::SP         addr        = iWallet->GenRndAddr();
        AddressWasm::STDSP  addrWasm    = std::make_shared<AddressWasm>(addr);

        return emscripten::val(addrWasm);
    });
}

emscripten::val WalletWasm::generate_next_hd_address (const std::string aHDGroupId)
{
    return WasmExceptionCatcher([&]()
    {
        Address::SP         addr        = iWallet->GenNextHDAddr(count_t::SMake(StrOps::SToSI64(aHDGroupId)));
        AddressWasm::STDSP  addrWasm    = std::make_shared<AddressWasm>(addr);

        return emscripten::val(addrWasm);
    });
}

emscripten::val WalletWasm::delete_address (const std::string aName)
{
    return WasmExceptionCatcher([&]()
    {
        iWallet->DeleteAddr(aName);
        return emscripten::val::null();
    });
}

emscripten::val WalletWasm::find_address (const std::string aName)
{
    return WasmExceptionCatcher([&]()
    {
        Address::SP         addr        = iWallet->FindAddr(aName);
        AddressWasm::STDSP  addrWasm    = std::make_shared<AddressWasm>(addr);

        return emscripten::val(addrWasm);
    });
}

emscripten::val WalletWasm::add_hd_group (const std::string aMnemonic, const std::string aPassword)
{
    return WasmExceptionCatcher([&]()
    {
        const count_t hdGroupId = iWallet->AddHDGroup(aMnemonic, aPassword);
        return emscripten::val(StrOps::SFromSI64(hdGroupId.As<s_int_64>()));
    });
}

emscripten::val WalletWasm::delete_hd_group (const std::string aHDGroupId)
{
    return WasmExceptionCatcher([&]()
    {
        iWallet->DeleteHDGroup(count_t::SMake(StrOps::SToSI64(aHDGroupId)));
        return emscripten::val::null();
    });
}

emscripten::val WalletWasm::new_wallet (void)
{
    return WasmExceptionCatcher([&]()
    {
        Wallet::SP          wallet      = MakeSP<Wallet>();
        WalletWasm::STDSP   walletWasm  = std::make_shared<WalletWasm>(std::move(wallet));

        return emscripten::val(walletWasm);
    });
}

emscripten::val WalletWasm::new_mnemonic_phrase (void)
{
    return WasmExceptionCatcher([&]()
    {
        return emscripten::val(std::string(WalletUtils::SNewMnemonic().ViewR().R().AsStringView()));
    });
}

}//namespace Sol::Core::LightWallet

EMSCRIPTEN_BINDINGS(WalletWasm_bind)
{
    emscripten::class_<Sol::Core::LightWallet::WalletWasm>("Wallet")
        .smart_ptr_constructor("Wallet", &std::make_shared<Sol::Core::LightWallet::WalletWasm>)
        .function("generate_random_address", &Sol::Core::LightWallet::WalletWasm::generate_random_address)
        .function("generate_next_hd_address", &Sol::Core::LightWallet::WalletWasm::generate_next_hd_address)
        .function("delete_address", &Sol::Core::LightWallet::WalletWasm::delete_address)
        .function("find_address", &Sol::Core::LightWallet::WalletWasm::find_address)
        .function("add_hd_group", &Sol::Core::LightWallet::WalletWasm::add_hd_group)
        .function("delete_hd_group", &Sol::Core::LightWallet::WalletWasm::delete_hd_group)
        .class_function("new_wallet", &Sol::Core::LightWallet::WalletWasm::new_wallet)
        .class_function("new_mnemonic_phrase", &Sol::Core::LightWallet::WalletWasm::new_mnemonic_phrase)
    ;
};
