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

#include "gd_camara.h" // class's header file


extern ICameraSceneNode *camaras_n[3];
extern bool camaras_a[3];
extern rect< s32 >  camaras_v[3];

int camara_contador;

// class constructor
GD_Camara::GD_Camara()
{
	// insert your code here
}

// class destructor
GD_Camara::~GD_Camara()
{
	// insert your code here
}


//! Crea una camara
/**
Parametros:

    Tipo => Tipo_Normal
            Tipo_FPS ->  se orienta con el mouse y las flechas para moverse
            TIpo_Modelador -> se rota manteniedo click y moviendo, click derecho mover, click derecho e izquierdo para zoom
*/
void GD_Camara::Crear(int tipo)
{


    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=GD_Sistema::device->getSceneManager();



     if(tipo == 3)
	    nodc = mismgr->addCameraSceneNodeFPS(0,70.0f,50.0f);

     if(tipo == 2)
	    nodc = mismgr->addCameraSceneNodeMaya();


     if(tipo == 1)
        nodc = mismgr->addCameraSceneNode();


    nodon = nodc;
    
 /*   camara_contador++;
    
    rect< s32 > viewport(0,0,640,480);
    
    camaras_n[0] = nodc;
    camaras_a[0] = true;
    camaras_v[0] = viewport;  
    
    miID = camara_contador-1;*/


}
/*
void GD_Camara::AreaRender(int x1, int y1, int x2, int y2)
{
         rect< s32 > viewporto(x1,y1,x2,y2);
         camaras_v[miID] = viewporto;  
}

void GD_Camara::Activada(bool opc)
{
      camaras_a[miID] = opc;
}
*/
void GD_Camara::Orientar(float x, float y, float z)
{
     nodc->setTarget(vector3df(x,y,z));
}

void GD_Camara::Orientar(vector3df poso)
{
     nodc->setTarget(poso);

}

double GD_Camara::Profundidad()
{
   return distancia;
}

void GD_Camara::Profundidad(float rango)
{
   distancia=(double)rango;
   nodc->setFarValue((f32)distancia);
}

//! Devuelve el vector hacia el que esta orientada la camara
vector3df GD_Camara::RetornarObjetivo()
{
    return nodc->getTarget();
}


int GD_Camara::Capar(int ang)
{
    return ang%360;
}

double GD_Camara::Capar(double ang)
{
    while(ang>360.0)
        ang=ang-360.0;
    while(ang<0)
        ang=ang+360.0;
    return ang;
}

double GD_Camara::CurvarValor(double actual, double destino, double velocidad)
{
    double diferencia=destino-actual;
    if(velocidad==0)
        return actual;
    else
        return actual+(diferencia*(1/velocidad));
}

double GD_Camara::CurvarAngulo(double actual, double destino, double velocidad)
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


double GD_Camara::GiroAngulo(double mirando, double meta)
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

double GD_Camara::MueveX(double x, double angulo, double velocidad)
{
     /*double angulop = Rad(angulo);
     double xf;
     xf = x + (velocidad*(double)sin(angulop));
     return xf; */

     return x+velocidad*sin(Rad(angulo));
}

double GD_Camara::MueveY(double y, double angulo, double velocidad)
{
    return y+velocidad*tan(Rad(angulo));

}

float GD_Camara::Rad(float Deg)
{
Deg = (Deg/180.0f); //Divide by 180
Deg = Deg*3.14159f; //Multuply by approximation to PI
return (float)Deg;
}

double GD_Camara::MueveZ(double z, double angulo, double velocidad)
{
     return z+velocidad*cos(Rad(angulo));
}

vector3df GD_Camara::Seguir(vector3df PosicionEntrada1, float anguloY,vector3df PosicionEntrada2, float distancia,float altura,float angulo, float dureza)
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
	cy = CurvarValor(cy,py+altura,dureza/8);
	cz = CurvarValor(cz,MueveZ(pz ,pa ,distancia),dureza);
//	printf("X: %f, Y: %f, Z: %f\n",cx,cy,cz);
     Salida.set(cx,cy,cz);
     return Salida;
}

void GD_Camara::Perseguir(vector3df PosicionEntrada1, float anguloY,double distancia,double altura,double angulo, double dureza)
{
//printf("tipo = %d\n", tipo);
 vector3df PosicionEntrada2 = nodc->getPosition();

         Posicionar(Seguir(PosicionEntrada1, anguloY, PosicionEntrada2,distancia,altura,angulo,dureza));
	    Orientar(PosicionEntrada1);

}

void GD_Camara::CrearColision( GD_Escenario scen, float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz)
{

    ITriangleSelector* selector = scen.RetornarDatos();

    ISceneManager* mismgr=midevice->getSceneManager();

	scene::ISceneNodeAnimator* anim = mismgr->createCollisionResponseAnimator(
		selector, nodon, core::vector3df(radiox,radioy,radioz),
		core::vector3df(transx,transy,transz),
		core::vector3df(grax,gray,graz));
	nodon->addAnimator(anim);
	//anim->drop();
}

void GD_Camara::Perseguir(GD_Nodo nodoncio,double distancia,double altura,double angulo, double dureza)
{

 vector3df PosicionEntrada2 = nodc->getPosition();
 Posicionar(Seguir(nodoncio.Posicion(), nodoncio.RotacionY(), PosicionEntrada2,distancia,altura,angulo,dureza));
 Orientar(nodoncio.Posicion());
 
}
