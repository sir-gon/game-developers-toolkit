###############################################################
# Este script de CMake solo busca las librerias que se pueden #
# usar con GDT.                                               #
#                                                             #
# La siguiente lista enumera las variables que se definen     #
# luego de hacer las comprobaciones. Puede usarlas en su      #
# proyecto para decidir si va a compilar con ellas o no.      #
#                                                             #
# Todas se pueden evaluar como verdadero/falso, pero recuerde #
# tambien guardan el valor de las rutas encontradas           #
#                                                             #
# Estas son las variables definidas                           #
# * IRRLICHT_INCLUDE_DIR                                      #
# * IRRLICHT_LIBRARY                                          #
# * OPENGL_gl_LIBRARY                                         #
# * OPENGL_glu_LIBRARY                                        #
# * X11_LIBRARIES # en sistemas unix                          #
# * OPENAL_INCLUDE_DIR                                        #
# * OPENAL_LIBRARY                                            #
# * ALUT_INCLUDE_DIR                                          #
# * ALUT_LIBRARY                                              #
# * OGG_INCLUDE                                               #
# * OGG_LIBRARY                                               #
# * VORBIS_INCLUDE_DIR                                        #
# * VORBIS_LIBRARY                                            #
# * VORBISFILE_LIBRARY                                        #
# * LUA_INCLUDE_DIR                                           #
# * LUA_LIBRARY                                               #
# * ODE_INCLUDE_DIR                                           #
# * ODE_LIBRARY                                               #
# * NEWTON_INCLUDE_DIR                                        #
# * NEWTON_LIBRARY                                            #
###############################################################

## PARA EVITAR HACER LA COMPROBACION MAS DE UNA VEZ
IF(NOT DEPENDENCIAS)
	SET(DEPENDENCIAS "YES")

########################
## Librerias graficas ##
########################
IF(NOT WIN32)
	# BUSCAR CABECERAS IRRLICHT
	FIND_PATH(IRRLICHT_INCLUDE_DIR irrlicht.h
		$ENV{IRRLICHTDIR}/include
		/usr/local/include/irrlicht
		/usr/local/include/Irrlicht
		/usr/local/include
		/usr/include/irrlicht
		/usr/include/Irrlicht
		/usr/include
		../../include/irrlicht
		)
	
	# BUSCAR LIBRERIA IRRLICHT
	FIND_LIBRARY(IRRLICHT_LIBRARY Irrlicht
		$ENV{IRRLICHTDIR}/lib/Linux
		/usr/local/lib
		/usr/lib
		/sw/lib
		/opt/local/lib
		/opt/csw/lib
		/opt/lib
		)

	# BUSCAR BIBLIOTECA GL
	FIND_LIBRARY(OPENGL_gl_LIBRARY GL
		/usr/local/lib
		/usr/lib
		/sw/lib
		/opt/local/lib
		/opt/csw/lib
		/opt/lib
		)

	FIND_LIBRARY(OPENGL_glu_LIBRARY GLU
		/usr/local/lib
		/usr/lib
		/sw/lib
		/opt/local/lib
		/opt/csw/lib
		/opt/lib
		)

	# BUSCAR LIBRERIAS DE X11
	FIND_LIBRARY(X11_LIBRARIES Xxf86vm #NAMES Xxf86vm Xext X11
		PATHS
		/usr/local/lib
		/usr/lib
		/sw/lib
		/opt/local/lib
		/opt/csw/lib
		/opt/lib
		)
	
	IF(NOT OPENGL_gl_LIBRARY)
		MESSAGE("DEPS: NO SE HA ENCONTRADO LA BIBLIOTECA GL")
	ENDIF(NOT OPENGL_gl_LIBRARY)
	
	IF(NOT OPENGL_glu_LIBRARY)
		MESSAGE("DEPS: NO SE HA ENCONTRADO LA BIBLIOTECA GLU")
	ENDIF(NOT OPENGL_glu_LIBRARY)

	IF(NOT X11_LIBRARIES)
		MESSAGE("DEPS: NO SE HAN ENCONTRADO BIBLIOTECAS DE X11")
	ENDIF(NOT X11_LIBRARIES)

