#add definitions, compiler switches, etc.
#ADD_DEFINITIONS(-Wall -O2)

FILE(GLOB GDT_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
FILE(GLOB GDT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

#build a library
ADD_LIBRARY(gdt SHARED ${GDT_SOURCES})

IF(NOT VIDEO_FOUND)
	MESSAGE(FATAL_ERROR "GDT: NO se encontraron algunos paquetes para el Video")
ENDIF(NOT VIDEO_FOUND)

IF(NOT SONIDO_FOUND)
	MESSAGE(FATAL_ERROR "GDT: NO se encontraron algunos paquetes para el Sistema de Sonido")
ENDIF(NOT SONIDO_FOUND)

IF(NOT SCRIPTING_FOUND)
	MESSAGE("GDT: NO se encontraron algunos paquetes para Scripting.")
	MESSAGE("GDT: Para contar con esta capacidad, instale el paquete de desarrollo de lua5.1")
ENDIF(NOT SCRIPTING_FOUND)

IF(NOT FISICA_FOUND)
	MESSAGE("GDT: NO se encontraron algunos paquetes para Fisicas. Para contar con esta capacidad, instale Newton SDK")
ENDIF(NOT FISICA_FOUND)

IF(VIDEO_FOUND AND SONIDO_FOUND)
   #MESSAGE("Se ha encontrado todo para usar construir la Biblioteca GDT")

   INCLUDE_DIRECTORIES(${OPENAL_INCLUDE_DIR} ${IRRLICHT_INCLUDE_DIR} ${ALUT_INCLUDE_DIR} ${OGG_INCLUDE_DIR} ${VORBIS_INCLUDE_DIR})
   TARGET_LINK_LIBRARIES(gdt ${OPENAL_LIBRARY} ${IRRLICHT_LIBRARY} ${ALUT_LIBRARY} ${OGG_LIBRARY} ${VORBIS_LIBRARY})

ENDIF(VIDEO_FOUND AND SONIDO_FOUND)

IF(SCRIPTING_FOUND)
   MESSAGE("GDT: Se ha encontrado LUA, se puede usar scripting")
   ADD_DEFINITIONS(-D_GDT_SCRIPTING_)
   INCLUDE_DIRECTORIES(${LUA_INCLUDE_DIR})
   TARGET_LINK_LIBRARIES(gdt ${LUA_LIBRARY})
ENDIF(SCRIPTING_FOUND)

IF(FISICA_FOUND)
   MESSAGE("GDT: Se ha encontrado Newton, se puede usar fisicas")
   ADD_DEFINITIONS(-D_GDT_FISICAS_)
   INCLUDE_DIRECTORIES(${NEWTON_INCLUDE_DIR})
   TARGET_LINK_LIBRARIES(gdt ${NEWTON_LIBRARY})
ENDIF(FISICA_FOUND)

#########################
# REGLAS DE INSTALACION #
#########################
INSTALL(FILES ${GDT_HEADERS} DESTINATION include/gdt)

INSTALL(TARGETS gdt LIBRARY
	DESTINATION lib
)