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

#ifndef ListaArchivos_H
#define ListaArchivos_H

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

namespace GDT
{

//! Representa una Lista de Archivos de un directorio
class ListaArchivos
{
public:
	// class constructor
	_GDT_EXPORT_ ListaArchivos();
	// class destructor
	_GDT_EXPORT_ ~ListaArchivos();
	
	IFileSystem* FileSystem;
	IFileList* FileList;
	
	_GDT_EXPORT_ void Crear(void);
	//! Obtiene el n&uacute;mero de elementos que tiene la lista.
	_GDT_EXPORT_ int Numero(void);
	//! Obtiene el nombre del archivo de la posici&oacute;n indicada de la lista.
	_GDT_EXPORT_ const c8* Nombre(int id);
	//! Obtiene el nombre completo (incluyendo la ruta) del archivo de la posici&oacute;n indicada de la lista.
	_GDT_EXPORT_ const c8* NombreCompleto(int id);
	//! Comprueba si el archivo de la posici&oacute;n indicada es un Directorio
	_GDT_EXPORT_ bool EsDirectorio(int id);
};

} // FIN NAMESPACE GDT

#endif // ListaArchivos_H
