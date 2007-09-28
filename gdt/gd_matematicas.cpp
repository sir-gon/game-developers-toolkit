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

/*!
 * \class GDT::Matematicas
 *
 * Ac&aacute; podr&aacute;s encontrar las funciones
 * matem&aacute;ticas m&aacute;s necesarias.
 *
 * Todos los m&eacute;todos de esta clase han sido declarados est&aacute;ticos,
 * de tal modo que ya no es necesario declarar una instancia de GDT::Matematicas.
 *
 * \since gdt-1.3.4-beta3
 */



#include "gd_matematicas.h" // class's header file
#include <iostream>

/* No documentar */
#ifndef _GDT_DOXYGEN_IGNORAR_
using namespace std;
#endif /* _GDT_DOXYGEN_IGNORAR_ */

double GDT::Matematicas::FastCos[360];
double GDT::Matematicas::FastSin[360];
double GDT::Matematicas::FastTan[360];
bool GDT::Matematicas::init = GDT::Matematicas::Inicializar();

/*!
* \return true, siempre.
*
* Inicializa el sistema de generaci&oacute;n de n&uacute;meros pseudo-aletatorios, y
* calcula las funciones trigonom&eacute;tricas de los 360 &aacute;ngulos enteros, para
* obtenerlos r&aacute;pido posteriormente.
*
* \note este m&eacute;todo es llamado autom&aacute;ticamente al iniciar, por lo tanto,
* no es necesario volver a llamarlo, y de hecho no se recomienda, para evitar
* p&eacute;rdida de rendimiento.
*/

bool GDT::Matematicas::Inicializar()
{

	//inicio los cosenos y senos rapidos
	for ( int i=0; i<360; i++ )
	{
		//FastCos[i]=cos((int)i*M_PI/180.0);
		FastCos[i]=cos ( ( float ) Rad ( i ) );
		FastSin[i]=sin ( ( float ) Rad ( i ) );
		FastTan[i]=tan ( ( float ) Rad ( i ) );
	}
	srand ( ( u32 ) time ( 0 ) );
	return true;
}


/*!
* \return el valor de la constante \f$\pi\f$. Es el mismo valor que se puede acceder por la constante M_PI.
* 
* Ejemplo:
* \code
* // Cacula el area de un circulo de radio "r"
* perimetro_circulo = 2 * GDT::Matematicas::PI() * r;
* 
* // Equivalente a lo anterior
* perimetro_circulo = 2 * M_PI * r;
* \endcode
*/
double GDT::Matematicas::PI()
{
	return M_PI;

}

/*!
* \return el valor de la constante "e". Es el mismo valor que se puede acceder por la constante M_E.
*/
double GDT::Matematicas::E()
{
	return M_E;
}

/*!
* \param ang es un &aacute;ngulo entero medido en
* <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.
* \since 2.0
*/
int GDT::Matematicas::Grados ( int ang )
{
	while ( ang>360.0 )
		ang-=360;
	while ( ang<0 )
		ang+=360;
	if ( ang==360 )
		return 0;
	return ang;
}

/*!
* \param ang es un &aacute;ngulo real medido en
* <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.
* \since 2.0
*/
double GDT::Matematicas::Grados ( double ang )
{
	while ( ang>360.0 )
		ang=ang-360.0;
	while ( ang<0 )
		ang=ang+360.0;
	if ( ang==360 )
		return 0;
	return ang;
}
/////////////////////////////
/*!
* \param ang es un &aacute;ngulo medido en
* <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.
*
* Ejemplo:
* \code
* ComponenteY = longitud * GDT::Matematicas::Seno( angulo );
* \endcode
*
* |note Error 0
*/
double GDT::Matematicas::Seno ( int ang )
{
	return FastSin[Grados ( ang ) ];
}

/*!
* \param ang es un &aacute;ngulo medido en
* <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.
*
* Ejemplo:
* \code
* ComponenteY = longitud * GDT::Matematicas::Seno( angulo );
* \endcode
*
* \note Error menor de 0.0002
*/
double GDT::Matematicas::Seno ( double ang )
{
	int a,b;
	double c,d;
	a=Grados ( ( int ) ang );
	b=a+1;
	c=FastSin[a]-FastSin[Grados ( b ) ];
	d=ang- ( double ) a;
	return FastSin[a]- ( c*d );
}

