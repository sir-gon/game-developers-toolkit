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

#include "gd_sonido3d.h" // class's header file

// class constructor
GD_Sonido3D::GD_Sonido3D()
{
	// insert your code here
     SCargado=0;	
}

// class destructor
GD_Sonido3D::~GD_Sonido3D()
{
	// insert your code here
}


    
char GD_Sonido3D::Cargar(char *archivo)
{
    ALenum format;
	ALsizei size;
	ALvoid* data;
	ALsizei freq;
	ALboolean loop;
	
	alGenBuffers(1, &SBuffer);
	if(alGetError() != AL_NO_ERROR)
		return AL_FALSE;

	alutLoadWAVFile(archivo, &format, &data, &size, &freq, &loop);
	alBufferData(SBuffer, format, data, size, freq);
	//alBufferData(SBuffer, AL_FORMAT_MONO8, data, size, freq);
	alutUnloadWAV(format, data, size, freq);
	
//	AL_FORMAT_MONO8                           0x1100
// AL_FORMAT_MONO16                          0x1101
// AL_FORMAT_STEREO8                         0x1102
// AL_FORMAT_STEREO16
/*   if(format==AL_FORMAT_MONO8)
   {
      printf("mono 8\n");
   }
   if(format==AL_FORMAT_MONO16)
   {
      printf("mono 16\n");
   }
   if(format==AL_FORMAT_STEREO8)
   {
      printf("stereo 8\n");
   }
   if(format==AL_FORMAT_STEREO16)
   {
      printf("stereo 16\n");
   }*/
   //printf("formato:%d frecuencia:%d tamaño:%d",format,freq,size);
	alGenSources(1, &SSource);

	if(alGetError() != AL_NO_ERROR){
        printf("Error al cargar archivo: %s\n" , archivo);
		return AL_FALSE;
    }
		
	alSourcei (SSource, AL_BUFFER,   SBuffer   );
	alSourcef (SSource, AL_PITCH,    1.0f      );
	alSourcef (SSource, AL_GAIN,     1.0f      );
	SSourcePos[0]=0.0; SSourcePos[1]=0.0; SSourcePos[2]=0.0;
	SSourceVel[0]=0.0; SSourceVel[1]=0.0; SSourceVel[2]=0.0;
	alSourcefv(SSource, AL_POSITION, SSourcePos);
	alSourcefv(SSource, AL_VELOCITY, SSourceVel);
	alSourcei (SSource, AL_LOOPING,  AL_FALSE  );
	
	if(alGetError() == AL_NO_ERROR){
        printf("Cargado archivo: %s\n" , archivo);                    
		return AL_TRUE;
    }
		
    printf("Error al cargar archivo: %s\n" , archivo);
	return AL_FALSE;
}

/*char GD_Sonido3D::CargarOgg(char *archivo)
{
   int result;
    
    if(!(oggFile = fopen(archivo, "rb")))
        printf("PETO_01");

    if((result = ov_open(oggFile, &oggStream, NULL, 0)) < 0)
    {
        fclose(oggFile);
        printf("PETO_02");
    }

    vorbisInfo = ov_info(&oggStream, -1);
    vorbisComment = ov_comment(&oggStream, -1);

    if(vorbisInfo->channels == 1)
        format = AL_FORMAT_MONO16;
    else
        format = AL_FORMAT_STEREO16;
        
    
    alGenBuffers(2, buffers);
    //check();
    alGenSources(1, &SSource);
    //check();
    
    alSource3f(SSource, AL_POSITION,        0.0, 0.0, 0.0);
    alSource3f(SSource, AL_VELOCITY,        0.0, 0.0, 0.0);
    alSource3f(SSource, AL_DIRECTION,       0.0, 0.0, 0.0);
    alSourcef (SSource, AL_ROLLOFF_FACTOR,  0.0          );
    alSourcei (SSource, AL_SOURCE_RELATIVE, AL_TRUE      );
    return 0;
}*/

