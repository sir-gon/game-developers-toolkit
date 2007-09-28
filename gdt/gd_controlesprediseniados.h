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


#ifndef GD_CONTROLESPREDISENIADOS_H
#define GD_CONTROLESPREDISENIADOS_H

#include <Irrlicht/irrlicht.h>
#include "gd_sistema.h"
#include "gd_malla.h"

//EXPORTAR SIMBOLOS AL CREAR DLL
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

/* No Documentar esto */
#ifndef _GDT_DOXYGEN_IGNORAR_
struct stTeclado
{
	int iUp,iDown,iRight,iLeft,iControl,iShift;
	double dUp,dDown,dRight,dLeft,dControl,dShift;
};

struct stMouse
{
	f32 MoveX,MoveY,MLeft,MRight,MCenter;
};
#endif /* _GDT_DOXYGEN_IGNORAR_ */


namespace GDT
{

//! Controles Predise&ntilde;ados
	class ControlesPrediseniados : public Matematicas, public Sistema
	{
		private:
			Sistema sistema;
		public:
			//protected:
			stTeclado Teclado;
			stMouse Mouse;


			_GDT_EXPORT_ ControlesPrediseniados();
			_GDT_EXPORT_ ControlesPrediseniados ( Sistema sistemaGeneral );
			_GDT_EXPORT_ ~ControlesPrediseniados();

			_GDT_EXPORT_ void TeclasActivas ( int iUp,int iDown,int iRight,int iLeft,int iControl,int iShift );
			_GDT_EXPORT_ void ValoresEnTeclado ( double dUp,double dDown,double dRight,double dLeft,double dControl,double dShift );

			//Plantilla de tipos de dato que usan la clase nodo
			_GDT_EXPORT_ void ActivarSistema ( Sistema sistem );
			_GDT_EXPORT_ void TecladoUDRL ( GDT::Nodo::Malla MallaX );
			_GDT_EXPORT_ void TecladoUDRLCtrlShift();
			_GDT_EXPORT_ void TecladoURLDMouseMove();
			_GDT_EXPORT_ void TecladoUDRLCtrlShiftMouseMove();

			_GDT_EXPORT_ void TecladoUDRL ( stTeclado *pTeclado );
			_GDT_EXPORT_ void TecladoUDRLCtrlShift ( stTeclado *pTeclado );
			_GDT_EXPORT_ void TecladoURLDMouseMove ( stTeclado *pTeclado,stMouse *pMouse );
			_GDT_EXPORT_ void TecladoUDRLCtrlShiftMouseMove ( stTeclado *pTeclado,stMouse *pMouse );

	};

} // FIN NAMESPACE GDT

#endif //CONTROLESPREDISENIADOS_H
