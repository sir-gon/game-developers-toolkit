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

#ifndef GD_FISICASODECUERPO_H
#define GD_FISICASODECUERPO_H

#include <irrlicht.h>
#include <ode.h>
#include "gd_sistema.h"

class GD_CuerpODE
{
    public:

    //variables
    dWorldID        Mundo;
    dBodyID         Body;
    dGeomID         Geom;
    dSpaceID        Espacio;
    dJointID        Articulacion;
    dJointGroupID   GrupoDeArticulacion;
    dMass*           Masa;

    //Funciones
    dBodyID Crear(dWorldID MundoODE);
    void Destruir();

    vector3df Posicion();
    vector3df Rotacion();
    vector3df ValorQuaternion();
    vector3df ValorVelocidadLinear();
    vector3df ValorVelocidadAngular();

    void Posicionar(dReal X, dReal Y, dReal Z);
    void Posicionar(vector3df Pos);
    void PosicionarX(dReal X);
    void PosicionarY(dReal Y);
    void PosicionarZ(dReal Z);

    void Rotar(const dMatrix3 R);
    void Quaternion(const dQuaternion q);

    void VelocidadLinear(dReal x, dReal y, dReal z);
    void VelocidadLinear(vector3df VelLinear);

    void VelocidadAngular(dReal x, dReal y, dReal z);
    void VelocidadAngular(vector3df VelAngular);

    void AsignarMasa(const dMass *mass);
    dMass* ValorMasa();

    void AniadirFuerza(dReal X, dReal Y, dReal Z);
    void AniadirFuerza(vector3df Fuerza);
    void AniadirGiro(dReal X, dReal Y, dReal Z);
    void AniadirGiro(vector3df Giro);
    void AniadirFuerzaRelativa(dReal X, dReal Y, dReal Z);
    void AniadirFuerzaRelativa(vector3df Fuerza);
    void AniadirGiroRelativo(dReal X, dReal Y, dReal Z);
    void AniadirGiroRelativo(vector3df Giro);
    void AniadirFuerzaDesdePosicion(dReal cX, dReal cY, dReal cZ,
                                    dReal pX, dReal pY, dReal pZ);
    void AniadirFuerzaDesdePosicion(vector3df Fuerza,vector3df Posicion);
    void AniadirFuerzaDesdePosicionRelativa(dReal cX, dReal cY, dReal cZ,
                                            dReal pX, dReal pY, dReal pZ);
    void AniadirFuerzaDesdePosicionRelativa(vector3df Fuerza,vector3df Posicion);
    void AniadirFuerzaRelativaDesdePosicion(dReal cX, dReal cY, dReal cZ,
                                            dReal pX, dReal pY, dReal pZ);
    void AniadirFuerzaRelativaDesdePosicion(vector3df Fuerza,vector3df Posicion);
    void AniadirFuerzaRelativaDesdePosicionRelativa(dReal cX, dReal cY, dReal cZ,
                                                    dReal pX, dReal pY, dReal pZ);
    void AniadirFuerzaRelativaDesdePosicionRelativa(vector3df Fuerza,vector3df Posicion);

    const dReal* RetornarFuerza();
    const dReal* RetornarGiro();

    void AsignarFuerza(dReal X, dReal Y, dReal Z);
    void AsignarFuerza(vector3df Fuerza);
    void AsignarGiro(dReal X, dReal Y, dReal Z);
    void AsignarGiro(vector3df Giro);

    void RetornarPuntoDePosicionRelativa(dReal px, dReal py, dReal pz,
                                         dVector3 result);
    vector3df RetornarPuntoDePosicionRelativa(dReal px, dReal py, dReal pz);

    void RetornarPuntoDeVelocidadRelativa(dReal px, dReal py, dReal pz,
                                            dVector3 result);
    vector3df RetornarPuntoDeVelocidadRelativa(dReal px, dReal py, dReal pz);
    void RetornarPuntoDeVelocidad(dReal px, dReal py, dReal pz,
                                    dVector3 result);
    vector3df RetornarPuntoDeVelocidad(dReal px, dReal py, dReal pz);
    void RetornarPosicionRelativaAlPunto(dReal px, dReal py, dReal pz,
                                         dVector3 result);
    vector3df RetornarPosicionRelativaAlPunto(dReal px, dReal py, dReal pz);

    void Vector_A_Mundo(dReal px, dReal py, dReal pz,
                        dVector3 result);
    vector3df Vector_A_Mundo(dReal px, dReal py, dReal pz);
    void Vector_De_Mundo(dReal px, dReal py, dReal pz,
                           dVector3 result);
    vector3df Vector_De_Mundo(dReal px, dReal py, dReal pz);

    void Activar();
    void Desactivar();
    bool Activo();

    void ModoAutodesactivar(bool bDeshabilitable);
    bool ValorModoAutodesactivar();
    void Autodesactivacion_por_UmbralLinear(dReal UmbralLinear);
    dReal ValorAutodesactivacion_por_UmbralLinear();
    void AutoDesactivacion_por_UmbralAngular(dReal UmbralAngular);
    dReal ValorAutoDesactivacion_por_UmbralAngular();
    void AutoDesactivacion_por_Iteraciones(int Iteraciones);
    int ValorAutoDesactivacion_por_Iteraciones();
    void AutoDesactivacion_por_Tiempo(dReal Tiempo);
    dReal ValorAutoDesactivacion_por_Tiempo();
    void AutoDesactivacion_por_Default();

    void SetData(void *data);
    void* GetData();

    void ModoDeRotacionFinita(bool activo);
    bool RotacionFinitaActivada();
    void EjeDeRotacionFinita(dReal x, dReal y, dReal z);
    void EjeDeRotacionFinita(vector3df ejes);

    int Articulaciones();
    dJointID SelecArticulacion(int index);

    void ActivarGravedad(bool activo);
    bool GravedadActiva();

    /* ///Funciones escritas en la documentacion de ODG pero que no son operativas
    void UmbralDeAutoDesactivacion_ModoSF1(dReal umbral);
    dReal ValorUmbralDeAutoDesactivacion_ModoSF1();

    void AutoDesactivacion_por_Iteraciones_ModoSF1(int Iteraciones);
    int ValorAutoDesactivacion_por_Iteraciones_ModoSF1();

    void ModoSF1_AutoDesactivacion(bool activo);
    bool ValorModoSF1_AutoDesactivacion();*/

};

#endif //GD_FISICASODECUERPO_H

#endif //_GDT_FISICAS_ODE_
