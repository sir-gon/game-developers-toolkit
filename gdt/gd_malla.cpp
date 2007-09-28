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

#include "gd_malla.h" // class's header file

// class constructor
GDT::Nodo::Malla::Malla()
{

}


// class destructor
GDT::Nodo::Malla::~Malla()
{
	// insert your code here
}

/*!
\param filename Archivo con la malla a cargar

Los formatos soportados son:
    - 3D Studio meshes (.3ds)
    - Alias Wavefront Maya (.obj)
    - Cartography shop 4 (.csm)
    - COLLADA (.xml, .dae)
    - DeleD (.dmf)
    - FSRad oct (.oct)
    - Microsoft DirectX (.x)
    - Milkshape (.ms3d)
    - My3DTools 3 (.my3D)
    - Pulsar LMTools (.lmts)
    - Quake 3 levels (.bsp)
    - Quake 2 models (.md2)
    - Ogre .mesh
    - Blitz3D. B3D

\image html mallacargar.png

Ejemplo:
\code
Dragon.Cargar ("media/dragon.x");
\endcode
*/
void GDT::Nodo::Malla::Cargar ( char *filename )
{


	RegistrarDevice ( Sistema::device ); //Asignando el dispositivo principal al dispositivo de escena de la clase nodo.

	mesh_smgr=Sistema::device->getSceneManager(); //Creando un Manejador de escena (Scene Manager)

	mesh = mesh_smgr->getMesh ( filename ); //Cargando el objetos segun el archivo
	static_mesh=mesh->getMesh ( 0 );// Malla estatica


	//Si la malla es estatica
	//if(Estatica==true)
	//{
	//nodon = mesh_smgr->addMeshSceneNode(static_mesh); //Creando el nodo del objeto estatico cargado
	//}
	//else
	//{



	nodoAM=mesh_smgr->addAnimatedMeshSceneNode ( mesh );
	nodon=nodoAM;


	//}

	if ( !nodon ) printf ( "ERROR: No se pudo Cargar la malla, %s.\n", filename );


	coloralphaA = 100;
	coloralphaD = 100;
	coloralphaEm = 100;
	coloralphaE = 100;

	for ( u32 i=0; i< nodon->getMaterialCount(); ++i )
	{
		nodon->getMaterial ( i ).EmissiveColor.set ( 100,80,80,80 );
		nodon->getMaterial ( i ).DiffuseColor.set ( 100,100,100,100 );
	}

	intersec_coli_a = mesh_smgr->addEmptySceneNode();
	intersec_coli_b = mesh_smgr->addEmptySceneNode();
	intersec_coli_c = mesh_smgr->addEmptySceneNode();
	intersec_coli_d = mesh_smgr->addEmptySceneNode();
	intersec_coli_e = mesh_smgr->addEmptySceneNode();
	intersec_coli_f = mesh_smgr->addEmptySceneNode();
	DummyNodo = mesh_smgr->addEmptySceneNode();




}

/*!
Para ser usada con parallax mapping y dem&aacute;s shaders,

\param filename la ruta del archivo con la malla.

Ejemplo:
\code
Pared.CargarTengentes("Cuarto.x");
\endcode
*/
void GDT::Nodo::Malla::CargarTangentes ( char *filename )
{

	RegistrarDevice ( Sistema::device ); //Asignando el dispositivo principal al dispositivo de escena de la clase nodo.

	mesh_smgr=Sistema::device->getSceneManager(); //Creando un Manejador de escena (Scene Manager)

	mesh = mesh_smgr->getMesh ( filename ); //Cargando el objetos segun el archivo
	static_mesh=mesh->getMesh ( 0 );// Malla estatica


	tangentMesh = midevice->getSceneManager()->getMeshManipulator()->createMeshWithTangents (
	                  static_mesh );
	nodo_tangentes = mesh_smgr->addMeshSceneNode ( tangentMesh );
	nodon=nodo_tangentes;


	intersec_coli_a = mesh_smgr->addEmptySceneNode();
	intersec_coli_b = mesh_smgr->addEmptySceneNode();
	intersec_coli_c = mesh_smgr->addEmptySceneNode();
	intersec_coli_d = mesh_smgr->addEmptySceneNode();
	intersec_coli_e = mesh_smgr->addEmptySceneNode();
	intersec_coli_f = mesh_smgr->addEmptySceneNode();
	DummyNodo = mesh_smgr->addEmptySceneNode();
}

