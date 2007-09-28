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

/*!
* \class GDT::XML
* Esta Clase nos permite manejar informaci&oacute;n, guardandola y leyendola en archivos XML.
* Algunas ideas de porque puede ser &uacute;til trabajar con XML puede ser:
*
* - Guardar/Leer la configuraci&oacute;n de nestro juego, las opciones que tome el usuario.
* - Guardar/Leer el avance en un jugeo, para luego restaurarlo y continuar jugando desde el punto guardado.
* - Guardar ac&aacute; el di&aacute;logo de los personajes, descripciones de objetos, etc. As&iacute;
* tambi&eacute;n es posible traducir nuestro juego a varios idiomas.
*
* El formato del archivo es texto plano, codificado como UTF16, y estructurado como XML.
* Es decir, de esta manera:
*
* \code
* <?xml version="1.0"?>
* <!--Se admiten Comentarios-->
* <elemento atributo1="Valor1" atributo2="Valor2">Este es un texto que contiene la etiqueta elemento.</elemento>
* \endcode
*/

#include "gd_xml.h" // class's header file

// class constructor
GDT::XML::XML()
{
	// insert your code here
}

// class destructor
GDT::XML::~XML()
{
	// insert your code here
}

/*!
* Ejemplo:
* \code
* xml.AbrirParaEscribir("datos.xml");
* \endcode
*/
void GDT::XML::AbrirParaEscribir ( const char *strArchivo )
{
	FileSystem = Sistema::device->getFileSystem();

	writeXML = FileSystem->createXMLWriter ( strArchivo );

	bEscribir = true;
}

/*!
* Es necesario escribir la cabecera primero para que el archivo sea XML v&aacute;lido.
*
* Ejemplo:
* \code
* xml.EscribirCabeceraXML();
* \endcode
*/
void GDT::XML::EscribirCabeceraXML ( void )
{
	writeXML->writeXMLHeader();
}

/*!
Se pueden indicar hasta 5 atributos.

Los elementos son de la siguiente forma:

\code <nombre atributo1=valor1 atributo2=valor2> \endcode

Ejemplo:
\code
xml.EscribirElemento(L"persona", false, L"nombre", L"GDT", L"edad" , L"5");
\endcode
*/
void GDT::XML::EscribirElemento ( const wchar_t* nombre, bool vacio,
                                  const wchar_t* attr1Nombre, const wchar_t* attr1Valor,
                                  const wchar_t* attr2Nombre, const wchar_t* attr2Valor,
                                  const wchar_t* attr3Nombre, const wchar_t* attr3Valor,
                                  const wchar_t* attr4Nombre, const wchar_t* attr4Valor,
                                  const wchar_t* attr5Nombre, const wchar_t* attr5Valor
                                )
{
	if ( bEscribir )
		writeXML->writeElement ( nombre, vacio, attr1Nombre, attr1Valor,
		                         attr2Nombre, attr2Valor, attr3Nombre, attr3Valor,
		                         attr4Nombre, attr4Valor, attr5Nombre, attr5Valor );
}

/*!
Ejemplo:
\code
xml.EscribirComentario(L"Esto es un comentario");
\endcode
*/
void GDT::XML::EscribirComentario ( const wchar_t* comentario )
{
	if ( bEscribir )
		writeXML->writeComment ( comentario );
}

/*!
El estilo de la etiqueta de cierre es as&iacute;:
\code </nombre> \endcode

Ejemplo:
\code
xml.EscribirCierreCabecera(L"nombre");
\endcode
*/
void GDT::XML::EscribirCierreEtiqueta ( const wchar_t* nombre )
{
	if ( bEscribir )
		writeXML->writeClosingTag ( nombre );
}

/*!
El texto se escribe de la siguiente forma:
\code
<elemento>Texto</elemento>
\endcode

\code
xml.EscribirTexto(L"Hola XML");
\endcode
*/
void GDT::XML::EscribirTexto ( const wchar_t* texto )
{
	if ( bEscribir )
		writeXML->writeText ( texto );
}

/*!
Ejemplo:
\code
xml.EscribirRupturaLinea();
\endcode
*/
void GDT::XML::EscribirRupturaLinea ( void )
{
	if ( bEscribir )
		writeXML->writeLineBreak();
}

/*!
\param strArchivo es la ruta al archivo
Ejemplo:
\code
xml.AbrirParaLeer("datos.xml");
\endcode
*/
void GDT::XML::AbrirParaLeer ( const char *strArchivo )
{
	FileSystem = Sistema::device->getFileSystem();

	readXML = FileSystem->createXMLReader ( strArchivo );

	bEscribir = false;
}

/*!
Ejemplo:
\code
while (xml.Leyendo() )
{
}
\endcode
*/
bool GDT::XML::Leyendo()
{
	if ( !bEscribir )
		return readXML->read();
	return false;
}

/*!
Las constantes de cada tipo de nodo son:

    - XML_LEIDO_NADA
    - XML_LEIDO_ELEMENTO
    - XML_LEIDO_FINELEMENTO
    - XML_LEIDO_TEXTO
    - XML_LEIDO_COMENTARIO

Ejemplo:
\code
switch ( xml.TipoNodo() )
{
    case XML_LEIDO_ELEMENTO:
    break;
}
\endcode
*/
EXML_NODE GDT::XML::TipoNodo ( void )
{
	return readXML->getNodeType();
}

/*!
Ejemplo:
\code
int atributos = xml.NumeroAtributos();
\endcode
*/
int GDT::XML::NumeroAtributos ( void )
{
	return readXML->getAttributeCount();
}


const wchar_t* GDT::XML::NombreAtributo ( int id )
{
	return readXML->getAttributeName ( id );
}

const wchar_t* GDT::XML::ValorAtributo ( int id )
{
	return readXML->getAttributeValue ( id );
}

const wchar_t* GDT::XML::ValorAtributo ( const wchar_t* atributo )
{
	return readXML->getAttributeValueSafe ( atributo );
}

const wchar_t* GDT::XML::NombreNodo()
{
	return readXML->getNodeName();
}

const wchar_t* GDT::XML::DatosNodo()
{
	return readXML->getNodeData();
}

bool GDT::XML::ElementoVacio()
{
	return readXML->isEmptyElement();
}

/*!
Ejemplo:
\code
xml.Cerrar();
\endcode
*/
void GDT::XML::Cerrar ( void )
{
	if ( bEscribir )
		writeXML->drop();
	else
		readXML->drop();
}
