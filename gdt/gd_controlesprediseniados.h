

#ifndef GD_CONTROLESPREDISENIADOS_H
#define GD_CONTROLESPREDISENIADOS_H

#include <irrlicht.h>
#include "gd_sistema.h"
#include "gd_malla.h"


//! \manonly Estructura de Teclado \endmanonly
struct stTeclado
{
   int iUp,iDown,iRight,iLeft,iControl,iShift;
   double dUp,dDown,dRight,dLeft,dControl,dShift;
};

//! \manonly Estructura de Mouse \endmanonly
struct stMouse
{
   f32 MoveX,MoveY,MLeft,MRight,MCenter;
};

//class GD_Malla;

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
// TODO (Astucia#1#): Crear comandos de teclado predise&ntilde;ados

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
