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

//! Crea un Cuerpo para f&iacute;sicas Open Dynamics Engine (ODE)
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
    _GDT_EXPORT_ void Destruir();

    _GDT_EXPORT_ vector3df Posicion();
    _GDT_EXPORT_ vector3df Rotacion();
    _GDT_EXPORT_ vector3df ValorQuaternion();
    _GDT_EXPORT_ vector3df ValorVelocidadLinear();
    _GDT_EXPORT_ vector3df ValorVelocidadAngular();

    _GDT_EXPORT_ void Posicionar(dReal X, dReal Y, dReal Z);
    _GDT_EXPORT_ void Posicionar(vector3df Pos);
    _GDT_EXPORT_ void PosicionarX(dReal X);
    _GDT_EXPORT_ void PosicionarY(dReal Y);
    _GDT_EXPORT_ void PosicionarZ(dReal Z);

    _GDT_EXPORT_ void Rotar(const dMatrix3 R);
    _GDT_EXPORT_ void Quaternion(const dQuaternion q);

    _GDT_EXPORT_ void VelocidadLinear(dReal x, dReal y, dReal z);
    _GDT_EXPORT_ void VelocidadLinear(vector3df VelLinear);

    _GDT_EXPORT_ void VelocidadAngular(dReal x, dReal y, dReal z);
    _GDT_EXPORT_ void VelocidadAngular(vector3df VelAngular);

    _GDT_EXPORT_ void AsignarMasa(const dMass *mass);
    _GDT_EXPORT_ dMass* ValorMasa();

    _GDT_EXPORT_ void AniadirFuerza(dReal X, dReal Y, dReal Z);
    _GDT_EXPORT_ void AniadirFuerza(vector3df Fuerza);
    _GDT_EXPORT_ void AniadirGiro(dReal X, dReal Y, dReal Z);
    _GDT_EXPORT_ void AniadirGiro(vector3df Giro);
    _GDT_EXPORT_ void AniadirFuerzaRelativa(dReal X, dReal Y, dReal Z);
    _GDT_EXPORT_ void AniadirFuerzaRelativa(vector3df Fuerza);
    _GDT_EXPORT_ void AniadirGiroRelativo(dReal X, dReal Y, dReal Z);
    _GDT_EXPORT_ void AniadirGiroRelativo(vector3df Giro);
    _GDT_EXPORT_ void AniadirFuerzaDesdePosicion(dReal cX, dReal cY, dReal cZ,
                                    dReal pX, dReal pY, dReal pZ);
    _GDT_EXPORT_ void AniadirFuerzaDesdePosicion(vector3df Fuerza,vector3df Posicion);
    _GDT_EXPORT_ void AniadirFuerzaDesdePosicionRelativa(dReal cX, dReal cY, dReal cZ,
                                            dReal pX, dReal pY, dReal pZ);
    _GDT_EXPORT_ void AniadirFuerzaDesdePosicionRelativa(vector3df Fuerza,vector3df Posicion);
    _GDT_EXPORT_ void AniadirFuerzaRelativaDesdePosicion(dReal cX, dReal cY, dReal cZ,
                                            dReal pX, dReal pY, dReal pZ);
    _GDT_EXPORT_ void AniadirFuerzaRelativaDesdePosicion(vector3df Fuerza,vector3df Posicion);
    _GDT_EXPORT_ void AniadirFuerzaRelativaDesdePosicionRelativa(dReal cX, dReal cY, dReal cZ,
                                                    dReal pX, dReal pY, dReal pZ);
    _GDT_EXPORT_ void AniadirFuerzaRelativaDesdePosicionRelativa(vector3df Fuerza,vector3df Posicion);

    _GDT_EXPORT_ const dReal* RetornarFuerza();
    _GDT_EXPORT_ const dReal* RetornarGiro();

    _GDT_EXPORT_ void AsignarFuerza(dReal X, dReal Y, dReal Z);
    _GDT_EXPORT_ void AsignarFuerza(vector3df Fuerza);
    _GDT_EXPORT_ void AsignarGiro(dReal X, dReal Y, dReal Z);
    _GDT_EXPORT_ void AsignarGiro(vector3df Giro);

    _GDT_EXPORT_ void RetornarPuntoDePosicionRelativa(dReal px, dReal py, dReal pz,
                                         dVector3 result);
    _GDT_EXPORT_ vector3df RetornarPuntoDePosicionRelativa(dReal px, dReal py, dReal pz);

    _GDT_EXPORT_ void RetornarPuntoDeVelocidadRelativa(dReal px, dReal py, dReal pz,
                                            dVector3 result);
    _GDT_EXPORT_ vector3df RetornarPuntoDeVelocidadRelativa(dReal px, dReal py, dReal pz);
    _GDT_EXPORT_ void RetornarPuntoDeVelocidad(dReal px, dReal py, dReal pz,
                                    dVector3 result);
    _GDT_EXPORT_ vector3df RetornarPuntoDeVelocidad(dReal px, dReal py, dReal pz);
    _GDT_EXPORT_ void RetornarPosicionRelativaAlPunto(dReal px, dReal py, dReal pz,
                                         dVector3 result);
    _GDT_EXPORT_ vector3df RetornarPosicionRelativaAlPunto(dReal px, dReal py, dReal pz);

    _GDT_EXPORT_ void Vector_A_Mundo(dReal px, dReal py, dReal pz,
                        dVector3 result);
    _GDT_EXPORT_ vector3df Vector_A_Mundo(dReal px, dReal py, dReal pz);
    _GDT_EXPORT_ void Vector_De_Mundo(dReal px, dReal py, dReal pz,
                           dVector3 result);
    _GDT_EXPORT_ vector3df Vector_De_Mundo(dReal px, dReal py, dReal pz);

    _GDT_EXPORT_ void Activar();
    _GDT_EXPORT_ void Desactivar();
    _GDT_EXPORT_ bool Activo();

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
    _GDT_EXPORT_ void AutoDesactivacion_por_Default();

    _GDT_EXPORT_ void SetData(void *data);
    _GDT_EXPORT_ void* GetData();

    _GDT_EXPORT_ void ModoDeRotacionFinita(bool activo);
    _GDT_EXPORT_ bool RotacionFinitaActivada();
    _GDT_EXPORT_ void EjeDeRotacionFinita(dReal x, dReal y, dReal z);
    _GDT_EXPORT_ void EjeDeRotacionFinita(vector3df ejes);

    _GDT_EXPORT_ int Articulaciones();
    _GDT_EXPORT_ dJointID SelecArticulacion(int index);

    _GDT_EXPORT_ void ActivarGravedad(bool activo);
    _GDT_EXPORT_ bool GravedadActiva();

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
