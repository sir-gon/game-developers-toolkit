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
* \class GDT::Fisicas::CuerpoNwt
*
* Implementa un Cuerpo de f&iacute;sicas Newton.
* 
* \warning Esta caracter&iacute;stica esta disponible cuando _GDT_FISICAS_NEWTON_ est&aacute; definido en tiempo de compilaci&oacute;n.
*
* \author Astucia
*/
 
#include "gd_fisicasNwtCuerpo.h"

GDT::Fisicas::CuerpoNwt::CuerpoNwt()
{
   MundoNwtn=NewtonCreate(PhysicsAlloc,PhysicsFree);
}

GDT::Fisicas::CuerpoNwt::CuerpoNwt(NewtonWorld* NwtnWorld)
{
   MundoNwtn=NwtnWorld;
}

GDT::Fisicas::CuerpoNwt::~CuerpoNwt(){};

void GDT::Fisicas::CuerpoNwt::Inicializar(NewtonWorld* NwtnWorld)
{
   MundoNwtn=NwtnWorld;
}

void GDT::Fisicas::CuerpoNwt::Cargar(char *filename,int EscudoColision)
{
   //Carga el objeto a la malla e inicializa el cuerpo fisico.
   malla.Cargar(filename);
   fisica.Inicializa(MundoNwtn,malla.nodon,EscudoColision);
}

void GDT::Fisicas::CuerpoNwt::CargarTangentes(char *filename,int EscudoColision)
{
   malla.CargarTangentes(filename);
   fisica.Inicializa(MundoNwtn,malla.nodon,EscudoColision);
}
void GDT::Fisicas::CuerpoNwt::CrearCubo()
{
   malla.CrearCubo();
   fisica.Inicializa(MundoNwtn,malla.nodon,0);
}

void GDT::Fisicas::CuerpoNwt::CrearCubo(float tamx, float tamy, float tamz )
{
   malla.CrearCubo(tamx,tamy,tamz);
   fisica.Inicializa(MundoNwtn,malla.nodon,0);
}

void GDT::Fisicas::CuerpoNwt::CrearPlano( int tx, int ty )
{
   malla.CrearPlano(tx,ty);
   fisica.Inicializa(MundoNwtn,malla.nodon,0);
}

void GDT::Fisicas::CuerpoNwt::CrearCilindro( int tx, int ty, f32 radio  )
{
   malla.CrearCilindro(tx,ty,radio);
   fisica.Inicializa(MundoNwtn,malla.nodon,4);
}

void GDT::Fisicas::CuerpoNwt::CrearCono( int tx, int ty, f32 radio  )
{
   malla.CrearCono(tx,ty,radio);
   fisica.Inicializa(MundoNwtn,malla.nodon,2);
}

void GDT::Fisicas::CuerpoNwt::CrearEsfera( float radio, int polynum)
{
   malla.CrearEsfera(radio,polynum);
   fisica.Inicializa(MundoNwtn,malla.nodon,1);
}


void GDT::Fisicas::CuerpoNwt::CrearEscenarioNewtoneano(char *filename)

{
   malla.Cargar(filename);
   fisica.CrearEscenarioNewtoneano(MundoNwtn,malla.nodon,malla.mesh_smgr,malla.static_mesh);
}

//****************************************************************************************
// Comandos de Fisica.

void GDT::Fisicas::CuerpoNwt::AsignarFisicas(float masa,vector3df vinercia,
                           vector3df vfuerza,
                           vector3df vomega,
                           int MatID)
{
   fisica.AsignarFuerza(vfuerza.X,vfuerza.Y,vfuerza.Z);
   fisica.AsignarOmega(vomega);
   fisica.AsignarMasa(masa,vinercia);
   fisica.AsignaMaterial(MatID);
   //AplicarFisica();
}

void GDT::Fisicas::CuerpoNwt::Fuerza(vector3df vfuerza)
{
   fisica.AsignarFuerza(vfuerza.X,vfuerza.Y,vfuerza.Z);
   AplicarFisica();
}

void GDT::Fisicas::CuerpoNwt::Omega(vector3df vomega)
{
   fisica.AsignarGiro(vomega.X,vomega.Y,vomega.Z);
   AplicarFisica();
}

void GDT::Fisicas::CuerpoNwt::Masa(float masa,vector3df vinercia)
{
   dFloat M,X,Y,Z;

   M=(dFloat) masa;
   X=(dFloat) vinercia.X;
   Y=(dFloat) vinercia.Y;
   Z=(dFloat) vinercia.Z;

   fisica.AsignarMasa(M,X,Y,Z);
   AplicarFisica();
}

void GDT::Fisicas::CuerpoNwt::Material(int MatID)
{
   fisica.AsignaMaterial(MatID);
   AplicarFisica();
}



//****************************************************************************************
// Comandos de Modificacion

void GDT::Fisicas::CuerpoNwt::Posicionar(vector3df pos)
{
   malla.Posicionar(pos);
   fisica.AsignarMatrizRecursivamente(malla.nodon->getRelativeTransformation());
}

void GDT::Fisicas::CuerpoNwt::Actualizar_Transformacion() //Experimental
{
   //NewtonBodySetTransformCallback(fisica.pCuerpoNwtn, Transformaciones());
      //const NewtonBody* bodyPtr,
      //NewtonSetTransform callback)

}

void GDT::Fisicas::CuerpoNwt::Actualizar()
{
   //AplicarFisica();
   fisica.AplicarFuerza_Torcion();
   fisica.Actualizar();
   malla.nodon->setPosition(fisica.matrix.getTranslation());
   malla.nodon->setRotation(fisica.matrix.getRotationDegrees());

} 

#endif // _GDT_FISICAS_

