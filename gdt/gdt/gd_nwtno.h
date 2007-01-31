#ifdef _GDT_FISICAS_

#ifndef GD_NWTNO_H
#define GD_NWTNO_H

#include "gd_sistema.h"
#include "gd_sistemamatematicas.h"
#include "gd_nodo.h"
#include "gd_malla.h"
#include <Newton.h>
#include <ITimer.h>
#include "gd_material_nwtno.h"


#define ESCUDO_CUBO     0
#define ESCUDO_ESFERA   1
#define ESCUDO_CONO     2
#define ESCUDO_CAPSULA  3
#define ESCUDO_CILINDRO 4
#define ESCUDO_SEMICILINDRO   5



//static NewtonWorld* nWorld=NewtonCreate (NULL,NULL);
static NewtonWorld* nWorld;



class GD_Newtoneano
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


   GD_Newtoneano();
   ~GD_Newtoneano();

   void DestruyeNewtoneano();


   void Inicializa(NewtonWorld* MundoNwtn,ISceneNode* gdNodo,int EscudoColision=0);

   void CrearEscenarioNewtoneano(NewtonWorld* MundoNwtn,ISceneNode* gdNodo,ISceneManager* pSM,IMesh* pStaticMesh);

   NewtonCollision* CreaEscudo(int Escudo);

   void AsignaMatriz(const matrix4 mat);

   vector3df AsignarFuerza(float X,float Y,float Z);
   vector3df AsignarGiro(float X,float Y,float Z);

   void AsignarMasa(dFloat mass,dFloat InerciaX,dFloat InerciaY,dFloat InerciaZ);
   void AsignarMasa(float mass,vector3df vecInerciaXYZ);

   void AsignarOmega(dFloat OX,dFloat OY,dFloat OZ);
   void AsignarOmega(vector3df vOmega);

   void AplicarFuerza_Torcion();

   void AsignaMaterial(int MaterialID);

   void ConvertidorNewtonIrrlicht();

   void AsignarValoresDeReposo(dFloat velmov,dFloat velgiro,int maxFPS);

   void AsignarMatrizRecursivamente(const matrix4 mat);

   void Impulsar(dFloat* vecVelocidadDelta, dFloat* vecPuntoDeImpulso);
   void Impulsar(vector3df vecVelocidadDelta, vector3df vecPuntoDeImpulso);

   bool StatusActivo();

   ISceneNode* Actualizar();


};


//static Newtoneano gdNwtn;
static ISceneNode* NwtNodo;
static dFloat NwtnMasa;
static vector3df NwtnVMasa;
static vector3df NwtnFuerza;

matrix4 RowMaj2ColumnMaj(matrix4 RowMat);
matrix4 ColumnMaj2RowMaj(matrix4 ColMat);
void*  PhysicsAlloc (int sizeInBytes);
void  PhysicsFree (void *ptr, int sizeInBytes);
///-----------------------------------------------------------------------------------------------
static void DestruyeNewtoneanoParaCallback(const NewtonBody* nBody);
static void ConvertidorNewtonIrrlichtParaCallback(const NewtonBody* body,const dFloat *pMatrix);
static void AplicarFuerza_TorcionParaCallbak(const NewtonBody* body);
static void LevelCollisionCallback (
	const NewtonBody* bodyWithTreeCollision,
	const NewtonBody* body,
	const dFloat* vertex,
	int vertexstrideInBytes,
	int indexCount,
	const int* indexArray);
///-----------------------------------------------------------------------------------------------


void DestruyeNewtoneanoParaCallback(const NewtonBody* nBody)
{
   //gdNwtn.DestruyeNewtoneano();

   //gdNwtn.DestruyeNewtoneano();
   ISceneNode* primitive;
	// get the graphic object form the rigid body
	primitive = (ISceneNode*) NewtonBodyGetUserData (nBody);
	// destroy the graphic object
	delete primitive;
}

void ConvertidorNewtonIrrlichtParaCallback(const NewtonBody* body,const dFloat *pMatrix)
{
   //ISceneNode* scnodo;
   matrix4 Matrix;

   //memcpy(Matrix.M, pMatrix, sizeof(float)*16);

   NewtonBodyGetMatrix(body,(dFloat*)&Matrix.M[0]);

   //Ordenando matriz
	//Matrix=ColumnMaj2RowMaj(Matrix);

	NwtNodo = (ISceneNode *)NewtonBodyGetUserData(body);
	if (NwtNodo)
	{
		// Position the node
		NwtNodo->setPosition(Matrix.getTranslation());		// set position
		NwtNodo->setRotation(Matrix.getRotationDegrees());	// and rotation

   }

   /*for(int c=0;c<=15;c++)
	   {
	      printf("%f, ",Matrix.M[c]);

	   }
	   printf("\n");*/


}

void AplicarFuerza_TorcionParaCallbak(const NewtonBody* body)
{

	NewtonBodyGetMassMatrix (body, &NwtnMasa,(dFloat*) &NwtnVMasa.X,(dFloat*) &NwtnVMasa.Y, (dFloat*)&NwtnVMasa.Z);

	NewtonBodySetForce (body,(dFloat*) &NwtnFuerza);

}

void LevelCollisionCallback (
	const NewtonBody* bodyWithTreeCollision,
	const NewtonBody* body,
	const dFloat* vertex,
	int vertexstrideInBytes,
	int indexCount,
	const int* indexArray)
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
#endif // GD_NWTNO_H

#endif // _GDT_FISICAS_