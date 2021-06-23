TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 1
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=1b4c6d4d-e554-43c1-8435-b440ff2b6296
QMAKE_CXXFLAGS += -DGP_TYPE_SYSTEM_STATIC_ADD_TO_MANAGER
DEFINES		   += SOL_CORE_LIGHT_WALLET_CORE_LIBRARY
PACKET_NAME     = SolCoreLightWalletCore
DIR_LEVEL       = ./../../

include(../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
	GP_CORE_LIB_V			= 2
	GP_CRYPTO_CORE_LIB_V	= 0

	SOL_LIB_V				= 0
}

os_linux{
}

LIBS += -lGpCore2$$TARGET_POSTFIX$$GP_CORE_LIB_V
LIBS += -lGpCryptoCore$$TARGET_POSTFIX$$GP_CRYPTO_CORE_LIB_V

LIBS += -lSolCoreDataModelEntities$$TARGET_POSTFIX$$SOL_LIB_V
#------------------------------ LIBS END ---------------------------------

SOURCES += \
	LightWalletCore.cpp \
	Utils/Serializator.cpp \
	Wallet/Address.cpp \
	Wallet/AddressFactory.cpp \
	Wallet/InstructionBuilder.cpp \
	Wallet/ProgramIds.cpp \
	Wallet/SystemDataBuilder.cpp \
	Wallet/SystemInstruction.cpp \
	Wallet/TransactionBuilder.cpp \
	Wallet/Wallet.cpp

HEADERS += \
	LightWalletCore.hpp \
	LightWalletCore_global.hpp \
	Utils/Serializator.hpp \
	Utils/Units.hpp \
	Utils/Utils.hpp \
	Wallet/Address.hpp \
	Wallet/AddressFactory.hpp \
	Wallet/InstructionBuilder.hpp \
	Wallet/ProgramIds.hpp \
	Wallet/SystemDataBuilder.hpp \
	Wallet/SystemInstruction.hpp \
	Wallet/TransactionBuilder.hpp \
	Wallet/Wallet.hpp
