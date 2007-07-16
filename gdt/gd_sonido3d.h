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

#ifdef _GDT_SONIDO_ //SE ESPERA DEFINICION COMO PARAMETRO DEL COMPILADOR

#ifndef GD_SONIDO3D_H
#define GD_SONIDO3D_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <al.h>
#include <alc.h>
#include <alut.h>
#include <ogg.h>
#include <vorbisfile.h>
#include <vector>

#define BUFFER_SIZE   32768     // 32 KB buffers

/* No documentar */
#ifndef _GDT_DOXYGEN_IGNORAR_
using namespace std;
#endif /* _GDT_DOXYGEN_IGNORAR_ */

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


//! Manejador de Sonido
/*!
Permite tocar sonidos, y hacer cosas interesantes con ellos, como por ejemplo dejar tocando un sonido en forma indefinida (conocido como loop o bucle de audio), detener/pausar a gusto la reproducci&oacute;n, etc.

Lo m&aacute;s importante, es que soporta formato Wav (onda plana), y OGG (comprimida).
*/
class GD_Sonido3D
{
    public:
	_GDT_EXPORT_ GD_Sonido3D();
	_GDT_EXPORT_ ~GD_Sonido3D();
    private:
	ALuint SBuffer;
	ALuint SSource;
	ALfloat SSourcePos[3];
	ALfloat SSourceVel[3];
	char SCargado;

    public:

	//! Carga un sonido wav
	_GDT_EXPORT_ char Cargar(char *);
	//! Libera el buffer de audio
	_GDT_EXPORT_ void Descargar();
	//! Inicia la reproducci&oacute;n del sonido
	_GDT_EXPORT_ void Reproducir();
	//! Alias de Reproducir
	_GDT_EXPORT_ void Play();
	//! Pausa la reproducci&oacute;n del sonido
	_GDT_EXPORT_ void Pausa();
	//! Alias de Pausa
	_GDT_EXPORT_ void Pause();
	//! Detiene la reproducci&oacute;n del sonido
	_GDT_EXPORT_ void Detener();
	//! Alias de Detener
	_GDT_EXPORT_ void Stop();
	//! Rebobina el sonido
	_GDT_EXPORT_ void Rebobinar();
	//! Alias de Rebobinar
	_GDT_EXPORT_ void Rewind();

        //! Establece que el sonido se debe volver a tocar desde el principio luego de que se acaba.
	_GDT_EXPORT_ void Bucle(char);
	_GDT_EXPORT_ void RelativoOyente(char);
	_GDT_EXPORT_ void VolumenMaximo(float);
	_GDT_EXPORT_ void VolumenMinimo(float);
	_GDT_EXPORT_ void ReferenciaDistancia(float);
	_GDT_EXPORT_ void FactorRolloff(float);
	_GDT_EXPORT_ void DistanciaMaxima(float);
	_GDT_EXPORT_ void Tono(float);
	_GDT_EXPORT_ int Estado();
	_GDT_EXPORT_ void Posicionar(float, float, float);
	_GDT_EXPORT_ void Velocidad(float, float, float);

	// Para cargar un sonido en formato OGG Vorbis.
	#ifdef _GDT_SONIDO_OGG_
	
	private:
        FILE*           oggFile;       // file handle
        OggVorbis_File  oggStream;     // stream handle
        vorbis_info*    vorbisInfo;    // some formatting data
        vorbis_comment* vorbisComment; // user comments

        ALenum format;     // internal format
        vector < char > bufferData; // The sound buffer data from file

	public:
	//! Carga un sonido Ogg Vorbis
        _GDT_EXPORT_ char CargarOGG(char *archivo);
	#endif
};


#endif // GD_SONIDO3D_H

#endif // _GDT_SONIDO_
