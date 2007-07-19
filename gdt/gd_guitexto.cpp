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
* \class GD_GuiTexto
*
* Este Control GUI permite desplegar Texto por la pantalla.
* Usese para mostrar alertas, mensajes, o para lo que sea conveniente.
*/

#include "gd_guitexto.h" // class's header file

// class constructor
GD_GuiTexto::GD_GuiTexto()
{
	// insert your code here
}

// class destructor
GD_GuiTexto::~GD_GuiTexto()
{
	// insert your code here
}

void GD_GuiTexto::Crear(int x1, int y1, int x2, int y2, wchar_t * texto, bool borde, bool wordWrap,	IGUIElement *padre)
{

    RegistrarDevice(GD_Sistema::device);

    IVideoDriver* driver = midevice->getVideoDriver();
    IGUIEnvironment* guienv = midevice->getGUIEnvironment();

	guitexto = guienv->addStaticText(texto, rect<s32>(x1,y1,x2,y2), borde,wordWrap, padre);

	Multilinea(true);

	guiele=guitexto;

	iX=x1; iY=y1; iAlto=x2; iAncho=y2; // Dimenciones del recuadro


}


/*!
\param x1,y1 posici&oacute;n del texto.
\param x2,y2 posici&oacute;n hasta la que llega el texto.
\param texto es el texto del Control GUI.
\param padre

Ejemplo:
Texto.Crear( 10, 5 , 40, 15, L"Leeme");
*/
void GD_GuiTexto::Crear(int x1, int y1, int x2, int y2, wchar_t * texto, IGUIElement *padre)
{

    RegistrarDevice(GD_Sistema::device);

    IVideoDriver* driver = midevice->getVideoDriver();
    IGUIEnvironment* guienv = midevice->getGUIEnvironment();

	guitexto = guienv->addStaticText(texto, rect<s32>(x1,y1,x2,y2), false,true, padre);
	Multilinea(true);

	iX=x1; iY=y1; iAlto=x2; iAncho=y2; // Dimenciones del recuadro
}

/*!
\param r,g,b colores Azul, Verde y Rojo, de 0 a 255.
\param a Transparencia alpha, de 0 a 255.

Ejemplo:
Texto.Color(255,0,0,255);
*/
void GD_GuiTexto::Color(int r, int g, int b,int a)
{
	guitexto->setOverrideColor(SColor( a, r, g, b));
}

/*!
\param fontname ruta al archivo de la fuente. Debe ser un bitmap de caracteres.

\since 13-04-2006
\author Astucia 
*/
void GD_GuiTexto::AsignarFuente(const char fontname[1024])
{

   guienv=midevice->getGUIEnvironment();  //Obtiene el entorno del GUI

   fuente = guienv->getFont((const c8*)fontname);//Asigna el nuevo archivo bmp que contiene la nueva fuente

   if(fuente!=0)     //Si la fuente se encuentra, entonces la asigna al objeto de texto
   {
      guitexto->setOverrideFont(fuente);
      szfuente=(wchar_t*) fontname;
   }
   else           //Si la fuente no se puede cargar, entonces utiliza la fuente por defecto
      fuente=guienv->getBuiltInFont();
}

void GD_GuiTexto::AsignarFuente(wchar_t * fontname) ///NUEVO
{

   guienv=midevice->getGUIEnvironment();  //Obtiene el entorno del GUI

   fuente = guienv->getFont((const c8*)fontname);//Asigna el nuevo archivo bmp que contiene la nueva fuente

   if(fuente!=0)     //Si la fuente se encuentra, entonces la asigna al objeto de texto
   {
      guitexto->setOverrideFont(fuente);
      szfuente=fontname;
   }
   else           //Si la fuente no se puede cargar, entonces utiliza la fuente por defecto
      fuente=guienv->getBuiltInFont();
}

/*!
\note Tambi&eacute;n se puede obtener el nombre mediante la propiedad wchar_t* szfuente
*/
wchar_t* GD_GuiTexto::FuenteEnUso()
{
   return szfuente;
}

/*!
*/
void GD_GuiTexto::Texto(const wchar_t *text,int x, int y,int ancho,int alto)
{
   core::position2d<s32> posicionXY;   //estructura de coordenadas XY
   core::dimension2d<s32> dimencionXY; //estructura de dimenciones Alto-Ancho
   core::rect< s32 > caja;             //estructura de caja o rectangulo(rect)

   guitexto->setText(text);   //Inserta el texto al texto estatico

   posicionXY= core::position2d< s32 >(x,y); //asigna la posicion en pantalla
   dimencionXY= core::dimension2d< s32 >(ancho,alto);  //Calcula el tama&ntilde;o del texto a mostrar
   caja= core::rect< s32 >(posicionXY,dimencionXY);   //Engloba los datos en una estructura
   guitexto->setRelativePosition(caja);   //Coloca el texto segun las coordenadas y
                                          //Configura el modo en que se muestra el texto en pantalla

}

