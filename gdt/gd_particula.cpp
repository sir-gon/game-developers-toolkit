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

#include "gd_particula.h" // class's header file

// class constructor
GDT::Nodo::Particula::Particula()
{
	// insert your code here
}

// class destructor
GDT::Nodo::Particula::~Particula()
{
	// insert your code here
}


void GDT::Nodo::Particula::Crear ( float x, float y, float z, float dx, float dy, float dz, int minparsec, int maxparsec, int tiempodevidamin, int tiempodevidamax, int maxang, char* filename )
{
//7,1,7
//x,y,z -> caja
//0.0,0.06,0.0
//dx,dy,dz -> direccion
//80
//minparsec -> numero minimo de particulas por segundo
//100
//maxparsec ->  numero maximo de particulas por segundo
//800
//tiempodevidamin
//2000
//tiempodevidamax
//0
//maxang

	RegistrarDevice ( Sistema::device );

	ISceneManager* mismgr=Sistema::device->getSceneManager();
	IVideoDriver* driver = Sistema::device->getVideoDriver();


	nodpt = mismgr->addParticleSystemSceneNode ( false );

	if ( !nodpt ) printf ( "ERROR: No se pudo Crear Sistema De Particulas.\n" );
//	nodpt->setPosition(core::vector3df(-70,60,40));
//	nodpt->setScale(core::vector3df(2,2,2));

	nodpt->setParticleSize ( core::dimension2d<f32> ( 20.0f, 20.0f ) );

	scene::IParticleEmitter* em = nodpt->createBoxEmitter (
	                                  core::aabbox3d<f32> ( -x,0,-z,x,y,z ),
	                                  core::vector3df ( dx,dy,dz ),
	                                  minparsec,maxparsec,
	                                  video::SColor ( 0,255,255,255 ), video::SColor ( 0,255,255,255 ),
	                                  tiempodevidamin,tiempodevidamax,maxang );

	nodpt->setEmitter ( em );
	em->drop();

	scene::IParticleAffector* paf =
	    nodpt->createFadeOutParticleAffector();

	nodpt->addAffector ( paf );
	paf->drop();

	nodpt->setMaterialFlag ( video::EMF_LIGHTING, false );
	nodpt->setMaterialTexture ( 0, driver->getTexture ( filename ) );
	nodpt->setMaterialType ( video::EMT_TRANSPARENT_VERTEX_ALPHA );

	nodon = nodpt;

}


void GDT::Nodo::Particula::Escalar ( float x,float y )
{
	nodpt->setParticleSize ( core::dimension2d<f32> ( x, y ) );
}


void GDT::Nodo::Particula::CrearColision ( Escenario scen,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz )
{

	ITriangleSelector* selector = scen.RetornarDatos();

	ISceneManager* mismgr=midevice->getSceneManager();

	scene::ISceneNodeAnimator* anim = mismgr->createCollisionResponseAnimator (
	                                      selector, nodon, core::vector3df ( radiox,radioy,radioz ),
	                                      core::vector3df ( transx,transy,transz ),
	                                      core::vector3df ( grax,gray,graz ) );
	nodon->addAnimator ( anim );
	//anim->drop();
}
