/*
* GDT (GAME DEVELOPERS TOOLKIT)
* Copyright (C) 2006 GDT STAFF
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

//Musica
#include "gd_musik.h"
// Sistema
#include "gd_sistema.h"
// 3D
#include "gd_escenario.h"
#include "gd_malla.h"
#include "gd_luz.h"
#include "gd_camara.h"
#include "gd_panorama.h"
#include "gd_cartelera.h"
#include "gd_terreno.h"
#include "gd_agua.h"
#include "gd_particula.h"
#include "gd_textura.h"
//Colisiones
#include "gd_colisiones3d.h"
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
//Sonido
#include "gd_sistemasonido.h"
#include "gd_sonido3d.h"
#include "gd_sonido.h"
//Matematicas
#include "gd_sistemamatematicas.h"
//Script
#include "gd_sistemalua.h"
//Controles prediseñados
//#include "gd_controlesprediseniados.h"
//Archivos
#include "gd_archivo.h"
#include "gd_xml.h"
#include "gd_listaarchivos.h"
//Otros
#include "gd_fundido.h"


IrrlichtDevice *GD_Sistema::device=NULL;
int GD_Sistema::ContadorElementosGui;

