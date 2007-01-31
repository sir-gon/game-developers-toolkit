/*///////////////////////////////////////////////////////////////////

GD_Agua 

Este archivo hace parte de GDT Game Developers Toolkit.
Para informacion de distribucion o uso dirigase a el archivo gdt.h
o en la web http://www.gdtoolkit.8m.net

*////////////////////////////////////////////////////////////////////

#ifndef GD_AGUA_H
#define GD_AGUA_H

#include "gd_nodo.h" // inheriting class's header file

// No description
class GD_Agua : public GD_Nodo
{
	public:
		// class constructor
		GD_Agua();
		// class destructor
		~GD_Agua();

	scene::IAnimatedMesh* mesh; // Malla que contiene el plano
		
    void CrearNormal(float x, float y, int nx, int ny,int tx,int ty,f32 AlturaOnda,f32 VelocidadOnda, f32 LongitudOnda, char* t);
    void CrearRealista(float x, float y, int nx, int ny,int tx,int ty,f32 AlturaOnda,f32 VelocidadOnda, f32 LongitudOnda, char* t1, char* t2);
};

#endif // GD_AGUA_H
