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

#include <irrlicht.h>
#include "gd_nodo.h"
#include "gd_escenario.h"
//#include "gd_malla.h"

// HACK PARA EXPORTAR SIMBOLOS EN DLL COMPILADOS CON VISUAL C++ 2005
#ifndef _GDT_EXPORT_
  #ifdef _GDT_VC_STUDIO_2005_
   #define _GDT_EXPORT_ __declspec(dllexport)
  #else
    #define _GDT_EXPORT_
  #endif
#endif

//! Colisiones en el Espacio
class GD_Colisiones3d : public GD_Nodo//: public GD_Malla
{
   protected:
      ITriangleSelector* selector;
      
   public:
	
	//GD_Nodo *cNodo;
	
	_GDT_EXPORT_ GD_Colisiones3d();
	_GDT_EXPORT_ ~GD_Colisiones3d();
	
	//ISceneCollisionManager* colmgr;
	//_GDT_EXPORT_ ITriangleSelector* RetornarDatosSelector();
	
	vector3df posmiacoli, resultado;
	vector3df vfin;
	bool coli;
	ISceneNode* DummyNodo;

	//void ActivarColisiones(IMesh* static_mesh);
	//! Crea un sistema de colisiones sencillo con un Escenario
	_GDT_EXPORT_ void CrearColision(ITriangleSelector* Mundo);
	//!
	_GDT_EXPORT_ void CrearColision(ITriangleSelector* Mundo,core::vector3df Radio,core::vector3df Gravedad,core::vector3df Traslacion);
	//!
	_GDT_EXPORT_ void CrearColision(ITriangleSelector* selector, float RadioX, float RadioY, float RadioZ, float GravedadX, float GravedadY, float GravedadZ, float TraslacionX, float TraslacionY, float TraslacionZ);
	
	//!
	_GDT_EXPORT_ void ActualizarDatosColision();
	
	//! Crea un sistema de colisiones sencillo con un GD_Escenario
	_GDT_EXPORT_ void CrearColision(GD_Escenario scen);
	//! Crea un sistema de colisiones avanzado con un GD_Escenario, usando vectores.
	_GDT_EXPORT_ void CrearColision(GD_Escenario scen,core::vector3df Radio,core::vector3df Gravedad,core::vector3df Traslacion);
	//! Crea un sistema de colisiones avanzado con un GD_Escenario, usando coordenadas.
	_GDT_EXPORT_ void CrearColision(GD_Escenario scen, float RadioX, float RadioY, float RadioZ, float GravedadX, float GravedadY, float GravedadZ, float TraslacionX, float TraslacionY, float TraslacionZ);
	
	//Obtencion de valores *******************************************************
	//! Obtiene los radios del elipsoide
	_GDT_EXPORT_ core::vector3df RetornarRadioElipsoide();
	//! Obtiene el punto en donde se intersectan un rayo y el GD_Escenario
	_GDT_EXPORT_ vector3df RetornarInterseccionRayo( vector3df ini, vector3df fin, GD_Escenario scen );
	//! Obtiene el punto en donde se intersectan un rayo y el Escenario
	_GDT_EXPORT_ vector3df RetornarInterseccionRayo( vector3df ini, vector3df fin, ITriangleSelector* trian );
	//! Obtiene las traslaciones del elipsoide
	_GDT_EXPORT_ core::vector3df RetornarTraslacionElipsoide();
	//! Obtiene la gravedad en cada eje
	_GDT_EXPORT_ core::vector3df RetornarGravedad();
	//! Obtiene los datos del Escenario
	_GDT_EXPORT_ ITriangleSelector* RetornarDatosMundo();
	//! Obtiene el estado de "caida" del nodo
	_GDT_EXPORT_ bool Callendo();
	
	//! Obtiene la posición donde colisiona el Nodo con el GD_Escenario
	_GDT_EXPORT_ vector3df PosicionColisionConEscenario( GD_Escenario scen );
	//! Comprueba si el Nodo colisiona con el Escenario.
	_GDT_EXPORT_ bool ColisionConEscenario( GD_Escenario scen );

	//! Obtiene la posición donde colisiona el Nodo con el GD_Escenario
	_GDT_EXPORT_ vector3df PosicionColisionConEscenario( ITriangleSelector* trian);
	//! Comprueba si el Nodo colisiona con el Escenario.
	_GDT_EXPORT_ bool ColisionConEscenario( ITriangleSelector* trian );
	
	//! Comprueba si el Nodo colisiona con un rayo
	_GDT_EXPORT_ bool ColisionConRayo( vector3df ini, vector3df fin, ITriangleSelector* trian );
	
	// Asignacion de valores *****************************************************
	//! Establece los radios del elipsoide con un vector.
	_GDT_EXPORT_ void AsignarRadioElipsoide(core::vector3df vector_3d);
	//! Establece los radios del elipsoide con un coordenadas.
	_GDT_EXPORT_ void AsignarRadioElipsoide(float x, float y, float z);
	//! Establece la traslación del elipsoide con un vector
	_GDT_EXPORT_ void AsignarTraslacionElipsoide(core::vector3df vector_3d);
	//! Establece la traslación del elipsoide con un coordenadas
	_GDT_EXPORT_ void AsignarTraslacionElipsoide(float x, float y, float z);   
	//! Establece la gravedad del elipsoide con un vector
	_GDT_EXPORT_ void AsignarGravedad(core::vector3df vector_3d);
	//! Establece la gravedad del elipsoide con un coordenadas
	_GDT_EXPORT_ void AsignarGravedad(float x, float y, float z);
	//! Establece datos de colision con un nuevo Escenario
	_GDT_EXPORT_ void AsignarDatosColision(ITriangleSelector *nuevoMundo);
	//! Establece datos de colision con un nuevo GD_Escenario
	_GDT_EXPORT_ void AsignarDatosColision(GD_Escenario scen);

	//! Obtiene una caja que rodea al Nodo
	_GDT_EXPORT_ aabbox3d<f32> RetornarCaja();
	//! Comprueba si el Nodo colisiona con una caja
	_GDT_EXPORT_ bool ColisionConCaja(aabbox3d<f32> Cajon);

	//! Comprueba si el Nodo colisiona con otro Nodo
	_GDT_EXPORT_ bool Colisiona(GD_Nodo nodocoli);
	
	bool AntiBug;

};
#endif //GD_COLISIONES3D_H
