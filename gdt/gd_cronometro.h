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

#ifndef CRONOMETRO_H
#define CRONOMETRO_H

#include "gd_sistema.h"

//EXPORTAR SIMBOLOS AL CREAR DLL
#ifndef _GDT_EXPORT_
  #ifdef WIN32
	#ifdef _GDT_DLL_
	   #define _GDT_EXPORT_ __declspec(dllexport)
	#else /* No _GDT_DLL_ */
	   #define _GDT_EXPORT_ __declspec(dllimport)
	#endif /* Fin No _GDT_DLL_ */
  #else
// SINO, DEFINIR COMO NULO EL EXPORTADOR
    #define _GDT_EXPORT_ /* Definido nulo */
  #endif  /* WIN32 */
#endif /* _GDT_EXPORT_ */

namespace GDT
{

//! Contador de tiempo
class Cronometro
{
	public:
	// class constructor
	_GDT_EXPORT_ Cronometro();
	// class destructor
	_GDT_EXPORT_ ~Cronometro();
	
	u32 TiempoDeFinalizar;
	u32 TiempoDePulso;
	u32 TiempoDelSistemaAlIniciar;
	u32 Estado; //1 contando   0 termino de contar
	u32 EstadoPulso;
	u32 ContadorPulsos;
	u32 TiempoDelUltimoPulso;
	u32 TDestino;
	bool usandoPulsos;
	
	_GDT_EXPORT_ void Activar(int tiempo);
	_GDT_EXPORT_ void ActivarPulso(int tiempo);
	_GDT_EXPORT_ bool Pulso();
	_GDT_EXPORT_ bool Terminado();
	_GDT_EXPORT_ bool Contando();
	_GDT_EXPORT_ u32 TiempoRestante();
	_GDT_EXPORT_ u32 TiempoActivado();
};

} // FIN NAMESPACE GDT

#endif // CRONOMETRO_H
