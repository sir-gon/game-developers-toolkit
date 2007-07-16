/***************************************************************************
 *   GDT (GAME DEVELOPERS TOOLKIT)                                         *
 *   Copyright (C) 2006 GDT STAFF                                          *
 *   http://gdt.sourceforge.net                                            *
 *                                                                         *
 *   Use este programa de Ejemplo para comenzar a armar su propio juego    *
 *                                                                         *
 ***************************************************************************/
 
 
#include <gdt.h>

GD_Sistema Sistema;
GD_Camara Camara;
GD_Malla Figura;
GD_Luz Luz;

int main()
{
	Sistema.Inicializar(640,480,16,false,OPENGL);
	Sistema.ColorFondo(30,30,30);

	Camara.Crear(Tipo_Modelador);
	
	// Crea una Figura
    Figura.CrearEsfera(30);
    // Colores de la Figura
    Figura.ColorEspecular(0,0,50);
    Figura.ColorEmisivo(0,0,50);
    Figura.ColorDifuso(0,0,50);
    
    // posicion // colores // radio
    Luz.Crear(60,60,60, 30, 30, 30, 25);
    
    // Ciclo de dibujado
	while(Sistema.EnEjecucion())
	{
          // Capturar Evento de Teclado
          if (Sistema.TeclaAbajo(T_ESC))
             // Cerrar Ejecucion
             Sistema.Matarme();
          // Dibujar
          Sistema.Render();
	}

	Sistema.Matarme();

	return 0;
}
