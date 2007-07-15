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

#ifndef GD_GUIMENU_H
#define GD_GUIMENU_H

#include "gd_gui.h" // inheriting class's header file
#include "gd_sistema.h"

//EXPORTAR SIMBOLOS AL CREAR DLL
#ifndef _GDT_EXPORT_
  #ifdef WIN32
	#ifdef BUILDING_DLL
	   #define _GDT_EXPORT_ __declspec (dllexport)
	#else /* Not BUILDING_DLL */
	   #define _GDT_EXPORT_ __declspec (dllimport)
	#endif /* Not BUILDING_DLL */
  #else
// SINO, DEFINIR COMO NULO EL EXPORTADOR 
    #define _GDT_EXPORT_ /* Definido nulo */
  #endif  /* WIN32 */
#endif /* _GDT_EXPORT_ */

//! Control GUI "Menu" y "SubMenu"
class _GDT_EXPORT_ GD_GuiMenu : public GD_gui
{
public:
	// class constructor
	GD_GuiMenu();
	GD_GuiMenu(IGUIContextMenu* SubMenu);
	// class destructor
	~GD_GuiMenu();

	int MenuID;

	IGUIContextMenu* menu;
	IGUIContextMenu* submenu; // NUEVO

	//! Crea un Control Gui del tipo Men&uacute;. En &eacute;l se pueden insertar Opciones y SubMenus.
	void Crear(IGUIElement* padre=0);
	//! Inserta una Opci&oacute;n para elegir dentro de un men&uacute;.
	void InsertarOpcion(wchar_t * texto, int nID=-1, bool bsubmenu = false, bool activado=true); // MODIFICADO //
	//!
	IGUIContextMenu* SubMenu(int  nID);
	//! 
	void AbrirSubMenu(int iNivel,bool bPadre_es_Menu); // NUEVO //
	//! Inserta un submen&uacute;.
	void InsertarSubMenu(wchar_t * texto, int nID,bool activado=true, bool bsubmenu = false);// NUEVO //
	//! Inserta un separador en el men&uacute;.
	void InsertarSeparador(void);
	//! Cambia el texto de una Opci&oacute;n.
	void CambiarTextoOpcion(int nID, const wchar_t* texto, bool bPadre_es_Menu=true);
	//! Obtiene el texto de una Opci&oacute;n;.
	const wchar_t* RetornarTextoOpcion(int nID);
	//! Establece una Opci&oacute;n como activada o desactivada.
	void OpcionActivada(int nID, bool activado);
	//! Comprueba si una Opci&oacute;n est&aacute activada.
	bool OpcionEstaActivada(int nID);
	//!
	int Seleccionado();

};

#endif // GD_GUIMENU_H
