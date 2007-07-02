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
 * \class GD_SistemaMatematicas
 *
 * Ac&aacute; podr&aacute;s encontrar las funciones 
 * matem&aacute;ticas m&aacute;s necesarias.
 *
 * Para todos los ejemplos, se asume que GD_SistemaMatematicas está
 * instanciado en una variable llamada Calcular, es decir:
 \code
     #include <gdt.h>

     GD_Sistema Sistema;
     GD_SistemaMatematicas Calcular;

     main {
         ////.....
     }
 \endcode
 */

#include "gd_sistemamatematicas.h" // class's header file

/*!
Inicializa el sistema de generaci&oacute;n de n&uacute;meros pseudo-aletatorios, y calcula las funciones trigonom&eacute;tricas de los 360 &aacute;ngulos enteros, para obtenerlos r&aacute;pido posteriormente.
*/
GD_SistemaMatematicas::GD_SistemaMatematicas()
{
    //inicio los cosenos y senos rapidos
    for(int i=0; i<361; i++)
    {
        FastCos[i]=cos((int)i*M_PI/180.0);
        FastSin[i]=sin((int)i*M_PI/180.0);
        FastTan[i]=tan((int)i*M_PI/180.0);
    }
    srand(time(0));
}

// class destructor
GD_SistemaMatematicas::~GD_SistemaMatematicas()
{
	// insert your code here
}

/*!
\return el valor de la constante \f$\pi\f$. Es el mismo valor que se puede acceder por la constante M_PI.

Ejemplo:
\code
// Cacula el area de un circulo de radio "r"
perimetro_circulo = 2 * Calcular.PI() * r;

// Equivalente a lo anterior
perimetro_circulo = 2 * M_PI * r;
\endcode
*/
double GD_SistemaMatematicas::PI()
{
    return M_PI;

}

/*!
\return el valor de la constante "e". Es el mismo valor que se puede acceder por la constante M_E.
*/
double GD_SistemaMatematicas::E()
{
    return M_E;
}

/*!
\param ang es un &aacute;ngulo entero medido en <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.
*/
int GD_SistemaMatematicas::Capar(int ang)
{
    while(ang>360.0)
        ang-=360;
    while(ang<0)
        ang+=360;
    return ang;
}

/*!
\param ang es un &aacute;ngulo real medido en <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.
*/
double GD_SistemaMatematicas::Capar(double ang)
{
    while(ang>360.0)
        ang=ang-360.0;
    while(ang<0)
        ang=ang+360.0;
    return ang;
}

/*!
\param ang es un &aacute;ngulo medido en <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.

Ejemplo:
\code
ComponenteY = longitud * Calcular.Seno( angulo );
\endcode
*/
//Error 0
double GD_SistemaMatematicas::Seno(int ang)
{
    return FastSin[Capar(ang)];
}

/*!
\param ang es un &aacute;ngulo medido en <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.

Ejemplo:
\code
ComponenteY = longitud * Calcular.Seno( angulo );
\endcode
*/
//Error menor de 0.0002
double GD_SistemaMatematicas::Seno(double ang)
{
    int a,b;
    double c,d;
    a=Capar((int)ang);
    b=a+1;
    c=FastSin[a]-FastSin[Capar(b)];
    d=ang-(double)a;
    return FastSin[a]-(c*d);
}

/*!
\param ang es un &aacute;ngulo entero medido en <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.

Ejemplo:
\code
ComponenteX = longitud * Calcular.Coseno( angulo );
\endcode
*/
//Error 0
double GD_SistemaMatematicas::Coseno(int ang)
{
    return FastCos[Capar(ang)];
}

/*!
\param ang es un &aacute;ngulo real medido en <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.

Ejemplo:
\code
ComponenteX = longitud * Calcular.Coseno( angulo );
\endcode
*/
//Error menor de 0.0002
double GD_SistemaMatematicas::Coseno(double ang)
{
    int a,b;
    double c,d;
    a=Capar((int)ang);
    b=a+1;
    c=FastCos[a]-FastCos[Capar(b)];
    d=ang-(double)a;
    return FastCos[a]-(c*d);
}

/*!
\param ang es un &aacute;ngulo entero medido en <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.

Ejemplo:
\code
pendiente = Calcular.Tangente( angulo );
\endcode
*/
double GD_SistemaMatematicas::Tangente(int ang)
{
    return FastTan[Capar(ang)];
}

