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

#ifndef GD_XML_H
#define GD_XML_H

#include "gd_sistema.h"

#define XML_LEIDO_NADA     EXN_NONE 
#define XML_LEIDO_ELEMENTO     EXN_ELEMENT
#define XML_LEIDO_FINELEMENTO  EXN_ELEMENT_END
#define XML_LEIDO_TEXTO        EXN_TEXT
#define XML_LEIDO_COMENTARIO   EXN_COMMENT
 
/**
 * Escribir y Leer Archivos XML
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
		void AbrirParaEscribir(const char *strArchivo);
		
		void EscribirCabeceraXML(void);
		
		
		void EscribirElemento(const wchar_t* nombre, bool vacio = false,
		          const wchar_t* attr1Nombre = 0, const wchar_t* attr1Valor = 0,
			      const wchar_t* attr2Nombre = 0, const wchar_t* attr2Valor = 0,
			      const wchar_t* attr3Nombre = 0, const wchar_t* attr3Valor = 0,
			      const wchar_t* attr4Nombre = 0, const wchar_t* attr4Valor = 0,
			      const wchar_t* attr5Nombre = 0, const wchar_t* attr5Valor = 0
			      );
        void EscribirComentario(const wchar_t* comentario);
        
        void EscribirCierreEtiqueta(const wchar_t* nombre);
        
        void EscribirTexto(const wchar_t* texto);
        
        void EscribirRupturaLinea(void);


	    // Leer
	    void AbrirParaLeer(const char *strArchivo);
	    
	    bool Leyendo();
	    
	    EXML_NODE TipoNodo(void);
	    
	    int NumeroAtributos(void);
	    const wchar_t* NombreAtributo(int id);
	    const wchar_t* ValorAtributo(int id);
	    const wchar_t* ValorAtributo(const wchar_t* atributo);
        const wchar_t* NombreNodo(void);
        const wchar_t* DatosNodo(void);
        bool ElementoVacio(void);
	    
	    void Cerrar();
		
};

#endif // GD_XML_H
