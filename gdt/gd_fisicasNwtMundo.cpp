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

#ifdef _GDT_FISICAS_NEWTON_

#include "gd_fisicasNwtMundo.h"

/*!
* \class GD_FisicasNwtMundo
*
* Implementa un Mundo de f&iacute;sicas Newton.
*
* \warning Esta caracter&iacute;stica esta disponible cuando _GDT_FISICAS_NEWTON_ est&aacute; definido en tiempo de compilaci&oacute;n.
*
* \author Astucia
*/

GD_FisicasNwtMundo::GD_FisicasNwtMundo()
{};

GD_FisicasNwtMundo::~GD_FisicasNwtMundo()
{};

void GD_FisicasNwtMundo::DestruyeNewtoneano()
{};

NewtonCollision* GD_FisicasNwtMundo::CreaEscudo ( int Escudo )
{
	NewtonCollision* collision;

	irr::core::aabbox3d<f32> boundingBox;
	vector3df centro;
	dFloat Largo,Ancho,Alto;
	dFloat RadioX,RadioY,RadioZ;
	dFloat Radio,Altura;

//Obteniendo la matriz (formas) del objeto
	matrix=nodoMalla->getRelativeTransformation();
	//Obteniendo el tama&ntilde;o del objeto.
	boundingBox=nodoMalla->getTransformedBoundingBox();
	matrix.transformBox ( boundingBox );
	//Centro de la figura
	centro=boundingBox.getCenter();


	switch ( Escudo )
	{
		case 0:
		{
			//Caja
			Largo= ( dFloat ) GD_Matematicas::Absoluto ( ( double ) boundingBox.MaxEdge.X-boundingBox.MinEdge.X );
			Alto= ( dFloat ) GD_Matematicas::Absoluto ( ( double ) boundingBox.MaxEdge.Y-boundingBox.MinEdge.Y );
			Ancho= ( dFloat ) GD_Matematicas::Absoluto ( ( double ) boundingBox.MaxEdge.Z-boundingBox.MinEdge.Z );

			printf ( "Largo: %f, Alto: %f, Ancho: %f\n",Largo,Alto,Ancho );

			//Creando colision
			collision = NewtonCreateBox ( nMundo,Largo,Alto,Ancho,NULL );

			return collision;
		}

		case 1:
		{
			//Esfera
			RadioX= ( dFloat ) GD_Matematicas::Absoluto ( ( double ) boundingBox.MaxEdge.X-centro.X );
			RadioY= ( dFloat ) GD_Matematicas::Absoluto ( ( double ) boundingBox.MaxEdge.Y-centro.Y );
			RadioZ= ( dFloat ) GD_Matematicas::Absoluto ( ( double ) boundingBox.MaxEdge.Z-centro.Z );

			printf ( "RadioX: %f, RadioY: %f, RadioZ: %f\n",RadioX,RadioY,RadioZ );

			//Creando colision
			collision = NewtonCreateSphere ( nMundo,RadioX,RadioY,RadioZ,NULL );
			return collision;
		}

		case 2:
		{
			//Cono
			Radio= ( dFloat ) GD_Matematicas::Absoluto ( ( double ) boundingBox.MaxEdge.X-centro.X );
			Altura= ( dFloat ) GD_Matematicas::Absoluto ( ( double ) boundingBox.MaxEdge.Y-boundingBox.MinEdge.Y );

			//Creando colision
			collision = NewtonCreateCone ( nMundo,Radio,Altura,NULL );
			return collision;
		}

		case 3:
		{
			//Capsula
			Radio= ( dFloat ) GD_Matematicas::Absoluto ( ( double ) boundingBox.MaxEdge.X-centro.X );
			Altura= ( dFloat ) GD_Matematicas::Absoluto ( ( double ) boundingBox.MaxEdge.Y-boundingBox.MinEdge.Y );

			//Creando colision
			collision = NewtonCreateCapsule ( nMundo,Radio,Altura,NULL );
			return collision;
		}

		case 4:
		{
			//Cilindro
			Radio= ( dFloat ) GD_Matematicas::Absoluto ( ( double ) boundingBox.MaxEdge.X-centro.X );
			Altura= ( dFloat ) GD_Matematicas::Absoluto ( ( double ) boundingBox.MaxEdge.Y-boundingBox.MinEdge.Y );

			//Creando colision
			collision = NewtonCreateCylinder ( nMundo,Radio,Altura,NULL );
			return collision;
		}

		case 5:
		{
			//SemiCilindro
			Radio= ( dFloat ) GD_Matematicas::Absoluto ( ( double ) boundingBox.MaxEdge.X-centro.X );
			Altura= ( dFloat ) GD_Matematicas::Absoluto ( ( double ) boundingBox.MaxEdge.Y-boundingBox.MinEdge.Y );

			//Creando colision
			collision = NewtonCreateChamferCylinder ( nMundo,Radio,Altura,NULL/*(dFloat*)&matrix.M[0]*/ );
			return collision;
		}
		default: return  collision=NULL;
	}

}

