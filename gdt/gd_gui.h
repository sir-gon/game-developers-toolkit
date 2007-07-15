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

/* No documentar */
#ifndef _GDT_DOXYGEN_IGNORAR_
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
#endif /* _GDT_DOXYGEN_IGNORAR_ */

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

//! Base de los Controles de la Interfaz Gr&aacute;fica de Usuario (GUI)
class _GDT_EXPORT_ GD_gui
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

	//!
	void RegistrarDevice( IrrlichtDevice *device );
	//! Comprueba si el control GUI est&aacute; activado.
	bool EstaActivado();
	//! Comprueba si el control GUI es visible.
	bool EstaVisible();
	//! Ubica el control GUI en las coordenadas que se indiquen.
	void Posicionar(int x, int y);
	//! Ubica el control GUI donde se indique usando un vector 2D.
	void Posicionar(position2d<s32> pos);
	//Agregado-------------------------------
	//void Mover(int x, int y);
	//---------------------------------------
	//! Activa o desactiva un Control GUI.
	void Activado(bool estado);
	//! Cambia el texto de un Control GUI.
	void Texto(const wchar_t *text);
	//! Obtiene el texto de un Control GUI.
	const wchar_t* RetornarTexto(void);
	//! Establece si el control es visible o no
	void Visible(bool estado);
	//! Obtiene la identiadad (ID) del Control GUI
	int ID(void);
	//! Obtiene el "elemento" del Control GUI.
	IGUIElement* Elemento(void);
	//! Hace que el Control GUI adopte otro control como su Hijo.
	void AdoptarHijo(IGUIElement* hijo);
	//! Destruye el control Gui.
	void Destruir(void);
	
	
	//Retornos
	//! Obtiene la posición del Control GUI
	position2d<s32> Posicion();
	int PosicionX();
	int PosicionY();
	//! Obtiene la posición del centro del Control GUI
	position2d<s32> Centro();
	int CentroX();
	int CentroY();
	//! Obtiene las dimensiones del Control GUI
	dimension2d<s32> Tamanio();
	//! Obtiene el ancho del Control GUI
	int Ancho();
	//! Obtiene el alto del Control GUI
	int Alto();
	//! Obtiene la posición de la esquina Superior Izquierda
	position2d<s32> EsquinaSuperiorIzquierda();
	//! Obtiene la coordenada X de la posición de la esquina Superior Izquierda
	int EsquinaSuperiorIzquierdaX();
	//! Obtiene la coordenada Y de la posición de la esquina Superior Izquierda
	int EsquinaSuperiorIzquierdaY();
	//! Obtiene la posición de la esquina Inferior Derecha
	position2d<s32> EsquinaInferiorDerecha();
	//! Obtiene la coordenada X de la posición de la esquina Inferior Derecha
	int EsquinaInferiorDerechaX();
	//! Obtiene la coordenada Y de la posición de la esquina Inferior Derecha
	int EsquinaInferiorDerechaY();
	//! Comprueba si un punto está al interior del Control GUI
	bool EsPuntoInterno(position2d<s32> punto);
	//! Comprueba si un las coordenadas están dentro del Control GUI
	bool EsPuntoInterno(int x,int y);
	//!
	bool Colision(rect<s32> Rectangulo);
	//!
	bool Colision(IGUIElement* guiElemento);
};

#endif // GD_GUI_H
