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
      Crea una c&aacute;mara estandar.
    - Tipo_FPS
      Crea la c&aacute;mara y la controla mediante el mouse y teclado.
    - Tipo_Modelador
      Crea la c&aacute;mara y se maneja mediante el mouse haciendo clic y moviendo el mouse.

Ejemplo:
\code
c&aacute;mara.Crear( Tipo_FPS );
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
    
    if(!nodon) printf("ERROR: No se pudo Crear La cámara.\n");    
}

/*!
\param x,y,z son las coordenadas de la posición donde debe mirar la c&aacute;mara
*/
void GD_Camara::Orientar(float x, float y, float z)
{
     nodc->setTarget(vector3df(x,y,z));
}
/*!
\param destino es un vector posición al cual la c&aacute;mara debe apuntar.
*/
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
 
/*!
\return el vector posición hacia donde está mirando la c&aacute;mara.
*/
vector3df GD_Camara::RetornarObjetivo()
{
    return nodc->getTarget();
}

/*!

*/
vector3df GD_Camara::Seguir(vector3df PosicionEntrada1, float anguloY,vector3df PosicionEntrada2, float distancia,float altura,float angulo, float durezaX, float durezaY, float durezaZ)
{
    vector3df Salida;
	double px = PosicionEntrada1.X;
	double py = PosicionEntrada1.Y;
	double pz = PosicionEntrada1.Z;
	double pa = GD_Matematicas::Capar(anguloY+angulo);
	double cx = PosicionEntrada2.X;
	double cy = PosicionEntrada2.Y;
	double cz = PosicionEntrada2.Z;
	cx = GD_Matematicas::CurvarValor((float)cx,(float)GD_Matematicas::MueveX(px ,pa ,distancia),durezaX);
	cy = GD_Matematicas::CurvarValor((float)cy,(float)py+altura,durezaY);
 	cz = GD_Matematicas::CurvarValor((float)cz,(float)GD_Matematicas::MueveZ(pz ,pa ,distancia),durezaZ);
    Salida.set((float)cx,(float)cy,(float)cz);
    return Salida;
}

/*!
Cabe resaltar que lo hace con suavizado ajustable.
\param PosicionEntrada1 es el punto a seguir.
\param anguloY
\param distancia es la distancia entre la c&aacute;mara y el objeto.
\param altura es la altura entre la c&aacute;mara y el objeto.
\param angulo es el ángulo a que esta la c&aacute;mara, es decir 270 esta atrás del objeto 90 a un lado del objeto etc.
\param durezaX,durezaY,durezaZ la dureza con la que se mueve la c&aacute;mara. Un valor bajo da mayor suavizado, un valor alto da una c&aacute;mara mas rígida.
*/
void GD_Camara::Perseguir(vector3df PosicionEntrada1, float anguloY, double distancia, double altura, double angulo, float durezaX, float durezaY, float durezaZ)
{
    vector3df PosicionEntrada2 = nodc->getPosition();
    Posicionar(
		Seguir(PosicionEntrada1,
			anguloY,
			PosicionEntrada2,
			(float)distancia,
			(float)altura,
			(float)angulo,
			durezaX,
			durezaY,
			durezaZ
		)
	);
    Orientar(PosicionEntrada1);
}

/*!
Cabe resaltar que lo hace con suavizado ajustable.
\param nodoncio es el punto a seguir.
\param distancia es la distancia entre la c&aacute;mara y el objeto.
\param altura es la altura entre la c&aacute;mara y el objeto.
\param angulo es el ángulo a que esta la c&aacute;mara, es decir 270 esta atrás del objeto 90 a un lado del objeto etc.
\param durezaX,durezaY,durezaZ la dureza con la que se mueve la c&aacute;mara. Un valor bajo da mayor suavizado, un valor alto da una c&aacute;mara mas rígida.
*/
void GD_Camara::Perseguir(GD_Nodo nodoncio,double distancia,double altura,double angulo, float durezaX, float durezaY, float durezaZ)
{
	vector3df PosicionEntrada2 = nodc->getPosition();
	Posicionar(
		Seguir(
			nodoncio.Posicion(),
			nodoncio.RotacionY(),
			PosicionEntrada2,
			(float)distancia,
			(float)altura,
			(float)angulo,
			durezaX,
			durezaY,
			durezaZ
		)
	);
	Orientar(nodoncio.Posicion());
}

/*!
\param nodoncio es el punto a seguir.
\param distancia es la distancia entre la c&aacute;mara y el objeto.
\param altura es la altura entre la c&aacute;mara y el objeto.
\param angulo es el ángulo a que esta la c&aacute;mara, es decir 270 esta atrás del objeto 90 a un lado del objeto etc.
\param dureza
*/
void GD_Camara::Perseguir(GD_Nodo nodoncio, double distancia, double altura, double angulo, double dureza)
{
	vector3df PosicionEntrada2 = nodc->getPosition();
	Posicionar(
		Seguir(
			nodoncio.Posicion(),
			nodoncio.RotacionY(),
			PosicionEntrada2,
			(float)distancia,
			(float)altura,
			(float)angulo,
			(float)dureza
		)
	);
	Orientar(nodoncio.Posicion());
}

//Compatibilidad hacia atr&aacute;s
/*!
\deprecated
*/
void GD_Camara::Perseguir(vector3df PosicionEntrada1, float anguloY,double distancia,double altura,double angulo, double dureza)
{
	//printf("tipo = %d\n", tipo);
	vector3df PosicionEntrada2 = nodc->getPosition();

	Posicionar(
		Seguir(
			PosicionEntrada1,
			(float)anguloY,
			PosicionEntrada2,
			(float)distancia,
			(float)altura,
			(float)angulo,
			(float)dureza
		)
	);

	Orientar(PosicionEntrada1);

}

/*!
\deprecated
*/
void GD_Camara::Perseguir(GD_Nodo nodoncio,double distancia,double altura,double angulo)
{
	Posicionar(nodoncio.Posicion());
	MoverY((float)altura);
	Mover(
		(float) cos( (float) (nodoncio.RotacionY()+angulo)*3.14159265359/180)
				* (float) distancia,
		0,
		(float) -sin( (float) (nodoncio.RotacionY()+angulo)*3.14159265359/180)
				* (float) distancia
	);
	Orientar(nodoncio.Posicion());
}
//Fin compatibilidad hacia atr&aacute;s

/*!
*/
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
