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

#ifndef GD_TERRENO_H
#define GD_TERRENO_H

#include "gd_nodo.h" // inheriting class's header file

// No description
class GD_Terreno : public GD_Nodo
{
	public:
		// class constructor
		GD_Terreno();
		// class destructor
		~GD_Terreno();
		
		ITerrainSceneNode* nodt;
          
          void Crear(char *filenameHMAP,float x, float y, float z);
          ITriangleSelector* selector;
          ITriangleSelector* RetornarDatos();
          
          void Texturizar(char *filenameTEX);
};

#endif // GD_TERRENO_H
