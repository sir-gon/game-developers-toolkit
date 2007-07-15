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

//! Colisiones en el Espacio
class _GDT_EXPORT_ GD_Colisiones3d : public GD_Nodo//: public GD_Malla
{
   protected:
      ITriangleSelector* selector;
      
   public:
	
	//GD_Nodo *cNodo;
	
	GD_Colisiones3d();
	~GD_Colisiones3d();
	
	//ISceneCollisionManager* colmgr;
	//ITriangleSelector* RetornarDatosSelector();
	
	vector3df posmiacoli, resultado;
	vector3df vfin;
	bool coli;
	ISceneNode* DummyNodo;

	//void ActivarColisiones(IMesh* static_mesh);
	//! Crea un sistema de colisiones sencillo con un Escenario
	void CrearColision(ITriangleSelector* Mundo);
	//!
	void CrearColision(ITriangleSelector* Mundo,core::vector3df Radio,core::vector3df Gravedad,core::vector3df Traslacion);
	//!
	void CrearColision(ITriangleSelector* selector, float RadioX, float RadioY, float RadioZ, float GravedadX, float GravedadY, float GravedadZ, float TraslacionX, float TraslacionY, float TraslacionZ);
	
	//!
	void ActualizarDatosColision();
	
	//! Crea un sistema de colisiones sencillo con un GD_Escenario
	void CrearColision(GD_Escenario scen);
	//! Crea un sistema de colisiones avanzado con un GD_Escenario, usando vectores.
	void CrearColision(GD_Escenario scen,core::vector3df Radio,core::vector3df Gravedad,core::vector3df Traslacion);
	//! Crea un sistema de colisiones avanzado con un GD_Escenario, usando coordenadas.
	void CrearColision(GD_Escenario scen, float RadioX, float RadioY, float RadioZ, float GravedadX, float GravedadY, float GravedadZ, float TraslacionX, float TraslacionY, float TraslacionZ);
	
	//Obtencion de valores *******************************************************
	//! Obtiene los radios del elipsoide
	core::vector3df RetornarRadioElipsoide();
	//! Obtiene el punto en donde se intersectan un rayo y el GD_Escenario
	vector3df RetornarInterseccionRayo( vector3df ini, vector3df fin, GD_Escenario scen );
	//! Obtiene el punto en donde se intersectan un rayo y el Escenario
	vector3df RetornarInterseccionRayo( vector3df ini, vector3df fin, ITriangleSelector* trian );
	//! Obtiene las traslaciones del elipsoide
	core::vector3df RetornarTraslacionElipsoide();
	//! Obtiene la gravedad en cada eje
	core::vector3df RetornarGravedad();
	//! Obtiene los datos del Escenario
	ITriangleSelector* RetornarDatosMundo();
	//! Obtiene el estado de "caida" del nodo
	bool Callendo();
	
	//! Obtiene la posición donde colisiona el Nodo con el GD_Escenario
	vector3df PosicionColisionConEscenario( GD_Escenario scen );
	//! Comprueba si el Nodo colisiona con el Escenario.
	bool ColisionConEscenario( GD_Escenario scen );

	//! Obtiene la posición donde colisiona el Nodo con el GD_Escenario
	vector3df PosicionColisionConEscenario( ITriangleSelector* trian);
	//! Comprueba si el Nodo colisiona con el Escenario.
	bool ColisionConEscenario( ITriangleSelector* trian );
	
	//! Comprueba si el Nodo colisiona con un rayo
	bool ColisionConRayo( vector3df ini, vector3df fin, ITriangleSelector* trian );
	
	// Asignacion de valores *****************************************************
	//! Establece los radios del elipsoide con un vector.
	void AsignarRadioElipsoide(core::vector3df vector_3d);
	//! Establece los radios del elipsoide con un coordenadas.
	void AsignarRadioElipsoide(float x, float y, float z);
	//! Establece la traslación del elipsoide con un vector
	void AsignarTraslacionElipsoide(core::vector3df vector_3d);
	//! Establece la traslación del elipsoide con un coordenadas
	void AsignarTraslacionElipsoide(float x, float y, float z);   
	//! Establece la gravedad del elipsoide con un vector
	void AsignarGravedad(core::vector3df vector_3d);
	//! Establece la gravedad del elipsoide con un coordenadas
	void AsignarGravedad(float x, float y, float z);
	//! Establece datos de colision con un nuevo Escenario
	void AsignarDatosColision(ITriangleSelector *nuevoMundo);
	//! Establece datos de colision con un nuevo GD_Escenario
	void AsignarDatosColision(GD_Escenario scen);

	//! Obtiene una caja que rodea al Nodo
	aabbox3d<f32> RetornarCaja();
	//! Comprueba si el Nodo colisiona con una caja
	bool ColisionConCaja(aabbox3d<f32> Cajon);

	//! Comprueba si el Nodo colisiona con otro Nodo
	bool Colisiona(GD_Nodo nodocoli);
	
	bool AntiBug;

};
#endif //GD_COLISIONES3D_H
