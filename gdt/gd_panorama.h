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

#ifndef GD_PANORAMA_H
#define GD_PANORAMA_H

#include "gd_nodo.h" // inheriting class's header file

/**
* Panorama
*/
class GD_Panorama : public GD_Nodo
{
	public:
		// class constructor
		GD_Panorama();
		// class destructor
		~GD_Panorama();
		
         void CrearCubico(char* up, char* down, char* left, char* right, char* front,char* back);
         void CrearDomo(char* texturadomo, int hres, int vres, int texporc, int esfporc);       
};

#endif // GD_PANORAMA_H
