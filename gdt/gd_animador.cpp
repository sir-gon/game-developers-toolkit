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

#include "gd_animador.h" // class's header file

/*!
* \class GD_Animador
* \since 2.0
*
*
*
* \author Joropo
* \warning Esta clase es Experimental
*/

// class constructor
GD_Animador::GD_Animador()
{
     anim=0;
	// insert your code here
}

// class destructor
GD_Animador::~GD_Animador()
{
	// insert your code here
}

void GD_Animador::CrearOrbita(float CentroX,float CentroY,float CentroZ, float Radio, float Velocidad, float DireccionX,float DireccionY,float DireccionZ)
{
     anim = GD_Sistema::device->getSceneManager()->createFlyCircleAnimator(core::vector3df(CentroX,CentroY,CentroZ), Radio, Velocidad, core::vector3df(DireccionX,DireccionY,DireccionZ));
}

void GD_Animador::CrearLinea(float IniX,float IniY,float IniZ, float FinX, float FinY, float FinZ, int Tiempo,bool Ciclo)
{       
     	    anim = GD_Sistema::device->getSceneManager()->createFlyStraightAnimator(core::vector3df(IniX,IniY,IniZ), 
			core::vector3df(FinX,FinY,FinZ), Tiempo, Ciclo);
}

void GD_Animador::CrearLinea(vector3df ini, vector3df fin, int Tiempo,bool Ciclo)
{
     	    anim = GD_Sistema::device->getSceneManager()->createFlyStraightAnimator(ini, 
			fin, Tiempo, Ciclo);     
}

void GD_Animador::CrearRotador(float RotacionPorSegundoX,float RotacionPorSegundoY,float RotacionPorSegundoZ)
{
   anim = GD_Sistema::device->getSceneManager()->createRotationAnimator (core::vector3df(RotacionPorSegundoX,RotacionPorSegundoY,RotacionPorSegundoZ));
}

void GD_Animador::CrearRecorreCurva(core::array<core::vector3df>& puntos, float  velocidad , int TiempoDeEmpezar, float  tightness  )
{
     if(TiempoDeEmpezar==-1) 
     {
         TiempoDeEmpezar = GD_Sistema::device->getTimer()->getTime();
     }
     
		anim = GD_Sistema::device->getSceneManager()->createFollowSplineAnimator(TiempoDeEmpezar, puntos,velocidad,tightness);
} 

void GD_Animador::CrearTexturaAnimada(char* RutaArchivoBase, char* Extension, int NumeroCuadros, int TiempoPorCuadro, bool ciclo)
{
	core::array<video::ITexture*> textures;
	for (s32 g=1; g<=NumeroCuadros; ++g)
	{
		char tmp[64];
		sprintf(tmp, "%s_%d.%s",RutaArchivoBase, g ,Extension);
		video::ITexture* t = GD_Sistema::device->getVideoDriver()->getTexture(tmp);
		textures.push_back(t);
	}
	
      anim = GD_Sistema::device->getSceneManager()->createTextureAnimator  (  textures, TiempoPorCuadro, ciclo); 
}

scene::ISceneNodeAnimator* GD_Animador::Retornar(void)
{
    return anim;
}


void GD_Animador::Destruir()
{
		anim->drop();
}
