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

#ifndef Archivo_H
#define Archivo_H

#include "gd_sistema.h"
#include "gd_cadena.h"

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

namespace GDT
{

//! Permite Leer y escribir en archivos de texto o estructuras.
class Archivo
{
	public:
		// class constructor
		_GDT_EXPORT_ Archivo();
		// class destructor
		_GDT_EXPORT_ ~Archivo();
		
		IFileSystem* FileSystem;
		
		bool bEscribir; // True si es escribir y False si es Leer
		
		IWriteFile* writeFile;
		IReadFile* readFile;
		//! Abre un archivo en modo Escritura
		_GDT_EXPORT_ void AbrirParaEscribir(const char *strArchivo, bool bContinuar = false);
		//! Abre un archivo en modo de Lectura
		_GDT_EXPORT_ void AbrirParaLeer(const char *strArchivo);
		//! Cierra el archivo abierto
		_GDT_EXPORT_ void Cerrar(void);
		//! Escribe la cadena en un archivo
		_GDT_EXPORT_ void Escribir(const char *strCadena, int bytes);
		//! Escribe la cadena en un archivo
		_GDT_EXPORT_ void Escribir(const char *strCadena);
		//! Escribe un entero en un archivo
		_GDT_EXPORT_ void Escribir(int numero);
		//! Lee el texto de un archivo y lo guarda en buffer
		_GDT_EXPORT_ void Leer(char *buffer, int bytes);
		
		// Defines para Escribir estructuras. FUNCIONAN!!!
		// El primer par&aacute;metro es la estructura, y el segundo el tipo.
		#define EscribirEstructura(estructura, tipo) writeFile->write( reinterpret_cast<char *>(&estructura), sizeof(tipo));
		#define LeerEstructura(estructura, tipo) readFile->read( reinterpret_cast<char *>(&estructura), sizeof(tipo));
		
        	_GDT_EXPORT_ int Bytes(void);

		_GDT_EXPORT_ bool CambiarPosicion(int posicion, bool bRelativo = false);
		_GDT_EXPORT_ int Posicion(void);
		//! Obtiene el nombre del archivo
		_GDT_EXPORT_ Cadena NombreArchivo(void);
};

} // FIN NAMESPACE GDT

#endif // Archivo_H
