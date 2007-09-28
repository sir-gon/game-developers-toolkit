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
* \class GDT::Nodo::Camara
*
* Crea y maneja las c&aacute;maras. Permite manejarlas por teclado o mouse,
* orientarlas a gusto y darles el comportamiento que la aplicaci&oacute;n requiera.
*
* Por ejemplo, nos permite dejar la c&aacute;mara detr&aacute;s de un personaje
* para juegos de tercera persona, o puede ser de primera persona.
*/

#include "gd_camara.h" // class's header file

// class constructor
GDT::Nodo::Camara::Camara()
{
	// insert your code here
}

// class destructor
GDT::Nodo::Camara::~Camara()
{
	// insert your code here
}

/*!
* 
* \param tipo puede ser:
*
*  - Tipo_Normal
*   Crea una c&aacute;mara estandar.
*  - Tipo_FPS
*   Crea la c&aacute;mara y la controla mediante el mouse y teclado.
*  - Tipo_Modelador
*   Crea la c&aacute;mara y se maneja mediante el mouse haciendo clic y moviendo el mouse.
* 
* Ejemplo:
* \code
* camara.Crear( Tipo_FPS );
* \endcode
*/

void GDT::Nodo::Camara::Crear ( int tipo )
{
	RegistrarDevice ( Sistema::device );
	ISceneManager* mismgr=Sistema::device->getSceneManager();

	if ( tipo == 3 )
		nodc = mismgr->addCameraSceneNodeFPS ( 0,70.0f,50.0f );

	if ( tipo == 2 )
		nodc = mismgr->addCameraSceneNodeMaya();


	if ( tipo == 1 )
		nodc = mismgr->addCameraSceneNode();


	nodon = nodc;

	if ( !nodon ) printf ( "ERROR: No se pudo Crear La camara.\n" );
}

/*!
* \param x,y,z son las coordenadas de la posici&oacute;ndonde 
* debe mirar la c&aacute;mara
*/
void GDT::Nodo::Camara::Orientar ( float x, float y, float z )
{
	nodc->setTarget ( vector3df ( x,y,z ) );
}
/*!
* \param destino es un vector posici&oacute;n al cual la 
* c&aacute;mara debe apuntar.
*/
void GDT::Nodo::Camara::Orientar ( vector3df destino )
{
	nodc->setTarget ( destino );
}

/*! */
double GDT::Nodo::Camara::Profundidad()
{
	return distancia;
}

/*! */
void GDT::Nodo::Camara::Profundidad ( float rango )
{
	distancia= ( double ) rango;
	nodc->setFarValue ( ( f32 ) distancia );
}

/*!
* \return el vector posici&oacute;n hacia donde est&aacute; mirando la c&aacute;mara.
*/
vector3df GDT::Nodo::Camara::RetornarObjetivo()
{
	return nodc->getTarget();
}

/*! */
vector3df GDT::Nodo::Camara::Seguir ( vector3df PosicionEntrada1, float anguloY,vector3df PosicionEntrada2, float distancia,float altura,float angulo, float durezaX, float durezaY, float durezaZ )
{
	vector3df Salida;
	double px = PosicionEntrada1.X;
	double py = PosicionEntrada1.Y;
	double pz = PosicionEntrada1.Z;
	double pa = GDT::Matematicas::Grados ( anguloY+angulo );
	double cx = PosicionEntrada2.X;
	double cy = PosicionEntrada2.Y;
	double cz = PosicionEntrada2.Z;
	cx = GDT::Matematicas::CurvarValor ( ( float ) cx, ( float ) GDT::Matematicas::MueveX ( px ,pa ,distancia ),durezaX );
	cy = GDT::Matematicas::CurvarValor ( ( float ) cy, ( float ) py+altura,durezaY );
	cz = GDT::Matematicas::CurvarValor ( ( float ) cz, ( float ) GDT::Matematicas::MueveZ ( pz ,pa ,distancia ),durezaZ );
	Salida.set ( ( float ) cx, ( float ) cy, ( float ) cz );
	return Salida;
}

/*!
* Cabe resaltar que lo hace con suavizado ajustable.
* \param PosicionEntrada1 es el punto a seguir.
* \param anguloY
* \param distancia es la distancia entre la c&aacute;mara y el objeto.
* \param altura es la altura entre la c&aacute;mara y el objeto.
* \param angulo es el &aacute;ngulo a que esta la c&aacute;mara, es decir 
* 270 esta atr&aacute;s del objeto 90 a un lado del objeto etc.
* \param durezaX,durezaY,durezaZ la dureza con la que se mueve 
* la c&aacute;mara. Un valor bajo da mayor suavizado, un valor alto 
* da una c&aacute;mara mas r&aacute;pido.
*/
void GDT::Nodo::Camara::Perseguir ( vector3df PosicionEntrada1, float anguloY, double distancia, double altura, double angulo, float durezaX, float durezaY, float durezaZ )
{
	vector3df PosicionEntrada2 = nodc->getPosition();
	Posicionar (
	    Seguir ( PosicionEntrada1,
	             anguloY,
	             PosicionEntrada2,
	             ( float ) distancia,
	             ( float ) altura,
	             ( float ) angulo,
	             durezaX,
	             durezaY,
	             durezaZ
	           )
	);
	Orientar ( PosicionEntrada1 );
}

