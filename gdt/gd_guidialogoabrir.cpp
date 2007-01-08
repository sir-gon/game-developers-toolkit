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

#include "gd_guidialogoabrir.h" // class's header file

// class constructor
GD_GuiDialogoAbrir::GD_GuiDialogoAbrir()
{
	// insert your code here
}

// class destructor
GD_GuiDialogoAbrir::~GD_GuiDialogoAbrir()
{
	// insert your code here
}

void GD_GuiDialogoAbrir::Crear(wchar_t * titulo, bool modal, IGUIElement* padre)
{

    RegistrarDevice(GD_Sistema::device);
    
    IVideoDriver* driver = midevice->getVideoDriver();
    IGUIEnvironment* guienv = midevice->getGUIEnvironment();
    
     opendlg=guienv->addFileOpenDialog(titulo, modal, padre, GD_Sistema::ContadorElementosGui++);
      guiele = opendlg;
}

