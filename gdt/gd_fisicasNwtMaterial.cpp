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

/*!
* \class GD_FisicasNwtMaterial
*
* Implementa las caracter&iacute;sticas del material de f&iacute;sicas Newton
*
* \warning Esta caracter&iacute;stica esta disponible cuando _GDT_FISICAS_NEWTON_ est&aacute; definido en tiempo de compilaci&oacute;n.
*
* \author Astucia
*/

#include "gd_fisicasNwtMaterial.h"

GD_FisicasNwtMaterial::GD_FisicasNwtMaterial()
{

}
GD_FisicasNwtMaterial::~GD_FisicasNwtMaterial()
{
   //NewtonMaterialDestroyAllGroupID(nMundo);
}

int GD_FisicasNwtMaterial::IDMaterialPorDefecto()
{
   return NewtonMaterialGetDefaultGroupID(nMundo);
}

int GD_FisicasNwtMaterial::CreaGrupoID()
{
   return NewtonMaterialCreateGroupID(nMundo);
}
MaterialData GD_FisicasNwtMaterial::CreaGrupoID(char* pszNombre)
{
   MaterialData MaterialTipo;
   MaterialTipo.pszNombre=pszNombre;
   MaterialTipo.ID=NewtonMaterialCreateGroupID(nMundo);
   return MaterialTipo;
}

void GD_FisicasNwtMaterial::MaterialesABColisionXDefecto(int A, int B, bool Activa)
{
   NewtonMaterialSetDefaultCollidable(nMundo,A,B,(int)Activa);
}

void GD_FisicasNwtMaterial::MaterialesABColisionContinua(int A, int B, bool Activa)
{
   NewtonMaterialSetContinuousCollisionMode(nMundo,A,B,(int)Activa);
}

void GD_FisicasNwtMaterial::MaterialesABFriccionXDefecto(int A, int B,
                                    dFloat Friccion_Estatica,
                                    dFloat Friccion_Cinetica)
{
   NewtonMaterialSetDefaultFriction(nMundo,A,B,Friccion_Estatica,Friccion_Cinetica);
}

void GD_FisicasNwtMaterial::MaterialesABElasticidadXDefecto(int A, int B,dFloat Elasticidad)
{
   NewtonMaterialSetDefaultElasticity(nMundo,A,B,Elasticidad);
}

void GD_FisicasNwtMaterial::MaterialesABConsistenciaXDefecto(int A, int B,dFloat Consistencia)
{
   NewtonMaterialSetDefaultSoftness(nMundo,A,B,Consistencia);
}

/*void Material_nwtn::RetrollamadaColisionMaterialesAB(int A,int B,void *userData)
{
   NewtonMaterialSetCollisionCallback(nMundo,A,B,userData);
}*/

#endif // _GDT_FISICAS_NEWTON_