/*!
\deprecated vea CrearCaja().
*/
void GDT::Nodo::Malla::CrearCubo( )
{
	// REEMPLAZADO PARA COMPATIBILIDAD CON VC+ 2005 EXPRESS
	//RegistrarDevice(Sistema::Sistema::device); //Asignando el dispositivo principal al dispositivo de escena de la clase nodo.
	RegistrarDevice ( Sistema::device ); //Asignando el dispositivo principal al dispositivo de escena de la clase nodo.
	mesh_smgr=Sistema::device->getSceneManager(); //Creando un Manejador de escena (Scene Manager)

	static_mesh=DibujarCubo();

	tangentMesh = midevice->getSceneManager()->getMeshManipulator()->createMeshWithTangents ( static_mesh );
	nodo_tangentes = mesh_smgr->addMeshSceneNode ( tangentMesh );
	nodon=nodo_tangentes;

	//nodon=mesh_smgr->addMeshSceneNode(static_mesh);

	tangentMesh = midevice->getSceneManager()->getMeshManipulator()->createMeshWithTangents ( static_mesh );
	nodo_tangentes = mesh_smgr->addMeshSceneNode ( tangentMesh );
	nodon=nodo_tangentes;


	if ( !nodon ) printf ( "ERROR: No se pudo Crear el cubo.\n" );

	ColorDifuso ( 100,100,100 );

	coloralphaA = 100;
	coloralphaD = 100;
	coloralphaEm = 100;
	coloralphaE = 100;


	intersec_coli_a = mesh_smgr->addEmptySceneNode();
	intersec_coli_b = mesh_smgr->addEmptySceneNode();
	intersec_coli_c = mesh_smgr->addEmptySceneNode();
	intersec_coli_d = mesh_smgr->addEmptySceneNode();
	intersec_coli_e = mesh_smgr->addEmptySceneNode();
	intersec_coli_f = mesh_smgr->addEmptySceneNode();

	DummyNodo = mesh_smgr->addEmptySceneNode();

}

/*!
\param tamx ancho
\param tamy alto
\param tamz largo

Ejemplo:
\code
Caja.CreaCaja(10,10,10);
\endcode
*/
void GDT::Nodo::Malla::CrearCaja ( float tamx, float tamy, float tamz )
{
	RegistrarDevice ( Sistema::device ); //Asignando el dispositivo principal al dispositivo de escena de la clase nodo.
	mesh_smgr=Sistema::device->getSceneManager(); //Creando un Manejador de escena (Scene Manager)

	static_mesh=DibujarCubo();

	tangentMesh = midevice->getSceneManager()->getMeshManipulator()->createMeshWithTangents (
	                  static_mesh );
	nodo_tangentes = mesh_smgr->addMeshSceneNode ( tangentMesh );
	nodon=nodo_tangentes;
	if ( !nodon ) printf ( "ERROR: No se pudo Crear el cubo.\n" );

//    nodon=mesh_smgr->addMeshSceneNode(static_mesh);
	nodon->setScale ( vector3df ( tamx,tamy,tamz ) );

	ColorDifuso ( 100,100,100 );

	coloralphaA = 100;
	coloralphaD = 100;
	coloralphaEm = 100;
	coloralphaE = 100;

	intersec_coli_a = mesh_smgr->addEmptySceneNode();
	intersec_coli_b = mesh_smgr->addEmptySceneNode();
	intersec_coli_c = mesh_smgr->addEmptySceneNode();
	intersec_coli_d = mesh_smgr->addEmptySceneNode();
	intersec_coli_e = mesh_smgr->addEmptySceneNode();
	intersec_coli_f = mesh_smgr->addEmptySceneNode();

	DummyNodo = mesh_smgr->addEmptySceneNode();
}

/*!
\deprecated vea CrearCaja().

Ejemplo:
\code
Caja.CreaCubo(10,10,10);
\endcode
*/
void GDT::Nodo::Malla::CrearCubo ( float tamx, float tamy, float tamz )
{
	CrearCaja ( tamx,tamy,tamz );
}

