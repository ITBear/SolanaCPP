#include "Transaction.hpp"

namespace Sol::Core::LightWallet {

Transaction::Transaction (void) noexcept
{
}

Transaction::Transaction (const Transaction& aTransaction):
signatures(aTransaction.signatures),
message(aTransaction.message),
message_serialized(aTransaction.message_serialized)
{
}

Transaction::Transaction (Transaction&& aTransaction) noexcept:
signatures(std::move(aTransaction.signatures)),
message(std::move(aTransaction.message)),
message_serialized(std::move(aTransaction.message_serialized))
{
}

Transaction::~Transaction (void) noexcept
{
}

Transaction&    Transaction::operator= (const Transaction& aTransaction)
{
    signatures          = aTransaction.signatures;
    message             = aTransaction.message;
    message_serialized  = aTransaction.message_serialized;

    return *this;
}

Transaction&    Transaction::operator= (Transaction&& aTransaction) noexcept
{
    signatures          = std::move(aTransaction.signatures);
    message             = std::move(aTransaction.message);
    message_serialized  = std::move(aTransaction.message_serialized);

    return *this;
}

}//namespace Sol::Core::LightWallet