/*!
* \param ang es un &aacute;ngulo entero medido en
* <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.
*
* Ejemplo:
* \code
* ComponenteX = longitud * GDT::Matematicas::Coseno( angulo );
* \endcode
*
* \note Error 0
*/
double GDT::Matematicas::Coseno ( int ang )
{
	return FastCos[Grados ( ang ) ];
}

/*!
* \param ang es un &aacute;ngulo real medido en
* <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.
*
* Ejemplo:
* \code
* ComponenteX = longitud * GDT::Matematicas::Coseno( angulo );
* \endcode
*
* \note Error menor de 0.0002
*/
double GDT::Matematicas::Coseno ( double ang )
{
	int a,b;
	double c,d;
	a=Grados ( ( int ) ang );
	b=a+1;
	c=FastCos[a]-FastCos[Grados ( b ) ];
	d=ang- ( double ) a;
	return FastCos[a]- ( c*d );
}

/*!
* \param ang es un &aacute;ngulo entero medido en
* <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.
*
* Ejemplo:
* \code
* pendiente = GDT::Matematicas::Tangente( angulo );
* \endcode
*/
double GDT::Matematicas::Tangente ( int ang )
{
	return FastTan[Grados ( ang ) ];
}

/*!
* \param ang es un &aacute;ngulo real medido en
* <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.
*
* Ejemplo:
* \code
* pendiente = GDT::Matematicas::Tangente( angulo );
* \endcode
*/
double GDT::Matematicas::Tangente ( double ang )
{
	int a,b;
	double c,d;
	a=Grados ( ( int ) ang );
	b=a+1;
	c=FastTan[a]-FastTan[Grados ( b ) ];
	d=ang- ( double ) a;
	return FastTan[a]- ( c*d );
}


/*!
* \param ValorA,ValorB n&uacute;meros enteros.
* \return el menor n&uacute;mero entero.
* 
* Ejemplo:
* \code
* // Retorna 10
* min = GDT::Matematicas::Minimo(10,20);
* \endcode
* 
* \author Sir_Gon
*/
int GDT::Matematicas::Minimo ( int ValorA,int ValorB )
{
	return ValorA < ValorB ? ValorA : ValorB;
}

/*!
* \param ValorA,ValorB n&uacute;meros reales.
* \return el menor n&uacute;mero real.
* 
* Ejemplo:
* \code
* min = GDT::Matematicas::Minimo(0, 2*GDT::Matematicas::PI());
* \endcode
* 
* \author Sir_Gon
*/
double GDT::Matematicas::Minimo ( double ValorA,double ValorB )
{
	return ValorA < ValorB ? ValorA : ValorB;
}

/*!
* \param ValorA,ValorB n&uacute;meros enteros.
* \return el entero m&aacute;s grande.
* 
* Ejemplo:
* \code
* min = GDT::Matematicas::Maximo(0, 234);
* \endcode
* 
* \author Sir_Gon
*/
int GDT::Matematicas::Maximo ( int ValorA,int ValorB )
{
	return ValorA > ValorB ? ValorA : ValorB;
}

/*!
* \param ValorA,ValorB n&uacute;meros enteros.
* \return el n&uacute;mero real m&aacute;s grande.
* 
* Ejemplo:
* \code
* min = GDT::Matematicas::Maximo(0, 2*GDT::Matematicas::PI());
* \endcode
* 
* \author Sir_Gon
*/
double GDT::Matematicas::Maximo ( double ValorA,double ValorB )
{
	return ValorA > ValorB ? ValorA : ValorB;
}

