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
	#ifdef _GDT_DLL_
	   #define _GDT_EXPORT_ __declspec(dllexport)
	#else /* Not _GDT_DLL_ */
	   #define _GDT_EXPORT_ __declspec(dllimport)
	#endif /* Not _GDT_DLL_ */
  #else
// SINO, DEFINIR COMO NULO EL EXPORTADOR 
    #define _GDT_EXPORT_ /* Definido nulo */
  #endif  /* WIN32 */
#endif /* _GDT_EXPORT_ */

namespace GDT
{

namespace Gui
{

//! Control GUI "Menu" y "SubMenu"
class Menu : public GD_gui
{
public:
	// class constructor
	_GDT_EXPORT_ Menu();
	_GDT_EXPORT_ Menu(IGUIContextMenu* SubMenu);
	// class destructor
	_GDT_EXPORT_ ~Menu();

	int MenuID;

	IGUIContextMenu* menu;
	IGUIContextMenu* submenu; // NUEVO

	//! Crea un Control Gui del tipo Men&uacute;. En &eacute;l se pueden insertar Opciones y SubMenus.
	_GDT_EXPORT_ void Crear(IGUIElement* padre=0);
	//! Inserta una Opci&oacute;n para elegir dentro de un men&uacute;.
	void InsertarOpcion(wchar_t * texto, int nID=-1, bool bsubmenu = false, bool activado=true); // MODIFICADO //
	//!
	_GDT_EXPORT_ IGUIContextMenu* SubMenu(int  nID);
	//! 
	_GDT_EXPORT_ void AbrirSubMenu(int iNivel,bool bPadre_es_Menu); // NUEVO //
	//! Inserta un submen&uacute;.
	_GDT_EXPORT_ void InsertarSubMenu(wchar_t * texto, int nID,bool activado=true, bool bsubmenu = false);// NUEVO //
	//! Inserta un separador en el men&uacute;.
	_GDT_EXPORT_ void InsertarSeparador(void);
	//! Cambia el texto de una Opci&oacute;n.
	_GDT_EXPORT_ void CambiarTextoOpcion(int nID, const wchar_t* texto, bool bPadre_es_Menu=true);
	//! Obtiene el texto de una Opci&oacute;n;.
	_GDT_EXPORT_ const wchar_t* RetornarTextoOpcion(int nID);
	//! Establece una Opci&oacute;n como activada o desactivada.
	_GDT_EXPORT_ void OpcionActivada(int nID, bool activado);
	//! Comprueba si una Opci&oacute;n est&aacute activada.
	_GDT_EXPORT_ bool OpcionEstaActivada(int nID);
	//!
	_GDT_EXPORT_ int Seleccionado();

};

} // FIN NAMESPACE SONIDO

} // FIN NAMESPACE GDT

#endif // GD_GUIMENU_H
