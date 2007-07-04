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

#ifndef GD_CARTELERA_H
#define GD_CARTELERA_H

#include "gd_nodo.h" // inheriting class's header file
#include "gd_escenario.h"

//! Maneja imagenes que siempre se ven frontalmente en la cámara
class GD_Cartelera : public GD_Nodo
{
	public:
		// class constructor
		GD_Cartelera();
		// class destructor
		~GD_Cartelera();
		
		IBillboardSceneNode* nodb;
		
        //! Carga una imágen como una Cartelera.
		void Crear(float tamx, float tamy, char* filename);
		void CrearColision( GD_Escenario scen,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz);
};

#endif // GD_CARTELERA_H
