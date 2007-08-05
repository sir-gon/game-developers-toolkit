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

#ifndef GD_CRONOMETRO_H
#define GD_CRONOMETRO_H


#include "gd_sistema.h"
/*
 * No description
 */
class GD_Cronometro
{
	public:
		// class constructor
		GD_Cronometro();
		// class destructor
		~GD_Cronometro();
		
		u32 TiempoDeFinalizar;
		u32 TiempoDePulso;
		u32 TiempoDelSistemaAlIniciar;
		u32 Estado; //1 contando   0 termino de contar
		u32 EstadoPulso;
		u32 ContadorPulsos;
		u32 TiempoDelUltimoPulso;
		u32 TDestino;
		bool usandoPulsos;
		
		void Activar(int tiempo);
		void ActivarPulso(int tiempo);
		bool Pulso();
		bool Terminado();
        bool Contando();
        u32 TiempoRestante();
        u32 TiempoActivado();
        
       
		
};

#endif // GD_CRONOMETRO_H
