TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=8f88b916-6dde-49a8-9be9-51c22a776a63
QMAKE_CXXFLAGS += -DGP_TYPE_SYSTEM_STATIC_ADD_TO_MANAGER
DEFINES		   += SOL_CORE_API_CLIENT_LIBRARY
PACKET_NAME     = SolCoreApiClient
DIR_LEVEL       = ./../../

include(../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
	GP_CORE_LIB_V							= 2
	GP_JSON_LIB_V							= 0
	GP_NETWORK_LIB_V						= 0
	GP_API_LIB_V							= 0

	SOL_CORE_DATA_MODEL_ENTITIES_LIB_V		= 0
	SOL_CORE_DATA_MODEL_API_LIB_V			= 0
}

os_linux{
}

LIBS += -lGpCore2$$TARGET_POSTFIX$$GP_CORE_LIB_V
LIBS += -lGpJson$$TARGET_POSTFIX$$GP_JSON_LIB_V
LIBS += -lGpNetwork$$TARGET_POSTFIX$$GP_NETWORK_LIB_V
LIBS += -lGpApi$$TARGET_POSTFIX$$GP_API_LIB_V

LIBS += -lSolCoreDataModelEntities$$TARGET_POSTFIX$$SOL_CORE_DATA_MODEL_ENTITIES_LIB_V
LIBS += -lSolCoreDataModelApi$$TARGET_POSTFIX$$SOL_CORE_DATA_MODEL_API_LIB_V
#------------------------------ LIBS END ---------------------------------

HEADERS += \
	ApiClient.hpp \
	ApiClient_global.hpp

SOURCES += \
	ApiClient.cpp