/*!
\param ang es un &aacute;ngulo real medido en <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.

Ejemplo:
\code
pendiente = Calcular.Tangente( angulo );
\endcode
*/
double GD_SistemaMatematicas::Tangente(double ang)
{
    int a,b;
    double c,d;
    a=Capar((int)ang);
    b=a+1;
    c=FastTan[a]-FastTan[Capar(b)];
    d=ang-(double)a;
    return FastTan[a]-(c*d);
}


/*!
\param ValorA,ValorB números enteros.
\return retorna el entero más pequeño.

Ejemplo:
\code
// Retorna 10
min = Calcular.Minimo(10,20);
\endcode

\author Sir_Gon <sir_gon@users.sourceforge.net>
*/
int GD_SistemaMatematicas::Minimo(int ValorA,int ValorB)
{
    if(ValorA > ValorB)
	return ValorB;
    else
        return ValorA;
}

/*!
\param ValorA,ValorB números reales.
\return el número real más pequeño.

Ejemplo:
\code
min = Calcular.Minimo(0, 2*Calcular.PI());
\endcode

\author Sir_Gon <sir_gon@users.sourceforge.net>
*/
double GD_SistemaMatematicas::Minimo(double ValorA,double ValorB)
{
    if(ValorA > ValorB)
	return ValorB;
    else
        return ValorA;
}

/*!
\param ValorA,ValorB números enteros.
\return el entero más grande.

Ejemplo:
\code
min = Calcular.Maximo(0, 234);
\endcode

\author Sir_Gon <sir_gon@users.sourceforge.net>
*/
int GD_SistemaMatematicas::Maximo(int ValorA,int ValorB)
{
    if(ValorA < ValorB)
	return ValorB;
    else
        return ValorA;
}

/*!
\param ValorA,ValorB números enteros.
\return el número real más grande.

Ejemplo:
\code
min = Calcular.Maximo(0, 2*Calcular.PI());
\endcode

\author Sir_Gon <sir_gon@users.sourceforge.net>
*/
double GD_SistemaMatematicas::Maximo(double ValorA,double ValorB)
{
    if(ValorA < ValorB)
	return ValorB;
    else
        return ValorA;
}

/*!
\param min,max los valores extremos del intervalo, sin importar el orden.
\return un número entero pseudoaleatorio en el intervalo [min,max]

Los valores m&iacute;nimo y m&aacute;ximo se incluyen en las im&aacute;genes (o recorrido) de la funci&oacute;n. Es decir, se incluyen como posibles resultados.

Ejemplo:
\code
probabilidad = Calcular.Azar(0,100); // un porcentaje entero al azar
\endcode

Se agradece a: http://www.daniweb.com/forums/thread1769.html
*/
int GD_SistemaMatematicas::Azar(int min,int max)
{
    return (rand()%Absoluto(max-min+1)) + Minimo(min, max);
}

/*!
\param min,max los valores extremos del intervalo, sin importar el orden.
\return un número real pseudoaleatorio en el intervalo [min,max]

Ejemplo:
\code
probabilidad = Calcular.Azar(0,100); // un porcentaje real al azar
\endcode

\author Sir_Gon <sir_gon@users.sourceforge.net>
*/
double GD_SistemaMatematicas::Azar(double min, double max)
{
    return rand()/(double(RAND_MAX)+1) * Absoluto(min-max) + Minimo(min, max);
}

/*!
\param x un número real.
\return la raiz cuadrada del número real x. Aquel número que multiplicado por sí mismo es x.

Ejemplo:
\code
// La raiz cuadrada de 4, osea 2.
raiz = Calcular.Raiz(4)
\endcode
*/
double GD_SistemaMatematicas::Raiz(double x)
{
    return sqrt(x);
}

/*!
\return un &aacute;ngulo medido en <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A> entre -180 y 180 grados.

Dicho ángulo es la tangente de la pendiente de la recta que uno los puntos \f$(x_1,y_1)\f$ con \f$(x_2, y_2)\f$. Esta basada en la ecuaión de la recta que pasa por 2 puntos.

La fórmula es la siguiente:
\f[
   \Theta =  ArcoTangente \left( \frac{y_2 - y_1}{x_2 - x_1} \right)
\f]

Para mayor información sobre el origen de la fórmula, lea <A HREF="http://es.wikipedia.org/wiki/Pendiente_de_una_recta">este artículo</A>.
*/
double GD_SistemaMatematicas::Angulo(double x1, double y1, double x2, double y2)
{
    return atan2(y2-y1,x2-x1) * 180.0 / M_PI;
}

