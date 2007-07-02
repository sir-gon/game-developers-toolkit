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

#include "gd_camara.h" // class's header file


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

/*!

\param tipo puede ser:

    - Tipo_Normal
      Crea una c�mara estandar.
    - Tipo_FPS
      Crea la c�mara y la controla mediante el mouse y teclado.
    - Tipo_Modelador
      Crea la c�mara y se maneja mediante el mouse haciendo clic y moviendo el mouse.

Ejemplo:
\code
Camara.Crear( Tipo_FPS );
\endcode
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
    
    if(!nodon) printf("ERROR: No se pudo Crear La Camara.\n");    
}

/*///////////////////////////////////////////////////////////////////
Establece la posicion hacia donde la camara debe mirar
*////////////////////////////////////////////////////////////////////
void GD_Camara::Orientar(float x, float y, float z)
{
     nodc->setTarget(vector3df(x,y,z));
}
/*///////////////////////////////////////////////////////////////////
Establece la posicion hacia donde la camara debe mirar
*////////////////////////////////////////////////////////////////////
void GD_Camara::Orientar(vector3df destino)
{
     nodc->setTarget(destino);
}

/*! */
double GD_Camara::Profundidad()
{
   return distancia;
}
/*! */
void GD_Camara::Profundidad(float rango)
{
   distancia=(double)rango;
   nodc->setFarValue((f32)distancia);
}
 
/*///////////////////////////////////////////////////////////////////
Devuelve el vector hacia el que esta orientada la camara
*////////////////////////////////////////////////////////////////////
vector3df GD_Camara::RetornarObjetivo()
{
    return nodc->getTarget();
}

/*///////////////////////////////////////////////////////////////////
Posiciona la camara detras de un punto en el espacio con suavizado
*////////////////////////////////////////////////////////////////////
vector3df GD_Camara::Seguir(vector3df PosicionEntrada1, float anguloY,vector3df PosicionEntrada2, float distancia,float altura,float angulo, float durezaX, float durezaY, float durezaZ)
{
    vector3df Salida;
	double px = PosicionEntrada1.X;
	double py = PosicionEntrada1.Y;
	double pz = PosicionEntrada1.Z;
	double pa = SisMat.Capar(anguloY+angulo);
	double cx = PosicionEntrada2.X;
	double cy = PosicionEntrada2.Y;
	double cz = PosicionEntrada2.Z;
	cx = SisMat.CurvarValor(cx,SisMat.MueveX(px ,pa ,distancia),durezaX);
	cy = SisMat.CurvarValor(cy,py+altura,durezaY);
 	cz = SisMat.CurvarValor(cz,SisMat.MueveZ(pz ,pa ,distancia),durezaZ);
    Salida.set(cx,cy,cz);
    return Salida;
}

/*///////////////////////////////////////////////////////////////////
Posiciona la c�ara para que "persiga" a un punto, cabe resaltar que lo hace con suavizado ajustable. Los siguientes son los par�etros.
PosicionEntrada1 Es el punto a seguir
distancia: la distancia entre la camara y el objeto.
altura: la altura entre la camara y el objeto
Angulo: el �gulo a que esta la camara, es decir 270 esta atr� del objeto 90 a un lado del objeto etc.
DurezaX , Y , Z: la dureza con la que se mueve la camara un valor bajo da mayor suavizado, un valor alto da una camara mas r�ida.
*////////////////////////////////////////////////////////////////////
void GD_Camara::Perseguir(vector3df PosicionEntrada1, float anguloY,double distancia,double altura,double angulo, float durezaX, float durezaY, float durezaZ)
{
    vector3df PosicionEntrada2 = nodc->getPosition();
    Posicionar(Seguir(PosicionEntrada1, anguloY, PosicionEntrada2,distancia,altura,angulo,durezaX,durezaY,durezaZ));
    Orientar(PosicionEntrada1);
}

/*///////////////////////////////////////////////////////////////////
Posiciona la c�ara para que "persiga" a un objeto, cabe resaltar que lo hace con suavizado ajustable. Los siguientes son los par�etros.
GD_Nodo obj es el objeto a perseguir: puede ser GD_Malla, etc.
distancia: la distancia entre la camara y el objeto.
altura: la altura entre la camara y el objeto
Angulo: el �gulo a que esta la camara, es decir 270 esta atr� del objeto 90 a un lado del objeto etc.
DurezaX , Y , Z: la dureza con la que se mueve la camara un valor bajo da mayor suavizado, un valor alto da una camara mas r�ida.
*////////////////////////////////////////////////////////////////////
void GD_Camara::Perseguir(GD_Nodo nodoncio,double distancia,double altura,double angulo, float durezaX, float durezaY, float durezaZ)
{
    vector3df PosicionEntrada2 = nodc->getPosition();
    Posicionar(Seguir(nodoncio.Posicion(), nodoncio.RotacionY(), PosicionEntrada2,distancia,altura,angulo,durezaX,durezaY,durezaZ));
    Orientar(nodoncio.Posicion());
}

void GD_Camara::Perseguir(GD_Nodo nodoncio,double distancia,double altura,double angulo)
{
 Posicionar(nodoncio.Posicion());
 MoverY(altura);
 Mover(cos((nodoncio.RotacionY()+angulo)*3.14159265359/180)*distancia,0,-sin((nodoncio.RotacionY()+angulo)*3.14159265359/180)*distancia);
 Orientar(nodoncio.Posicion());
}

//Compatibilidad hacia atr&aacute;s
void GD_Camara::Perseguir(vector3df PosicionEntrada1, float anguloY,double distancia,double altura,double angulo, double dureza)
{
//printf("tipo = %d\n", tipo);
 vector3df PosicionEntrada2 = nodc->getPosition();

         Posicionar(Seguir(PosicionEntrada1, anguloY, PosicionEntrada2,distancia,altura,angulo,dureza));
	    Orientar(PosicionEntrada1);

}

void GD_Camara::Perseguir(GD_Nodo nodoncio,double distancia,double altura,double angulo, double dureza)
{

 vector3df PosicionEntrada2 = nodc->getPosition();
 Posicionar(Seguir(nodoncio.Posicion(), nodoncio.RotacionY(), PosicionEntrada2,distancia,altura,angulo,dureza));
 Orientar(nodoncio.Posicion());
 
}
//Fin compatibilidad hacia atr&aacute;s


void GD_Camara::CrearColision( GD_Escenario scen, float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz)
{
    ITriangleSelector* selector = scen.RetornarDatos();

    ISceneManager* mismgr=midevice->getSceneManager();

	scene::ISceneNodeAnimator* anim = mismgr->createCollisionResponseAnimator(
		selector, nodon, core::vector3df(radiox,radioy,radioz),
		core::vector3df(transx,transy,transz),
		core::vector3df(grax,gray,graz));
	nodon->addAnimator(anim);
	anim->drop();
}
