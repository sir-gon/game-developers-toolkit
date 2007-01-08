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

#ifndef GD_LUZ_H
#define GD_LUZ_H

#define RADIAL 1
#define DIRECCIONAL 2

#include "gd_nodo.h" // inheriting class's header file
#include "gd_escenario.h"

/**
* Luces
*/
class GD_Luz : public GD_Nodo
{
	public:
	// class constructor
	GD_Luz();
	// class destructor
	~GD_Luz();
	
	ILightSceneNode* nodl;
	video::SLight sluz;

	void Crear();
	void Crear(int r, int g ,int b, float radio);
	void Crear(int r, int g ,int b, float radio, int tipmo);
	
	void Crear(float x, float y, float z, float radio);
	void Crear(float x, float y, float z, float radio, int tipo);
	void Crear(float x, float y, float z, float r, float g ,float b, float radio);
	void Crear(float x, float y, float z, float r, float g ,float b, float radio, int tipo);
	
	void Tipo(int tipo);
	
	void HacerSombra(bool hacer);
	
	void Direccion(float x, float y, float z);
	void Direccion( vector3df vect);
	
	void Radio(float rad);
	
	void ColorAmbiente(s32 r,s32 g,s32 b);
	void ColorDifuso( s32 r,s32 g,s32 b);
	void ColorEspecular(s32 r,s32 g,s32 b);
	
	void AumentarColorAmbiente(float val);
	void AumentarColorDifuso(float val);
	void AumentarColorEspecular(float val);
	
	void CrearColision( GD_Escenario scen,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz);
};

#endif // GD_LUZ_H
