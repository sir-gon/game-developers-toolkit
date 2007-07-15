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

//! Control GUI "Texto" (Text)
class _GDT_EXPORT_ GD_GuiTexto : public GD_gui
{
private:
	int iX,iY,iAlto,iAncho;

public:
	// class constructor
	GD_GuiTexto();
	// class destructor
	~GD_GuiTexto();

	IGUIStaticText* guitexto;

	wchar_t *szfuente; //variable que alberga el nombre del archivo bmp de la fuente en uso.

	//! Crea un control Gui de tipo texto est&aacute;tico.
	void Crear(int x1, int y1, int x2, int y2, wchar_t * texto, bool borde, bool wordWrap,	IGUIElement *padre=0);
	//! Crea un control Gui de tipo texto est&aacute;tico.
	void Crear(int x1, int y1, int x2, int y2, wchar_t * texto, IGUIElement *padre=0);
	//! Asigna el color del texto.
	void Color(int r, int g, int b,int a = 255);
	//! Asigna la fuente que usar&aacute; el texto.
	void AsignarFuente(const char fontname[1024]); //Carga un nuevo bmp de fuentes
	void AsignarFuente(wchar_t * fontname); /// NUEVO
	//! Obtiene el nombre del archivo de fuentes usado.
	wchar_t* FuenteEnUso();
							//
	void Texto(const wchar_t *text,int x, int y,int ancho, int alto);
	void Texto(const wchar_t *text,int x, int y);
	void TextoCentrado(const wchar_t *text,int x,int y,int ancho, int alto);
	void TextoCentrado(const wchar_t *text,int x,int y);
	int PosicionX();
	int PosicionY();
	void Posicionar(position2d<s32> pos);
	void Posicionar(int x,int y);
	int AnchoDelTexto();
	int AltoDelTexto();
	void Multilinea(bool activar);
	void Visible(bool visible);
	bool EsVisible();
};

#endif // GD_GUITEXTO_H
