// Class automatically generated by Dev-C++ New Class wizard

#ifndef GD_GUIVENTANA_H
#define GD_GUIVENTANA_H

#include "gd_gui.h" // inheriting class's header file

#include "gd_sistema.h"
/*
 * GUI Ventana (Window)
 */
class GD_GuiVentana : public GD_gui
{
	public:
		// class constructor
		GD_GuiVentana();
		// class destructor
		~GD_GuiVentana();
		
		IGUIWindow* ventana;

		void Crear(int x1, int y1, int x2, int y2, wchar_t * texto, bool modal,IGUIElement* padre=0);
		
		
};

#endif // GD_GUIVENTANA_H
