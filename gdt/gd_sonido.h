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

#ifndef GD_SONIDO_H
#define GD_SONIDO_H

#include "gd_sonido3d.h" // inheriting class's header file

// HACK PARA COMPILAR EN VISUAL C++ 2005
#ifndef _GDT_EXPORT_
  #ifdef _GDT_VC_STUDIO_2005_
   #define _GDT_EXPORT_ __declspec(dllexport)
  #else
    #define _GDT_EXPORT_
  #endif
#endif

/*
 * No description
 */
class GD_Sonido : public GD_Sonido3D
{
	public:
		// class constructor
		_GDT_EXPORT_ GD_Sonido();
		// class destructor
		_GDT_EXPORT_ ~GD_Sonido();
		
		_GDT_EXPORT_ char Cargar(char *);
        _GDT_EXPORT_ void Descargar();
        _GDT_EXPORT_ void Reproducir();
        _GDT_EXPORT_ void Pausa();
        _GDT_EXPORT_ void Detener();
        _GDT_EXPORT_ void Rebobinar();
        _GDT_EXPORT_ void Play();
        _GDT_EXPORT_ void Pause();
        _GDT_EXPORT_ void Stop();
        _GDT_EXPORT_ void Rewind();
        _GDT_EXPORT_ void Bucle(char);
        _GDT_EXPORT_ void Volumen(int);
        //_GDT_EXPORT_ void FactorRolloff(float);
        _GDT_EXPORT_ void Pan(float);
        _GDT_EXPORT_ void Tono(float);
        _GDT_EXPORT_ int Estado();
};

#endif // GD_SONIDO_H

#endif // _GDT_SONIDO_

