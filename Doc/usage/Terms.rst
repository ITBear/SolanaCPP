Terms and Definitions
=====================

.. glossary::

   WebAssembly
      The `WebAssembly <https://webassembly.org/>`_ (abbreviated *Wasm*) is a software technology
      that allows you to use code written in C++ in the JavaScript environment.


   Wallet
      A *wallet* is software that stores a set of key pairs of asymmetric cryptography and 
      allows you to perform transaction signing operations using them.


   HD Group
      An *Hierarchical Deterministic* wallet is a *wallet* that allows deriving hierarchical chains of key pairs
      from the initial master seed in a deterministic way.


   HD Wallet
      The *wallet* that consists of several HD Groups.


   HD Account
      An *HD Account* is a very specific intermediate node in the hierarchy of an HD Group (defined by BIP-044 specification),
      from which all other key pairs are derived.


   Address
      The term *Address* here means an object of the :js:class:`Addr` class, which is essentially a key pair.


   HD Address
      An *HD Address* is one of the *Addresses* in the HD Group hierarchy.


   non-HD Address
      It is single *Address* not associated with the HD Group.
      It can be obtained by importing a private key or random generation.

      .. note::
         This library can simultaneously work with several non-HD addresses,
         and also with several HD Groups.


   Mnemonic phrase
      *Mnemonic phrase* (or mnemonic sentence) - is a group of easy to remember words (space separated)
      for the determinate generation of the master seed (and, accordingly, HD Account) for certain HD Group in HD Wallet.

      A mnemonic code or sentence is superior for human interaction compared to the handling of raw binary
      or hexadecimal representations of a wallet master seed. 
      The sentence could be written on paper or spoken over the telephone.


   Public-address
      Aka *"Hex address"* or *"Recipient address"*.
      It's a hexadecimal string that is the *"official address"* of some wallet
      to which you can, for example, transfer a certain amount of cryptocurrency.


