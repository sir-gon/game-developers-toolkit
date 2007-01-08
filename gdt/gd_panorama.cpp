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

	mismgr->getVideoDriver()->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);
}


void GD_Panorama::CrearDomo(char* texturadomo, int hres, int vres, int texporc, int esfporc)
{
    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=GD_Sistema::device->getSceneManager();

    float texpor = texporc/100;
    float esfpor = esfporc/50;    
    
    if(texpor>1) texpor=1;
    if(esfpor>2) texpor=2;
    

    mismgr->getVideoDriver()->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);

	nodon = mismgr->addSkyDomeSceneNode(mismgr->getVideoDriver()->getTexture(texturadomo), 
                                        hres,
                                        vres,
                                        texpor,
                                        esfpor);

	mismgr->getVideoDriver()->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);


}
