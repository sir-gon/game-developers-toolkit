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

#include "gd_guiventana.h" // class's header file

// class constructor
GD_GuiVentana::GD_GuiVentana()
{
	// insert your code here
}

// class destructor
GD_GuiVentana::~GD_GuiVentana()
{
	// insert your code here
}

void GD_GuiVentana::Crear(int x1, int y1, int x2, int y2, wchar_t * texto, bool modal, IGUIElement* padre)
{

    RegistrarDevice(GD_Sistema::device);
    
    IVideoDriver* driver = midevice->getVideoDriver();
    IGUIEnvironment* guienv = midevice->getGUIEnvironment();
    
     ventana=guienv->addWindow(rect<s32>(x1,y1,x2,y2),modal, texto, padre, GD_Sistema::ContadorElementosGui++);
     
     // Provisional. Desactivamos y ocultamos el Bot&oacute;n de Cerrar.
     // Porque si la ventana adopta hijos de un error al cerrarse
     ventana->getCloseButton()->setEnabled(false); 
     ventana->getCloseButton()->setVisible(false); 
     
      guiele = ventana;
}
