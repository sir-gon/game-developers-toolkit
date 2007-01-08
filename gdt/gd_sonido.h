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

#ifndef GD_SONIDO_H
#define GD_SONIDO_H

#include "gd_sonido3d.h" // inheriting class's header file

/**
 * Sonido
 */
class GD_Sonido : public GD_Sonido3D
{
	public:
		// class constructor
		GD_Sonido();
		// class destructor
		~GD_Sonido();
		
		char Cargar(char *);
        void Descargar();
        void Reproducir();
        void Pausa();
        void Detener();
        void Rebobinar();
        void Play();
        void Pause();
        void Stop();
        void Rewind();
        void Bucle(char);
        void Volumen(int);
        //void FactorRolloff(float);
        void Pan(float);
        void Tono(float);
        int Estado();
};

#endif // GD_SONIDO_H
