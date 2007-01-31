PROJECT(GDT CXX)
#include_directories (gdt)
ADD_DEFINITIONS(-Os)

SET(GDT_FROM_ROOT "YES")
MESSAGE("CONFIGURANDO PARA COMPILAR DESDE LA RAIZ")

IF (UNIX)
	SET(LIBRARY_OUTPUT_PATH ${GDT_SOURCE_DIR}/lib/linux-x86)
ENDIF (UNIX)

IF (WIN32)
	SET(LIBRARY_OUTPUT_PATH ${GDT_SOURCE_DIR}/lib/win32)
ENDIF (WIN32)

#INCLUDE (${CMAKE_ROOT}/Modules/FindOpenAL.cmake)
INCLUDE (VIDEO.cmake)
INCLUDE (SONIDO.cmake)
INCLUDE (SCRIPTING.cmake)
INCLUDE (FISICA.cmake)

## DIRECTORIO DE FUENTES DE LA BIBLIOTECA GDT
IF(EXISTS gdt)
	ADD_SUBDIRECTORY (gdt)
ENDIF(EXISTS gdt)

## DIRECTORIO FUENTES DE DEMOS
IF(EXISTS demos)
	ADD_SUBDIRECTORY (demos)
ENDIF(EXISTS demos)

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
    CopyOfCMakeCache.txt
    CMakeCCompiler.cmake
    CMakeCXXCompiler.cmake
    CMakeSystem.cmake
    html latex
    #Doxyfile
    )

  SET(DISTCLEAN_DIRS
    CMakeTmp
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