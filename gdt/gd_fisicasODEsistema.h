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

// HACK PARA EXPORTAR SIMBOLOS EN DLL COMPILADOS CON VISUAL C++ 2005
#ifndef _GDT_EXPORT_
  #ifdef _GDT_VC_STUDIO_2005_
   #define _GDT_EXPORT_ __declspec(dllexport)
  #else
    #define _GDT_EXPORT_
  #endif
#endif

void QuaternionToEuler(const dQuaternion quaternion,irr::core::vector3df &euler);
void EulerToQuaternion(const irr::core::vector3df &euler, dQuaternion quaternion);

vector3df RealAVector3d(const dReal* Val);
dReal* Vector3dAReal(const vector3df Val);

//! Soporte de F&iacute;sicas Open Dynamics Engine (ODE)
class GD_SistemaODE
{
    public:
    //variables
    dWorldID        MundoODE;
    dSpaceID        Espacio;
    dJointGroupID   GrupoDeArticulaciones;


    //funciones
    GD_SistemaODE();

    _GDT_EXPORT_ dWorldID CrearMundoODE();
    _GDT_EXPORT_ void DestruirMundoODE();

    _GDT_EXPORT_ vector3df Gravedad(dReal x, dReal y, dReal z);
    _GDT_EXPORT_ vector3df Gravedad(vector3df grav);
    _GDT_EXPORT_ vector3df Gravedad();

    _GDT_EXPORT_ void AsignarERP(dReal erp);
    _GDT_EXPORT_ dReal ObtenerERP();
    _GDT_EXPORT_ void AsignarCFM(dReal cfm);
    _GDT_EXPORT_ dReal ObtenerCFM();

    _GDT_EXPORT_ void ModoAutodesactivar(bool bDeshabilitable);
    _GDT_EXPORT_ bool ValorModoAutodesactivar();
    _GDT_EXPORT_ void Autodesactivacion_por_UmbralLinear(dReal UmbralLinear);
    _GDT_EXPORT_ dReal ValorAutodesactivacion_por_UmbralLinear();
    _GDT_EXPORT_ void AutoDesactivacion_por_UmbralAngular(dReal UmbralAngular);
    _GDT_EXPORT_ dReal ValorAutoDesactivacion_por_UmbralAngular();
    _GDT_EXPORT_ void AutoDesactivacion_por_Iteraciones(int Iteraciones);
    _GDT_EXPORT_ int ValorAutoDesactivacion_por_Iteraciones();
    _GDT_EXPORT_ void AutoDesactivacion_por_Tiempo(dReal Tiempo);
    _GDT_EXPORT_ dReal ValorAutoDesactivacion_por_Tiempo();

    _GDT_EXPORT_ vector3df Impulso_a_Fuerza(dReal Incremento,vector3df Impulso);
    _GDT_EXPORT_ void CerrarODE(){dCloseODE();};

    _GDT_EXPORT_ void Actualizar(dReal VelIteracion);
    _GDT_EXPORT_ void Actualzar_Modo_QS(dReal VelIteracion);
    _GDT_EXPORT_ void NumIteraciones_modo_QS(int Iteraciones);
    _GDT_EXPORT_ int ValorNumIteraciones_modo_QS();

    _GDT_EXPORT_ void VelocidadMaximaDeCorreccion_por_Contacto(dReal vel);
    _GDT_EXPORT_ dReal ValorVelocidadMaximaDeCorreccion_por_Contacto();

    _GDT_EXPORT_ void SuperficieDeContacto(dReal Profundidad);
    _GDT_EXPORT_ dReal ValorSuperficieDeContacto();

    _GDT_EXPORT_ void Actualizar_Modo_SF1(dReal VelIteracion, int MaxIteraciones);

    _GDT_EXPORT_ void ProfundidadDeAutoactivacionSF1(int ProfundidadDeAutoactivacion);
    _GDT_EXPORT_ int ValorProfundidadDeAutoactivacionSF1();
};

#endif //GD_FISICASODESISTEMA_H

#endif //_GDT_FISICAS_ODE_
