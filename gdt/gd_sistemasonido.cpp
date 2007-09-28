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

#include "gd_sistemasonido.h" // class's header file

// class constructor
GDT::Sonido::SistemaSonido::SistemaSonido()
{
	// insert your code here
}

// class destructor
GDT::Sonido::SistemaSonido::~SistemaSonido()
{
	// insert your code here
}

/*!
*/
void GDT::Sonido::SistemaSonido::Inicializar()
{
	SListenerPos[0] = SListenerPos[1] = SListenerPos[2] = 0.0;
	SListenerVel[0] = SListenerVel[1] = SListenerVel[2] = 0.0;

	SListenerOri[0] = 0.0;
	SListenerOri[1] = 0.0;
	SListenerOri[2] = -1.0;
	SListenerOri[3] = 0.0;
	SListenerOri[4] = 1.0;
	SListenerOri[5] = 0.0;

	//SGDsoundIniciado=0;
	SGDsoundIniciado=false;

	alutInit ( NULL, 0 );
	alGetError();

	//SGDsoundIniciado=1;
	SGDsoundIniciado=true;
}

/*!
*/
void GDT::Sonido::SistemaSonido::Inicializar ( char *tipo )
{
	SListenerPos[0] = SListenerPos[1] = SListenerPos[2] = 0.0;
	SListenerVel[0] = SListenerVel[1] = SListenerVel[2] = 0.0;

	SListenerOri[0] = 0.0;
	SListenerOri[1] = 0.0;
	SListenerOri[2] = -1.0;
	SListenerOri[3] = 0.0;
	SListenerOri[4] = 1.0;
	SListenerOri[5] = 0.0;

	SGDsoundIniciado=0;

	ALCdevice* pDevice;
	ALCcontext* pContext;
	//ALCubyte* defaultDevice;

	//    pDevice = alcOpenDevice((ALCubyte*)"DirectSound3D");

	pDevice = alcOpenDevice ( ( ALCchar* ) tipo );
	if ( pDevice )
	{
		pContext = alcCreateContext ( pDevice, NULL );
		alcMakeContextCurrent ( pContext );
	}


	if ( alcGetError ( pDevice ) != ALC_NO_ERROR )
		SGDsoundIniciado=0;

	alGetError();
	//SGDsoundIniciado=1;
	SGDsoundIniciado=true;
}

/*!
*/
void GDT::Sonido::SistemaSonido::FinGDsonido()
{
	alutExit();
	//SGDsoundIniciado=0;
	SGDsoundIniciado=false;
}

/*!
*/
void GDT::Sonido::SistemaSonido::PosicionOyente ( float x, float y, float z )
{
	SListenerPos[0]= ( ALfloat ) x;
	SListenerPos[1]= ( ALfloat ) y;
	SListenerPos[2]= ( ALfloat ) z;
	alListenerfv ( AL_POSITION, SListenerPos );
}

/*!
*/
void GDT::Sonido::SistemaSonido::VelocidadOyente ( float x, float y, float z )
{
	SListenerVel[0]=x; SListenerVel[1]=y; SListenerVel[2]=z;
	alListenerfv ( AL_VELOCITY, SListenerVel );
}

/*!
*/
void GDT::Sonido::SistemaSonido::OrientacionOyente ( float x1, float y1, float z1 )
{
	SListenerOri[0]=x1; SListenerOri[1]=y1; SListenerOri[2]=z1;
	SListenerOri[3]=0; SListenerOri[4]=1.0; SListenerOri[5]=0;
	alListenerfv ( AL_ORIENTATION, SListenerOri );
}

/*!
*/
void GDT::Sonido::SistemaSonido::OrientacionOyente (
    float x1, float y1, float z1,
    float x2, float y2, float z2
)
{
	SListenerOri[0]=x1; SListenerOri[1]=y1; SListenerOri[2]=z1;
	SListenerOri[3]=x2; SListenerOri[4]=y2; SListenerOri[5]=z2;
	alListenerfv ( AL_ORIENTATION, SListenerOri );
}



#endif // _GDT_SONIDO_
