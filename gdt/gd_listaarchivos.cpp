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

#include "gd_listaarchivos.h" // class's header file

// class constructor
GD_ListaArchivos::GD_ListaArchivos()
{
	// insert your code here
}

// class destructor
GD_ListaArchivos::~GD_ListaArchivos()
{
	// insert your code here
}

void GD_ListaArchivos::Crear(void)
{
     FileSystem = GD_Sistema::device->getFileSystem(); 
     
     FileList= FileSystem->createFileList();
}

int GD_ListaArchivos::Numero(void)
{
    return FileList->getFileCount();
}

const c8* GD_ListaArchivos::Nombre(int id)
{
      return FileList->getFileName(id);
}

const c8* GD_ListaArchivos::NombreCompleto(int id)
{
      return FileList->getFullFileName(id);
}

bool GD_ListaArchivos::EsDirectorio(int id)
{
      return FileList->isDirectory(id);
}
