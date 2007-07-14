/***************************************************************************
 *   GDT (GAME DEVELOPERS TOOLKIT)                                         *
 *   Copyright (C) 2006 GDT STAFF                                          *
 *   http://gdt.sourceforge.net                                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor,                    *
 *   Boston, MA 02110-1301 USA                                             *
 ***************************************************************************/

#ifdef _GDT_SCRIPTING_

/*!
* \class GD_SistemaLua
*
* Provee una capa de Scripting externa, en Lenguaje Lua.
*/

#include "gd_sistemalua.h" // class's header file

// class constructor
GD_SistemaLua::GD_SistemaLua()
{
    // Abrimos Lua
    this->LuaMV = lua_open();
    printf("SistemaLua inicializado. Usando %s\n", LUA_VERSION);
    
    // Ponemos el Token
    strcpy(this->strToken,"->\n");
    
    // Ponemos que se muestren los errores automï¿½icamente
    this->bAutoErrores = true;
    
    
    // Cargamos todas las librerï¿½s estandar
    luaopen_base(this->LuaMV); 
    luaopen_table(this->LuaMV); 
    //luaopen_io(this->LuaMV); 
    luaopen_string(this->LuaMV);
    luaopen_math(this->LuaMV);
    luaopen_debug(this->LuaMV);
    
    // Por un "extraï¿½" error el primver valor que se coje de una tabla siempre muestra 0.
    // para evitarlo cogemos aqui el primer valor, que no existe.
    this->Priv_LlegarATabla("Tab->Tab");
    lua_pop(this->LuaMV, lua_gettop(this->LuaMV) );
}

GD_SistemaLua::GD_SistemaLua(lua_State* L)
{
	this->LuaMV = L;
}

// class destructor
GD_SistemaLua::~GD_SistemaLua()
{
	// insert your code here
}

// -----------------
// FUNCIONES PRIVADAS DE LA CLASE
// ------------------

// *********
// Inicio y Cierre
// *********
/*!
\deprecated El constructor ya hace lo mismo.
*/
void GD_SistemaLua::Inicializar(void)
{
    // Abrimos Lua
    this->LuaMV = lua_open();
    printf("SistemaLua inicializado. Usando %s\n", LUA_VERSION);
    
    // Ponemos el Token
    strcpy(this->strToken,"->\n");
    
    // Ponemos que se muestren los errores automï¿½icamente
    this->bAutoErrores = true;
    
    
    // Cargamos todas las librerï¿½s estandar
    luaopen_base(this->LuaMV); 
    luaopen_table(this->LuaMV); 
    //luaopen_io(this->LuaMV); 
    luaopen_string(this->LuaMV);
    luaopen_math(this->LuaMV);
    luaopen_debug(this->LuaMV);
    
    // Por un "extraï¿½" error el primver valor que se coje de una tabla siempre muestra 0.
    // para evitarlo cogemos aqui el primer valor, que no existe.
    this->Priv_LlegarATabla("Tab->Tab");
    lua_pop(this->LuaMV, lua_gettop(this->LuaMV) );

}

/*!
Cuando el sistema se cierra, se borran todas las variables y tablas que este contenga. Tambi&eacute;n se descargan los archivos scripts, incluyendo las funciones que estos contengan, y las que hayamos registrado nosotros.

Es muy recomendable cerrar el sistema Lua cuando ya no lo necesitemos y as&iacute; ahorrar memoria.

Ejemplo:
\code
Lua.Cerrar();
\endcode
*/
void GD_SistemaLua::Cerrar(void)
{
     // Cerramos
    lua_close(this->LuaMV);   
}

/*!
\return la M&aacute;quina Virtual Lua.

Ejemplo:
L = Lua.RetornarEstado();
*/
lua_State* GD_SistemaLua::RetornarEstado(void)
{
    return this->LuaMV;
}


