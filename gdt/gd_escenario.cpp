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
* \class GDT::Nodo::Escenario
*/

#include "gd_escenario.h" // class's header file

// class constructor
GDT::Nodo::Escenario::Escenario()
{
	// insert your code here
}

// class destructor
GDT::Nodo::Escenario::~Escenario()
{
	// insert your code here
}

void GDT::Nodo::Escenario::CargarBSP(char *filenamePK3, char *filenameBSP)
{
	RegistrarDevice(Sistema::device);
	ISceneManager* mismgr=Sistema::device->getSceneManager();
	
	midevice->getFileSystem()->addZipFileArchive(filenamePK3);
		
	mesh = mismgr->getMesh(filenameBSP);
		
	if (mesh)
		nodon = mismgr->addOctTreeSceneNode(mesh->getMesh(0));
		
		if(!nodon) printf("ERROR: No se pudo Cargar El Escenario BSP, %s en el paquete %s.\n", filenameBSP ,filenamePK3 );
		
	selector = mismgr->createOctTreeTriangleSelector(mesh->getMesh(0), nodon);
	nodon->setTriangleSelector(selector);
	//selector->drop();
}

void GDT::Nodo::Escenario::Cargar(char *filename)
{
	RegistrarDevice(Sistema::device);
	ISceneManager* mismgr=Sistema::device->getSceneManager();
	
	IAnimatedMesh* mesha = mismgr->getMesh(filename);
	meshs = mesha->getMesh(0); 
	
	nodon = mismgr->addOctTreeSceneNode(meshs);
	if(!nodon) printf("ERROR: No se pudo Cargar El Escenario, %s.\n", filename);     
		
		selector = mismgr->createOctTreeTriangleSelector(meshs, nodon);
		nodon->setTriangleSelector(selector);  
	
	ColorDifuso(100,100,100);
}

ITriangleSelector* GDT::Nodo::Escenario::RetornarDatos()
{
     return selector;
}
