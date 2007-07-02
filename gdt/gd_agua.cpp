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

/*!
 * \class GD_Agua
 *
 * Permite simular la superficie de un l&iacute;quido.
 * La t&eacute;cnica es poner el nodo GD_Agua en un lugar del escenario donde
 * se vea como si fuera la superficie de un lago, pozo, estanque, o lo 
 * que se ocurra.
 * Autom&aacute;ticamente el plano ondular&aacute; como si se tratase de un l&iacute;quido real.
 */

#include "gd_agua.h" // class's header file

// class constructor
GD_Agua::GD_Agua()
{
}

// class destructor
GD_Agua::~GD_Agua()
{
}
 
/*!
\param x,y ancho de cada cuadro del mosaico.
\param nx,ny cuadros en que componen el mosaico.
\param tx, ty mapeo de textura, es decir las veces que se repite la textura.
\param AlturaOnda altura de la onda.
\param VelocidadOnda velocidad de la onda.
\param LongitudOnda la longitud de la onda.
\param t es la ruta de la textura. La textura se aplica y queda la superficie transparente.

\image html aguanormal.png

Ejemplo:
\code
Mar.CrearNormal(100, 100, 100, 100, 100, 100, 4, 300, 30, "media/water.jpg");
\endcode
*/
void GD_Agua::CrearNormal(float x, float y, int nx, int ny,int tx,int ty,f32 AlturaOnda,f32 VelocidadOnda, f32 LongitudOnda, char* t)
{
    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=midevice->getSceneManager();

    // Se crea el plano
    mesh = mismgr->addHillPlaneMesh("myHill",
	core::dimension2d<f32>(x,y),
	core::dimension2d<s32>(nx,ny), 0, 0,
	core::dimension2d<f32>(0,0),
	core::dimension2d<f32>(tx,ty));

    // Se crea el nodo y se le agrega el plano
	nodon = mismgr->addWaterSurfaceSceneNode(mesh->getMesh(0), AlturaOnda, VelocidadOnda, LongitudOnda);

    if(!nodon) printf("ERROR: No se pudo crear Agua Normal\n");

    // Se carga la textura
	nodon->setMaterialTexture(0, mismgr->getVideoDriver()->getTexture(t));
	
	// Se establece el material transparente
	nodon->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
}

/*! La textura1 se vuelve reflexi&oacute;n esf&eacute;rica transparente y la textura2 es la base es decir el piso.
\param x,y ancho de cada cuadro del mosaico.
\param nx,ny cuadros en que componen el mosaico.
\param tx, ty mapeo de textura, es decir las veces que se repite la textura.
\param AlturaOnda altura de la onda.
\param VelocidadOnda velocidad de la onda.
\param LongitudOnda la longitud de la onda.
\param t1 es la ruta de la textura de la superficie.
\param t2 es la ruta de la textura del piso.

\image html aguarealista.png

Ejemplo:
\code
Mar.CrearRealista(100, 100, 100, 100, 100, 100, 4, 300, 30, "media/water.jpg", "media/piso.jpg");
\endcode
*/
void GD_Agua::CrearRealista(float x, float y, int nx, int ny, int tx,int ty, f32 AlturaOnda,f32 VelocidadOnda, f32 LongitudOnda, char* t1, char* t2)
{

    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=midevice->getSceneManager();

    // Se crea el plano
    mesh = mismgr->addHillPlaneMesh("myHill",
	core::dimension2d<f32>(x,y), //tamano mosaico
	core::dimension2d<s32>(nx,ny), 0, 0,//numero mosaicos
	core::dimension2d<f32>(0,0),
	core::dimension2d<f32>(tx,ty));

    // Se crea el nodo y se le agrega el plano
	nodon = mismgr->addWaterSurfaceSceneNode(mesh->getMesh(0), AlturaOnda, VelocidadOnda, LongitudOnda);

    if(!nodon) printf("ERROR: No se pudo crear Agua Realista\n");

    // Se carga las texturas
	nodon->setMaterialTexture(1,	mismgr->getVideoDriver()->getTexture(t1));
	nodon->setMaterialTexture(0,	mismgr->getVideoDriver()->getTexture(t2));

	// Se establece el material de refleccion de la segunda capa
	nodon->setMaterialType(EMT_REFLECTION_2_LAYER);
     
}

