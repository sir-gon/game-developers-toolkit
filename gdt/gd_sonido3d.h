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

#ifndef GD_SONIDO3D_H
#define GD_SONIDO3D_H

/*
 * No description
 */
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <al.h>
#include <alc.h>
#include <alut.h>
#include <ogg.h>
#include <vorbisfile.h>


using namespace std;

/**
* Sonido 3D
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
        
        //para ogg
        /*ALuint buffers[2];
        FILE*           oggFile;
        OggVorbis_File  oggStream;
        vorbis_info*    vorbisInfo;
        vorbis_comment* vorbisComment;
        ALenum format;*/

    public:
        char Cargar(char *);
        //char CargarOgg(char *archivo);
        char CargarOGG(char *);
        void Descargar();
        void Reproducir();
        void Pausa();
        void Detener();
        void Rebobinar();
        void Play();
        void Pause();
        void Stop();
        void Rewind();
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