/*!
\param tx largo del plano
\param ty ancho del plano

Ejemplo:
\code
Piso.CrearPlano (100, 100);
\endcode
*/
void GDT::Nodo::Malla::CrearPlano ( int tx, int ty )
{
	RegistrarDevice ( Sistema::device ); //Asignando el dispositivo principal al dispositivo de escena de la clase nodo.
	mesh_smgr=Sistema::device->getSceneManager(); //Creando un Manejador de escena (Scene Manager)

	static_mesh=DibujarPlano ( tx,ty );

	tangentMesh = midevice->getSceneManager()->getMeshManipulator()->createMeshWithTangents (
	                  static_mesh );
	nodo_tangentes = mesh_smgr->addMeshSceneNode ( tangentMesh );
	nodon=nodo_tangentes;

//    nodon=mesh_smgr->addMeshSceneNode(static_mesh);

	if ( !nodon ) printf ( "ERROR: No se pudo Crear el Plano.\n" );

	ColorDifuso ( 100,100,100 );

	coloralphaA = 100;
	coloralphaD = 100;
	coloralphaEm = 100;
	coloralphaE = 100;


	intersec_coli_a = mesh_smgr->addEmptySceneNode();
	intersec_coli_b = mesh_smgr->addEmptySceneNode();
	intersec_coli_c = mesh_smgr->addEmptySceneNode();
	intersec_coli_d = mesh_smgr->addEmptySceneNode();
	intersec_coli_e = mesh_smgr->addEmptySceneNode();
	intersec_coli_f = mesh_smgr->addEmptySceneNode();

	DummyNodo = mesh_smgr->addEmptySceneNode();

}

/*!
\param tx ancho
\param ty altura
\param radio el radio basal

Ejemplo:
\code
Tarro.CrearCilindro( 2,2,1 );
\endcode
*/
void GDT::Nodo::Malla::CrearCilindro ( int tx, int ty, f32 radio )
{
	RegistrarDevice ( Sistema::device ); //Asignando el dispositivo principal al dispositivo de escena de la clase nodo.
	mesh_smgr=Sistema::device->getSceneManager(); //Creando un Manejador de escena (Scene Manager)

	static_mesh=DibujarCilindro ( tx, ty, radio );

	tangentMesh = midevice->getSceneManager()->getMeshManipulator()->createMeshWithTangents (
	                  static_mesh );
	nodo_tangentes = mesh_smgr->addMeshSceneNode ( tangentMesh );
	nodon=nodo_tangentes;

//    nodon=mesh_smgr->addMeshSceneNode(static_mesh);


	if ( !nodon ) printf ( "ERROR: No se pudo Crear el Cilindro.\n" );

	ColorDifuso ( 100,100,100 );

	coloralphaA = 100;
	coloralphaD = 100;
	coloralphaEm = 100;
	coloralphaE = 100;


	intersec_coli_a = mesh_smgr->addEmptySceneNode();
	intersec_coli_b = mesh_smgr->addEmptySceneNode();
	intersec_coli_c = mesh_smgr->addEmptySceneNode();
	intersec_coli_d = mesh_smgr->addEmptySceneNode();
	intersec_coli_e = mesh_smgr->addEmptySceneNode();
	intersec_coli_f = mesh_smgr->addEmptySceneNode();

	DummyNodo = mesh_smgr->addEmptySceneNode();


}

/*!
\param tx ancho
\param ty altura
\param radio el radio basal

Ejemplo:
\code
Conito.CrearCono( 2,2,1 );
\endcode
*/
void GDT::Nodo::Malla::CrearCono ( int tx, int ty, f32 radio )
{
	RegistrarDevice ( Sistema::device ); //Asignando el dispositivo principal al dispositivo de escena de la clase nodo.
	mesh_smgr=Sistema::device->getSceneManager(); //Creando un Manejador de escena (Scene Manager)

	static_mesh=DibujarCono ( tx, ty, radio );

	tangentMesh = midevice->getSceneManager()->getMeshManipulator()->createMeshWithTangents (
	                  static_mesh );
	nodo_tangentes = mesh_smgr->addMeshSceneNode ( tangentMesh );
	nodon=nodo_tangentes;

//    nodon=mesh_smgr->addMeshSceneNode(static_mesh);


	if ( !nodon ) printf ( "ERROR: No se pudo Crear el Cono.\n" );

	ColorDifuso ( 100,100,100 );

	coloralphaA = 100;
	coloralphaD = 100;
	coloralphaEm = 100;
	coloralphaE = 100;


	intersec_coli_a = mesh_smgr->addEmptySceneNode();
	intersec_coli_b = mesh_smgr->addEmptySceneNode();
	intersec_coli_c = mesh_smgr->addEmptySceneNode();
	intersec_coli_d = mesh_smgr->addEmptySceneNode();
	intersec_coli_e = mesh_smgr->addEmptySceneNode();
	intersec_coli_f = mesh_smgr->addEmptySceneNode();

	DummyNodo = mesh_smgr->addEmptySceneNode();

}

