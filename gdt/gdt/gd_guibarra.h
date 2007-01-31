// Class automatically generated by Dev-C++ New Class wizard

#ifndef GD_GUIBARRA_H
#define GD_GUIBARRA_H

#include "gd_gui.h" // inheriting class's header file

#include "gd_sistema.h"
/*
 * GUI Barras (SCroll Bar)
 */
class GD_GuiBarra : public GD_gui
{
	public:
		// class constructor
		GD_GuiBarra();
		// class destructor
		~GD_GuiBarra();
		
		IGUIScrollBar* barra;
		
		void CrearHorizontal(int x1, int y1, int x2, int y2, IGUIElement* padre=0);
		void CrearVertical(int x1, int y1, int x2, int y2, IGUIElement* padre=0);
		
		void MaximoValor(int maximo);
		int Posicion(void);
		void Posicionar(int posicion);
};

#endif // GD_GUIBARRA_H
