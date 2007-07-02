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

#ifndef GD_GUI_H
#define GD_GUI_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

//! Base de cualquier elemento de la GUI
/*
 * Funciones comunes entre los objetos GUI
 */
class GD_gui
{
	public:
		// class constructor
		GD_gui();
		// class destructor
		~GD_gui();

      IrrlichtDevice *midevice;

		IGUISkin* skin;
		IGUIFont* fuente;
		IGUIEnvironment* guienv;
		IGUIElement* guiele;


      void RegistrarDevice(	IrrlichtDevice *device );

		bool EstaActivado();
		bool EstaVisible();

		void Posicionar(int x, int y);
		void Posicionar(position2d<s32> pos);
		//A&ntilde;adido--------------------------------
		void Mover(int x, int y);
		//---------------------------------------

		void Activado(bool estado);


		void Texto(const wchar_t *text);
		const wchar_t* RetornarTexto(void);

      void Visible(bool estado);

      int ID(void);

      IGUIElement* Elemento(void);

      void AdoptarHijo(IGUIElement* hijo);

      void Destruir(void);


      //Retornos
      position2d<s32> Posicion();
      int PosicionX();
      int PosicionY();
      position2d<s32> Centro();
      int CentroX();
      int CentroY();
      dimension2d<s32> Tamanio();
      int Ancho();
      int Alto();
      position2d<s32> EsquinaSuperiorIzquierda();
      int EsquinaSuperiorIzquierdaX();
      int EsquinaSuperiorIzquierdaY();
      position2d<s32> EsquinaInferiorDerecha();
      int EsquinaInferiorDerechaX();
      int EsquinaInferiorDerechaY();
      bool EsPuntoInterno(position2d<s32> punto);
      bool EsPuntoInterno(int x,int y);
      bool Colision(rect<s32> Rectangulo);
      bool Colision(IGUIElement* guiElemento);

};

#endif // GD_GUI_H
