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
* \class GDPanorama
*
* Un Panorama es la cubierta que podemos darle al escenario, para reemplazar
* el color plano que presenta por defecto.
*
* El Panorama puede ser de 2 tipos, Domo o Cubo.
*/
#include "gd_panorama.h" // class's header file

// class constructor
GD_Panorama::GD_Panorama()
{
	// insert your code here
}

// class destructor
GD_Panorama::~GD_Panorama()
{
	// insert your code here
}

/*!
\param up ruta a imagen de la Cara Superior
\param down ruta a imagen de la Cara Inferior
\param left ruta a imagen de la Cara Izquierda
\param right ruta a imagen de la Cara Derecha
\param front ruta a imagen de la Cara Frontal
\param back ruta a imagen de la Cara Trasera

Ejemplo:
\code
CieloCubo.CrearCubico(
	"media/cara_superior.jpg",
	"media/cara_inferior.jpg",
	"media/cara_izquierda.jpg",
	"media/cara_derecha.jpg",
	"media/cara_frontal.jpg",
	"media/cara_trasera.jpg");
\endcode
*/
void GD_Panorama::CrearCubico(char* up, char* down, char* left, char* right, char* front,char* back)
{
    
    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=GD_Sistema::device->getSceneManager();



     mismgr->getVideoDriver()->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);

	nodon = mismgr->addSkyBoxSceneNode(
		mismgr->getVideoDriver()->getTexture(up),
		mismgr->getVideoDriver()->getTexture(down),
		mismgr->getVideoDriver()->getTexture(left),
		mismgr->getVideoDriver()->getTexture(right),
		mismgr->getVideoDriver()->getTexture(front),
		mismgr->getVideoDriver()->getTexture(back));
		
    if(!nodon) printf("ERROR: No se pudo Crear Panorama Cubico.\n"); 

	mismgr->getVideoDriver()->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);
	
	
}

/*!
\param texturadomo Es la imagen que cubre el domo.
\param hres
\param vres
\param texporc
\param esfporc

Ejemplo:
\code
CieloDomo.CrearDomo("../media/panorama/domin.jpg",13,13,100,100);
\endcode
*/
void GD_Panorama::CrearDomo(char* texturadomo, int hres, int vres, int texporc, int esfporc)
{
    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=GD_Sistema::device->getSceneManager();

    float texpor = (float)texporc/100;
    float esfpor = (float)esfporc/50;    
    
    if(texpor>1) texpor=1;
    if(esfpor>2) texpor=2;
    

    mismgr->getVideoDriver()->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);

	nodon = mismgr->addSkyDomeSceneNode(mismgr->getVideoDriver()->getTexture(texturadomo), 
                                        hres,
                                        vres,
                                        texpor,
                                        esfpor);

    if(!nodon) printf("ERROR: No se pudo Crear Panorama Domo.\n"); 


	mismgr->getVideoDriver()->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);


}
