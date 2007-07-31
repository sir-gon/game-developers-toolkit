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
* \class GD_FisicasOdeSistema
*
* Crea y maneja un Mundo de F&iacute;sicas usando ODE.
* Todos los métodos afectan en forma global el comportamiento del Mundo.
* Si se crean 2 Mundos en 2 instancias separadas, los cuerpos que pertenezcan
* a mundos separados no interactuan, es decir, no les afectan las fuerzas del 
* otro mundo, ni 
*
* Para incrementar la velocidad de los c&aacute;lculos, los Cuerpos puedes ser
* autom&aacute;ticamente deshabilitados cuando cumplen ciertas condiciones.
* Los valores predeterminados para esta funcionalidad son:
*
* - AutoDisableFlag = disabled
* - AutoDisableLinearThreshold = 0.01
* - AutoDisableAngularThreshold = 0.01
* - AutoDisableSteps = 10
* - AutoDisableTime = 0
* 
* \warning Esta caracter&iacute;stica esta disponible cuando _GDT_FISICAS_ODE_
* est&aacute; definido en tiempo de compilaci&oacute;n.
*
* \author Astucia
*/

#include "gd_fisicasOdeSistema.h"

/*!
*/
GD_FisicasOdeSistema::GD_FisicasOdeSistema()
{
   MundoODE=CrearMundoODE();
}

/*!
* \note Este Mundo no sobreescribe el mundo definido por defecto 
* para la instancia, sino que crea otro Mundo aparte.
*/
dWorldID GD_FisicasOdeSistema::CrearMundoODE()
{
   return dWorldCreate();
}

/*!
* Para volver a crear un Mundo para la instancia,
* deber&aacute; llamar nuevamente al constructor GD_FisicasOdeSistema()
*/
void GD_FisicasOdeSistema::DestruirMundoODE()
{
   dWorldDestroy(MundoODE);
}

/*!
* Las unidades son: \f$ \frac{m}{s^2} \f$ (metro partido por (segundo al cuadrado))
*
* Ejemplo:
* \code
* Mundo.Gravedad(dReal x, dReal y, dReal z)
* \endcode
*/
vector3df GD_FisicasOdeSistema::Gravedad(dReal x, dReal y, dReal z)
{
   dWorldSetGravity(MundoODE,x, y, z);
   return Gravedad();
}

/*!
* Las unidades son: \f$ \frac{m}{s^2} \f$ (metro partido por (segundo al cuadrado))
*
* Ejemplo:
* \code
* 
* \endcode
*/

vector3df GD_FisicasOdeSistema::Gravedad(vector3df grav)
{
   Gravedad((dReal) grav.X, (dReal) grav.Y, (dReal) grav.Z);
   return Gravedad();
}

/*!
* \return Un vector con la gravedad del mundo en cada eje.
*
* Las unidades son: \f$ \frac{m}{s^2} \f$ (metro partido por (segundo al cuadrado))
*
* Ejemplo:
* \code
*
* \endcode
*/
vector3df GD_FisicasOdeSistema::Gravedad()
{
   vector3df gravI;
   dWorldGetGravity(MundoODE, (dReal*) &gravI);
   return gravI;
}

/*!
* (Error Reduction Parameter)
*
* Debe ser un valor entre 0 y 1
*
* Ejemplo:
* \code
* Mundo.AsignarERP(0.4);
* \endcode
*/
void GD_FisicasOdeSistema::AsignarERP(dReal erp)
{
   dWorldSetERP(MundoODE,erp);
}

/*!
* \return el valor del Par&aacute;metro de Reducci&oacute;n de Errores (ERP)
*/
dReal GD_FisicasOdeSistema::ObtenerERP()
{
   return dWorldGetERP(MundoODE);
}

/*!
* Valor usualmente entre \f$ 10^{-9} \f$ - 1
*/
void GD_FisicasOdeSistema::AsignarCFM(dReal cfm)
{
   dWorldSetCFM(MundoODE,cfm);
}

/*!
* Valor usualmente entre \f$ 10^{-9} \f$ - 1
*/
dReal GD_FisicasOdeSistema::ObtenerCFM()
{
   return dWorldGetCFM (MundoODE);
}

/*!
* \param bDeshabilitable true habilita la autodesactivaci&oacute;n de cuerpos,
* false la desactiva.
*
* Esto incrementa la velocidad, ya que los cuerpos deshabilitados no consumen proceso
* del CPU.
*
* Los cuerpos deshabilitados se reactivan automáticamente si estan conectados a otro
* en estado activo.
*
* \note Deshabilitado por defecto.
*/
void GD_FisicasOdeSistema::ModoAutodesactivar(bool bDeshabilitable)
{
    dWorldSetAutoDisableFlag(MundoODE, (int) bDeshabilitable);
}

/*!
*/
bool GD_FisicasOdeSistema::ValorModoAutodesactivar()
{
    //return (bool)dWorldGetAutoDisableFlag(MundoODE);
	if(dWorldGetAutoDisableFlag(MundoODE) == 0) {
		return false;
	} else {
		return true;
	}
}

/*!
*/
void GD_FisicasOdeSistema::Autodesactivacion_por_UmbralLinear(dReal UmbralLinear)
{
    dWorldSetAutoDisableLinearThreshold(MundoODE, UmbralLinear);
}

/*!
*/
dReal GD_FisicasOdeSistema::ValorAutodesactivacion_por_UmbralLinear()
{
    return dWorldGetAutoDisableLinearThreshold(MundoODE);
}

