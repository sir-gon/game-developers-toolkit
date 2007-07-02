//Clase Colisiones 3d para mallas

#ifndef GD_COLISIONES3D_H
#define GD_COLISIONES3D_H

#include <irrlicht.h>
#include "gd_nodo.h"

#include "gd_escenario.h"
//#include "gd_malla.h"

//class GD_Malla;

class GD_Colisiones3d : public GD_Nodo//: public GD_Malla
{
   protected:
      ITriangleSelector* selector;
      
   public:

      //GD_Nodo *cNodo;

      GD_Colisiones3d();
      ~GD_Colisiones3d();

      //ISceneCollisionManager* colmgr;
      ITriangleSelector* RetornarDatosSelector();
      
      vector3df posmiacoli, resultado;
      vector3df vfin;
      bool coli;
      ISceneNode* DummyNodo;

      //void ActivarColisiones(IMesh* static_mesh);
      void CrearColision(ITriangleSelector* Mundo);
      void CrearColision(ITriangleSelector* Mundo,core::vector3df Radio,core::vector3df Gravedad,core::vector3df Traslacion);
      void CrearColision(ITriangleSelector* selector, float RadioX, float RadioY, float RadioZ, float GravedadX, float GravedadY, float GravedadZ, float TraslacionX, float TraslacionY, float TraslacionZ);
      void ActualizarDatosColision();

      void CrearColision(GD_Escenario scen);
      void CrearColision(GD_Escenario scen,core::vector3df Radio,core::vector3df Gravedad,core::vector3df Traslacion);
      void CrearColision(GD_Escenario scen, float RadioX, float RadioY, float RadioZ, float GravedadX, float GravedadY, float GravedadZ, float TraslacionX, float TraslacionY, float TraslacionZ);



      //Obtencion de valores *******************************************************
      core::vector3df RetornarRadioElipsoide();
      
      vector3df RetornarInterseccionRayo( vector3df ini, vector3df fin, GD_Escenario scen );
      vector3df RetornarInterseccionRayo( vector3df ini, vector3df fin, ITriangleSelector* trian );

      core::vector3df RetornarTraslacionElipsoide();
      core::vector3df RetornarGravedad();
      ITriangleSelector* RetornarDatosMundo();
      bool Callendo();
      
      vector3df PosicionColisionConEscenario( GD_Escenario scen );
      bool ColisionConEscenario( GD_Escenario scen );

      vector3df PosicionColisionConEscenario( ITriangleSelector* trian);
      bool ColisionConEscenario( ITriangleSelector* trian );
 
      bool ColisionConRayo( vector3df ini, vector3df fin, ITriangleSelector* trian );
      
      // Asignacion de valores *****************************************************
      void AsignarRadioElipsoide(core::vector3df vector_3d);
      void AsignarRadioElipsoide(float x, float y, float z);
      void AsignarTraslacionElipsoide(core::vector3df vector_3d);
      void AsignarTraslacionElipsoide(float x, float y, float z);   
      void AsignarGravedad(core::vector3df vector_3d);
      void AsignarGravedad(float x, float y, float z);
      
      void AsignarDatosColision(ITriangleSelector *nuevoMundo);
      void AsignarDatosColision(GD_Escenario scen);
      
      
      bool ColisionConCaja(aabbox3d<f32> Cajon);
      aabbox3d<f32> RetornarCaja();
      
      bool Colisiona(GD_Nodo nodocoli);


      bool AntiBug;
      
                 

};
#endif //GD_COLISIONES3D_H
