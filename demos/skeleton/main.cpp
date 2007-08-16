/*****************************************
 *   GDT (GAME DEVELOPERS TOOLKIT)       *
 *   Copyright (C) 2006 GDT STAFF        *
 *   http://gdt.sourceforge.net          *
 *                                       *
 *   Use este programa de Ejemplo para   *
 *   comenzar a armar su propio juego    *
 *                                       *
 *****************************************/
 
#include <gdt.h>

Sistema MiSistema;
Camara MiCamara;
Malla Figura;
Luz Lampara;

int main()
{
	MiSistema.Inicializar(640,480,16,false,OPENGL);
	MiSistema.ColorFondo(30,30,30);

	MiCamara.Crear(Tipo_Modelador);
	
	// Crea una Figura
    Figura.CrearEsfera(30);
    // Colores de la Figura
    Figura.ColorEspecular(0,0,50);
    Figura.ColorEmisivo(0,0,50);
    Figura.ColorDifuso(0,0,50);
    
    // posicion // colores // radio
    Lampara.Crear(60,60,60, 30, 30, 30, 25);
    
    // Ciclo de dibujado
	while(MiSistema.EnEjecucion())
	{
          // Capturar Evento de Teclado
          if (MiSistema.TeclaAbajo(T_ESC))
             // Cerrar Ejecucion
             MiSistema.Matarme();
          // Dibujar
          MiSistema.Render();
	}

	MiSistema.Matarme();

	return 0;
}
