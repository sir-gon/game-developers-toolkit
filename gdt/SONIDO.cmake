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

#BUSCAR CABECERAS OGG
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

IF(NOT OPENAL_INCLUDE_DIR)
	MESSAGE("NO SE HAN ENCONTRADO CABECERAS DE OPENAL")
ENDIF(NOT OPENAL_INCLUDE_DIR)

IF(NOT OPENAL_LIBRARY)
	MESSAGE("NO SE HA ENCONTRADO LA BIBLIOTECA OPENAL")
ENDIF(NOT OPENAL_LIBRARY)

IF(NOT ALUT_INCLUDE_DIR)
	MESSAGE("NO SE HAN ENCONTRADO CABECERAS DE ALUT")
ENDIF(NOT ALUT_INCLUDE_DIR)

IF(NOT ALUT_LIBRARY)
	MESSAGE("NO SE HA ENCONTRADO LA BIBLIOTECA ALUT")
ENDIF(NOT ALUT_LIBRARY)

IF(NOT OGG_INCLUDE_DIR)
	MESSAGE("NO SE HAN ENCONTRADO CABECERAS DE OGG")
ENDIF(NOT OGG_INCLUDE_DIR)

IF(NOT VORBIS_INCLUDE_DIR)
	MESSAGE("NO SE HAN ENCONTRADO CABECERAS DE VORBIS")
ENDIF(NOT VORBIS_INCLUDE_DIR)

SET(SONIDO_FOUND "NO")
IF(OPENAL_LIBRARY AND OPENAL_INCLUDE_DIR
  AND ALUT_INCLUDE_DIR AND ALUT_LIBRARY
  AND OGG_INCLUDE_DIR AND OGG_LIBRARY
  AND VORBIS_INCLUDE_DIR AND VORBIS_LIBRARY)
	SET(SONIDO_FOUND "YES")
ENDIF(OPENAL_LIBRARY AND OPENAL_INCLUDE_DIR
  AND ALUT_INCLUDE_DIR AND ALUT_LIBRARY
  AND OGG_INCLUDE_DIR AND OGG_LIBRARY
  AND VORBIS_INCLUDE_DIR AND VORBIS_LIBRARY)