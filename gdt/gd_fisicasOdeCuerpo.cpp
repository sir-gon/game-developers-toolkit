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
* \class GD_FisicasOdeCuerpo
*
* Crea y maneja un Cuerpo Rígido, el cual puede interactuar con un Mundo
* y con otros Cuerpos que esten presentes en el mismo Mundo.
*
* \warning Esta caracter&iacute;stica esta disponible cuando _GDT_FISICAS_ODE_ est&aacute; definido en tiempo de compilaci&oacute;n.
*
* \author Astucia
*/

#include "gd_fisicasOdeCuerpo.h"
#include "gd_fisicasOdeSistema.h"

dBodyID GD_FisicasOdeCuerpo::Crear(dWorldID MundoODE)
{
    Body=dBodyCreate(MundoODE);
}
void GD_FisicasOdeCuerpo::Destruir()
{
    dBodyDestroy(Body);
}

vector3df GD_FisicasOdeCuerpo::Posicion()
{
    return RealAVector3d(dBodyGetPosition(Body));
}
vector3df GD_FisicasOdeCuerpo::Rotacion()
{
    return RealAVector3d(dBodyGetRotation(Body));
}
vector3df GD_FisicasOdeCuerpo::ValorQuaternion()
{
    return RealAVector3d(dBodyGetQuaternion(Body));
}
vector3df GD_FisicasOdeCuerpo::ValorVelocidadLinear()
{
    return RealAVector3d(dBodyGetLinearVel(Body));
}
vector3df GD_FisicasOdeCuerpo::ValorVelocidadAngular()
{
    return RealAVector3d(dBodyGetAngularVel(Body));
}

void GD_FisicasOdeCuerpo::Posicionar(dReal X, dReal Y, dReal Z)
{
    dBodySetPosition(Body, X, Y, Z);
}
void GD_FisicasOdeCuerpo::Posicionar(vector3df Pos)
{
    Posicionar((dReal) Pos.X, (dReal) Pos.Y, (dReal) Pos.Z);
}
void GD_FisicasOdeCuerpo::PosicionarX(dReal X)
{
    vector3df PosA;

    PosA=Posicion();
    PosA.X=X;
    Posicionar(PosA);
}
void GD_FisicasOdeCuerpo::PosicionarY(dReal Y)
{
    vector3df PosA;

    PosA=Posicion();
    PosA.Y=Y;
    Posicionar(PosA);
}
void GD_FisicasOdeCuerpo::PosicionarZ(dReal Z)
{
    vector3df PosA;

    PosA=Posicion();
    PosA.Z=Z;
    Posicionar(PosA);

}

void GD_FisicasOdeCuerpo::Rotar(const dMatrix3 R)
{
    dBodySetRotation(Body,R);
}
void GD_FisicasOdeCuerpo::Quaternion(const dQuaternion q)
{
    dBodySetQuaternion(Body,q);
}

void GD_FisicasOdeCuerpo::VelocidadLinear(dReal x, dReal y, dReal z)
{
    dBodySetLinearVel(Body,x,y,z);
}
void GD_FisicasOdeCuerpo::VelocidadLinear(vector3df VelLinear)
{
    VelocidadLinear((dReal) VelLinear.X, (dReal) VelLinear.Y, (dReal) VelLinear.Z);
}

void GD_FisicasOdeCuerpo::VelocidadAngular(dReal x, dReal y, dReal z)
{
    dBodySetAngularVel(Body,x,y,z);
}
void GD_FisicasOdeCuerpo::VelocidadAngular(vector3df VelAngular)
{
    VelocidadAngular((dReal) VelAngular.X, (dReal) VelAngular.Y, (dReal) VelAngular.Z);
}

void GD_FisicasOdeCuerpo::AsignarMasa(const dMass *mass)
{
    dBodySetMass(Body, mass);
    //dBodyGetMass(Body, Masa);
}
dMass* GD_FisicasOdeCuerpo::ValorMasa()
{
    dBodyGetMass(Body, Masa);
    return Masa;
}