/*!
\param radio el radio de la esfera.
\param polynum es la precisi&oacute;n. Mientras mayor sea, m&aacute;s pol&iacute;gonos dibujaran la esfera.

Ejemplo:
\code
Bola.CrearEsfera( 10 );
\endcode
*/
void GDT::Nodo::Malla::CrearEsfera ( float radio, int polynum )
{
	RegistrarDevice ( Sistema::device ); //Asignando el dispositivo principal al dispositivo de escena de la clase nodo.
	mesh_smgr=Sistema::device->getSceneManager(); //Creando un Manejador de escena (Scene Manager)

	nodon=mesh_smgr->addSphereSceneNode ( radio, polynum );


	if ( !nodon ) printf ( "ERROR: No se pudo Crear el Esfera.\n" );


	coloralphaA = 100;
	coloralphaD = 100;
	coloralphaEm = 100;
	coloralphaE = 100;

	intersec_coli_a = mesh_smgr->addEmptySceneNode();
	intersec_coli_b = mesh_smgr->addEmptySceneNode();
	intersec_coli_c = mesh_smgr->addEmptySceneNode();
	intersec_coli_d = mesh_smgr->addEmptySceneNode();
	intersec_coli_e = mesh_smgr->addEmptySceneNode();
	intersec_coli_f = mesh_smgr->addEmptySceneNode();

	DummyNodo = mesh_smgr->addEmptySceneNode();

}

/*!
M&aacute;s conocidas como "stencil shadows", todo se hace autom&aacute;ticamente seg&uacute;n las luces que haya y su posici&oacute;. Si se desea controlar el n&uacute;mero de luces que proyecten sombras Luz tiene comandos para configurar si crean o no sombras.

Ejemplo:
\code
Dragon.ProyectarSombra();
\endcode
*/
void GDT::Nodo::Malla::ProyectarSombra()
{
	nodoAM->addShadowVolumeSceneNode();
}


/*!
Devuelve el cuadro instantaneo en el que en ese momento esta la malla

Ejemplo:
\code
Cuadro = Dragon.RetonarCuadro();
\endcode
*/
int GDT::Nodo::Malla::RetornarCuadro()
{
	return nodoAM->getFrameNr();
}

/*!
\param CuadrosPorSegundo son los cuadros por segundo (CPS)
*/
void GDT::Nodo::Malla::VelocidadAnimacion ( int CuadrosPorSegundo )
{
	RegistrarVelAni ( CuadrosPorSegundo );
	nodoAM->setAnimationSpeed ( ( f32 ) velani );
}

/*!
Ejemplo:
\code
Dragon.CuadroActual(120);
\endcode
*/
void GDT::Nodo::Malla::CuadroActual ( int cuadro )
{
	nodoAM->setCurrentFrame ( cuadro );
	nodoAM->setAnimationSpeed ( ( f32 ) velani );
}

//! Establece el ciclo de la animacion.
void GDT::Nodo::Malla::CicloCuadros ( int ini, int fin )
{

	// Evita el error al colocar 0 como el inicio
	if ( ini < 1 ) ini = 1;

	if ( controlani )
	{
		if ( ( ini!=old_ini ) & ( fin!=old_fin ) )
		{

//            printf("old ini = %d, old fin = %d, Cambiando a ini = %d, fin = %d\n", old_ini,old_fin,ini,fin);
			old_ini = ini;
			old_fin = fin;
//7196823
			nodoAM->setFrameLoop ( ini, fin );
			nodoAM->setAnimationSpeed ( ( f32 ) velani );
		}
	}
	else
	{
		nodoAM->setFrameLoop ( ini, fin );
		nodoAM->setAnimationSpeed ( ( f32 ) velani );
	}

}

