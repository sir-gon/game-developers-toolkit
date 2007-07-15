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

#ifndef GD_ARCHIVO_H
#define GD_ARCHIVO_H

#include "gd_sistema.h"

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

//! Permite Leer y escribir en archivos de texto o estructuras.
class _GDT_EXPORT_ GD_Archivo
{
	public:
		// class constructor
		GD_Archivo();
		// class destructor
		~GD_Archivo();
		
		IFileSystem* FileSystem;
		
		bool bEscribir; // True si es escribir y False si es Leer
		
		IWriteFile* writeFile;
		IReadFile* readFile;
		//! Abre un archivo en modo Escritura
		void AbrirParaEscribir(const char *strArchivo, bool bContinuar = false);
		//! Abre un archivo en modo de Lectura
		void AbrirParaLeer(const char *strArchivo);
		//! Cierra el archivo abierto
		void Cerrar(void);
		//! Escribe la cadena en un archivo
		void Escribir(const char *strCadena, int bytes);
		//! Lee el texto de un archivo y lo guarda en buffer
		void Leer(char *buffer, int bytes);
		
		// Defines para Escribir estructuras. FUNCIONAN!!!
		// El primer par&aacute;metro es la estructura, y el segundo el tipo.
		#define EscribirEstructura(estructura, tipo) writeFile->write( reinterpret_cast<char *>(&estructura), sizeof(tipo));
		#define LeerEstructura(estructura, tipo) readFile->read( reinterpret_cast<char *>(&estructura), sizeof(tipo));
		
        	int Bytes(void);

		bool CambiarPosicion(int posicion, bool bRelativo = false);
		int Posicion(void);
			
		const char *NombreArchivo(void);
};

#endif // GD_ARCHIVO_H
