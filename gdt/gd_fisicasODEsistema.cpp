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

#if defined(_GDT_FISICAS_ODE_)

/*!
* \class GD_SistemaODE
*
* Crea y maneja un Mundo de F&iacute;sicas usando ODE.
* 
* \warning Esta caracter&iacute;stica esta disponible cuando _GDT_FISICAS_ODE_ est&aacute; definido en tiempo de compilaci&oacute;n.
*
* \author Astucia
*/

#include "gd_fisicasODEsistema.h"

GD_SistemaODE::GD_SistemaODE()
{
   MundoODE=CrearMundoODE();
}

dWorldID GD_SistemaODE::CrearMundoODE()
{
   return dWorldCreate();
}
void GD_SistemaODE::DestruirMundoODE()
{
   dWorldDestroy(MundoODE);
}

vector3df GD_SistemaODE::Gravedad(dReal x, dReal y, dReal z)
{
   dWorldSetGravity(MundoODE,x, y, z);
   return Gravedad();
}
vector3df GD_SistemaODE::Gravedad(vector3df grav)
{
   Gravedad((dReal) grav.X, (dReal) grav.Y, (dReal) grav.Z);
   return Gravedad();
}

vector3df GD_SistemaODE::Gravedad()
{
   vector3df gravI;
   dWorldGetGravity(MundoODE, (dReal*) &gravI);
   return gravI;
}

void GD_SistemaODE::AsignarERP(dReal erp)
{
   dWorldSetERP(MundoODE,erp);
}
dReal GD_SistemaODE::ObtenerERP()
{
   return dWorldGetERP(MundoODE);
}
void GD_SistemaODE::AsignarCFM(dReal cfm)
{
   dWorldSetCFM(MundoODE,cfm);
}
dReal GD_SistemaODE::ObtenerCFM()
{
   return dWorldGetCFM (MundoODE);
}

void GD_SistemaODE::ModoAutodesactivar(bool bDeshabilitable)
{
    dWorldSetAutoDisableFlag(MundoODE, (int) bDeshabilitable);
}
bool GD_SistemaODE::ValorModoAutodesactivar()
{
    return (bool)dWorldGetAutoDisableFlag(MundoODE);
}
void GD_SistemaODE::Autodesactivacion_por_UmbralLinear(dReal UmbralLinear)
{
    dWorldSetAutoDisableLinearThreshold(MundoODE, UmbralLinear);
}
dReal GD_SistemaODE::ValorAutodesactivacion_por_UmbralLinear()
{
    return dWorldGetAutoDisableLinearThreshold(MundoODE);
}
void GD_SistemaODE::AutoDesactivacion_por_UmbralAngular(dReal UmbralAngular)
{
    dWorldSetAutoDisableAngularThreshold(MundoODE, UmbralAngular);
}
dReal GD_SistemaODE::ValorAutoDesactivacion_por_UmbralAngular()
{
    return dWorldGetAutoDisableAngularThreshold(MundoODE);
}
void GD_SistemaODE::AutoDesactivacion_por_Iteraciones(int Iteraciones)
{
    dWorldSetAutoDisableSteps(MundoODE, Iteraciones);
}
int GD_SistemaODE::ValorAutoDesactivacion_por_Iteraciones()
{
    return dWorldGetAutoDisableSteps(MundoODE);
}
void GD_SistemaODE::AutoDesactivacion_por_Tiempo(dReal Tiempo)
{
    dWorldSetAutoDisableTime(MundoODE, Tiempo);
}
dReal GD_SistemaODE::ValorAutoDesactivacion_por_Tiempo()
{
    return dWorldGetAutoDisableTime(MundoODE);
}
vector3df GD_SistemaODE::Impulso_a_Fuerza(dReal Incremento,vector3df Impulso)
{
    dVector3 vFuerza;
    vector3df vFuerzaR;

    dWorldImpulseToForce(MundoODE, Incremento,
            (dReal) Impulso.X, (dReal) Impulso.Y, (dReal) Impulso.Z, vFuerza);

    vFuerzaR.X=vFuerza[0];  vFuerzaR.Y=vFuerza[1];  vFuerzaR.Z=vFuerza[2];

    return vFuerzaR;

}