########################
## Librerias de audio ##
########################
# BUSCAR CABECERAS DE OPENAL
FIND_PATH(OPENAL_INCLUDE_DIR NAMES al.h alc.h
  PATHS
  $ENV{OPENALDIR}/include
  ~/Library/Frameworks/OpenAL.framework/Headers
  /Library/Frameworks/OpenAL.framework/Headers
  /System/Library/Frameworks/OpenAL.framework/Headers # Tiger
  /usr/local/include/AL
  /usr/local/include/OpenAL
  /usr/local/include
  /usr/include/AL
  /usr/include/OpenAL
  /usr/include
  /sw/include/AL # Fink
  /sw/include/OpenAL 
  /sw/include
  /opt/local/include/AL # DarwinPorts
  /opt/local/include/OpenAL
  /opt/local/include
  /opt/csw/include/AL # Blastwave
  /opt/csw/include/OpenAL
  /opt/csw/include
  /opt/include/AL
  /opt/include/OpenAL
  /opt/include
  )

# I'm not sure if I should do a special casing for Apple. It is 
# unlikely that other Unix systems will find the framework path.
# But if they do ([Next|Open|GNU]Step?), 
# do they want the -framework option also?
IF(${OPENAL_INCLUDE_DIR} MATCHES ".framework")
  STRING(REGEX REPLACE "(.*)/.*\\.framework/.*" "\\1" OPENAL_FRAMEWORK_PATH_TMP ${OPENAL_INCLUDE_DIR})
  IF("${OPENAL_FRAMEWORK_PATH_TMP}" STREQUAL "/Library/Frameworks"
      OR "${OPENAL_FRAMEWORK_PATH_TMP}" STREQUAL "/System/Library/Frameworks"
      )
    # String is in default search path, don't need to use -F
    SET (OPENAL_LIBRARY "-framework OpenAL" CACHE STRING "OpenAL framework for OSX")
  ELSE("${OPENAL_FRAMEWORK_PATH_TMP}" STREQUAL "/Library/Frameworks"
      OR "${OPENAL_FRAMEWORK_PATH_TMP}" STREQUAL "/System/Library/Frameworks"
      )
    # String is not /Library/Frameworks, need to use -F
    SET(OPENAL_LIBRARY "-F${OPENAL_FRAMEWORK_PATH_TMP} -framework OpenAL" CACHE STRING "OpenAL framework for OSX")
  ENDIF("${OPENAL_FRAMEWORK_PATH_TMP}" STREQUAL "/Library/Frameworks"
    OR "${OPENAL_FRAMEWORK_PATH_TMP}" STREQUAL "/System/Library/Frameworks"
    )
  # Clear the temp variable so nobody can see it
  SET(OPENAL_FRAMEWORK_PATH_TMP "" CACHE INTERNAL "")

ELSE(${OPENAL_INCLUDE_DIR} MATCHES ".framework")
  FIND_LIBRARY(OPENAL_LIBRARY 
    NAMES openal al OpenAL32
    PATHS
    $ENV{OPENALDIR}/lib
    $ENV{OPENALDIR}/libs
    /usr/local/lib
    /usr/lib
    /sw/lib
    /opt/local/lib
    /opt/csw/lib
    /opt/lib
    )
ENDIF(${OPENAL_INCLUDE_DIR} MATCHES ".framework")

# BUSCAR CABECERAS ALUT
FIND_PATH(ALUT_INCLUDE_DIR alut.h
  $ENV{ALUTDIR}/include
  ~/Library/Frameworks/OpenAL.framework/Headers
  /Library/Frameworks/OpenAL.framework/Headers
  /System/Library/Frameworks/OpenAL.framework/Headers # Tiger
  /usr/local/include/AL
  /usr/local/include/OpenAL
  /usr/local/include
  /usr/include/AL
  /usr/include/OpenAL
  /usr/include
  /sw/include/AL # Fink
  /sw/include/OpenAL 
  /sw/include
  /opt/local/include/AL # DarwinPorts
  /opt/local/include/OpenAL
  /opt/local/include
  /opt/csw/include/AL # Blastwave
  /opt/csw/include/OpenAL
  /opt/csw/include
  /opt/include/AL
  /opt/include/OpenAL
  /opt/include
  )