/*!
* \param min,max los valores extremos del intervalo, sin importar el orden.
* \return un n&uacute;mero entero pseudoaleatorio en el intervalo [min,max]
* 
* Los valores m&iacute;nimo y m&aacute;ximo se incluyen en las im&aacute;genes (o recorrido) de la funci&oacute;n. Es decir, se incluyen como posibles resultados.
* 
* Ejemplo:
* \code
* probabilidad = GDT::Matematicas::Azar(0,100); // un porcentaje entero al azar
* \endcode
* 
* \note Se agradece a: http://www.daniweb.com/forums/thread1769.html
*/
int GDT::Matematicas::Azar ( int min,int max )
{
	return ( rand() %Absoluto ( max-min+1 ) ) + Minimo ( min, max );
}

/*!
* \param min,max los valores extremos del intervalo, sin importar el orden.
* \return un n&uacute;mero real pseudoaleatorio en el intervalo [min,max]
* 
* Ejemplo:
* \code
* probabilidad = GDT::Matematicas::Azar(0,100); // un porcentaje real al azar
* \endcode
* 
* \author Sir_Gon
*/
double GDT::Matematicas::Azar ( double min, double max )
{
	return rand() / ( double ( RAND_MAX ) +1 ) * Absoluto ( min-max ) + Minimo ( min, max );
}

/*!
* \param x un n&uacute;mero real.
* \return la raiz cuadrada del n&uacute;mero real x. Aquel n&uacute;mero que
* multiplicado por s&iacute; mismo es x.
* 
* Ejemplo:
* \code
* // La raiz cuadrada de 4, osea 2.
* raiz = GDT::Matematicas::Raiz(4)
* \endcode
*/
double GDT::Matematicas::Raiz ( double x )
{
	return sqrt ( x );
}

/*!
* \return un &aacute;ngulo medido en 
* <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A> 
* entre -180 y 180 grados.
* 
* Dicho &aacute;ngulo es la tangente de la pendiente de la recta que uno los 
* puntos \f$(x_1,y_1)\f$ con \f$(x_2, y_2)\f$. Esta basada en la ecuai&oacute;n
* de la recta que pasa por 2 puntos.
* 
* La f&oacute;mula es la siguiente:
* \f[
*    \Theta =  ArcoTangente \left( \frac{y_2 - y_1}{x_2 - x_1} \right)
* \f]
* 
* Para mayor informaci&oacute;n sobre el origen de la f&oacute;mula, lea 
* <A HREF="http://es.wikipedia.org/wiki/Pendiente_de_una_recta">
* este art&iacute;culo</A>.
*/
double GDT::Matematicas::Angulo ( double x1, double y1, double x2, double y2 )
{
	return atan2 ( y2-y1,x2-x1 ) * 180.0 / M_PI;
}

/*!
* La formula es:
* 
* \f[
*    \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}
* \f]
*/
double GDT::Matematicas::Distancia ( double x1, double y1, double x2, double y2 )
{
	return sqrt ( pow ( ( x1-x2 ),2 ) + pow ( ( y1-y2 ),2 ) );
}

/*!
La formula es:
* 
* \f[
*    \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2 + (z_2 - z_1)^2}
* \f]
*/
double GDT::Matematicas::Distancia3d ( double x1, double y1, double z1, double x2, double y2, double z2 )
{
	return sqrt ( pow ( ( x1-x2 ),2 ) + pow ( ( y1-y2 ),2 ) + pow ( ( z1-z2 ),2 ) );
}

double GDT::Matematicas::GiroAngulo ( double mirando, double meta )
{
	double diff;
	diff=mirando-meta;
	while ( diff>180 )
		diff-=360;
	while ( diff<-180 )
		diff+=360;
	if ( diff==0 )
		return 0;
	if ( diff<0 )
		return 1;
	else
		return -1;
}

/*!
* \param x n&uacute;mero real.
* 
* Definici&oacute;n:
* \f[
* f(x) = \frac{e^x - e^{-x}}{2}
* \f]
* 
* Para m&aacute;s informaci&oacute;n sobre esta funci&oacute;n matem&aacute;tica, <A href="http://es.wikipedia.org/wiki/Seno_hiperb%C3%B3lico">lea este art&iacute;culo</A>.
*/
double GDT::Matematicas::SenoHyperbolico ( double x )
{
	return sinh ( x );
}