void GD_SistemaODE::Actualizar(dReal VelIteracion)
{
    dWorldStep (MundoODE, VelIteracion);
}
void GD_SistemaODE::Actualzar_Modo_QS(dReal VelIteracion)
{
    dWorldStep(MundoODE,VelIteracion);
}
void GD_SistemaODE::NumIteraciones_modo_QS(int Iteraciones)
{
    dWorldSetQuickStepNumIterations (MundoODE, Iteraciones);
}
int GD_SistemaODE::ValorNumIteraciones_modo_QS()
{
    return dWorldGetQuickStepNumIterations(MundoODE);
}

void GD_SistemaODE::VelocidadMaximaDeCorreccion_por_Contacto(dReal vel)
{
    dWorldSetContactMaxCorrectingVel(MundoODE, vel);
}
dReal GD_SistemaODE::ValorVelocidadMaximaDeCorreccion_por_Contacto()
{
    return dWorldGetContactMaxCorrectingVel(MundoODE);
}

void GD_SistemaODE::SuperficieDeContacto(dReal Profundidad)
{
    dWorldSetContactSurfaceLayer (MundoODE,Profundidad);
}
dReal GD_SistemaODE::ValorSuperficieDeContacto()
{
    return dWorldGetContactSurfaceLayer(MundoODE);
}

void GD_SistemaODE::Actualizar_Modo_SF1(dReal VelIteracion, int MaxIteraciones)
{
    dWorldStepFast1(MundoODE, VelIteracion, MaxIteraciones);
}
void GD_SistemaODE::ProfundidadDeAutoactivacionSF1(int ProfundidadDeAutoactivacion)
{
    dWorldSetAutoEnableDepthSF1(MundoODE, ProfundidadDeAutoactivacion);
}
int GD_SistemaODE::ValorProfundidadDeAutoactivacionSF1()
{
    return dWorldGetAutoEnableDepthSF1(MundoODE);
}

//*******************************************************
//********************* Funciones ***********************
//*******************************************************
void QuaternionToEuler(const dQuaternion quaternion,irr::core::vector3df &euler){
      dReal w,x,y,z;
      w=quaternion[0];
      x=quaternion[1];
      y=quaternion[2];
      z=quaternion[3];
      double sqw = w*w;
      double sqx = x*x;
      double sqy = y*y;
      double sqz = z*z;
      // heading
      euler.Z = (irr::f32) (atan2(2.0 * (x*y + z*w),(sqx - sqy - sqz + sqw))*irr::core::RADTODEG64);
      // bank
      euler.X = (irr::f32) (atan2(2.0 * (y*z + x*w),(-sqx - sqy + sqz + sqw))*irr::core::RADTODEG64);
      // attitude
      euler.Y = (irr::f32) (asin(-2.0 * (x*z - y*w))*irr::core::RADTODEG64);
}

void EulerToQuaternion(const irr::core::vector3df &euler, dQuaternion quaternion){
      double _heading=euler.Z*irr::core::DEGTORAD64/2.0;
      double _attitude=euler.Y*irr::core::DEGTORAD64/2.0;
      double _bank=euler.X*irr::core::DEGTORAD64/2.0;
      double c1 = cos(_heading);
      double s1 = sin(_heading);
      double c2 = cos(_attitude);
      double s2 = sin(_attitude);
      double c3 = cos(_bank);
      double s3 = sin(_bank);
      double c1c2 = c1*c2;
      double s1s2 = s1*s2;
      //w
      quaternion[0]=(dReal) (c1c2*c3 + s1s2*s3);
      //x
      quaternion[1]=(dReal) (c1c2*s3 - s1s2*c3);
      //y
      quaternion[2]=(dReal) (c1*s2*c3 + s1*c2*s3);
      //z
      quaternion[3]=(dReal) (s1*c2*c3 - c1*s2*s3);
}

vector3df RealAVector3d(const dReal* Val)
{
    vector3df Vectr;
    Vectr.X=(float)Val[0];
    Vectr.Y=(float)Val[1];
    Vectr.Z=(float)Val[2];
    return Vectr;
}
dReal* Vector3dAReal(const vector3df Val)
{
    dReal* Vectr;

    Vectr[0]=(float)Val.X;
    Vectr[1]=(float)Val.Y;
    Vectr[2]=(float)Val.Z;

    return Vectr;
} 

#endif //_GDT_FISICAS_ODE_
