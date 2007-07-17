###########################################################
# Los saguientes variables definen las rutas              #
# donde se encontraron las cabeceras y librerias buscadas #
#                                                         #
# Uselas en su proyecto para compilar con la libreria GDT #
#                                                         #
# GDT_INCLUDE_DIR                                         #
# GDT_LIBRARY                                             #
#                                                         #
# Las siguientes variables son true/false define solo si  #
# se ha buscado GDT y si fue encontrado                   #
#                                                         #
# SEARCH_GDT                                              #
# GDT_FOUND                                               #
###########################################################

#EVITAR BUSCAR GDT 2 VECES
IF(NOT SEARCH_GDT)
	SET(SEARCH_GDT "YES")

SET(GDT_FOUND "NO")

# BUSCAR CABECERAS GDT
FIND_PATH(GDT_INCLUDE_DIR gdt.h
	$ENV{GDTDIR}/include
	# RUTAS RELATIVAS
	./gdt
	../gdt
	# RUTAS ABSOLUTAS
	/usr/local/include/gdt
	/usr/local/include
	/usr/include/gdt
	/usr/include
	)

# BUSCAR LIBRERIA GDT
FIND_LIBRARY(GDT_LIBRARY gdt
	$ENV{GDTDIR}/lib/linux-x86
	# RUTAS RELATIVAS
	../lib/linux-x86
	../lib
	./
	./lib/linux-x86
	./lib
	./gdt
	./gdt/lib/linux-x86
	./gdt
	../gdt
	# RUTAS ABSOLUTAS
	/usr/local/lib
	/usr/lib
	)

IF(GDT_INCLUDE_DIR)
	MESSAGE("DEPS: Se encontraron las cabeceras de GDT en: " ${GDT_INCLUDE_DIR})
ELSE(GDT_INCLUDE_DIR)
	MESSAGE("DEPS: SE HAN ENCONTRADO CABECERAS DE GDT")
ENDIF(GDT_INCLUDE_DIR)

IF(GDT_LIBRARY)
	MESSAGE("DEPS: Se encontro la bibliotca GDT en: " ${GDT_LIBRARY})
ELSE(GDT_LIBRARY)
	MESSAGE("DEPS: NO SE HA ENCONTRADO LA BIBLITECA DE GDT")
ENDIF(GDT_LIBRARY)

## ESTABLECER EL RESULTADO DE BUSQUEDA
IF(GDT_INCLUDE_DIR AND GDT_LIBRARY)
   SET(GDT_FOUND "YES")
ENDIF(GDT_INCLUDE_DIR AND GDT_LIBRARY)

#EVITAR BUSCAR GDT 2 VECES
ENDIF(NOT SEARCH_GDT)