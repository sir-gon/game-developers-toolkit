// Class automatically generated by Dev-C++ New Class wizard

#ifndef GD_PARTICULA_H
#define GD_PARTICULA_H

#include "gd_nodo.h" // inheriting class's header file
#include "gd_escenario.h"

// No description
class GD_Particula : public GD_Nodo
{
	public:
		// class constructor
		GD_Particula();
		// class destructor
		~GD_Particula();
		
		IParticleSystemSceneNode* nodpt;
		
		void Crear(float x, float y, float z, float dx, float dy, float dz, int minparsec, int maxparsec, int tiempodevidamin, int tiempodevidamax, int maxang, char* filename);
		void Escalar(float x,float y);
		
		void CrearColision( GD_Escenario scen,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz);
};

#endif // GD_PARTICULA_H