/*!
*/
void GD_FisicasOdeSistema::AutoDesactivacion_por_UmbralAngular(dReal UmbralAngular)
{
    dWorldSetAutoDisableAngularThreshold(MundoODE, UmbralAngular);
}

/*!
*/
dReal GD_FisicasOdeSistema::ValorAutoDesactivacion_por_UmbralAngular()
{
    return dWorldGetAutoDisableAngularThreshold(MundoODE);
}

/*!
*/
void GD_FisicasOdeSistema::AutoDesactivacion_por_Iteraciones(int Iteraciones)
{
    dWorldSetAutoDisableSteps(MundoODE, Iteraciones);
}

/*!
*/
int GD_FisicasOdeSistema::ValorAutoDesactivacion_por_Iteraciones()
{
    return dWorldGetAutoDisableSteps(MundoODE);
}

/*!
*/
void GD_FisicasOdeSistema::AutoDesactivacion_por_Tiempo(dReal Tiempo)
{
    dWorldSetAutoDisableTime(MundoODE, Tiempo);
}

/*!
*/
dReal GD_FisicasOdeSistema::ValorAutoDesactivacion_por_Tiempo()
{
    return dWorldGetAutoDisableTime(MundoODE);
}

/*!
* Libera parte de la memoria que no es posible liberar con otros
* m&eacute;todos destructivos de ODE.
*
* Se sugiere usarlo en el final de los programas, o donde deje de ser
* necesario usar f&iacute;sicas, para prevenir que otras funciones
* fallen a causa
*/
void CerrarODE(){
    dCloseODE();
}

/*!
*/
vector3df GD_FisicasOdeSistema::Impulso_a_Fuerza(dReal Incremento,vector3df Impulso)
{
    dVector3 vFuerza;
    vector3df vFuerzaR;

    dWorldImpulseToForce(MundoODE, Incremento,
            (dReal) Impulso.X, (dReal) Impulso.Y, (dReal) Impulso.Z, vFuerza);

    vFuerzaR.X=vFuerza[0];  vFuerzaR.Y=vFuerza[1];  vFuerzaR.Z=vFuerza[2];

    return vFuerzaR;

}

/*!
* Es hom&oacute;logo a GD_Sistema::Render(), pero en vez de dibujar,
* calcula todos los factores f&iacute;sicos en juego.
*
* \note Cabe destacar que ODE solamente se dedica calcular. Quien dibuja en pantalla
* los resultados es el motor Irrlicht.
*/
void GD_FisicasOdeSistema::Actualizar(dReal VelIteracion)
{
    dWorldStep (MundoODE, VelIteracion);
}

/*!
* Es m&aacute;s veloz que Actualizar() pero a la vez m&aacute;s impreciso
*/
void GD_FisicasOdeSistema::Actualzar_Modo_QS(dReal VelIteracion)
{
    //dWorldStep(MundoODE,VelIteracion);
    dWorldQuickStep(MundoODE,VelIteracion);
}

/*!
* \author Sir_Gon <sir_gon@users.sourceforge.net>
*/
void GD_FisicasOdeSistema::Actualizar_Rapido(dReal VelIteracion)
{
    //dWorldStep(MundoODE,VelIteracion);
    dWorldQuickStep(MundoODE,VelIteracion);
}

/*!
* Mientras mayor sea el n&uacute;mero, m&aacute;s preciso.
*/
void GD_FisicasOdeSistema::NumIteraciones_modo_QS(int Iteraciones)
{
    dWorldSetQuickStepNumIterations (MundoODE, Iteraciones);
}

/*!
* \author Sir_Gon <sir_gon@users.sourceforge.net>
*/
void GD_FisicasOdeSistema::NumIteraciones_Rapidas(int Iteraciones)
{
    dWorldSetQuickStepNumIterations (MundoODE, Iteraciones);
}


int GD_FisicasOdeSistema::ValorNumIteraciones_modo_QS()
{
    return dWorldGetQuickStepNumIterations(MundoODE);
}

/*!
* \author Sir_Gon <sir_gon@users.sourceforge.net>
*/
int GD_FisicasOdeSistema::ValorNumIteraciones_Rapidas()
{
    return dWorldGetQuickStepNumIterations(MundoODE);
}

void GD_FisicasOdeSistema::VelocidadMaximaDeCorreccion_por_Contacto(dReal vel)
{
    dWorldSetContactMaxCorrectingVel(MundoODE, vel);
}
dReal GD_FisicasOdeSistema::ValorVelocidadMaximaDeCorreccion_por_Contacto()
{
    return dWorldGetContactMaxCorrectingVel(MundoODE);
}

void GD_FisicasOdeSistema::SuperficieDeContacto(dReal Profundidad)
{
    dWorldSetContactSurfaceLayer (MundoODE,Profundidad);
}
dReal GD_FisicasOdeSistema::ValorSuperficieDeContacto()
{
    return dWorldGetContactSurfaceLayer(MundoODE);
}

void GD_FisicasOdeSistema::Actualizar_Modo_SF1(dReal VelIteracion, int MaxIteraciones)
{
    dWorldStepFast1(MundoODE, VelIteracion, MaxIteraciones);
}
void GD_FisicasOdeSistema::ProfundidadDeAutoactivacionSF1(int ProfundidadDeAutoactivacion)
{
    dWorldSetAutoEnableDepthSF1(MundoODE, ProfundidadDeAutoactivacion);
}
int GD_FisicasOdeSistema::ValorProfundidadDeAutoactivacionSF1()
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