void GD_FisicasNwtMundo::Inicializa ( NewtonWorld* MundoNwtn,ISceneNode* gdNodo,int EscudoColision )
{

	//Cargando el objeto Malla.
	nodoMalla=gdNodo;
	nMundo=MundoNwtn;

	//Carga el objeto colision.
	pColisionNwtn=CreaEscudo ( EscudoColision );
	// create the rigid body
	pCuerpoNwtn = NewtonCreateBody ( nMundo, pColisionNwtn );
	// release the collision geometry when not need it
	NewtonReleaseCollision ( nMundo, pColisionNwtn );

	//Cargando el NewtonBody con los valores de la matriz del objeto personaje.
	NewtonBodySetMatrix ( pCuerpoNwtn, ( dFloat* ) matrix.pointer() );
	// save the pointer to the graphic object with the body.
	NewtonBodySetUserData ( pCuerpoNwtn, nodoMalla );

	// set a destructor for this rigid body
	///**** LLAMADA A CALLBACK ******
	NewtonBodySetDestructorCallback ( pCuerpoNwtn,DestruyeNewtoneanoParaCallback );

	///%%%%% AQUI PUEDO LLAMAR A TODOS LOS CALLBACKS %%%%% ///

}

void GD_FisicasNwtMundo::CrearEscenarioNewtoneano ( NewtonWorld* MundoNwtn,ISceneNode* gdNodo,ISceneManager* pSM,IMesh* pStaticMesh )
{

	vector3df e0, e1, area;
	//float mag = 0.0f;
	s32 vercnt,triTot=0;
	int Tri;
	static matrix4* mat4;
	matrix4 tmpMatrix;



	// load map  ----------------------------------------------------------------
	//Esenario.Cargar("media/warehouse/warehouse.x",true,Sistema.RetornarDevice());
	//Esenario.Posicionar(0.0,0.0,0.0);
	//---------------------------------------------------------------------------

	//Crea un arbol de triangulos y lo asigna al nodo de la esena
	TS=pSM->createOctTreeTriangleSelector ( pStaticMesh,gdNodo );
	gdNodo->setTriangleSelector ( TS );
	//TS->drop();// Libera el espacio en memoria usado por el selector de triangulos

	//Muestra la cantidad de triangulos que contiene la figura
	vercnt=gdNodo->getTriangleSelector()->getTriangleCount();
	printf ( "TotalTriangulos= %i\n", ( int ) vercnt );
	//Recarga el selector de triangulos (esto es relativamente inecesario. Si no se liberara el
	//espacio en memoria anteriormente se puede omitir este
	//comando, lo dejo para comprobacion de datos.)
	//TS=gdNodo->getTriangleSelector();
	//Crea un array que contendr&aacute; todos los triangulos de la figura
	triangle3df Triangulos[vercnt];
	//Carga de triangulos el array anterior.
	tmpMatrix=gdNodo->getRelativeTransformation();
	mat4=&tmpMatrix;
	TS->getTriangles ( &Triangulos[0],vercnt,triTot,mat4 );
	printf ( "TotalTriangulos= %i\n", ( int ) triTot ); //muestra la cantidad de triangulos procesados
	//system("PAUSE");

	//Crea un arbol de colisiones.
	pColisionNwtn = NewtonCreateTreeCollision ( MundoNwtn, NULL );
	//Inicia la carga de lo que sera el cuerpo Newton
	NewtonTreeCollisionBeginBuild ( pColisionNwtn );

	//Desde 0 hasta la cantidad total de triangulos
	for ( Tri=0;Tri<triTot;Tri++ )
	{
		//Este procedimiento parece ser innecesario, lo dejo parasolucion de posibles problemas
		//*************************************************************************************
		//e0 = Triangulos[Tri].pointB - Triangulos[Tri].pointA;
		//e1 = Triangulos[Tri].pointC - Triangulos[Tri].pointA;
		//area = e0.crossProduct ( e1 );
		//mag = area.dotProduct ( area );
		//if ( mag > -0.00001 )
		///////////////////////////////////////////////////////////////////////////////////////

		//A&ntilde;ade los triangulos al arbol de colisiones
		NewtonTreeCollisionAddFace ( pColisionNwtn, 3, ( dFloat* ) &Triangulos[Tri].pointA, sizeof ( Triangulos[Tri].pointA ), Tri );
		//muestra en pantalla los triangulos de la figura (control del programador)
		//printf("PuntoA= %0.2f, %0.2f, %0.2f\n",(float)Triangulos[Tri].pointA.X,(float)Triangulos[Tri].pointA.Y,(float)Triangulos[Tri].pointA.Z);
		//printf("PuntoB= %0.2f, %0.2f, %0.2f\n",(float)Triangulos[Tri].pointB.X,(float)Triangulos[Tri].pointB.Y,(float)Triangulos[Tri].pointB.Z);
		//printf("PuntoC= %0.2f, %0.2f, %0.2f\n",(float)Triangulos[Tri].pointC.X,(float)Triangulos[Tri].pointC.Y,(float)Triangulos[Tri].pointC.Z);
		//system("PAUSE");
	}

	TS->drop();// Libera la memora del selector de triangulos
	//Finaliza la creacion del arbol de colisiones
	NewtonTreeCollisionEndBuild ( pColisionNwtn,1 );
	//Crea el cuerpo newton
	pCuerpoNwtn = NewtonCreateBody ( MundoNwtn, pColisionNwtn );
	//system("PAUSE");
	//Libera la memoria de la variable de colision
	NewtonReleaseCollision ( MundoNwtn, pColisionNwtn );


}


