# game-developers-toolkit
(OBSOLETE) Library over Irrlicht for 3D Video Game development

This library has obsolete dependencies, and is not working since 2007.

It was backed up to github only for historical purposes.

Original Documentation and coding is in SPANISH.


# Preparar Paquetes
Los siguientes paquetes son herramientas de compilación:

gcc g++ build-essential automake libtool

Los siguientes paquetes son librerías y headers:

liblua5.1-0-dev libalut-dev libalut0 libopenal0a libopenal-dev libogg-dev libvorbis-dev

Nota1: los paquetes tienen esos nombres en ubuntu, pueden variar en otras distros.

Nota2: estos paquetes tienes varias dependencias, así que no hay que dedudar en instalarlas todas.

# Preparar archivos y directorios

* Preparar un directorio para todo lo que se va a hacer.
por ejemplo "dev", en este mismi directorio es conveniente más adelante guardar los proyectos basados en gdt e irrlicht.
Sugerencia: no use rutas con espacios en blanco.

* En este directorio "dev" crear uno para los headers de gdt e irrlicht, de preferencia uno para cada cual para que no se mezclen las cosas.
Sugerencia: nombrar al directorio ".include" para que quede oculto

Ejemplo:
dev/.include/gdt		//Directorio headers de gdt
dev/.include/irrlicht		//Directorio headers de irrlicht.

* Ahora, copiar todos los .h de gdt e irrlicht en las carpetas destinadas correspondientes.

* En el directorio "dev" crear una carpeta para las librerías de gdt e irrlicht. 
Sugerencia: nombrar al directorio ".lib/linux-x86"

Ejemplo:
dev/.lib/linux-x86

* Copiar en el directorio ".lib/linux-x86" el archivos libIrrlicht.a del paquete de irrlicht, la librería precompilada para Linux.

# Configurar Kdevelop para compilar GDT

* Crear proyecto Kdevelop de C++ (el hello world u otro que sea simple)

* Eliminar el unico "target" desde el panel de Automake MAnager

* Agregar un nuevo "target" con:
Primary: Library
Prefix: noinst
File Name: libgdt

* Agregar a nuestro target (panel de Automake Manager, boton derecho en el target -> Add Existing Files) nuevo todos los .cpp de GDT

* Ir al menú Project -> Project Options -> Build Configuration 
Seleccionar default

* Ir al menú Project -> Project Options -> Configure Options

* Agregar en C/C++ preprocessor flags (CPPFLAGS):
-I../../.include/gdt -I../../.include/irrlicht -I/usr/include/AL -I/usr/include/ogg -I/usr/include/vorbis -I/usr/include/lua5.1

Nota: estas rutas corresponden a los headers, las 2 primeras son las carpetas de headers de los pasos anteriores, las otras son de las demás librerías que se pueden instalar con paquetes, por lo mismo, cabe verificar que sean las rutas correctas ya que pueden variar de una distro a otra.

* Agregar en Linker Flags (LDFLAGS):
-L../../.lib/linux-x86/

Nota: esta es la carpeta donde está la librería libIrrlicht.a y donde futuramente copiaremos la libgdt.a para que este disponibles para los otros proyectos.

* En el panel Automake Manager, click derecho sobre el target "libgdt.a" -> Options -> Flags -> Linker Flags (LDFLAGS), en la caja "Other" llenar con:

$(all_libraries) -lalut -logg -lopenal -lvorbis -lvorbisenc -lvorbisfile -llua5.1 -lGL

* Construir :P

* Copiar gdt/src/libgdta.a al directorio ".lib/linux-x86"

C/C++ preprocessor flags (CPPFLAGS):
-I../../.include/gdt -I../../.include/irrlicht -I/usr/include/AL -I/usr/include/ogg -I/usr/include/vorbis -I/usr/include/lua5.1

Linker Flags (LDFLAGS):
-L../../.lib/linux-x86/

# Crear una aplicación GDT con la librería construida

* se necesitan librarias para opengl y X11 y sus dependencias
libglut-dev libxxf86vm-dev

* Ir al menú Project -> Project Options -> Build Configuration 
Seleccionar default

* Ir al menú Project -> Project Options -> Configure Options

* Crear un nuevo proyecto, darle nombre y guardarlo en nuestra carpeta dev

* Configurar Kdevelop con los siguientes parametros como en la sección anterior:

C/C++ preprocessor flags (CPPFLAGS):
-I../../.include/gdt -I../../.include/irrlicht -I/usr/include/AL -I/usr/include/ogg -I/usr/include/vorbis -I/usr/include/lua5.1

