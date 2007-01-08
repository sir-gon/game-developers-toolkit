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
  
#ifndef GD_AGUA_H
#define GD_AGUA_H

#include "gd_nodo.h" // inheriting class's header file

/**
No description
*/
class GD_Agua : public GD_Nodo
{
	public:
		// class constructor
		GD_Agua();
		// class destructor
		~GD_Agua();
		
		scene::IAnimatedMesh* mesh;
		
    void CrearNormal(float x, float y, int nx, int ny,int tx,int ty,f32 AlturaOnda,f32 VelocidadOnda, f32 LongitudOnda, char* t);
    void CrearRealista(float x, float y, int nx, int ny,int tx,int ty,f32 AlturaOnda,f32 VelocidadOnda, f32 LongitudOnda, char* t1, char* t2);
};

#endif // GD_AGUA_H
