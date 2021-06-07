Wallet class
===============

.. js:class:: Wallet

   An object of this class is not created using the ``new`` operator,
   but is returned by the static factory method :js:meth:`new_wallet`.


Static methods
--------------

.. js:method:: new_mnemonic_phrase()

   :returns: A ``string`` containing generated :term:`Mnemonic phrase`.

   | Generates a new mnemonic phrase.
   | Example:

   .. code-block:: javascript

      var mnemonic_phrase = GetRes(Module.CryptoCoreWallet.new_mnemonic_pharase());
      console.log("New mnemonic phrase '" + mnemonic_phrase + "'");


.. js:method:: new_wallet()

   :returns: An ``object`` of :js:class:`Wallet` class.

   | Factory static method to create a new object of `Wallet` class.
   | Example:

   .. code-block:: javascript

      if (!window.crypto_core_wallet)
      {
         console.log("New wallet");
         window.crypto_core_wallet = GetRes(Module.CryptoCoreWallet.new_wallet());
      }



Class methods
-------------

.. js:method:: add_hd_group(mnemonic, password)

   :param String mnemonic: A mnemonic phrase to import from.
   :param String password: An optional password for mnemonic import.
   :returns: ``sInt64`` a new Group ID.

   | Method for creating a new :term:`HD Group` in the :term:`HD Wallet`.
   | Further, the returned ID is used for operations with :term:`HD Address` es.

   .. code-block:: javascript

      var crypto_core_hdGroupId = GetRes(window.crypto_core_wallet.add_hd_group(mnemonic, password));
      console.log("New HD group ID = " + crypto_core_hdGroupId);


.. js:method:: delete_hd_group(groupID)

   :param String groupID: The :term:`HD Group` ID to delete from the :term:`HD Wallet`.

   | Method for deletion the :term:`HD Group` by given `groupID`.


.. js:method:: generate_next_hd_address(groupID)

   :param String groupID: The ID of the :term:`HD Group`, that is used to get the next :term:`HD Address`.
   :returns: An ``object`` of :js:class:`Addr` class.

   | Method for deriving the next :term:`HD Address` for the :term:`HD Group` by given `groupID` parameter.
   | Example:

   .. code-block:: javascript

      var hdAddr = GetRes(window.crypto_core_wallet.generate_next_hd_address(crypto_core_hdGroupId));


.. js:method:: generate_random_address()

   :returns: An ``object`` of :js:class:`Addr` class.

   | Method for generating a random :term:`Address` not associated with any :term:`HD Group`.


.. js:method:: delete_address(hexAddress)

   :param String hexAddress: The :term:`Public-address` representation of :term:`Address` to delete from the :term:`Wallet`.

   | Method for deletion the :term:`Address` from the :term:`Wallet` by given :term:`Public-address`.


.. js:method:: find_address(hexAddress)

   :param String hexAddress: The :term:`Public-address` representation of :term:`Address` to find in the :term:`Wallet`.
   :returns: An ``object`` of :js:class:`Addr` class.

   | Method for finding and getting the ``object`` of :js:class:`Addr` class in the :term:`Wallet` by given :term:`Public-address`.


.. js:method::serialize(password)

   :param String password: The password to encrypt the serialization.
   :returns: A ``String`` containing the HEX serialized :term:`Wallet`.

   | Method to serialize the :term:`Wallet` with the purpose of storing it aside.


.. js:method::deserialize(hexSerializedWallet, password)

   :param String hexSerializedWallet: A string hex representation of the serialized wallet.
   :param String password: The password to decrypt the serialized wallet.

   | Method to deserialize the :term:`Wallet` which was stored aside.


