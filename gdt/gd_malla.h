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

#ifndef GD_MALLA_H
#define GD_MALLA_H

//#include "gd_nodo.h" // inheriting class's header file
#include "gd_colisiones3d.h"

#define STAND EMAT_STAND
#define RUN EMAT_RUN
#define ATTACK EMAT_ATTACK
#define PAIN_A EMAT_PAIN_A
#define PAIN_B EMAT_PAIN_B
#define PAIN_C EMAT_PAIN_C
#define JUMP EMAT_JUMP
#define FLIP EMAT_FLIP
#define SALUTE EMAT_SALUTE
#define FALLBACK EMAT_FALLBACK
#define WAVE EMAT_WAVE
#define POINT EMAT_POINT
#define CROUCH_STAND EMAT_CROUCH_STAND
#define CROUCH_WALK EMAT_CROUCH_WALK 
#define CROUCH_ATTACK EMAT_CROUCH_ATTACK
#define CROUCH_PAIN EMAT_CROUCH_PAIN 
#define CROUCH_DEATH EMAT_CROUCH_DEATH
#define DEATH_FALLBACK EMAT_DEATH_FALLBACK
#define EMAT_DEATH_FALLFORWARD DEATH_FALLFORWARD
#define EMAT_DEATH_FALLBACKSLOW DEATH_FALLBACKSLOW
#define EMAT_BOOM BOOM


/**
 * Mallas
 */
class GD_Malla :  public GD_Colisiones3d  //public GD_Nodo,
{
   private:

      void RegistrarVelAni(int va);
	  IMesh* DibujarCubo();
	  IMesh* DibujarPlano(int gridX=25, int gridY=25);
	  IMesh* DibujarCilindro(int gridX=25, int gridY=25,f32 ridus=1);
	  IMesh* DibujarCono(int gridX=25, int gridY=25,f32 ridus=1);	  
	  IMesh* DibujarEsfera();
      int velani;

	public:

		// class constructor
		GD_Malla();
		// class destructor
		~GD_Malla();

	
	IAnimatedMesh* mesh;
	IMesh* static_mesh;
	IMesh* tangentMesh;
	ISceneNode* nodo_tangentes;  
	IAnimatedMeshSceneNode *nodoAM;
	
	int Tipo_Esc; 
	bool controlani;
	irr::scene::EMD2_ANIMATION_TYPE old_aniTipoActual;
	int old_ini,old_fin;
	
	
	void Cargar(char *filename);
	void CargarTangentes(char *filename);
	
	void CrearCubo( );
	void CrearCubo(float tamx, float tamy, float tamz );
	void CrearPlano( int tx, int ty );
	void CrearCilindro( int tx, int ty, f32 radio  );
	void CrearCono( int tx, int ty, f32 radio  );
	void CrearEsfera( float radio, int polynum = 16 );
	
	void Reemplazar(ISceneNode* nod_R);
	ISceneNode* RetornarNodoHuesoX(c8* Nombre );
	ISceneNode* RetornarNodoHuesoMS3D(c8* Nombre );
	
	int RetornarCuadro();
	void VelocidadAnimacion(int CuadrosPorSegundo);
	void CuadroActual(int cuadro);
	void CicloCuadros(int ini, int fin);
	void CicloMD2(irr::scene::EMD2_ANIMATION_TYPE );
	void Repeticion(bool enCiclo);
	void ControlAnimacion(bool control); // evita que la animacion se reinicie cada vez que se llama
	
	void ProyectarSombra();
		
	void CalibrarColisionConEscenario(float x, float y, float z);
	void CalibrarColisionConEscenarioX(float x, float y, float z);
	void CalibrarColisionConEscenarioY(float x, float y, float z);
	void CalibrarColisionConEscenarioZ(float x, float y, float z); 


};

#endif // GD_MALLA_H
