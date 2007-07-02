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

#include "gd_sonido.h" // class's header file

// class constructor
GD_Sonido::GD_Sonido()
{
	// insert your code here
}

// class destructor
GD_Sonido::~GD_Sonido()
{
	// insert your code here
}



char GD_Sonido::Cargar(char *archivo)
{
    Cargar(archivo);
    RelativoOyente(1);
    Posicionar(0.0f , 0.0f , 0.1f);
    return 0;
}

void GD_Sonido::Descargar()
{
    Descargar();
}

void GD_Sonido::Reproducir()
{
    Reproducir();
}

void GD_Sonido::Pausa()
{
    Pausa();
}

void GD_Sonido::Detener()
{
    Detener();
}

void GD_Sonido::Rebobinar()
{
    Rebobinar();
}

void GD_Sonido::Play()
{
    Play();
}

void GD_Sonido::Pause()
{
    Pause();
}

void GD_Sonido::Stop()
{
    Stop();
}

void GD_Sonido::Rewind()
{
    Rewind();
}
void GD_Sonido::Bucle(char loop)
{
    Bucle(loop);
}

void GD_Sonido::Pan(float p)
{
   Posicionar(p , 0.0f , 0.1f);
}

void GD_Sonido::Tono(float t)
{
   Tono(t);
}

int GD_Sonido::Estado()
{
    //0 esta sonando , 1 esta en pausa, 2 esta parado, cualquier otra cosa es fallo
    return Estado();
}
void GD_Sonido::Volumen(int vol)
{
   float rvol;
   if(vol<0)
   {
      vol=0;
   }
   rvol=(float)vol/100.0f;
   //Posicion(0.0,0.0,0.0-rvol);
   //ReferenciaDistancia(rvol);
   VolumenMaximo(rvol);
}

