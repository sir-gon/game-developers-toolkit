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

/*!\mainpage

\image html logoGDT.png

\section intro Manual de Referencia
Bienvenido a la documentaci&oacute;n de GDT.

Ac&aacute; encontrar&aacute; los detalles de todas las Clases, Propiedades, M&eacute;todos y Definiciones. En la mayor&iacute;a encontrar&aacute;s las definiciones de los par&aacute;metros, el prop&oacute;sito de cada m&eacute;todo y en ocaciones un ejemplos de su uso.

<A HREF="refman.pdf">Ac&aacute; puede encontrar una copia descargable en formato PDF</A>

\section getting_started Comenzando con un esqueleto GDT
Para comenzar, puedes ocupar el siguiente programa esqueleto:

\code
#include <gdt.h>

GD_Sistema Sistema;

int main()
{
        Sistema.Inicializar(640,480,16,false,OPENGL);
        
        GD_Camara Camara;
        Camara.Crear(Tipo_Modelador );

        while(Sistema.EnEjecucion())
        {
                // Cerrar programa con tecla ESC
                if(Sistema.TeclaAbajo(T_ESC)) Sistema.Matarme();
                
                //Dibujar contenido de la ventana 
                Sistema.Render();
        }
        
        Sistema.Matarme();
        
        return 0;
}
\endcode

Para enlazar correctamente con las librerías externas, recuerda que se necesitan:

- gdt
- Irrlicht
- openal
- alut
- ogg
- vorvis
- vorbisenc
- vorbisfile
- lua5.1

Dependiendo del compilador y plataforma, el enlazado se configura de diferentes maneras.
*/


// Sistema
#include "gd_sistema.h"
// 3D
#include "gd_escenario.h"
#include "gd_luz.h"
#include "gd_camara.h"
#include "gd_panorama.h"
#include "gd_cartelera.h"
#include "gd_terreno.h"
#include "gd_agua.h"
#include "gd_particula.h"
//#include "gd_textura.h"
//#include "gd_colisiones3d.h"
#include "gd_malla.h"
// GUI
#include "gd_guiimagen.h"
#include "gd_guitexto.h"
#include "gd_guiboton.h"
#include "gd_guibarra.h"
#include "gd_guiedicion.h"
#include "gd_guidialogoabrir.h"
#include "gd_guiventana.h"
#include "gd_guimenu.h"
// Reloj
//#include "gd_reloj.h"
//Matematicas
#include "gd_sistemamatematicas.h"
//Controles prediseï¿½dos
//#include "gd_controlesprediseniados.h"
// ARCHIVOS
#include "gd_archivo.h"
#include "gd_xml.h"
#include "gd_listaarchivos.h"
//Otros
#include "gd_fundido.h"

// CAPA DE AUDIO
#if defined(_GDT_SONIDO_)
  //Sonido
  #include "gd_sistemasonido.h"
  #include "gd_sonido3d.h"
  #include "gd_sonido.h"
  //Musica
  #if defined(WIN32)
     #include "gd_musik.h"
  #endif
#endif

//Lenguaje de Scripting LUA
#if defined(_GDT_SCRIPTING_)
  #include "gd_sistemalua.h"
#endif

//Fisicas ODE
#if defined(_GDT_FISICAS_NEWTON_ODE_)
  
#endif

//Fisicas NEWTON DYNAMICS
#if defined(_GDT_FISICAS_NEWTON_NEWTON_)
  #include "gd_sistemafisicas.h"
  #include "gd_cuerpo.h"
#endif


// HACK PARA EXPORTAR SIMBOLOS EN DLL COMPILADOS CON VISUAL C++ 2005
#ifndef _GDT_EXPORT_
  #ifdef _GDT_VC_STUDIO_2005_
   #define _GDT_EXPORT_ __declspec(dllexport)
  #else
    #define _GDT_EXPORT_
  #endif
#endif

