#pragma once

#include "../LightWalletCore_global.hpp"

namespace Sol::Core::LightWallet {

class SOL_CORE_LIGHT_WALLET_CORE_API Transaction
{
public:
    CLASS_DECLARE_DEFAULTS(Transaction)

public:
    using NetworkTypeT  = Sol::Core::DataModel::NetworkType;
    using NetworkTypeTE = NetworkTypeT::EnumT;

public:
                                        Transaction     (void) noexcept;
                                        Transaction     (const Transaction& aTransaction);
                                        Transaction     (Transaction&& aTransaction) noexcept;
    virtual                             ~Transaction    (void) noexcept;

    Transaction&                        operator=       (const Transaction& aTransaction);
    Transaction&                        operator=       (Transaction&& aTransaction) noexcept;

public:
    GpVector<GpBytesArray>              signatures;
    Sol::Core::DataModel::MessageDesc   message;
    GpBytesArray                        message_serialized;
};

}//namespace Sol::Core::LightWallet