/*!
* Cabe resaltar que lo hace con suavizado ajustable.
* \param nodoncio es el punto a seguir.
* \param distancia es la distancia entre la c&aacute;mara y el objeto.
* \param altura es la altura entre la c&aacute;mara y el objeto.
* \param angulo es el &aacute;ngulo a que esta la c&aacute;mara, es decir 
* 270 esta atr&aacute;s del objeto 90 a un lado del objeto etc.
* \param durezaX,durezaY,durezaZ la dureza con la que se mueve 
* la c&aacute;mara. Un valor bajo da mayor suavizado, un valor alto 
* da una c&aacute;mara mas r&aacute;pido.
*/
void GDT::Nodo::Camara::Perseguir ( NodoBase nodoncio,double distancia,double altura,double angulo, float durezaX, float durezaY, float durezaZ )
{
	vector3df PosicionEntrada2 = nodc->getPosition();
	Posicionar (
	    Seguir (
	        nodoncio.Posicion(),
	        nodoncio.RotacionY(),
	        PosicionEntrada2,
	        ( float ) distancia,
	        ( float ) altura,
	        ( float ) angulo,
	        durezaX,
	        durezaY,
	        durezaZ
	    )
	);
	Orientar ( nodoncio.Posicion() );
}

/*!
* \param nodoncio es el punto a seguir.
* \param distancia es la distancia entre la c&aacute;mara y el objeto.
* \param altura es la altura entre la c&aacute;mara y el objeto.
* \param angulo es el &aacute;ngulo a que esta la c&aacute;mara, es decir 
* 270 esta atr&aacute;s del objeto 90 a un lado del objeto etc.
* \param dureza la dureza con la que se mueve la c&aacute;mara.
* Un valor bajo da mayor suavizado, un valor alto da una c&aacute;mara 
* mas r&aacute;pido.
*/
void GDT::Nodo::Camara::Perseguir ( NodoBase nodoncio, double distancia, double altura, double angulo, double dureza )
{
	vector3df PosicionEntrada2 = nodc->getPosition();
	Posicionar (
	    Seguir (
	        nodoncio.Posicion(),
	        nodoncio.RotacionY(),
	        PosicionEntrada2,
	        ( float ) distancia,
	        ( float ) altura,
	        ( float ) angulo,
	        ( float ) dureza
	    )
	);
	Orientar ( nodoncio.Posicion() );
}

//Compatibilidad hacia atr&aacute;s
/*!
* \deprecated Se ha dejado solo por compatibilidad hacia atr&aacute;s
*/
void GDT::Nodo::Camara::Perseguir ( vector3df PosicionEntrada1, float anguloY,double distancia,double altura,double angulo, double dureza )
{
	//printf("tipo = %d\n", tipo);
	vector3df PosicionEntrada2 = nodc->getPosition();

	Posicionar (
	    Seguir (
	        PosicionEntrada1,
	        ( float ) anguloY,
	        PosicionEntrada2,
	        ( float ) distancia,
	        ( float ) altura,
	        ( float ) angulo,
	        ( float ) dureza
	    )
	);

	Orientar ( PosicionEntrada1 );

}

/*!
* \deprecated Se ha dejado solo por compatibilidad hacia atr&aacute;s
*/
void GDT::Nodo::Camara::Perseguir ( NodoBase nodoncio,double distancia,double altura,double angulo )
{
	Posicionar ( nodoncio.Posicion() );
	MoverY ( ( float ) altura );
	Mover (
	    ( float ) cos ( ( float ) ( nodoncio.RotacionY() +angulo ) *3.14159265359/180 )
	    * ( float ) distancia,
	    0,
	    ( float ) -sin ( ( float ) ( nodoncio.RotacionY() +angulo ) *3.14159265359/180 )
	    * ( float ) distancia
	);
	Orientar ( nodoncio.Posicion() );
}
//Fin compatibilidad hacia atr&aacute;s

/*! */
void GDT::Nodo::Camara::CrearColision ( Escenario scen, float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz )
{
	ITriangleSelector* selector = scen.RetornarDatos();

	ISceneManager* mismgr=midevice->getSceneManager();

	scene::ISceneNodeAnimator* anim = mismgr->createCollisionResponseAnimator (
	                                      selector, nodon, core::vector3df ( radiox,radioy,radioz ),
	                                      core::vector3df ( transx,transy,transz ),
	                                      core::vector3df ( grax,gray,graz ) );
	nodon->addAnimator ( anim );
	anim->drop();
}