/*!
\param tipoAnimacionMD2 son los nombres de los ciclos, pueden ser:
    - STAND
    - RUN
    - ATTACK
    - PAIN_A
    - PAIN_B
    - PAIN_C
    - JUMP
    - FLIP
    - SALUTE
    - FALLBACK
    - WAVE
    - POINT
    - CROUCH_STAND
    - CROUCH_WALK
    - CROUCH_ATTACK
    - CROUCH_PAIN
    - CROUCH_DEATH
    - DEATH_FALLBACK

Ejemplo:
\code
Dragon.CicloMD2( RUN );
\endcode
*/
void GDT::Nodo::Malla::CicloMD2 ( irr::scene::EMD2_ANIMATION_TYPE tipoAnimacionMD2 )
{

//     printf("tipoAnimacionMD2 = %d, old = %d\n",tipoAnimacionMD2,old_aniTipoActual);
	if ( controlani )
	{
		if ( tipoAnimacionMD2 != old_aniTipoActual )
		{
			nodoAM->setMD2Animation ( tipoAnimacionMD2 );
			old_aniTipoActual = tipoAnimacionMD2;

		}
	}
	else
		nodoAM->setMD2Animation ( tipoAnimacionMD2 );

	nodoAM->setAnimationSpeed ( ( f32 ) velani );
}


void GDT::Nodo::Malla::Repeticion ( bool enCiclo )
{
	nodoAM->setLoopMode ( enCiclo );
}

void GDT::Nodo::Malla::ControlAnimacion ( bool control )
{
	controlani=control;
}

/*!
Se usa para remplazar un Malla con un nodo de un hueso para poder manejarlo.
Se usa conjuntamente con RetornarNodoHuesoX y RetornarNodoHuesoMS3D

Ejemplo:
\code
nHueso.Remplazar( RetornarNodoHuesoX(brazo ));
\endcode
*/
void GDT::Nodo::Malla::Reemplazar ( ISceneNode* nod_R )
{
	nodon=nod_R;
}

/*!
Para que al remplazarlo con el comando Reemplazar() pueda "anclarle" un objeto, por ejemplo una espada en la mano y que as&iacute; se mueva y rote junto con la mano incluyendo la animaci&oacute;n, cabe resaltar que los formatos con animaci&oacute;n por esqueleto son el X y MS3D

\image html anclarahueso.png

Ejemplo:
\code
HuesoManoD.Reemplazar( Protagonista.RetornarNodoHuesoX( "Bip01_R_Hand" ) );
HuesoManoD.Anclar( Espada )
\endcode
*/
ISceneNode* GDT::Nodo::Malla::RetornarNodoHuesoX ( c8* Nombre )
{

	ISceneNode* nodo_hueso = nodoAM->getXJointNode ( Nombre );
	return nodo_hueso;
}

/*!
Para que al remplazarlo con el comando Reemplazar() pueda "anclarle" un objeto, por ejemplo una espada en la mano y que as&iacute; se mueva y rote junto con la mano incluyendo la animaci&oacute;n, cabe resaltar que los formatos con animaci&oacute;n por esqueleto son el X y MS3D

\image html anclarahueso.png
*/
ISceneNode* GDT::Nodo::Malla::RetornarNodoHuesoMS3D ( c8* Nombre )
{

	ISceneNode* nodo_hueso = nodoAM->getMS3DJointNode ( Nombre );
	return nodo_hueso;
}

//From Irrforge.org
IMesh* GDT::Nodo::Malla::DibujarCubo()
{
	SMesh* msh = new SMesh();
	SMeshBuffer* mb = new SMeshBuffer();
	msh->addMeshBuffer ( mb );
	S3DVertex vtx[12];
	vtx[0]  = S3DVertex ( -1,-1,-1, -1,-1,-1, SColor ( 255,255,255,255 ), 0, 1 );
	vtx[1]  = S3DVertex ( 1,-1,-1,  1,-1,-1, SColor ( 255,255,255,255 ), 1, 1 );
	vtx[2]  = S3DVertex ( 1, 1,-1,  1, 1,-1, SColor ( 255,255,255,255 ), 1, 0 );
	vtx[3]  = S3DVertex ( -1, 1,-1, -1, 1,-1, SColor ( 255,255,255,255 ), 0, 0 );
	vtx[4]  = S3DVertex ( 1,-1, 1,  1,-1, 1, SColor ( 255,255,255,255 ), 0, 1 );
	vtx[5]  = S3DVertex ( 1, 1, 1,  1, 1, 1, SColor ( 255,255,255,255 ), 0, 0 );
	vtx[6]  = S3DVertex ( -1, 1, 1, -1, 1, 1, SColor ( 255,255,255,255 ), 1, 0 );
	vtx[7]  = S3DVertex ( -1,-1, 1, -1,-1, 1, SColor ( 255,255,255,255 ), 1, 1 );
	vtx[8]  = S3DVertex ( -1, 1, 1, -1, 1, 1, SColor ( 255,255,255,255 ), 0, 1 );
	vtx[9]  = S3DVertex ( -1, 1,-1, -1, 1,-1, SColor ( 255,255,255,255 ), 1, 1 );
	vtx[10] = S3DVertex ( 1,-1, 1,  1,-1, 1, SColor ( 255,255,255,255 ), 1, 0 );
	vtx[11] = S3DVertex ( 1,-1,-1,  1,-1,-1, SColor ( 255,255,255,255 ), 0, 0 );


	for ( int i=0;i<12;i++ ) mb->Vertices.push_back ( vtx[i] );
	u16 indices[36] = {   0,2,1,   0,3,2,   1,5,4,   1,2,5,
	                      4,6,7,   4,5,6,   7,3,0,   7,6,3,
	                      9,5,2,   9,8,5,   0,11,10, 0,10,7
	                  };
	for ( int i=0;i<36;i++ ) mb->Indices.push_back ( indices[i] );

	return msh;
}


