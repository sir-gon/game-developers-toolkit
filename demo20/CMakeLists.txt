#add definitions, compiler switches, etc.
#ADD_DEFINITIONS(-Wall -O2)
ADD_DEFINITIONS(-O2)

# Make sure the compiler can find include files from our Hello library.
include_directories (${GDT_SOURCE_DIR}/gdt)

# Make sure the linker can find the Hello library once it is built.
LINK_DIRECTORIES (${HELLO_BINARY_DIR}/gdt)

# Add executable called "helloDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx".  The extensions are automatically found.
ADD_EXECUTABLE (gdtDemo main.cpp)

#
#INCLUDE (${CMAKE_ROOT}/Modules/FindOpenAL.cmake)
INCLUDE (../VIDEO.cmake)
INCLUDE (../SONIDO.cmake)
INCLUDE (../SCRIPTING.cmake)
#INCLUDE (../FISICA.cmake)

IF(NOT VIDEO_FOUND)
	MESSAGE(FATAL_ERROR "GDT: NO se encontraron algunos paquetes para el Video")
ENDIF(NOT VIDEO_FOUND)

IF(NOT SONIDO_FOUND)
	MESSAGE(FATAL_ERROR "GDT: NO se encontraron algunos paquetes para el Sistema de Sonido")
ENDIF(NOT SONIDO_FOUND)

#IF(NOT FISICA_FOUND)
#	MESSAGE(FATAL_ERROR "NO se encontraron algunos paquetes para Física")
#ENDIF(NOT FISICA_FOUND)

IF(VIDEO_FOUND AND SONIDO_FOUND)
   #MESSAGE("Se ha encontrado todo para usar construir la Biblioteca GDT")

   INCLUDE_DIRECTORIES(${OPENAL_INCLUDE_DIR} ${IRRLICHT_INCLUDE_DIR} ${ALUT_INCLUDE_DIR} ${OGG_INCLUDE_DIR} ${VORBIS_INCLUDE_DIR})
   TARGET_LINK_LIBRARIES(gdtDemo gdt ${OPENAL_LIBRARY} ${IRRLICHT_LIBRARY} ${ALUT_LIBRARY} ${OGG_LIBRARY} ${VORBIS_LIBRARY})

ENDIF(VIDEO_FOUND AND SONIDO_FOUND)

IF(SCRIPTING_FOUND)
   INCLUDE_DIRECTORIES(${LUA_INCLUDE_DIR})
   TARGET_LINK_LIBRARIES(gdtDemo ${LUA_LIBRARY})
ELSE(SCRIPTING_FOUND)
   MESSAGE(FATAL_ERROR "NO SE PUEDE ENLAZAR CON LUA")
ENDIF(SCRIPTING_FOUND)

########################################################################################
########################################################################################
########################################################################################

IF(NOT WIN32)
	IF(X11_LIBRARIES)
		TARGET_LINK_LIBRARIES(gdtDemo ${X11_LIBRARIES})
	ELSE(X11_LIBRARIES)
		MESSAGE(FATAL_ERROR "NO SE PUEDE ENLAZAR CON X11")
	ENDIF(X11_LIBRARIES)
ENDIF(NOT WIN32)

IF(OPENGL_gl_LIBRARY)
   TARGET_LINK_LIBRARIES(gdtDemo ${OPENGL_gl_LIBRARY})
ELSE(OPENGL_gl_LIBRARY)
   MESSAGE(FATAL_ERROR "NO SE PUEDE ENLAZAR CON OPENGL")
ENDIF(OPENGL_gl_LIBRARY)

IF(OPENGL_glu_LIBRARY)
   TARGET_LINK_LIBRARIES(gdtDemo ${OPENGL_glu_LIBRARY})
ELSE(OPENGL_glu_LIBRARY)
   MESSAGE(FATAL_ERROR "NO SE PUEDE ENLAZAR CON OPENGL")
ENDIF(OPENGL_glu_LIBRARY)

IF(VORBISFILE_LIBRARY)
   TARGET_LINK_LIBRARIES(gdtDemo ${VORBISFILE_LIBRARY})
ELSE(VORBISFILE_LIBRARY)
   MESSAGE(FATAL_ERROR "NO SE PUEDE ENLAZAR CON VORBISFILE")
ENDIF(VORBISFILE_LIBRARY)
