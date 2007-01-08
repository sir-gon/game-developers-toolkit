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

#include "gd_agua.h" // class's header file

// class constructor
GD_Agua::GD_Agua()
{
	// insert your code here
}

// class destructor
GD_Agua::~GD_Agua()
{
	// insert your code here
}
 

void GD_Agua::CrearNormal(float x, float y, int nx, int ny,int tx,int ty,f32 AlturaOnda,f32 VelocidadOnda, f32 LongitudOnda, char* t)
{

    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=midevice->getSceneManager();

    	mesh = mismgr->addHillPlaneMesh("myHill",
		core::dimension2d<f32>(20,20),
		core::dimension2d<s32>(40,40), 0, 0,
		core::dimension2d<f32>(0,0),
		core::dimension2d<f32>(tx,ty));

	nodon = mismgr->addWaterSurfaceSceneNode(mesh->getMesh(0), AlturaOnda, VelocidadOnda, LongitudOnda);



	nodon->setMaterialTexture(0,	mismgr->getVideoDriver()->getTexture(t));

	nodon->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
     
}

void GD_Agua::CrearRealista(float x, float y, int nx, int ny, int tx,int ty, f32 AlturaOnda,f32 VelocidadOnda, f32 LongitudOnda, char* t1, char* t2)
{

    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=midevice->getSceneManager();

    	mesh = mismgr->addHillPlaneMesh("myHill",
		core::dimension2d<f32>(x,y), //tamano mosaico
		core::dimension2d<s32>(nx,ny), 0, 0,//numero mosaicos
		core::dimension2d<f32>(0,0),
		core::dimension2d<f32>(tx,ty));

	nodon = mismgr->addWaterSurfaceSceneNode(mesh->getMesh(0), AlturaOnda, VelocidadOnda, LongitudOnda);

	nodon->setMaterialTexture(1,	mismgr->getVideoDriver()->getTexture(t1));
	nodon->setMaterialTexture(0,	mismgr->getVideoDriver()->getTexture(t2));

	nodon->setMaterialType(EMT_REFLECTION_2_LAYER);
     
}

