#pragma once

#include "../Wallet/Transaction.hpp"

namespace Sol::Core::LightWallet {

class SOL_CORE_LIGHT_WALLET_CORE_API Serializator
{
    CLASS_REMOVE_CTRS(Serializator)

public:
    static GpBytesArray SSerialize      (const Transaction& aTransaction);
    static GpBytesArray SSerializeNoSig (const Transaction& aTransaction);
    static void         SSerialize      (const Transaction& aTransaction,
                                         GpByteWriter&      aWriter);
    static void         SSerializeNoSig (const Transaction& aTransaction,
                                         GpByteWriter&      aWriter);
    static void         SSerialize      (const Sol::Core::DataModel::MessageDesc&   aMessage,
                                         GpByteWriter&                              aWriter);
    static void         SSerialize      (const Sol::Core::DataModel::MessageHeaderDesc& aMessageHeader,
                                         GpByteWriter&                                  aWriter);
    static void         SSerialize      (const GpVector<Sol::Core::DataModel::InstructionDesc::SP>& aInstructions,
                                         GpByteWriter&                                              aWriter);
    static void         SSerialize      (const Sol::Core::DataModel::InstructionDesc&   aInstruction,
                                         GpByteWriter&                                  aWriter);
    static void         SSerialize      (const GpBytesArray&    aByteBuffer,
                                         GpByteWriter&          aWriter,
                                         const bool             aWriteLen);
    static void         SSerialize      (const GpVector<GpBytesArray>&  aArrayOfBuffers,
                                         GpByteWriter&                  aWriter,
                                         const bool                     aWriteElementLen);
    static void         SSerialize      (const GpVector<count_t>&   aArrayOfIdx,
                                         GpByteWriter&              aWriter);

};

}//Sol::Core::LightWallet
