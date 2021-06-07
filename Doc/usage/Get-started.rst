Getting started
===============

Important notes
---------------

Some methods are **static**
and can be called without creating an object. For example:

.. code-block:: javascript

   var result = Module.CryptoCore<SomeClass>.<someStaticMethod>();


Other methods are members of objects of certain classes.
So at first you have to create an object of certain class and then to call its methods.
In fact, in this library almost always objects are created by some factory method, e.g.:

.. code-block:: javascript

   var myObject = Module.CryptoCore<SomeClass>.<someFactoryMethod>();
   var result = myObject.<someMethod>();


All methods return a result object that always has two important fields -
``error`` and ``data``:

- ``result.error`` - if exists, it contains an exception;
- ``result.data`` -  contains result data.

You can check for errors in the following way:

.. code-block:: html

   <script>
      function GetRes(aRs)
      {
         if (aRs.error)
         {
            throw aRs.error;
         }
         if (aRs.data)
         {
            return aRs.data;
         }
         throw 'Unknown result value: ' + JSON.stringify(aRs);
      }
   </script>


.. warning::
   The methods never throw exceptions related to the logic of the library.
   But the system exceptions can be thrown nonetheless!


The arguments to the methods, which are essentially integers, are passed as string values. 
The reason is that JavaScript cannot work with Big Integers.


Typical usage
-------------

First of all you have to include corresponding JavaScript file into your HTML page:

.. code-block:: html

   <script src="CryptoCoreWasm.js"></script>



Mnemonic phrase generation
~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: html

   <script>
      function NewMnemonicPhrase()
      {
         var mnemonic_phrase = GetRes(Module.CryptoCoreWallet.new_mnemonic_pharase());
         console.log("New mnemonic phrase: '" + mnemonic_phrase + "'");
      }
   </script>


Import mnemonic phrase
~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: html

   <script>
      function ImportMnemonicPhrase()
      {
         // Mnemonic phrase from previous example
         var mnemonic = mnemonic_phrase;
         var password = ""; // optional
         console.log("HD mnemonic phrase '" + mnemonic + "', password = '" + password + "'");

         // New wallet
         if (!window.crypto_core_wallet)
         {
            console.log("Creating a new wallet");
            window.crypto_core_wallet = GetRes(Module.CryptoCoreWallet.new_wallet());
         }

         // New HD Group from mnemonic phrase (we can add multiple HD groups, each will have unique ID)
         console.log("Creating a new HD group...");
         window.crypto_core_hdGroupId = GetRes(window.crypto_core_wallet.add_hd_group(mnemonic, password));
         console.log("New HD group ID = " + window.crypto_core_hdGroupId);

         // New HD Address from HD group
         console.log("Creating a new HD Addreess from HD Group...");
         var hdAddr = GetRes(window.crypto_core_wallet.generate_next_hd_address(window.crypto_core_hdGroupId));
         var addrStrHex = GetRes(hdAddr.address());
         console.log("New address: " + "0x" + addrStrHex);
      }
   </script>


Transaction signature
~~~~~~~~~~~~~~~~~~~~~

.. code-block:: html

    <script>
      function SignTransaction()
      {
         // We will assume that the required data is contained in the corresponding fields of the web form
         var addressStrHex = document.getElementById("hd_address_source").value;
         console.log("Get HD Address from wallet by Address ...");
         var hdAddr = GetRes(window.crypto_core_wallet.find_address(addressStrHex));

         console.log("New transaction...");

         var d = new Date();

         var network   = document.getElementById("transaction_network_source").value;
         var type      = document.getElementById("transaction_type_source").value;
         var to        = document.getElementById("transaction_to_source").value;
         var value     = document.getElementById("transaction_value_source").value;
         var fee       = document.getElementById("transaction_fee_source").value;
         var nonce     = document.getElementById("transaction_nonce_source").value;
         var data      = document.getElementById("transaction_data_source").value;
         var gas       = document.getElementById("transaction_gas_source").value;
         var gas_price = document.getElementById("transaction_gas_price_source").value;

         // Network type
         var network_type = Module.CryptoCoreNetworkType.TESTNET;
         if (network == "MAINNET") network_type = Module.CryptoCoreNetworkType.MAINNET;
         else network_type = Module.CryptoCoreNetworkType.TESTNET;

         // Transaction type
         var transaction_type = Module.CryptoCoreTransactionType.COINBASE;
         if (type == "TRANSFER") transaction_type = Module.CryptoCoreTransactionType.TRANSFER;
         else if (type == "DELEGATE") transaction_type = Module.CryptoCoreTransactionType.DELEGATE;
         else if (type == "VOTE") transaction_type = Module.CryptoCoreTransactionType.VOTE;
         else if (type == "UNVOTE") transaction_type = Module.CryptoCoreTransactionType.UNVOTE;
         else if (type == "CREATE") transaction_type = Module.CryptoCoreTransactionType.CREATE;
         else if (type == "CALL") transaction_type = Module.CryptoCoreTransactionType.CALL;

         var transaction = GetRes(Module.CryptoCoreTransaction.new_transaction(
            network_type,
            transaction_type,
            String(to),
            String(value),
            String(fee),
            String(nonce),
            String(d.getTime()),
            String(data),
            String(gas),
            String(gas_price)
         ));

         console.log("Sign transaction...");
         var transaction_sign = GetRes(hdAddr.sign_transaction(transaction));

         var transaction_hash = GetRes(transaction_sign.hash());
         console.log("Transaction hash '" + transaction_hash + "'");

         var transaction_sign_hex_encoded = GetRes(transaction_sign.encode());
         console.log("Transaction sign hex str '" + transaction_sign_hex_encoded + "'");
      }
   </script>