IMesh* GDT::Nodo::Malla::DibujarPlano ( int gridX, int gridY )
{
	SMesh* msh = new SMesh();
	SMeshBuffer* mb = new SMeshBuffer();
	msh->addMeshBuffer ( mb );
	int vertCnt = 0;
	for ( int x = 0; x < gridX; x++ )
		for ( int y = 0; y < gridY; y++ )
		{
			f32 xx   = ( f32 ) ( 0.5- ( f32 ) x/ ( gridX-1 ) ) *2;
			f32 yy   = ( f32 ) ( 0.5- ( f32 ) y/ ( gridY-1 ) ) *2;
			f32 xcord = ( f32 ) 1- ( f32 ) x/ ( gridX-1 );
			f32 ycord = ( f32 ) y/ ( gridY-1 )-1;
			mb->Vertices.push_back ( S3DVertex ( xx,yy,0, 0,0,0,SColor ( 255,255,255,255 ),xcord,ycord ) );

			if ( x < gridX - 1 && y < gridY - 1 )
			{
				mb->Indices.push_back ( vertCnt + 0 );
				mb->Indices.push_back ( vertCnt + 1 );
				mb->Indices.push_back ( vertCnt + 1 + gridY );
				mb->Indices.push_back ( vertCnt + 1 + gridY );
				mb->Indices.push_back ( vertCnt + gridY );
				mb->Indices.push_back ( vertCnt + 0 );
			}
			vertCnt++;
		}
	return msh;
}

IMesh* GDT::Nodo::Malla::DibujarCilindro ( int gridX, int gridY,f32 ridus )
{
	SMesh* msh = new SMesh();
	SMeshBuffer* mb = new SMeshBuffer();
	msh->addMeshBuffer ( mb );
	f32 Tstp = ( f32 ) ( 2*3.14/ ( gridX-1 ) );
	int vertCnt = 0;
	for ( int x = 0; x < gridX; x++ )
		for ( int y = 0; y < gridY; y++ )
		{
			f32 yy   = ( f32 ) ( 0.5- ( f32 ) y/ ( gridY-1 ) ) *2;
			f32 xx   = sin ( ( f32 ) x*Tstp ) *ridus;
			f32 zz   = cos ( ( f32 ) x*Tstp ) *ridus;
			f32 xcord = 1- ( f32 ) x/ ( gridX-1 );
			f32 ycord = ( f32 ) y/ ( gridY-1 )-1;
			if ( x < gridX-1 )
			{
				mb->Vertices.push_back ( S3DVertex ( xx,yy,zz, 0,0,0,SColor ( 255,255,255,255 ),xcord,ycord ) );

			}
			else
			{
				f32 yy   = ( f32 ) ( 0.5- ( f32 ) y/ ( gridY-1 ) ) *2;
				f32 xx   = ( f32 ) sin ( 0.0 ) *ridus;
				f32 zz   = ( f32 ) cos ( 0.0 ) *ridus;
				mb->Vertices.push_back ( S3DVertex ( xx,yy,zz, 0,0,0,SColor ( 255,255,255,255 ),xcord,ycord ) );

			}
			if ( x < gridX - 1 && y < gridY - 1 )
			{
				mb->Indices.push_back ( vertCnt + 0 );
				mb->Indices.push_back ( vertCnt + 1 );
				mb->Indices.push_back ( vertCnt + 1 + gridY );
				mb->Indices.push_back ( vertCnt + 1 + gridY );
				mb->Indices.push_back ( vertCnt + gridY );
				mb->Indices.push_back ( vertCnt + 0 );
			}
			vertCnt++;
		}
	return msh;
}


