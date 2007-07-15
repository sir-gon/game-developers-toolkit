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

/*!
\class GDControlesPrediseniados


\todo (Astucia#1#): Crear comandos de teclado predise&ntilde;ados
\todo (Astucia#1#): Crear funciones con valores de retorno
*/
#include "gd_controlesprediseniados.h"


GD_ControlesPrediseniados::GD_ControlesPrediseniados()
{
      Teclado.iUp=38;
      Teclado.iDown=40;
      Teclado.iLeft=37;
      Teclado.iRight=39;
      Teclado.iControl=17;
      Teclado.iShift=16;

}
GD_ControlesPrediseniados::~GD_ControlesPrediseniados(){}

GD_ControlesPrediseniados::GD_ControlesPrediseniados(GD_Sistema sistemaGeneral)
{
      sistema=sistemaGeneral;
      Teclado.iUp=38;
      Teclado.iDown=40;
      Teclado.iLeft=37;
      Teclado.iRight=39;
      Teclado.iControl=17;
      Teclado.iShift=16;
}

void GD_ControlesPrediseniados::ActivarSistema(GD_Sistema sistem,GD_SistemaMatematicas Matematicas)
{
   sistema=sistem;
   Mat=Matematicas;
}

void GD_ControlesPrediseniados::TeclasActivas(int iUp,int iDown,int iRight,int iLeft,int iControl=17,int iShift=16)
{
   Teclado.iUp=iUp;
   Teclado.iDown=iDown;
   Teclado.iRight=iRight;
   Teclado.iLeft=iLeft;
   Teclado.iControl=iControl;
   Teclado.iShift=iShift;
}

void GD_ControlesPrediseniados::ValoresEnTeclado(double dUp,double dDown,double dRight,double dLeft,double dControl,double dShift)
{
   Teclado.dUp=dUp;
   Teclado.dDown=dDown;
   Teclado.dRight=dRight;
   Teclado.dLeft=dLeft;
   Teclado.dControl=dControl;
   Teclado.dShift=dShift;
}

void GD_ControlesPrediseniados::TecladoUDRL(GD_Malla Malla)
{

   static int Pers=0;
   static int OldPers=0;
   static float fPosX,fPosY,fPosZ;
   static float fAngX,fAngY,fAngZ;
   static vector3df vecPosPers;
   float MousePsX;

   // Estado del personaje principal
   //Posicion
   fPosX=Malla.PosicionX();
   fPosY=Malla.PosicionY();
   fPosZ=Malla.PosicionZ();
   //Angulo de rotacion
   fAngX=Malla.RotacionX();
   fAngY=Malla.RotacionY();
   fAngZ=Malla.RotacionZ();


   //Moviendo
   if ((sistema.TeclaAbajo(38))||(sistema.TeclaAbajo(87))){
      fPosX=(float)Mat.NewXValue(fPosX,fAngY,-2.0);
      fPosZ=(float)Mat.NewZValue(fPosZ,fAngY,-2.0);
   }
   if ((sistema.TeclaAbajo(T_FLECHA_ABAJO))||(sistema.TeclaAbajo(T_TECLA_S))){
      fPosX=(float)Mat.NewXValue(fPosX,fAngY,2.0);
      fPosZ=(float)Mat.NewZValue(fPosZ,fAngY,2.0);
   }
   if ((sistema.TeclaAbajo(T_FLECHA_IZQUIERDA))||(sistema.TeclaAbajo(T_TECLA_Q))){fPosY-=3.0;}
   if ((sistema.TeclaAbajo(T_FLECHA_DERECHA))||(sistema.TeclaAbajo(T_TECLA_E))){fPosY+=3.0;}

   if ((sistema.TeclaAbajo(T_CONTROL))||(sistema.TeclaAbajo(T_TECLA_D))){
      fPosX=(float)Mat.NewXValue(fPosX,Mat.WrapValue(fAngY+90),-2.0);
      fPosZ=(float)Mat.NewZValue(fPosZ,Mat.WrapValue(fAngY+90),-2.0);
   }
   if ((sistema.TeclaAbajo(T_SHIFT))||(sistema.TeclaAbajo(T_TECLA_A))){
      fPosX=(float)Mat.NewXValue(fPosX,Mat.WrapValue(fAngY+90),2.0);
      fPosZ=(float)Mat.NewZValue(fPosZ,Mat.WrapValue(fAngY+90),2.0);
   }

   if(sistema.TeclaAbajo(T_TECLA_M))
      Malla.MoverX(5.0);


   MousePsX=sistema.MouseMovimientoX(1);
   if (MousePsX<0)
   {fAngY=(float)Mat.WrapValue(fAngY-2.5);}
   else
   {
      if (MousePsX>0){fAngY=(float)Mat.WrapValue(fAngY+2.5);}
   }

   Malla.Posicionar(fPosX,fPosY,fPosZ);
   Malla.RotarY(fAngY);

   vecPosPers=Malla.Posicion();

   // Seguimiento de camara
   //Seguimiento_de_Camara(vecPosPers,fAngY);

   //CargarNodo(nodoReceptor);
/*
   if(sistema.TeclaAbajo(Teclado.iUp))
      Malla.Mover(Malla.NewXValue(Malla.PosicionX(),0,Teclado.dUp),
                  0,Malla.NewZValue(Malla.PosicionZ(),0,Teclado.dUp));

   if(sistema.TeclaAbajo(Teclado.iDown))
      Malla.Mover(Malla.NewXValue(Malla.PosicionX(),0,Teclado.dDown),
                  0,Malla.NewZValue(Malla.PosicionZ(),0,Teclado.dDown));

   if(sistema.TeclaAbajo(Teclado.iLeft))
      Malla.Mover(Malla.NewXValue(Malla.PosicionX(),90,Teclado.dLeft),
                  0,Malla.NewZValue(Malla.PosicionZ(),90,Teclado.dLeft));

   if(sistema.TeclaAbajo(Teclado.iRight))
      Malla.Mover(Malla.NewXValue(Malla.PosicionX(),90,Teclado.dRight),
                  0,Malla.NewZValue(Malla.PosicionZ(),90,Teclado.dRight));

   //ActualizarNodoReceptor(nodoReceptor);
*/
}

void GD_ControlesPrediseniados::TecladoUDRLCtrlShift()
{
}

void GD_ControlesPrediseniados::TecladoURLDMouseMove()
{
}

void GD_ControlesPrediseniados::TecladoUDRLCtrlShiftMouseMove()
{
}

void GD_ControlesPrediseniados::TecladoUDRL(stTeclado *pTeclado)
{
}

void GD_ControlesPrediseniados::TecladoUDRLCtrlShift(stTeclado *pTeclado)
{
}

void GD_ControlesPrediseniados::TecladoURLDMouseMove(stTeclado *pTeclado,stMouse *pMouse)
{
}

void GD_ControlesPrediseniados::TecladoUDRLCtrlShiftMouseMove(stTeclado *pTeclado,stMouse *pMouse)
{
}