/*!
La formula es:

\f[
   \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}
\f]
*/
double GD_SistemaMatematicas::Distancia(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}

/*!
La formula es:

\f[
   \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2 + (z_2 - z_1)^2}
\f]
*/
double GD_SistemaMatematicas::Distancia3d(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return sqrt(pow((x1-x2),2) + pow((y1-y2),2) + pow((z1-z2),2));
}

double GD_SistemaMatematicas::GiroAngulo(double mirando, double meta)
{
    double diff;
    diff=mirando-meta;
    while(diff>180)
        diff=diff-360;
    while(diff<-180)
        diff=diff+360;
    if(diff==0)
        return 0;
    if(diff<0)
        return 1;
    else
        return -1;
}

/*!
\param x n&uacute;mero real.

Definici&oacute;n:
\f[
f(x) = \frac{e^x - e^{-x}}{2}
\f]

Para m&aacute;s informaci&oacute;n sobre esta funci&oacute;n matem&aacute;tica, <A href="http://es.wikipedia.org/wiki/Seno_hiperb%C3%B3lico">lea este art&iacute;culo</A>.
*/
double GD_SistemaMatematicas::SenoHyperbolico(double x)
{
    return sinh(x);
}

/*!
\param x n&uacute;mero real.

Definici&oacute;n:
\f[
f(x) = \frac{e^x + e^{-x}}{2}
\f]

Para m&aacute;s informaci&oacute;n sobre esta funci&oacute;n matem&aacute;tica, <A href="http://es.wikipedia.org/wiki/Coseno_hiperb%C3%B3lico">lea este art&iacute;culo</A>.
*/
double GD_SistemaMatematicas::CosenoHyperbolico(double x)
{
    return cosh(x);
}

/*!
\param t n&uacute;mero real.

Definici&oacute;n:
\f[
f(x) = \frac{e^x - e^{-x}}{e^x + e^{-x}}
\f]

Para m&aacute;s informaci&oacute;n sobre esta funci&oacute;n matem&aacute;tica, <A href="http://es.wikipedia.org/wiki/Tangente_hiperb%C3%B3lica">lea este art&iacute;culo</A>.
*/
double GD_SistemaMatematicas::TangenteHyperbolica(double t)
{
    return tanh(t);
}

/*!
\param x n&uacute;mero real.

Es la inversa del Seno().
*/
double GD_SistemaMatematicas::ArcoSeno(double x)
{
    return asin(x);
}

/*!
\param x n&uacute;mero real.

Es la inversa del Coseno().
*/
double GD_SistemaMatematicas::ArcoCoseno(double x)
{
    return acos(x);
}

/*!
\param x n&uacute;mero real.

Es la inversa de la Tangente().
*/
double GD_SistemaMatematicas::ArcoTangente(double x)
{
    return atan(x);
}

/*!
\param x n&uacute;mero real.

Es la inversa del Logaritmo Natural (Logaritmo()).
*/
double GD_SistemaMatematicas::Exponencial(double x)
{
    return exp(x);
}

/*!
\param x n&uacute;mero real positivo, distinto de 0. Si desea usar n&uacute;mero negativos, se sugiere ocupar la funci&oacute;n Absoluto() como par&aacute;metro de entrada.

Es la inversa de la funci&oacute;n Potencia() en base "e" (llamada tambi&eacute;n "exponencial natural"), es decir, encuentra el valor del exponente "n" para el cual se cumple:

\f[
\displaystyle x = b^n
\f]

Definici&oacute;n:
\f[
ln(x) = \int_{0}^{x} \dfrac {dt} {t} \mbox{ ; } \forall \mbox{ } x > 0 
\f]

Ejemplo:
\code
resultado = Calcular.Logaritmo( E_() ); // Retorna 1
\endcode

Nota: El n&uacute;mero "e" se puede obtener usando E().
*/
double GD_SistemaMatematicas::Logaritmo(double x)
{
    return log(x);
}

