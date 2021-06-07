#pragma once

#include "AddressWasm.hpp"

namespace Sol::Core::LightWallet {

class WalletWasm
{
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(WalletWasm)

public:
    using STDSP = std::shared_ptr<WalletWasm>;

public:
                            WalletWasm                  (void) noexcept;
                            WalletWasm                  (Wallet::SP aWallet) noexcept;
                            ~WalletWasm                 (void) noexcept;

    emscripten::val         generate_random_address     (void);
    emscripten::val         generate_next_hd_address    (const std::string aHDGroupId);
    emscripten::val         delete_address              (const std::string aName);
    emscripten::val         find_address                (const std::string aName);
    emscripten::val         add_hd_group                (const std::string aMnemonic, const std::string aPassword);
    emscripten::val         delete_hd_group             (const std::string aHDGroupId);

    static emscripten::val  new_wallet                  (void);
    static emscripten::val  new_mnemonic_phrase         (void);

private:
    Wallet::SP              iWallet;
};

}//namespace Sol::Core::LightWallet
