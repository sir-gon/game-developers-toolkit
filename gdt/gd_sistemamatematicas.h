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

#ifndef GD_MATEMATICAS_H
#define GD_MATEMATICAS_H


#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <irrlicht.h>


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


/**
 * Sistema de Matemática
 */
class GD_SistemaMatematicas
{
	public:
		// class constructor
		GD_SistemaMatematicas();
		// class destructor
		~GD_SistemaMatematicas();

	double FastCos[361];
	double FastSin[361];
	double FastTan[361];
	
	void Inicializar();
	int Capar(int);
	double Capar(double);
	double Coseno(int);
	double Seno(int);
	double Coseno(double);
	double Seno(double);
	int Azar(int,int);
	double Azar(double, double);
	double Raiz(double);
	double Angulo(double, double, double, double);
	double Distancia(double, double, double, double);
	double Distancia3d(double, double, double, double, double, double);
	double GiroAngulo(double, double);
	double PI();
	double E();
	double Tangente(int);
	double Tangente(double);
	double SenoHyperbolico(double);
	double CosenoHyperbolico(double);
	double TangenteHyperbolica(double);
	double ArcoSeno(double);
	double ArcoCoseno(double);
	double ArcoTangente(double);
	double Exponencial(double);
	double Logaritmo(double);
	double Logaritmo10(double);
	double Potencia(double, double);
	int RedondearArriba(double);
	int RedondearAbajo(double);
	int Redondear(double);
	int Entero(double);
	int Absoluto(int);
	double Absoluto(double);
	double CurvarValor(double, double, double);
	double CurvarAngulo(double, double, double);
	double MueveX(double, double, double);
	double MueveY(double, double, double);
	double MueveZ(double z, double angulo, double velocidad);
	char Rango(double, double, double,char);
	double BuscarNormal(double, double, double);
	vector3df Seguir( vector3df PosicionEntrada1, float anguloY,vector3df PosicionEntrada2, float distancia,float altura,float angulo, float dureza);
	float Rad(float Deg);
	
	// POSICION ********************************************************
	double WrapValue(double Angulo);
	//Regresa el nuevo valor del valor de la ordenadas X,Y,Z (segun el caso)
	//segun un angulo y una distancia dadas.
	double NewXValue(double dXActual,double dAngulo,double dDistancia);
	double NewYValue(double dYActual,double dAngulo,double dDistancia);
	double NewZValue(double dZActual,double dAngulo,double dDistancia);
	//******************************************************************

};

#endif // GD_MATEMATICAS_H
