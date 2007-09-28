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

/* No Documentar esto */
#ifndef _GDT_DOXYGEN_IGNORAR_
struct MaterialData
{
	char* pszNombre;
	int ID;
};
#endif /* _GDT_DOXYGEN_IGNORAR_ */


namespace GDT
{

	namespace Fisica
	{

		class MaterialNwt
		{
			public:

				NewtonWorld* nMundo;


				_GDT_EXPORT_ MaterialNwt();
				_GDT_EXPORT_ MaterialNwt ( NewtonWorld* nMundo );
				_GDT_EXPORT_ ~MaterialNwt();



				_GDT_EXPORT_ int IDMaterialPorDefecto();
				_GDT_EXPORT_ int CreaGrupoID();
				_GDT_EXPORT_ MaterialData CreaGrupoID ( char* pszNombre );

				_GDT_EXPORT_ void MaterialesABColisionXDefecto ( int A, int B, bool Activa );
				_GDT_EXPORT_ void MaterialesABColisionContinua ( int A, int B, bool Activa=true );

				_GDT_EXPORT_ void MaterialesABFriccionXDefecto ( int A, int B,
				        dFloat Friccion_Estatica,
				        dFloat Friccion_Cinetica );
				/*Nota: El valor de los coeficientes de friccion deve ser positiva; El valor
				de la friccion cintetica deve ser menor a la friccion estatica; El valor
				recomendado para la friccion es: menor o igual a 1.0; Por consideracion hacia
				algunos materiales Newton soporta un valor de 2.0 en la friccion cinetica.*/

				_GDT_EXPORT_ void MaterialesABElasticidadXDefecto ( int A, int B,dFloat Elasticidad );
				/*Nota: El valor del coeficiente de elasticidad deve ser positivo; Se recomienda
				que se usen valores merores o iguales a 1.0.*/

				_GDT_EXPORT_ void MaterialesABConsistenciaXDefecto ( int A, int B,dFloat Consistencia );
				/*Nota: El valor del coeficiente de Consistencia (Suavidad) deve ser positivo;
				Se recomienda que se usen valores merores o iguales a 1.0; un valor tipico
				de consistencia es de 0.15*/

				//void RetrollamadaColisionMaterialesAB(int A,int B,void *userData);


		};

	} // FIN NAMESPACE FISICAS

} // FIN NAMESPACE GDT

#endif // GD_FISICAS_NEWTON_MATERIAL_H_

#endif // _GDT_FISICAS_NEWTON_
