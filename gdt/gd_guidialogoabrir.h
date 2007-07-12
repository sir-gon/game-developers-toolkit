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

#ifndef GD_GUIDIALOGOABRIR_H
#define GD_GUIDIALOGOABRIR_H

#include "gd_gui.h" // inheriting class's header file
#include "gd_sistema.h"

// HACK PARA COMPILAR EN VISUAL C++ 2005
#ifndef _GDT_EXPORT_
  #ifdef _GDT_VC_STUDIO_2005_
   #define _GDT_EXPORT_ __declspec(dllexport)
  #else
    #define _GDT_EXPORT_
  #endif
#endif

//! Control GUI "Dialogo de Abrir" para archivos
class GD_GuiDialogoAbrir : public GD_gui
{
public:
	// class constructor
	_GDT_EXPORT_ GD_GuiDialogoAbrir();
	// class destructor
	_GDT_EXPORT_ ~GD_GuiDialogoAbrir();
	
	IGUIFileOpenDialog* opendlg;

	//! Crea un Control GUI del tipo Dialogo Abrir.
	_GDT_EXPORT_ void Crear(wchar_t * titulo, bool modal, IGUIElement* padre=0);
	
};

#endif // GD_GUIDIALOGOABRIR_H
