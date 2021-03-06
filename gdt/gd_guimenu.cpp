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
* \class GDT::Gui::Menu
*
* Este Control GUI permite darle a escoger al usuario una de varias opciones.
*
* De esta manera, el men&uacute; puede servir para cosas como "configurar" el
* juego, preguntar que hacer cuando el jugador se enfrente a una situaci&oacute;n
* donde deba tomar alguna alternativa, o cualquier situaci&oacute;n donde sea
* necesario ofrecer opciones.
*/

#include "gd_guimenu.h" // class's header file

// class constructor
GDT::Gui::Menu::Menu()
{
	// insert your code here
}

GDT::Gui::Menu::Menu ( IGUIContextMenu* SubMenu )
{
	menu = SubMenu;
}

// class destructor
GDT::Gui::Menu::~Menu()
{
	// insert your code here
}

/*!
Ejemplo:
\code
Menu.Crear();
\endcode
*/
void GDT::Gui::Menu::Crear ( IGUIElement* padre )
{
	RegistrarDevice ( Sistema::device );

	//IVideoDriver* driver = midevice->getVideoDriver();
	IGUIEnvironment* guienv = midevice->getGUIEnvironment();

	MenuID=Sistema::ContadorElementosGui++;
	menu=guienv->addMenu ( padre, MenuID );

	guiele = menu;
}

/*!
\param texto es el texto de la Opci&oacute;n.
\param nID es el ID de la Opci&oacute;n.
\param bsubmenu true si la opci&oacute;n ser&aacute; un submen&uacute;. False por omisi&oacute;n
\param activado Activado por omisi&oacute;n;

Ejemplo:
\code
Menu.InsertarOpcion("Archivo",0, true);
Menu.InsertarOpcion("Nuevo", 1001);
\endcode
*/
void GDT::Gui::Menu::InsertarOpcion ( wchar_t * texto, int nID, bool bsubmenu, bool activado )
{
	menu->addItem ( texto,nID,activado,bsubmenu );
}

/*!
Ejemplo:
\code
Menu.InsertarSeparador();
\endcode
*/
void GDT::Gui::Menu::InsertarSeparador ( void )
{
	menu->addSeparator();
}

/*!
Ejemplo:
\code
GuiMenu MenuArchivo( Menu.SubMenu(0) );
\endcode
*/
IGUIContextMenu* GDT::Gui::Menu::SubMenu ( int  nID )
{
	return menu->getSubMenu ( nID );
}

void GDT::Gui::Menu::AbrirSubMenu ( int iNivel,bool bPadre_es_Menu=true ) // NUEVO //
{
	if ( bPadre_es_Menu==true )
	{
		submenu = menu->getSubMenu ( iNivel );
	}
	else
	{
		submenu = submenu->getSubMenu ( iNivel );
	}
}

/*!
\bug Provoca un Segmentation Fault
*/
void GDT::Gui::Menu::InsertarSubMenu ( wchar_t * texto, int nID,bool activado, bool bsubmenu ) // NUEVO //
{

	submenu->addItem ( texto,nID,activado,bsubmenu );

}

/*!
*/
void GDT::Gui::Menu::CambiarTextoOpcion ( int nID, const wchar_t* texto, bool bPadre_es_Menu )
{
	if ( bPadre_es_Menu=true )
	{
		menu->setItemText ( nID, texto );
	}
	else
	{
		submenu->setItemText ( nID,texto );
	}

}

/*!
*/
const wchar_t* GDT::Gui::Menu::RetornarTextoOpcion ( int nID )
{
	return menu->getItemText ( nID );
}

/*!
*/
void GDT::Gui::Menu::OpcionActivada ( int nID, bool activado )
{
	menu->setItemEnabled ( nID, activado );
}

/*!
*/
bool GDT::Gui::Menu::OpcionEstaActivada ( int nID )
{
	return menu->isItemEnabled ( nID );
}

/*!
*/
int GDT::Gui::Menu::Seleccionado()
{
	return 0;
}