void GD_FisicasNwtMundo::AsignaMatriz ( const matrix4 mat )
{
	NewtonBodySetMatrix ( pCuerpoNwtn, ( dFloat* ) matrix.pointer() );
}

void GD_FisicasNwtMundo::AsignarMasa ( dFloat mass,dFloat InerciaX,dFloat InerciaY,dFloat InerciaZ )
{
	// set the body mass and inertia
	masa=mass;
	vInerciaXYZ.X=InerciaX;
	vInerciaXYZ.Y=InerciaY;
	vInerciaXYZ.Z=InerciaZ;
	NewtonBodySetMassMatrix ( pCuerpoNwtn, ( dFloat ) masa, ( dFloat ) vInerciaXYZ.X, ( dFloat ) vInerciaXYZ.Y, ( dFloat ) vInerciaXYZ.Z );
}

void GD_FisicasNwtMundo::AsignarMasa ( float mass,vector3df vecInerciaXYZ )
{
	AsignarMasa ( ( dFloat ) mass, ( dFloat ) vInerciaXYZ.X, ( dFloat ) vInerciaXYZ.Y, ( dFloat ) vInerciaXYZ.Z );
}

void GD_FisicasNwtMundo::AsignarOmega ( dFloat OX,dFloat OY,dFloat OZ )
{
	//Asignando angulo vectorial
	dFloat omega[16]={OX,OY,OZ,1.0};
	NewtonBodySetOmega ( pCuerpoNwtn,&omega[0] );
}

