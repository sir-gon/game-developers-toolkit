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

#include "gd_gui.h" // class's header file

// class constructor
GD_gui::GD_gui()
{
	// insert your code here
}

// class destructor
GD_gui::~GD_gui()
{
	// insert your code here
}

void GD_gui::RegistrarDevice(	IrrlichtDevice *device )
{
	midevice = device;
}


bool GD_gui::EstaActivado()
{
      return guiele->isEnabled();
}

bool GD_gui::EstaVisible()
{
      return guiele->isVisible();
}

void GD_gui::Posicionar(int x, int y)
{
    guiele->move(core::position2d< s32 >( x,  y));
}

void GD_gui::Activado(bool estado)
{
    guiele->setEnabled(estado);
}

void GD_gui::Texto(const wchar_t *text) 
{
    guiele->setText(text); 
}

const wchar_t* GD_gui::RetornarTexto(void ) 
{
    return guiele->getText(); 
}
 
void GD_gui::Visible(bool estado)
{
    guiele->setVisible(estado); 
}

int GD_gui::ID()
{
    return guiele->getID();
}

IGUIElement* GD_gui::Elemento(void)
{
    return guiele;
}

void GD_gui::AdoptarHijo(IGUIElement* hijo)
{
    guiele->addChild(hijo);
}

void GD_gui::Destruir(void)
{
    guiele->remove();
}
