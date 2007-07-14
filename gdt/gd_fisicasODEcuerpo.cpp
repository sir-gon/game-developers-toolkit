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

#include "gd_fisicasODEcuerpo.h"
#include "gd_fisicasODEsistema.h"

dBodyID GD_CuerpODE::Crear(dWorldID MundoODE)
{
    Body=dBodyCreate(MundoODE);
}
void GD_CuerpODE::Destruir()
{
    dBodyDestroy(Body);
}

vector3df GD_CuerpODE::Posicion()
{
    return RealAVector3d(dBodyGetPosition(Body));
}
vector3df GD_CuerpODE::Rotacion()
{
    return RealAVector3d(dBodyGetRotation(Body));
}
vector3df GD_CuerpODE::ValorQuaternion()
{
    return RealAVector3d(dBodyGetQuaternion(Body));
}
vector3df GD_CuerpODE::ValorVelocidadLinear()
{
    return RealAVector3d(dBodyGetLinearVel(Body));
}
vector3df GD_CuerpODE::ValorVelocidadAngular()
{
    return RealAVector3d(dBodyGetAngularVel(Body));
}

void GD_CuerpODE::Posicionar(dReal X, dReal Y, dReal Z)
{
    dBodySetPosition(Body, X, Y, Z);
}
void GD_CuerpODE::Posicionar(vector3df Pos)
{
    Posicionar((dReal) Pos.X, (dReal) Pos.Y, (dReal) Pos.Z);
}
void GD_CuerpODE::PosicionarX(dReal X)
{
    vector3df PosA;

    PosA=Posicion();
    PosA.X=X;
    Posicionar(PosA);
}
void GD_CuerpODE::PosicionarY(dReal Y)
{
    vector3df PosA;

    PosA=Posicion();
    PosA.Y=Y;
    Posicionar(PosA);
}
void GD_CuerpODE::PosicionarZ(dReal Z)
{
    vector3df PosA;

    PosA=Posicion();
    PosA.Z=Z;
    Posicionar(PosA);

}

void GD_CuerpODE::Rotar(const dMatrix3 R)
{
    dBodySetRotation(Body,R);
}
void GD_CuerpODE::Quaternion(const dQuaternion q)
{
    dBodySetQuaternion(Body,q);
}

void GD_CuerpODE::VelocidadLinear(dReal x, dReal y, dReal z)
{
    dBodySetLinearVel(Body,x,y,z);
}
void GD_CuerpODE::VelocidadLinear(vector3df VelLinear)
{
    VelocidadLinear((dReal) VelLinear.X, (dReal) VelLinear.Y, (dReal) VelLinear.Z);
}

void GD_CuerpODE::VelocidadAngular(dReal x, dReal y, dReal z)
{
    dBodySetAngularVel(Body,x,y,z);
}
void GD_CuerpODE::VelocidadAngular(vector3df VelAngular)
{
    VelocidadAngular((dReal) VelAngular.X, (dReal) VelAngular.Y, (dReal) VelAngular.Z);
}

void GD_CuerpODE::AsignarMasa(const dMass *mass)
{
    dBodySetMass(Body, mass);
    //dBodyGetMass(Body, Masa);
}
dMass* GD_CuerpODE::ValorMasa()
{
    dBodyGetMass(Body, Masa);
    return Masa;
}

void GD_CuerpODE::AniadirFuerza(dReal X, dReal Y, dReal Z)
{
    dBodyAddForce(Body, X, Y, Z);
}

