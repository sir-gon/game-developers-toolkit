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

#ifndef GD_CADENA_H
#define GD_CADENA_H

#include <iostream>
#include "gd_sistema.h"
#include "gd_matematicas.h"

/* No documentar */
#ifndef _GDT_DOXYGEN_IGNORAR_
using namespace std;
#endif /* _GDT_DOXYGEN_IGNORAR_ */

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

#define PRECISION   8

namespace GDT
{

//! Manejo y conversi&oacute;n de cadenas de Texto.
	class Cadena// : public core::stringc
	{
		//private:
			//core::stringw mStringW;

		public:
			//! Representaci&oacute;n interna de la cadena
			core::stringc mStringC;

			//! Inicializa una Cadena en blanco
			_GDT_EXPORT_ Cadena();
			//! Inicializa la Cadena con una dada
			_GDT_EXPORT_ Cadena ( char* cadena );
			//! Inicializa la Cadena con una dada
			_GDT_EXPORT_ Cadena ( const char* cadena );
			//! Inicializa la Cadena con una dada
			_GDT_EXPORT_ Cadena ( wchar_t* cadena );
			//! Inicializa la Cadena con una dada
			_GDT_EXPORT_ Cadena ( const wchar_t* cadena );
			//! Destruye el objeto
			_GDT_EXPORT_ ~Cadena();

			//! Fabrica instancias de cadenas
			_GDT_EXPORT_ static Cadena Fabricar ( char* cadena );
			//! Fabrica instancias de cadenas
			_GDT_EXPORT_ static Cadena Fabricar ( const char* cadena );
			//! Fabrica instancias de cadenas
			_GDT_EXPORT_ static Cadena Fabricar ( wchar_t* cadena );
			//! Fabrica instancias de cadenas
			_GDT_EXPORT_ static Cadena Fabricar ( const wchar_t* cadena );

            #define FabCADENA(texto) GDT::Cadena::Fabricar(texto);
            //#define EscribirEstructura(estructura, tipo) writeFile->write( reinterpret_cast<char *>(&estructura), sizeof(tipo));

			// Retorna en diferentes tipos
			// int
			// float
			// char*
			// c8*
			// wchar_t*

			//! Devuelve la cadena como un n&uacute;mero Entero (int).
			_GDT_EXPORT_ u32 RetornarInt();
			//! Devuelve la cadena como un n&uacute;mero Decimal (float).
			_GDT_EXPORT_ float RetornarFloat();
			//! Devuelve la cadena como un (char*).
			_GDT_EXPORT_ char* RetornarChar();
			//! Devuelve la cadena como un (const char*).
			_GDT_EXPORT_ const char* RetornarConstChar();
			//! Devuelve la cadena como un (c8*)
			_GDT_EXPORT_ c8* RetornarC8();
			//! Devuelve la cadena como un (const c8*)
			_GDT_EXPORT_ const c8* RetornarConstC8();
			//! Devuelve la cadena como un (wchar_t*)
			_GDT_EXPORT_ wchar_t* RetornarWChar_t(); // parece que tiene un bug que no reconoce los dos primeros caracteres
			//! Devuelve la cadena como un (const wchar_t*)
			_GDT_EXPORT_ const wchar_t* RetornarConstWChar_t();
			//! Devuelve la cadena como un (stringc)
			_GDT_EXPORT_ irr::core::stringc RetornarStringC();


			_GDT_EXPORT_ void Sumar ( Cadena cadena );
			_GDT_EXPORT_ void Sumar ( wchar_t* cadena );
			_GDT_EXPORT_ void Sumar ( char* cadena );
			_GDT_EXPORT_ void Sumar ( const char* cadena );
			_GDT_EXPORT_ void Sumar ( float numero );
			_GDT_EXPORT_ void Sumar ( int numero );

	// --------------- Operaciones dentro de Cadenas --------------- //
			//! Busca la &uacute;ltima aparici&oacute;n del caracter en la Cadena
			_GDT_EXPORT_ s32 BuscarUltimo( char busqueda );
			//! Obtiene una subcadena.
			_GDT_EXPORT_ Cadena SubCadena( u32 inicio, u32 largo );
			//! Crea espacio en memoria y asigna el valor de char*.
			_GDT_EXPORT_ char* CopiarCharEnNuevaMemoria ( char* Original );
			//! Devuelve la cantidad de caracteres de la Cadena.
			_GDT_EXPORT_ u32 Longitud();

	// --------------- Operaciones Estaticas --------------- //
			// UTILIDADS ESTATICAS
			//! Devuelve la cantidad de caracteres de una cadena char* dada.
			_GDT_EXPORT_ static u32 Longitud ( char* cadena );
			//! Devuelve la cantidad de caracteres de una cadena const char* dada.
			_GDT_EXPORT_ static u32 Longitud ( const char* cadena );
			//! Devuelve la cantidad de caracteres de una cadena const char* dada.
			//_GDT_EXPORT_ static int Longitud(wchar_t* cadena);
			//! Devuelve el tamano del arreglo char*
			_GDT_EXPORT_ static u32 Longitud ( int cadena );

