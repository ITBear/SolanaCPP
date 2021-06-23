#pragma once

#include "../LightWalletCore_global.hpp"

namespace Sol::Core::LightWallet {

class SOL_CORE_LIGHT_WALLET_CORE_API Serializator
{
    CLASS_REMOVE_CTRS(Serializator)

public:
    using TransactionT = Sol::Core::DataModel::TransactionDesc;

public:
    static GpBytesArray SSerialize      (const TransactionT& aTransaction);
    static GpBytesArray SSerializeNoSig (const TransactionT& aTransaction);
    static void         SSerialize      (const TransactionT&    aTransaction,
                                         GpByteWriter&          aWriter);
    static void         SSerializeNoSig (const TransactionT&    aTransaction,
                                         GpByteWriter&          aWriter);
    static void         SSerialize      (const Sol::Core::DataModel::MessageDesc&   aMessage,
                                         GpByteWriter&                              aWriter);

private:
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