void GD_CuerpODE::AniadirFuerza(vector3df Fuerza)
{
    AniadirFuerza((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z);
}

void GD_CuerpODE::AniadirGiro(dReal X, dReal Y, dReal Z)
{
    dBodyAddTorque(Body, X, Y, Z);
}

void GD_CuerpODE::AniadirGiro(vector3df Giro)
{
    AniadirGiro((dReal) Giro.X, (dReal) Giro.Y, (dReal) Giro.Z);
}

void GD_CuerpODE::AniadirFuerzaRelativa(dReal X, dReal Y, dReal Z)
{
    dBodyAddRelForce(Body, X, Y, Z);
}

void GD_CuerpODE::AniadirFuerzaRelativa(vector3df Fuerza)
{
    AniadirFuerzaRelativa((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z);
}

void GD_CuerpODE::AniadirGiroRelativo(dReal X, dReal Y, dReal Z)
{
    dBodyAddRelTorque(Body, X, Y, Z);
}

void GD_CuerpODE::AniadirGiroRelativo(vector3df Giro)
{
    AniadirGiroRelativo((dReal) Giro.X, (dReal) Giro.Y, (dReal) Giro.Z);
}

void GD_CuerpODE::AniadirFuerzaDesdePosicion(dReal cX, dReal cY, dReal cZ,
                                             dReal pX, dReal pY, dReal pZ)
{
    dBodyAddForceAtPos(Body, cX, cY, cZ, pX, pY, pZ);
}

void GD_CuerpODE::AniadirFuerzaDesdePosicion(vector3df Fuerza,vector3df Posicion)
{
    AniadirFuerzaDesdePosicion((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z,
                               (dReal) Posicion.X, (dReal) Posicion.Y, (dReal) Posicion.Z);
}
void GD_CuerpODE::AniadirFuerzaDesdePosicionRelativa(dReal cX, dReal cY, dReal cZ,
                                                     dReal pX, dReal pY, dReal pZ)
{
    dBodyAddForceAtRelPos(Body, cX, cY, cZ, pX, pY, pZ);
}

void GD_CuerpODE::AniadirFuerzaDesdePosicionRelativa(vector3df Fuerza,vector3df Posicion)
{
    AniadirFuerzaDesdePosicionRelativa((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z,
                                        (dReal) Posicion.X, (dReal) Posicion.Y, (dReal) Posicion.Z);
}
void GD_CuerpODE::AniadirFuerzaRelativaDesdePosicion(dReal cX, dReal cY, dReal cZ,
                                                     dReal pX, dReal pY, dReal pZ)
{
    dBodyAddRelForceAtPos(Body, cX, cY, cZ, pX, pY, pZ);
}
void GD_CuerpODE::AniadirFuerzaRelativaDesdePosicion(vector3df Fuerza,vector3df Posicion)
{
    AniadirFuerzaRelativaDesdePosicion((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z,
                                        (dReal) Posicion.X, (dReal) Posicion.Y, (dReal) Posicion.Z);
}
void GD_CuerpODE::AniadirFuerzaRelativaDesdePosicionRelativa(dReal cX, dReal cY, dReal cZ,
                                                             dReal pX, dReal pY, dReal pZ)
{
    dBodyAddRelForceAtRelPos(Body, cX, cY, cZ, pX, pY, pZ);
}
void GD_CuerpODE::AniadirFuerzaRelativaDesdePosicionRelativa(vector3df Fuerza,vector3df Posicion)
{
    AniadirFuerzaRelativaDesdePosicionRelativa((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z,
                                                (dReal) Posicion.X, (dReal) Posicion.Y, (dReal) Posicion.Z);
}
const dReal* GD_CuerpODE::RetornarFuerza()
{
    return dBodyGetForce(Body);
}

const dReal* GD_CuerpODE::RetornarGiro()
{
    return dBodyGetTorque(Body);
}

void GD_CuerpODE::AsignarFuerza(dReal X, dReal Y, dReal Z)
{
    dBodySetForce(Body, X, Y, Z);
}

void GD_CuerpODE::AsignarFuerza(vector3df Fuerza)
{
    AsignarFuerza((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z);
}
void GD_CuerpODE::AsignarGiro(dReal X, dReal Y, dReal Z)
{
    dBodySetTorque(Body, X, Y, Z);
}
void GD_CuerpODE::AsignarGiro(vector3df Giro)
{
    AsignarGiro((dReal) Giro.X, (dReal) Giro.Y, (dReal) Giro.Z);
}

void GD_CuerpODE::RetornarPuntoDePosicionRelativa(dReal px, dReal py, dReal pz,
                                     dVector3 result)
{
    dBodyGetRelPointPos(Body, px, py, pz,result);
}

vector3df GD_CuerpODE::RetornarPuntoDePosicionRelativa(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    RetornarPuntoDePosicionRelativa(px,py,pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;
}

void GD_CuerpODE::RetornarPuntoDeVelocidadRelativa(dReal px, dReal py, dReal pz,
                                                    dVector3 result)
{
    dBodyGetRelPointVel(Body, px, py, pz,result);
}
vector3df GD_CuerpODE::RetornarPuntoDeVelocidadRelativa(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    RetornarPuntoDeVelocidadRelativa(px,py,pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;
}
void GD_CuerpODE::RetornarPuntoDeVelocidad(dReal px, dReal py, dReal pz,
                                            dVector3 result)
{
    dBodyGetPointVel(Body,px, py, pz,result);
}
vector3df GD_CuerpODE::RetornarPuntoDeVelocidad(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    RetornarPuntoDeVelocidad(px, py, pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;

}
void GD_CuerpODE::RetornarPosicionRelativaAlPunto(dReal px, dReal py, dReal pz,
                                                    dVector3 result)
{
    dBodyGetPosRelPoint(Body,px, py, pz,result);
}
vector3df GD_CuerpODE::RetornarPosicionRelativaAlPunto(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    RetornarPosicionRelativaAlPunto(px, py, pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;
}


void GD_CuerpODE::Vector_A_Mundo(dReal px, dReal py, dReal pz,
                                 dVector3 result)
{
    dBodyVectorToWorld(Body, px, py, pz,result);
}
vector3df GD_CuerpODE::Vector_A_Mundo(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    Vector_A_Mundo(px, py, pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;
}

void GD_CuerpODE::Vector_De_Mundo(dReal px, dReal py, dReal pz,
                                    dVector3 result)
{
    dBodyVectorFromWorld(Body, px, py, pz, result);
}
vector3df GD_CuerpODE::Vector_De_Mundo(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    Vector_De_Mundo(px, py, pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;
}


void GD_CuerpODE::Activar()
{
    dBodyEnable(Body);
}
void GD_CuerpODE::Desactivar()
{
    dBodyDisable(Body);
}
bool GD_CuerpODE::Activo()
{
    return (bool)dBodyIsEnabled(Body);
}


void GD_CuerpODE::ModoAutodesactivar(bool bDeshabilitable)
{
    dBodySetAutoDisableFlag(Body, (int) bDeshabilitable);
}
bool GD_CuerpODE::ValorModoAutodesactivar()
{
    return (bool)dBodyGetAutoDisableFlag(Body);
}
void GD_CuerpODE::Autodesactivacion_por_UmbralLinear(dReal UmbralLinear)
{
    dBodySetAutoDisableLinearThreshold(Body, UmbralLinear);
}
dReal GD_CuerpODE::ValorAutodesactivacion_por_UmbralLinear()
{
    return dBodyGetAutoDisableLinearThreshold(Body);
}
void GD_CuerpODE::AutoDesactivacion_por_UmbralAngular(dReal UmbralAngular)
{
    dBodySetAutoDisableAngularThreshold(Body, UmbralAngular);
}
dReal GD_CuerpODE::ValorAutoDesactivacion_por_UmbralAngular()
{
    return dBodyGetAutoDisableAngularThreshold(Body);
}
void GD_CuerpODE::AutoDesactivacion_por_Iteraciones(int Iteraciones)
{
    dBodySetAutoDisableSteps (Body,Iteraciones);
}
int GD_CuerpODE::ValorAutoDesactivacion_por_Iteraciones()
{
    return dBodyGetAutoDisableSteps(Body);
}
void GD_CuerpODE::AutoDesactivacion_por_Tiempo(dReal Tiempo)
{
    dBodySetAutoDisableTime(Body, Tiempo);
}
dReal GD_CuerpODE::ValorAutoDesactivacion_por_Tiempo()
{
    return dBodyGetAutoDisableTime(Body);
}
void GD_CuerpODE::AutoDesactivacion_por_Default()
{
    dBodySetAutoDisableDefaults(Body);
}

void GD_CuerpODE::SetData(void *data)
{
    dBodySetData(Body, data);
}
void* GD_CuerpODE::GetData()
{
    return (void*) dBodyGetData(Body);
}

void GD_CuerpODE::ModoDeRotacionFinita(bool activo)
{
    dBodySetFiniteRotationMode(Body, (int) activo);
}
bool GD_CuerpODE::RotacionFinitaActivada()
{
    return dBodyGetFiniteRotationMode(Body);
}
void GD_CuerpODE::EjeDeRotacionFinita(dReal x, dReal y, dReal z)
{
    dBodySetFiniteRotationAxis(Body,x, y, z);
}
void GD_CuerpODE::EjeDeRotacionFinita(vector3df ejes)
{
    EjeDeRotacionFinita((dReal) ejes.X, (dReal) ejes.Y, (dReal) ejes.Z);
}

int GD_CuerpODE::Articulaciones()
{
    return dBodyGetNumJoints(Body);
}
dJointID GD_CuerpODE::SelecArticulacion(int index)
{
    return dBodyGetJoint(Body, index);
}

void GD_CuerpODE::ActivarGravedad(bool activo)
{
    dBodySetGravityMode(Body, (int) activo);
}
bool GD_CuerpODE::GravedadActiva()
{
    return (bool) dBodyGetGravityMode(Body);
}

/* ///Funciones escritas en la documentacion de ODG pero que no son operativas
void GD_CuerpODE::UmbralDeAutoDesactivacion_ModoSF1(dReal umbral)
{
    dBodySetAutoDisableThresholdSF1(Body, umbral);
}
dReal GD_CuerpODE::ValorUmbralDeAutoDesactivacion_ModoSF1()
{
    return dBodyGetAutoDisableThresholdSF1(Body);
}

{
    dBodySetAutoDisableStepsSF1(Body, Iteraciones);
}
int GD_CuerpODE::ValorAutoDesactivacion_por_Iteraciones_ModoSF1()
{
    return dBodyGetAutoDisableStepsSF1(Body);
}

void GD_CuerpODE::ModoSF1_AutoDesactivacion(bool activo)
{
    dBodySetAutoDisableSF1(Body, (int) activo);
}
bool GD_CuerpODE::ValorModoSF1_AutoDesactivacion()
{
    return (bool)dBodyGetAutoDisableSF1(Body);
}
*/

#endif //_GDT_FISICAS_ODE_