# BUSCAR LIBRERIA ALUT
FIND_LIBRARY(ALUT_LIBRARY alut
	$ENV{ALUTDIR}/lib
	$ENV{ALUTDIR}/libs
	/usr/local/lib
	/usr/lib
	/sw/lib
	/opt/local/lib
	/opt/csw/lib
	/opt/lib
)

#B USCAR CABECERAS OGG
FIND_PATH(OGG_INCLUDE_DIR ogg.h
	$ENV{OGGDIR}/include
	/usr/local/include/ogg
	/usr/local/include
	/usr/include/ogg
	/usr/include
	)

# BUSCAR LIBRERIA OGG
FIND_LIBRARY(OGG_LIBRARY ogg
	$ENV{OGGDIR}/lib
	$ENV{OGGDIR}/libs
	/usr/local/lib
	/usr/lib
	/sw/lib
	/opt/local/lib
	/opt/csw/lib
	/opt/lib
)

# BUSCAR CABECERAS VORBIS
FIND_PATH(VORBIS_INCLUDE_DIR vorbisfile.h
	$ENV{VORBISDIR}/include
	/usr/local/include/vorbis
	/usr/local/include
	/usr/include/vorbis
	/usr/include
	)

# BUSCAR LIBRERIA VORBIS
FIND_LIBRARY(VORBIS_LIBRARY vorbis
	$ENV{VORBISDIR}/lib
	$ENV{VORBISDIR}/libs
	/usr/local/lib
	/usr/lib
	/sw/lib
	/opt/local/lib
	/opt/csw/lib
	/opt/lib
)

# BUSCAR LIBRERIA VORBIS
FIND_LIBRARY(VORBISFILE_LIBRARY NAMES vorbisfile
	$ENV{VORBISDIR}/lib
	$ENV{VORBISDIR}/libs
	/usr/local/lib
	/usr/lib
	/sw/lib
	/opt/local/lib
	/opt/csw/lib
	/opt/lib
)

# BUSCAR CABECERAS LUA
FIND_PATH(LUA_INCLUDE_DIR NAMES lua.h lualib.h luaxlib.h
	PATHS
	$ENV{LUADIR}/include
	/usr/local/include/lua5.1
	/usr/local/include
	/usr/include/lua5.1
	/usr/include/lua
	/usr/include
	)

# BUSCAR LIBRERIA LUA
FIND_LIBRARY(LUA_LIBRARY NAMES lua5.1
	PATHS
	$ENV{LUADIR}/lib
	$ENV{LUADIR}/libs
	/usr/local/lib
	/usr/lib
	/sw/lib
	/opt/local/lib
	/opt/csw/lib
	/opt/lib
	)

##########################
## Librerias de Fisicas ##
##########################
# BUSCAR CABECERAS NEWTON
FIND_PATH(NEWTON_INCLUDE_DIR NAMES Newton.h
	PATHS
	$ENV{NEWTONDIR}/include
	/usr/local/include/newton
	/usr/local/include/Newton
	/usr/local/include/
	/usr/include/newton
	/usr/include/Newton
	/usr/include
	)

# BUSCAR LIBRERIA NEWTON
FIND_LIBRARY(NEWTON_LIBRARY NAMES Newton
	PATHS
	$ENV{NEWTONDIR}/lib
	$ENV{NEWTONDIR}/libs
	/usr/local/lib
	/usr/lib
	/sw/lib
	/opt/local/lib
	/opt/csw/lib
	/opt/lib
	)

# BUSCAR CABECERAS ODE
FIND_PATH(ODE_INCLUDE_DIR NAMES ode.h
	PATHS
	$ENV{ODEDIR}/include
	/usr/local/include/ode
	/usr/local/include/
	/usr/include/ode
	/usr/include
	)

