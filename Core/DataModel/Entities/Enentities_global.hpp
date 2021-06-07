#pragma once

#include "../../../../GPlatform/GpCore2/GpCore.hpp"

#if defined(SOL_CORE_DATA_MODEL_ENTITIES_LIBRARY)
    #define SOL_CORE_DATA_MODEL_ENTITIES_API GP_DECL_EXPORT
#else
    #define SOL_CORE_DATA_MODEL_ENTITIES_API GP_DECL_IMPORT
#endif

using namespace GPlatform;

namespace Sol::Core::DataModel
{}