/*!
*/
void GD_GuiTexto::Texto(const wchar_t *text,int x, int y)
{
   core::position2d<s32> posicionXY;   //estructura de coordenadas XY
   core::dimension2d<s32> dimencionXY; //estructura de dimenciones Alto-Ancho
   core::rect< s32 > caja;             //estructura de caja o rectangulo(rect)

   guitexto->setText(text);   //Inserta el texto al texto estatico

   posicionXY= core::position2d< s32 >(x,y); //asigna la posicion en pantalla
   dimencionXY=core::dimension2d<s32>(iAlto,iAncho);  //Calcula el tama&ntilde;o del texto a mostrar
   caja= core::rect< s32 >(posicionXY,dimencionXY);   //Engloba los datos en una estructura
   guitexto->setRelativePosition(caja);   //Coloca el texto segun las coordenadas y
                                          //Configura el modo en que se muestra el texto en pantalla

}

/*!
*/
void GD_GuiTexto::TextoCentrado(const wchar_t *text,int x,int y,int ancho,int alto)
{
   core::position2d<s32> posicionXY;   //estructura de coordenadas XY
   core::dimension2d<s32> dimencionXY; //estructura de dimenciones Alto-Ancho
   core::rect< s32 > caja;             //estructura de caja o rectangulo(rect)

   guitexto->setText(text);   //Inserta el texto al texto estatico


   dimencionXY= core::dimension2d< s32 >(ancho,alto);  //Calcula el tama&ntilde;o del texto a mostrar
   posicionXY= core::position2d< s32 >((int)x-(dimencionXY.Width/2),(int)y-(dimencionXY.Height/2)); //asigna la posicion en pantalla
   caja= core::rect< s32 >(posicionXY,dimencionXY);   //Engloba los datos en una estructura
   guitexto->setRelativePosition(caja);   //Coloca el texto segun las coordenadas y
                                          //Configura el modo en que se muestra el texto en pantalla

}

/*!
*/
void GD_GuiTexto::TextoCentrado(const wchar_t *text,int x,int y)
{
   core::position2d<s32> posicionXY;   //estructura de coordenadas XY
   core::dimension2d<s32> dimencionXY; //estructura de dimenciones Alto-Ancho
   core::rect< s32 > caja;             //estructura de caja o rectangulo(rect)

   guitexto->setText(text);   //Inserta el texto al texto estatico


   dimencionXY=core::dimension2d<s32>(iAlto,iAncho);  //Calcula el tama&ntilde;o del texto a mostrar
   posicionXY= core::position2d< s32 >((int)x-(dimencionXY.Width/2),(int)y-(dimencionXY.Height/2)); //asigna la posicion en pantalla
   caja= core::rect< s32 >(posicionXY,dimencionXY);   //Engloba los datos en una estructura
   guitexto->setRelativePosition(caja);   //Coloca el texto segun las coordenadas y
                                          //Configura el modo en que se muestra el texto en pantalla

}

/*!
*/
int GD_GuiTexto::PosicionX()
{
   core::rect<s32> caja;
   caja = guitexto->getRelativePosition();
   return caja.UpperLeftCorner.X;

}

/*!
*/
int GD_GuiTexto::PosicionY()
{
   core::rect<s32> caja;
   caja = guitexto->getRelativePosition();
   return caja.UpperLeftCorner.Y;

}

/*!
*/
void GD_GuiTexto::Posicionar(position2d<s32> pos)
{
   core::rect<s32> caja;
   caja = guitexto->getRelativePosition();
   caja.UpperLeftCorner=pos;
   guitexto->setRelativePosition(caja);
}

/*!
*/
void GD_GuiTexto::Posicionar(int x,int y)
{
   core::rect<s32> caja;
   caja = guitexto->getRelativePosition();
   caja.UpperLeftCorner.X=x;
   caja.UpperLeftCorner.Y=y;
   guitexto->setRelativePosition(caja);
}

/*!
*/
int GD_GuiTexto::AnchoDelTexto()
{
   int Ancho=0;
   core::rect<s32> caja;
   caja = guitexto->getRelativePosition();
   Ancho=(int)caja.LowerRightCorner.X-caja.UpperLeftCorner.X;
   return Ancho;

}

/*!
*/
int GD_GuiTexto::AltoDelTexto()
{
   int Alto=0;
   core::rect<s32> caja;
   caja = guitexto->getRelativePosition();
   Alto=(int)caja.LowerRightCorner.Y-caja.UpperLeftCorner.Y;
   return Alto;
}

/*!
*/
void GD_GuiTexto::Multilinea(bool activar)
{
   guitexto->setWordWrap(activar);
}


void GD_GuiTexto::Visible(bool visible)
{
      guitexto->setVisible(visible);
}


bool GD_GuiTexto::EsVisible()
{
      return guitexto->isVisible();
}

