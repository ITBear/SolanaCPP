TEMPLATE        = app
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=593abd67-f316-45ad-8b30-9faa0570c4dc
QMAKE_CXXFLAGS += -DGP_TYPE_SYSTEM_STATIC_ADD_TO_MANAGER
PACKET_NAME     = SolExampleWallet
DIR_LEVEL       = ./../../

include(../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
	GP_CORE_LIB_V			= 2
	GP_CRYPTO_CORE_LIB_V	= 0
	GP_UTF8_PROC_LIB_V		= 0
	GP_JSON_LIB_V			= 0
	GP_NETWORK_LIB_V		= 0
	GP_API_LIB_V			= 0
	GP_API_HTTP_LIB_V		= 0

	SOL_LIB_V				= 0

	BOOST_LIB_POSTFIX		= -mgw82-mt-x64-1_75
}

os_linux
{
}

os_browser
{
}

LIBS += -lGpCore2$$TARGET_POSTFIX$$GP_CORE_LIB_V
LIBS += -lGpCryptoCore$$TARGET_POSTFIX$$GP_CRYPTO_CORE_LIB_V
LIBS += -lGpJson$$TARGET_POSTFIX$$GP_JSON_LIB_V
LIBS += -lGpNetwork$$TARGET_POSTFIX$$GP_NETWORK_LIB_V
LIBS += -lGpApi$$TARGET_POSTFIX$$GP_API_LIB_V
LIBS += -lGpApiHttp$$TARGET_POSTFIX$$GP_API_HTTP_LIB_V

LIBS += -lSolCoreDataModelEntities$$TARGET_POSTFIX$$SOL_LIB_V
LIBS += -lSolCoreDataModelApi$$TARGET_POSTFIX$$SOL_LIB_V
LIBS += -lSolCoreLightWalletCore$$TARGET_POSTFIX$$SOL_LIB_V
LIBS += -lSolCoreApiClient$$TARGET_POSTFIX$$SOL_LIB_V

LIBS += -lutf8proc$$TARGET_POSTFIX$$GP_UTF8_PROC_LIB_V
LIBS += -lsodium
LIBS += -lgmp
LIBS += -lgmpxx
LIBS += -lpthread
LIBS += -lboost_context

#------------------------------ LIBS END ---------------------------------

HEADERS += \
	Wallet_global.hpp

SOURCES += \
	main.cpp
