// Class automatically generated by Dev-C++ New Class wizard

#include "gd_textura.h" // class's header file

// class constructor
GD_Textura::GD_Textura()
{
	// insert your code here
}

// class destructor
GD_Textura::~GD_Textura()
{
	// insert your code here
}


void GD_Textura::Cargar(char* filename)
{
   mi_device = GD_Sistema::device;
     
   tex = GD_Sistema::device->getVideoDriver()->getTexture(filename);
}


ITexture* GD_Textura::Textura()
{
   return tex;
}

void GD_Textura::GenerarMapaNormales(float amplitud)
{
     mi_device->getVideoDriver()->makeNormalMapTexture(tex, amplitud);

} 

