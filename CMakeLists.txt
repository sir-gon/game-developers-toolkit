PROJECT(GDT CXX)

ADD_DEFINITIONS(-Os)

SET(GDT_FROM_ROOT "YES")

MESSAGE("CONFIGURANDO PARA COMPILAR DESDE LA RAIZ")
MESSAGE("Directorio actual: " ${CMAKE_CURRENT_SOURCE_DIR})

SET(OBJETOS ${CMAKE_CURRENT_SOURCE_DIR}/OBJS)
SET(CMAKE_BINARY_DIR ${OBJETOS})
SET(CMAKE_FILES_DIRECTORY ${OBJETOS})
SET(PROJECT_BINARY_DIR ${OBJETOS})

IF (UNIX)
	SET(LIBRARY_OUTPUT_PATH ${GDT_SOURCE_DIR}/lib/linux-x86)
	SET(OBJETOS ${CMAKE_CURRENT_SOURCE_DIR}/OBJS/linux-x86)
	SET(CMAKE_BINARY_DIR ${OBJETOS})
ENDIF (UNIX)

IF (WIN32)
	SET(LIBRARY_OUTPUT_PATH ${GDT_SOURCE_DIR}/lib/win32)
ENDIF (WIN32)

MESSAGE("GDT_ROOT: Directorio de salida de bibliotecas: " ${LIBRARY_OUTPUT_PATH})
MESSAGE("GDT_ROOT: Directorio de salida de objetos: " ${CMAKE_BINARY_DIR})

## RUTINAS DE COMPROBACION DE DEPENDENCIAS
INCLUDE (DEPENDENCIAS.cmake)

## DIRECTORIO DE FUENTES DE LA BIBLIOTECA GDT
IF(EXISTS gdt)
	MESSAGE("+------------------------------------------+")
	MESSAGE("|AVISO: se va a construir la biblioteca GDT|")
	MESSAGE("+------------------------------------------+")
	ADD_SUBDIRECTORY (gdt ${OBJETOS}/gdt)
ELSE(EXISTS gdt)
	MESSAGE("AVISO: NO se va a construir la biblioteca GDT")
ENDIF(EXISTS gdt)

## DIRECTORIO FUENTES DE DEMOS
IF(EXISTS demos)
	MESSAGE("+------------------------------------+")
	MESSAGE("|AVISO: se pueden construir los demos|")
	MESSAGE("+------------------------------------+")
	ADD_SUBDIRECTORY (demos ${OBJETOS}/demo)
ELSE(EXISTS demos)
	MESSAGE("+--------------------------------------+")
	MESSAGE("|AVISO: NO se puede construir los demos|")
	MESSAGE("+--------------------------------------+")
ENDIF(EXISTS demos)

## AGREGAR OBJETIVO doc (documentacion)

#cd '/home/gon/dev/libgdt' && doxygen Doxyfile && cd '../gdtdoc/html' && doxytag -s search.idx 
IF (UNIX)
  ADD_CUSTOM_TARGET(doc)
  
  ADD_CUSTOM_COMMAND(
    TARGET doc
    PRE_BUILD
    COMMAND	doxygen
    ARGS	Doxyfile
    )

  ADD_CUSTOM_COMMAND(
    TARGET doc
    PRE_BUILD
    COMMAND	cd
    ARGS	'../gdtdoc/html'
    )

  ADD_CUSTOM_COMMAND(
    TARGET doc
    PRE_BUILD
    COMMAND	doxytag
    ARGS	-s search.idx
    )

ENDIF(UNIX)

## AGREGAR OBJETIVO "distclean"
## EXTRAIDO DE http://www.mip.informatik.uni-kiel.de/~jw/cmake/CMakeModules/TargetDistclean.cmake
## EDITADO POR SIR_GON http://devgon.worpress.com
# add custom target distclean
# cleans and removes cmake generated files etc.
# Jan Woetzel 04/2003
# www.mip.informatik.uni-kiel.de/~jw
##
# TODO : change rm/delete to cmake -E 's built in delete (JW)
##
IF (UNIX)
  ADD_CUSTOM_TARGET(distclean)
  ADD_DEPENDENCIES (distclean clean)

  SET(DISTCLEAN_FILES
    cmake.depends
    cmake.check_depends
    CMakeCache.txt
    cmake.check_cache
    CMakeOutput.log
    core core.*
    gmon.out bb.out
    *~
    *%
    SunWS_cache
    ii_files
    *.so
    *.o
    *.a
    *.ncb
    CopyOfCMakeCache.txt
    CMakeCCompiler.cmake
    CMakeCXXCompiler.cmake
    CMakeSystem.cmake
    html latex
    GDT.kdev*
    #Doxyfile
    )

  SET(DISTCLEAN_DIRS
    CMakeTmp
    #CMakeFiles
    OBJS
    )

SET(DISTCLEAN_RECURSIVE_FILES
  CMakeCache.txt

  progress.make
  Makefile
  cmake_install.cmake
  cmake.check_depends
  cmake.depends
)

  # for 1.8.x:
  ADD_CUSTOM_COMMAND(
    TARGET distclean
    PRE_BUILD
    COMMAND rm
    ARGS    -Rf ${DISTCLEAN_FILES} ${DISTCLEAN_DIRS}
   COMMENT
    )

  FOREACH(RMTARGET ${DISTCLEAN_RECURSIVE_FILES})
    ADD_CUSTOM_COMMAND(
      TARGET distclean
      PRE_BUILD
      COMMAND find
      ARGS . -wholename ${RMTARGET} -exec rm -R "{}" "\;"
      COMMENT
      )
  ENDFOREACH(RMTARGET ${DISTCLEAN_RECURSIVE_FILES})

ENDIF(UNIX)