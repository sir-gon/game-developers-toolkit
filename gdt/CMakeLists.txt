#add definitions, compiler switches, etc.
#ADD_DEFINITIONS(-Wall -O2)
ADD_DEFINITIONS(-O2)
#build a shared library
ADD_LIBRARY(gdt STATIC
gd_agua.cpp
gd_archivo.cpp
gd_camara.cpp
gd_cartelera.cpp
gd_colisiones3d.cpp
gd_controlesprediseniados.cpp
gd_escenario.cpp
gd_fundido.cpp
gd_guibarra.cpp
gd_guiboton.cpp
gd_gui.cpp
gd_guidialogoabrir.cpp
gd_guiedicion.cpp
gd_guiimagen.cpp
gd_guimenu.cpp
gd_guitexto.cpp
gd_guiventana.cpp
gd_listaarchivos.cpp
gd_luz.cpp
gd_malla.cpp
#gd_musik.cpp
gd_nodo.cpp
gd_panorama.cpp
gd_particula.cpp
gd_sistema.cpp
gd_sistemalua.cpp
gd_sistemamatematicas.cpp
gd_sistemasonido.cpp
gd_sonido3d.cpp
gd_sonido.cpp
gd_terreno.cpp
gd_textura.cpp
gd_xml.cpp
)

INCLUDE (../VIDEO.cmake)
INCLUDE (../SONIDO.cmake)
INCLUDE (../SCRIPTING.cmake)
#INCLUDE (../FISICA.cmake)

IF(NOT VIDEO_FOUND)
	MESSAGE(FATAL_ERROR "GDT: NO se encontraron algunos paquetes para el Video")
ENDIF(NOT VIDEO_FOUND)

IF(NOT SONIDO_FOUND)
	MESSAGE(FATAL_ERROR "GDT: NO se encontraron algunos paquetes para el Sistema de Sonido")
ENDIF(NOT SONIDO_FOUND)

IF(NOT SCRIPTING_FOUND)
	MESSAGE(FATAL_ERROR "NO se encontraron algunos paquetes para Scripting")
ENDIF(NOT SCRIPTING_FOUND)

#IF(NOT FISICA_FOUND)
#	MESSAGE(FATAL_ERROR "NO se encontraron algunos paquetes para Física")
#ENDIF(NOT FISICA_FOUND)

IF(VIDEO_FOUND AND SONIDO_FOUND)
   #MESSAGE("Se ha encontrado todo para usar construir la Biblioteca GDT")

   INCLUDE_DIRECTORIES(${OPENAL_INCLUDE_DIR} ${IRRLICHT_INCLUDE_DIR} ${ALUT_INCLUDE_DIR} ${OGG_INCLUDE_DIR} ${VORBIS_INCLUDE_DIR})
   TARGET_LINK_LIBRARIES(gdt ${OPENAL_LIBRARY} ${IRRLICHT_LIBRARY} ${ALUT_LIBRARY} ${OGG_LIBRARY} ${VORBIS_LIBRARY})

ENDIF(VIDEO_FOUND AND SONIDO_FOUND)

IF(SCRIPTING_FOUND)
   INCLUDE_DIRECTORIES(${LUA_INCLUDE_DIR})
   TARGET_LINK_LIBRARIES(gdt ${LUA_LIBRARY})
ENDIF(SCRIPTING_FOUND)