# BUSCAR LIBRERIA ODE
FIND_LIBRARY(ODE_LIBRARY NAMES ode
	PATHS
	$ENV{ODEDIR}/lib
	$ENV{ODEDIR}/libs
	/usr/local/lib
	/usr/lib
	/sw/lib
	/opt/local/lib
	/opt/csw/lib
	/opt/lib
	)

ENDIF(NOT WIN32)

## VARIABLES DE AGRUPACION
SET(VIDEO_FOUND "NO")
SET(SONIDO_FOUND "NO")
SET(SONIDO_OGG_FOUND "NO")
SET(SCRIPTING_FOUND "NO")
SET(FISICAS_NEWTON_FOUND "NO")
SET(FISICAS_ODE_FOUND "NO")

## MENSAJES PARA EL USUARIO
IF(OPENGL_gl_LIBRARY)
	MESSAGE("DEPS: Se ha encontrado la biblioteca GL en: " ${OPENGL_gl_LIBRARY})
ELSE(OPENGL_gl_LIBRARY)
	MESSAGE("DEPS: NO SE HA ENCONTRADO LA BIBLIOTECA GL")
ENDIF(OPENGL_gl_LIBRARY)

IF(OPENGL_glu_LIBRARY)
	MESSAGE("DEPS: Se ha encontrado la biblioteca GLU en: " ${OPENGL_glu_LIBRARY})
ELSE(OPENGL_glu_LIBRARY)
	MESSAGE("DEPS: NO SE HA ENCONTRADO LA BIBLIOTECA GLU")
ENDIF(OPENGL_glu_LIBRARY)

IF(IRRLICHT_INCLUDE_DIR)
	MESSAGE("DEPS: Se encontraron las cabeceras de Irrlicht en: " ${IRRLICHT_INCLUDE_DIR})
ELSE(IRRLICHT_INCLUDE_DIR)
	MESSAGE("DEPS: NO SE HAN ENCONTRADO CABECERAS DE IRRLICHT")
ENDIF(IRRLICHT_INCLUDE_DIR)

IF(IRRLICHT_LIBRARY)
	MESSAGE("DEPS: Se ha encontrado la biblioteca Irrlicht en: " ${IRRLICHT_LIBRARY})
ELSE(IRRLICHT_LIBRARY)
	MESSAGE("SE HA LA BIBLITECA DE IRRLICHT")
ENDIF(IRRLICHT_LIBRARY)

IF(OPENAL_INCLUDE_DIR)
	MESSAGE("DEPS: Se han encontrado las cabeceras de OpenAL en: " ${OPENAL_INCLUDE_DIR})
ELSE(OPENAL_INCLUDE_DIR)
	MESSAGE("DEPS: NO SE HAN ENCONTRADO CABECERAS DE OPENAL")
ENDIF(OPENAL_INCLUDE_DIR)

IF(OPENAL_LIBRARY)
	MESSAGE("DEPS: Se ha encontrado la bibliteca OpenAL en: " ${OPENAL_LIBRARY})
ELSE(OPENAL_LIBRARY)
	MESSAGE("DEPS: NO SE HA ENCONTRADO LA BIBLIOTECA OPENAL")
ENDIF(OPENAL_LIBRARY)

IF(ALUT_INCLUDE_DIR)
	MESSAGE("DEPS: Se han encontrado las cabeceras de ALUT en: " ${ALUT_INCLUDE_DIR})
ELSE(ALUT_INCLUDE_DIR)
	MESSAGE("DEPS: NO SE HAN ENCONTRADO CABECERAS DE ALUT")
ENDIF(ALUT_INCLUDE_DIR)

IF(ALUT_LIBRARY)
	MESSAGE("DEPS: Se ha encontrado la bibliteca ALUT en: " ${ALUT_LIBRARY})
ELSE(ALUT_LIBRARY)
	MESSAGE("DEPS: NO SE HA ENCONTRADO LA BIBLIOTECA ALUT")
