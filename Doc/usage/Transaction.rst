Transaction class
=================

.. js:class:: Transaction

   An object of :js:class:`Transaction` class is created with factory static method :js:meth:`new_transaction` and
   contains all necessary transaction parameters.


Static methods
--------------

.. js:method:: new_transaction(networkType, transactionType, addressToHex, amount, fee, nonce, timestamp, dataHex, gas, gasPrice)

   :param NetworkType networkType: A type of network.
   :param TransactionType transactionType: A type of transaction.
   :param string addressToHex: :term:`Public-address` in string hexadecimal form.
   :param string amount: Amount of payment (integer value `in nano-coin`).
   :param string fee: Amount of fee (integer value `in nano-coin`).
   :param string nonce: A :term:`Nonce` (unique and sequential for the sender).
   :param string timestamp: A timestamp of the transaction (`in milliseconds`).
   :param string dataHex: Some arbitrary text data in string hexadecimal form.
   :param string gas: Amount of `gas`.
   :param string gasPrice: Gas price (integer value `in nano-coin`).
   :returns: ``object`` of :js:class:`Transaction` class.

   | Factory method for creating of :js:class:`Transaction` class object.
   | Example:

   .. code-block:: javascript

      var d = new Date();
      var network_type = Module.CryptoCoreNetworkType.TESTNET;
      var transaction_type = Module.CryptoCoreTransactionType.TRANSFER;
      var to = "0x82c38263217817de2ef28937c7747716eb1e7228";
      var data = "0x756E6F2D6C616273206C696768742077616C6C65742064656D6F"; // "uno-labs light wallet demo" in hex form
      var value = "100000000"; // nano-coin
      var fee = "5000000";     // nano-coin
      var nonce = "533";       // Actually, you have to get it from Node API
      var gas = "0";
      var gas_price = "0";     // nano-coin

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

      var transaction_sign = GetRes(hdAddr.sign_transaction(transaction));

      var transaction_hash = GetRes(transaction_sign.hash());
      console.log("Transaction hash '" + transaction_hash + "'");

      var transaction_sign_hex_encoded = GetRes(transaction_sign.encode());
      console.log("Transaction sign hex str '" + transaction_sign_hex_encoded + "'");


Class methods
-------------

.. js:method:: encode()

   :returns: An encoded ``string`` of :js:class:`Transaction` object.

   | Method to get an encoded representation of itself.



Getters
-------

There are also some "getters" methods in the class:

      - network_type()
      - transaction_type()
      - address_to()
      - value()
      - fee()
      - nonce()
      - timestamp()
      - data()
      - gas()
      - gas_price()


