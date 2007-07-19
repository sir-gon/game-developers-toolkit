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

#ifndef GD_GUITEXTO_H
#define GD_GUITEXTO_H

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

//! Control GUI "Texto" (Text)
class GD_GuiTexto : public GD_gui
{
private:
	int iX,iY,iAlto,iAncho;

public:
	// class constructor
	_GDT_EXPORT_ GD_GuiTexto();
	// class destructor
	_GDT_EXPORT_ ~GD_GuiTexto();

	IGUIStaticText* guitexto;

	wchar_t *szfuente; //variable que alberga el nombre del archivo bmp de la fuente en uso.

	//! Crea un control Gui de tipo texto est&aacute;tico.
	_GDT_EXPORT_ void Crear(int x1, int y1, int x2, int y2, wchar_t * texto, bool borde, bool wordWrap,	IGUIElement *padre=0);
	//! Crea un control Gui de tipo texto est&aacute;tico.
	_GDT_EXPORT_ void Crear(int x1, int y1, int x2, int y2, wchar_t * texto, IGUIElement *padre=0);
	//! Asigna el color del texto.
	_GDT_EXPORT_ void Color(int r, int g, int b,int a = 255);
	//! Asigna la fuente que usar&aacute; el texto.
	_GDT_EXPORT_ void AsignarFuente(const char fontname[1024]); //Carga un nuevo bmp de fuentes
	_GDT_EXPORT_ void AsignarFuente(wchar_t * fontname); /// NUEVO
	//! Obtiene el nombre del archivo de fuentes usado.
	_GDT_EXPORT_ wchar_t* FuenteEnUso();
							//
	_GDT_EXPORT_ void Texto(const wchar_t *text,int x, int y,int ancho, int alto);
	_GDT_EXPORT_ void Texto(const wchar_t *text,int x, int y);
	_GDT_EXPORT_ void TextoCentrado(const wchar_t *text,int x,int y,int ancho, int alto);
	_GDT_EXPORT_ void TextoCentrado(const wchar_t *text,int x,int y);
	_GDT_EXPORT_ int PosicionX();
	_GDT_EXPORT_ int PosicionY();
	_GDT_EXPORT_ void Posicionar(position2d<s32> pos);
	_GDT_EXPORT_ void Posicionar(int x,int y);
	_GDT_EXPORT_ int AnchoDelTexto();
	_GDT_EXPORT_ int AltoDelTexto();
	_GDT_EXPORT_ void Multilinea(bool activar);
	_GDT_EXPORT_ void Visible(bool visible);
	_GDT_EXPORT_ bool EsVisible();
};

#endif // GD_GUITEXTO_H
