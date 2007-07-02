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

//! Manejador de Nodos
/**
 * Funciones del espacio comunes entre los objetos
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
        //! Le asigna una posici&oacute;n en el espacio 3D
        void Posicionar(float x, float y, float z);
        //! Le asigna una posici&oacute;n en el espacio 3D, recibe como par&aacute;metro un vector.
        void Posicionar(vector3df pos);
        //! Le asigna la posici&oacute;n en X conservando la posici&oacute;n actual en Y y Z
        void PosicionarX(float x);
        //! Le asigna la posici&oacute;n en Y conservando la posici&oacute;n actual en X y Z
        void PosicionarY(float y);
        //! Le asigna la posici&oacute;n en Z conservando la posici&oacute;n actual en X y Y
        void PosicionarZ(float z);
        //! Retorna un vector con la posici&oacute;n actual.
        vector3df Posicion();
        //! Devuelve la posicion X actual del nodo
        float PosicionX();
        //! Devuelve la posicion Y actual del nodo
        float PosicionY();
        //! Devuelve la posicion Z actual del nodo
        float PosicionZ();
        //! Asigna la rotaci&oacute;n del nodo, en grados.
        void Rotar(float x, float y, float z);
        //! Asigna la rotaci&oacute;n del nodo, en grados. Recibe como par&aacute;metro un vector.
        void Rotar(vector3df rot);
        //! Le asigna la rotaci&oacute;n en X conservando la rotaci&oacute;n actual en Y y Z, en grados
        void RotarX(float x);
        //! Le asigna la rotaci&oacute;n en Y conservando la rotaci&oacute;n actual en X y Z, en grados
        void RotarY(float y);
        //! Le asigna la rotaci&oacute;n en Z conservando la rotaci&oacute;n actual en X y Y, en grados
        void RotarZ(float z);
        //! Retorna un vector con la rotaci&oacute;n actual.
        vector3df Rotacion();
        //! Devuelve la rotacion X actual
        float RotacionX();
        //! Devuelve la rotacion Y actual
        float RotacionY();
        //! Devuelve la rotacion Z actual
        float RotacionZ();
        //! Cambia el tama&ntilde;o del nodo en X,Y,Z
        void Escalar(float x, float y, float z);
        //! Cambia el tama&ntilde;o del nodo en X,Y,Z. Recibe como par&aacute;metro un vector.
        void Escalar(vector3df esc);
        //! Cambia el tama&ntilde;o en X (ancho), conservando el tama&ntilde;o actual en Y y Z
        void EscalarX(float x);
        //! Cambia el tama&ntilde;o en Y (largo), conservando el tama&ntilde;o actual en X y Z
        void EscalarY(float y);
        //! Cambia el tama&ntilde;o en Z (alto), conservando el tama&ntilde;o actual en Y y X
        void EscalarZ(float z);
        //! Mueve el nodo segun su orientacion actual.
        void Mover(float x, float y, float z);
        //! Mueve el nodo segun su orientacion actual en X (izquierda,derecha)
        void MoverX(float x);
        //! Mueve el nodo segun su orientacion actual en Y (arriba,abajo)
        void MoverY(float y);
        //! Mueve el nodo segun su orientacion actual en Z (frente,atras)
        void MoverZ(float z);
	//! Gira el nodo segun su orientacion actual en X,Y,Z
        void Girar(float x, float y, float z);
	//! Gira el nodo segun su orientacion actual en X
        void GirarX(float x);
	//! Gira el nodo segun su orientacion actual en Y
        void GirarY(float y);
	//! Gira el nodo segun su orientacion actual en Z
        void GirarZ(float z);

	//! Orienta el nodo hacia otro.
        vector3df Orientar(GD_Nodo gdnodito);
	//! Orienta el nodo hacia un vector.
        vector3df Orientar(vector3df destino);
	//! Orienta el nodo hacia las coordenadas X, Y, Z.
	vector3df Orientar(float x, float y, float z);

	//! Retorna un vector con el tama&ntilde;o actual.
        vector3df Tamano();
	//! Retorna la tama&ntilde;o en X, es decir el ancho
        float TamanoX();
	//! Retorna la tama&ntilde;o en Y, es decir el alto
        float TamanoY();
	//! Retorna la tama&ntilde;o en Z, es decir el largo
        float TamanoZ();

	//! Aplica una textura al nodo, en base a una imagen
        void Texturizar(char *filename, int capa=-1);
	//! Aplica una textura al nodo, en base a un objeto GD_Textura
        void Texturizar(GD_Textura textu, int capa=-1);

	//! Activa o desactiva un material de renderizado
        void MaterialFlag(E_MATERIAL_FLAG cual, bool enable);
	//! Cambia el tipo de material de renderizado
        void MaterialTipo(E_MATERIAL_TYPE cual);
	//! Establece el relieve del material
        void MaterialRelieve(float alt=0.035);

        s32 coloralphaA, coloralphaD, coloralphaEm, coloralphaE;

	//! Establece la forma como refleja el color de ambiente
        void ColorAmbiente( s32 r,s32 g,s32 b, int capa = -1);
	//! Establece el color difuso
        void ColorDifuso( s32 r,s32 g,s32 b, int capa = -1);
	//! Establece el color emisivo
        void ColorEmisivo(s32 r,s32 g,s32 b, int capa = -1);
	//! Establece la forma como refleja el color especular o brillo
        void ColorEspecular( s32 r,s32 g,s32 b, int capa = -1); 

	//! Destruye el nodo
        void Destruir(void);

	//!Ajusta el nivel transparencia de un nodo.
        void NivelTransparencia(s32 v);

	//! Establece la visibilidad del nodo
        void Visible(bool estado);
	//! Comprueba si el nodo actualmente es visible o no
        bool EsVisible();

	//! Le ancla un nodo
        void Anclar(GD_Nodo gdnodito);
	//! Desancla un nodo previamente anclado.
        void DesAnclar(GD_Nodo gdnodito);

        //! Crea una respuesta de colisi&oacute;n.
	void CrearColision(ITriangleSelector* selector, float RadioX, float RadioY, float RadioZ, float GravedadX, float GravedadY, float GravedadZ, float TraslacionX, float TraslacionY, float TraslacionZ);

};

#endif // GD_NODO_H
