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
#include "gd_fisicasNWTNOnwtno.h"
#include "gd_fisicasNWTNOmaterial.h"


class GD_Cuerpo
{
	public:
		GD_Cuerpo();
		GD_Cuerpo ( NewtonWorld* NwtnWorld );
		~GD_Cuerpo();


		NewtonWorld* MundoNwtn;
		GD_Malla malla;
		GD_Newtoneano fisica;
		GD_Material_nwtn material;

		//Creacion
		void Inicializar ( NewtonWorld* NwtnWorld );
		void Cargar ( char *filename,int EscudoColision=0 );
		void CargarTangentes ( char *filename,int EscudoColision=0 );
		void CrearCubo();
		void CrearCubo ( float tamx, float tamy, float tamz );
		void CrearPlano ( int tx, int ty );
		void CrearCilindro ( int tx, int ty, f32 radio );
		void CrearCono ( int tx, int ty, f32 radio );
		void CrearEsfera ( float radio, int polynum = 16 );
		void CrearEscenarioNewtoneano ( char *filename );
		// Fisica
		void AplicarFisica() {fisica.AplicarFuerza_Torcion();};

		void AsignarFisicas ( float masa,vector3df vinercia,
		                      vector3df vfuerza,
		                      vector3df vomega,
		                      int MatID );

		void Fuerza ( vector3df vfuerza );
		void Omega ( vector3df vomega );
		void Masa ( float masa,vector3df vinercia );
		void Material ( int MatID );

		//Modificacion
		void Posicionar ( vector3df pos );
		void Actualizar_Transformacion();
		void Actualizar();
		void ActivarFisicas() {Actualizar();};

};




#endif  // GD_CUERPO_NEWTON_H

#endif // _GDT_FISICAS_NEWTON_
