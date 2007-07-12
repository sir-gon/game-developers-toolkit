#ifdef _GDT_FISICAS_NEWTON_

#ifndef GD_MATERIAL_NWTNO_H_
#define GD_MATERIAL_NWTNO_H_

#include <stdio.h>
#include <Newton.h>

struct MaterialData
{
   char* pszNombre;
   int ID;
};

class GD_Material_nwtn
{
   public:

   NewtonWorld* nMundo;


   GD_Material_nwtn();
   GD_Material_nwtn(NewtonWorld* nMundo);
   ~GD_Material_nwtn();



   int IDMaterialPorDefecto();
   int CreaGrupoID();
   MaterialData CreaGrupoID(char* pszNombre);

   void MaterialesABColisionXDefecto(int A, int B, bool Activa);
   void MaterialesABColisionContinua(int A, int B, bool Activa=true);

   void MaterialesABFriccionXDefecto(int A, int B,
                                    dFloat Friccion_Estatica,
                                    dFloat Friccion_Cinetica);
   /*Nota: El valor de los coeficientes de friccion deve ser positiva; El valor
   de la friccion cintetica deve ser menor a la friccion estatica; El valor
   recomendado para la friccion es: menor o igual a 1.0; Por consideracion hacia
   algunos materiales Newton soporta un valor de 2.0 en la friccion cinetica.*/

   void MaterialesABElasticidadXDefecto(int A, int B,dFloat Elasticidad);
   /*Nota: El valor del coeficiente de elasticidad deve ser positivo; Se recomienda
   que se usen valores merores o iguales a 1.0.*/

   void MaterialesABConsistenciaXDefecto(int A, int B,dFloat Consistencia);
   /*Nota: El valor del coeficiente de Consistencia (Suavidad) deve ser positivo;
   Se recomienda que se usen valores merores o iguales a 1.0; un valor tipico
   de consistencia es de 0.15*/

   //void RetrollamadaColisionMaterialesAB(int A,int B,void *userData);



};


#endif // GD_MATERIAL_NWTNO_H_

#endif // _GDT_FISICAS_NEWTON_
