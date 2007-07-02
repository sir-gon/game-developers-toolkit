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

#include "gd_terreno.h" // class's header file

// class constructor
GD_Terreno::GD_Terreno()
{
	// insert your code here
}

// class destructor
GD_Terreno::~GD_Terreno()
{
	// insert your code here
}


void GD_Terreno::Crear(char *filenameHMAP,float x, float y, float z)
{
     
    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=midevice->getSceneManager();
    
    IVideoDriver* driver = midevice->getVideoDriver();
    
	nodt = mismgr->addTerrainSceneNode( filenameHMAP,0,-1, vector3df(0,0,0),vector3df(0,0,0),vector3df(x,y/3,z));

		     
     selector = mismgr->createTerrainTriangleSelector(nodt,0);
	nodt->setTriangleSelector(selector);
	
  nodon =nodt;
    if(!nodon) printf("ERROR: No se pudo Crear Terreno, %s.\n", filenameHMAP); 
     
}

ITriangleSelector* GD_Terreno::RetornarDatos()
{
     return selector;
}

void GD_Terreno::Texturizar(char *filenameTEX)
{
    
     IVideoDriver* driver = midevice->getVideoDriver();
        
     driver->setTextureCreationFlag(video::ETCF_ALWAYS_32_BIT, true);
     driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);
     
     nodt->setMaterialTexture(0, driver->getTexture(filenameTEX));
     
     driver->setTextureCreationFlag(video::ETCF_ALWAYS_32_BIT, false);
     driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);
}
