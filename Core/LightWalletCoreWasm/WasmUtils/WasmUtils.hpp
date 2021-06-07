#pragma once

#include "../LightWalletCoreWasm_global.hpp"

namespace Sol::Core::LightWallet {

emscripten::val WasmExceptionCatcher    (std::function<emscripten::val()> aFn);
emscripten::val WasmJsonApiError        (std::string_view aMessage);

}//namespace Sol::Core::LightWallet
