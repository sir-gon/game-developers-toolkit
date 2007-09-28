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

#ifdef _GDT_SONIDO_

#include "gd_sonido.h" // class's header file

/*!
* \class GDT::Sonido::Sonido
*/

// class constructor
GDT::Sonido::Sonido::Sonido()
{
	// insert your code here
}

// class destructor
GDT::Sonido::Sonido::~Sonido()
{
	// insert your code here
}



char GDT::Sonido::Sonido::Cargar ( char *archivo )
{
	/*
	   Cargar(archivo);
	   RelativoOyente(1);
	   Posicionar(0.0f , 0.0f , 0.1f);
	*/
	return 0;
}

void GDT::Sonido::Sonido::Descargar()
{
	//Descargar();
}

void GDT::Sonido::Sonido::Reproducir()
{
	//Reproducir();
}

void GDT::Sonido::Sonido::Pausa()
{
	//Pausa();
}

void GDT::Sonido::Sonido::Detener()
{
	//Detener();
}

void GDT::Sonido::Sonido::Rebobinar()
{
	//Rebobinar();
}

void GDT::Sonido::Sonido::Play()
{
	//Play();
}

void GDT::Sonido::Sonido::Pause()
{
	//Pause();
}

void GDT::Sonido::Sonido::Stop()
{
	//Stop();
}

void GDT::Sonido::Sonido::Rewind()
{
	//Rewind();
}
void GDT::Sonido::Sonido::Bucle ( char loop )
{
	//Bucle(loop);
}

void GDT::Sonido::Sonido::Pan ( float p )
{
	GDT::Sonido::Sonido::Posicionar ( p , 0.0f , 0.1f );
}

void GDT::Sonido::Sonido::Tono ( float t )
{
	//Tono(t);
}

int GDT::Sonido::Sonido::Estado()
{
	//0 esta sonando , 1 esta en pausa, 2 esta parado, cualquier otra cosa es fallo
	//return Estado();
	return 0;
}
void GDT::Sonido::Sonido::Volumen ( int vol )
{
	float rvol;
	if ( vol<0 )
	{
		vol=0;
	}
	rvol= ( float ) vol/100.0f;
	//Posicion(0.0,0.0,0.0-rvol);
	//ReferenciaDistancia(rvol);
	GDT::Sonido::Sonido::VolumenMaximo ( rvol );
}

#endif // _GDT_SONIDO_
