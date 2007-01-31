#BUSCAR CABECERAS LUA
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

IF(LUA_INCLUDE_DIR)
	MESSAGE("* Se encontraron las cabeceras de LUA en: " ${LUA_INCLUDE_DIR})
ELSE(LUA_INCLUDE_DIR)
	MESSAGE("NO SE HAN ENCONTRADO CABECERAS DE LUA")
ENDIF(LUA_INCLUDE_DIR)

IF(LUA_LIBRARY)
	MESSAGE("* Se encontró Biblioteca de LUA en: " ${LUA_LIBRARY})
ELSE(LUA_LIBRARY)
	MESSAGE("NO SE HA ENCONTRADO LA BIBLIOTECA LUA")
ENDIF(LUA_LIBRARY)

SET(SCRIPTING_FOUND "NO")
IF(LUA_INCLUDE_DIR AND LUA_LIBRARY)
   SET(SCRIPTING_FOUND "YES")
ENDIF(LUA_INCLUDE_DIR AND LUA_LIBRARY)