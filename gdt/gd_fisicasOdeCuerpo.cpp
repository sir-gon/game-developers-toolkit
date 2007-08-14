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
* \class GDT::fisica::Cuerpo
*
* Crea y maneja un Cuerpo R�ido, el cual puede interactuar con un Mundo
* y con otros Cuerpos que esten presentes en el mismo Mundo.
*
* \warning Esta caracter&iacute;stica esta disponible cuando _GDT_FISICAS_ODE_ est&aacute; definido en tiempo de compilaci&oacute;n.
*
* \author Astucia
*/

#include "gd_fisicasOdeCuerpo.h"
#include "gd_fisicasOdeSistema.h"

dBodyID GDT::fisica::Cuerpo::Crear(dWorldID MundoODE)
{
    return Body=dBodyCreate(MundoODE);
}
void GDT::fisica::Cuerpo::Destruir()
{
    dBodyDestroy(Body);
}

vector3df GDT::fisica::Cuerpo::Posicion()
{
    return RealAVector3d(dBodyGetPosition(Body));
}
vector3df GDT::fisica::Cuerpo::Rotacion()
{
    return RealAVector3d(dBodyGetRotation(Body));
}
vector3df GDT::fisica::Cuerpo::ValorQuaternion()
{
    return RealAVector3d(dBodyGetQuaternion(Body));
}
vector3df GDT::fisica::Cuerpo::ValorVelocidadLinear()
{
    return RealAVector3d(dBodyGetLinearVel(Body));
}
vector3df GDT::fisica::Cuerpo::ValorVelocidadAngular()
{
    return RealAVector3d(dBodyGetAngularVel(Body));
}

void GDT::fisica::Cuerpo::Posicionar(dReal X, dReal Y, dReal Z)
{
    dBodySetPosition(Body, X, Y, Z);
}
void GDT::fisica::Cuerpo::Posicionar(vector3df Pos)
{
    Posicionar((dReal) Pos.X, (dReal) Pos.Y, (dReal) Pos.Z);
}
void GDT::fisica::Cuerpo::PosicionarX(dReal X)
{
    vector3df PosA;

    PosA=Posicion();
    PosA.X=X;
    Posicionar(PosA);
}
void GDT::fisica::Cuerpo::PosicionarY(dReal Y)
{
    vector3df PosA;

    PosA=Posicion();
    PosA.Y=Y;
    Posicionar(PosA);
}
void GDT::fisica::Cuerpo::PosicionarZ(dReal Z)
{
    vector3df PosA;

    PosA=Posicion();
    PosA.Z=Z;
    Posicionar(PosA);

}

void GDT::fisica::Cuerpo::Rotar(const dMatrix3 R)
{
    dBodySetRotation(Body,R);
}
void GDT::fisica::Cuerpo::Quaternion(const dQuaternion q)
{
    dBodySetQuaternion(Body,q);
}

void GDT::fisica::Cuerpo::VelocidadLinear(dReal x, dReal y, dReal z)
{
    dBodySetLinearVel(Body,x,y,z);
}
void GDT::fisica::Cuerpo::VelocidadLinear(vector3df VelLinear)
{
    VelocidadLinear((dReal) VelLinear.X, (dReal) VelLinear.Y, (dReal) VelLinear.Z);
}

void GDT::fisica::Cuerpo::VelocidadAngular(dReal x, dReal y, dReal z)
{
    dBodySetAngularVel(Body,x,y,z);
}
void GDT::fisica::Cuerpo::VelocidadAngular(vector3df VelAngular)
{
    VelocidadAngular((dReal) VelAngular.X, (dReal) VelAngular.Y, (dReal) VelAngular.Z);
}

void GDT::fisica::Cuerpo::AsignarMasa(const dMass *mass)
{
    dBodySetMass(Body, mass);
    //dBodyGetMass(Body, Masa);
}
dMass* GDT::fisica::Cuerpo::ValorMasa()
{
    dBodyGetMass(Body, Masa);
    return Masa;
}

void GDT::fisica::Cuerpo::AniadirFuerza(dReal X, dReal Y, dReal Z)
{
    dBodyAddForce(Body, X, Y, Z);
}