/*!
* \param x n&uacute;mero real.
* 
* Definici&oacute;n:
* \f[
* f(x) = \frac{e^x + e^{-x}}{2}
* \f]
* 
* Para m&aacute;s informaci&oacute;n sobre esta funci&oacute;n matem&aacute;tica, <A href="http://es.wikipedia.org/wiki/Coseno_hiperb%C3%B3lico">lea este art&iacute;culo</A>.
*/
double GDT::Matematicas::CosenoHyperbolico ( double x )
{
	return cosh ( x );
}

/*!
* \param t n&uacute;mero real.
* 
* Definici&oacute;n:
* \f[
* f(x) = \frac{e^x - e^{-x}}{e^x + e^{-x}}
* \f]
* 
* Para m&aacute;s informaci&oacute;n sobre esta funci&oacute;n matem&aacute;tica, <A href="http://es.wikipedia.org/wiki/Tangente_hiperb%C3%B3lica">lea este art&iacute;culo</A>.
*/
double GDT::Matematicas::TangenteHyperbolica ( double t )
{
	return tanh ( t );
}

/*!
* \param x n&uacute;mero real.
* 
* \f$ ArcoSeno( Seno (x) ) = x; \f$
*/
double GDT::Matematicas::ArcoSeno ( double x )
{
	return asin ( x );
}

/*!
* \param x n&uacute;mero real.
* 
* \f$ ArcoCoseno( Coseno(x) ) = x; \f$
*/
double GDT::Matematicas::ArcoCoseno ( double x )
{
	return acos ( x );
}

/*!
* \param x n&uacute;mero real.
* 
* \f$ ArcoTangente( Tangente(x) ) = x; \f$
*/
double GDT::Matematicas::ArcoTangente ( double x )
{
	return atan ( x );
}

/*!
* \param x n&uacute;mero real.
*
* Es la inversa del Logaritmo Natural (Logaritmo()).
*/
double GDT::Matematicas::Exponencial ( double x )
{
	return exp ( x );
}

/*!
* \param x n&uacute;mero real positivo, distinto de 0. Si desea usar n&uacute;mero negativos, se sugiere ocupar la funci&oacute;n Absoluto() como par&aacute;metro de entrada.
*
* Es la inversa de la funci&oacute;n Potencia() en base "e" (llamada tambi&eacute;n "exponencial natural"), es decir, encuentra el valor del exponente "n" para el cual se cumple:
*
* \f[
* \displaystyle x = b^n
* \f]
*
* Definici&oacute;n:
* \f[
* ln(x) = \int_{0}^{x} \dfrac {dt} {t} \mbox{ ; } \forall \mbox{ } x > 0
* \f]
*
* Ejemplo:
* \code
* resultado = GDT::Matematicas::Logaritmo( E_() ); // Retorna 1
* \endcode
*
* Nota: El n&uacute;mero "e" se puede obtener usando E().
*/
double GDT::Matematicas::Logaritmo ( double x )
{
	return log ( x );
}

/*!
* \param x n&uacute;mero real positivo, distinto de 0. Si desea usar n&uacute;mero negativos, se sugiere ocupar la funci&oacute;n Absoluto() como par&aacute;metro de entrada.
*
* Es la inversa de la funci&oacute;n Potencia() en base 10, es decir, encuentra el valor del exponente "n" para el cual se cumple:
*
*    \f$x = 10^n\f$
*
* Ejemplo:
* \code
* resultado = GDT::Matematicas::Logaritmo( 10 ); // Retorna 1
* \endcode
*/
double GDT::Matematicas::Logaritmo10 ( double x )
{
	return log10 ( x );
}

/*!
* Definici&oacute;n:
* \f[
* Potencia(x, y) = x^y
* \f]
*/
double GDT::Matematicas::Potencia ( double x, double y )
{
	return pow ( x,y );
}

/*!
* Por muy peque&ntilde;o que sea el decimal, se trunca al entero y se suma 1.
*
* \param x es un n&uacute;mero real
*
* Ejemplo:
* \code
* aproximado = GDT::Matematicas::RedondearArriba(0.0000000000000001) // Retorna 1
* \endcode
*/
int GDT::Matematicas::RedondearArriba ( double x )
{
	return ( int ) ceil ( x );
}

