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
* \class GDT::Gui::Edicion
*
* Este Control GUI nos permite ingresar texto a trav&eacute;s de una
* caja donde aparecen los caracteres que escribimos.
*
* Considerese de aquï¿½en adelante "Edicion" como un ejemplo de un
* objeto instanciado de esta clase.
*/

#include "gd_guiedicion.h" // class's header file

// class constructor
GDT::Gui::Edicion::Edicion()
{
	// insert your code here
}

// class destructor
GDT::Gui::Edicion::~Edicion()
{
	// insert your code here
}

/*!
\param x1,y1 posici&oacute;n de cuadro de edici&oacute;n.
\param x2,y2 hasta donde llega el cuadro de edici&oacute;n.
\param texto es el texto inicial con el que se crea.
\param borde true si queremos que el cuadro tenga borde.
\param padre por defecto es 0. Si no esta seguro, omita este par&aacute;metro.

Ejemplo:
\code
Edicion.Crearl(5,5, 30,15, L"Escribe aqui", true);
\endcode
*/
void GDT::Gui::Edicion::Crear ( int x1, int y1, int x2, int y2, wchar_t * texto, bool borde,IGUIElement* padre )
{
	RegistrarDevice ( Sistema::device );

	//IVideoDriver* driver = midevice->getVideoDriver();
	IGUIEnvironment* guienv = midevice->getGUIEnvironment();

	editbox=guienv->addEditBox ( texto, rect<s32> ( x1,y1,x2,y2 ),borde,padre, Sistema::ContadorElementosGui++ );
	guiele = editbox;
}

/*!
\param max el n&uacute;mero m&aacute;ximo de caracteres. Poner 0 para infinito.

Ejemplo:
\code
Edicion.CaracteresMaximo(20);
\endcode
*/
void GDT::Gui::Edicion::CaracteresMaximo ( int max )
{
	editbox->setMax ( max );
}

/*!
Ejemplo:
\code
int maximo = Edicion.RetornarCaracteresMaximo();
\endcode
*/
int GDT::Gui::Edicion::RetornarCaracteresMaximo ( void )
{
	return editbox->getMax();
}
