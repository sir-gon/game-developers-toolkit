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
* \class GDT::Gui::Ventana
*/

#include "gd_guiventana.h" // class's header file

// class constructor
GDT::Gui::Ventana::Ventana()
{
	// insert your code here
}

// class destructor
GDT::Gui::Ventana::~Ventana()
{
	// insert your code here
}

/*!
En &eacute;l se podr&aacute;n insertar otros controles.

\param x1,y1 posici&oacute;n de la Ventana.
\param x2,y2 hastsa donde llega la Ventana.
\param texto titulo de la ventana.
\param modal si queremos que la ventana sea modal.
\param padre
*/
void GDT::Gui::Ventana::Crear(int x1, int y1, int x2, int y2, wchar_t * texto, bool modal, IGUIElement* padre)
{

	RegistrarDevice(Sistema::device);
	
	//IVideoDriver* driver = midevice->getVideoDriver();
	IGUIEnvironment* guienv = midevice->getGUIEnvironment();
	
	ventana=guienv->addWindow(rect<s32>(x1,y1,x2,y2),modal, texto, padre, Sistema::ContadorElementosGui++);
	
	// Provisional. Desactivamos y ocultamos el Bot&oacute;n de Cerrar.
	// Porque si la ventana adopta hijos de un error al cerrarse
	ventana->getCloseButton()->setEnabled(false); 
	ventana->getCloseButton()->setVisible(false); 
	
	guiele = ventana;
}
