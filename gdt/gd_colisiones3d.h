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

#ifndef GD_COLISIONES3D_H
#define GD_COLISIONES3D_H

#include <Irrlicht/irrlicht.h>
#include "gd_nodo.h"
#include "gd_escenario.h"
//#include "gd_malla.h"

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

//! Colisiones en el Espacio
		class Colisiones3D : public NodoBase//: public GD_Malla
		{
			protected:
				ITriangleSelector* selector;

			public:

				//NodoBase *cNodo;

				_GDT_EXPORT_ Colisiones3D();
				_GDT_EXPORT_ ~Colisiones3D();

				//ISceneCollisionManager* colmgr;
				//_GDT_EXPORT_ ITriangleSelector* RetornarDatosSelector();

				vector3df posmiacoli, resultado;
				vector3df vfin;
				bool coli;
				ISceneNode* DummyNodo;

				//void ActivarColisiones(IMesh* static_mesh);
				//! Crea un sistema de colisiones sencillo con un Escenario
				_GDT_EXPORT_ void CrearColision ( ITriangleSelector* Mundo );
				//!
				_GDT_EXPORT_ void CrearColision ( ITriangleSelector* Mundo,core::vector3df Radio,core::vector3df Gravedad,core::vector3df Traslacion );
				//!
				_GDT_EXPORT_ void CrearColision ( ITriangleSelector* selector, float RadioX, float RadioY, float RadioZ, float GravedadX, float GravedadY, float GravedadZ, float TraslacionX, float TraslacionY, float TraslacionZ );

				//!
				_GDT_EXPORT_ void ActualizarDatosColision();

				//! Crea un sistema de colisiones sencillo con un Escenario
				_GDT_EXPORT_ void CrearColision ( Escenario scen );
				//! Crea un sistema de colisiones avanzado con un Escenario, usando vectores.
				_GDT_EXPORT_ void CrearColision ( Escenario scen,core::vector3df Radio,core::vector3df Gravedad,core::vector3df Traslacion );
				//! Crea un sistema de colisiones avanzado con un Escenario, usando coordenadas.
				_GDT_EXPORT_ void CrearColision ( Escenario scen, float RadioX, float RadioY, float RadioZ, float GravedadX, float GravedadY, float GravedadZ, float TraslacionX, float TraslacionY, float TraslacionZ );

				//Obtencion de valores *******************************************************
				//! Obtiene los radios del elipsoide
				_GDT_EXPORT_ core::vector3df RetornarRadioElipsoide();
				//! Obtiene el punto en donde se intersectan un rayo y el Escenario
				_GDT_EXPORT_ vector3df RetornarInterseccionRayo ( vector3df ini, vector3df fin, Escenario scen );
				//! Obtiene el punto en donde se intersectan un rayo y el Escenario
				_GDT_EXPORT_ vector3df RetornarInterseccionRayo ( vector3df ini, vector3df fin, ITriangleSelector* trian );
				//! Obtiene las traslaciones del elipsoide
				_GDT_EXPORT_ core::vector3df RetornarTraslacionElipsoide();
				//! Obtiene la gravedad en cada eje
				_GDT_EXPORT_ core::vector3df RetornarGravedad();
				//! Obtiene los datos del Escenario
				_GDT_EXPORT_ ITriangleSelector* RetornarDatosMundo();
				//! Obtiene el estado de "caida" del nodo
				_GDT_EXPORT_ bool Callendo();

				//! Obtiene la posici&oacute;n donde colisiona el Nodo con el Escenario
				_GDT_EXPORT_ vector3df PosicionColisionConEscenario ( Escenario scen );
				//! Comprueba si el Nodo colisiona con el Escenario.
				_GDT_EXPORT_ bool ColisionConEscenario ( Escenario scen );

				//! Obtiene la posici&oacute;n donde colisiona el Nodo con el Escenario
				_GDT_EXPORT_ vector3df PosicionColisionConEscenario ( ITriangleSelector* trian );
				//! Comprueba si el Nodo colisiona con el Escenario.
				_GDT_EXPORT_ bool ColisionConEscenario ( ITriangleSelector* trian );

				//! Comprueba si el Nodo colisiona con un rayo
				_GDT_EXPORT_ bool ColisionConRayo ( vector3df ini, vector3df fin, ITriangleSelector* trian );

				// Asignacion de valores *****************************************************
				//! Establece los radios del elipsoide con un vector.
				_GDT_EXPORT_ void AsignarRadioElipsoide ( core::vector3df vector_3d );
				//! Establece los radios del elipsoide con un coordenadas.
				_GDT_EXPORT_ void AsignarRadioElipsoide ( float x, float y, float z );
				//! Establece la traslaci&oacute;n del elipsoide con un vector
				_GDT_EXPORT_ void AsignarTraslacionElipsoide ( core::vector3df vector_3d );
				//! Establece la traslaci&oacute;n del elipsoide con un coordenadas
				_GDT_EXPORT_ void AsignarTraslacionElipsoide ( float x, float y, float z );
				//! Establece la gravedad del elipsoide con un vector
				_GDT_EXPORT_ void AsignarGravedad ( core::vector3df vector_3d );
				//! Establece la gravedad del elipsoide con un coordenadas
				_GDT_EXPORT_ void AsignarGravedad ( float x, float y, float z );
				//! Establece datos de colision con un nuevo Escenario
				_GDT_EXPORT_ void AsignarDatosColision ( ITriangleSelector *nuevoMundo );
				//! Establece datos de colision con un nuevo Escenario
				_GDT_EXPORT_ void AsignarDatosColision ( Escenario scen );

				//! Obtiene una caja que rodea al Nodo
				_GDT_EXPORT_ aabbox3d<f32> RetornarCaja();
				//! Comprueba si el Nodo colisiona con una caja
				_GDT_EXPORT_ bool ColisionConCaja ( aabbox3d<f32> Cajon );

				//! Comprueba si el Nodo colisiona con otro Nodo
				_GDT_EXPORT_ bool Colisiona ( NodoBase nodocoli );

				bool AntiBug;

		};

	} // FIN NAMESPACE NODO

} // FIN NAMESPACE GDT

#endif //GD_COLISIONES3D_H
