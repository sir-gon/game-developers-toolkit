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

IF(NOT WIN32)
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
	FIND_LIBRARY(X11_LIBRARIES NAMES Xxf86vm Xext X11
		PATHS
		/usr/local/lib
		/usr/lib
		/sw/lib
		/opt/local/lib
		/opt/csw/lib
		/opt/lib
		)
	
	IF(NOT OPENGL_gl_LIBRARY)
		MESSAGE("NO SE HA ENCONTRADO LA BIBLIOTECAS GL")
	ENDIF(NOT OPENGL_gl_LIBRARY)
	
	IF(NOT OPENGL_glu_LIBRARY)
		MESSAGE("NO SE HA ENCONTRADO LA BIBLIOTECAS GLU")
	ENDIF(NOT OPENGL_glu_LIBRARY)

	IF(NOT X11_LIBRARIES)
		MESSAGE("NO SE HAN ENCONTRADO BIBLIOTECAS DE X11")
	ENDIF(NOT X11_LIBRARIES)

ENDIF(NOT WIN32)

IF(NOT IRRLICHT_INCLUDE_DIR)
	MESSAGE("NO SE HAN ENCONTRADO CABECERAS DE IRRLICHT")
ENDIF(NOT IRRLICHT_INCLUDE_DIR)

IF(NOT IRRLICHT_LIBRARY)
	MESSAGE("NO SE HA LA BIBLITECA DE IRRLICHT")
ENDIF(NOT IRRLICHT_LIBRARY)

SET(VIDEO_FOUND "NO")
IF(IRRLICHT_INCLUDE_DIR AND IRRLICHT_LIBRARY)
   SET(VIDEO_FOUND "YES")
ENDIF(IRRLICHT_INCLUDE_DIR AND IRRLICHT_LIBRARY)