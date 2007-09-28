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
* \class GDT::Gui::Boton
*
*/

#include "gd_guiboton.h" // class's header file

// class constructor
GDT::Gui::Boton::Boton()
{
	// insert your code here
}

// class destructor
GDT::Gui::Boton::~Boton()
{
	// insert your code here
}

/*!
\param x1,y1 posici&oacute;n del Bot&oacute;n.
\param x2,y2 hasta donde llega el Bot&oacute;n.
\param padre por defecto es 0. Si no esta seguro, omita este par&aacute;metro.

Ejemplo:
\code
Boton.Crear(5,5, 35,25);
\endcode
*/
void GDT::Gui::Boton::Crear ( int x1, int y1, int x2, int y2,IGUIElement* padre )
{
	RegistrarDevice ( Sistema::device );

	//IVideoDriver* driver = midevice->getVideoDriver();
	IGUIEnvironment* guienv = midevice->getGUIEnvironment();

	boton=guienv->addButton ( rect<s32> ( x1,y1,x2,y2 ),padre, Sistema::ContadorElementosGui++ );


	guiele = boton;
}

/*!
\param x1,y1 posici&oacute;n del Bot&oacute;n.
\param x2,y2 hasta donde llega el Bot&oacute;n.
\param texto es el texto con que se crear&aacute; el bot&oacute;n.
\param padre por defecto es 0. Si no esta seguro, omita este par&aacute;metro.

Ejemplo:
\code
Boton.Texto(5,5, 35,25,L"Pulsame");
\endcode
*/
void GDT::Gui::Boton::Crear ( int x1, int y1, int x2, int y2, wchar_t * texto, IGUIElement* padre )
{
	RegistrarDevice ( Sistema::device );

	//IVideoDriver* driver = midevice->getVideoDriver();
	IGUIEnvironment* guienv = midevice->getGUIEnvironment();

	boton=guienv->addButton ( rect<s32> ( x1,y1,x2,y2 ),padre, Sistema::ContadorElementosGui++ );

	boton->setText ( texto );

	guiele = boton;
}

/*!
\param x1,y1 posici&oacute;n del Bot&oacute;n.
\param x2,y2 hasta donde llega el Bot&oacute;n.
\param filename_boton_normal ruta a la imagen normal del bot&oacute;n.
\param filename_boton_presionado ruta a la imagen del bot&oacute;n cuando se pulsa.
\param padre por defecto es 0. Si no esta seguro, omita este par&aacute;metro.
*/
void GDT::Gui::Boton::CrearConImagen ( int x1, int y1, int x2, int y2, char* filename_boton_normal ,char* filename_boton_presionado , IGUIElement* padre )
{

	RegistrarDevice ( Sistema::device );

	IVideoDriver* driver = midevice->getVideoDriver();
	IGUIEnvironment* guienv = midevice->getGUIEnvironment();

	boton=guienv->addButton ( rect<s32> ( x1,y1,x2,y2 ),padre, Sistema::ContadorElementosGui++ );

	boton->setImage ( driver->getTexture ( filename_boton_normal ) );
	boton->setPressedImage ( driver->getTexture ( filename_boton_presionado ) );

	guiele = boton;
}


