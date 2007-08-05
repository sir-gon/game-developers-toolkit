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

//! C&aacute;lculos Matem&aacute;ticos
class GD_Matematicas
{
public:
	//! Arreglo con los cosenos de los 360 &aacute;ngulos
	_GDT_EXPORT_ static double FastCos[360];
	//! Arreglo con los senos de los 360 &aacute;ngulos
	_GDT_EXPORT_ static double FastSin[360];
	//! Arreglo con las tangentes de los 360 &aacute;ngulos
	_GDT_EXPORT_ static double FastTan[360];

	//! Inicializa los c&aacute;lculos trigonom&eacute;tricos y de n&uacute; pseudo-aleatorios
	_GDT_EXPORT_ static bool Inicializar();
	//! Convierte el n&uacute;mero entero de grados a uno perteneciente al rango [0-359]
	_GDT_EXPORT_ static int Grados(int);
	//! Convierte el n&uacute;mero real de grados a uno perteneciente al rango [0-359]
	_GDT_EXPORT_ static double Grados(double);

	// CONSTANTES UNIVERSALES
	//! Retorna la constante "Pi"
	_GDT_EXPORT_ static double PI();
	//! Retorna la constante "e" (o base del logaritmo natural)
	_GDT_EXPORT_ static double E();
	
	// FUNCIONES TRIGONOMETRICAS
	//! Calcula el Seno del &aacute;ngulo entero dado
	_GDT_EXPORT_ static double Seno(int);
	//! Calcula el Seno del &aacute;ngulo dado
	_GDT_EXPORT_ static double Seno(double);
	//! Calcula el Coseno del &aacute;ngulo entero dado
	_GDT_EXPORT_ static double Coseno(int);
	//! Calcula el Coseno del &aacute;ngulo dado
	_GDT_EXPORT_ static double Coseno(double);
	//! Calcula la Tangente del &aacute;ngulo entero dado
	_GDT_EXPORT_ static double Tangente(int);
	//! Calcula la Tangente del &aacute;ngulo dado
	_GDT_EXPORT_ static double Tangente(double);
	
	// FUNCIONES BASICAS
	//! Retorna el m&iacute;nimo entre 2 valores
	_GDT_EXPORT_ static int Minimo(int, int);
	//! Retorna el m&iacute;nimo entre 2 valores
	_GDT_EXPORT_ static double Minimo(double, double);
	//! Retorna el m&aacute;ximo entre 2 valores
	_GDT_EXPORT_ static int Maximo(int, int);
	//! Retorna el m&aacute;ximo entre 2 valores
	_GDT_EXPORT_ static double Maximo(double, double);
	//! Redondea hacia arriba un n&uacute;mero
	_GDT_EXPORT_ static int RedondearArriba(double);
	//! Redondea hacia abajo un n&uacute;mero
	_GDT_EXPORT_ static int RedondearAbajo(double);
	//! Redondea aplicando la regla habitual de redondeo.
	_GDT_EXPORT_ static int Redondear(double);
	//! Convierte un n&uacute;mero real a entero
	_GDT_EXPORT_ static int Entero(double);
	//! Retorna el Valor Absoluto de un n&uacute;mero entero
	_GDT_EXPORT_ static int Absoluto(int);
	//! Retorna el Valor Absoluto de un n&uacute;mero real
	_GDT_EXPORT_ static double Absoluto(double);
	
	// PROBABILIDAD
	//! Retorna un n&uacute;mero entero pseudoaleatorio en el intervalo entre el m&iacute;nimo y m&aacute;ximo dado
	_GDT_EXPORT_ static int Azar(int,int);
	//! Retorna un n&uacute;mero decimal pseudoaleatorio en el intervalo entre el m&iacute;nimo y m&aacute;ximo dado
	_GDT_EXPORT_ static double Azar(double, double);
	
