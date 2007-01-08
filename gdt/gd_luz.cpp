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

 
#include "gd_luz.h" // class's header file

// class constructor
GD_Luz::GD_Luz()
{
	// insert your code here
}

// class destructor
GD_Luz::~GD_Luz()
{
	// insert your code here
}

//! Crea una luz 
/**
x,y,z => posicion
r,g,b => color
radio
*/
void GD_Luz::Crear(float x, float y, float z, float radio)
{

    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=GD_Sistema::device->getSceneManager();


	nodl = mismgr->addLightSceneNode(0, 
     core::vector3df(x,y,z),
	video::SColorf( 200, 200, 200), 
     radio);
     
     nodon = nodl;
     
     sluz = nodl->getLightData();
     
     HacerSombra(false);
     Tipo(1);
	
}

void GD_Luz::Crear(float x, float y, float z, float radio, int tipo)
{

    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=GD_Sistema::device->getSceneManager();


	nodl = mismgr->addLightSceneNode(0, 
     core::vector3df(x,y,z),
	video::SColorf( 200, 200, 200), 
     radio);
     
     nodon = nodl;
     
     sluz = nodl->getLightData();
     
     HacerSombra(false);
     Tipo(tipo);
	
}

void GD_Luz::Crear()
{

    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=GD_Sistema::device->getSceneManager();


	nodl = mismgr->addLightSceneNode(0, 
     core::vector3df(200,200,200),
	video::SColorf( 200, 200, 200), 
     300);
     
     nodon = nodl;
     
     sluz = nodl->getLightData();
     
     HacerSombra(false);
     Tipo(1);
	
}



void GD_Luz::Crear(float x, float y, float z, float r, float g ,float b, float radio)
{

    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=GD_Sistema::device->getSceneManager();


	nodl = mismgr->addLightSceneNode(0, 
     core::vector3df(x,y,z),
	video::SColorf( r, g, b), 
     radio);
     
     nodon = nodl;
     
     sluz = nodl->getLightData();
     
     HacerSombra(false);
     Tipo(1);
	
}


void GD_Luz::Crear(float x, float y, float z, float r, float g ,float b, float radio, int tipo)
{

    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=GD_Sistema::device->getSceneManager();


	nodl = mismgr->addLightSceneNode(0, 
     core::vector3df(x,y,z),
	video::SColorf( r, g, b), 
     radio);
     
     nodon = nodl;
     
     sluz = nodl->getLightData();
     
     HacerSombra(false);
     Tipo(tipo);
	
}



void GD_Luz::HacerSombra(bool hacer)
{
     sluz.CastShadows = hacer;
}


void GD_Luz::Direccion(float x, float y, float z)
{
      sluz.Position.set(x,y,z);
}

void GD_Luz::Direccion( vector3df vect)
{
      sluz.Position = vect;
}

void GD_Luz::Tipo(int tipo)
{
     if(tipo==1) sluz.Type = ELT_POINT;
     if(tipo==2) sluz.Type = ELT_DIRECTIONAL;     
}

void GD_Luz::Radio( float rad )
{
     sluz.Radius = rad;
}

void GD_Luz::ColorAmbiente(s32 r,s32 g,s32 b)
{
     sluz.AmbientColor.set(r,g,b);
}

// CAMBIADO POR SIR_GON
//void GD_Luz::ColorDifuso( int r,int g,int  b)
void GD_Luz::ColorDifuso(s32 r,s32 g,s32  b)
{
     sluz.DiffuseColor.set(r,g,b);     
     printf("cambiando valor de la luz R a %d\n",r);
}

void GD_Luz::ColorEspecular(s32 r,s32 g,s32 b)
{
     sluz.SpecularColor.set(r,g,b);     

}


void GD_Luz::AumentarColorAmbiente(float val)
{
     float rr = sluz.AmbientColor.r;
     float gg = sluz.AmbientColor.g;
     float bb = sluz.AmbientColor.b;     
     
     rr+=val;
     gg+=val;
     bb+=val;          
     
     sluz.AmbientColor.set(rr,gg,bb);
}

void GD_Luz::AumentarColorDifuso(float val)
{
     float rr = sluz.DiffuseColor.r;
     float gg = sluz.DiffuseColor.g;
     float bb = sluz.DiffuseColor.b;     
     
     rr+=val;
     gg+=val;
     bb+=val;          
     
     sluz.DiffuseColor.set(rr,gg,bb);
}

void GD_Luz::AumentarColorEspecular(float val)
{
     float rr = sluz.SpecularColor.r;
     float gg = sluz.SpecularColor.g;
     float bb = sluz.SpecularColor.b;     
     
     rr+=val;
     gg+=val;
     bb+=val;          
     
     sluz.SpecularColor.set(rr,gg,bb);
}

void GD_Luz::CrearColision( GD_Escenario scen,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz)
{

    ITriangleSelector* selector = scen.RetornarDatos();

    ISceneManager* mismgr=midevice->getSceneManager();

	scene::ISceneNodeAnimator* anim = mismgr->createCollisionResponseAnimator(
		selector, nodon, core::vector3df(radiox,radioy,radioz),
		core::vector3df(transx,transy,transz),
		core::vector3df(grax,gray,graz));
	nodon->addAnimator(anim);
	//anim->drop();
}


void GD_Luz::Crear(int r, int g ,int b, float radio)
{
     Crear(100,100,100,r,g,b,3);
}

void GD_Luz::Crear(int r, int g ,int b, float radio, int tipom)
{
      Crear(100,100,100,r,g,b,3);
      Tipo(tipom);
}
