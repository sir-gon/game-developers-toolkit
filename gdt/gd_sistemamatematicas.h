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

#ifndef GD_MATEMATICAS_H
#define GD_MATEMATICAS_H

#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <irrlicht.h>
#include <stdlib.h>
#include <string.h>
#include "gd_sistema.h"

/* No documentar */
#ifndef _GDT_DOXYGEN_IGNORAR_
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
#endif /* _GDT_DOXYGEN_IGNORAR_ */


// HACK PARA EXPORTAR SIMBOLOS EN DLL COMPILADOS CON VISUAL C++ 2005
#ifndef _GDT_EXPORT_
  #ifdef _GDT_VC_STUDIO_2005_
   #define _GDT_EXPORT_ __declspec(dllexport)
  #else
    #define _GDT_EXPORT_
  #endif
#endif

//! C&aacute;lculos Matem&aacute;ticos
class GD_SistemaMatematicas
{
public:
	//! [Constructor] Inicializa el Sistema de matem&aacute;ticas
	GD_SistemaMatematicas();
	// class destructor
	~GD_SistemaMatematicas();
	
	
	double FastCos[361];
	double FastSin[361];
	double FastTan[361];
	
	//void Inicializar();
	_GDT_EXPORT_ int Capar(int);
	_GDT_EXPORT_ double Capar(double);
	
	// CONSTANTES UNIVERSALES
	//! Retorna la constante "Pi"
	_GDT_EXPORT_ double PI();
	//! Retorna la constante "e" (o base del logaritmo natural)
	_GDT_EXPORT_ double E();
	
	// FUNCIONES TRIGONOMETRICAS
	//! Calcula el Seno del &aacute;ngulo entero dado
	_GDT_EXPORT_ double Seno(int);
	//! Calcula el Seno del &aacute;ngulo dado
	_GDT_EXPORT_ double Seno(double);
	//! Calcula el Coseno del &aacute;ngulo entero dado
	_GDT_EXPORT_ double Coseno(int);
	//! Calcula el Coseno del &aacute;ngulo dado
	_GDT_EXPORT_ double Coseno(double);
	//! Calcula la Tangente del &aacute;ngulo entero dado
	_GDT_EXPORT_ double Tangente(int);
	//! Calcula la Tangente del &aacute;ngulo dado
	_GDT_EXPORT_ double Tangente(double);
	
	// FUNCIONES BASICAS
	//! Retorna el m&iacute;nimo entre 2 valores
	_GDT_EXPORT_ int Minimo(int, int);
	//! Retorna el m&iacute;nimo entre 2 valores
	_GDT_EXPORT_ double Minimo(double, double);
	//! Retorna el m&aacute;ximo entre 2 valores
	_GDT_EXPORT_ int Maximo(int, int);
	//! Retorna el m&aacute;ximo entre 2 valores
	_GDT_EXPORT_ double Maximo(double, double);
	//! Redondea hacia arriba un n&uacute;mero
	_GDT_EXPORT_ int RedondearArriba(double);
	//! Redondea hacia abajo un n&uacute;mero
	_GDT_EXPORT_ int RedondearAbajo(double);
	//! Redondea aplicando la regla habitual de redondeo.
	_GDT_EXPORT_ int Redondear(double);
	//! Convierte un n&uacute;mero real a entero
	_GDT_EXPORT_ int Entero(double);
	//! Retorna el Valor Absoluto de un n&uacute;mero entero
	_GDT_EXPORT_ int Absoluto(int);
	//! Retorna el Valor Absoluto de un n&uacute;mero real
	_GDT_EXPORT_ double Absoluto(double);
	
	// PROBABILIDAD
	//! Retorna un n&uacute;mero entero pseudoaleatorio en el intervalo entre el m&iacute;nimo y m&aacute;ximo dado
	_GDT_EXPORT_ int Azar(int,int);
	//! Retorna un n&uacute;mero decimal pseudoaleatorio en el intervalo entre el m&iacute;nimo y m&aacute;ximo dado
	_GDT_EXPORT_ double Azar(double, double);
	