/*!
* Por muy alto que sea el decimal, se trunca al entero.
*
* \param x es un n&uacute;mero real
*
* Ejemplo:
* \code
* aproximado = GDT::Matematicas::RedondearAbajo(10.9) // Retorna 10
* \endcode
*/
int GDT::Matematicas::RedondearAbajo ( double x )
{
	return ( int ) floor ( x );
}

/*!
* La regla es si el primer decimal es menor a 5, se redondea hacia abajo (o se trunca al entero), en caso contrario, si es mayor o igual a 5, se redondea hacia arriba (al sucesor de la parte entera del n&uacute;mero).
*
* Ejemplo:
* \code
* aproximado = GDT::Matematicas::RedondearAbajo(3.9) // Retorna 4
* aproximado = GDT::Matematicas::RedondearAbajo(3.5) // Retorna 4
* aproximado = GDT::Matematicas::RedondearAbajo(3.4) // Retorna 3
* \endcode
*/
int GDT::Matematicas::Redondear ( double x )
{
	int y;
	double z;
	y= ( int ) x;
	z=x-y;
	if ( z<=0.5 )
		return ( int ) x;
	else
		return ( int ) ( x+1 );
}

/*! */
int GDT::Matematicas::Entero ( double x )
{
	return ( int ) x;
}

/*!
* \param x n&uacute;mero entero.
* \return el valor del n&uacute;mero real sin signo.
*
* Definici&oacute;n:
* \f[
* Absoluto(x) = |x| =
* \begin{cases}
* x & \text{si } x \geq 0 \\
* -x & \text{si } x < 0
* \end{cases}
* \f]
*
* Ejemplo:
*
* \code
* valor = GDT::Matematicas::Absoluto( -10 ); //
* if(valor == 10) {
*     cout << "El valor absoluto de -10 es 10" << "\n";
* }
* \endcode
*/
int GDT::Matematicas::Absoluto ( int x )
{
	return abs ( x );
}

/*!
* \param x n&uacute;mero real.
* \return el valor del n&uacute;mero real sin signo.
*
* Definici&oacute;n:
* \f[
* Absoluto(x) = |x| =
* \begin{cases}
* x & \text{si } x \geq 0 \\
* -x & \text{si } x < 0
* \end{cases}
* \f]
*
* Ejemplo:
*
* \code
* valor = GDT::Matematicas::Absoluto( -10 ); //
* if(valor == 10) {
*     cout << "El valor absoluto de -10 es 10" << "\n";
* }
* \endcode
*/
double GDT::Matematicas::Absoluto ( double x )
{
	return fabs ( x );
}

float GDT::Matematicas::CurvarValor ( float actual, float destino, float velocidad )
{
	float diferencia=destino-actual;
	if ( velocidad==0 )
		return actual;
	else
		return actual+ ( diferencia* ( 1/velocidad ) );
}

double GDT::Matematicas::CurvarAngulo ( double actual, double destino, double velocidad )
{
	double diferencia;
	actual=Grados ( actual );
	destino=Grados ( destino );
	if ( GiroAngulo ( actual, destino ) >0 )
	{
		diferencia=destino-actual;
		if ( velocidad==0 )
			return actual;
		else
			return Grados ( actual+ ( diferencia* ( 1/velocidad ) ) );
	}
	else
	{
		diferencia=actual-destino;
		if ( velocidad==0 )
			return actual;
		else
			return Grados ( actual- ( diferencia* ( 1/velocidad ) ) );
	}
}

double GDT::Matematicas::MueveX ( double x, double angulo, double velocidad )
{
	/*double angulop = Rad(angulo);
	double xf;
	xf = x + (velocidad*(double)sin(angulop));
	return xf; */

	return x+velocidad*sin ( Rad ( angulo ) );
}

double GDT::Matematicas::MueveY ( double y, double angulo, double velocidad )
{
	return y+velocidad*tan ( Rad ( angulo ) );

}

double GDT::Matematicas::MueveZ ( double z, double angulo, double velocidad )
{
	return z+velocidad*cos ( Rad ( angulo ) );
}