void GD_FisicasNwtMundo::AsignarOmega ( vector3df vOmega )
{
	//Asignando angulo vectorial
	dFloat omega[16]={ ( dFloat ) vOmega.X, ( dFloat ) vOmega.Y, ( dFloat ) vOmega.Z,1.0};
	NewtonBodySetOmega ( pCuerpoNwtn,&omega[0] );
}

vector3df GD_FisicasNwtMundo::AsignarFuerza ( float X,float Y,float Z )
{
	fuerza.X=X;
	fuerza.Y=Y;
	fuerza.Z=Z;
	// Linea agregada
	return fuerza;
}

vector3df GD_FisicasNwtMundo::AsignarGiro ( float X,float Y,float Z )
{
	giro.X=X;
	giro.Y=Y;
	giro.Z=Z;
	// Linea agregada
	return giro;
}

void GD_FisicasNwtMundo::AplicarFuerza_Torcion()
{

	NwtnFuerza.X=fuerza.X;
	NwtnFuerza.Y=fuerza.Y;
	NwtnFuerza.Z=fuerza.Z;
	///*** CALLBACK *****
	NewtonBodySetForceAndTorqueCallback ( pCuerpoNwtn, AplicarFuerza_TorcionParaCallbak );
}

void GD_FisicasNwtMundo::AsignaMaterial ( int MaterialID )
{
	NewtonBodySetMaterialGroupID ( pCuerpoNwtn, MaterialID );
}


void GD_FisicasNwtMundo::ConvertidorNewtonIrrlicht()
{
	//Cargando los datos del cuerpo Newtoneano en la matriz del cuerpo Irrlicht
	NewtonBodyGetMatrix ( pCuerpoNwtn, ( dFloat* ) matrix.pointer() );
	//Carga los datos al nodo base
	nodoMalla = ( ISceneNode * ) NewtonBodyGetUserData ( pCuerpoNwtn );
	if ( nodoMalla )
	{
		// Position the node
		nodoMalla->setPosition ( matrix.getTranslation() );		// set position
		nodoMalla->setRotation ( matrix.getRotationDegrees() );	// and rotation
	}

}

ISceneNode* GD_FisicasNwtMundo::Actualizar()
{

	// set the transform call back function
	///*** CALLBACK *****
	NewtonBodySetTransformCallback ( pCuerpoNwtn, ConvertidorNewtonIrrlichtParaCallback );
	nodoMalla=NwtNodo;

	NewtonBodyGetMatrix ( pCuerpoNwtn, ( dFloat* ) matrix.pointer() );
	//ConvertidorNewtonIrrlicht();
	return nodoMalla;
}

void GD_FisicasNwtMundo::AsignarValoresDeReposo ( dFloat velmov,dFloat velgiro,int maxFPS )
{
	//GD_Matematicas SMT;

	velmov=GD_Matematicas::Potencia ( velmov,2.0 );
	velgiro=GD_Matematicas::Potencia ( velgiro,2.0 );
	NewtonBodySetFreezeTreshold ( pCuerpoNwtn,velmov,velgiro,maxFPS );
}

void GD_FisicasNwtMundo::AsignarMatrizRecursivamente ( const matrix4 mat )
{
	NewtonBodySetMatrixRecursive ( pCuerpoNwtn, ( dFloat* ) &mat );
}

