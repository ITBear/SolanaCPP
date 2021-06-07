#include "WasmUtils.hpp"

namespace Sol::Core::LightWallet {

emscripten::val WasmExceptionCatcher(std::function<emscripten::val()> aFn)
{
    emscripten::val resVal = emscripten::val::object();

    try
    {
        resVal.set("data", aFn());
    } catch (const std::exception& e)
    {
        resVal = WasmJsonApiError(e.what());
    } catch (...)
    {
        resVal = WasmJsonApiError("Unknown exception"_sv);
    }

    return resVal;
}

emscripten::val WasmJsonApiError (std::string_view aMessage)
{
    emscripten::val error = emscripten::val::object();

    error.set("error", std::string(aMessage));

    return error;
}

}//namespace Sol::Core::LightWallet