IMesh* GDT::Nodo::Malla::DibujarCono ( int gridX, int gridY,f32 ridus )
{
	SMesh* msh = new SMesh();
	SMeshBuffer* mb = new SMeshBuffer();
	msh->addMeshBuffer ( mb );
	f32 vstp = ridus/ ( f32 ) ( gridY-1 );
	f32 Tstp = ( f32 ) ( 2*3.14/ ( gridX-1 ) );
	int vertCnt = 0;
	for ( int x = 0; x < gridX; x++ )
		for ( int y = 0; y < gridY; y++ )
		{
			f32 yy   = ( f32 ) ( 0.5- ( f32 ) y/ ( gridY-1 ) ) *2;
			f32 xx   = ( f32 ) sin ( x*Tstp ) * ( y*vstp );
			f32 zz   = ( f32 ) cos ( x*Tstp ) * ( y*vstp );
			f32 xcord = 1- ( f32 ) x/ ( gridX-1 );
			f32 ycord = ( f32 ) y/ ( gridY-1 )-1;
			if ( x < gridX-1 )
			{
				mb->Vertices.push_back ( S3DVertex ( xx,yy,zz, 0,0,0,SColor ( 255,255,255,255 ),xcord,ycord ) );

			}
			else
			{
				f32 yy   = ( f32 ) ( 0.5- ( f32 ) y/ ( gridY-1 ) ) *2;
				f32 xx   = ( f32 ) sin ( x*Tstp ) * ( y*vstp );
				f32 zz   = ( f32 ) cos ( x*Tstp ) * ( y*vstp );
				mb->Vertices.push_back ( S3DVertex ( xx,yy,zz, 0,0,0,SColor ( 255,255,255,255 ),xcord,ycord ) );

			}
			if ( x < gridX - 1 && y < gridY - 1 )
			{
				mb->Indices.push_back ( vertCnt + 0 );
				mb->Indices.push_back ( vertCnt + 1 );
				mb->Indices.push_back ( vertCnt + 1 + gridY );
				mb->Indices.push_back ( vertCnt + 1 + gridY );
				mb->Indices.push_back ( vertCnt + gridY );
				mb->Indices.push_back ( vertCnt + 0 );
			}
			vertCnt++;
		}

	return msh;
}


IMesh* GDT::Nodo::Malla::DibujarEsfera()
{
	// return msh
	// La siguiente linea fue agregada SOLO para probar con VC++ 2005
	return static_mesh;
}

void GDT::Nodo::Malla::RegistrarVelAni ( int va )
{
	velani = va;
}

void GDT::Nodo::Malla::CalibrarColisionConEscenario ( float x, float y, float z )
{
	intersec_coli_a->setScale ( vector3df ( x,y,z ) );
	intersec_coli_b->setScale ( vector3df ( x,y,z ) );
	intersec_coli_c->setScale ( vector3df ( x,y,z ) );
	intersec_coli_d->setScale ( vector3df ( x,y,z ) );
	intersec_coli_e->setScale ( vector3df ( x,y,z ) );
	intersec_coli_f->setScale ( vector3df ( x,y,z ) );
}

void GDT::Nodo::Malla::CalibrarColisionConEscenarioX ( float x, float y, float z )
{
	intersec_coli_a->setScale ( vector3df ( x,y,z ) );
	intersec_coli_b->setScale ( vector3df ( x,y,z ) );

}

void GDT::Nodo::Malla::CalibrarColisionConEscenarioY ( float x, float y, float z )
{
	intersec_coli_c->setScale ( vector3df ( x,y,z ) );
	intersec_coli_d->setScale ( vector3df ( x,y,z ) );

}

void GDT::Nodo::Malla::CalibrarColisionConEscenarioZ ( float x, float y, float z )
{
	intersec_coli_e->setScale ( vector3df ( x,y,z ) );
	intersec_coli_f->setScale ( vector3df ( x,y,z ) );

}
