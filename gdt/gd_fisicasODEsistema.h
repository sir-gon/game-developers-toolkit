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

#ifndef GD_FISICASODESISTEMA_H
#define GD_FISICASODESISTEMA_H

#include <irrlicht.h>
#include <ode.h>
#include "gd_sistema.h"

/* No documentar */
#ifndef _GDT_DOXYGEN_IGNORAR_
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
#endif /* _GDT_DOXYGEN_IGNORAR_ */

void QuaternionToEuler(const dQuaternion quaternion,irr::core::vector3df &euler);
void EulerToQuaternion(const irr::core::vector3df &euler, dQuaternion quaternion);

vector3df RealAVector3d(const dReal* Val);
dReal* Vector3dAReal(const vector3df Val);


class GD_SistemaODE
{
    public:
    //variables
    dWorldID        MundoODE;
    dSpaceID        Espacio;
    dJointGroupID   GrupoDeArticulaciones;


    //funciones
    GD_SistemaODE();

    dWorldID CrearMundoODE();
    void DestruirMundoODE();

    vector3df Gravedad(dReal x, dReal y, dReal z);
    vector3df Gravedad(vector3df grav);
    vector3df Gravedad();

    void AsignarERP(dReal erp);
    dReal ObtenerERP();
    void AsignarCFM(dReal cfm);
    dReal ObtenerCFM();

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

    vector3df Impulso_a_Fuerza(dReal Incremento,vector3df Impulso);
    void CerrarODE(){dCloseODE();};

    void Actualizar(dReal VelIteracion);
    void Actualzar_Modo_QS(dReal VelIteracion);
    void NumIteraciones_modo_QS(int Iteraciones);
    int ValorNumIteraciones_modo_QS();

    void VelocidadMaximaDeCorreccion_por_Contacto(dReal vel);
    dReal ValorVelocidadMaximaDeCorreccion_por_Contacto();

    void SuperficieDeContacto(dReal Profundidad);
    dReal ValorSuperficieDeContacto();

    void Actualizar_Modo_SF1(dReal VelIteracion, int MaxIteraciones);

    void ProfundidadDeAutoactivacionSF1(int ProfundidadDeAutoactivacion);
    int ValorProfundidadDeAutoactivacionSF1();
};

#endif //GD_FISICASODESISTEMA_H

#endif //_GDT_FISICAS_ODE_
