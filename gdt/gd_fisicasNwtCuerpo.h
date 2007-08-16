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

#ifndef GD_CUERPO_NEWTON_H
#define GD_CUERPO_NEWTON_H

#include "gd_malla.h"
#include "gd_fisicasNwtMundo.h"
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

namespace GDT
{

namespace Fisicas
{

//! Un Cuerpo Newton
class CuerpoNwt
{
	public:
		_GDT_EXPORT_ CuerpoNwt();
		_GDT_EXPORT_ CuerpoNwt( NewtonWorld* NwtnWorld );
		_GDT_EXPORT_ ~CuerpoNwt();


		NewtonWorld* MundoNwtn;
		GDT::Nodo::Malla malla;
		MundoNwt fisica;
		MaterialNwt material;

		//Creacion
		_GDT_EXPORT_ void Inicializar ( NewtonWorld* NwtnWorld );
		_GDT_EXPORT_ void Cargar ( char *filename,int EscudoColision=0 );
		_GDT_EXPORT_ void CargarTangentes ( char *filename,int EscudoColision=0 );
		_GDT_EXPORT_ void CrearCubo();
		_GDT_EXPORT_ void CrearCubo ( float tamx, float tamy, float tamz );
		_GDT_EXPORT_ void CrearPlano ( int tx, int ty );
		_GDT_EXPORT_ void CrearCilindro ( int tx, int ty, f32 radio );
		_GDT_EXPORT_ void CrearCono ( int tx, int ty, f32 radio );
		_GDT_EXPORT_ void CrearEsfera ( float radio, int polynum = 16 );
		_GDT_EXPORT_ void CrearEscenarioNewtoneano ( char *filename );
		// Fisica
		_GDT_EXPORT_ void AplicarFisica() {fisica.AplicarFuerza_Torcion();};

		_GDT_EXPORT_ void AsignarFisicas ( float masa,vector3df vinercia,
		                      vector3df vfuerza,
		                      vector3df vomega,
		                      int MatID );

		_GDT_EXPORT_ void Fuerza ( vector3df vfuerza );
		_GDT_EXPORT_ void Omega ( vector3df vomega );
		_GDT_EXPORT_ void Masa ( float masa,vector3df vinercia );
		_GDT_EXPORT_ void Material ( int MatID );

		//Modificacion
		_GDT_EXPORT_ void Posicionar ( vector3df pos );
		_GDT_EXPORT_ void Actualizar_Transformacion();
		_GDT_EXPORT_ void Actualizar();
		_GDT_EXPORT_ void ActivarFisicas() {Actualizar();};

};

} // FIN NAMESPACE FISICAS

} // FIN NAMESPACE GDT

#endif  // GD_CUERPO_NEWTON_H

#endif // _GDT_FISICAS_NEWTON_
