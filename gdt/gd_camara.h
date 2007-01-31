/*///////////////////////////////////////////////////////////////////

GD_Camara 

Este archivo hace parte de GDT Game Developers Toolkit.
Para informacion de distribucion o uso dirigase a el archivo gdt.h
o en la web http://www.gdtoolkit.8m.net

*////////////////////////////////////////////////////////////////////

#ifndef GD_CAMARA_H
#define GD_CAMARA_H

#include "gd_nodo.h" // inheriting class's header file
#include "gd_escenario.h"

#include "gd_sistemamatematicas.h"

// No description
class GD_Camara : public GD_Nodo
{
   private:
      double distancia;
	public:
		// class constructor
		GD_Camara();
		// class destructor
		~GD_Camara();
		
		int miID;
		
		GD_SistemaMatematicas SisMat;

	ICameraSceneNode* nodc;
	void Crear(int tipo=Tipo_Normal);

	void Orientar(float x, float y, float z);
	void Orientar(vector3df poso);

	//Profundidad de camara
	double Profundidad();
	void Profundidad(float rango);
	
	// establece el viewport
	//void AreaRender(int x1, int y1, int x2, int y2);
	
	// Si se rendereiza con esta camara
	//void Activada(bool opc);
	
	//****************************

	vector3df RetornarObjetivo();
		
	vector3df Seguir(vector3df PosicionEntrada1, float anguloY,vector3df PosicionEntrada2, float distancia,float altura,float angulo=180,  float durezaX=15, float durezaY=15/8, float durezaZ=15);
	
	void Perseguir(vector3df PosicionEntrada1, float anguloY,double distancia,double altura,double angulo,  float durezaX, float durezaY, float durezaZ);
	void Perseguir(GD_Nodo nodoncio,double distancia,double altura,double angulo,  float durezaX, float durezaY, float durezaZ);
	void Perseguir(GD_Nodo nodoncio,double distancia,double altura,double angulo, double dureza);

	// COMPATIBILIDAD HACIA ATRAS
	void Perseguir(vector3df PosicionEntrada1, float anguloY,double distancia,double altura,double angulo, double dureza);	
	void Perseguir(GD_Nodo nodoncio,double distancia,double altura,double angulo);
	// FIN COMPATIBILIDAD HACIA ATRAS

	void CrearColision( GD_Escenario scen,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz);



};

#endif // GD_CAMARA_H
