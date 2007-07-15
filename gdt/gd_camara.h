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
#include "gd_sistemamatematicas.h"

//EXPORTAR SIMBOLOS AL CREAR DLL
#ifndef _GDT_EXPORT_
  #ifdef WIN32
	#ifdef BUILDING_DLL
	   #define _GDT_EXPORT_ __declspec (dllexport)
	#else /* Not BUILDING_DLL */
	   #define _GDT_EXPORT_ __declspec (dllimport)
	#endif /* Not BUILDING_DLL */
  #else
// SINO, DEFINIR COMO NULO EL EXPORTADOR 
    #define _GDT_EXPORT_ /* Definido nulo */
  #endif  /* WIN32 */
#endif /* _GDT_EXPORT_ */

//! Controlador de C&aacute;mara
class _GDT_EXPORT_ GD_Camara : public GD_Nodo
{
   private:
		double distancia;
	public:
		// class constructor
		GD_Camara();
		// class destructor
		~GD_Camara();
		
		int miID;
		
		GD_SistemaMatematicas SisMat;

		ICameraSceneNode* nodc;
		//! Crea una C&aacute;mara
		void Crear(int tipo=Tipo_Normal);
		//! Establece la posición hacia donde la cámara debe mirar.
		void Orientar(float x, float y, float z);
		//! Establece la posición hacia donde la cámara debe mirar.
		void Orientar(vector3df destino);

		//! Retorna la distancia mas lejana hasta donde renderizara
		double Profundidad();
		//! Establece la distancia mas lejana hasta donde renderizara
		void Profundidad(float rango);
		
		// establece el viewport
		//void AreaRender(int x1, int y1, int x2, int y2);
		
		// Si se rendereiza con esta camara
		//void Activada(bool opc);
		
		//****************************
		//! Devuelve el vector hacia el que esta orientada la cámara
		vector3df RetornarObjetivo();
		//! Posiciona la camara detras de un punto en el espacio con suavizado
		vector3df Seguir(vector3df PosicionEntrada1, 
					float anguloY,
					vector3df PosicionEntrada2,
					float distancia,
					float altura,
					float angulo=180,
					float durezaX=15,
					float durezaY=15/8,
					float durezaZ=15);

		//! Posiciona la cámara para que "persiga" a un punto
		void Perseguir(vector3df PosicionEntrada1, float anguloY,double distancia,double altura,double angulo,  float durezaX, float durezaY, float durezaZ);
		//! Posiciona la cámara para que "persiga" a un objeto
		void Perseguir(GD_Nodo nodoncio,double distancia, double altura, double angulo, float durezaX, float durezaY, float durezaZ);
		//! Posiciona la cámara para que "persiga" a un objeto
		void Perseguir(GD_Nodo nodoncio,double distancia, double altura, double angulo, double dureza);

		// COMPATIBILIDAD HACIA ATRAS
		//! Posiciona la cámara para que "persiga" a un punto
		void Perseguir(vector3df PosicionEntrada1, float anguloY, double distancia, double altura, double angulo, double dureza);	
		//! Posiciona la cámara para que "persiga" a un objeto
		void Perseguir(GD_Nodo nodoncio, double distancia, double altura, double angulo);
		// FIN COMPATIBILIDAD HACIA ATRAS

		void CrearColision( GD_Escenario scen,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz);

};

#endif // GD_CAMARA_H
