// Class automatically generated by Dev-C++ New Class wizard

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
