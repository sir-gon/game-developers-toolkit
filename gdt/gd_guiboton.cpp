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

#include "gd_guiboton.h" // class's header file

// class constructor
GD_GuiBoton::GD_GuiBoton()
{
	// insert your code here
}

// class destructor
GD_GuiBoton::~GD_GuiBoton()
{
	// insert your code here
}

void GD_GuiBoton::Crear(int x1, int y1, int x2, int y2,IGUIElement* padre)
{

    RegistrarDevice(GD_Sistema::device);
    
    IVideoDriver* driver = midevice->getVideoDriver();
    IGUIEnvironment* guienv = midevice->getGUIEnvironment();
    
     boton=guienv->addButton(rect<s32>(x1,y1,x2,y2),padre, GD_Sistema::ContadorElementosGui++);

     
      guiele = boton;
}

void GD_GuiBoton::Crear(int x1, int y1, int x2, int y2, wchar_t * texto, IGUIElement* padre)
{    
    RegistrarDevice(GD_Sistema::device);
    
    IVideoDriver* driver = midevice->getVideoDriver();
    IGUIEnvironment* guienv = midevice->getGUIEnvironment();
    
     boton=guienv->addButton(rect<s32>(x1,y1,x2,y2),padre, GD_Sistema::ContadorElementosGui++);
     
     boton->setText(texto);
     
     guiele = boton;
}

void GD_GuiBoton::CrearConImagen(int x1, int y1, int x2, int y2, char* filename_boton_normal ,char* filename_boton_presionado , IGUIElement* padre)
{

    RegistrarDevice(GD_Sistema::device);
    
    IVideoDriver* driver = midevice->getVideoDriver();
    IGUIEnvironment* guienv = midevice->getGUIEnvironment();
    
     boton=guienv->addButton(rect<s32>(x1,y1,x2,y2),padre, GD_Sistema::ContadorElementosGui++);
 
     boton->setImage(driver->getTexture(filename_boton_normal));
     boton->setPressedImage(driver->getTexture(filename_boton_presionado)); 
     
      guiele = boton;
}
	

