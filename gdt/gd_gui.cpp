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
* \class GDgui
*
* Esta Clase es una plantilla com&uacute;n para todo los objetos GUI
* (sigla en ingl&eacute;s, Graphical User Interface).
*
* Los Controles GUI son objetos que se dibujan en 2D por sobre la escena 
* 2D/3D que se est&aacute; dibujando con nodos y similares.
*
* Con los Controle GUI podemos ingresar/obtener informaci&oacute;n e 
* interactuar con el programa.
*/

#include "gd_gui.h" // class's header file

// class constructor
GD_gui::GD_gui()
{
	// insert your code here
}

// class destructor
GD_gui::~GD_gui()
{
	// insert your code here
}

void GD_gui::RegistrarDevice(	IrrlichtDevice *device )
{
	midevice = device;
}

/*!
Ejemplo:
\code
if( Boton.EstaActivado() )
{
    // hacer algo
}
\endcode
*/
bool GD_gui::EstaActivado()
{
      return guiele->isEnabled();
}

/*!
Ejemplo:
\code
if( Boton.EstaVisible() )
{
}
\endcode
*/
bool GD_gui::EstaVisible()
{
      return guiele->isVisible();
}

/*!
\param x,y coordenadas en pixeles.

Ejemplo:
\code
Boton.Posicionar(50, 20);
\endcode
*/
void GD_gui::Posicionar(int x, int y)
{
    //guiele->move(core::position2d< s32 >( x,  y));
    position2d<s32> NewPos;

    NewPos.X=x; NewPos.Y=y;
    rect<s32> cua(NewPos,guiele->getRelativePosition().getSize());

    guiele->setRelativePosition(cua);
}

/*!
\param pos vector posicion 2D, en pixeles

Ejemplo:
\code
Boton.Posicionar(50, 20);
\endcode
*/
void GD_gui::Posicionar(position2d<s32> pos)
{
   rect<s32> cua(pos,guiele->getRelativePosition().getSize());
   guiele->setRelativePosition(cua);
}

/*!
\param estado True para activado y false para desactivado.

\code
Boton.Activar(false);
\endcode
*/
void GD_gui::Activado(bool estado)
{
    guiele->setEnabled(estado);
}

/*!
\param text El texto del boton

Ejemplo:
\code
Boton.Texto(L"Pulsame");
\endcode
*/
void GD_gui::Texto(const wchar_t *text)
{
    guiele->setText(text);
}

/*!
\return El texto actual del Control GUI
*/
const wchar_t* GD_gui::RetornarTexto(void )
{
    return guiele->getText();
}

/*!
Ejemplo:
\code
Boton.Visible(false);
\endcode
*/
void GD_gui::Visible(bool estado)
{
    guiele->setVisible(estado);
}

/*!
\code
int id = Boton.ID();
\endcode
*/
int GD_gui::ID()
{
    return guiele->getID();
}

/*!
Ejemplo:
\code
Ventana.AdoptarHijo(Boton1.Elemento() );
\endcode
*/
IGUIElement* GD_gui::Elemento(void)
{
    return guiele;
}

/*!
Ejemplo:
\code
Ventana.AdoptarHijo(Boton1.Elemento() );
\endcode
*/
void GD_gui::AdoptarHijo(IGUIElement* hijo)
{
    guiele->addChild(hijo);
}

/*!
Ejemplo:
\code
Boton.Destruir();
\endcode
*/
void GD_gui::Destruir(void)
{
    guiele->remove();
}

//Retornos *****************************************************
//**************************************************************

position2d<s32> GD_gui::Posicion()
{
   return guiele->getRelativePosition().UpperLeftCorner;
}
int GD_gui::PosicionX()
{
   return (int)Posicion().X;
}
int GD_gui::PosicionY()
{
   return (int)Posicion().Y;
}
position2d<s32> GD_gui::Centro()
{
   return guiele->getRelativePosition().getCenter();
}
int GD_gui::CentroX()
{
   return (int)Centro().X;
}
int GD_gui::CentroY()
{
   return (int)Centro().Y;
}
dimension2d<s32> GD_gui::Tamanio()
{
   return guiele->getRelativePosition().getSize();
}
int GD_gui::Ancho()
{
   return (int) guiele->getRelativePosition().getWidth();
}
int GD_gui::Alto()
{
   return (int) guiele->getRelativePosition().getHeight();
}
position2d<s32> GD_gui::EsquinaSuperiorIzquierda()
{
   return guiele->getRelativePosition().UpperLeftCorner;
}
int GD_gui::EsquinaSuperiorIzquierdaX()
{
   return (int)EsquinaSuperiorIzquierda().X;
}
int GD_gui::EsquinaSuperiorIzquierdaY()
{
   return (int)EsquinaSuperiorIzquierda().Y;
}
position2d<s32> GD_gui::EsquinaInferiorDerecha()
{
   return guiele->getRelativePosition().LowerRightCorner;
}
int GD_gui::EsquinaInferiorDerechaX()
{
   return (int)EsquinaInferiorDerecha().X;
}
int GD_gui::EsquinaInferiorDerechaY()
{
   return (int)EsquinaInferiorDerecha().Y;
}
bool GD_gui::EsPuntoInterno(position2d<s32> punto)
{
   return guiele->getRelativePosition().isPointInside(punto);
}
bool GD_gui::EsPuntoInterno(int x,int y)
{
   return EsPuntoInterno(position2d<s32>(x,y));
}
bool GD_gui::Colision(rect<s32> Rectangulo)
{
   return guiele->getRelativePosition().isRectCollided(Rectangulo);
}
bool GD_gui::Colision(IGUIElement* guiElemento)
{
   return Colision(guiElemento->getRelativePosition());
}
///--------------------------------------------------------------


