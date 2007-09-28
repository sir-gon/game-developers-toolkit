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

/*!
* \class GDT::Gui::Fundido
*
*
*/

#include "gd_fundido.h" // class's header file

// class constructor
GDT::Gui::Fundido::Fundido()
{
	// insert your code here
}

// class destructor
GDT::Gui::Fundido::~Fundido()
{
	// insert your code here
}

void GDT::Gui::Fundido::Crear()
{
	RegistrarDevice ( Sistema::device );

	//IVideoDriver* driver = midevice->getVideoDriver();
	IGUIEnvironment* guienv = midevice->getGUIEnvironment();

	//fundido=guienv->addInOutFader(rect<s32>(0,0,TamPantalla.Width, TamPantalla.Height), 0, -1);
	fundido=guienv->addInOutFader();

	guiele = fundido;
}
/*
void GDT::Gui::Fundido::Crear( int x1, int y1, int x2, int y2)
{

    RegistrarDevice(Sistema::device);

    IVideoDriver* driver = midevice->getVideoDriver();
    IGUIEnvironment* guienv = midevice->getGUIEnvironment();

    rect<s32> rec(x1,y1,x2,y2);

     fundido = guienv->addInOutFader(rec, 0, -1);

      guiele = fundido;
}
*/

void GDT::Gui::Fundido::Color ( int r, int g, int b )
{
	fundido->setColor ( video::SColor ( 0, r, g, b ) );
}

void GDT::Gui::Fundido::FundirHaciaDentro ( int tiempo )
{
	fundido->fadeIn ( tiempo );
}

void GDT::Gui::Fundido::FundirHaciaFuera ( int tiempo )
{
	fundido->fadeOut ( tiempo );
}

bool GDT::Gui::Fundido::Terminado ( void )
{
	return fundido->isReady();
}