// *********
// Ejecucion
// *********
/*!
\return 0 si no se producen errores.

Ejemplo:
\code
int error = Lua.EjecutarCadena("a = 5; print(a);");
\endcode
*/
int GD_SistemaLua::EjecutarCadena(char* strCadenaLua)
{
    int iError;
    // Cargamos la cadena y la ejecutamos en modo seguro. Si los errores estï¿½ automï¿½icos se muestran.
    if ( iError = luaL_loadstring(this->LuaMV, strCadenaLua) || lua_pcall(this->LuaMV, 0, 0, 0) )
    {
         if(this->bAutoErrores)
             this->MostrarError();
    }
    
    return iError;
}

/*!
\return 0 si no se producen errores.

Ejemplo:
\code
int error = Lua.EjecutarArchivo("script.lua");
\endcode
*/
int GD_SistemaLua::EjecutarArchivo(char* strArchivo)
{
    int iError;
    // Cargamos el archivo y lo ejecutamos en modo seguro. Si los errores estï¿½ automï¿½icos se muestran.
    if ( iError = luaL_loadfile(this->LuaMV, strArchivo) || lua_pcall(this->LuaMV, 0, 0, 0) )
    {
         if(this->bAutoErrores)
             this->MostrarError();
    }
    
    return iError;
}


// *********
// Obtenciï¿½ de valores
// *********
/*!
Ejemplo:
\code
numero = Lua.RetornarNumero("minumero");
numero = Lua.RetornarNumero("mitabla->minumero");
\endcode
*/
lua_Number GD_SistemaLua::RetornarNumero(char *strCadenaTabla)
{
    // Vamos hasta el valor de la tabla
    this->Priv_LlegarATabla(strCadenaTabla);
    
    // Obtenemos la posiciï¿½ del valor en la pila
    int nPosValorPila = lua_gettop(this->LuaMV);

    // Comprobamos si es un nmero. Si no, mostramos un error.
    if( !lua_isnumber(this->LuaMV, nPosValorPila) )
    {
        char strError[256];
        sprintf(strError, "La cadena %s no llega a un Numero", strCadenaTabla);
        lua_pushstring(this->LuaMV, strError); 
        this->MostrarError();
        return 0;
    }
    
    // Obtenemos el Numero a Devolver
    lua_Number nRet;

    nRet = lua_tonumber(this->LuaMV, nPosValorPila );
       
    // Eliminamos los elementos que se han ocupado de la pila
    lua_pop(this->LuaMV, nPosValorPila);
    
    // Devolvemos el valor de nmero 
    return nRet; 
}

/*!
Ejemplo:
\code
texto = Lua.RetornarCadena("micadena");
texto = Lua.RetornarNumero("mitabla->micadena");
\endcode
*/
const char *GD_SistemaLua::RetornarCadena( char *strCadenaTabla)
{
    // Vamos hasta el valor de la tabla
    this->Priv_LlegarATabla(strCadenaTabla);
    
    // Obtenemos la posiciï¿½ del valor en la pila
    int nPosValorPila = lua_gettop(this->LuaMV);
    
    // Comprobamos si es un cadena. Si no, mostramos un error.
    if( !lua_isstring(this->LuaMV, nPosValorPila) )
    {
        char strError[256];
        sprintf(strError, "La cadena %s no llega a una Cadena", strCadenaTabla);
        lua_pushstring(this->LuaMV, strError); 
        this->MostrarError();
        return "ERROR";
    }
    
    // Obtenemos la Cadena a Devolver
    const char *strDev;

    strDev = lua_tostring(this->LuaMV, nPosValorPila );
       
    // Eliminamos los elementos que se han ocupado de la pila
    lua_pop(this->LuaMV, nPosValorPila);
    
    // Devolvemos el valor de nmero 
    return strDev;     
}


