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

#ifndef GD_ANIMADOR_H
#define GD_ANIMADOR_H

#include <irrlicht.h>
#include "gd_sistema.h"
#include <irrArray.h> 
#include "gd_textura.h"

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

//! Animador
class GD_Animador
{
	public:
	// class constructor
	_GDT_EXPORT_ GD_Animador();
	// class destructor
	_GDT_EXPORT_ ~GD_Animador();
	
	scene::ISceneNodeAnimator* anim;
	scene::ISceneNodeAnimator* Retornar(void);
	
	//! Crea un animador en orbita. Los parametros son la posicion del centro, el radio, y la velocidad 
	_GDT_EXPORT_ void CrearOrbita(
		float CentroX, float CentroY, float CentroZ,
		float Radio, float Velocidad=0.001f,
		float DireccionX=0.0f,float DireccionY=1.0f,float DireccionZ=0.0f
	);

	//! Crea un animador en Linea, el nodo ira de un punto a otro en linea recta en un tiempo dado. Muy recomendado para hacer la trayectoria de los disparos.
	_GDT_EXPORT_ void CrearLinea(
		float IniX, float IniY, float IniZ,
		float FinX, float FinY, float FinZ,
		int Tiempo,
		bool Ciclo=false
	);
	_GDT_EXPORT_ void CrearLinea(
		vector3df ini,
		vector3df fin,
		int Tiempo,
		bool Ciclo=false
	);

	//! Crea un animador rotacional, el nodo girara, tantos angulos por segundo con respecto a el mismo.
	_GDT_EXPORT_ void CrearRotador(
		float RotacionPorSegundoX,
		float RotacionPorSegundoY,
		float RotacionPorSegundoZ
	);
	
	//! Crea un animador que sigue por una ruta o curva.
	_GDT_EXPORT_ void CrearRecorreCurva(
		core::array<core::vector3df>& puntos,
		float  velocidad = 1.0f,
		int TiempoDeEmpezar=-1,
		float  tightness = 0.5f
	);

	//! Crea un animador de textura, esto hace que el nodo quede texturizado por una secuencia de imagenes ej. Animate.CrearTexturaAnimada("ani/fuego","bmp", 8,50); Malla.AgregarAnimador(Animate);, las imagenes tienen que estar numeradas ej. Fuego_1.bmp Fuego_2.bmp . Los dos primeros parametros en el ej. seria corresponden a "Fuego", "bmp" 
	_GDT_EXPORT_ void CrearTexturaAnimada(
		char* RutaArchivoBase,
		char* Extension,
		int NumeroCuadros,
		int TiempoPorCuadro=100,
		bool ciclo=true
	);
	
	_GDT_EXPORT_ void Destruir();

};

#endif // GD_ANIMADOR_H
