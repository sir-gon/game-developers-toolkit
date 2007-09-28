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

/*
 * Esta cabecera solo reune comentarios para documentar.
 * NO POSEE NINGUNA FUNIONALIDAD, por lo tanto puede ser totalmente omitida
 */

/*!\mainpage
*
* \image html logoGDT.png
*
* \section intro Manual de Referencia
* Bienvenido a la documentaci&oacute;n de GDT.
*
* Ac&aacute; encontrar&aacute; los detalles de todas las Clases, Propiedades,
* M&eacute;todos y Definiciones. En la mayor&iacute;a encontrar&aacute;s las
* definiciones de los par&aacute;metros, el prop&oacute;sito de cada
* m&eacute;todo y en ocaciones un ejemplos de su uso.
*
*
* <A HREF="refman.pdf">Ac&aacute; puede encontrar una copia descargable en
* formato PDF</A>
*
* \section comenzando Comenzando con un esqueleto GDT
* Para comenzar, los novatos pueden preferir ocupar una versi&oacute;n
* precompilada de GDT.
*
* Luego, para probar la instalaci&oacute;n, puede ocupar el siguiente programa
* esqueleto:
*
* \code
* #include <gdt/gdt.h>
*
* //------------/ Variables globales /-------------
*
* Sistema MiSistema;
* Camara MiCamara;
* Malla Bola;
* Luz Foco;
*
* //---------------/ Principal /-------------------
* int main()
* {
*     MiSistema.Inicializar( 640, 480, 16, false, OPENGL );
*     MiSistema.LimiteCPS( 35 );
*
*     MiCamara.Crear( Tipo_Modelador );
*
*     Foco.Crear( 50,70,60,100,100,100,1 );
*
*     Bola.CrearEsfera( 10, 24 );
*
*     // --------/ Ciclo principal /------------
*      while( MiSistema.EnEjecucion() )
*      {
*          // Cerrar programa con tecla ESC
*          if( MiSistema.TeclaAbajo(T_ESC) )
*             MiSistema.Finalizar();
*
*          //Dibujar contenido de la ventana
*          MiSistema.Render();
*      }
*      // -----/ fin ciclo principal /------
*
*      MiSistema.Finalizar();
*
*      return 0; // termina el programa
* }
* \endcode
*
* Para enlazar correctamente con las librer&iacute;as externas, recuerda que se
* necesitan:
*
* - gdt
* - Irrlicht
*
* Y opcionalmente:
* - openal (OpenAL32)
* - alut
* - ogg
* - vorvis
* - vorbisenc
* - vorbisfile
* - lua5.1
* - ode
* - Newton // No inclu&iacute;do con GDT en ninguna versi&oacute;n
* por restricci&oacute; de la Licencia.
*
* Dependiendo del compilador y plataforma, el enlazado se configura
* de diferentes maneras.
*
* \section important Si desea compilar GDT, concidere que...
*
* Antes, era necesario instalar toda las dependencias. Ahora se pueden ocupar
* las mismas, pero ya no son todas obligatorias.
*
* En el caso de que no se requiera, o aparezcan problemas, tal vez desee
* compilar GDT con menos caracter&iacute;sticas.
*
* Para esto, se han establecido algunas definiciones para el preprocesador que
* permiten compilar con las caracter&iacute;sticas opcionales:
*
*     - _GDT_SONIDO_ // Incluye soporte para tocar sonido usando Openal + Alut
*     - _GDT_SONIDO_OGG_ // Incluye soporte para decodificar OGG + Vorbis. NO
*  sirve de nada si no se define _GDT_SONIDO_.
*     - _GDT_MIDI_ // Incluye soporte para tocar sonidos Midi. Este
*  m&oacute;dulo requiere la WINAPI. Viene desactivado en Linux
*  (por razones obvias) y en MS Visual C++ 2005 Express. En este
*  &uacute;ltimo porque necesita tener previamente instalado el Platform SDK.
*  Si desea usar Midi en MSVC, entonces asegurese de tener el PSDK instalado,
*  y luego agregar esta definici&oacute;n en su proyecto.
*     - _GDT_SCRIPTING_ // LUA
*     - _GDT_FISICAS_ODE_ // F&iacute;sicas Open Dynamics Engine.
*     - _GDT_FISICAS_NEWTON_ // F&iacute;sicas Newton Dynamics, desactivado en forma
*  predeterminada. Se deja como opcional para el usuario por temas de licencia.
*
* \section evitar Lo que debe evitar
*
* Por favor, para no tener problemas, no intente:
*
* - Compilar GDT sin haber instalado Irrlicht. Es la principal dependencia de
*  GDT, ya que provee el motor gr&aacute;fico y la base de muchas otras cosas
*  necesarias. Para mayor informaci&oacute;n lea el siguiente punto.
*
* - Compilar GDT con m&oacute;dulos opcionales si sus dependencias no
*  est&aacute;n instaladas, o no est&aacute;n disponibles. Aseg&uacute;rese
*  que las cabeceras (.h) de las dependencias est&eacute;n disponibles en algun
*  directorio de inclusi&oacute;n o agregar rutas adicionales, donde se tienen
*  instaladas, al proyecto del IDE escogido.
*
* - Usar una caracter&iacute;stica de GDT en un proyecto propio si GDT no fue
*  compilado con ese soporte. En el mejor de los casos podr&iacute;a provocar;
*  una caida durante la ejecuci&oacute;n, pero es m&aacute;s probable que ni
*  siquiera deje compilar/enlazar correctamente el proyecto.
*
* - Usar una caracter&iacute;stica de GDT opcional en su proyecto, sin definir
*  las constantes que activan tal caracter&iacute;stica. Por ejemplo, es
*  incorrecto ocupar Sonido sin haber definido _GDT_SONIDO_. Estas constantes
*  se pueden definir en el proyecto de su IDE, as&iacute; como manualmente en
*  su propio c&oacute;digo, pero asegurese de hacerlo antes incluir GDT,
*  por ejemplo as&iacute;:
*
* \code
* #define _GDT_SONIDO_
* #include <gdt/gdt.h>
* \endcode
*
* - Definir _GDT_DOXYGEN_IGNORAR_. Se ha puesto en ciertas partes del
*  c&oacute;digo fuente, para evitar que aparezca en la documentaci&oacute;n
*  algunas cosas que no son necesarias mostrar. Cuando se define
*  _GDT_DOXYGEN_IGNORAR_ el compilador ignorar&aacute; partes que SI SON
*  NECESARIAS PARA COMPILAR.
*
* - Definir _GDT_DLL_ si no est&aacute; compilando GDT como librer&iacute;a
*  din&aacute;mica DLL en Windows. Tampoco defina esta constante en su propio
*  proyecto. Esta constante se usa para definir _GDT_EXPORT_ con el valor que
*  corresponde en caso de compilar GDT como DLL en Windows.
*
* - Definir _GDT_EXPORT_. Esta constante se define autom&aacute;ticamente
*  en tiempo de compilaci&oacute;n. Se usa para saber si un s&iacute;mbolo
*  se est&aacute; exportando o importanto, cuando se ocupan las mismas
*  cabeceras tanto para la propia librer&iacute;a GDT como para proyectos
*  que enlazan con GDT.
*/

//NAMESPACES

//! \namespace GDT Espacio Principal.
/*!
* \namespace GDT
*
* Es el espacio principal de Game Developers Toolkit.
* Todas las clases de m&aacute;s bajo nivel dependen de este espacio.
*
* Ac&aacute; se encuentran las clases que interactuan con el Sistema Operativo,
* por ejemplo Archivo, XML que son de lectura/escritura de archivos,
* o Cronometro, que maneja funciones de tiempo.
*/


//! \namespace GDT::Fisica C&aacute;lculos de S&oacute;lido R&iacute;gido.
/*!
* \namespace GDT::Fisica
*
*
*/

//! \namespace GDT::Gui Controles de Interfaz gr&aacute;fica de Usuario.
/*!
* \namespace GDT::Gui
*
*
*/

//! \namespace GDT::Nodo Figuras 3D
/*!
* \namespace GDT::Nodo
*
*
*/

//! \namespace GDT::Script Ejecuci&oacute;n de guiones externos.
/*!
* \namespace GDT::Script
*
*
*/

//! \namespace GDT::Sonido M&uacute;sica y efectos de sonido.
/*!
* \namespace GDT::Sonido
*
*
*/

