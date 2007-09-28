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

#include "gd_textura.h" // class's header file

/*!
*/
GDT::Textura::Textura()
{
	// insert your code here
}

/*!
*/
GDT::Textura::~Textura()
{
	// insert your code here
}

/*!
*/
void GDT::Textura::Cargar ( char* filename )
{
	mi_device = Sistema::device;

	tex = Sistema::device->getVideoDriver()->getTexture ( filename );
}


/*!
*/
ITexture* GDT::Textura::RetornarTextura()
{
	return tex;
}

/*!
*/
void GDT::Textura::GenerarMapaNormales ( float amplitud )
{
	mi_device->getVideoDriver()->makeNormalMapTexture ( tex, amplitud );

}

