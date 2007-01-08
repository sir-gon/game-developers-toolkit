/*
* GDT (GAME DEVELOPERS TOOLKIT)
* Copyright (C) 2006 GDT STAFF
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#ifndef GD_GUITEXTO_H
#define GD_GUITEXTO_H

#include "gd_gui.h" // inheriting class's header file

#include "gd_sistema.h"

/**
 * GUI Texto
 */
class GD_GuiTexto : public GD_gui
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

          void Crear(int x1, int y1, int x2, int y2, wchar_t * texto,bool borde, bool wordWrap,	IGUIElement *padre=0);
          void Crear(int x1, int y1, int x2, int y2, wchar_t * texto, IGUIElement *padre=0);
          void Color(int r, int g, int b,int a);
         //A�dido por Astucia 13-04-2006
          void AsignarFuente(const char fontname[1024]); //Carga un nuevo bmp de fuentes
          wchar_t* FuenteEnUso();   //Regresa el nombre del archivo de fuentes usado.
                                    //Tambien se puede obtener el nombre mediante la variable wchar_t* szfuente
          void Texto(const wchar_t *text,int x, int y,int ancho, int alto);
          void Texto(const wchar_t *text,int x, int y);
          void TextoCentrado(const wchar_t *text,int x,int y,int ancho, int alto);
          void TextoCentrado(const wchar_t *text,int x,int y);
          int PosicionX();
          int PosicionY();
          void Posicionar(position2d<s32> PosicionXY);
          void Posicionar(int X,int Y);
          int AnchoDelTexto();
          int AltoDelTexto();
          void Multilinea(bool activar);
          void Visible(bool visible);
          bool EsVisible();
};

#endif // GD_GUITEXTO_H