ENDIF(ALUT_LIBRARY)

IF(OGG_INCLUDE_DIR)
	MESSAGE("DEPS: Se han encontrado las cabeceras de Ogg en: " ${OGG_INCLUDE_DIR})
ELSE(OGG_INCLUDE_DIR)
	MESSAGE("DEPS: NO SE HAN ENCONTRADO CABECERAS DE OGG")
ENDIF(OGG_INCLUDE_DIR)

IF(OGG_LIBRARY)
	MESSAGE("DEPS: Se ha encontrado la biblioteca Ogg en: " ${OGG_LIBRARY})
ELSE(OGG_LIBRARY)
	MESSAGE("DEPS: NO SE HA ENCONTRADO LA BIBLIOTECA OGG")
ENDIF(OGG_LIBRARY)

IF(VORBIS_INCLUDE_DIR)
	MESSAGE("DEPS: Se han encontrado las cabeceras de Vorbis en: " ${VORBIS_INCLUDE_DIR})
ELSE(VORBIS_INCLUDE_DIR)
	MESSAGE("DEPS: NO SE HAN ENCONTRADO CABECERAS DE VORBIS")
ENDIF(VORBIS_INCLUDE_DIR)

IF(VORBIS_LIBRARY)
	MESSAGE("DEPS: Se ha encontrado la biblioteca Vorbis en: " ${VORBIS_LIBRARY})
ELSE(VORBIS_LIBRARY)
	MESSAGE("DEPS: NO SE HA ENCONTRADO LA BIBLIOTECA VORBIS")
ENDIF(VORBIS_LIBRARY)


IF(VORBIS_INCLUDE_DIR)
	MESSAGE("DEPS: Se han encontrado las cabeceras de Vorbisfile en: " ${VORBIS_INCLUDE_DIR})
ELSE(VORBIS_INCLUDE_DIR)
	MESSAGE("DEPS: NO SE HA ENCONTRADO LA BIBLIOTECA VORBIS")
ENDIF(VORBIS_INCLUDE_DIR)

IF(VORBISFILE_LIBRARY)
	MESSAGE("DEPS: Se ha encontrado la biblioteca Vorbisfile en: " ${VORBISFILE_LIBRARY})
ELSE(VORBISFILE_LIBRARY)
	MESSAGE("DEPS: NO SE HA ENCONTRADO LA BIBLIOTECA VORBISFILE")
ENDIF(VORBISFILE_LIBRARY)

IF(LUA_INCLUDE_DIR)
	MESSAGE("DEPS: Se encontraron las cabeceras de LUA en: " ${LUA_INCLUDE_DIR})
ELSE(LUA_INCLUDE_DIR)
	MESSAGE("DEPS: NO SE HAN ENCONTRADO CABECERAS DE LUA")
ENDIF(LUA_INCLUDE_DIR)

IF(LUA_LIBRARY)
	MESSAGE("DEPS: Se ha encontrado la biblioteca de LUA en: " ${LUA_LIBRARY})
ELSE(LUA_LIBRARY)
	MESSAGE("DEPS: NO SE HA ENCONTRADO LA BIBLIOTECA LUA")
ENDIF(LUA_LIBRARY)

IF(NEWTON_INCLUDE_DIR)
	MESSAGE("DEPS: Se han encontrado las cabeceras de Newton Dynamics en: " ${NEWTON_INCLUDE_DIR})
ELSE(NEWTON_INCLUDE_DIR)
	MESSAGE("DEPS: NO SE HAN ENCONTRADO CABECERAS DE NEWTON")
ENDIF(NEWTON_INCLUDE_DIR)

IF(NEWTON_LIBRARY)
	MESSAGE("DEPS: Se ha encontrado la biblioteca Newton Dynamics en: " ${NEWTON_LIBRARY})
ELSE(NEWTON_LIBRARY)
	MESSAGE("DEPS: NO SE HA ENCONTRADO LA BIBLIOTECA NEWTON")
ENDIF(NEWTON_LIBRARY)