// *********
// Cambio de valores
// *********
/*!
Ejemplo:
\code
Lua.CambiarNumero("minumero", 53);
Lua.CambiarNumero("mitabla->minumero", 53);
\endcode
*/
void GD_SistemaLua::CambiarNumero(char *strCadenaTabla, lua_Number lnNumero)
{  
    // Contamos el nmero de partes en que se divide la cadena 
    char *ptrC;
    char strCadenaC[strlen(strCadenaTabla)];
    strcpy(strCadenaC, strCadenaTabla);
  
    ptrC = strtok( strCadenaC, this->strToken);
    
    int nPartes = 0;
    while( (ptrC = strtok( NULL, this->strToken )) != NULL )
    {
           nPartes++;
    }
    
    // Ahora navegamos hasta la clave de la tabla y la cambiamos    
    // Obtenemos el Inicio que recibimos la global
    lua_pop(this->LuaMV, lua_gettop(this->LuaMV) );
    char *ptr;
    char strCadena[strlen(strCadenaTabla)];
    strcpy(strCadena, strCadenaTabla);
    
    ptr = strtok( strCadena, this->strToken);
    
    lua_getglobal(this->LuaMV, ptr);
    
    // Si no tiene partes es que es una variable globa, asique la ponemos y salimos
    if( nPartes == 0)
    {
        lua_pushnumber(this->LuaMV, lnNumero);
        lua_setglobal(this->LuaMV, ptr);
        return;
    }
    
    // Obtenemos el nmero de elementos que despues cojeremos como tabla, y le suamos uno ya que habrï¿½que cojerlo de allï¿½
    int nGtIndex = lua_gettop(this->LuaMV) + 1;

    // El resto hasta llegar al final, los ponemos como cadenas en el Stack
    int ntFor; // Variable del bucle For
    for( ntFor = 1; ntFor <= nPartes-1 ; ntFor++ )
    {
           ptr = strtok( NULL, this->strToken );
           
           lua_pushstring(this->LuaMV, ptr);
           
           // Ahora usamos GetTable para que coja el valor de la tabla
           lua_gettable(this->LuaMV, - nGtIndex );   
    }
    
    // Ahora nos queda cojer la posiciï¿½ de la clave y cambiar su valor
    ptr = strtok( NULL, this->strToken );

    lua_pushstring(this->LuaMV, ptr);
    lua_pushnumber(this->LuaMV, lnNumero);
    lua_settable(this->LuaMV, nGtIndex);
    
    // Limpiamos la pila
    lua_pop(this->LuaMV, lua_gettop(this->LuaMV) );
}

/*!
Ejemplo:
\code
Lua.CambiarTexto("mitexto", "Un texto");
Lua.CambiarTexto("mitabla->mitexto", "Otro texto");
\endcode
*/
void GD_SistemaLua::CambiarCadena(char *strCadenaTabla, const char *strCadenaTexto)
{
    // Contamos el nmero de partes en que se divide la cadena 
    char *ptrC;
    char strCadenaC[strlen(strCadenaTabla)];
    strcpy(strCadenaC, strCadenaTabla);
  
    ptrC = strtok( strCadenaC, this->strToken);
    
    int nPartes = 0;
    while( (ptrC = strtok( NULL, this->strToken )) != NULL )
    {
           nPartes++;
    }
    
    // Ahora navegamos hasta la clave de la tabla y la cambiamos    
    // Obtenemos el Inicio que recibimos la global
    lua_pop(this->LuaMV, lua_gettop(this->LuaMV) );
    char *ptr;
    char strCadena[strlen(strCadenaTabla)];
    strcpy(strCadena, strCadenaTabla);
    
    ptr = strtok( strCadena, this->strToken);
    
    lua_getglobal(this->LuaMV, ptr);
    
    // Si no tiene partes es que es una variable globa, asique la ponemos y salimos
    if( nPartes == 0)
    {
        lua_pushstring(this->LuaMV, strCadenaTexto);
        lua_setglobal(this->LuaMV, ptr);
        return;
    }
    
    // Obtenemos el nmero de elementos que despues cojeremos como tabla, y le suamos uno ya que habrï¿½que cojerlo de allï¿½
    int nGtIndex = lua_gettop(this->LuaMV) + 1;

    // El resto hasta llegar al final, los ponemos como cadenas en el Stack
    int ntFor; // Variable del bucle For
    for( ntFor = 1; ntFor <= nPartes-1 ; ntFor++ )
    {
           ptr = strtok( NULL, this->strToken );
           
           lua_pushstring(this->LuaMV, ptr);
           
           // Ahora usamos GetTable para que coja el valor de la tabla
           lua_gettable(this->LuaMV, - nGtIndex );   
    }
    
    // Ahora nos queda cojer la posiciï¿½ de la clave y cambiar su valor
    ptr = strtok( NULL, this->strToken );

    lua_pushstring(this->LuaMV, ptr);
    lua_pushstring(this->LuaMV, strCadenaTexto);
    lua_settable(this->LuaMV, nGtIndex);
    
    // Limpiamos la pila
    lua_pop(this->LuaMV, lua_gettop(this->LuaMV) );
}