/*!
\param x n&uacute;mero real positivo, distinto de 0. Si desea usar n&uacute;mero negativos, se sugiere ocupar la funci&oacute;n Absoluto() como par&aacute;metro de entrada.

Es la inversa de la funci&oacute;n Potencia() en base 10, es decir, encuentra el valor del exponente "n" para el cual se cumple:

   \f$x = 10^n\f$

Ejemplo:
\code
resultado = Calcular.Logaritmo( 10 ); // Retorna 1
\endcode

*/
double GD_SistemaMatematicas::Logaritmo10(double x)
{
    return log10(x);
}

/*!
Definici&oacute;n:
\f[
Potencia(x, y) = x^y
\f]
*/
double GD_SistemaMatematicas::Potencia(double x, double y)
{
    return pow(x,y);
}

/*!
Por muy peque&ntilde;o que sea el decimal, se trunca al entero y se suma 1.

\param x es un n&uacute;mero real

Ejemplo:
\code
aproximado = Calcular.RedondearArriba(0.0000000000000001) // Retorna 1
\endcode
*/
int GD_SistemaMatematicas::RedondearArriba(double x)
{
    return (int)ceil(x);
}

/*!
Por muy alto que sea el decimal, se trunca al entero.

\param x es un n&uacute;mero real

Ejemplo:
\code
aproximado = Calcular.RedondearAbajo(10.9) // Retorna 10
\endcode
*/
int GD_SistemaMatematicas::RedondearAbajo(double x)
{
    return (int)floor(x);
}

/*!
La regla es si el primer decimal es menor a 5, se redondea hacia abajo (o se trunca al entero), en caso contrario, si es mayor o igual a 5, se redondea hacia arriba (al sucesor de la parte entera del n&uacute;mero).

Ejemplo:
\code
aproximado = Calcular.RedondearAbajo(3.9) // Retorna 4
aproximado = Calcular.RedondearAbajo(3.5) // Retorna 4
aproximado = Calcular.RedondearAbajo(3.4) // Retorna 3
\endcode
*/
int GD_SistemaMatematicas::Redondear(double x)
{
    int y;
    double z;
    y=(int)x;
    z=x-y;
    if(z<=0.5)
        return (int)x;
    else
        return (int)(x+1);
}

/*!

*/
int GD_SistemaMatematicas::Entero(double x)
{
    return (int)x;
}

/*!
\return el valor del número real sin signo.

Definición:
\f[
Absoluto(x) = |x| =
\begin{cases} 
x & \text{si } x \geq 0 \\
-x & \text{si } x < 0
\end{cases}
\f]

Ejemplo:

\code
\param x número entero.
valor = Calcular.Absoluto( -10 ); //
if(valor == 10) {
    cout << "El valor absoluto de -10 es 10" << "\n";
}
\endcode
*/
int GD_SistemaMatematicas::Absoluto(int x)
{
    return abs(x);
}

/*!
\param x número real.
\return el valor del número real sin signo.

Definición:
\f[
Absoluto(x) = |x| =
\begin{cases} 
x & \text{si } x \geq 0 \\
-x & \text{si } x < 0
\end{cases}
\f]

Ejemplo:

\code
valor = Calcular.Absoluto( -10 ); //
if(valor == 10) {
    cout << "El valor absoluto de -10 es 10" << "\n";
}
\endcode
*/
double GD_SistemaMatematicas::Absoluto(double x)
{
    return fabs(x);
}

float GD_SistemaMatematicas::CurvarValor(float actual, float destino, float velocidad)
{
    float diferencia=destino-actual;
    if(velocidad==0)
        return actual;
    else
        return actual+(diferencia*(1/velocidad));
}

double GD_SistemaMatematicas::CurvarAngulo(double actual, double destino, double velocidad)
{
    double diferencia;
    actual=Capar(actual);
    destino=Capar(destino);
    if(GiroAngulo(actual, destino)>0)
    {
        diferencia=destino-actual;
        if(velocidad==0)
            return actual;
        else
            return Capar(actual+(diferencia*(1/velocidad)));
    }
    else
    {
        diferencia=actual-destino;
        if(velocidad==0)
            return actual;
        else
            return Capar(actual-(diferencia*(1/velocidad)));
    }
}

double GD_SistemaMatematicas::MueveX(double x, double angulo, double velocidad)
{
     /*double angulop = Rad(angulo);
     double xf;
     xf = x + (velocidad*(double)sin(angulop));
     return xf; */

     return x+velocidad*sin(Rad(angulo));
}

