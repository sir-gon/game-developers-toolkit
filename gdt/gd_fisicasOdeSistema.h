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

namespace GDT
{

namespace fisica
{

void QuaternionToEuler(const dQuaternion quaternion,irr::core::vector3df &euler);
void EulerToQuaternion(const irr::core::vector3df &euler, dQuaternion quaternion);

vector3df RealAVector3d(const dReal* Val);
dReal* Vector3dAReal(const vector3df Val);

//! Soporte de F&iacute;sicas Open Dynamics Engine (ODE)
class Mundo
{
    public:
    //variables
    dWorldID        MundoODE;
    dSpaceID        Espacio;
    dJointGroupID   GrupoDeArticulaciones;


    //funciones
    //! Crea autom&aacute;ticamente un Mundo predeterminado para la instancia.
    _GDT_EXPORT_ Mundo();
    //! Crea un Mundo y retorna su ID.
    _GDT_EXPORT_ dWorldID CrearMundoODE();
    //! Destruye el Mundo actual
    _GDT_EXPORT_ void DestruirMundoODE();
    //! Establece la gravedad del mundo en cada coordenada.
    _GDT_EXPORT_ vector3df Gravedad(dReal x, dReal y, dReal z);
    //! Establece la gravedad del mundo en cada coordenada usando un vector.
    _GDT_EXPORT_ vector3df Gravedad(vector3df grav);
    //! Obtiene un vector con la gravedad en cada eje.
    _GDT_EXPORT_ vector3df Gravedad();

    //! Establece el valor del Par&aacute;metro de Reducci&oacute;n de Errores (ERP)
    _GDT_EXPORT_ void AsignarERP(dReal erp);
    //! Obtiene el valor del Par&aacute;metro de Reducci&oacute;n de Errores (ERP)
    _GDT_EXPORT_ dReal ObtenerERP();
    //! Establece el Constraint Force Mixing (CFM)
    _GDT_EXPORT_ void AsignarCFM(dReal cfm);
    //! Obtiene el Constraint Force Mixing (CFM)
    _GDT_EXPORT_ dReal ObtenerCFM();


    //AUTODESACTIVAR CUERPOS GLOBALMENTE
    //! Auto-desactiva globalmente los cuerpos que han estado quietos mucho tiempo.
    _GDT_EXPORT_ void ModoAutodesactivar(bool bDeshabilitable);
    //! Comprueba si esta permitido autodesactivar los cuerpos.
    _GDT_EXPORT_ bool ValorModoAutodesactivar();
    //! Auto-desactiva globalmente los cuerpos con menor velocidad lineal a la establecida.
    _GDT_EXPORT_ void Autodesactivacion_por_UmbralLinear(dReal UmbralLinear);
    //! Obtiene la velocidad lineal m&iacute;nima a la que se auto-desactivan los Cuerpos.
    _GDT_EXPORT_ dReal ValorAutodesactivacion_por_UmbralLinear();
    //! Auto-desactiva globalmente los cuerpos con menor velocidad angular a la establecida.
    _GDT_EXPORT_ void AutoDesactivacion_por_UmbralAngular(dReal UmbralAngular);
    //! Obtiene la velocidad angular m&iacute;nima a la que se auto-desactivan los Cuerpos.
    _GDT_EXPORT_ dReal ValorAutoDesactivacion_por_UmbralAngular();
    //! Auto-desactiva globalmente los cuerpos que pasen quietos por m&aacute;s del n&uacute;mero de Iteraciones (pasos o Steps) establecido.
    _GDT_EXPORT_ void AutoDesactivacion_por_Iteraciones(int Iteraciones);
    //! Obtiene la cantidad de pasos en que se auto-desactivan los Cuerpos.
    _GDT_EXPORT_ int ValorAutoDesactivacion_por_Iteraciones();
    //! Auto-desactiva globalmente los cuerpos que pasen quietos por m&aacute;s del n&uacute;mero del tiempo establecido.
    _GDT_EXPORT_ void AutoDesactivacion_por_Tiempo(dReal Tiempo);
    //! Obtiene la cantidad de tiempo en que se auto-desactivan los Cuerpos.
    _GDT_EXPORT_ dReal ValorAutoDesactivacion_por_Tiempo();

    //!
    _GDT_EXPORT_ vector3df Impulso_a_Fuerza(dReal Incremento,vector3df Impulso);
    //! Libera la memoria ocupada por ODE que no puede limpiarse con otras funciones
    _GDT_EXPORT_ void CerrarODE();

    //! Realiza un paso de la simulaci&oacute;n
    _GDT_EXPORT_ void Actualizar(dReal VelIteracion);
    //! Realiza r&aacute;pidamente un paso de la simulaci&oacute;n
    _GDT_EXPORT_ void Actualzar_Modo_QS(dReal VelIteracion);
    //! Alias de Actualzar_Modo_QS()
    _GDT_EXPORT_ void Actualizar_Rapido(dReal VelIteracion);
    //! Establece la cantidad de iteraciones que se har&aacute;n en Actualizar_Rapido()
    _GDT_EXPORT_ void NumIteraciones_modo_QS(int Iteraciones);
    //! Alias de NumIteraciones_modo_QS()
    _GDT_EXPORT_ void NumIteraciones_Rapidas(int Iteraciones);
    //! Obtiene la cantidad de iteraciones que se har&aacute;n en Actualizar_Rapido()
    _GDT_EXPORT_ int ValorNumIteraciones_modo_QS();
    //! Alias de ValorNumIteraciones_modo_QS()
    _GDT_EXPORT_ int ValorNumIteraciones_Rapidas();

    //!
    _GDT_EXPORT_ void VelocidadMaximaDeCorreccion_por_Contacto(dReal vel);
    _GDT_EXPORT_ dReal ValorVelocidadMaximaDeCorreccion_por_Contacto();

    _GDT_EXPORT_ void SuperficieDeContacto(dReal Profundidad);
    _GDT_EXPORT_ dReal ValorSuperficieDeContacto();

    _GDT_EXPORT_ void Actualizar_Modo_SF1(dReal VelIteracion, int MaxIteraciones);

    _GDT_EXPORT_ void ProfundidadDeAutoactivacionSF1(int ProfundidadDeAutoactivacion);
    _GDT_EXPORT_ int ValorProfundidadDeAutoactivacionSF1();
};

} // FIN NAMESPACE FISICAS

} // FIN NAMESPACE GDT

#endif //GD_FISICASODESISTEMA_H

#endif //_GDT_FISICAS_ODE_
