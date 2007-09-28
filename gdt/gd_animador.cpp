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
* \class GDT::Animador
* \since 2.0
*
*
*
* \author Joropo
* \warning Esta clase es Experimental
*/

// class constructor
GDT::Animador::Animador()
{
	anim=0;
	// insert your code here
}

// class destructor
GDT::Animador::~Animador()
{
	// insert your code here
}

void GDT::Animador::CrearOrbita ( float CentroX,float CentroY,float CentroZ, float Radio, float Velocidad, float DireccionX,float DireccionY,float DireccionZ )
{
	anim = Sistema::device->getSceneManager()->createFlyCircleAnimator ( core::vector3df ( CentroX,CentroY,CentroZ ), Radio, Velocidad, core::vector3df ( DireccionX,DireccionY,DireccionZ ) );
}

void GDT::Animador::CrearLinea ( float IniX,float IniY,float IniZ, float FinX, float FinY, float FinZ, int Tiempo,bool Ciclo )
{
	anim = Sistema::device->getSceneManager()->createFlyStraightAnimator ( core::vector3df ( IniX,IniY,IniZ ),
	        core::vector3df ( FinX,FinY,FinZ ), Tiempo, Ciclo );
}

void GDT::Animador::CrearLinea ( vector3df ini, vector3df fin, int Tiempo,bool Ciclo )
{
	anim = Sistema::device->getSceneManager()->createFlyStraightAnimator ( ini,
	        fin, Tiempo, Ciclo );
}

void GDT::Animador::CrearRotador ( float RotacionPorSegundoX,float RotacionPorSegundoY,float RotacionPorSegundoZ )
{
	anim = Sistema::device->getSceneManager()->createRotationAnimator ( core::vector3df ( RotacionPorSegundoX,RotacionPorSegundoY,RotacionPorSegundoZ ) );
}

void GDT::Animador::CrearRecorreCurva ( core::array<core::vector3df>& puntos, float  velocidad , int TiempoDeEmpezar, float  tightness )
{
	if ( TiempoDeEmpezar==-1 )
	{
		TiempoDeEmpezar = Sistema::device->getTimer()->getTime();
	}

	anim = Sistema::device->getSceneManager()->createFollowSplineAnimator ( TiempoDeEmpezar, puntos,velocidad,tightness );
}


/*!
* Hace que el nodo quede texturizado por una secuencia de im&aacute;genes.
*
* \param RutaArchivoBase son las im&aacute;genes. Tienen que estar numeradas.
* Ej. Fuego_1.bmp Fuego_2.bmp.
* \param Extension la extensi&oacute;n de las im&aacute;genes,
* es decir, bmp, jpg, etc.
* \param NumeroCuadros
* \param TiempoPorCuadro
* \param ciclo
*
* Ejemplo:
* \code
* Animate.CrearTexturaAnimada("ani/Fuego","bmp", 8,50);
* Malla.AgregarAnimador(Animate);
* \endcode
*
* Los dos primeros par&aacute;metros en el ej. corresponden a "Fuego", "bmp"
*/
void GDT::Animador::CrearTexturaAnimada ( 
	char* RutaArchivoBase,
	char* Extension, 
	int NumeroCuadros, 
	int TiempoPorCuadro, 
	bool ciclo 
	)
{
	core::array<video::ITexture*> textures;
	for ( s32 g=1; g<=NumeroCuadros; ++g )
	{
		char tmp[64];
		sprintf ( tmp, "%s_%d.%s",RutaArchivoBase, g ,Extension );
		video::ITexture* t = Sistema::device->getVideoDriver()->getTexture ( tmp );
		textures.push_back ( t );
	}

	anim = Sistema::device->getSceneManager()->createTextureAnimator ( textures, TiempoPorCuadro, ciclo );
}

scene::ISceneNodeAnimator* GDT::Animador::Retornar ( void )
{
	return anim;
}


void GDT::Animador::Destruir()
{
	anim->drop();
}
