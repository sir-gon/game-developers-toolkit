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
#include "gd_matematicas.h"
#include "gd_textura.h"
#include "gd_animador.h"

/* No documentar */
#ifndef _GDT_DOXYGEN_IGNORAR_
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
#endif /* _GDT_DOXYGEN_IGNORAR_ */

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

namespace GDT
{

namespace Nodo
{

//! Controla un objeto en el espacio (un Nodo)
class NodoBase
{
public:
	// class constructor
	_GDT_EXPORT_ NodoBase();
	// class destructor
	_GDT_EXPORT_ ~NodoBase();

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

        // para arreglar bug en gd_luz 
        float  mi_posicion_x;
        float  mi_posicion_y;
        float  mi_posicion_z; 
	
	_GDT_EXPORT_ void RegistrarDevice(	IrrlichtDevice *device );
	//! Le asigna una posici&oacute;n en el espacio 3D
	_GDT_EXPORT_ void Posicionar(float x, float y, float z);
	//! Le asigna una posici&oacute;n en el espacio 3D, recibe como par&aacute;metro un vector.
	_GDT_EXPORT_ void Posicionar(vector3df pos);
	//! Le asigna la posici&oacute;n en X conservando la posici&oacute;n actual en Y y Z
	_GDT_EXPORT_ void PosicionarX(float x);
	//! Le asigna la posici&oacute;n en Y conservando la posici&oacute;n actual en X y Z
	_GDT_EXPORT_ void PosicionarY(float y);
	//! Le asigna la posici&oacute;n en Z conservando la posici&oacute;n actual en X y Y
	_GDT_EXPORT_ void PosicionarZ(float z);
	//! Retorna un vector con la posici&oacute;n actual.
	_GDT_EXPORT_ vector3df Posicion();
	//! Devuelve la posicion X actual del nodo
	_GDT_EXPORT_ float PosicionX();
	//! Devuelve la posicion Y actual del nodo
	_GDT_EXPORT_ float PosicionY();
	//! Devuelve la posicion Z actual del nodo
	_GDT_EXPORT_ float PosicionZ();
	//! Asigna la rotaci&oacute;n del nodo, en grados.
	_GDT_EXPORT_ void Rotar(float x, float y, float z);
	//! Asigna la rotaci&oacute;n del nodo, en grados. Recibe como par&aacute;metro un vector.
	_GDT_EXPORT_ void Rotar(vector3df rot);
	//! Le asigna la rotaci&oacute;n en X conservando la rotaci&oacute;n actual en Y y Z, en grados
	_GDT_EXPORT_ void RotarX(float x);
	//! Le asigna la rotaci&oacute;n en Y conservando la rotaci&oacute;n actual en X y Z, en grados
	_GDT_EXPORT_ void RotarY(float y);
	//! Le asigna la rotaci&oacute;n en Z conservando la rotaci&oacute;n actual en X y Y, en grados
	_GDT_EXPORT_ void RotarZ(float z);
	//! Retorna un vector con la rotaci&oacute;n actual.
	_GDT_EXPORT_ vector3df Rotacion();
	//! Devuelve la rotacion X actual
	_GDT_EXPORT_ float RotacionX();
	//! Devuelve la rotacion Y actual
	_GDT_EXPORT_ float RotacionY();
	//! Devuelve la rotacion Z actual
	_GDT_EXPORT_ float RotacionZ();
	//! Cambia el tama&ntilde;o del nodo en X,Y,Z
	_GDT_EXPORT_ void Escalar(float x, float y, float z);
	//! Cambia el tama&ntilde;o del nodo en X,Y,Z. Recibe como par&aacute;metro un vector.
	_GDT_EXPORT_ void Escalar(vector3df esc);
	//! Cambia el tama&ntilde;o en X (ancho), conservando el tama&ntilde;o actual en Y y Z
	_GDT_EXPORT_ void EscalarX(float x);
	//! Cambia el tama&ntilde;o en Y (largo), conservando el tama&ntilde;o actual en X y Z
	_GDT_EXPORT_ void EscalarY(float y);
	//! Cambia el tama&ntilde;o en Z (alto), conservando el tama&ntilde;o actual en Y y X
	_GDT_EXPORT_ void EscalarZ(float z);
	//! Mueve el nodo segun su orientacion actual.
	_GDT_EXPORT_ void Mover(float x, float y, float z);
	//! Mueve el nodo segun su orientacion actual en X (izquierda,derecha)
	_GDT_EXPORT_ void MoverX(float x);
	//! Mueve el nodo segun su orientacion actual en Y (arriba,abajo)
	_GDT_EXPORT_ void MoverY(float y);
	//! Mueve el nodo segun su orientacion actual en Z (frente,atras)
	_GDT_EXPORT_ void MoverZ(float z);
	//! Gira el nodo segun su orientacion actual en X,Y,Z
	_GDT_EXPORT_ void Girar(float x, float y, float z);
	//! Gira el nodo segun su orientacion actual en X
	_GDT_EXPORT_ void GirarX(float x);
	//! Gira el nodo segun su orientacion actual en Y
	_GDT_EXPORT_ void GirarY(float y);
	//! Gira el nodo segun su orientacion actual en Z
	_GDT_EXPORT_ void GirarZ(float z);
	