/*!
* \param x n&uacute;mero real a evaluar
* \param min,max limites del intervalo.
* \param incluir Si es True se incluyen los extremos, en caso contrario se excluyen.
* \return True si el n&uacute;mero x se encuentra en el interior del intervalo.
*/
char GDT::Matematicas::Rango ( double x, double min, double max, char incluir )
{
	if ( incluir )
		return RangoCerrado ( x, min, max );
	else
		return RangoAbierto ( x, min, max );
}

/*!
* \param x n&uacute;mero real a evaluar
* \param min,max limites del intervalo.
* \return True si el n&uacute;mero x se encuentra en el interior del intervalo abierto, es decir, excluyendo los valores extremos.
*
* \author Sir_Gon
*/
char GDT::Matematicas::RangoAbierto ( double x, double min, double max )
{
	if ( min < x && x < max )
		return 1;
	else
		return 0;
}

/*!
* \param x n&uacute;mero real a evaluar
* \param min,max extremos del intervalo.
* \return True si el n&uacute;mero x se encuentra en el interior del intervalo cerrado, es decir, incluyendo los valores extremos.
*
* \author Sir_Gon
*/
char GDT::Matematicas::RangoCerrado ( double x, double min, double max )
{
	if ( min <= x && x <= max )
		return 1;
	else
		return 0;
}

/*!
\bug Esta implementaci&oacute;n siempre retorna 0.
*/
double GDT::Matematicas::BuscarNormal ( double x, double y, double z )
{
	return 0;
}

vector3df GDT::Matematicas::Seguir ( vector3df PosicionEntrada1, float anguloY,vector3df PosicionEntrada2, float distancia,float altura,float angulo=180, float dureza=15 )
{
	vector3df Salida;
	f32 px = PosicionEntrada1.X;
	f32 py = PosicionEntrada1.Y;
	f32 pz = PosicionEntrada1.Z;
	double pa = Grados ( anguloY+angulo );
	f32 cx = PosicionEntrada2.X;
	f32 cy = PosicionEntrada2.Y;
	f32 cz = PosicionEntrada2.Z;
	cx = CurvarValor ( cx, ( float ) MueveX ( px , ( float ) pa ,distancia ),dureza );
	cy = CurvarValor ( cy,py+altura,dureza/2 );
	cz = CurvarValor ( cz, ( float ) MueveZ ( pz , ( float ) pa ,distancia ),dureza );
	//printf("X: %f, Y: %f, Z: %f\n",cx,cy,cz);
	Salida.set ( cx,cy,cz );
	return Salida;
}

/*!
* \param Deg es un &aacute;ngulo entero medido en
* <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.
* \return el valor del &aacute;ngulo en radianes.
*/
double GDT::Matematicas::Rad ( double Deg )
{
	/*
	Deg = (Deg/180.0f); //Divide by 180
	Deg = Deg*3.14159f; //Multuply by approximation to PI
	return (float)Deg;
	*/
	return Deg/ ( double ) 180.0*M_PI;
}

// POSICION *************************************************************
// Evita que el angulo sea mayor de 360 o menor a 0
double GDT::Matematicas::WrapValue ( double Angulo )
{
	while ( Angulo>=360 ) {Angulo-=360;}
	while ( Angulo<0 ) {Angulo+=360;}
	return Angulo;
}
//Regresa el nuevo valor del valor de la ordenadas X,Y,Z (segun el caso)
//segun un angulo y una distancia dadas.
double GDT::Matematicas::NewXValue ( double dXActual,double dAngulo,double dDistancia )
{
	return ( ( Seno ( dAngulo ) *dDistancia ) +dXActual );
}

double GDT::Matematicas::NewYValue ( double dYActual,double dAngulo,double dDistancia )
{
	return  -1* ( ( Seno ( dAngulo ) *dDistancia ) +dYActual );
}

double GDT::Matematicas::NewZValue ( double dZActual,double dAngulo,double dDistancia )
{
	return ( ( Coseno ( dAngulo ) *dDistancia ) +dZActual );
}
// *************************************************************************
