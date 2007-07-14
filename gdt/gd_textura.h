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

#ifndef GD_TEXTURA_H
#define GD_TEXTURA_H


#include <irrlicht.h>
#include "gd_sistema.h"

/* No documentar */
#ifndef _GDT_DOXYGEN_IGNORAR_
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
#endif /* _GDT_DOXYGEN_IGNORAR_ */

// HACK PARA EXPORTAR SIMBOLOS EN DLL COMPILADOS CON VISUAL C++ 2005
#ifndef _GDT_EXPORT_
  #ifdef _GDT_VC_STUDIO_2005_
   #define _GDT_EXPORT_ __declspec(dllexport)
  #else
    #define _GDT_EXPORT_
  #endif
#endif

//! Representa una textura.
class GD_Textura
{
	public:
		// class constructor
		_GDT_EXPORT_ GD_Textura();
		// class destructor
		_GDT_EXPORT_ ~GD_Textura();
		
        IrrlichtDevice *mi_device;
		
		ITexture* tex;

		//! Carga una Textura
		_GDT_EXPORT_ void Cargar(char* filename);
		//! Retorna el objeto interno de la Textura.
		_GDT_EXPORT_ ITexture* Textura();
		//! Genera un mapa de normales a partir de la Textura
		_GDT_EXPORT_ void GenerarMapaNormales(float amplitud=1.0);

};

#endif // GD_TEXTURA_H
