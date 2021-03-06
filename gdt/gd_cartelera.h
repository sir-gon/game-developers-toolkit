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

#ifndef GD_CARTELERA_H
#define GD_CARTELERA_H

#include "gd_nodo.h" // inheriting class's header file
#include "gd_escenario.h"

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

//! Imagenes que siempre se ven frontalmente en la c&aacute;mara
		class Cartelera : public NodoBase
		{
			public:
				// class constructor
				_GDT_EXPORT_ Cartelera();
				// class destructor
				_GDT_EXPORT_ ~Cartelera();

				IBillboardSceneNode* nodb;

				//! Carga una imï¿½en como una Cartelera.
				_GDT_EXPORT_ void Crear (
				    float tamx,
				    float tamy,
				    char* filename
				);

				_GDT_EXPORT_ void CrearColision (
				    Escenario scen,
				    float radiox, float radioy, float radioz,
				    float transx, float transy, float transz,
				    float grax, float gray, float graz
				);
		};

	} // FIN NAMESPACE NODO

} // FIN NAMESPACE GDT

#endif // GD_CARTELERA_H
