#BUSCAR CABECERAS LUA
FIND_PATH(LUA_INCLUDE_DIR NAMES lua.h lualib.h luaxlib.h
	PATHS
	$ENV{LUADIR}/include
	/usr/local/include/lua5.1
	/usr/local/include/lua50
	/usr/local/include
	/usr/include/lua5.1
	/usr/include/lua50
	/usr/include/lua
	/usr/include
	)

# BUSCAR LIBRERIA LUA
FIND_LIBRARY(LUA_LIBRARY NAMES lua5.1 lua50
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

IF(NOT LUA_LIBRARY)
	MESSAGE("NO SE HA ENCONTRADO LA BIBLIOTECA LUA")
ENDIF(NOT LUA_LIBRARY)

IF(NOT LUA_INCLUDE_DIR)
	MESSAGE("NO SE HAN ENCONTRADO CABECERAS DE LUA")
ENDIF(NOT LUA_INCLUDE_DIR)

SET(SCRIPTING_FOUND "NO")
IF(LUA_INCLUDE_DIR AND LUA_LIBRARY)
   SET(SCRIPTING_FOUND "YES")
ENDIF(LUA_INCLUDE_DIR AND LUA_LIBRARY)