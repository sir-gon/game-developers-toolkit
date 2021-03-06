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

#ifndef GD_FISICAS_NEWTON_NWTNO_H
#define GD_FISICAS_NEWTON_NWTNO_H

#include <stdio.h>
#include <Newton.h>
#include <ITimer.h>
#include "gd_sistema.h"
#include "gd_matematicas.h"
#include "gd_nodo.h"
#include "gd_malla.h"
#include "gd_fisicasNwtMaterial.h"


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


#define ESCUDO_CUBO     0
#define ESCUDO_ESFERA   1
#define ESCUDO_CONO     2
#define ESCUDO_CAPSULA  3
#define ESCUDO_CILINDRO 4
#define ESCUDO_SEMICILINDRO   5

namespace GDT
{

	namespace Fisica
	{

		//static NewtonWorld* nWorld=NewtonCreate (NULL,NULL);
		//static NewtonWorld* nWorld;

		class MundoNwt
		{

			public:
				//Objetos Principales.

				ISceneNode* nodoMalla;
				//ITriangleSelector* TS;
				NewtonWorld* nMundo;
				NewtonBody* pCuerpoNwtn;
				NewtonCollision* pColisionNwtn;

				//Vectores de recepcion
				vector3df cords3d;
				matrix4  matrix;
				ITriangleSelector* TS;


				//Vectores
				vector3df fuerza,giro,omega;
				float masa;
				vector3df vInerciaXYZ;

				//Material
				MaterialData Material;

				//triangle3df Triangulos[];


				_GDT_EXPORT_ MundoNwt();
				_GDT_EXPORT_ ~MundoNwt();

				_GDT_EXPORT_ void DestruyeNewtoneano();


				_GDT_EXPORT_ void Inicializa ( NewtonWorld* MundoNwtn,ISceneNode* gdNodo,int EscudoColision=0 );

				_GDT_EXPORT_ void CrearEscenarioNewtoneano ( NewtonWorld* MundoNwtn,ISceneNode* gdNodo,ISceneManager* pSM,IMesh* pStaticMesh );

				_GDT_EXPORT_ NewtonCollision* CreaEscudo ( int Escudo );

				_GDT_EXPORT_ void AsignaMatriz ( const matrix4 mat );

				_GDT_EXPORT_ vector3df AsignarFuerza ( float X,float Y,float Z );
				_GDT_EXPORT_ vector3df AsignarGiro ( float X,float Y,float Z );

				_GDT_EXPORT_ void AsignarMasa ( dFloat mass,dFloat InerciaX,dFloat InerciaY,dFloat InerciaZ );
				_GDT_EXPORT_ void AsignarMasa ( float mass,vector3df vecInerciaXYZ );

				_GDT_EXPORT_ void AsignarOmega ( dFloat OX,dFloat OY,dFloat OZ );
				_GDT_EXPORT_ void AsignarOmega ( vector3df vOmega );

				_GDT_EXPORT_ void AplicarFuerza_Torcion();

				_GDT_EXPORT_ void AsignaMaterial ( int MaterialID );

				_GDT_EXPORT_ void ConvertidorNewtonIrrlicht();

				_GDT_EXPORT_ void AsignarValoresDeReposo ( dFloat velmov,dFloat velgiro,int maxFPS );

				_GDT_EXPORT_ void AsignarMatrizRecursivamente ( const matrix4 mat );

				_GDT_EXPORT_ void Impulsar ( dFloat* vecVelocidadDelta, dFloat* vecPuntoDeImpulso );
				_GDT_EXPORT_ void Impulsar ( vector3df vecVelocidadDelta, vector3df vecPuntoDeImpulso );

				_GDT_EXPORT_ bool StatusActivo();

				ISceneNode* Actualizar();


		};


//static Newtoneano gdNwtn;
		static ISceneNode* NwtNodo;
		static dFloat NwtnMasa;
		static vector3df NwtnVMasa;
		static vector3df NwtnFuerza;

		matrix4 RowMaj2ColumnMaj ( matrix4 RowMat );
		matrix4 ColumnMaj2RowMaj ( matrix4 ColMat );
		void*  PhysicsAlloc ( int sizeInBytes );
		void  PhysicsFree ( void *ptr, int sizeInBytes );
//--------------------------------------------------------------------------------
		static void DestruyeNewtoneanoParaCallback ( const NewtonBody* nBody );
		static void ConvertidorNewtonIrrlichtParaCallback ( const NewtonBody* body,const dFloat *pMatrix );
		static void AplicarFuerza_TorcionParaCallbak ( const NewtonBody* body );
		static void LevelCollisionCallback (
		    const NewtonBody* bodyWithTreeCollision,
		    const NewtonBody* body,
		    const dFloat* vertex,
		    int vertexstrideInBytes,
		    int indexCount,
		    const int* indexArray );
//---------------------------------------------------------------------------------


		void DestruyeNewtoneanoParaCallback ( const NewtonBody* nBody )
		{
			//gdNwtn.DestruyeNewtoneano();

			//gdNwtn.DestruyeNewtoneano();
			ISceneNode* primitive;
			// get the graphic object form the rigid body
			primitive = ( ISceneNode* ) NewtonBodyGetUserData ( nBody );
			// destroy the graphic object
			delete primitive;
		}

		void ConvertidorNewtonIrrlichtParaCallback ( const NewtonBody* body,const dFloat *pMatrix )
		{
			//ISceneNode* scnodo;
			matrix4 Matrix;

			//memcpy(Matrix.M, pMatrix, sizeof(float)*16);

			NewtonBodyGetMatrix ( body, ( dFloat* ) Matrix.pointer() );

			//Ordenando matriz
			//Matrix=ColumnMaj2RowMaj(Matrix);

			NwtNodo = ( ISceneNode * ) NewtonBodyGetUserData ( body );
			if ( NwtNodo )
			{
				// Position the node
				NwtNodo->setPosition ( Matrix.getTranslation() );		// set position
				NwtNodo->setRotation ( Matrix.getRotationDegrees() );	// and rotation

			}

			/*for(int c=0;c<=15;c++)
			 {
			    printf("%f, ",Matrix.M[c]);

			 }
			 printf("\n");*/


		}

		void AplicarFuerza_TorcionParaCallbak ( const NewtonBody* body )
		{

			NewtonBodyGetMassMatrix ( body, &NwtnMasa, ( dFloat* ) &NwtnVMasa.X, ( dFloat* ) &NwtnVMasa.Y, ( dFloat* ) &NwtnVMasa.Z );

			NewtonBodySetForce ( body, ( dFloat* ) &NwtnFuerza );

		}


		void LevelCollisionCallback (
		    const NewtonBody* bodyWithTreeCollision,
		    const NewtonBody* body,
		    const dFloat* vertex,
		    int vertexstrideInBytes,
		    int indexCount,
		    const int* indexArray )
		{
			// the application can use this function for debugging purpose by writing the
			// face to a global variable then display which face of the mesh are been used for collision.
			// ,,,,,,,,,,,
			// ..........

			// the application can use this function also to modify the collision geometry by changing the face ID
			// this could be uses full to make surface change for example from dry to wet, or breaking glass
			// for this the application should used the functions:
			// int id = NewtonTreeCollisionGetFaceAtribute (treeCollision, indexArray);
			// NewtonTreeCollisionSetFaceAtribute (treeCollision, indexArray, new id);

		}


	} // FIN NAMESPACE FISICAS

} // FIN NAMESPACE GDT

#endif // FISICAS_NEWTON_NWTNO_H

#endif // _GDT_FISICAS_NEWTON_
