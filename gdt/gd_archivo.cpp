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

#include "gd_archivo.h" // class's header file

// class constructor
GD_Archivo::GD_Archivo()
{
	// insert your code here
}

// class destructor
GD_Archivo::~GD_Archivo()
{
	// insert your code here
}

void GD_Archivo::AbrirParaEscribir(const char *strArchivo, bool bContinuar)
{
     FileSystem = GD_Sistema::device->getFileSystem(); 
     
     writeFile = FileSystem->createAndWriteFile(strArchivo, bContinuar);  
     
     bEscribir = true;  
}

void GD_Archivo::AbrirParaLeer(const char *strArchivo)
{
     FileSystem = GD_Sistema::device->getFileSystem(); 
     
     readFile = FileSystem->createAndOpenFile(strArchivo);   
     
     bEscribir = false; 
}

void GD_Archivo::Cerrar(void)
{
     if(bEscribir)
         writeFile->drop();
     else
         readFile->drop();
}

void GD_Archivo::Escribir(const char *strCadena, int bytes)
{
     if(bEscribir)
     {
         writeFile->write(strCadena, bytes);
     }
}

void GD_Archivo::Leer( char * buffer, int bytes)
{
     if(!bEscribir)
     {
         readFile->read( buffer, bytes);
     }
}

int GD_Archivo::Bytes(void)
{
     if(!bEscribir)
     {
         readFile->getSize();
     }
}

bool GD_Archivo::CambiarPosicion(int posicion, bool bRelativo)
{
     if(bEscribir)
     {
         return writeFile->seek(posicion, bRelativo);
     }
     else
     {
         return readFile->seek(posicion, bRelativo);
     }        
}

int GD_Archivo::Posicion(void)
{
    if(bEscribir)
    {
        return writeFile->getPos();
    }
    else
    {
        return readFile->getPos();
    }  
}

const char *GD_Archivo::NombreArchivo(void)
{
    if(bEscribir)
    {
        return writeFile->getFileName();
    }
    else
    {
        return readFile->getFileName();
    }       
}
