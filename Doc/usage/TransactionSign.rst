TransactionSign class
=====================

.. js:class:: TransactionSign

   An object of this class is not created using the ``new`` operator,
   but is returned by the :js:meth:`sign_transaction` method of :js:class:`Addr` object.

   Actually, the :js:class:`TransactionSign` objects are storage for the following data:

      - encoded transaction data;
      - a transaction hash (Blake2B);
      - a sign of hash;
      - the public key (with no prefix) of the `key pair` with which the signature was made.


Class methods
-------------

.. js:method:: data()

   :returns: A ``string`` containing encoded transaction data.

   | Method to get encoded transaction data.


.. js:method:: hash()

   :returns: A ``string`` containing a hash (Blake2B) of the transaction data.

   | Method to get a hash of the transaction data.


.. js:method:: sign()

   :returns: A ``string`` containing a sign of the transaction data hash.

   | Method to get a sign of the transaction data hash.


.. js:method:: public_key()

   :returns: A ``string`` containing the public key.

   | Method to get the public key (with no prefix) of the `key pair` with which the signature was made.


.. js:method:: encode()

   :returns: A ``string`` containing encoded :js:class:`TransactionSign` object.

   | Encode all data contained in this object in order to prepare before sending to the blockchain network.
   | Example:

   .. code-block:: javascript

      var transaction_sign = GetRes(hdAddr.sign_transaction(transaction));

      var transaction_hash = GetRes(transaction_sign.hash());
      console.log("Transaction hash '" + transaction_hash + "'");

      var transaction_sign_hex_encoded = GetRes(transaction_sign.encode());
      console.log("Transaction sign hex str '" + transaction_sign_hex_encoded + "'");

