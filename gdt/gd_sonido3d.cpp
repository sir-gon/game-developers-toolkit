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

/*!
Ejemplo:
\code
Musica.CargarOGG("media/musica.ogg");
Musica.Bucle ( true );
Musica.Reproducir();
\endcode
*/
char GD_Sonido3D::Cargar(char *archivo)
{
	// Create 1 source
	alGenSources(1, &SSource);
	
	// Try to create a buffer from the WAV file
	SBuffer = alutCreateBufferFromFile(archivo);
	if (SBuffer==AL_NONE) // If it failed, we bail
	{
		/* Print some error message */
		return AL_FALSE;
	}

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


#ifdef _GDT_SONIDO_OGG_
/*!
\param archivo La ruta al archivo OGG

Carga un archivo OGG en el buffer, y lo deja listo para la reproducci&oacute;n. Vea Reproducir.

\warning Este m&eacute;todo solo estar&aacute; disponible en caso que _GDT_SONIDO_OGG_ est&eacute; definido en tiempo de compilaci&oacute;n

Ejemplo:
\code
Musica.CargarOGG("media/musica.ogg");
Musica.Bucle ( true );
Musica.Reproducir();
\endcode

\author Sir_Gon <sir_gon@users.sourceforge.net>

\note Se agradece al siguiente <A HREF="http://www.gamedev.net/reference/articles/article2031.asp">art&iacute;culo de GameDev:</A>
*/
char GD_Sonido3D::CargarOGG(char *archivo)
{

  ALsizei freq;               // The frequency of the sound data

  // Create sound buffer and source
  alGenBuffers(1, &SBuffer);
  alGenSources(1, &SSource);

  
  int endian = 0;             // 0 for Little-Endian, 1 for Big-Endian
  int bitStream;
  long bytes;
  char array[BUFFER_SIZE];    // Local fixed size array
  FILE *f;
  // Open for binary reading
  f = fopen(archivo, "rb");
  
  vorbis_info *pInfo;
  OggVorbis_File oggFile;

  ov_open(f, &oggFile, NULL, 0);
return 'a';
  // Get some information about the OGG file
  pInfo = ov_info(&oggFile, -1);

  // Check the number of channels... always use 16-bit samples
  if (pInfo->channels == 1)
    format = AL_FORMAT_MONO16;
  else
    format = AL_FORMAT_STEREO16;
  // end if

  // The frequency of the sampling rate
  freq = pInfo->rate;

  do {
    // Read up to a buffer's worth of decoded sound data
    bytes = ov_read(&oggFile, array, BUFFER_SIZE, endian, 2, 1, &bitStream);
    // Append to end of buffer
    bufferData.insert(bufferData.end(), array, array + bytes);
  } while (bytes > 0);
  ov_clear(&oggFile);

  // Upload sound data to buffer
  alBufferData(SBuffer, format, &bufferData[0], static_cast < ALsizei > (bufferData.size()), freq);

  // Attach sound buffer to source
  alSourcei(SSource, AL_BUFFER, SBuffer);

  printf("Cargado archivo OGG: %s\n", archivo);
  return 'a';
}
#endif // _GDT_SONIDO_OGG_

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

#endif // _GDT_SONIDO_

