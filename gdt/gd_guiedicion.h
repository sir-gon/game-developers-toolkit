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

#ifndef GD_GUIEDICION_H
#define GD_GUIEDICION_H

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

//! Control GUI "Cuadro de Edición" (EditBox)
class Edicion : public GD_gui
{
public:
	// class constructor
	_GDT_EXPORT_ Edicion();
	// class destructor
	_GDT_EXPORT_ ~Edicion();
	
	IGUIEditBox* editbox;

	//! Crea un Control Gui del tipo Edici&oacute;n de texto.
	_GDT_EXPORT_ void Crear(int x1, int y1, int x2, int y2, wchar_t * texto, bool borde, IGUIElement* padre=0);
	//! Especifica el m&aacute;ximo de caracteres que se pueden escribir.
	_GDT_EXPORT_ void CaracteresMaximo(int max);
	//! Retorna el m&aacute;ximo de caracteres que se pueden escribir.
	_GDT_EXPORT_ int RetornarCaracteresMaximo(void);
};

} // FIN NAMESPACE SONIDO

} // FIN NAMESPACE GDT

#endif // GD_GUIEDICION_H
