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

#ifndef GD_LUZ_H
#define GD_LUZ_H

#define RADIAL 1
#define DIRECCIONAL 2

#include "gd_nodo.h" // inheriting class's header file
#include "gd_escenario.h"

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
//! Crea y controla luces
/*!
Las luces permiten iluminar las mallas, con el color que sea establecida la luz, incluso se pueden proyectar sombras din&aacute;micas en las mallas ocupando luces.
*/
class _GDT_EXPORT_ GD_Luz : public GD_Nodo
{
        public:
        // class constructor
        GD_Luz();
        // class destructor
        ~GD_Luz();

        ILightSceneNode* nodl;
        video::SLight sluz; 

        //! Crea una luz
        void Crear();
        //! Crea una luz
        void Crear(int r, int g ,int b, float radio);
        //! Crea una luz
        void Crear(int r, int g ,int b, float radio, int tipmo);
        //! Crea una luz
        void Crear(float x, float y, float z, float radio);
        //! Crea una luz
        void Crear(float x, float y, float z, float radio, int tipo);
        //! Crea una luz
        void Crear(float x, float y, float z, float r, float g ,float b, float radio);
        //! Crea una luz	
        void Crear(float x, float y, float z, float r, float g ,float b, float radio, int tipo);
        //! Cambia el tipo de luz.
        void Tipo(int tipo);
        //! Establece si esta luz hace que las mallas tengan sombra.
        void HacerSombra(bool hacer);
        //! Son las coordenadas a la que apunta la luz en el caso de que el tipo sea direccional
        void Direccion(float x, float y, float z);
        //! Es el vector direcci&oacute;n a la que apunta la luz en el caso de que el tipo sea direccional
        void Direccion( vector3df vect);
        //! Establece el radio de la luz en el caso de que sea direccional
        void Radio(float rad);

        void ColorAmbiente(s32 r,s32 g,s32 b);
        void ColorDifuso( s32 r,s32 g,s32 b);
        void ColorEspecular(s32 r,s32 g,s32 b);

        void AumentarColorAmbiente(float val);
        void AumentarColorDifuso(float val);
        void AumentarColorEspecular(float val);

        void CrearColision( GD_Escenario scen,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz);
};

#endif // GD_LUZ_H
