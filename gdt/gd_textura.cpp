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

#include "gd_textura.h" // class's header file

// class constructor
GD_Textura::GD_Textura()
{
	// insert your code here
}

// class destructor
GD_Textura::~GD_Textura()
{
	// insert your code here
}


void GD_Textura::Cargar(char* filename)
{
   mi_device = GD_Sistema::device;
     
   tex = GD_Sistema::device->getVideoDriver()->getTexture(filename);
}


ITexture* GD_Textura::Textura()
{
   return tex;
}

void GD_Textura::GenerarMapaNormales(float amplitud)
{
     mi_device->getVideoDriver()->makeNormalMapTexture(tex, amplitud);

} 