			// CONVERSORES ESTATICOS
			//! Convierte un n&uacute;mero entero en una cadena char*
			_GDT_EXPORT_ static char* ConvertirNumeroEnChar ( int numero );
			//! Convierte un n&uacute;mero real en cadena char*
			_GDT_EXPORT_ static char* ConvertirNumeroEnChar ( double numero );
			//! Convierte un n&uacute;mero entero en una cadena wchar_t*
			_GDT_EXPORT_ static wchar_t* ConvertirNumeroEnWchart ( int numero );
			//! Convierte un n&uacute;mero real en cadena wchar_t*
			_GDT_EXPORT_ static wchar_t* ConvertirNumeroEnWchart ( double number );
			//! Convierte una cadena wchar_t* a una cadena char*
			_GDT_EXPORT_ static char* ConvertirWchartEnChar ( wchar_t *cadena );
			//! Convierte una cadena char* a una cadena wchar_t*
			_GDT_EXPORT_ static wchar_t* ConvertirCharEnWchart ( char *cadena );


	// --------------- Operadores --------------- //
			// Operadores asignacion
			// =
			//! Guarda en la Cadena izquierda el texto de la Cadena de la derecha
			_GDT_EXPORT_ void operator = ( Cadena Cade );
			//! Guarda en la Cadena el texto del stringc
			_GDT_EXPORT_ void operator = ( irr::core::stringc );
			//! Guarda en la Cadena el texto de la cadena char*
			_GDT_EXPORT_ void operator = ( char* CharIgual );
			//! Guarda en la Cadena el texto de la cadena const char*
			_GDT_EXPORT_ void operator = ( const char* CharIgual );
			//! Guarda en la Cadena el entero
			_GDT_EXPORT_ void operator = ( int IntIgual );
			//! Guarda en la Cadena el float
			_GDT_EXPORT_ void operator = ( float FloatIgual );
			//! Guarda en la Cadena el texto de la cadena wchar_t*
			_GDT_EXPORT_ void operator = ( wchar_t* WCharIgual );
			//! Guarda en la Cadena el texto de la cadena const wchar_t*
			_GDT_EXPORT_ void operator = ( const wchar_t* WCharIgual );


			// Operadores comparacion
			// ==
			// Compara si las Cadenas son iguales
			_GDT_EXPORT_ bool operator== ( Cadena cadena );
			// Compara si la Cadena es igual la cadena char*
			_GDT_EXPORT_ bool operator== ( char* cadena );
			// Compara si la Cadena es igual la cadena char*
			_GDT_EXPORT_ bool operator== ( wchar_t* cadena );

			// !=
			// Compara si las Cadenas son distintas
			_GDT_EXPORT_ bool operator!= ( Cadena cadena );
			// Compara si la Cadena es distinta de la cadena char*
			_GDT_EXPORT_ bool operator!= ( char* cadena );
			// Compara si la Cadena es distinta de la cadena wchar_t*
			_GDT_EXPORT_ bool operator!= ( wchar_t* cadena );

			// Operador Suma Binaria +
			//! Concatenar Cadena con un n&uacute;mero entero
			_GDT_EXPORT_ Cadena operator+ ( int numero );
			//! Concatenar Cadena con un n&uacute;mero float
			_GDT_EXPORT_ Cadena operator+ ( float numero );
			//! Concatenar Cadena con un n&uacute;mero double
			_GDT_EXPORT_ Cadena operator+ ( double numero );
			//! Concatenar Cadena con una cadena "char"
			_GDT_EXPORT_ Cadena operator+ ( const char* cadena );
			//! Concatenar Cadena con cadena "w_chart"
			_GDT_EXPORT_ Cadena operator+ ( const wchar_t* cadena );
			//! Concatenar Cadena con otra Cadena
			_GDT_EXPORT_ Cadena operator+ ( Cadena cadena );

			// Operador Suma-Asignacion
			//! Concatena el numero entero de la derecha en la Cadena izquierda
			_GDT_EXPORT_ void operator+= ( int numero );
			//! Concatena el numero float de la derecha en la Cadena izquierda
			_GDT_EXPORT_ void operator+= ( float numero );
			//! Concatena el numero real de la derecha en la Cadena izquierda
			//_GDT_EXPORT_ void operator+= (double numero);
			//! Concatena la una cadena "char*" de la derecha en la Cadena izquierda
			_GDT_EXPORT_ void operator+= ( const char* cadena );
			//! Concatena la una cadena "w_chart*" de la derecha en la Cadena izquierda
			_GDT_EXPORT_ void operator+= ( const wchar_t* cadena );
			//! Concatena la Cadena de la derecha en la Cadena izquierda
			_GDT_EXPORT_ void operator+= ( Cadena cadena );

	}; // FIN CLASE

} // FIN NAMESPACE

#endif // Cadena_H
