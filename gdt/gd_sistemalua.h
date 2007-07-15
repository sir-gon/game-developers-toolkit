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
	#ifdef BUILDING_DLL
	   #define _GDT_EXPORT_ __declspec (dllexport)
	#else /* Not BUILDING_DLL */
	   #define _GDT_EXPORT_ __declspec (dllimport)
	#endif /* Not BUILDING_DLL */
  #else
// SINO, DEFINIR COMO NULO EL EXPORTADOR 
    #define _GDT_EXPORT_ /* Definido nulo */
  #endif  /* WIN32 */
#endif /* _GDT_EXPORT_ */

//! Sistema de Scripting LUA
class _GDT_EXPORT_ GD_SistemaLua
{
public:
	// class constructor
	GD_SistemaLua();
	GD_SistemaLua(lua_State* L);
	
	// class destructor
	~GD_SistemaLua();
	
	//---------
	//Funciones
	//---------
	// Inicio y Cierre
	void Inicializar(void);
	//! Cierra el sistema Lua.
	void Cerrar(void);
	//! Obtiene la m&aacute;quina virtual Lua.
	lua_State* RetornarEstado(void);
		
	// Ejecucion
	//! Ejecuta una cadena Lua.
	int EjecutarCadena(char* strCadenaLua);
	//! Carga y ejecuta un archivo Lua.
	int EjecutarArchivo(char* strArchivo);
	
	// Obtenciï¿½ de valores
	//! Obtiene un número de una variable global o de una variable que de una tabla.
	lua_Number RetornarNumero(char *strCadenaTabla);
	//! Obtiene una cadena de texto de una variable global o de una variable dentro de una tabla.
	const char *RetornarCadena( char *strCadenaTabla);
	
	// Cambio de valores
	//! Cambia el valor n&uacute;mero de una variable global o de una variable dentro de una tabla.
	void CambiarNumero(char *strCadenaTabla, lua_Number lnNumero);
	//! Cambia el texto de una variable global o de una variable dentro de una tabla.
	void CambiarCadena(char *strCadenaTabla, const char *strCadenaTexto);
	
	// Llamar Funciones
	//! Prepara una función, que esté en un script Lua, para ser llamada desde GDT.
	void PrepararFuncion(char *strFuncion);
	//! Pone un parámetro número a la función Lua que va a ser llamada.
	void PonerParametroNumero(lua_Number lNumero);
	//! Pone un parámetro de cadena de texto a la función Lua que va a ser llamada.
	void PonerParametroCadena(char *strCadena);
	//! Llama a una función Lua previamente preparada.
	int LlamarFuncion(int nArgumentos, int nResultados);
	//! Obtiene el resultado número de una función Lua llamada.
	lua_Number RetornarResultadoNumero(void);
	//! Obtiene el resultado cadena de texto de una función Lua llamada.
	const char *RetornarResultadoCadena(void);
	//! Borra de la menoría todos los resultados devueltos por una función Lua.
	void LimpiarResultados(void);
	
	// Funciones C a LUA
	//! El primer parámetro es el nombre que tendrá la función en Lua.
	void RegistrarFuncion(const char *strNombre, lua_CFunction fFuncion);
	//! En una función GDT a&ntilde;adida a Lua, retorna el número de parámetros que ha recibido la función.
	int NumeroParametros(void);
	//! En una función GDT a&ntilde;adida a Lua, retorna el valor número del parámetro indicado,
	lua_Number RetornarParametroNumero(int nParametro);
	//! En una función GDT a&ntilde;adida a Lua, retorna la cadena de texto del parámetro indicado.
	const char *RetornarParametroCadena(int nParametro);
	//! En una función GDT a&ntilde;adida a Lua, borra los parámetros de la memoria.
	void LimpiarParametros(void);
	//! En una función GDT a&ntilde;adida a Lua, pone un número como resultado (valor devuelto) de la función.
	void PonerResultadoNumero(lua_Number lNumero);
	//! En una función GDT a&ntilde;adida a Lua, pone una cadena de texto como resultado (valor devuelto) de la función.
	void PonerResultadoCadena(const char *strCadena);
	
	
	// Errores
	//! Activa o desactiva que los errores encontrados durante el procesamiento de Lua se muestran automáticamente.
	void MostrarErroresAutomaticamente(bool bMostrar);
	//! Muestra, en la consola, información sobre un error Lua que se ha producido.
	void MostrarError();
	
private:
	lua_State* LuaMV;  
	
	char strToken[4];
	
	bool bAutoErrores;
	
	void Priv_LlegarATabla( char *strCadenaTabla );

};

#endif // GD_SISTEMALUA_H

#endif // _GDT_SCRIPTING_
