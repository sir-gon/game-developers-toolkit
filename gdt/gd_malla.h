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

#ifndef GD_MALLA_H
#define GD_MALLA_H

//#include "gd_nodo.h" // inheriting class's header file
#include "gd_colisiones3d.h"

//EXPORTAR SIMBOLOS AL CREAR DLL
#ifndef _GDT_EXPORT_
  #ifdef WIN32
	#ifdef _GDT_DLL_
	   #define _GDT_EXPORT_ __declspec(dllexport)
	#else /* Not _GDT_DLL_ */
	   #define _GDT_EXPORT_ __declspec(dllimport)
	#endif /* Not _GDT_DLL_ */
  #else
// SINO, DEFINIR COMO NULO EL EXPORTADOR 
    #define _GDT_EXPORT_ /* Definido nulo */
  #endif  /* WIN32 */
#endif /* _GDT_EXPORT_ */

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



//!Carga y manipula una Malla (Mesh)
/*!

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
	_GDT_EXPORT_ GD_Malla();
	// class destructor
	_GDT_EXPORT_ ~GD_Malla();
	
	IAnimatedMesh* mesh;
	IMesh* static_mesh;
	IMesh* tangentMesh;
	ISceneNode* nodo_tangentes;
	IAnimatedMeshSceneNode *nodoAM;
	
	int Tipo_Esc;
	bool controlani;
	irr::scene::EMD2_ANIMATION_TYPE old_aniTipoActual;
	int old_ini,old_fin;
	
	//! Carga una malla animada o est&aacute;tica.
	_GDT_EXPORT_ void Cargar(char *filename);
	//! Carga un malla est&aacute;tica y genera sus tangentes.
	_GDT_EXPORT_ void CargarTangentes(char *filename);
	
	//! Crea una caja
	_GDT_EXPORT_ void CrearCaja();
	//! Crea una Caja (paralelep&iacute;pedo)
	_GDT_EXPORT_ void CrearCaja(float tamx, float tamy, float tamz );
	//! Crea un cubo
	_GDT_EXPORT_ void CrearCubo(); // Obsoleto
	//! Crea un cubo
	_GDT_EXPORT_ void CrearCubo(float tamx, float tamy, float tamz );
	//! Crea un Plano
	_GDT_EXPORT_ void CrearPlano( int tx, int ty );
	//! Crea un Cilindro
	_GDT_EXPORT_ void CrearCilindro( int tx, int ty, f32 radio  );
	//! Crea un Cono
	_GDT_EXPORT_ void CrearCono( int tx, int ty, f32 radio  );
	//! Crea una Esfera
	_GDT_EXPORT_ void CrearEsfera( float radio, int polynum = 16 );
	
	//! Remplaza el nodo de una clase que hereda de GD_Nodo
	_GDT_EXPORT_ void Reemplazar(ISceneNode* nod_R);
	//! Retorna el nodo de un hueso especifico
	_GDT_EXPORT_ ISceneNode* RetornarNodoHuesoX(c8* Nombre );
	//! Retorna el nodo de un hueso especifico
	_GDT_EXPORT_ ISceneNode* RetornarNodoHuesoMS3D(c8* Nombre );
	//! Devuelve el cuadro de la animacion.
	_GDT_EXPORT_ int RetornarCuadro();
	//! Establece la velocidad de la animacion de la malla.
	_GDT_EXPORT_ void VelocidadAnimacion(int CuadrosPorSegundo);
	//! Establece el cuadro actual de la animacion
	_GDT_EXPORT_ void CuadroActual(int cuadro);
	//! Establece el ciclo de animaci&oacute;n
	_GDT_EXPORT_ void CicloCuadros(int ini, int fin);
	//! Establece el ciclo de animaci&oacute;n para los modelos MD2 de quake
	_GDT_EXPORT_ void CicloMD2(irr::scene::EMD2_ANIMATION_TYPE );
	//! Cambia la aniamaci&oacute;n a modo ciclo
	_GDT_EXPORT_ void Repeticion(bool enCiclo);
	//! Evita que la animacion se reinicie cada vez que se llama
	_GDT_EXPORT_ void ControlAnimacion(bool control);

	//! Activa la generaci&oacute;n de sombras proyectadas de la malla.
	_GDT_EXPORT_ void ProyectarSombra();

	_GDT_EXPORT_ void CalibrarColisionConEscenario(float x, float y, float z);
	_GDT_EXPORT_ void CalibrarColisionConEscenarioX(float x, float y, float z);
	_GDT_EXPORT_ void CalibrarColisionConEscenarioY(float x, float y, float z);
	_GDT_EXPORT_ void CalibrarColisionConEscenarioZ(float x, float y, float z);
	

};

#endif // GD_MALLA_H
