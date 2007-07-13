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

// HACK PARA COMPILAR EN VISUAL C++ 2005
#ifndef _GDT_EXPORT_
  #ifdef _GDT_VC_STUDIO_2005_
   #define _GDT_EXPORT_ __declspec(dllexport)
  #else
    #define _GDT_EXPORT_
  #endif
#endif

//! Imagenes que siempre se ven frontalmente en la c&aacute;mara
class GD_Cartelera : public GD_Nodo
{
public:
	// class constructor
	_GDT_EXPORT_ GD_Cartelera();
	// class destructor
	_GDT_EXPORT_ ~GD_Cartelera();
	
	IBillboardSceneNode* nodb;
	
	//! Carga una imágen como una Cartelera.
	_GDT_EXPORT_ void Crear(float tamx, float tamy, char* filename);
	_GDT_EXPORT_ void CrearColision( GD_Escenario scen,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz);
};

#endif // GD_CARTELERA_H