void GDT::fisica::Cuerpo::AniadirFuerza(vector3df Fuerza)
{
    AniadirFuerza((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z);
}

void GDT::fisica::Cuerpo::AniadirGiro(dReal X, dReal Y, dReal Z)
{
    dBodyAddTorque(Body, X, Y, Z);
}

void GDT::fisica::Cuerpo::AniadirGiro(vector3df Giro)
{
    AniadirGiro((dReal) Giro.X, (dReal) Giro.Y, (dReal) Giro.Z);
}

void GDT::fisica::Cuerpo::AniadirFuerzaRelativa(dReal X, dReal Y, dReal Z)
{
    dBodyAddRelForce(Body, X, Y, Z);
}

void GDT::fisica::Cuerpo::AniadirFuerzaRelativa(vector3df Fuerza)
{
    AniadirFuerzaRelativa((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z);
}

void GDT::fisica::Cuerpo::AniadirGiroRelativo(dReal X, dReal Y, dReal Z)
{
    dBodyAddRelTorque(Body, X, Y, Z);
}

void GDT::fisica::Cuerpo::AniadirGiroRelativo(vector3df Giro)
{
    AniadirGiroRelativo((dReal) Giro.X, (dReal) Giro.Y, (dReal) Giro.Z);
}

void GDT::fisica::Cuerpo::AniadirFuerzaDesdePosicion(dReal cX, dReal cY, dReal cZ,
                                             dReal pX, dReal pY, dReal pZ)
{
    dBodyAddForceAtPos(Body, cX, cY, cZ, pX, pY, pZ);
}

void GDT::fisica::Cuerpo::AniadirFuerzaDesdePosicion(vector3df Fuerza,vector3df Posicion)
{
    AniadirFuerzaDesdePosicion((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z,
                               (dReal) Posicion.X, (dReal) Posicion.Y, (dReal) Posicion.Z);
}
void GDT::fisica::Cuerpo::AniadirFuerzaDesdePosicionRelativa(dReal cX, dReal cY, dReal cZ,
                                                     dReal pX, dReal pY, dReal pZ)
{
    dBodyAddForceAtRelPos(Body, cX, cY, cZ, pX, pY, pZ);
}

void GDT::fisica::Cuerpo::AniadirFuerzaDesdePosicionRelativa(vector3df Fuerza,vector3df Posicion)
{
    AniadirFuerzaDesdePosicionRelativa((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z,
                                        (dReal) Posicion.X, (dReal) Posicion.Y, (dReal) Posicion.Z);
}
void GDT::fisica::Cuerpo::AniadirFuerzaRelativaDesdePosicion(dReal cX, dReal cY, dReal cZ,
                                                     dReal pX, dReal pY, dReal pZ)
{
    dBodyAddRelForceAtPos(Body, cX, cY, cZ, pX, pY, pZ);
}
void GDT::fisica::Cuerpo::AniadirFuerzaRelativaDesdePosicion(vector3df Fuerza,vector3df Posicion)
{
    AniadirFuerzaRelativaDesdePosicion((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z,
                                        (dReal) Posicion.X, (dReal) Posicion.Y, (dReal) Posicion.Z);
}
void GDT::fisica::Cuerpo::AniadirFuerzaRelativaDesdePosicionRelativa(dReal cX, dReal cY, dReal cZ,
                                                             dReal pX, dReal pY, dReal pZ)
{
    dBodyAddRelForceAtRelPos(Body, cX, cY, cZ, pX, pY, pZ);
}
void GDT::fisica::Cuerpo::AniadirFuerzaRelativaDesdePosicionRelativa(vector3df Fuerza,vector3df Posicion)
{
    AniadirFuerzaRelativaDesdePosicionRelativa((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z,
                                                (dReal) Posicion.X, (dReal) Posicion.Y, (dReal) Posicion.Z);
}
const dReal* GDT::fisica::Cuerpo::RetornarFuerza()
{
    return dBodyGetForce(Body);
}

const dReal* GDT::fisica::Cuerpo::RetornarGiro()
{
    return dBodyGetTorque(Body);
}

void GDT::fisica::Cuerpo::AsignarFuerza(dReal X, dReal Y, dReal Z)
{
    dBodySetForce(Body, X, Y, Z);
}

void GDT::fisica::Cuerpo::AsignarFuerza(vector3df Fuerza)
{
    AsignarFuerza((dReal) Fuerza.X, (dReal) Fuerza.Y, (dReal) Fuerza.Z);
}
void GDT::fisica::Cuerpo::AsignarGiro(dReal X, dReal Y, dReal Z)
{
    dBodySetTorque(Body, X, Y, Z);
}
void GDT::fisica::Cuerpo::AsignarGiro(vector3df Giro)
{
    AsignarGiro((dReal) Giro.X, (dReal) Giro.Y, (dReal) Giro.Z);
}

void GDT::fisica::Cuerpo::RetornarPuntoDePosicionRelativa(dReal px, dReal py, dReal pz,
                                     dVector3 result)
{
    dBodyGetRelPointPos(Body, px, py, pz,result);
}

vector3df GDT::fisica::Cuerpo::RetornarPuntoDePosicionRelativa(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    RetornarPuntoDePosicionRelativa(px,py,pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;
}

void GDT::fisica::Cuerpo::RetornarPuntoDeVelocidadRelativa(dReal px, dReal py, dReal pz,
                                                    dVector3 result)
{
    dBodyGetRelPointVel(Body, px, py, pz,result);
}
vector3df GDT::fisica::Cuerpo::RetornarPuntoDeVelocidadRelativa(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    RetornarPuntoDeVelocidadRelativa(px,py,pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;
}
void GDT::fisica::Cuerpo::RetornarPuntoDeVelocidad(dReal px, dReal py, dReal pz,
                                            dVector3 result)
{
    dBodyGetPointVel(Body,px, py, pz,result);
}
vector3df GDT::fisica::Cuerpo::RetornarPuntoDeVelocidad(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    RetornarPuntoDeVelocidad(px, py, pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;

}
void GDT::fisica::Cuerpo::RetornarPosicionRelativaAlPunto(dReal px, dReal py, dReal pz,
                                                    dVector3 result)
{
    dBodyGetPosRelPoint(Body,px, py, pz,result);
}
vector3df GDT::fisica::Cuerpo::RetornarPosicionRelativaAlPunto(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    RetornarPosicionRelativaAlPunto(px, py, pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;
}


void GDT::fisica::Cuerpo::Vector_A_Mundo(dReal px, dReal py, dReal pz,
                                 dVector3 result)
{
    dBodyVectorToWorld(Body, px, py, pz,result);
}
vector3df GDT::fisica::Cuerpo::Vector_A_Mundo(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    Vector_A_Mundo(px, py, pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;
}

void GDT::fisica::Cuerpo::Vector_De_Mundo(dReal px, dReal py, dReal pz,
                                    dVector3 result)
{
    dBodyVectorFromWorld(Body, px, py, pz, result);
}
vector3df GDT::fisica::Cuerpo::Vector_De_Mundo(dReal px, dReal py, dReal pz)
{
    dVector3 result;
    vector3df resultado;
    Vector_De_Mundo(px, py, pz,result);
    resultado.X=result[0];
    resultado.Y=result[1];
    resultado.Z=result[2];
    return resultado;
}


void GDT::fisica::Cuerpo::Activar()
{
    dBodyEnable(Body);
}
void GDT::fisica::Cuerpo::Desactivar()
{
    dBodyDisable(Body);
}
bool GDT::fisica::Cuerpo::Activo()
{
    //return (bool)dBodyIsEnabled(Body);
	if(dBodyIsEnabled(Body) == 0)
		return false;
	else {
		return true;
	}
}


void GDT::fisica::Cuerpo::ModoAutodesactivar(bool bDeshabilitable)
{
    dBodySetAutoDisableFlag(Body, (int) bDeshabilitable);
}
bool GDT::fisica::Cuerpo::ValorModoAutodesactivar()
{
    //return (bool)dBodyGetAutoDisableFlag(Body);
		if(dBodyGetAutoDisableFlag(Body) == 0) {
		return false;
	} else {
		return true;
	}
}
void GDT::fisica::Cuerpo::Autodesactivacion_por_UmbralLinear(dReal UmbralLinear)
{
    dBodySetAutoDisableLinearThreshold(Body, UmbralLinear);
}
dReal GDT::fisica::Cuerpo::ValorAutodesactivacion_por_UmbralLinear()
{
    return dBodyGetAutoDisableLinearThreshold(Body);
}
void GDT::fisica::Cuerpo::AutoDesactivacion_por_UmbralAngular(dReal UmbralAngular)
{
    dBodySetAutoDisableAngularThreshold(Body, UmbralAngular);
}
dReal GDT::fisica::Cuerpo::ValorAutoDesactivacion_por_UmbralAngular()
{
    return dBodyGetAutoDisableAngularThreshold(Body);
}
void GDT::fisica::Cuerpo::AutoDesactivacion_por_Iteraciones(int Iteraciones)
{
    dBodySetAutoDisableSteps (Body,Iteraciones);
}
int GDT::fisica::Cuerpo::ValorAutoDesactivacion_por_Iteraciones()
{
    return dBodyGetAutoDisableSteps(Body);
}
void GDT::fisica::Cuerpo::AutoDesactivacion_por_Tiempo(dReal Tiempo)
{
    dBodySetAutoDisableTime(Body, Tiempo);
}
dReal GDT::fisica::Cuerpo::ValorAutoDesactivacion_por_Tiempo()
{
    return dBodyGetAutoDisableTime(Body);
}
void GDT::fisica::Cuerpo::AutoDesactivacion_por_Default()
{
    dBodySetAutoDisableDefaults(Body);
}

void GDT::fisica::Cuerpo::SetData(void *data)
{
    dBodySetData(Body, data);
}
void* GDT::fisica::Cuerpo::GetData()
{
    return (void*) dBodyGetData(Body);
}

void GDT::fisica::Cuerpo::ModoDeRotacionFinita(bool activo)
{
    dBodySetFiniteRotationMode(Body, (int) activo);
}
bool GDT::fisica::Cuerpo::RotacionFinitaActivada()
{
	//return dBodyGetFiniteRotationMode(Body);
	if(!dBodyGetFiniteRotationMode(Body))
		return false;
	else
		return true;
}
void GDT::fisica::Cuerpo::EjeDeRotacionFinita(dReal x, dReal y, dReal z)
{
    dBodySetFiniteRotationAxis(Body,x, y, z);
}
void GDT::fisica::Cuerpo::EjeDeRotacionFinita(vector3df ejes)
{
    EjeDeRotacionFinita((dReal) ejes.X, (dReal) ejes.Y, (dReal) ejes.Z);
}

int GDT::fisica::Cuerpo::Articulaciones()
{
    return dBodyGetNumJoints(Body);
}
dJointID GDT::fisica::Cuerpo::SelecArticulacion(int index)
{
    return dBodyGetJoint(Body, index);
}

void GDT::fisica::Cuerpo::ActivarGravedad(bool activo)
{
    dBodySetGravityMode(Body, (int) activo);
}
bool GDT::fisica::Cuerpo::GravedadActiva()
{
	// return (bool) dBodyGetGravityMode(Body);
    if(!dBodyGetGravityMode(Body))
		return false;
	else 
		return true;
	
}

/* ///Funciones escritas en la documentacion de ODG pero que no son operativas
void GDT::fisica::Cuerpo::UmbralDeAutoDesactivacion_ModoSF1(dReal umbral)
{
    dBodySetAutoDisableThresholdSF1(Body, umbral);
}
dReal GDT::fisica::Cuerpo::ValorUmbralDeAutoDesactivacion_ModoSF1()
{
    return dBodyGetAutoDisableThresholdSF1(Body);
}

{
    dBodySetAutoDisableStepsSF1(Body, Iteraciones);
}
int GDT::fisica::Cuerpo::ValorAutoDesactivacion_por_Iteraciones_ModoSF1()
{
    return dBodyGetAutoDisableStepsSF1(Body);
}

void GDT::fisica::Cuerpo::ModoSF1_AutoDesactivacion(bool activo)
{
    dBodySetAutoDisableSF1(Body, (int) activo);
}
bool GDT::fisica::Cuerpo::ValorModoSF1_AutoDesactivacion()
{
    return (bool)dBodyGetAutoDisableSF1(Body);
}
*/

#endif //_GDT_FISICAS_ODE_
