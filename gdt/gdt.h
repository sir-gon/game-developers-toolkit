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

\section comenzando Comenzando con un esqueleto GDT
Para comenzar, los novatos pueden preferir ocupar una versi&oacute;n 
precompilada de GDT.

Luego, para probar la instalaci&oacute;n, puede ocupar el siguiente programa esqueleto:

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

Para enlazar correctamente con las librer&iacute;as externas, recuerda que se necesitan:

- gdt
- Irrlicht

Y opcionalmente:
- openal
- alut
- ogg
- vorvis
- vorbisenc
- vorbisfile
- lua5.1

Dependiendo del compilador y plataforma, el enlazado se configura de diferentes maneras.

\section important Si desea compilar GDT, concidere que...

Antes, era necesario instalar toda las dependencias. Ahora se pueden ocupar
las mismas, pero ya no son todas obligatorias.

En el caso de que no se requiera, o aparezcan problemas, tal vez desee compilar
GDT con menos caracter&iacute;sticas.

Para esto, se han establecido algunas definicione para el preprocesador que permiten 
Compilar:

    - _GDT_SONIDO_ // Incluye soporte para tocar sonido usando Openal + Alut
    - _GDT_SONIDO_OGG_ // Incluye soporte para decodificar OGG + Vorbis. NO sirve de nada si no se define _GDT_SONIDO_.
    - _GDT_MIDI_ // Incluye soporte para tocar sonidos Midi. Este m&oacutelo requiere la WINAPI. Viene desactivado en Linux (por razones obvias) y en MS Visual C++ 2005 Express. En este &uacute;ltimo porque necesita tener instalado el Platform SDK previamente. Si desea usar Midi en MSVC, entonces asegurese de tener el PSDK instalado, y luego agregar esta definici&oacute;n en su proyecto.
    - _GDT_SCRIPTING_ // LUA
    - _GDT_FISICAS_NEWTON_ // Newton Dynamics, desactivado en forma predeterminada
    - _GDT_FISICAS_ODE_ // NO implementado aun, pero irá a futuro.

\section evitar Lo que debe evitar:

Por favor, para no tener problemas, no intente:

- Definir _GDT_DOXYGEN_IGNORAR_. Se ha puesto en ciertas partes del c&oacute;digo fuente, para evitar que aparezca en la documentaci&oacute;n algunas cosas que no son necesarias mostrar. Cuando se define _GDT_DOXYGEN_IGNORAR_ el compilador ignorar&aacute; partes que SI SON NECESARIAS PARA COMPILAR.

- Compilar GDT sin haber instalado Irrlicht. Es la principal dependencia de GDT, ya que provee el motor gr&aacute;fico y la base de muchas otras cosas necesarias. Para mayor informaci&oacute;n lea el siguiente punto.

- Compilar GDT con m&oacute;dulos opcionales si sus dependencias no est&aacute; instaladas, o no est&aacute; disponibles. Aseg&uacute;rese que las cabeceras (.h) de las dependencias est&eacute;n disponibles en algun directorio de inclusi&oacute;n o agregar rutas adicionales, donde se tienen instaladas, al proyecto del IDE escogido.

- Usar una caracter&iacute;stica de GDT en un proyecto propio si GDT no fue compilado con ese soporte. En el mejor de los casos provocar&aacute; inevitablemente una caida del ejecutable. De echo es m&aacutes probable que ni siquiera deje compilar/enlazar correctamente el proyecto.
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

