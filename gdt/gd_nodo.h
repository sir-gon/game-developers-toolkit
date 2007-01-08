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

#ifndef GD_NODO_H
#define GD_NODO_H

#include <irrlicht.h>


#include "gd_sistema.h"
#include "gd_sistemamatematicas.h"
#include "gd_textura.h"


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

/**
 * Funciones comunes entre los objetos
 */
class GD_Nodo
{
	public:
		// class constructor
		GD_Nodo();
		// class destructor
		~GD_Nodo();
	
	
	IrrlichtDevice *midevice;
	ISceneManager* mesh_smgr;
	ISceneNode* nodon;
	ISceneNodeAnimator* anim;
	
	ISceneNodeAnimatorCollisionResponse* colision;
	
	
	ISceneNode* intersec_coli_a;
	ISceneNode* intersec_coli_b;
	ISceneNode* intersec_coli_c;
	ISceneNode* intersec_coli_d;
	ISceneNode* intersec_coli_e;
	ISceneNode* intersec_coli_f;
	
	
	void RegistrarDevice(	IrrlichtDevice *device );
	
	
		void Posicionar(float x, float y, float z);
	void Posicionar(vector3df pos);
		void PosicionarX(float x);
		void PosicionarY(float y);
		void PosicionarZ(float z);
		vector3df Posicion();
		float PosicionX();
		float PosicionY();
		float PosicionZ();
	void Rotar(float x, float y, float z);
	void Rotar(vector3df rot);            
		void RotarX(float x);
		void RotarY(float y);
		void RotarZ(float z);
		vector3df Rotacion();
		float RotacionX();
		float RotacionY();
		float RotacionZ();
	void Escalar(float x, float y, float z);
	void Escalar(vector3df esc);
		void EscalarX(float x);
		void EscalarY(float y);
		void EscalarZ(float z);
	void Mover(float x, float y, float z);
		void MoverX(float x);
		void MoverY(float y);
		void MoverZ(float z);
	void Girar(float x, float y, float z);
		void GirarX(float x);
		void GirarY(float y);
		void GirarZ(float z);
		
	vector3df Orientar(vector3df destino);
	vector3df Orientar(GD_Nodo gdnodito);
	
	vector3df Tamano();
	float TamanoX();
	float TamanoY();
	float TamanoZ();
	
	
	void Texturizar(char *filename, int capa=-1);
	void Texturizar(GD_Textura textu, int capa=-1);
	
	void MaterialFlag(E_MATERIAL_FLAG cual, bool enable);
	void MaterialTipo(E_MATERIAL_TYPE cual);
	
	void MaterialRelieve(float alt=0.035);
	
	s32 coloralphaA, coloralphaD, coloralphaEm, coloralphaE;
	
	// agregado por Habatar
	void ColorAmbiente( s32 r,s32 g,s32 b, int capa = -1);
	void ColorDifuso( s32 r,s32 g,s32 b, int capa = -1);
	void ColorEmisivo(s32 r,s32 g,s32 b, int capa = -1);
	void ColorEspecular( s32 r,s32 g,s32 b, int capa = -1); 
	
	void Destruir(void);
	
	void NivelTransparencia(s32 v);
	
	void Visible(bool estado);
	bool EsVisible();
	
	void Anclar(GD_Nodo gdnodito);
	void DesAnclar(GD_Nodo gdnodito);
	
	void CrearColision( ITriangleSelector* selector,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz);


};

#endif // GD_NODO_H
