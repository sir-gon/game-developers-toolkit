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

#include "gd_sistemamatematicas.h" // class's header file

// class constructor
GD_SistemaMatematicas::GD_SistemaMatematicas()
{
	// insert your code here
}

// class destructor
GD_SistemaMatematicas::~GD_SistemaMatematicas()
{
	// insert your code here
}


void GD_SistemaMatematicas::Inicializar()
{
    //inicio los cosenos y senos rapidos
    for(int i=0; i<361; i++)
    {
        FastCos[i]=cos((int)i*M_PI/180.0);
        FastSin[i]=sin((int)i*M_PI/180.0);
        FastTan[i]=tan((int)i*M_PI/180.0);
    }
    srand(time(NULL));
}

int GD_SistemaMatematicas::Capar(int ang)
{
    return ang%360;
}

double GD_SistemaMatematicas::Capar(double ang)
{
    while(ang>360.0)
        ang=ang-360.0;
    while(ang<0)
        ang=ang+360.0;
    return ang;
}

//Error 0
double GD_SistemaMatematicas::Coseno(int ang)
{
    return FastCos[Capar(ang)];
}

//Error 0
double GD_SistemaMatematicas::Seno(int ang)
{
    return FastSin[Capar(ang)];
}




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
int GD_SistemaMatematicas::Azar(int min,int max)
{
    int n=max-min+1;
    return (rand()%n)+min;
}

//revisar (tarda tela...)
double GD_SistemaMatematicas::Azar(double min, double max)
{
    double n=max-min;
    double r;
    double lol=(double)rand()*2658013;
    while(lol>max)
        lol=lol-n;
    while(lol<min)
        lol=lol+n;
/*    if(lol>max)
    {
        r=((lol-max)/n)+1;
        return lol-(r*n);
    }
    if(lol<min)
    {
        r=(min-lol)/n;
        return lol+(r*n);
    }*/
    return lol;
}

double GD_SistemaMatematicas::Raiz(double n)
{
    return sqrt(n);
}

double GD_SistemaMatematicas::Angulo(double x1, double y1, double x2, double y2)
{
    return atan2(y2-y1,x2-x1) * 180.0 / M_PI;
}

double GD_SistemaMatematicas::Distancia(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}

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

double GD_SistemaMatematicas::PI()
{
    return M_PI;
}

double GD_SistemaMatematicas::E()
{
    return M_E;
}

double GD_SistemaMatematicas::Tangente(int t)
{
    return FastTan[Capar(t)];
}

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

double GD_SistemaMatematicas::SenoHyperbolico(double s)
{
    return sinh(s);
}
double GD_SistemaMatematicas::CosenoHyperbolico(double c)
{
    return cosh(c);
}
double GD_SistemaMatematicas::TangenteHyperbolica(double t)
{
    return tanh(t);
}
double GD_SistemaMatematicas::ArcoSeno(double as)
{
    return asin(as);
}

double GD_SistemaMatematicas::ArcoCoseno(double ac)
{
    return acos(ac);
}

double GD_SistemaMatematicas::ArcoTangente(double at)
{
    return atan(at);
}

double GD_SistemaMatematicas::Exponencial(double e)
{
    return exp(e);
}

double GD_SistemaMatematicas::Logaritmo(double l)
{
    return log(l);
}

double GD_SistemaMatematicas::Logaritmo10(double l)
{
    return log10(l);
}

double GD_SistemaMatematicas::Potencia(double x, double y)
{
    return pow(x,y);
}

int GD_SistemaMatematicas::RedondearArriba(double x)
{
    return (int)ceil(x);
}

int GD_SistemaMatematicas::RedondearAbajo(double x)
{
    return (int)floor(x);
}

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

int GD_SistemaMatematicas::Entero(double x)
{
    return (int)x;
}

int GD_SistemaMatematicas::Absoluto(int x)
{
    return abs(x);
}

double GD_SistemaMatematicas::Absoluto(double x)
{
    return fabs(x);
}

double GD_SistemaMatematicas::CurvarValor(double actual, double destino, double velocidad)
{
    double diferencia=destino-actual;
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

char GD_SistemaMatematicas::Rango(double x, double min, double max, char incluir)
{
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
}

double GD_SistemaMatematicas::BuscarNormal(double x, double y, double z)
{
    return 0;
}

vector3df GD_SistemaMatematicas::Seguir( vector3df PosicionEntrada1, float anguloY,vector3df PosicionEntrada2, float distancia,float altura,float angulo=180, float dureza=15)
{
      vector3df Salida;
	double px = PosicionEntrada1.X;
	double py = PosicionEntrada1.Y;
	double pz = PosicionEntrada1.Z;
	double pa = Capar(anguloY+angulo);
	double cx = PosicionEntrada2.X;
	double cy = PosicionEntrada2.Y;
	double cz = PosicionEntrada2.Z;
	cx = CurvarValor(cx,MueveX(px ,pa ,distancia),dureza);
	cy = CurvarValor(cy,py+altura,dureza/2);
	cz = CurvarValor(cz,MueveZ(pz ,pa ,distancia),dureza);
//	printf("X: %f, Y: %f, Z: %f\n",cx,cy,cz);
     Salida.set(cx,cy,cz);
     return Salida;
}


float GD_SistemaMatematicas::Rad(float Deg)
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
