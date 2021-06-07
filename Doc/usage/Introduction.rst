Introduction
============

Wasm version on the CryptoCore library is essentially intended to create various web versions of the light :term:`HD Wallet` (BIP-0044).
They can be used both to replace the standard wallets developed by the creators
of the diverse blockchain projects,
as well as for various specialized applications (dApps) based on the blockchain ecosystems.

A `wallet` is a tool for creating asymmetric key pairs and digital signatures for all sort of transactions.
It should have the following main features:

- Random mnemonic phrase generation;
- Creation or recovery an :term:`HD Account` based on a mnemonic phrase;
- Import a private key;
- Generating a random key pair (:term:`Address`);
- Deriving a sequence of key pairs (:term:`HD Addresses <HD Address>`) for the HD Account;
- Finding derived HD Addresses in HD Account;
- Finding :term:`non-HD Addresses <non-HD Address>` (imported or genearated);
- Generating a message for a transaction;
- Signing transaction messages.

In fact, a fully functional wallet must be able to perform many other functions.
Such as, for example, communication with a network node through its API
to obtain information necessary for the transaction, or
storing wallet data between user sessions in a browser.
The implementation of such advanced features is beyond the scope of this lightweight library,
designed to perform basic cryptographic operations in the JavaScript environment.

The specificity of the CryptoCore library algorithms is that they use cryptography on elliptic curves `Ed25519`,
and this is why you can’t use standard `Web Crypto API` present in modern browsers.
Fairly well-known `libSodium` library is most suitable for implementing that algorithms.
This project makes heavy use of the libSodium.

You can read more about the HD Wallets at the following links:

- BIP-0039 - https://github.com/bitcoin/bips/blob/master/bip-0039.mediawiki
- BIP-0032 - https://github.com/bitcoin/bips/blob/master/bip-0032.mediawiki
- BIP32-Ed25519 - https://github.com/orogvany/BIP32-Ed25519-java
- SLIP-0100 - https://github.com/satoshilabs/slips/blob/master/slip-0010.md
- BIP-0044 - https://github.com/bitcoin/bips/blob/master/bip-0044.mediawiki


Installation
------------

To build the project, QMake and EMSCRIPTEN compiler are used. The build process is quite complicated,
so the compiled files are laid out in the assets at the `release section` of corresponding `CryptoCore` project.

Download an archive ``crypto_core_wasm.tar.gz`` from assets on release page of this project.
Then unpack the archive into your project folder.

For use it in the browser project you have to import ``CryptoCoreWasm.js`` into your HTML page: 

.. code-block:: html

    <script src="CryptoCoreWasm.js"></script>

