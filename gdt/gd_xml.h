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

#ifndef GD_XML_H
#define GD_XML_H

#include "gd_sistema.h"

#define XML_LEIDO_NADA     EXN_NONE 
#define XML_LEIDO_ELEMENTO     EXN_ELEMENT
#define XML_LEIDO_FINELEMENTO  EXN_ELEMENT_END
#define XML_LEIDO_TEXTO        EXN_TEXT
#define XML_LEIDO_COMENTARIO   EXN_COMMENT

//! Escribir y Leer Archivos XML
/*!
Esta Clase nos permite manejar informaci&oacute;n, guardandola y leyendola en archivos XML.
Algunas ideas de porque puede ser &uacute;til trabajar con XML puede ser:

- Guardar/Leer la configuraci&oacute;n de nestro juego, las opciones que tome el usuario.

- Guardar/Leer el avance en un jugeo, para luego restaurarlo y continuar jugando desde el punto guardado.

- Guardar ac&aacute; el di&aacute;logo de los personajes, descripciones de objetos, etc. As&iacute; tambi&eacute;n es posible traducir nuestro juego a varios idiomas.

El formato del archivo es texto plano, codificado como UTF16, y estructurado como XML.
Es decir, de esta manera:

\code
<?xml version="1.0"?>
<!--Se admiten Comentarios-->
<elemento atributo1="Valor1" atributo2="Valor2">Este es un texto que contiene la etiqueta elemento.</elemento>
\endcode
*/
class GD_XML
{
	public:
		// class constructor
		GD_XML();
		// class destructor
		~GD_XML();
		
		IFileSystem* FileSystem;
		
		bool bEscribir; // True si es escribir y False si es Leer
		
		IXMLWriter* writeXML;
		IXMLReader* readXML;
		
		// Escribir
		//! Abre un archivo XML para escribir sobre &eacute;l.
		void AbrirParaEscribir(const char *strArchivo);
		//! Escribe la cabecera XML en un archivo
		void EscribirCabeceraXML(void);
		//! Escribe un elemento en el archivo XML
		void EscribirElemento(const wchar_t* nombre, bool vacio = false,
		          const wchar_t* attr1Nombre = 0, const wchar_t* attr1Valor = 0,
			      const wchar_t* attr2Nombre = 0, const wchar_t* attr2Valor = 0,
			      const wchar_t* attr3Nombre = 0, const wchar_t* attr3Valor = 0,
			      const wchar_t* attr4Nombre = 0, const wchar_t* attr4Valor = 0,
			      const wchar_t* attr5Nombre = 0, const wchar_t* attr5Valor = 0
			      );
		//! Escribe un comentario en el archivo XML.
		void EscribirComentario(const wchar_t* comentario);
		//! Escribe el cierre de una etiqueta XML.
		void EscribirCierreEtiqueta(const wchar_t* nombre);
		//! Escribe un texto en el archivo XML.
		void EscribirTexto(const wchar_t* texto);
		//! Escribe un salto de l&iacute;nea
		void EscribirRupturaLinea(void);

		// Leer
		//! Abre un archivo XML para leer de &eacute;l.
		void AbrirParaLeer(const char *strArchivo);
		//! Devuelve true si se est&aacute; leyendo del archivo.
		bool Leyendo();
		//! Devuelve el tipo de nodo que se ha le&iacute;do.
		EXML_NODE TipoNodo(void);
		//! Cuando se ha le&iacute;do un elemento, retorna el n&uacute;mero de atributos que tiene este.
		int NumeroAtributos(void);
		//! Devuelve el nombre del atributo que est&aacute; en la posici&oacute;n indicada.
		const wchar_t* NombreAtributo(int id);
		//! Devuelve el valor del atributo indicado.
		const wchar_t* ValorAtributo(int id);
		//! Devuelve el valor del atributo nombrado.
		const wchar_t* ValorAtributo(const wchar_t* atributo);
		//! Devuelve el nombre del nodo que se ha le&iacute;do.
		const wchar_t* NombreNodo(void);
		//! Devuelve los datos del nodo que se ha le&iacute;do.
		const wchar_t* DatosNodo(void);
		//! Devuelve true si el elemento le&iacute;do est&aacute; vac&iacute;o.
		bool ElementoVacio(void);
		//! Cierra un archivo XML abierto.
		void Cerrar();
	
};

#endif // GD_XML_H
