#pragma once

#include "Address.hpp"
#include "SystemInstruction.hpp"

namespace Sol::Core::LightWallet {

class SOL_CORE_LIGHT_WALLET_CORE_API SystemDataBuilder
{
    CLASS_REMOVE_CTRS(SystemDataBuilder);

public:
    //Create accounts and transfer lamports between them
    static GpBytesArray         SCreateAccount      (const lamport_t        aLamports,
                                                     const size_byte_t      aSpace,
                                                     const GpRawPtrByteR    aProgramId);

    //Assign
    static GpBytesArray         SAssign             (const GpRawPtrByteR    aProgramId);

    //Transfer lamports between accounts
    static GpBytesArray         STransfer           (const lamport_t        aLamports);
};

}//namespace Sol::Core::LightWallet
