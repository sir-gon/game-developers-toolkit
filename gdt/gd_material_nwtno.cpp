#ifdef _GDT_FISICAS_

#include "gd_material_nwtno.h"


GD_Material_nwtn::GD_Material_nwtn()
{

}
GD_Material_nwtn::~GD_Material_nwtn()
{
   //NewtonMaterialDestroyAllGroupID(nMundo);
}

int GD_Material_nwtn::IDMaterialPorDefecto()
{
   return NewtonMaterialGetDefaultGroupID(nMundo);
}

int GD_Material_nwtn::CreaGrupoID()
{
   return NewtonMaterialCreateGroupID(nMundo);
}
MaterialData GD_Material_nwtn::CreaGrupoID(char* pszNombre)
{
   MaterialData MaterialTipo;
   MaterialTipo.pszNombre=pszNombre;
   MaterialTipo.ID=NewtonMaterialCreateGroupID(nMundo);
   return MaterialTipo;
}

void GD_Material_nwtn::MaterialesABColisionXDefecto(int A, int B, bool Activa)
{
   NewtonMaterialSetDefaultCollidable(nMundo,A,B,(int)Activa);
}

void GD_Material_nwtn::MaterialesABColisionContinua(int A, int B, bool Activa)
{
   NewtonMaterialSetContinuousCollisionMode(nMundo,A,B,(int)Activa);
}

void GD_Material_nwtn::MaterialesABFriccionXDefecto(int A, int B,
                                    dFloat Friccion_Estatica,
                                    dFloat Friccion_Cinetica)
{
   NewtonMaterialSetDefaultFriction(nMundo,A,B,Friccion_Estatica,Friccion_Cinetica);
}

void GD_Material_nwtn::MaterialesABElasticidadXDefecto(int A, int B,dFloat Elasticidad)
{
   NewtonMaterialSetDefaultElasticity(nMundo,A,B,Elasticidad);
}

void GD_Material_nwtn::MaterialesABConsistenciaXDefecto(int A, int B,dFloat Consistencia)
{
   NewtonMaterialSetDefaultSoftness(nMundo,A,B,Consistencia);
}

/*void Material_nwtn::RetrollamadaColisionMaterialesAB(int A,int B,void *userData)
{
   NewtonMaterialSetCollisionCallback(nMundo,A,B,userData);
}*/

#endif // _GDT_FISICAS_


