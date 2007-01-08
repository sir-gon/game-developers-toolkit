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

#ifndef GD_ARCHIVO_H
#define GD_ARCHIVO_H

#include "gd_sistema.h"

/**
 * Leer y escribir Archivos
 */
class GD_Archivo
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
		
		void AbrirParaEscribir(const char *strArchivo, bool bContinuar = false);
		void AbrirParaLeer(const char *strArchivo);
		void Cerrar(void);
		
		void Escribir(const char *strCadena, int bytes);
        void Leer(char *buffer, int bytes);
        
        // Defines para Escribir estructuras. FUNCIONAN!!!
        // El primer par�etro es la estructura, y el segundo el tipo.
        #define EscribirEstructura(estructura, tipo) writeFile->write( reinterpret_cast<char *>(&estructura), sizeof(tipo));
        #define LeerEstructura(estructura, tipo) readFile->read( reinterpret_cast<char *>(&estructura), sizeof(tipo));
        
        int Bytes(void);
		
		bool CambiarPosicion(int posicion, bool bRelativo = false);
		int Posicion(void);
		
		const char *NombreArchivo(void);
};

#endif // GD_ARCHIVO_H
