// Class automatically generated by Dev-C++ New Class wizard

#ifndef GD_TEXTURA_H
#define GD_TEXTURA_H


#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


#include "gd_sistema.h"
/*
 * No description
 */
class GD_Textura
{
	public:
		// class constructor
		GD_Textura();
		// class destructor
		~GD_Textura();
		
        IrrlichtDevice *mi_device;
		
		ITexture* tex;
		
		void Cargar(char* filename);
		
		ITexture* Textura();
		
		void GenerarMapaNormales(float amplitud=1.0);

};

#endif // GD_TEXTURA_H