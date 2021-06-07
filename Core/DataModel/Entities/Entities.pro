TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=2c236c67-dd1a-487e-af09-fa65b82d1104
QMAKE_CXXFLAGS += -DGP_TYPE_SYSTEM_STATIC_ADD_TO_MANAGER
DEFINES		   += SOL_CORE_DATA_MODEL_ENTITIES_LIBRARY
PACKET_NAME     = SolCoreDataModelEntities
DIR_LEVEL       = ./../../../

include(../../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
	GP_CORE_LIB_V = 2
}

os_linux{
}

LIBS += -lGpCore2$$TARGET_POSTFIX$$GP_CORE_LIB_V

#------------------------------ LIBS END ---------------------------------

SOURCES += \
	BuiltinProgramId.cpp \
	InstructionDesc.cpp \
	MessageDesc.cpp \
	MessageHeaderDesc.cpp \
	NetworkType.cpp


HEADERS += \
	BuiltinProgramId.hpp \
	Enentities_global.hpp \
	Entities.hpp \
	InstructionDesc.hpp \
	MessageDesc.hpp \
	MessageHeaderDesc.hpp \
	NetworkType.hpp \
	Units.hpp
