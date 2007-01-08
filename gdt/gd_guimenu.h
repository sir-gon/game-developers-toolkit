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

#ifndef GD_GUIMENU_H
#define GD_GUIMENU_H

#include "gd_gui.h" // inheriting class's header file

#include "gd_sistema.h"
/**
 * GUI Menu y SubMenu
 */
class GD_GuiMenu : public GD_gui
{
	public:
		// class constructor
		GD_GuiMenu();
		GD_GuiMenu(IGUIContextMenu* SubMenu);
		// class destructor
		~GD_GuiMenu();
		
		IGUIContextMenu* menu;
		
		void Crear(IGUIElement* padre=0);
		void InsertarOpcion(wchar_t * texto, int nID, bool submenu = false);
		void InsertarSeparador(void);
			
		IGUIContextMenu* SubMenu(int  nID);
		
		void CambiarTextoOpcion(int nID, const wchar_t* texto);
		const wchar_t* RetornarTextoOpcion(int nID);
		
		void OpcionActivada(int nID, bool activado);
		bool OpcionEstaActivada(int nID);
};

#endif // GD_GUIMENU_H
