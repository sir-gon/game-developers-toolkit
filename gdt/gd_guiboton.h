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

#ifndef GD_GUIBOTON_H
#define GD_GUIBOTON_H

#include "gd_gui.h" // inheriting class's header file

#include "gd_sistema.h"
/*
 * GUI Botones 
 */
class GD_GuiBoton : public GD_gui
{
	public:
		// class constructor
		GD_GuiBoton();
		// class destructor
		~GD_GuiBoton();
		
		IGUIButton* boton;

         void Crear(int x1, int y1, int x2, int y2, IGUIElement* padre=0); 
         void Crear(int x1, int y1, int x2, int y2, wchar_t * texto, IGUIElement* padre=0);
         void CrearConImagen(int x1, int y1, int x2, int y2, char* filename_boton_normal ,char* filename_boton_presionado, IGUIElement* padre=0);
};

#endif // GD_GUIBOTON_H
