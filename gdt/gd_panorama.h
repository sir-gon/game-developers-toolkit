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

#ifndef GD_PANORAMA_H
#define GD_PANORAMA_H

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

//! Cubre el fondo con una o varias im&aacute;genes panor&aacute;micas.
		class Panorama : public NodoBase
		{
			public:
				// class constructor
				_GDT_EXPORT_ Panorama();
				// class destructor
				_GDT_EXPORT_ ~Panorama();

				//! Cubre el fondo con un panor&aacute;ma c&uacute;bico
				_GDT_EXPORT_ void CrearCubico ( char* up, char* down, char* left, char* right, char* front,char* back );
				//! Cubre el fondo con un panor&aacute;ma esf&eacute;rico
				_GDT_EXPORT_ void CrearDomo ( char* texturadomo, int hres, int vres, int texporc, int esfporc );
		};

	} // FIN NAMESPACE NODO

} // FIN NAMESPACE GDT

#endif // GD_PANORAMA_H
