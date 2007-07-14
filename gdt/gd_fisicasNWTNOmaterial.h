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

#ifndef GD_FISICAS_NEWTON_MATERIAL_H_
#define GD_FISICAS_NEWTON_MATERIAL_H_

#include <stdio.h>
#include <Newton.h>

/* No Documentar esto */
#ifndef _GDT_DOXYGEN_IGNORAR_
struct MaterialData
{
   char* pszNombre;
   int ID;
};
#endif /* _GDT_DOXYGEN_IGNORAR_ */


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


#endif // GD_FISICAS_NEWTON_MATERIAL_H_

#endif // _GDT_FISICAS_NEWTON_
