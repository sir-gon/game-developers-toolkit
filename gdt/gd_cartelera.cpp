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
* \class GDT::Nodo::Cartelera
* Las Carteleras son im&aacute;genes 2D que no importando desde donde las
* apunte la c&aacute;mara (en el espacio 3D), siempre se ven de la misma forma.
* 
* Si la c&aacute;mara rota, la imagen se seguir&aacute; viendo de frente.
* 
* Son &uacute;tiles para agregar elementos en el escenario como 
* &aacute;rboles o resplandores.
* 
* \image html cartelera.png
*/
#include "gd_cartelera.h" // class's header file

// class constructor
GDT::Nodo::Cartelera::Cartelera()
{
	// insert your code here
}

// class destructor
GDT::Nodo::Cartelera::~Cartelera()
{
	// insert your code here
}

/*!
* \param tamx,tamy son el tama� de la im�en.
* \param filename la ruta al archivo im�en para la textura.
* 
* \image html cartelera.png
* 
* Ejemplo:
* \code
* Resplandor.Crear( 10, 10, "lampara.bmp" );
* \endcode
*/
void GDT::Nodo::Cartelera::Crear(float tamx, float tamy, char* filename)
{
    
    RegistrarDevice(Sistema::device);
    ISceneManager* mismgr=Sistema::device->getSceneManager();


    
     nodb = mismgr->addBillboardSceneNode(0, core::dimension2d<f32>(tamx, tamy));
	 
	 nodon = nodb;
  
     if(!nodon) printf("ERROR: No se pudo Crear Cartelera.\n");
	  
	 nodon->setMaterialFlag(video::EMF_LIGHTING, false);
	 nodon->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
	 
	 Texturizar(filename);	 
}

void GDT::Nodo::Cartelera::CrearColision( Escenario scen,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz)
{

    ITriangleSelector* selector = scen.RetornarDatos();

    ISceneManager* mismgr=midevice->getSceneManager();

	scene::ISceneNodeAnimator* anim = mismgr->createCollisionResponseAnimator(
		selector, nodon, core::vector3df(radiox,radioy,radioz),
		core::vector3df(transx,transy,transz),
		core::vector3df(grax,gray,graz));
	nodon->addAnimator(anim);
	//anim->drop();
}