char GD_Sonido3D::CargarOGG(char *fileName)
{
    int endian = 0;       // 0 for Little-Endian, 1 for Big-Endian
    int bitStream;
    long bytes;
    char array[2048];
    char *arg;
    long contador;
    ALenum format;
    ALsizei freq;
    FILE *f;

    //abrimos el archivo
    f = fopen(fileName, "rb");
    
    //creamos las estructuras de informacion ogg
    vorbis_info *pInfo;
    OggVorbis_File oggFile;
    ov_open(f, &oggFile, NULL, 0);
    pInfo = ov_info(&oggFile, -1);
    

    //descubrimos si esta en mono o en stereo
    if (pInfo->channels == 1)
        format = AL_FORMAT_MONO16;
    else
        format = AL_FORMAT_STEREO16;
    
    //sacamos la frecuencia
    freq = pInfo->rate;
    //printf(" -FRECUENCIA DEL ARCHIVO %d- ",freq);
    
    //iniciamos el buffer de openal (interno del objeto)
    alGenBuffers(1, &SBuffer);
    //printf(" -BUFFER CREADO- ");
    
    //mientras queden bytes en el archivo
    contador=0;
    //arg=(char*) malloc(2048);
    arg=(char*)malloc(40000000);
    do {
        //leemos 2048 bytes del archivo y lo metemos en array  
        //bytes = ov_read(&oggFile, array, 2048, endian, 2, 1, &bitStream);
        bytes = ov_read(&oggFile, &arg[contador], 2048, endian, 2, 1, &bitStream);
        contador=contador+bytes;
        //arg=(char *)realloc(arg,contador+2048);
    } while (bytes > 0);
    alBufferData(SBuffer, format, arg, contador, freq);
    alGenSources(1, &SSource);

    if(alGetError() != AL_NO_ERROR)
        return AL_FALSE;
    
    alSourcei (SSource, AL_BUFFER,   SBuffer   );
    alSourcef (SSource, AL_PITCH,    1.0f      );
    alSourcef (SSource, AL_GAIN,     1.0f      );
    SSourcePos[0]=0.0; SSourcePos[1]=0.0; SSourcePos[2]=0.0;
    SSourceVel[0]=0.0; SSourceVel[1]=0.0; SSourceVel[2]=0.0;
    alSourcefv(SSource, AL_POSITION, SSourcePos);
    alSourcefv(SSource, AL_VELOCITY, SSourceVel);
    alSourcei (SSource, AL_LOOPING,  AL_FALSE  );
    
    free(arg);
    ov_clear(&oggFile);
    //printf(" -ARCHIVO CERRADO %d bytes leidos-j ",contador);
    printf("Cargado archivo OGG: %s\n",fileName);
}

void GD_Sonido3D::Descargar()
{
//    alDeleteBuffers(1, &SBuffer);
	alDeleteSources(1, &SSource);
}
void GD_Sonido3D::Reproducir()
{
    alSourcePlay(SSource);
}
void GD_Sonido3D::Pausa()
{
    alSourcePause(SSource);
}
void GD_Sonido3D::Detener()
{
    alSourceStop(SSource);
}
void GD_Sonido3D::Rebobinar()
{
    alSourceRewind(SSource);
}
void GD_Sonido3D::Play()
{
    alSourcePlay(SSource);
}
void GD_Sonido3D::Pause()
{
    alSourcePause(SSource);
}
void GD_Sonido3D::Stop()
{
    alSourceStop(SSource);
}
void GD_Sonido3D::Rewind()
{
    alSourceRewind(SSource);
}
void GD_Sonido3D::Bucle(char loop)
{
    alSourcei(SSource, AL_LOOPING,  loop  );
}
void GD_Sonido3D::RelativoOyente(char rel)
{
    alSourcei(SSource, AL_SOURCE_RELATIVE, rel);
}
void GD_Sonido3D::VolumenMaximo(float max)
{
    if(max>1.0)
        max=1.0;
    if(max<0.0)
        max=0.0;
    alSourcef(SSource,AL_MAX_GAIN,max);
}
void GD_Sonido3D::VolumenMinimo(float min)
{
    if(min>1.0)
        min=1.0;
    if(min<0.0)
        min=0.0;
    alSourcef(SSource,AL_MIN_GAIN,min);
}
void GD_Sonido3D::ReferenciaDistancia(float ref)
{
    alSourcef(SSource,AL_REFERENCE_DISTANCE, ref);
}
void GD_Sonido3D::FactorRolloff(float rol)
{
    alSourcef(SSource, AL_ROLLOFF_FACTOR, rol);
}
void GD_Sonido3D::DistanciaMaxima(float dis)
{
    alSourcef(SSource, AL_MAX_DISTANCE, dis);
}
void GD_Sonido3D::Tono(float ton)
{
    alSourcef(SSource, AL_PITCH, ton);
}
int GD_Sonido3D::Estado()
{
    //4114 sonando , 4115 pausa , 4116 sin sonar
    //0 esta sonando , 1 esta en pausa, 2 esta parado, cualquier otra cosa es fallo
    ALint state;
    alGetSourcei(SSource, AL_SOURCE_STATE, &state);
    return state-4114;
}
void GD_Sonido3D::Posicionar(float x, float y, float z)
{
    SSourcePos[0]=x; SSourcePos[1]=y; SSourcePos[2]=z;
    alSourcefv(SSource, AL_POSITION, SSourcePos);
}
void GD_Sonido3D::Velocidad(float x, float y, float z)
{
    SSourceVel[0]=x; SSourceVel[1]=y; SSourceVel[2]=z;
    alSourcefv(SSource, AL_VELOCITY, SSourceVel);
}


