######################################################
## Este archivo es un script esqueleto para compilar 
## proyectos basados en GDT usando CMake
##
## Reemplace todas las apariciones de "skeleton" por 
## el nombre del ejecutable que desea, y tambien cambiele 
## nombre al proyecto por uno a su propio gusto
##
## Tambien si lo necesita, puede agregar/quitar/editar
## otros parametros de compilacion.
##
## Para ello, revise la documentacion de CMake y GCC
##
## Para facilitar un poco el sunto, se incluyen las rutinas
## DEPENDENCIAS.cmake y GDT.cmake
##
###############################################################

PROJECT(SKELETON CXX)

# Parametros del compilador
# -Wall para mostrar todos los warnings y -O2 para optimizar
ADD_DEFINITIONS(-Wall -O2)

FILE(GLOB PROJECT_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
FILE(GLOB PROJECT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Agregar los .cpp al ejecutable
ADD_EXECUTABLE (skeleton ${PROJECT_SOURCES})

## RUTINAS DE COMPROBACION DE DEPENDENCIAS
IF(EXISTS DEPENDENCIAS.cmake)
   INCLUDE(DEPENDENCIAS.cmake)
ELSE(EXISTS DEPENDENCIAS.cmake)
   MESSAGE(FATAL_ERROR "GDT: NO se pueden detectar las dependencias")
ENDIF(EXISTS DEPENDENCIAS.cmake)
IF(EXISTS GDT.cmake)
   INCLUDE(GDT.cmake)
ELSE(EXISTS GDT.cmake)
   MESSAGE(FATAL_ERROR "GDT: NO se pueden detectar GDT")
ENDIF(EXISTS GDT.cmake)


#DETECTAR GRAFICOS
IF(NOT GRAFICOS_FOUND)
   # Irrlicht Es indispensable
   MESSAGE(FATAL_ERROR "GDT: NO se ha encontrado Irrlicht")
ELSE(NOT GRAFICOS_FOUND)

   INCLUDE_DIRECTORIES(${IRRLICHT_INCLUDE_DIR})
   TARGET_LINK_LIBRARIES(skeleton ${IRRLICHT_LIBRARY})

   ## En LINUX, se requiere X11 para dibujar las ventanas.
   IF(NOT WIN32)
      IF(X11_LIBRARIES)
         #
         TARGET_LINK_LIBRARIES(skeleton ${X11_LIBRARIES})
      ELSE(X11_LIBRARIES)
         MESSAGE(FATAL_ERROR "NO SE PUEDE ENLAZAR CON X11")
      ENDIF(X11_LIBRARIES)
   ENDIF(NOT WIN32)

   ## Dibujado OPENGL
   IF(OPENGL_gl_LIBRARY)
      TARGET_LINK_LIBRARIES(skeleton ${OPENGL_gl_LIBRARY})
   ELSE(OPENGL_gl_LIBRARY)
      # GL es Indispensable
      MESSAGE(FATAL_ERROR "NO SE PUEDE ENLAZAR CON OPENGL")
   ENDIF(OPENGL_gl_LIBRARY)

   IF(OPENGL_glu_LIBRARY)
      TARGET_LINK_LIBRARIES(skeleton  ${OPENGL_glu_LIBRARY})
   ELSE(OPENGL_glu_LIBRARY)
      # GLU es Indispensable
      MESSAGE(FATAL_ERROR "NO SE PUEDE ENLAZAR CON OPENGL")
   ENDIF(OPENGL_glu_LIBRARY)

ENDIF(NOT GRAFICOS_FOUND)

## Detectar GDT
IF(NOT GDT_FOUND)
   # GDT Es indispensable
   MESSAGE(FATAL_ERROR "GDT: NO se ha encontrado GDT")
ELSE(NOT GDT_FOUND)
   INCLUDE_DIRECTORIES(${GDT_INCLUDE_DIR} ${IRRLICHT_INCLUDE_DIR} )
   TARGET_LINK_LIBRARIES(skeleton ${GDT_LIBRARY} ${IRRLICHT_LIBRARY})
ENDIF(NOT GDT_FOUND)

# Buscar el sonido
IF(NOT SONIDO_FOUND)
   #Si requiere sonido descomente la proxima linea y comente la siguiente
   #MESSAGE(FATAL_ERROR "GDT: No se encontraron paquetes de sonido OPENAL + ALUT")
   MESSAGE("GDT: No se encontraron paquetes de sonido OPENAL + ALUT")
ELSE(NOT SONIDO_FOUND)
   ADD_DEFINITIONS(-D_GDT_SONIDO_)
   INCLUDE_DIRECTORIES(${OPENAL_INCLUDE_DIR} ${ALUT_INCLUDE_DIR})
   TARGET_LINK_LIBRARIES(skeleton ${OPENAL_LIBRARY} ${ALUT_LIBRARY})
ENDIF(NOT SONIDO_FOUND)

# Buscar decodificador OGG Vorbis
IF(NOT SONIDO_OGG_FOUND)
   #Si requiere OGG descomente la proxima linea y comente la siguiente.
   #MESSAGE(FATAL_ERROR "GDT: No se encontraron paquetes de sonido OGG Vorbis")
   MESSAGE("GDT: No se encontraron paquetes de sonido OGG Vorbis")
ELSE(NOT SONIDO_OGG_FOUND)
   ADD_DEFINITIONS(-D_GDT_SONIDO_OGG_)
   INCLUDE_DIRECTORIES(${OGG_INCLUDE_DIR} ${VORBIS_INCLUDE_DIR})
   TARGET_LINK_LIBRARIES(skeleton ${OGG_LIBRARY} ${VORBIS_LIBRARY} ${VORBISFILE_LIBRARY})
ENDIF(NOT SONIDO_OGG_FOUND)

# Buscar Scripting
IF(NOT SCRIPTING_FOUND)
   #Si requiere OGG descomente la porxima linea y comente la siguiente.
   #MESSAGE(FATAL_ERROR "GDT: No se encontraron paquetes de sonido Lua")
   MESSAGE("GDT: No se encontraron paquetes Lua")
ELSE(NOT SCRIPTING_FOUND)
   ADD_DEFINITIONS(-D_GDT_SCRIPTING_)
   INCLUDE_DIRECTORIES(${LUA_INCLUDE_DIR})
   TARGET_LINK_LIBRARIES(skeleton ${LUA_LIBRARY})
ENDIF(NOT SCRIPTING_FOUND)

# Buscar Fisicas ODE
IF(NOT FISICAS_ODE_FOUND)
   #Si requiere OGG descomente la porxima linea y comente la siguiente.
   #MESSAGE(FATAL_ERROR "GDT: No se encontraron paquetes de fisicas ODE")
   MESSAGE("GDT: No se ha encontrado el paquete de fisicas ODE")
ELSE(NOT FISICAS_ODE_FOUND)
   ADD_DEFINITIONS(-D_GDT_FISICAS_ODE_)
   INCLUDE_DIRECTORIES(${ODE_INCLUDE_DIR})
   TARGET_LINK_LIBRARIES(skeleton ${ODE_LIBRARY})
ENDIF(NOT FISICAS_ODE_FOUND)

# Buscar Fisicas NEWTON
IF(NOT FISICAS_NEWTON_FOUND)
   #Si requiere OGG descomente la porxima linea y comente la siguiente.
   #MESSAGE(FATAL_ERROR "GDT: No se encontraron paquetes de fisicas Newton")
   MESSAGE("GDT: No se ha encontrado el paquete de fisicas Newton")
ELSE(NOT FISICAS_NEWTON_FOUND)
   ADD_DEFINITIONS(-D_GDT_FISICAS_NEWTON_)
   INCLUDE_DIRECTORIES(${NEWTON_INCLUDE_DIR})
   TARGET_LINK_LIBRARIES(skeleton ${NEWTON_LIBRARY})
ENDIF(NOT FISICAS_NEWTON_FOUND)