IF(ODE_INCLUDE_DIR)
	MESSAGE("DEPS: Se han encontrado las cabeceras de Open Dynamics Engine en: " ${ODE_INCLUDE_DIR})
ELSE(ODE_INCLUDE_DIR)
	MESSAGE("DEPS: NO SE HAN ENCONTRADO CABECERAS DE ODE")
ENDIF(ODE_INCLUDE_DIR)

IF(ODE_LIBRARY)
	MESSAGE("DEPS: Se ha encontrado la biblioteca Open Dynamics Engine en: " ${ODE_LIBRARY})
ELSE(ODE_LIBRARY)
	MESSAGE("DEPS: NO SE HA ENCONTRADO LA BIBLIOTECA ODE")
ENDIF(ODE_LIBRARY)

IF(NOT WIN32)
	IF(NOT X11_LIBRARIES)
		MESSAGE("DEPS: NO SE HAN ENCONTRADO BIBLIOTECAS DE X11")
	ENDIF(NOT X11_LIBRARIES)
	
	## COMPROBAR GRUPO DE VIDEO + X11
	IF(IRRLICHT_INCLUDE_DIR AND IRRLICHT_LIBRARY AND X11_LIBRARIES)
		SET(VIDEO_FOUND "YES")
	ENDIF(IRRLICHT_INCLUDE_DIR AND IRRLICHT_LIBRARY AND X11_LIBRARIES)
ELSE(NOT WIN32)
	## COMPROBAR GRUPO DE VIDEO
	IF(IRRLICHT_INCLUDE_DIR AND IRRLICHT_LIBRARY)
		SET(VIDEO_FOUND "YES")
	ENDIF(IRRLICHT_INCLUDE_DIR AND IRRLICHT_LIBRARY)
ENDIF(NOT WIN32)

## COMPROBAR GRUPO DE SONIDO
IF(OPENAL_LIBRARY AND OPENAL_INCLUDE_DIR
  AND ALUT_INCLUDE_DIR AND ALUT_LIBRARY
  #AND OGG_INCLUDE_DIR AND OGG_LIBRARY
  #AND VORBIS_INCLUDE_DIR AND VORBIS_LIBRARY
)
	SET(SONIDO_FOUND "YES")
ENDIF(OPENAL_LIBRARY AND OPENAL_INCLUDE_DIR
  AND ALUT_INCLUDE_DIR AND ALUT_LIBRARY
  #AND OGG_INCLUDE_DIR AND OGG_LIBRARY
  #AND VORBIS_INCLUDE_DIR AND VORBIS_LIBRARY
)

## COMPROBAR GRUPO OGG
IF( OGG_INCLUDE_DIR AND OGG_LIBRARY
    AND VORBIS_INCLUDE_DIR AND VORBIS_LIBRARY
)
	SET(SONIDO_OGG_FOUND "YES")
ENDIF(OGG_INCLUDE_DIR AND OGG_LIBRARY
    AND VORBIS_INCLUDE_DIR AND VORBIS_LIBRARY
)

## COMPROBAR GRUPO DE SCRIPTING
IF(LUA_INCLUDE_DIR AND LUA_LIBRARY)
   SET(SCRIPTING_FOUND "YES")
ENDIF(LUA_INCLUDE_DIR AND LUA_LIBRARY)

## COMPROBAR GRUPO DE FISICAS NEWTON
IF(NEWTON_INCLUDE_DIR AND NEWTON_LIBRARY)
   SET(FISICAS_NEWTON_FOUND "YES")
ENDIF(NEWTON_INCLUDE_DIR AND NEWTON_LIBRARY)

## COMPROBAR GRUPO DE FISICAS ODE
IF(ODE_INCLUDE_DIR AND ODE_LIBRARY)
   SET(FISICAS_ODE_FOUND "YES")
ENDIF(ODE_INCLUDE_DIR AND ODE_LIBRARY)

## PARA EVITAR HACER LA COMPROBACION MAS DE UNA VEZ
ENDIF(NOT DEPENDENCIAS)