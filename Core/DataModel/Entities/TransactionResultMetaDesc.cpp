#include "TransactionResultMetaDesc.hpp"

namespace Sol::Core::DataModel {

TYPE_STRUCT_IMPLEMENT(TransactionResultMetaDesc, GP_MODULE_UUID)

TransactionResultMetaDesc::TransactionResultMetaDesc (void) noexcept
{
}

TransactionResultMetaDesc::~TransactionResultMetaDesc (void) noexcept
{
}

void    TransactionResultMetaDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& /*aPropsOut*/)
{
    //TODO: implement meta: https://docs.solana.com/developing/clients/jsonrpc-api#gettransaction
    /*
    "meta": {
      "err": null,
      "fee": 5000,
      "innerInstructions": [],
      "logMessages": [
        "Program Vote111111111111111111111111111111111111111 invoke [1]",
        "Program Vote111111111111111111111111111111111111111 success"
      ],
      "postBalances": [
        396750640579,
        87796487434227,
        1,
        1,
        1
      ],
      "postTokenBalances": [],
      "preBalances": [
        396750645579,
        87796487434227,
        1,
        1,
        1
      ],
      "preTokenBalances": [],
      "rewards": [],
      "status": {
        "Ok": null
      }*/

    /*"meta": {
      "err": null,
      "fee": 5000,
      "innerInstructions": [],
      "logMessages": [
        "Program 11111111111111111111111111111111 invoke [1]",
        "Program 11111111111111111111111111111111 success"
      ],
      "postBalances": [
        999994000,
        0,
        1
      ],
      "postTokenBalances": [],
      "preBalances": [
        1000000000,
        0,
        1
      ],
      "preTokenBalances": [],
      "rewards": [
        {
          "lamports": -1000,
          "postBalance": 0,
          "pubkey": "HQYjxmF9sVrRQH6ywgAvw5F3zpcLsUjWRP7GQ9stSzbK",
          "rewardType": "Rent"
        }
      ],
      "status": {
        "Ok": null
      }
    }*/


    //PROP();
}

}//namespace Sol::Core::DataModel
