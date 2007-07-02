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

#ifndef GD_AGUA_H
#define GD_AGUA_H

#include "gd_nodo.h" // inheriting class's header file

//! Efectos de Agua
class GD_Agua : public GD_Nodo
{
	public:
		// class constructor
		GD_Agua();
		// class destructor
		~GD_Agua();

     //! Malla que contiene el plano
     scene::IAnimatedMesh* mesh; 

    //! Crea una superficie de agua con su movimiento que se actualiza autom&aacute;ticamente.
    void CrearNormal(float x, float y, int nx, int ny,int tx,int ty,f32 AlturaOnda,f32 VelocidadOnda, f32 LongitudOnda, char* t);
    //! Es igual que CrearNormal pero realista, los par&aacute;metros son los mismos excepto t2 que es la textura del piso.
    void CrearRealista(float x, float y, int nx, int ny,int tx,int ty,f32 AlturaOnda,f32 VelocidadOnda, f32 LongitudOnda, char* t1, char* t2);
};

#endif // GD_AGUA_H
