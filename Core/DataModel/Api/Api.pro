TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=066b1d6c-24e4-4710-8c7f-6b009029669c
QMAKE_CXXFLAGS += -DGP_TYPE_SYSTEM_STATIC_ADD_TO_MANAGER
DEFINES		   += SOL_CORE_DATA_MODEL_API_LIBRARY
PACKET_NAME     = SolCoreDataModelApi
DIR_LEVEL       = ./../../../

include(../../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
	GP_CORE_LIB_V	= 2

	SOL_LIB_V		= 0
}

os_linux{
}

LIBS += -lGpCore2$$TARGET_POSTFIX$$GP_CORE_LIB_V

LIBS += -lSolCoreDataModelEntities$$TARGET_POSTFIX$$SOL_LIB_V
#------------------------------ LIBS END ---------------------------------

SOURCES += \
	Methods/getBalance.cpp \
	Methods/getRecentBlockhash.cpp \
	Methods/getTransaction.cpp \
	Methods/getTransactionCount.cpp \
	Methods/getVersion.cpp \
	Methods/requestAirdrop.cpp \
	Methods/sendTransaction.cpp

HEADERS += \
    Api_global.hpp \
	Api.hpp \
	Methods/Methods.hpp \
	Methods/getBalance.hpp \
	Methods/getRecentBlockhash.hpp \
	Methods/getTransaction.hpp \
	Methods/getTransactionCount.hpp \
	Methods/getVersion.hpp \
	Methods/requestAirdrop.hpp \
	Methods/sendTransaction.hpp
