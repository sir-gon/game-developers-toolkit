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

#ifndef GD_GUI_H
#define GD_GUI_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

/**
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
	
	void Activado(bool estado);
	
	
	void Texto(const wchar_t *text);
	const wchar_t* RetornarTexto(void);

	void Visible(bool estado);
	
	int ID(void);
	
	IGUIElement* Elemento(void);
	
	void AdoptarHijo(IGUIElement* hijo);
	
	void Destruir(void);

};

#endif // GD_GUI_H