void GD_FisicasOdeCuerpo::AniadirFuerza(dReal X, dReal Y, dReal Z)
{
    dBodyAddForce(Body, X, Y, Z);
}

void GD_FisicasOdeCuerpo::AniadirFuerza(vector3df Fuerza)
{
    AniadirFuerza((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z);
}

void GD_FisicasOdeCuerpo::AniadirGiro(dReal X, dReal Y, dReal Z)
{
    dBodyAddTorque(Body, X, Y, Z);
}

void GD_FisicasOdeCuerpo::AniadirGiro(vector3df Giro)
{
    AniadirGiro((dReal) Giro.X, (dReal) Giro.Y, (dReal) Giro.Z);
}

void GD_FisicasOdeCuerpo::AniadirFuerzaRelativa(dReal X, dReal Y, dReal Z)
{
    dBodyAddRelForce(Body, X, Y, Z);
}

void GD_FisicasOdeCuerpo::AniadirFuerzaRelativa(vector3df Fuerza)
{
    AniadirFuerzaRelativa((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z);
}

void GD_FisicasOdeCuerpo::AniadirGiroRelativo(dReal X, dReal Y, dReal Z)
{
    dBodyAddRelTorque(Body, X, Y, Z);
}

void GD_FisicasOdeCuerpo::AniadirGiroRelativo(vector3df Giro)
{
    AniadirGiroRelativo((dReal) Giro.X, (dReal) Giro.Y, (dReal) Giro.Z);
}

void GD_FisicasOdeCuerpo::AniadirFuerzaDesdePosicion(dReal cX, dReal cY, dReal cZ,
                                             dReal pX, dReal pY, dReal pZ)
{
    dBodyAddForceAtPos(Body, cX, cY, cZ, pX, pY, pZ);
}

void GD_FisicasOdeCuerpo::AniadirFuerzaDesdePosicion(vector3df Fuerza,vector3df Posicion)
{
    AniadirFuerzaDesdePosicion((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z,
                               (dReal) Posicion.X, (dReal) Posicion.Y, (dReal) Posicion.Z);
}
void GD_FisicasOdeCuerpo::AniadirFuerzaDesdePosicionRelativa(dReal cX, dReal cY, dReal cZ,
                                                     dReal pX, dReal pY, dReal pZ)
{
    dBodyAddForceAtRelPos(Body, cX, cY, cZ, pX, pY, pZ);
}

void GD_FisicasOdeCuerpo::AniadirFuerzaDesdePosicionRelativa(vector3df Fuerza,vector3df Posicion)
{
    AniadirFuerzaDesdePosicionRelativa((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z,
                                        (dReal) Posicion.X, (dReal) Posicion.Y, (dReal) Posicion.Z);
}
void GD_FisicasOdeCuerpo::AniadirFuerzaRelativaDesdePosicion(dReal cX, dReal cY, dReal cZ,
                                                     dReal pX, dReal pY, dReal pZ)
{
    dBodyAddRelForceAtPos(Body, cX, cY, cZ, pX, pY, pZ);
}
void GD_FisicasOdeCuerpo::AniadirFuerzaRelativaDesdePosicion(vector3df Fuerza,vector3df Posicion)
{
    AniadirFuerzaRelativaDesdePosicion((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z,
                                        (dReal) Posicion.X, (dReal) Posicion.Y, (dReal) Posicion.Z);
}
void GD_FisicasOdeCuerpo::AniadirFuerzaRelativaDesdePosicionRelativa(dReal cX, dReal cY, dReal cZ,
                                                             dReal pX, dReal pY, dReal pZ)
{
    dBodyAddRelForceAtRelPos(Body, cX, cY, cZ, pX, pY, pZ);
}
void GD_FisicasOdeCuerpo::AniadirFuerzaRelativaDesdePosicionRelativa(vector3df Fuerza,vector3df Posicion)
{
    AniadirFuerzaRelativaDesdePosicionRelativa((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z,
                                                (dReal) Posicion.X, (dReal) Posicion.Y, (dReal) Posicion.Z);
}
const dReal* GD_FisicasOdeCuerpo::RetornarFuerza()
{
    return dBodyGetForce(Body);
}

const dReal* GD_FisicasOdeCuerpo::RetornarGiro()
{
    return dBodyGetTorque(Body);
}

void GD_FisicasOdeCuerpo::AsignarFuerza(dReal X, dReal Y, dReal Z)
{
    dBodySetForce(Body, X, Y, Z);
}

void GD_FisicasOdeCuerpo::AsignarFuerza(vector3df Fuerza)
{
    AsignarFuerza((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z);
}
void GD_FisicasOdeCuerpo::AsignarGiro(dReal X, dReal Y, dReal Z)
{
    dBodySetTorque(Body, X, Y, Z);
}
void GD_FisicasOdeCuerpo::AsignarGiro(vector3df Giro)
{
    AsignarGiro((dReal) Giro.X, (dReal) Giro.Y, (dReal) Giro.Z);
}

void GD_FisicasOdeCuerpo::RetornarPuntoDePosicionRelativa(dReal px, dReal py, dReal pz,
                                     dVector3 result)
{
    dBodyGetRelPointPos(Body, px, py, pz,result);
}

vector3df GD_FisicasOdeCuerpo::RetornarPuntoDePosicionRelativa(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    RetornarPuntoDePosicionRelativa(px,py,pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;
}

void GD_FisicasOdeCuerpo::RetornarPuntoDeVelocidadRelativa(dReal px, dReal py, dReal pz,
                                                    dVector3 result)
{
    dBodyGetRelPointVel(Body, px, py, pz,result);
}
vector3df GD_FisicasOdeCuerpo::RetornarPuntoDeVelocidadRelativa(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    RetornarPuntoDeVelocidadRelativa(px,py,pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;
}
void GD_FisicasOdeCuerpo::RetornarPuntoDeVelocidad(dReal px, dReal py, dReal pz,
                                            dVector3 result)
{
    dBodyGetPointVel(Body,px, py, pz,result);
}
vector3df GD_FisicasOdeCuerpo::RetornarPuntoDeVelocidad(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    RetornarPuntoDeVelocidad(px, py, pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;

}
void GD_FisicasOdeCuerpo::RetornarPosicionRelativaAlPunto(dReal px, dReal py, dReal pz,
                                                    dVector3 result)
{
    dBodyGetPosRelPoint(Body,px, py, pz,result);
}
vector3df GD_FisicasOdeCuerpo::RetornarPosicionRelativaAlPunto(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    RetornarPosicionRelativaAlPunto(px, py, pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;
}


void GD_FisicasOdeCuerpo::Vector_A_Mundo(dReal px, dReal py, dReal pz,
                                 dVector3 result)
{
    dBodyVectorToWorld(Body, px, py, pz,result);
}
vector3df GD_FisicasOdeCuerpo::Vector_A_Mundo(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    Vector_A_Mundo(px, py, pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;
}

void GD_FisicasOdeCuerpo::Vector_De_Mundo(dReal px, dReal py, dReal pz,
                                    dVector3 result)
{
    dBodyVectorFromWorld(Body, px, py, pz, result);
}
vector3df GD_FisicasOdeCuerpo::Vector_De_Mundo(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    Vector_De_Mundo(px, py, pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;
}


void GD_FisicasOdeCuerpo::Activar()
{
    dBodyEnable(Body);
}
void GD_FisicasOdeCuerpo::Desactivar()
{
    dBodyDisable(Body);
}
bool GD_FisicasOdeCuerpo::Activo()
{
    return (bool)dBodyIsEnabled(Body);
}


void GD_FisicasOdeCuerpo::ModoAutodesactivar(bool bDeshabilitable)
{
    dBodySetAutoDisableFlag(Body, (int) bDeshabilitable);
}
bool GD_FisicasOdeCuerpo::ValorModoAutodesactivar()
{
    return (bool)dBodyGetAutoDisableFlag(Body);
}
void GD_FisicasOdeCuerpo::Autodesactivacion_por_UmbralLinear(dReal UmbralLinear)
{
    dBodySetAutoDisableLinearThreshold(Body, UmbralLinear);
}
dReal GD_FisicasOdeCuerpo::ValorAutodesactivacion_por_UmbralLinear()
{
    return dBodyGetAutoDisableLinearThreshold(Body);
}
void GD_FisicasOdeCuerpo::AutoDesactivacion_por_UmbralAngular(dReal UmbralAngular)
{
    dBodySetAutoDisableAngularThreshold(Body, UmbralAngular);
}
dReal GD_FisicasOdeCuerpo::ValorAutoDesactivacion_por_UmbralAngular()
{
    return dBodyGetAutoDisableAngularThreshold(Body);
}
void GD_FisicasOdeCuerpo::AutoDesactivacion_por_Iteraciones(int Iteraciones)
{
    dBodySetAutoDisableSteps (Body,Iteraciones);
}
int GD_FisicasOdeCuerpo::ValorAutoDesactivacion_por_Iteraciones()
{
    return dBodyGetAutoDisableSteps(Body);
}
void GD_FisicasOdeCuerpo::AutoDesactivacion_por_Tiempo(dReal Tiempo)
{
    dBodySetAutoDisableTime(Body, Tiempo);
}
dReal GD_FisicasOdeCuerpo::ValorAutoDesactivacion_por_Tiempo()
{
    return dBodyGetAutoDisableTime(Body);
}
void GD_FisicasOdeCuerpo::AutoDesactivacion_por_Default()
{
    dBodySetAutoDisableDefaults(Body);
}

void GD_FisicasOdeCuerpo::SetData(void *data)
{
    dBodySetData(Body, data);
}
void* GD_FisicasOdeCuerpo::GetData()
{
    return (void*) dBodyGetData(Body);
}

void GD_FisicasOdeCuerpo::ModoDeRotacionFinita(bool activo)
{
    dBodySetFiniteRotationMode(Body, (int) activo);
}
bool GD_FisicasOdeCuerpo::RotacionFinitaActivada()
{
    return dBodyGetFiniteRotationMode(Body);
}
void GD_FisicasOdeCuerpo::EjeDeRotacionFinita(dReal x, dReal y, dReal z)
{
    dBodySetFiniteRotationAxis(Body,x, y, z);
}
void GD_FisicasOdeCuerpo::EjeDeRotacionFinita(vector3df ejes)
{
    EjeDeRotacionFinita((dReal) ejes.X, (dReal) ejes.Y, (dReal) ejes.Z);
}

int GD_FisicasOdeCuerpo::Articulaciones()
{
    return dBodyGetNumJoints(Body);
}
dJointID GD_FisicasOdeCuerpo::SelecArticulacion(int index)
{
    return dBodyGetJoint(Body, index);
}

void GD_FisicasOdeCuerpo::ActivarGravedad(bool activo)
{
    dBodySetGravityMode(Body, (int) activo);
}
bool GD_FisicasOdeCuerpo::GravedadActiva()
{
    return (bool) dBodyGetGravityMode(Body);
}

/* ///Funciones escritas en la documentacion de ODG pero que no son operativas
void GD_FisicasOdeCuerpo::UmbralDeAutoDesactivacion_ModoSF1(dReal umbral)
{
    dBodySetAutoDisableThresholdSF1(Body, umbral);
}
dReal GD_FisicasOdeCuerpo::ValorUmbralDeAutoDesactivacion_ModoSF1()
{
    return dBodyGetAutoDisableThresholdSF1(Body);
}

{
    dBodySetAutoDisableStepsSF1(Body, Iteraciones);
}
int GD_FisicasOdeCuerpo::ValorAutoDesactivacion_por_Iteraciones_ModoSF1()
{
    return dBodyGetAutoDisableStepsSF1(Body);
}

void GD_FisicasOdeCuerpo::ModoSF1_AutoDesactivacion(bool activo)
{
    dBodySetAutoDisableSF1(Body, (int) activo);
}
bool GD_FisicasOdeCuerpo::ValorModoSF1_AutoDesactivacion()
{
    return (bool)dBodyGetAutoDisableSF1(Body);
}
*/

#endif //_GDT_FISICAS_ODE_
