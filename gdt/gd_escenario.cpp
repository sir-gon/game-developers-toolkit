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


#include "gd_escenario.h" // class's header file

// class constructor
GD_Escenario::GD_Escenario()
{
	// insert your code here
}

// class destructor
GD_Escenario::~GD_Escenario()
{
	// insert your code here
}

void GD_Escenario::CargarBSP(char *filenamePK3, char *filenameBSP)
{
    
        
    
    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=GD_Sistema::device->getSceneManager();

        
     midevice->getFileSystem()->addZipFileArchive(filenamePK3);
		
      mesh = mismgr->getMesh(filenameBSP);
          	
          	   
	if (mesh)
	    nodon = mismgr->addOctTreeSceneNode(mesh->getMesh(0));
	    

          	
		selector = mismgr->createOctTreeTriangleSelector(mesh->getMesh(0), nodon);
		nodon->setTriangleSelector(selector);
		//selector->drop();
	
    
     	

}

void GD_Escenario::Cargar(char *filename)
{
           
     
    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=GD_Sistema::device->getSceneManager();

     IAnimatedMesh* mesha = mismgr->getMesh(filename);
     meshs = mesha->getMesh(0); 
     
     nodon = mismgr->addOctTreeSceneNode(meshs);
	    
		selector = mismgr->createOctTreeTriangleSelector(meshs, nodon);
		nodon->setTriangleSelector(selector);  
	
	ColorDifuso(100,100,100);
}

ITriangleSelector* GD_Escenario::RetornarDatos()
{
     return selector;
}
