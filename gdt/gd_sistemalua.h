#ifdef _GDT_SCRIPTING_

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


/*
 * No description
 */
class GD_SistemaLua
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
		void Cerrar(void);
		lua_State* RetornarEstado(void);
			
		// Ejecuci�
		int EjecutarCadena(char* strCadenaLua);
		int EjecutarArchivo(char* strArchivo);
		
		// Obtenci� de valores
		lua_Number RetornarNumero(char *strCadenaTabla);
		const char *RetornarCadena( char *strCadenaTabla);
		
		// Cambio de valores
		void CambiarNumero(char *strCadenaTabla, lua_Number lnNumero);
		void CambiarCadena(char *strCadenaTabla, const char *strCadenaTexto);
		
		// Lallamar Funciones
		void PrepararFuncion(char *strFuncion);
		void PonerParametroNumero(lua_Number lNumero);
		void PonerParametroCadena(char *strCadena);
		int LlamarFuncion(int nArgumentos, int nResultados);
		lua_Number RetornarResultadoNumero(void);
		const char *RetornarResultadoCadena(void);
		void LimpiarResultados(void);
		
		// Funciones C a LUA
		void RegistrarFuncion(const char *strNombre, lua_CFunction fFuncion);
		int NumeroParametros(void);
		lua_Number RetornarParametroNumero(int nParametro);
		const char *RetornarParametroCadena(int nParametro);
		void LimpiarParametros(void);
		void PonerResultadoNumero(lua_Number lNumero);
		void PonerResultadoCadena(const char *strCadena);
		
		
		// Errores
		void MostrarErroresAutomaticamente(bool bMostrar);
		void MostrarError();
		
	private:
		lua_State* LuaMV;  
		
		char strToken[4];
		
		bool bAutoErrores;
		
		void Priv_LlegarATabla( char *strCadenaTabla );

};

#endif // GD_SISTEMALUA_H

#endif // _GDT_SCRIPTING_
