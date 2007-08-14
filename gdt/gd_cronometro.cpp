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

#include "gd_cronometro.h" // class's header file

/*!
* \class GDT::Cronometro
* \since 2.0
*
*
*
* \author Joropo
* \warning Esta clase es Experimental
*/

// class constructor
GDT::Cronometro::Cronometro()
{
	// insert your code here
	Estado = 0;
}

// class destructor
GDT::Cronometro::~Cronometro()
{
	// insert your code here
}


void GDT::Cronometro::Activar(int tiempo)
{
     TiempoDeFinalizar = tiempo;
     TiempoDelSistemaAlIniciar = GD_Sistema::device->getTimer()->getTime();
     Estado = 1;
}

void GDT::Cronometro::ActivarPulso(int tiempo)
{
     TiempoDePulso = tiempo;
     TiempoDelSistemaAlIniciar = GD_Sistema::device->getTimer()->getTime();
     EstadoPulso = 0;
     usandoPulsos = true;
     TiempoDelUltimoPulso = TiempoActivado();
}

bool GDT::Cronometro::Terminado()
{

   TDestino = TiempoDelSistemaAlIniciar + TiempoDeFinalizar;
        
   if( TDestino  <  GD_Sistema::device->getTimer()->getTime())
   {
       Estado = 0;
       return true;       
   }
   else
   {
       Estado = 1;
       return false;
   }
}

bool GDT::Cronometro::Contando()
{
     
     Terminado(); // actualiza
     
     if(Estado==1)
        return true;
     else
        return false;
}



u32 GDT::Cronometro::TiempoRestante()
{
    return TDestino - GD_Sistema::device->getTimer()->getTime();
}

u32 GDT::Cronometro::TiempoActivado()
{
    return GD_Sistema::device->getTimer()->getTime() - TiempoDelSistemaAlIniciar;
}

bool GDT::Cronometro::Pulso()
{
    //printf("DEBUG: TiempoActivado() = %d, TiempoDelUltimoPulso = %d, TiempoDePulso = %d\n", TiempoActivado(), TiempoDelUltimoPulso, TiempoDePulso);
     if(TiempoActivado() >= (TiempoDelUltimoPulso + TiempoDePulso))
     {
           TiempoDelUltimoPulso = TiempoActivado();
           ContadorPulsos++;
          // printf("PULSO\n");
           return true;
     }
     else
        return false;
}


