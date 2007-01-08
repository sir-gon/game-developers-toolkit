/*
* GDT (GAME DEVELOPERS TOOLKIT)
* Copyright (C) 2006 GDT STAFF
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include "gd_xml.h" // class's header file

// class constructor
GD_XML::GD_XML()
{
	// insert your code here
}

// class destructor
GD_XML::~GD_XML()
{
	// insert your code here
}

void GD_XML::AbrirParaEscribir(const char *strArchivo)
{
     FileSystem = GD_Sistema::device->getFileSystem(); 
     
     writeXML = FileSystem->createXMLWriter(strArchivo);  
     
     bEscribir = true;  
}

void GD_XML::EscribirCabeceraXML(void)
{
     writeXML->writeXMLHeader();
}

void GD_XML::EscribirElemento(const wchar_t* nombre, bool vacio,
		          const wchar_t* attr1Nombre, const wchar_t* attr1Valor,
			      const wchar_t* attr2Nombre, const wchar_t* attr2Valor,
			      const wchar_t* attr3Nombre, const wchar_t* attr3Valor,
			      const wchar_t* attr4Nombre, const wchar_t* attr4Valor,
			      const wchar_t* attr5Nombre, const wchar_t* attr5Valor
			      )
{
    if(bEscribir)
        writeXML->writeElement(nombre, vacio, attr1Nombre, attr1Valor, 
                     attr2Nombre, attr2Valor, attr3Nombre, attr3Valor,
                     attr4Nombre, attr4Valor, attr5Nombre, attr5Valor);
}

void GD_XML::EscribirComentario(const wchar_t* comentario)
{
     if(bEscribir)
         writeXML->writeComment(comentario);
}

void GD_XML::EscribirCierreEtiqueta(const wchar_t* nombre)
{
     if(bEscribir)
         writeXML->writeClosingTag(nombre);
}

void GD_XML::EscribirTexto(const wchar_t* texto)
{
     if(bEscribir)
         writeXML->writeText(texto);
}

void GD_XML::EscribirRupturaLinea(void)
{
     if(bEscribir)
         writeXML->writeLineBreak();
}

void GD_XML::AbrirParaLeer(const char *strArchivo)
{
     FileSystem = GD_Sistema::device->getFileSystem(); 
     
     readXML = FileSystem->createXMLReader(strArchivo);   
     
     bEscribir = false; 
}

bool GD_XML::Leyendo()
{
     if(!bEscribir)
         return readXML->read();
}

EXML_NODE GD_XML::TipoNodo(void)
{
    return readXML->getNodeType();
}

int GD_XML::NumeroAtributos(void)
{
    return readXML->getAttributeCount();
}

const wchar_t* GD_XML::NombreAtributo(int id)
{
      return readXML->getAttributeName(id);
}

const wchar_t* GD_XML::ValorAtributo(int id)
{
      return readXML->getAttributeValue(id);
}

const wchar_t* GD_XML::ValorAtributo(const wchar_t* atributo)
{
      return readXML->getAttributeValueSafe(atributo);
}

const wchar_t* GD_XML::NombreNodo()
{
      return readXML->getNodeName();
}

const wchar_t* GD_XML::DatosNodo()
{
      return readXML->getNodeData();
}

bool GD_XML::ElementoVacio()
{
     return readXML->isEmptyElement();
}

void GD_XML::Cerrar(void)
{
     if(bEscribir)
         writeXML->drop();
     else
         readXML->drop();
}
