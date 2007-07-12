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
* \class GD_GuiImagen
*
* Usa una imagen como Control GUI, lo cual nos permite desplegar
* contenidos de imagen, logotipos, alertas, o lo que sea importante
* mostrar al usuario que no satisfaga el simple texto.
*/

#include "gd_guiimagen.h" // class's header file

// class constructor
GD_GuiImagen::GD_GuiImagen()
{
	// insert your code here
}

// class destructor
GD_GuiImagen::~GD_GuiImagen()
{
	// insert your code here
}

/*!
Los formatos soportados son:

    -  Adobe Photoshop (.psd)
    - JPEG File Interchange Format (.jpg)
    - Portable Network Graphics (.png)
    - Truevision Targa (.tga)
    - Windows Bitmap (.bmp)
    - Zsoft Paintbrush (.pcx)
    -  Adobe Photoshop (.psd)
    - JPEG File Interchange Format (.jpg)
    - Portable Network Graphics (.png)
    - Truevision Targa (.tga)
    - Windows Bitmap (.bmp)
    - Zsoft Paintbrush (.pcx)
*/
void GD_GuiImagen::Cargar(char *filename)
{

    RegistrarDevice(GD_Sistema::device);

    driver = midevice->getVideoDriver();
    guienv = midevice->getGUIEnvironment();

    //irr::core::dimension2d< s32 > tam;
    //irr::video::ITexture* textura;

    textura=driver->getTexture(filename);

    tam = textura->getOriginalSize();

    // printf("TAMX = %d, TAMY = %d",tam.Width, tam.Height);

  //  int tamx = tam.Width+40;
  //  int tamy = tam.Height+2;
  //
//	img = guienv->addImage(rect<s32>(0,0,tam.Width,tam.Height));
//	img->setImage(textura);

	img = guienv->addImage(driver->getTexture(filename),core::position2d<s32>(5,5));


    guiele=img;
}

/*!
\param uso true para activar el canal alpha, false para desactivarlo

Ejemplo:
\code
Imagen.UsarCanalAlpha(true);
\endcode
*/
void GD_GuiImagen::UsarCanalAlpha(bool uso)
{
    img->setUseAlphaChannel(uso);
}