Linker Flags (LDFLAGS):
-L../../.lib/linux-x86

* Configurar el target, en el panel Automake Manager, click derecho sobre el target correspondiente (lleva el nombre del proyecto) -> Options -> Flags -> Linker Flags (LDFLAGS), en la caja "Other" llenar con:

$(all_libraries) -lgdt -lIrrlicht -lalut -logg -lopenal -lvorbis -lvorbisenc -lvorbisfile -llua5.1 -lGL -lGLU -lXxf86vm -lXext -lX11

* Escribir el codigo o copiar un demo, guardarlos en la carpeta dev/nombre_del_proyecto/src, luego agregar los archivos .cpp/.h al target ( panel de Automake Manager, boton derecho en el target -> Add Existing Files )

* Compilar y Correr

* Una vez creado el proyecto y que se ha comprobado que compila y se ejecuta correctamente, es posible distribuir el código fuente para cualquier distro, basta que en el usuario baje el paquete, lo descomprima, abra una consola o un terminar y valla a la carpeta donde descompimio el código, entonces debe usar los comandos:

./configure
make

Nota: aun no he probado como hacer que make sirva para instalar el código una vez compilado, con el clásico comando "make install", por el momento, basta con entrar a la carpeta src y ejecutar el binario creado con "make"

# CAMBIOS EN EL CODIGO FUENTE
[nombre_archivo:linea] [agregado:]
... tal codigo ...
[cambiado por]
.... otro codigo ...

***********[gdt.h:1]
//Musica
#include "gd_musik.h"

***********[cambiado por]
//Musica
#ifdef WIN32
	// ESTA FUNCIONA SOLO EN WINDOWS.
	#include "gd_musik.h"
	// HACK PARA QUE LA FUNCION SWPRINTF ESTE DEFINIDA COMO EL ESTANDAR UNIX
	#define swprintf _snwprintf
#endif

***********[gd_nodo.h:9]
#include "gd_Sistema.h"

***********[cambiado por]
#include "gd_sistema.h"

***********[gd_textura.h:17]
#include "gd_Sistema.h"

***********[cambiado por]
#include "gd_sistema.h"

***********[gd_malla.h:82]
      ISceneNode* GD_Malla::RetornarNodoHuesoX(c8* Nombre );
      ISceneNode* GD_Malla::RetornarNodoHuesoMS3D(c8* Nombre );

***********[cambiado por]
      ISceneNode* RetornarNodoHuesoX(c8* Nombre );
      ISceneNode* RetornarNodoHuesoMS3D(c8* Nombre );

***********[gd_musik.h:1] [agregado:]
      // Este archivo funciona solo en win32
      #ifdef WIN32 
***********[gd_musik.h:68] [agregado:]
      // Este archivo funciona solo en win32      
      #endif

***********[gd_musik.cpp:1] [agregado:]
      // Este archivo funciona solo en win32
      #ifdef WIN32
***********[gd_musik.cpp:192] [agregado:]
      // Este archivo funciona solo en win32
      #endif

***********[Nota: tambien vale omitir gd_musik.cpp en la compilacion, pero prefiero dejarlo mientras hasta encontrar alguna alternativa para tocar midi en linux] ********

***********[gd_sistemamatematicas.cpp:3]
#include "GD_SistemaMatematicas.h" // class's header file

***********[cambiado por]
#include "gd_sistemamatematicas.h" // class's header file

***********[gd_sistemasonido.cpp:60]
    pDevice = alcOpenDevice((ALCubyte*)tipo);

***********[cambiado por]
#ifdef WIN32
    pDevice = alcOpenDevice((ALCubyte*)tipo);
#else
    pDevice = alcOpenDevice((ALCchar*)tipo);
#endif

###########################
### ERRORES AL COMPILAR ###
###########################
hay que revizar estos warnings:

gd_sonido3d.cpp:32: warning: ‘alutLoadWAVFile’ is deprecated (declared at /usr/include/AL/alut.h:102)
gd_sonido3d.cpp:32: warning: ‘alutLoadWAVFile’ is deprecated (declared at /usr/include/AL/alut.h:102)
gd_sonido3d.cpp:35: warning: ‘alutUnloadWAV’ is deprecated (declared at /usr/include/AL/alut.h:105)
gd_sonido3d.cpp:35: warning: ‘alutUnloadWAV’ is deprecated (declared at /usr/include/AL/alut.h:105)
