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

#include "gd_listaarchivos.h" // class's header file

/*!
* \class GDT::ListaArchivos
*
* Implementa mï¿½odos de acceso a Directorios del sistema de archivos.
* Con esto podemos examinar el contenido de un directorio, sus archivos,
* otros directorios, la cantidad de elementos, etc.
*/
// class constructor
GDT::ListaArchivos::ListaArchivos()
{
	FileSystem = Sistema::device->getFileSystem();

	FileList= FileSystem->createFileList();
}

// class destructor
GDT::ListaArchivos::~ListaArchivos()
{
	// insert your code here
}

/*!
* \deprecated El constructor inicializa todo, no hace falta volver a repetirlo.
*/
void GDT::ListaArchivos::Crear ( void )
{
	FileSystem = Sistema::device->getFileSystem();

	FileList= FileSystem->createFileList();
}

/*!
* Ejemplo:
* \code
* int archivos = Lista.Numero();
* \endcode
*/
int GDT::ListaArchivos::Numero ( void )
{
	return FileList->getFileCount();
}

/*!
*/
const c8* GDT::ListaArchivos::Nombre ( int id )
{
	return FileList->getFileName ( id );
}

/*!
*/
const c8* GDT::ListaArchivos::NombreCompleto ( int id )
{
	return FileList->getFullFileName ( id );
}

/*!
* \return true si es directorio, en caso contrario retorna false.
*
* Ejemplo:
* \code
* bool directorio = Lista.EsDirectorio(6);
* \endcode
*/
bool GDT::ListaArchivos::EsDirectorio ( int id )
{
	return FileList->isDirectory ( id );
}
