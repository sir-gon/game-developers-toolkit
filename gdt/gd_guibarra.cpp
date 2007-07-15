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

/*!
* \class GDGuiBarra
*
* 
*/

#include "gd_guibarra.h" // class's header file

// class constructor
GD_GuiBarra::GD_GuiBarra()
{
	// insert your code here
}

// class destructor
GD_GuiBarra::~GD_GuiBarra()
{
	// insert your code here
}

/*!
\param x1,y1 posición de la barra.
\param x2,y2 hasta donde llega la barra.
\param padre por defecto es 0. Si no esta seguro, omita este par&aacute;metro.

Ejemplo:
\code
Barra.CrearHorizontal(5,5, 30,15);
\endcode
*/
void GD_GuiBarra::CrearHorizontal(int x1, int y1, int x2, int y2, IGUIElement* padre)
{

    RegistrarDevice(GD_Sistema::device); 
    
    IVideoDriver* driver = midevice->getVideoDriver();
    IGUIEnvironment* guienv = midevice->getGUIEnvironment();
    
     barra=guienv->addScrollBar(true, rect<s32>(x1,y1,x2,y2),padre, GD_Sistema::ContadorElementosGui++);
     
      guiele = barra;
}

/*!
\param x1,y1 posición de la barra.
\param x2,y2 hasta donde llega la barra.
\param padre por defecto es 0. Si no esta seguro, omita este par&aacute;metro.

Ejemplo:
\code
Barra.CrearVerticall(5,5, 15,30);
\endcode
*/
void GD_GuiBarra::CrearVertical(int x1, int y1, int x2, int y2,IGUIElement* padre)
{

    RegistrarDevice(GD_Sistema::device); 
    
    IVideoDriver* driver = midevice->getVideoDriver();
    IGUIEnvironment* guienv = midevice->getGUIEnvironment();
    
     barra=guienv->addScrollBar(false, rect<s32>(x1,y1,x2,y2),padre, GD_Sistema::ContadorElementosGui++);
     
      guiele = barra;
}

/*!
El máximo no puede sobrepasar de 255.

\param maximo el valor m&aacute;

Ejemplo:
\code
Barra.MaximoValor(157);
\endcode
*/
void GD_GuiBarra::MaximoValor(int maximo)
{
     barra->setMax(maximo);
}

/*!
Ejemplo:
\code
int pos = Barra.Posicion();
\endcode
*/
int GD_GuiBarra::Posicion(void)
{
     return barra->getPos();
}

/*!
Ejemplo:
\code
Barra.Posicionar(50);
\endcode
*/
void GD_GuiBarra::Posicionar(int posicion)
{
     barra->setPos(posicion);
}