// *********
// Lallamar Funciones
// *********
/*!
Ejemplo:
\code
Lua.PrepararFuncion("Funcion");
\endcode
*/
void GD_SistemaLua::PrepararFuncion(char *strFuncion)
{
    // Limpiamos la pila por precacuciï¿½
    lua_pop(this->LuaMV, lua_gettop(this->LuaMV) );
    
    // Obtenemos la funciï¿½
    lua_getglobal(this->LuaMV, strFuncion);
}

/*!
Ejemplo:
\code
Lua.PonerParametroNumero(65);
\endcode
*/
void GD_SistemaLua::PonerParametroNumero(lua_Number lNumero)
{
    lua_pushnumber(this->LuaMV, lNumero);
}

/*!
Ejemplo:
\code
Lua.PonerParametroCadena("hola");
\endcode
*/
void GD_SistemaLua::PonerParametroCadena(char *strCadena)
{
    lua_pushstring(this->LuaMV, strCadena);
}

/*!
\return 0 si no se producen errores.

Se indicar&aacute;n el n&uacute;mero de par&aacute;metros que se le ha pasado y el n&uacute;mero de resultados que retornar&aacute; la funci&oacute;n.

Ejemplo:
\code
int error = Lua.LlamarFuncion(4,3);
\endcode
*/
int GD_SistemaLua::LlamarFuncion(int nArgumentos, int nResultados)
{
    int iError;
    // Llamamos a la funciï¿½ en modo seguro en modo seguro. Si los errores estï¿½ automï¿½icos se muestran.
    if ( iError = lua_pcall(this->LuaMV, nArgumentos, nResultados, 0) )
    {
         if(this->bAutoErrores)
             this->MostrarError();
    }
    
    return iError;
}

/*!
Ejemplo:
\code
numero = Lua.RetornarResultadoNumero();
\endcode
*/
lua_Number GD_SistemaLua::RetornarResultadoNumero(void)
{
    lua_Number nRet;
    if( lua_isnumber(this->LuaMV, -1) )
        nRet = lua_tonumber(this->LuaMV, -1);
    
    lua_pop(this->LuaMV,1);
    
    return nRet;
}

/*!
Ejemplo:
\code
int texto = Lua.RetornarResultadoCadena();
\endcode
*/
const char *GD_SistemaLua::RetornarResultadoCadena(void)
{
    const char *strDev;
    if( lua_isstring(this->LuaMV, -1) )
        strDev = lua_tostring(this->LuaMV, -1);
        
    lua_pop(this->LuaMV,1);
    
    return strDev;
}

/*!
Los resultados deben ser limpiados antes de realizar cualquier otra operaci&oacute;n de Lua diferente a retornar.

Ejemplo:
\code
Lua.LimparResultados();
\endcode
*/
void GD_SistemaLua::LimpiarResultados(void)
{
    // Destuimos todos los elementos de la pila
    lua_pop(this->LuaMV, lua_gettop(this->LuaMV) );
}


// *********
// Funciones C a LUA
// *********
/*!
Registra una funci&oacute;n, programada en nuestro c&oacute;digo GDT, para ser usada como una funci&oacute;n de Lua.
\param strNombre es el nombre que tendr&aacute; la funci&oacute;n en Lua.
\param fFunction es el la funci&oacute;n en nuestro c&oacute;digo GDT.

Ejemplo:
\code
Lua.RegistrarFuncion("HacerSumas", LUA_Hacer_Sumas);
\endcode
*/
void GD_SistemaLua::RegistrarFuncion(const char *strNombre, lua_CFunction fFuncion)
{
    lua_register(this->LuaMV, strNombre, fFuncion);
}

