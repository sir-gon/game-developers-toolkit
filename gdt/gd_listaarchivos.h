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

#ifndef GD_LISTAARCHIVOS_H
#define GD_LISTAARCHIVOS_H

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

//! Representa una Lista de Archivos de un directorio /
class _GDT_EXPORT_ GD_ListaArchivos
{
public:
	// class constructor
	GD_ListaArchivos();
	// class destructor
	~GD_ListaArchivos();
	
	IFileSystem* FileSystem;
	IFileList* FileList;
	
	void Crear(void);
	//! Obtiene el n&uacute;mero de elementos que tiene la lista.
	int Numero(void);
	//! Obtiene el nombre del archivo de la posici&oacute;n indicada de la lista.
	const c8* Nombre(int id);
	//! Obtiene el nombre completo (incluyendo la ruta) del archivo de la posici&oacute;n indicada de la lista.
	const c8* NombreCompleto(int id);
	//! Comprueba si el archivo de la posici&oacute;n indicada es un Directorio
	bool EsDirectorio(int id);
};

#endif // GD_LISTAARCHIVOS_H