void GD_FisicasNwtMundo::Impulsar ( dFloat* vecVelocidadDelta, dFloat* vecPuntoDeImpulso )
{
	NewtonAddBodyImpulse ( pCuerpoNwtn,vecVelocidadDelta,vecVelocidadDelta );
}
void GD_FisicasNwtMundo::Impulsar ( vector3df vecVelocidadDelta, vector3df vecPuntoDeImpulso )
{
	NewtonAddBodyImpulse ( pCuerpoNwtn, ( dFloat* ) &vecVelocidadDelta, ( dFloat* ) &vecPuntoDeImpulso );
}

bool GD_FisicasNwtMundo::StatusActivo()
{
	return ( bool ) NewtonBodyGetSleepingState ( pCuerpoNwtn );
}


///---------------------------------------------------------------------------

matrix4 RowMaj2ColumnMaj ( matrix4 RowMat )
{

	//int Row,Col;
	//int i=0;
	matrix4 ColMat=RowMat;
	/*
	   dFloat Matriz[4][4];

	   for(Col=0;Col<4;Col++)
	   {
	      for (Row=0;Row<4;Row++)
	      {
	         Matriz[Row][Col]=(dFloat)RowMat.M[i];
	         i++;
	      }
	   }

	   i=0;
	   for (Row=0;Row<4;Row++)
	   {
	      for(Col=0;Col<4;Col++)
	      {
	         ColMat.M[i]=(f32)Matriz[Row][Col];
	         i++;
	      }
	   }

	*/

	ColMat.getTransposed ( RowMat ); // Estara correcto?

	return ColMat;
}

matrix4 ColumnMaj2RowMaj ( matrix4 ColMat )
{
	//int Row,Col;
	//int i=0;
	matrix4 RowMat=ColMat;

	/*dFloat Matriz[4][4];

	for (Row=0;Row<4;Row++)
	{
	   for(Col=0;Col<4;Col++)
	   {
	      Matriz[Row][Col]=(dFloat)ColMat.M[i];
	      i++;
	   }
	}

	i=0;
	for(Col=0;Col<4;Col++)
	{
	   for (Row=0;Row<4;Row++)
	   {
	      RowMat.M[i]=(f32)Matriz[Row][Col];
	      i++;
	   }
	}*/
	/*int o=0;
	for(i=0;i<16;i++)
	{
	   //printf("front: %f, up: %f, right %f: Pos: %f\n",
	   RowMat.M[o]=ColMat.M[i];
	   RowMat.M[o+1]=ColMat.M[i+1];
	   RowMat.M[o+2]=ColMat.M[i+2];
	   RowMat.M[o+3]=ColMat.M[i+3];
	   o++;
	}*/

// COMENTADO POR SIR_GON. INTENTANDO UNA MEJOR MANERA DE HACER ESTO.
	/*
	   RowMat.M[0]=ColMat.M[0]; RowMat.M[1]=ColMat.M[4]; RowMat.M[2]=ColMat.M[8]; RowMat.M[3]=ColMat.M[12];  //Front
	   RowMat.M[4]=ColMat.M[1]; RowMat.M[5]=ColMat.M[5]; RowMat.M[6]=ColMat.M[9]; RowMat.M[7]=ColMat.M[13];  //Up
	   RowMat.M[8]=ColMat.M[2]; RowMat.M[9]=ColMat.M[6]; RowMat.M[10]=ColMat.M[10]; RowMat.M[11]=ColMat.M[14];  //Right
	   RowMat.M[12]=ColMat.M[3]; RowMat.M[13]=ColMat.M[7]; RowMat.M[14]=ColMat.M[11]; RowMat.M[15]=ColMat.M[15];  //Pos
	*/

	RowMat.getTransposed ( ColMat ); // Estara correcto?

// FIN ARREGLO SIR GON

	return RowMat;
}

///*************************************************************
// memory allocation for Newton
void*  PhysicsAlloc ( int sizeInBytes )
{
	return malloc ( sizeInBytes );
}

// memory de-allocation for Newton
void  PhysicsFree ( void *ptr, int sizeInBytes )
{
	free ( ptr );
}
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif // _GDT_FISICAS_NEWTON_

