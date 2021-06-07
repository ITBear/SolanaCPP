TEMPLATE        = app
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=8baed363-f79e-45fc-b589-6230620befa7
QMAKE_CXXFLAGS += -DGP_TYPE_SYSTEM_STATIC_ADD_TO_MANAGER
DEFINES		   += SOL_CORE_LIGHT_WALLET_CORE_WASM_LIBRARY
PACKET_NAME     = SolCoreLightWalletCoreWasm
DIR_LEVEL       = ./../../

include(../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
	GP_CORE_LIB_V						= 2
	GP_CRYPTO_CORE_LIB_V				= 0

	SOL_CORE_DATA_MODEL_ENTITIES_LIB_V	= 0
	SOL_CORE_LIGHT_WALLET_CORE_LIB_V	= 0
}

LIBS += -lsodium
LIBS += -lgmp
LIBS += -lgmpxx
LIBS += -lutf8proc$$TARGET_POSTFIX
LIBS += -lGpCore2$$TARGET_POSTFIX$$GP_CORE_LIB_V
LIBS += -lGpCryptoCore$$TARGET_POSTFIX$$GP_CRYPTO_CORE_LIB_V

LIBS += -lSolCoreDataModelEntities$$TARGET_POSTFIX$$SOL_CORE_DATA_MODEL_ENTITIES_LIB_V
LIBS += -lSolCoreLightWalletCore$$TARGET_POSTFIX$$SOL_CORE_LIGHT_WALLET_CORE_LIB_V
#------------------------------ LIBS END ---------------------------------

SOURCES += \
	Wallet/AddressWasm.cpp \
	Wallet/WalletWasm.cpp \
	WasmUtils/WasmUtils.cpp

HEADERS += \
	LightWalletCoreWasm_global.hpp \
	Wallet/AddressWasm.hpp \
	Wallet/WalletWasm.hpp \
	WasmUtils/WasmUtils.hpp
