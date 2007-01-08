/*
* GDT (GAME DEVELOPERS TOOLKIT)
* Copyright (C) 2006 GDT STAFF
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#ifndef GD_CONTROLESPREDISENIADOS_H
#define GD_CONTROLESPREDISENIADOS_H

#include <irrlicht.h>
#include "gd_sistema.h"
#include "gd_malla.h"


struct stTeclado
{
   int iUp,iDown,iRight,iLeft,iControl,iShift;
   double dUp,dDown,dRight,dLeft,dControl,dShift;
};

struct stMouse
{
   f32 MoveX,MoveY,MLeft,MRight,MCenter;
};

/**
 * Controles Prediseñados
 */
class GD_ControlesPrediseniados : public GD_SistemaMatematicas, public GD_Sistema
{
   private:
      GD_Sistema sistema;
      GD_SistemaMatematicas Mat;
      //GD_Malla Malla;
   public:
   //protected:
	stTeclado Teclado;
	stMouse Mouse;
	// TODO (Astucia#1#): Crear comandos de teclado predise�dos
	
	// TODO (Astucia#1#): Crear funciones con valores de retorno
	
	GD_ControlesPrediseniados();
	GD_ControlesPrediseniados(GD_Sistema sistemaGeneral);
	~GD_ControlesPrediseniados();
	
	void TeclasActivas(int iUp,int iDown,int iRight,int iLeft,int iControl,int iShift);
	void ValoresEnTeclado(double dUp,double dDown,double dRight,double dLeft,double dControl,double dShift);
	
	//Plantilla de tipos de dato que usan la clase nodo
	void ActivarSistema(GD_Sistema sistem,GD_SistemaMatematicas Matematicas);
	void TecladoUDRL(GD_Malla Malla);
	void TecladoUDRLCtrlShift();
	void TecladoURLDMouseMove();
	void TecladoUDRLCtrlShiftMouseMove();
	
	void TecladoUDRL(stTeclado *pTeclado);
	void TecladoUDRLCtrlShift(stTeclado *pTeclado);
	void TecladoURLDMouseMove(stTeclado *pTeclado,stMouse *pMouse);
	void TecladoUDRLCtrlShiftMouseMove(stTeclado *pTeclado,stMouse *pMouse);

};
#endif //CONTROLESPREDISENIADOS_H
