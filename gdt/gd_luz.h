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
	#ifdef _GDT_DLL_
	   #define _GDT_EXPORT_ __declspec(dllexport)
	#else /* Not _GDT_DLL_ */
	   #define _GDT_EXPORT_ __declspec(dllimport)
	#endif /* Not _GDT_DLL_ */
  #else
// SINO, DEFINIR COMO NULO EL EXPORTADOR 
    #define _GDT_EXPORT_ /* Definido nulo */
  #endif  /* WIN32 */
#endif /* _GDT_EXPORT_ */

//! Crea y controla luces
/*!
Las luces permiten iluminar las mallas, con el color que sea establecida la luz, incluso se pueden proyectar sombras din&aacute;micas en las mallas ocupando luces.
*/
class GD_Luz : public GD_Nodo
{
        public:
        // class constructor
        _GDT_EXPORT_ GD_Luz();
        // class destructor
        _GDT_EXPORT_ ~GD_Luz();

        ILightSceneNode* nodl;
        video::SLight sluz; 

        //! Crea una luz
        _GDT_EXPORT_ void Crear();
        //! Crea una luz
        _GDT_EXPORT_ void Crear(int r, int g ,int b, float radio);
        //! Crea una luz
        _GDT_EXPORT_ void Crear(int r, int g ,int b, float radio, int tipmo);
        //! Crea una luz
        _GDT_EXPORT_ void Crear(float x, float y, float z, float radio);
        //! Crea una luz simple de un cierto radio y la posiciona en las coordenadas dadas
        _GDT_EXPORT_ void Crear(float x, float y, float z, float radio, int tipo);
        //! Crea una luz de un color (RGB) de un cierto radio y la posiciona en las coordenadas dadas
        _GDT_EXPORT_ void Crear(float x, float y, float z, float r, float g ,float b, float radio);
        //! Crea una luz	
        _GDT_EXPORT_ void Crear(float x, float y, float z, float r, float g ,float b, float radio, int tipo);
        //! Cambia el tipo de luz.
        _GDT_EXPORT_ void Tipo(int tipo);
        //! Establece si esta luz hace que las mallas tengan sombra.
        _GDT_EXPORT_ void HacerSombra(bool hacer);
        //! Son las coordenadas a la que apunta la luz en el caso de que el tipo sea direccional
        _GDT_EXPORT_ void Direccion(float x, float y, float z);
        //! Es el vector direcci&oacute;n a la que apunta la luz en el caso de que el tipo sea direccional
        _GDT_EXPORT_ void Direccion( vector3df vect);
        //! Establece el radio de la luz en el caso de que sea direccional
        _GDT_EXPORT_ void Radio(float rad);

        _GDT_EXPORT_ void ColorAmbiente(s32 r,s32 g,s32 b);
        _GDT_EXPORT_ void ColorDifuso(s32 r,s32 g,s32 b);
        _GDT_EXPORT_ void ColorEspecular(s32 r,s32 g,s32 b);

        // no son los mismos que heredan de GD_Nodo, con las luces funciona diferente
        // asi que tenemos que implementar nuevos metodos
        _GDT_EXPORT_ int RetornarColorAmbienteR();
        _GDT_EXPORT_ int RetornarColorAmbienteG();
        _GDT_EXPORT_ int RetornarColorAmbienteB();
        _GDT_EXPORT_ int RetornarColorDifusoR();
        _GDT_EXPORT_ int RetornarColorDifusoG();
        _GDT_EXPORT_ int RetornarColorDifusoB();
        _GDT_EXPORT_ int RetornarColorEspecularR();
        _GDT_EXPORT_ int RetornarColorEspecularG();
        _GDT_EXPORT_ int RetornarColorEspecularB();

        _GDT_EXPORT_ void AumentarColorAmbiente(float val);
        _GDT_EXPORT_ void AumentarColorDifuso(float val);
        _GDT_EXPORT_ void AumentarColorEspecular(float val);

        _GDT_EXPORT_ void CrearColision( GD_Escenario scen,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz);
};

#endif // GD_LUZ_H
