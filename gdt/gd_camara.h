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

#ifndef GD_CAMARA_H
#define GD_CAMARA_H

#include "gd_nodo.h" // inheriting class's header file
#include "gd_escenario.h"

/**
* Camara
*/
class GD_Camara : public GD_Nodo
{
   private:
      double distancia;
	public:
		// class constructor
		GD_Camara();
		// class destructor
		~GD_Camara();
		
		int miID;

          ICameraSceneNode* nodc;
          void Crear(int tipo=Tipo_Normal);

          void Orientar(float x, float y, float z);
          void Orientar(vector3df poso);

         //Profundidad de camara
          double Profundidad();
          void Profundidad(float rango);
          
          // establece el viewport
  //        void AreaRender(int x1, int y1, int x2, int y2);
          
          // Si se rendereiza con esta camara
      //    void Activada(bool opc);
          
          //****************************

          vector3df RetornarObjetivo();
          


        float Rad(float Deg);
        int Capar(int);
        double Capar(double);
        double GiroAngulo(double, double);
        double CurvarValor(double, double, double);
        double CurvarAngulo(double, double, double);
        double MueveX(double, double, double);
        double MueveY(double, double, double);
        double MueveZ(double z, double angulo, double velocidad);

        vector3df Seguir(vector3df PosicionEntrada1, float anguloY,vector3df PosicionEntrada2, float distancia,float altura,float angulo=180, float dureza=15);
        
        void Perseguir(vector3df PosicionEntrada1, float anguloY,double distancia,double altura,double angulo, double dureza);
        void Perseguir(GD_Nodo nodoncio,double distancia,double altura,double angulo, double dureza);
        
        void CrearColision( GD_Escenario scen,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz);
        


};

#endif // GD_CAMARA_H
