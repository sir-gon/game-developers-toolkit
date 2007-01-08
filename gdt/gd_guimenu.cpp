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

#include "gd_guimenu.h" // class's header file

// class constructor
GD_GuiMenu::GD_GuiMenu()
{
	// insert your code here
}

GD_GuiMenu::GD_GuiMenu(IGUIContextMenu* SubMenu)
{
	menu = SubMenu;
}

// class destructor
GD_GuiMenu::~GD_GuiMenu()
{
	// insert your code here
}

void GD_GuiMenu::Crear(IGUIElement* padre)
{

    RegistrarDevice(GD_Sistema::device);
    
    IVideoDriver* driver = midevice->getVideoDriver();
    IGUIEnvironment* guienv = midevice->getGUIEnvironment();
    
     menu=guienv->addMenu(padre, GD_Sistema::ContadorElementosGui++);
     
      guiele = menu;
}

void GD_GuiMenu::InsertarOpcion(wchar_t * texto, int nID, bool submenu)
{
    menu->addItem(texto, nID, true, submenu);
}

void GD_GuiMenu::InsertarSeparador(void)
{
    menu->addSeparator();
}

IGUIContextMenu* GD_GuiMenu::SubMenu(int  nID)
{
    return menu->getSubMenu(nID);
}

void GD_GuiMenu::CambiarTextoOpcion(int nID, const wchar_t* texto)
{
     menu->setItemText(nID, texto);
}

const wchar_t* GD_GuiMenu::RetornarTextoOpcion(int nID)
{
      return menu->getItemText(nID);
}

void GD_GuiMenu::OpcionActivada(int nID, bool activado)
{
     menu->setItemEnabled(nID, activado);
}

bool GD_GuiMenu::OpcionEstaActivada(int nID)
{
     return menu->isItemEnabled(nID);
}
