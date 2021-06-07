Addr class
==========

.. js:class:: Addr

   This class is designed to work with a specific key pair (not with an :term:`HD wallet` or an :term:`HD Group`).


Static methods
--------------

   The class has no static methods.


Class methods
-------------

.. js:method:: address()

   :returns: A ``string`` containing a :term:`Public-address` (without leading '0x').

   | Method to get a HEX representation of itself (aka :term:`Public-address`).
   | Example:

   .. code-block:: javascript

      //New HD address from HD group
      var hdAddr = GetRes(window.crypto_core_wallet.generate_next_hd_address(crypto_core_hdGroupId));
      var addrStrHex = GetRes(hdAddr.address());
      console.log("New address: " + "0x" + addrStrHex);


.. js:method:: sign_transaction(transaction)

   :param transaction: An object of :js:class:`Transaction` class.
   :returns: An ``object`` of :js:class:`TransactionSign` class.

   | Performs a signature of a :js:class:`Transaction` object.
   | Example:

   .. code-block:: javascript

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


.. js:method:: nonce()

   :returns: A ``string`` containing the current :term:`Nonce` (string representation of SINT64 - max value is 9,223,372,036,854,775,807).

   | Method to get the current :term:`Nonce`, which was set by :js:meth:`set_nonce` method or
     was incremented by :js:meth:`inc_nonce` method.


.. js:method:: set_nonce(nonce)

   :param string nonce: A string representation of :term:`Nonce` to set.
   :returns: ``void``.

   | Set the :term:`Nonce` for this :term:`Address`.


.. js:method:: inc_nonce()

   :returns: A ``string`` containing the incremented :term:`Nonce`.

   | Method to increment the current :term:`Nonce`.


.. js:method:: private_key()

   :returns: A ``string`` HEX representation of the *private key* part of this :term:`Address`.

   | Method to get the HEX representation of the *private key* part of this :term:`Address`.


.. js:method:: name()

   :returns: A ``string`` containing the *name* of this :term:`Address` if any name was set by :js:meth:`set_name` method.

   | Method to set recognizable name to this :term:`Address`.


.. js:method:: set_name(name)

   :param string name: Any recognizable name to assign to this Address.
   :returns: ``void``.

   | Set any recognizable name for this :term:`Address`.


