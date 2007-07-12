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

// HACK PARA COMPILAR EN VISUAL C++ 2005
#ifndef _GDT_EXPORT_
  #ifdef _GDT_VC_STUDIO_2005_
   #define _GDT_EXPORT_ __declspec(dllexport)
  #else
    #define _GDT_EXPORT_
  #endif
#endif

//! Base de los elementos (Controles) de la Interfaz Gr&aacute;fica de Usuario (GUI)
class GD_gui
{
public:
	// class constructor
	_GDT_EXPORT_ GD_gui();
	// class destructor
	_GDT_EXPORT_ ~GD_gui();
	
	IrrlichtDevice *midevice;
	
	IGUISkin* skin;
	IGUIFont* fuente;
	IGUIEnvironment* guienv;
	IGUIElement* guiele;

	//!
	_GDT_EXPORT_ void RegistrarDevice( IrrlichtDevice *device );
	//! Comprueba si el control GUI est&aacute; activado.
	_GDT_EXPORT_ bool EstaActivado();
	//! Comprueba si el control GUI es visible.
	_GDT_EXPORT_ bool EstaVisible();
	//! Ubica el control GUI en las coordenadas que se indiquen.
	_GDT_EXPORT_ void Posicionar(int x, int y);
	//! Ubica el control GUI donde se indique usando un vector 2D.
	_GDT_EXPORT_ void Posicionar(position2d<s32> pos);
	//Agregado-------------------------------
	//_GDT_EXPORT_ void Mover(int x, int y);
	//---------------------------------------
	//! Activa o desactiva un Control GUI.
	_GDT_EXPORT_ void Activado(bool estado);
	//! Cambia el texto de un Control GUI.
	_GDT_EXPORT_ void Texto(const wchar_t *text);
	//! Obtiene el texto de un Control GUI.
	_GDT_EXPORT_ const wchar_t* RetornarTexto(void);
	//! Establece si el control es visible o no
	_GDT_EXPORT_ void Visible(bool estado);
	//! Obtiene la identiadad (ID) del Control GUI
	_GDT_EXPORT_ int ID(void);
	//! Obtiene el "elemento" del Control GUI.
	_GDT_EXPORT_ IGUIElement* Elemento(void);
	//! Hace que el Control GUI adopte otro control como su Hijo.
	_GDT_EXPORT_ void AdoptarHijo(IGUIElement* hijo);
	//! Destruye el control Gui.
	_GDT_EXPORT_ void Destruir(void);
	
	
	//Retornos
	//! Obtiene la posición del Control GUI
	_GDT_EXPORT_ position2d<s32> Posicion();
	_GDT_EXPORT_ int PosicionX();
	_GDT_EXPORT_ int PosicionY();
	//! Obtiene la posición del centro del Control GUI
	_GDT_EXPORT_ position2d<s32> Centro();
	_GDT_EXPORT_ int CentroX();
	_GDT_EXPORT_ int CentroY();
	//! Obtiene las dimensiones del Control GUI
	_GDT_EXPORT_ dimension2d<s32> Tamanio();
	//! Obtiene el ancho del Control GUI
	_GDT_EXPORT_ int Ancho();
	//! Obtiene el alto del Control GUI
	_GDT_EXPORT_ int Alto();
	//! Obtiene la posición de la esquina Superior Izquierda
	_GDT_EXPORT_ position2d<s32> EsquinaSuperiorIzquierda();
	//! Obtiene la coordenada X de la posición de la esquina Superior Izquierda
	_GDT_EXPORT_ int EsquinaSuperiorIzquierdaX();
	//! Obtiene la coordenada Y de la posición de la esquina Superior Izquierda
	_GDT_EXPORT_ int EsquinaSuperiorIzquierdaY();
	//! Obtiene la posición de la esquina Inferior Derecha
	_GDT_EXPORT_ position2d<s32> EsquinaInferiorDerecha();
	//! Obtiene la coordenada X de la posición de la esquina Inferior Derecha
	_GDT_EXPORT_ int EsquinaInferiorDerechaX();
	//! Obtiene la coordenada Y de la posición de la esquina Inferior Derecha
	_GDT_EXPORT_ int EsquinaInferiorDerechaY();
	//! Comprueba si un punto está al interior del Control GUI
	_GDT_EXPORT_ bool EsPuntoInterno(position2d<s32> punto);
	//! Comprueba si un las coordenadas están dentro del Control GUI
	_GDT_EXPORT_ bool EsPuntoInterno(int x,int y);
	//!
	_GDT_EXPORT_ bool Colision(rect<s32> Rectangulo);
	//!
	_GDT_EXPORT_ bool Colision(IGUIElement* guiElemento);
};

#endif // GD_GUI_H