double GD_SistemaMatematicas::MueveY(double y, double angulo, double velocidad)
{
    return y+velocidad*tan(Rad(angulo));

}

double GD_SistemaMatematicas::MueveZ(double z, double angulo, double velocidad)
{
     return z+velocidad*cos(Rad(angulo));
}

/*!
\param x número real a evaluar
\param min,max limites del intervalo.
\param incluir Si es True se incluyen los extremos, en caso contrario se excluyen.
\return True si el número x se encuentra en el interior del intervalo.
*/
char GD_SistemaMatematicas::Rango(double x, double min, double max, char incluir)
{
/*
    if(incluir)
    {
        if(x<min || x>max)
            return 0;
        else
            return 1;
    }
    else
    {
        if(x<=min || x>=max)
            return 0;
        else
            return 1;
    }
*/
    if(incluir)
       return RangoCerrado(x, min, max);
    else
       return RangoAbierto(x, min, max);

}

/*!
\param x número real a evaluar
\param min,max limites del intervalo.
\return True si el número x se encuentra en el interior del intervalo abierto, es decir, excluyendo los valores extremos.

\author Sir_Gon <sir_gon@users.sourceforge.net>
*/
char GD_SistemaMatematicas::RangoAbierto(double x, double min, double max)
{
    if(min < x && x < max)
        return 1;
    else
        return 0;
}

/*!
\param x número real a evaluar
\param min,max extremos del intervalo.
\return True si el número x se encuentra en el interior del intervalo cerrado, es decir, incluyendo los valores extremos.

\author Sir_Gon <sir_gon@users.sourceforge.net>
*/
char GD_SistemaMatematicas::RangoCerrado(double x, double min, double max)
{
    if(min <= x && x <= max)
        return 1;
    else
        return 0;
}

/*!
\bug Esta implementación siempre retorna 0.
*/
double GD_SistemaMatematicas::BuscarNormal(double x, double y, double z)
{
    return 0;
}

vector3df GD_SistemaMatematicas::Seguir( vector3df PosicionEntrada1, float anguloY,vector3df PosicionEntrada2, float distancia,float altura,float angulo=180, float dureza=15)
{
      vector3df Salida;
	f32 px = PosicionEntrada1.X;
	f32 py = PosicionEntrada1.Y;
	f32 pz = PosicionEntrada1.Z;
	double pa = Capar(anguloY+angulo);
	f32 cx = PosicionEntrada2.X;
	f32 cy = PosicionEntrada2.Y;
	f32 cz = PosicionEntrada2.Z;
	cx = CurvarValor(cx,MueveX(px ,pa ,distancia),dureza);
	cy = CurvarValor(cy,py+altura,dureza/2);
	cz = CurvarValor(cz,MueveZ(pz ,pa ,distancia),dureza);
//	printf("X: %f, Y: %f, Z: %f\n",cx,cy,cz);
     Salida.set(cx,cy,cz);
     return Salida;
}

/*!
\param Deg es un &aacute;ngulo entero medido en <A HREF="http://es.wikipedia.org/wiki/Grado_sexagesimal">grados sexagesimales</A>.
\return el valor del &aacute;ngulo en radianes.
*/
double GD_SistemaMatematicas::Rad(double Deg)
{
Deg = (Deg/180.0f); //Divide by 180
Deg = Deg*3.14159f; //Multuply by approximation to PI
return (float)Deg;
}

// POSICION *************************************************************
// Evita que el angulo sea mayor de 360 o menor a 0
double GD_SistemaMatematicas::WrapValue(double Angulo)
{
   while (Angulo>=360){Angulo-=360;}
   while (Angulo<0){Angulo+=360;}
   return Angulo;
}
//Regresa el nuevo valor del valor de la ordenadas X,Y,Z (segun el caso)
//segun un angulo y una distancia dadas.
double GD_SistemaMatematicas::NewXValue(double dXActual,double dAngulo,double dDistancia)
{
   return ((Seno(dAngulo)*dDistancia)+dXActual);
}

double GD_SistemaMatematicas::NewYValue(double dYActual,double dAngulo,double dDistancia)
{
   return  -1*((Seno(dAngulo)*dDistancia)+dYActual);
}

double GD_SistemaMatematicas::NewZValue(double dZActual,double dAngulo,double dDistancia)
{
      return ((Coseno(dAngulo)*dDistancia)+dZActual);
}
// *************************************************************************
