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

//SE ESPERA DEFINICION COMO PARAMETRO DEL COMPILADOR
#ifdef _GDT_SONIDO_

#ifndef GD_SISTEMASONIDO_H
#define GD_SISTEMASONIDO_H

/*
 * No description
 */

//INCLUDES para la libreria
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <al.h>
#include <alc.h>
#include <alut.h>
#include <ogg.h>
#include <vorbisfile.h>

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

/* No documentar */
#ifndef _GDT_DOXYGEN_IGNORAR_
using namespace std;
#endif /* _GDT_DOXYGEN_IGNORAR_ */

class _GDT_EXPORT_ GD_SistemaSonido
{

    public:

		// class constructor
		GD_SistemaSonido();
		// class destructor
		~GD_SistemaSonido();

        //Posicion, velocidad y orientacion del oyente. (no tocar directamente, usar las funciones...)
        ALfloat SListenerPos[2];
        ALfloat SListenerVel[2];
        ALfloat SListenerOri[5];
        // Orientation of the Listener. (first 3 elements are "at", second 3 are "up")
        // Also note that these should be units of '1'.

        //variable para saber si esta iniciado o no el openal (0 no, 1 si)
        char SGDsoundIniciado;

        //funcion para iniciar el GD_Sonido con el dispositivo m&aacute;s compatible que encuentre
        void Inicializar();
        //igual pero indicandole que dispositivo tiene que usar
        void Inicializar(char *);
        //finaliza el GD_Sonido y desbloquea el dispositivo
        void FinGDsonido();
        //Ajusta la posicion en 3d del oyente
        void PosicionOyente(float,float,float);
        //Ajusta el movimiento del oyente en 3d (aun en pruebas)
        void VelocidadOyente(float,float,float);
        //Ajusta la orientacion del oyente
        void OrientacionOyente(float, float, float);
        //Ajusta la orientacion del oyente (incluyendo roll, 3 ultimos floats)
        void OrientacionOyente(float, float, float, float, float, float);
};

#endif // GD_SISTEMASONIDO_H

#endif // _GDT_SONIDO_
