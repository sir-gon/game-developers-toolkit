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

//SE ESPERA DEFINICION COMO PARAMETRO DEL COMPILADOR
#ifdef _GDT_SCRIPTING_

#ifndef GD_SISTEMALUA_H
#define GD_SISTEMALUA_H

extern "C" 
{
   #include "lua.h"
   #include "lualib.h"
   #include "lauxlib.h"
}

#include <iostream>
#include <string.h>
#include <wchar.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

//EXPORTAR SIMBOLOS AL CREAR DLL
#ifndef _GDT_EXPORT_
  #ifdef WIN32
	#ifdef _GDT_DLL_
	   #define _GDT_EXPORT_ __declspec(dllexport)
	#else /* Not _GDT_DLL_ */
	   #define _GDT_EXPORT_ __declspec(dllimport)
	#endif /* Not _GDT_DLL_ */
  #else
// SINO, DEFINIR COMO NULO EL EXPORTADOR 
    #define _GDT_EXPORT_ /* Definido nulo */
  #endif  /* WIN32 */
#endif /* _GDT_EXPORT_ */

//! Sistema de Scripting LUA
class GD_SistemaLua
{
public:
	// class constructor
	_GDT_EXPORT_ GD_SistemaLua();
	_GDT_EXPORT_ GD_SistemaLua(lua_State* L);
	
	// class destructor
	_GDT_EXPORT_ ~GD_SistemaLua();
	
	//---------
	//Funciones
	//---------
	// Inicio y Cierre
	_GDT_EXPORT_ void Inicializar(void);
	//! Cierra el sistema Lua.
	_GDT_EXPORT_ void Cerrar(void);
	//! Obtiene la m&aacute;quina virtual Lua.
	_GDT_EXPORT_ lua_State* RetornarEstado(void);
		
	// Ejecucion
	//! Ejecuta una cadena Lua.
	_GDT_EXPORT_ int EjecutarCadena(char* strCadenaLua);
	//! Carga y ejecuta un archivo Lua.
	_GDT_EXPORT_ int EjecutarArchivo(char* strArchivo);
	
	// Obtenci� de valores
	//! Obtiene un n�mero de una variable global o de una variable que de una tabla.
	_GDT_EXPORT_ lua_Number RetornarNumero(char *strCadenaTabla);
	//! Obtiene una cadena de texto de una variable global o de una variable dentro de una tabla.
	_GDT_EXPORT_ const char *RetornarCadena( char *strCadenaTabla);
	
	// Cambio de valores
	//! Cambia el valor n&uacute;mero de una variable global o de una variable dentro de una tabla.
	_GDT_EXPORT_ void CambiarNumero(char *strCadenaTabla, lua_Number lnNumero);
	//! Cambia el texto de una variable global o de una variable dentro de una tabla.
	_GDT_EXPORT_ void CambiarCadena(char *strCadenaTabla, const char *strCadenaTexto);
	
	// Llamar Funciones
	//! Prepara una funci�n, que est� en un script Lua, para ser llamada desde GDT.
	_GDT_EXPORT_ void PrepararFuncion(char *strFuncion);
	//! Pone un par�metro n�mero a la funci�n Lua que va a ser llamada.
	_GDT_EXPORT_ void PonerParametroNumero(lua_Number lNumero);
	//! Pone un par�metro de cadena de texto a la funci�n Lua que va a ser llamada.
	_GDT_EXPORT_ void PonerParametroCadena(char *strCadena);
	//! Llama a una funci�n Lua previamente preparada.
	_GDT_EXPORT_ int LlamarFuncion(int nArgumentos, int nResultados);
	//! Obtiene el resultado n�mero de una funci�n Lua llamada.
	_GDT_EXPORT_ lua_Number RetornarResultadoNumero(void);
	//! Obtiene el resultado cadena de texto de una funci�n Lua llamada.
	_GDT_EXPORT_ const char *RetornarResultadoCadena(void);
	//! Borra de la menor�a todos los resultados devueltos por una funci�n Lua.
	_GDT_EXPORT_ void LimpiarResultados(void);
	
	// Funciones C a LUA
	//! El primer par�metro es el nombre que tendr� la funci�n en Lua.
	_GDT_EXPORT_ void RegistrarFuncion(const char *strNombre, lua_CFunction fFuncion);
	//! En una funci�n GDT a&ntilde;adida a Lua, retorna el n�mero de par�metros que ha recibido la funci�n.
	_GDT_EXPORT_ int NumeroParametros(void);
	//! En una funci�n GDT a&ntilde;adida a Lua, retorna el valor n�mero del par�metro indicado,
	_GDT_EXPORT_ lua_Number RetornarParametroNumero(int nParametro);
	//! En una funci�n GDT a&ntilde;adida a Lua, retorna la cadena de texto del par�metro indicado.
	_GDT_EXPORT_ const char *RetornarParametroCadena(int nParametro);
	//! En una funci�n GDT a&ntilde;adida a Lua, borra los par�metros de la memoria.
	_GDT_EXPORT_ void LimpiarParametros(void);
	//! En una funci�n GDT a&ntilde;adida a Lua, pone un n�mero como resultado (valor devuelto) de la funci�n.
	_GDT_EXPORT_ void PonerResultadoNumero(lua_Number lNumero);
	//! En una funci�n GDT a&ntilde;adida a Lua, pone una cadena de texto como resultado (valor devuelto) de la funci�n.
	_GDT_EXPORT_ void PonerResultadoCadena(const char *strCadena);
	
	
	// Errores
	//! Activa o desactiva que los errores encontrados durante el procesamiento de Lua se muestran autom�ticamente.
	_GDT_EXPORT_ void MostrarErroresAutomaticamente(bool bMostrar);
	//! Muestra, en la consola, informaci�n sobre un error Lua que se ha producido.
	_GDT_EXPORT_ void MostrarError();
	
private:
	lua_State* LuaMV;  
	
	char strToken[4];
	
	bool bAutoErrores;
	
	void Priv_LlegarATabla( char *strCadenaTabla );

};

#endif // GD_SISTEMALUA_H

#endif // _GDT_SCRIPTING_
