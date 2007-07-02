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

using namespace std;

//! Manejador de Sonido
/*!
Permite tocar sonidos, y hacer cosas interesantes con ellos, como por ejemplo dejar tocando un sonido en forma indefinida (conocido como loop o bucle de audio), detener/pausar a gusto la reproducci&oacute;n, etc.

Lo m&aacute;s importante, es que soporta formato Wav (onda plana), y OGG (comprimida).
*/
class GD_Sonido3D
{
    public:
        GD_Sonido3D();
        ~GD_Sonido3D();
    private:
        ALuint SBuffer;
        ALuint SSource;
        ALfloat SSourcePos[3];
        ALfloat SSourceVel[3];
        char SCargado;

        // {GON} esto es para CargarOGG
        FILE*           oggFile;       // file handle
        OggVorbis_File  oggStream;     // stream handle
        vorbis_info*    vorbisInfo;    // some formatting data
        vorbis_comment* vorbisComment; // user comments

        ALenum format;     // internal format
        vector < char > bufferData; // The sound buffer data from file
        // {/GON}

    public:
        //! Carga un sonido wav
        char Cargar(char *);
        //! Carga un sonido Ogg Vorbis
        char CargarOGG(char *archivo);
        //! Libera el buffer de audio
        void Descargar();
        //! Inicia la reproducci&oacute;n del sonido
        void Reproducir();
        //! Pausa la reproducci&oacute;n del sonido
        void Pausa();
        //! Detiene la reproducci&oacute;n del sonido
        void Detener();
        //! Rebobina el sonido
        void Rebobinar();
        //! Alias de Reproducir
        void Play();
        //! Alias de Pausa
        void Pause();
        //! Alias de Detener
        void Stop();
        //! Alias de Rebobinar
        void Rewind();
        //! Establece que el sonido se debe volver tocar desde el principio luego de que se acaba.
        void Bucle(char);
        void RelativoOyente(char);
        void VolumenMaximo(float);
        void VolumenMinimo(float);
        void ReferenciaDistancia(float);
        void FactorRolloff(float);
        void DistanciaMaxima(float);
        void Tono(float);
        int Estado();
        void Posicionar(float, float, float);
        void Velocidad(float, float, float);
};


#endif // GD_SONIDO3D_H
