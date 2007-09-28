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
* \class GDT::Gui::GuiBase
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
GDT::Gui::GuiBase::GuiBase()
{
	// insert your code here
}

// class destructor
GDT::Gui::GuiBase::~GuiBase()
{
	// insert your code here
}

void GDT::Gui::GuiBase::RegistrarDevice (	IrrlichtDevice *device )
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
bool GDT::Gui::GuiBase::EstaActivado()
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
bool GDT::Gui::GuiBase::EstaVisible()
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
void GDT::Gui::GuiBase::Posicionar ( int x, int y )
{
	//guiele->move(core::position2d< s32 >( x,  y));
	position2d<s32> NewPos;

	NewPos.X=x; NewPos.Y=y;
	rect<s32> cua ( NewPos,guiele->getRelativePosition().getSize() );

	guiele->setRelativePosition ( cua );
}

/*!
\param pos vector posicion 2D, en pixeles

Ejemplo:
\code
Boton.Posicionar(50, 20);
\endcode
*/
void GDT::Gui::GuiBase::Posicionar ( position2d<s32> pos )
{
	rect<s32> cua ( pos,guiele->getRelativePosition().getSize() );
	guiele->setRelativePosition ( cua );
}

/*!
\param estado True para activado y false para desactivado.

\code
Boton.Activar(false);
\endcode
*/
void GDT::Gui::GuiBase::Activado ( bool estado )
{
	guiele->setEnabled ( estado );
}

/*!
\param text El texto del boton

Ejemplo:
\code
Boton.Texto(L"Pulsame");
\endcode
*/
void GDT::Gui::GuiBase::Texto ( const wchar_t *text )
{
	guiele->setText ( text );
}

/*!
\return El texto actual del Control GUI
*/
const wchar_t* GDT::Gui::GuiBase::RetornarTexto ( void )
{
	return guiele->getText();
}

/*!
Ejemplo:
\code
Boton.Visible(false);
\endcode
*/
void GDT::Gui::GuiBase::Visible ( bool estado )
{
	guiele->setVisible ( estado );
}

/*!
\code
int id = Boton.ID();
\endcode
*/
int GDT::Gui::GuiBase::ID()
{
	return guiele->getID();
}

/*!
Ejemplo:
\code
Ventana.AdoptarHijo(Boton1.Elemento() );
\endcode
*/
IGUIElement* GDT::Gui::GuiBase::Elemento ( void )
{
	return guiele;
}

/*!
Ejemplo:
\code
Ventana.AdoptarHijo(Boton1.Elemento() );
\endcode
*/
void GDT::Gui::GuiBase::AdoptarHijo ( IGUIElement* hijo )
{
	guiele->addChild ( hijo );
}

/*!
Ejemplo:
\code
Boton.Destruir();
\endcode
*/
void GDT::Gui::GuiBase::Destruir ( void )
{
	guiele->remove();
}

//Retornos *****************************************************
//**************************************************************

position2d<s32> GDT::Gui::GuiBase::Posicion()
{
	return guiele->getRelativePosition().UpperLeftCorner;
}
int GDT::Gui::GuiBase::PosicionX()
{
	return ( int ) Posicion().X;
}
int GDT::Gui::GuiBase::PosicionY()
{
	return ( int ) Posicion().Y;
}
position2d<s32> GDT::Gui::GuiBase::Centro()
{
	return guiele->getRelativePosition().getCenter();
}
int GDT::Gui::GuiBase::CentroX()
{
	return ( int ) Centro().X;
}
int GDT::Gui::GuiBase::CentroY()
{
	return ( int ) Centro().Y;
}
dimension2d<s32> GDT::Gui::GuiBase::Tamanio()
{
	return guiele->getRelativePosition().getSize();
}
int GDT::Gui::GuiBase::Ancho()
{
	return ( int ) guiele->getRelativePosition().getWidth();
}
int GDT::Gui::GuiBase::Alto()
{
	return ( int ) guiele->getRelativePosition().getHeight();
}
position2d<s32> GDT::Gui::GuiBase::EsquinaSuperiorIzquierda()
{
	return guiele->getRelativePosition().UpperLeftCorner;
}
int GDT::Gui::GuiBase::EsquinaSuperiorIzquierdaX()
{
	return ( int ) EsquinaSuperiorIzquierda().X;
}
int GDT::Gui::GuiBase::EsquinaSuperiorIzquierdaY()
{
	return ( int ) EsquinaSuperiorIzquierda().Y;
}
position2d<s32> GDT::Gui::GuiBase::EsquinaInferiorDerecha()
{
	return guiele->getRelativePosition().LowerRightCorner;
}
int GDT::Gui::GuiBase::EsquinaInferiorDerechaX()
{
	return ( int ) EsquinaInferiorDerecha().X;
}
int GDT::Gui::GuiBase::EsquinaInferiorDerechaY()
{
	return ( int ) EsquinaInferiorDerecha().Y;
}
bool GDT::Gui::GuiBase::EsPuntoInterno ( position2d<s32> punto )
{
	return guiele->getRelativePosition().isPointInside ( punto );
}
bool GDT::Gui::GuiBase::EsPuntoInterno ( int x,int y )
{
	return EsPuntoInterno ( position2d<s32> ( x,y ) );
}
bool GDT::Gui::GuiBase::Colision ( rect<s32> Rectangulo )
{
	return guiele->getRelativePosition().isRectCollided ( Rectangulo );
}
bool GDT::Gui::GuiBase::Colision ( IGUIElement* guiElemento )
{
	return Colision ( guiElemento->getRelativePosition() );
}
///--------------------------------------------------------------


