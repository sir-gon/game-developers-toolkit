#ifdef _GDT_FISICAS_

#ifndef GD_CUERPO_H
#define GD_CUERPO_H

#include "gd_malla.h"
#include "gd_nwtno.h"
#include "gd_material_nwtno.h"


class GD_Cuerpo
{
   public:
   GD_Cuerpo();
   GD_Cuerpo(NewtonWorld* NwtnWorld);
   ~GD_Cuerpo();


      NewtonWorld* MundoNwtn;
      GD_Malla malla;
      GD_Newtoneano fisica;
      GD_Material_nwtn material;

      //Creacion
      void Inicializar(NewtonWorld* NwtnWorld);
      void Cargar(char *filename,int EscudoColision=0);
      void CargarTangentes(char *filename,int EscudoColision=0);
      void CrearCubo();
      void CrearCubo(float tamx, float tamy, float tamz );
      void CrearPlano( int tx, int ty );
      void CrearCilindro( int tx, int ty, f32 radio  );
      void CrearCono( int tx, int ty, f32 radio  );
      void CrearEsfera( float radio, int polynum = 16 );
      void CrearEscenarioNewtoneano(char *filename);
      // Fisica
      void AplicarFisica(){fisica.AplicarFuerza_Torcion();};

      void AsignarFisicas(float masa,vector3df vinercia,
                           vector3df vfuerza,
                           vector3df vomega,
                           int MatID);

      void Fuerza(vector3df vfuerza);
      void Omega(vector3df vomega);
      void Masa(float masa,vector3df vinercia);
      void Material(int MatID);

      //Modificacion
      void Posicionar(vector3df pos);
      void Actualizar_Transformacion();
      void Actualizar();
      void ActivarFisicas(){Actualizar();};

};




#endif  // GD_CUERPO_H

#endif // _GDT_FISICAS_
