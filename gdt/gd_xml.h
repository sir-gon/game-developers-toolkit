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

#ifndef XML_H
#define XML_H

#include "gd_sistema.h"

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

#define XML_LEIDO_NADA     EXN_NONE
#define XML_LEIDO_ELEMENTO     EXN_ELEMENT
#define XML_LEIDO_FINELEMENTO  EXN_ELEMENT_END
#define XML_LEIDO_TEXTO        EXN_TEXT
#define XML_LEIDO_COMENTARIO   EXN_COMMENT

namespace GDT
{

//! Escribir y Leer Archivos XML
	class XML
	{
		public:
			// class constructor
			_GDT_EXPORT_ XML();
			// class destructor
			_GDT_EXPORT_ ~XML();

			IFileSystem* FileSystem;

			bool bEscribir; // True si es escribir y False si es Leer

			IXMLWriter* writeXML;
			IXMLReader* readXML;

			// Escribir
			//! Abre un archivo XML para escribir sobre &eacute;l.
			_GDT_EXPORT_ void AbrirParaEscribir ( const char *strArchivo );
			//! Escribe la cabecera XML en un archivo
			_GDT_EXPORT_ void EscribirCabeceraXML ( void );
			//! Escribe un elemento en el archivo XML
			_GDT_EXPORT_ void EscribirElemento ( const wchar_t* nombre, bool vacio = false,
			                                     const wchar_t* attr1Nombre = 0, const wchar_t* attr1Valor = 0,
			                                     const wchar_t* attr2Nombre = 0, const wchar_t* attr2Valor = 0,
			                                     const wchar_t* attr3Nombre = 0, const wchar_t* attr3Valor = 0,
			                                     const wchar_t* attr4Nombre = 0, const wchar_t* attr4Valor = 0,
			                                     const wchar_t* attr5Nombre = 0, const wchar_t* attr5Valor = 0
			                                   );
			//! Escribe un comentario en el archivo XML.
			_GDT_EXPORT_ void EscribirComentario ( const wchar_t* comentario );
			//! Escribe el cierre de una etiqueta XML.
			_GDT_EXPORT_ void EscribirCierreEtiqueta ( const wchar_t* nombre );
			//! Escribe un texto en el archivo XML.
			_GDT_EXPORT_ void EscribirTexto ( const wchar_t* texto );
			//! Escribe un salto de l&iacute;nea
			_GDT_EXPORT_ void EscribirRupturaLinea ( void );

			// Leer
			//! Abre un archivo XML para leer de &eacute;l.
			_GDT_EXPORT_ void AbrirParaLeer ( const char *strArchivo );
			//! Devuelve true si se est&aacute; leyendo del archivo.
			_GDT_EXPORT_ bool Leyendo();
			//! Devuelve el tipo de nodo que se ha le&iacute;do.
			_GDT_EXPORT_ EXML_NODE TipoNodo ( void );
			//! Cuando se ha le&iacute;do un elemento, retorna el n&uacute;mero de atributos que tiene este.
			_GDT_EXPORT_ int NumeroAtributos ( void );
			//! Devuelve el nombre del atributo que est&aacute; en la posici&oacute;n indicada.
			_GDT_EXPORT_ const wchar_t* NombreAtributo ( int id );
			//! Devuelve el valor del atributo indicado.
			_GDT_EXPORT_ const wchar_t* ValorAtributo ( int id );
			//! Devuelve el valor del atributo nombrado.
			_GDT_EXPORT_ const wchar_t* ValorAtributo ( const wchar_t* atributo );
			//! Devuelve el nombre del nodo que se ha le&iacute;do.
			_GDT_EXPORT_ const wchar_t* NombreNodo ( void );
			//! Devuelve los datos del nodo que se ha le&iacute;do.
			_GDT_EXPORT_ const wchar_t* DatosNodo ( void );
			//! Devuelve true si el elemento le&iacute;do est&aacute; vac&iacute;o.
			_GDT_EXPORT_ bool ElementoVacio ( void );
			//! Cierra un archivo XML abierto.
			_GDT_EXPORT_ void Cerrar();

	};

} // FIN NAMESPACE

#endif // XML_H
