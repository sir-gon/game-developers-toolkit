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

#ifndef GD_TEXTURA_H
#define GD_TEXTURA_H


#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


#include "gd_sistema.h"

/**
 * Textura
 */
class GD_Textura
{
	public:
		// class constructor
		GD_Textura();
		// class destructor
		~GD_Textura();
		
        IrrlichtDevice *mi_device;
		
		ITexture* tex;
		
		void Cargar(char* filename);
		
		ITexture* Textura();
		
		void GenerarMapaNormales(float amplitud=1.0);

};

#endif // GD_TEXTURA_H
