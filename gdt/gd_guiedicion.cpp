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

#include "gd_guiedicion.h" // class's header file

// class constructor
GD_GuiEdicion::GD_GuiEdicion()
{
	// insert your code here
}

// class destructor
GD_GuiEdicion::~GD_GuiEdicion()
{
	// insert your code here
}

void GD_GuiEdicion::Crear(int x1, int y1, int x2, int y2, wchar_t * texto, bool borde,IGUIElement* padre)
{

    RegistrarDevice(GD_Sistema::device);
    
    IVideoDriver* driver = midevice->getVideoDriver();
    IGUIEnvironment* guienv = midevice->getGUIEnvironment();
    
     editbox=guienv->addEditBox(texto, rect<s32>(x1,y1,x2,y2),borde,padre, GD_Sistema::ContadorElementosGui++);
      guiele = editbox;
}

// Poner 0 para infinito
void GD_GuiEdicion::CaracteresMaximo( int max )
{
     editbox->setMax(max);
}

int GD_GuiEdicion::RetornarCaracteresMaximo( void )
{
     return editbox->getMax();
}
