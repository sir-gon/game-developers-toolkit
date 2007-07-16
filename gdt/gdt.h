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
#include "gd_textura.h"
#include "gd_colisiones3d.h"
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
//Controles predise�dos
#include "gd_controlesprediseniados.h"
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
#if defined(_GDT_FISICAS_ODE_)
  #include "gd_fisicasODEsistema.h"
  #include "gd_fisicasODEcuerpo.h"
#endif

//Fisicas NEWTON DYNAMICS
#if defined(_GDT_FISICAS_NEWTON_)
  #include "gd_fisicasNWTNOnwtno.h"
  #include "gd_fisicasNWTNOmaterial.h"
  #include "gd_fisicasNWTNOcuerpo.h"
#endif

//EXPORTAR SIMBOLOS AL CREAR DLL
#ifndef _GDT_EXPORT_
  #ifdef WIN32
	#ifdef _GDT_DLL_
	   #define _GDT_EXPORT_ __declspec(dllexport)
	#else /* Not _GDT_DLL_ */
	   #define _GDT_EXPORT_ __declspec(dllimport)
	#endif /* Not _GDT_DLL_ */
  #else
// SINO, DEFINIR COMO NULO EL EXPORTADOR 
    #define _GDT_EXPORT_ /* Definido nulo */
  #endif  /* WIN32 */
#endif /* _GDT_EXPORT_ */