/*!
Ejemplo:
\code
parametros = Lua.NumeroParametros();
\endcode
*/
int GD_SistemaLua::NumeroParametros(void)
{
    lua_gettop(this->LuaMV);
}

/*!
Ejemplo:
\code
numero = Lua.RetornarParametroNumero(1);
\endcode
*/
lua_Number GD_SistemaLua::RetornarParametroNumero(int nParametro)
{
    return lua_tonumber(this->LuaMV, nParametro);
}

/*!
Ejemplo:
\endcode
texto = Lua.RetornarParametroCadena(2);
\endcode
*/
const char *GD_SistemaLua::RetornarParametroCadena(int nParametro)
{
    return lua_tostring(this->LuaMV, nParametro);
}

/*!
Los par&aacute;metros deben ser limpiados antes de realizar cualquier otra operaci&oacute;n de Lua diferente a retornar par&aacute;metros.

Ejemplo:
\code
Lua.LimparParametros();
\endcode
*/
void GD_SistemaLua::LimpiarParametros(void)
{
    lua_pop(this->LuaMV, lua_gettop(this->LuaMV) );
}

/*!
Ejemplo:
\code
Lua.PonerResultadoNumero(43);
\endcode
*/
void GD_SistemaLua::PonerResultadoNumero(lua_Number lNumero)
{
    lua_pushnumber(this->LuaMV, lNumero);
}

/*!
Ejemplo:
\code
Lua.PonerResultadoCadena("Adios");
\endcode
*/
void GD_SistemaLua::PonerResultadoCadena(const char *strCadena)
{
    lua_pushstring(this->LuaMV, strCadena);
}


// *********
// Errores
// *********
/*!
Por defecto, cuando se inicializa el sistema se activa que los errores se muestren autom&aacute;ticamente.

Ejemplo:
\code
Lua.MostrarErroresAutomaticamente( false );
\endcode
*/
void GD_SistemaLua::MostrarErroresAutomaticamente(bool bMostrar)
{
    // Cambiamos si los errores se mostrarï¿½ automï¿½icamente
    this->bAutoErrores = bMostrar;
}

/*!
Debe ser llamado s&oacute;lo cuando se sepa que se ha producido un error y cuando est&eacute; desactivado que se muestren errores autom&aacute;ticamente.

Ejemplo:
\code
Lua.MostrarError();
\endcode
*/
void GD_SistemaLua::MostrarError(void)
{
    // Mostramos el Error por pantalla
    printf("!SistemaLua ERROR: %s\n", lua_tostring(this->LuaMV, -1) );
    lua_pop(this->LuaMV, 1);
}


// -----------------
// FUNCIONES PRIVADAS DE LA CLASE
// ------------------
void GD_SistemaLua::Priv_LlegarATabla( char *strCadenaTabla )
{
    // Copiamos la Cadena   
    char *ptr;
    char strCadena[strlen(strCadenaTabla)];
    strcpy(strCadena, strCadenaTabla);
  
    
    // Obtenemos el Inicio que recibimos la global
    ptr = strtok( strCadena, this->strToken);
    lua_getglobal(this->LuaMV, ptr);
    
    // Obtenemos el nmero de elementos que despues cojeremos como tabla, y le suamos uno ya que habrï¿½que cojerlo de allï¿½
    int nGtIndex = lua_gettop(this->LuaMV) + 1;

    // El resto hasta llegar al final, los ponemos como cadenas en el Stack
    while( (ptr = strtok( NULL, this->strToken )) != NULL )
    {
           lua_pushstring(this->LuaMV, ptr);
           
           // Ahora usamos GetTable para que coja el valor de la tabla
           lua_gettable(this->LuaMV, - nGtIndex );   
    }

}

#endif // _GDT_SCRIPTING_

