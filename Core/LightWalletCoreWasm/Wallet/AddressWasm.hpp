#pragma once

#include "../LightWalletCoreWasm_global.hpp"

namespace Sol::Core::LightWallet {

class AddressWasm
{
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(AddressWasm)

public:
    using STDSP = std::shared_ptr<AddressWasm>;

public:
                            AddressWasm         (void) noexcept;
                            AddressWasm         (Address::SP aAddr) noexcept;
                            ~AddressWasm        (void) noexcept;

    emscripten::val         private_key         (void) const;
    emscripten::val         name                (void) const;
    emscripten::val         sign_data_base64    (const std::string aDataBase64) const;
    //emscripten::val       sign_tx             (TransactionWasm::STDSP aTransactionWasm) const;

private:
    Address::SP             iAddr;
};

}//namespace Sol::Core::LightWallet