	//! Orienta el nodo hacia otro.
	_GDT_EXPORT_ vector3df Orientar(NodoBase gdnodito);
	//! Orienta el nodo hacia un vector.
	_GDT_EXPORT_ vector3df Orientar(vector3df destino);
	//! Orienta el nodo hacia las coordenadas X, Y, Z.
	_GDT_EXPORT_ vector3df Orientar(float x, float y, float z);
	
	//! Retorna un vector con el tama&ntilde;o actual.
	_GDT_EXPORT_ vector3df Tamano();
	//! Retorna la tama&ntilde;o en X, es decir el ancho
	_GDT_EXPORT_ float TamanoX();
	//! Retorna la tama&ntilde;o en Y, es decir el alto
	_GDT_EXPORT_ float TamanoY();
	//! Retorna la tama&ntilde;o en Z, es decir el largo
	_GDT_EXPORT_ float TamanoZ();
	
	//! Aplica una textura al nodo, en base a una imagen
	_GDT_EXPORT_ void Texturizar(char *filename, int capa=-1);
	//! Aplica una textura al nodo, en base a un objeto Textura
	_GDT_EXPORT_ void Texturizar(Textura textu, int capa=-1);
	
	//! Activa o desactiva un material de renderizado
	_GDT_EXPORT_ void MaterialFlag(E_MATERIAL_FLAG cual, bool enable);
	//! Cambia el tipo de material de renderizado
	_GDT_EXPORT_ void MaterialTipo(E_MATERIAL_TYPE cual);
	//! Establece el relieve del material
	_GDT_EXPORT_ void MaterialRelieve(float alt=0.035);
	
	s32 coloralphaA, coloralphaD, coloralphaEm, coloralphaE;
	
	//! Establece la forma como refleja el color de ambiente
	_GDT_EXPORT_ void ColorAmbiente( s32 r,s32 g,s32 b, int capa = -1);
	//! Establece el color difuso
	_GDT_EXPORT_ void ColorDifuso( s32 r,s32 g,s32 b, int capa = -1);
	//! Establece el color emisivo
	_GDT_EXPORT_ void ColorEmisivo(s32 r,s32 g,s32 b, int capa = -1);
	//! Establece la forma como refleja el color especular o brillo
	_GDT_EXPORT_ void ColorEspecular( s32 r,s32 g,s32 b, int capa = -1); 
	//! Establece cuanta region de la malla se ve afectada con brillo
        _GDT_EXPORT_ void Brillo(float intensidad);

	//! Destruye el nodo
	_GDT_EXPORT_ void Destruir(void);
	
	//!Ajusta el nivel transparencia de un nodo.
	_GDT_EXPORT_ void NivelTransparencia(s32 v, int capa = -1);
	
	//! Establece la visibilidad del nodo
	_GDT_EXPORT_ void Visible(bool estado);
	//! Comprueba si el nodo actualmente es visible o no
	_GDT_EXPORT_ bool EsVisible();
	
	//! Le ancla un nodo
	_GDT_EXPORT_ void Anclar(NodoBase gdnodito);
	//! Desancla un nodo previamente anclado.
	_GDT_EXPORT_ void DesAnclar(NodoBase gdnodito);
	
	//! Crea una respuesta de colisi&oacute;n.
	_GDT_EXPORT_ void CrearColision(ITriangleSelector* selector, float RadioX, float RadioY, float RadioZ, float GravedadX, float GravedadY, float GravedadZ, float TraslacionX, float TraslacionY, float TraslacionZ);
	
	//! Devuelve los valores de los colores
	// para las luces no funcionan estos metodos asi que las luces
	// tienen sus propios metodos con el mismo nombre
	_GDT_EXPORT_ int RetornarColorAmbienteR();
	_GDT_EXPORT_ int RetornarColorAmbienteG();
	_GDT_EXPORT_ int RetornarColorAmbienteB(); 
	_GDT_EXPORT_ int RetornarColorEmisivoR();
	_GDT_EXPORT_ int RetornarColorEmisivoG();
	_GDT_EXPORT_ int RetornarColorEmisivoB();
	_GDT_EXPORT_ int RetornarColorDifusoR();
	_GDT_EXPORT_ int RetornarColorDifusoG();
	_GDT_EXPORT_ int RetornarColorDifusoB();                
	_GDT_EXPORT_ int RetornarColorEspecularR();
	_GDT_EXPORT_ int RetornarColorEspecularG();
	_GDT_EXPORT_ int RetornarColorEspecularB();    
	
	_GDT_EXPORT_ int RetornarBrillo();
	
	_GDT_EXPORT_ void AgregarAnimador(Animador Animate);
};

} // FIN NAMESPACE NODO

} // FIN NAMESPACE GDT

#endif // GD_NODO_H
