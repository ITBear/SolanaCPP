#pragma once

#include "../../../GPlatform/GpCore2/GpCore.hpp"
#include "../../../GPlatform/GpCryptoCore/GpCryptoCore.hpp"
#include "../LightWalletCore/LightWalletCore.hpp"

#if !defined(__EMSCRIPTEN__)
#   error This library can be build only with EMSCRIPTEN
#endif

#include <emscripten.h>
#include <emscripten/bind.h>

using namespace GPlatform;

namespace Sol::Core::LightWallet
{}
