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

#ifndef GD_GUIBOTON_H
#define GD_GUIBOTON_H

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

//! Control GUI "Boton" (Button)
class Boton : public GuiBase
{
public:
	// class constructor
	_GDT_EXPORT_ Boton();
	// class destructor
	_GDT_EXPORT_ ~Boton();

	IGUIButton* boton;

	//! Crea un control Gui del tipo Bot&oacute;n.
	_GDT_EXPORT_ void Crear(int x1, int y1, int x2, int y2, IGUIElement* padre=0);
	//! Crea un control Gui del tipo Bot&oacute;n.
	_GDT_EXPORT_ void Crear(int x1, int y1, int x2, int y2, wchar_t * texto, IGUIElement* padre=0);
	//! Crea un control Gui del tipo Bot&oacute;n, con una imagen.
	_GDT_EXPORT_ void CrearConImagen(int x1, int y1, int x2, int y2, char* filename_boton_normal ,char* filename_boton_presionado, IGUIElement* padre=0);
};

} // FIN NAMESPACE GUI

} // FIN NAMESPACE GDT

#endif // GD_GUIBOTON_H