	// RECTAS
	//! Calcula el &aacute; que forma la recta que une 2 puntos con el eje X
	_GDT_EXPORT_ static double Angulo(double, double, double, double);
	//! Calcula la distancia entre 2 puntos en un plano (2 dimensiones)
	_GDT_EXPORT_ static double Distancia(double, double, double, double);
	//! Calcula la distancia entre 2 puntos en el espacio (3 dimensiones)
	_GDT_EXPORT_ static double Distancia3d(double, double, double, double, double, double);
	_GDT_EXPORT_ static double GiroAngulo(double, double);
	
	// POTENCIAS Y RAICES
	//! Retorna la ra&iacute;z cuadrada de un n&uacute;mero
	_GDT_EXPORT_ static double Raiz(double);
	//! Calcula la potencia de x elevado a y.
	_GDT_EXPORT_ static double Potencia(double, double);
	
	// FUNCIONES EXPONENCIALES Y LOGARITMICAS
	//! Calcula la Exponencial de x. La base es "e".
	_GDT_EXPORT_ static double Exponencial(double);
	//! Calcula el valor de la funci&oacute;n logaritmo natural de un n&uacute;mero.
	_GDT_EXPORT_ static double Logaritmo(double);
	//! Calcula el valor de la funci&oacute;n logaritmo base 10 de un n&uacute;mero.
	_GDT_EXPORT_ static double Logaritmo10(double);
	
	// FUNCIONES HIPERBOLICAS
	//! Calcula el Seno Hiperb&oacute;lico de un n&uacute;mero.
	_GDT_EXPORT_ static double SenoHyperbolico(double);
	//! Calcula el Coseno Hiperb&oacute;lico de un n&uacute;mero: f(x) = ( e^x + e^(-x) ) / 2
	_GDT_EXPORT_ static double CosenoHyperbolico(double);
	_GDT_EXPORT_ static double TangenteHyperbolica(double);
	
	// FUNCIONES TRIGONOMETRICAS INVERSAS
	//! Funci&oacute;n inversa del Seno().
	_GDT_EXPORT_ static double ArcoSeno(double);
	//! Funci&oacute;n inversa del Coseno().
	_GDT_EXPORT_ static double ArcoCoseno(double);
	//! Funci&oacute;n inversa de la Tangente().
	_GDT_EXPORT_ static double ArcoTangente(double);
	//! Calcula el valor de la funci&oacute;n exponencial de un n&uacute;mero. f(x) = e^x
	
	_GDT_EXPORT_ static float CurvarValor(float, float, float);
	_GDT_EXPORT_ static double CurvarAngulo(double, double, double);
	_GDT_EXPORT_ static double MueveX(double, double, double);
	_GDT_EXPORT_ static double MueveY(double, double, double);
	_GDT_EXPORT_ static double MueveZ(double z, double angulo, double velocidad);
	
	// INTERVALO
	//! Comprueba si un número pertecene al Intervalo.
	_GDT_EXPORT_ static char Rango(double, double, double,char);
	//! Comprueba si un número pertecene al Intervalo Abierto.
	_GDT_EXPORT_ static char RangoAbierto(double, double, double);
	//! Comprueba si un número pertecene al Intervalo Cerrado.
	_GDT_EXPORT_ static char RangoCerrado(double, double, double);
	//!
	_GDT_EXPORT_ static double BuscarNormal(double, double, double);
	//!
	_GDT_EXPORT_ static vector3df Seguir( 
		vector3df PosicionEntrada1,
		float anguloY,
		vector3df PosicionEntrada2,
		float distancia,
		float altura,
		float angulo,
		float dureza
	);
	
	//! Convierte grados sexagesimales a radianes.
	_GDT_EXPORT_ static double Rad(double);

	// POSICION ********************************************************
	//!
	_GDT_EXPORT_ static double WrapValue(double Angulo);
	//! Regresa el nuevo valor del valor de la ordenadas X,Y,Z (segun el caso) segun un angulo y una distancia dadas.
	_GDT_EXPORT_ static double NewXValue(double dXActual,double dAngulo,double dDistancia);
	//!
	_GDT_EXPORT_ static double NewYValue(double dYActual,double dAngulo,double dDistancia);
	//!
	_GDT_EXPORT_ static double NewZValue(double dZActual,double dAngulo,double dDistancia);
	//******************************************************************

};


#endif // GD_MATEMATICAS_H