	// RECTAS
	//! Calcula el &aacute; que forma la recta que une 2 puntos con el eje X
	_GDT_EXPORT_ double Angulo(double, double, double, double);
	//! Calcula la distancia entre 2 puntos en un plano (2 dimensiones)
	_GDT_EXPORT_ double Distancia(double, double, double, double);
	//! Calcula la distancia entre 2 puntos en el espacio (3 dimensiones)
	_GDT_EXPORT_ double Distancia3d(double, double, double, double, double, double);
	_GDT_EXPORT_ double GiroAngulo(double, double);
	
	// POTENCIAS Y RAICES
	//! Retorna la ra&iacute;z cuadrada de un n&uacute;mero
	_GDT_EXPORT_ double Raiz(double);
	//! Calcula la potencia de x elevado a y.
	_GDT_EXPORT_ double Potencia(double, double);
	
	// FUNCIONES EXPONENCIALES Y LOGARITMICAS
	//! Calcula la Exponencial de x. La base es "e".
	_GDT_EXPORT_ double Exponencial(double);
	//! Calcula el valor de la funci&oacute;n logaritmo natural de un n&uacute;mero.
	_GDT_EXPORT_ double Logaritmo(double);
	//! Calcula el valor de la funci&oacute;n logaritmo base 10 de un n&uacute;mero.
	_GDT_EXPORT_ double Logaritmo10(double);
	
	// FUNCIONES HIPERBOLICAS
	//! Calcula el Seno Hiperb&oacute;lico de un n&uacute;mero.
	_GDT_EXPORT_ double SenoHyperbolico(double);
	//! Calcula el Coseno Hiperb&oacute;lico de un n&uacute;mero: f(x) = ( e^x + e^(-x) ) / 2
	_GDT_EXPORT_ double CosenoHyperbolico(double);
	_GDT_EXPORT_ double TangenteHyperbolica(double);
	
	// FUNCIONES TRIGONOMETRICAS INVERSAS
	//! Funci&oacute;n inversa del Seno(). ArcoSeno( Seno (x) ) = x;
	_GDT_EXPORT_ double ArcoSeno(double);
	//! Funci&oacute;n inversa del Coseno(). ArcoCoseno( Coseno (x) ) = x;
	_GDT_EXPORT_ double ArcoCoseno(double);
	//! Funci&oacute;n inversa de la Tangente(). ArcoTangente( Tangente (x) ) = x;
	_GDT_EXPORT_ double ArcoTangente(double);
	//! Calcula el valor de la funci&oacute;n exponencial de un n&uacute;mero. f(x) = e^x
	
	_GDT_EXPORT_ float CurvarValor(float, float, float);
	_GDT_EXPORT_ double CurvarAngulo(double, double, double);
	_GDT_EXPORT_ double MueveX(double, double, double);
	_GDT_EXPORT_ double MueveY(double, double, double);
	_GDT_EXPORT_ double MueveZ(double z, double angulo, double velocidad);
	
	// INTERVALO
	//! Comprueba si un número pertecene al Intervalo.
	_GDT_EXPORT_ char Rango(double, double, double,char);
	//! Comprueba si un número pertecene al Intervalo Abierto.
	_GDT_EXPORT_ char RangoAbierto(double, double, double);
	//! Comprueba si un número pertecene al Intervalo Cerrado.
	_GDT_EXPORT_ char RangoCerrado(double, double, double);
	
	_GDT_EXPORT_ double BuscarNormal(double, double, double);
	vector3df Seguir( vector3df PosicionEntrada1, float anguloY,vector3df PosicionEntrada2, float distancia,float altura,float angulo, float dureza);
	
	//! Convierte grados sexagesimales a radianes.
	_GDT_EXPORT_ double Rad(double);

	// POSICION ********************************************************
	_GDT_EXPORT_ double WrapValue(double Angulo);
	//Regresa el nuevo valor del valor de la ordenadas X,Y,Z (segun el caso)
	//segun un angulo y una distancia dadas.
	_GDT_EXPORT_ double NewXValue(double dXActual,double dAngulo,double dDistancia);
	_GDT_EXPORT_ double NewYValue(double dYActual,double dAngulo,double dDistancia);
	_GDT_EXPORT_ double NewZValue(double dZActual,double dAngulo,double dDistancia);
	//******************************************************************

	
};

#endif // GD_MATEMATICAS_H
