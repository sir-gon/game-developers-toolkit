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

namespace Nodo
{

//! Efectos de Agua
class Agua : public NodoBase
{
	public:
		// class constructor
		_GDT_EXPORT_ Agua();
		// class destructor
		_GDT_EXPORT_ ~Agua();

     //! Malla que contiene el plano
     scene::IAnimatedMesh* mesh; 

    //! Crea una superficie de agua con su movimiento que se actualiza autom&aacute;ticamente.
    _GDT_EXPORT_ void CrearNormal(
	float x, float y,
	int nx, int ny,
	int tx,int ty,
	f32 AlturaOnda,
	f32 VelocidadOnda,
	f32 LongitudOnda,
	char* textura
	);
    //! Es igual que CrearNormal pero realista, los par&aacute;metros son los mismos excepto t2 que es la textura del piso.
    _GDT_EXPORT_ void CrearRealista(
	float x, float y,
	int nx, int ny,
	int tx, int ty,
	f32 AlturaOnda,
	f32 VelocidadOnda,
	f32 LongitudOnda,
	char* texturaAgua, char* texturaPiso);
};

} // FIN NAMESPACE NODO

} // FIN NAMESPACE GDT

#endif // GD_AGUA_H
