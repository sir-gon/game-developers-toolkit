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

#ifndef GD_CAMARA_H
#define GD_CAMARA_H

#include "gd_nodo.h" // inheriting class's header file
#include "gd_escenario.h"
#include "gd_matematicas.h"

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

//! Controlador de C&aacute;mara
/*!
Crea y maneja las c&aacute;maras. Permite manejarlas por teclado o mouse, orientarlas a gusto y darles el comportamiento que la aplicaci&oacute;n requiera.

Por ejemplo, nos permite dejar la c&aacute;mara detr&aacute;s de un personaje para juegos de tercera persona, o puede ser de primera persona.
*/
class GD_Camara : public GD_Nodo
{
   private:
		double distancia;
	public:
		// class constructor
		_GDT_EXPORT_ GD_Camara();
		// class destructor
		_GDT_EXPORT_ ~GD_Camara();
		
		int miID;
		
		GD_Matematicas SisMat;

		ICameraSceneNode* nodc;
		//! Crea una C&aacute;mara
		_GDT_EXPORT_ void Crear(int tipo=Tipo_Normal);
		//! Establece la posici&oacute;n hacia donde la c&aacute;mara debe mirar.
		_GDT_EXPORT_ void Orientar(float x, float y, float z);
		//! Establece la posici&oacute;n hacia donde la c&aacute;mara debe mirar.
		_GDT_EXPORT_ void Orientar(vector3df destino);

		//! Retorna la distancia mas lejana hasta donde renderizara
		_GDT_EXPORT_ double Profundidad();
		//! Establece la distancia mas lejana hasta donde renderizara
		_GDT_EXPORT_ void Profundidad(float rango);
		
		// establece el viewport
		//_GDT_EXPORT_ void AreaRender(int x1, int y1, int x2, int y2);
		
		// Si se rendereiza con esta camara
		//_GDT_EXPORT_ void Activada(bool opc);
		
		//****************************
		//! Devuelve el vector hacia el que esta orientada la c&aacute;mara
		_GDT_EXPORT_ vector3df RetornarObjetivo();
		//! Posiciona la camara detras de un punto en el espacio con suavizado
		_GDT_EXPORT_ vector3df Seguir(vector3df PosicionEntrada1, 
					float anguloY,
					vector3df PosicionEntrada2,
					float distancia,
					float altura,
					float angulo=180,
					float durezaX=15,
					float durezaY=15/8,
					float durezaZ=15);

		//! Posiciona la c&aacute;mara para que "persiga" a un punto
		_GDT_EXPORT_ void Perseguir(vector3df PosicionEntrada1, float anguloY,double distancia,double altura,double angulo,  float durezaX, float durezaY, float durezaZ);
		//! Posiciona la c&aacute;mara para que "persiga" a un objeto
		_GDT_EXPORT_ void Perseguir(GD_Nodo nodoncio,double distancia, double altura, double angulo, float durezaX, float durezaY, float durezaZ);
		//! Posiciona la c&aacute;mara para que "persiga" a un objeto
		_GDT_EXPORT_ void Perseguir(GD_Nodo nodoncio,double distancia, double altura, double angulo, double dureza);

		// COMPATIBILIDAD HACIA ATRAS
		//! Posiciona la c&aacute;mara para que "persiga" a un punto
		_GDT_EXPORT_ void Perseguir(vector3df PosicionEntrada1, float anguloY, double distancia, double altura, double angulo, double dureza);	
		//! Posiciona la c&aacute;mara para que "persiga" a un objeto
		_GDT_EXPORT_ void Perseguir(GD_Nodo nodoncio, double distancia, double altura, double angulo);
		// FIN COMPATIBILIDAD HACIA ATRAS

		_GDT_EXPORT_ void CrearColision( GD_Escenario scen,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz);

};

#endif // GD_CAMARA_H
