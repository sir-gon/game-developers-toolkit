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

#ifndef GD_PARTICULA_H
#define GD_PARTICULA_H

#include "gd_nodo.h" // inheriting class's header file
#include "gd_escenario.h"

/**
* Particulas
*/
class GD_Particula : public GD_Nodo
{
	public:
		// class constructor
		GD_Particula();
		// class destructor
		~GD_Particula();
		
		IParticleSystemSceneNode* nodpt;
		
		void Crear(float x, float y, float z, float dx, float dy, float dz, int minparsec, int maxparsec, int tiempodevidamin, int tiempodevidamax, int maxang, char* filename);
		void Escalar(float x,float y);
		
		void CrearColision( GD_Escenario scen,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz);
};

#endif // GD_PARTICULA_H
