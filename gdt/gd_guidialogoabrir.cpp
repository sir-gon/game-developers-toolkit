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
* \class GDT::Gui::DialogoAbrir
*
* Este Control GUI nos permite interactuar con el sistema de archivos,
* mostrando las carpetas y archivos, y brindando la posibilidad de navegar
* y escoger el archivo que se desea.
*
* Uselo para permitir que el usuario pueda cargar o salvar datos usando archivos.
*/

#include "gd_guidialogoabrir.h" // class's header file

// class constructor
GDT::Gui::DialogoAbrir::DialogoAbrir()
{
	// insert your code here
}

// class destructor
GDT::Gui::DialogoAbrir::~DialogoAbrir()
{
	// insert your code here
}

/*!
* \param titulo es el titulo del cuadro.
* \param modal true si queremo que el control sea modal.
* \param padre por defecto es 0. Si no esta seguro, omita este par&aacute;metro.
*
* Ejemplo:
* \code
* DAbrir.Crear(L"Elige un archivo para cargar", true);
* \endcode
*/
void GDT::Gui::DialogoAbrir::Crear ( wchar_t * titulo, bool modal, IGUIElement* padre )
{
	RegistrarDevice ( Sistema::device );

	//IVideoDriver* driver = midevice->getVideoDriver();
	IGUIEnvironment* guienv = midevice->getGUIEnvironment();

	opendlg=guienv->addFileOpenDialog ( titulo, modal, padre, Sistema::ContadorElementosGui++ );
	guiele = opendlg;
}

