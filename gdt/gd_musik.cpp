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

/*!
* \class GDT::Sonido::Musik
*
* Trabaja en forma similar a Sonido3D, en el sentido que los m&eacute;todos
* estan pensados bajo los mismos conceptos.
*
* \note Este m&oacute;dulo funciona solo en win32, ya que ocupa la WINAPI.
* \note Para compilar en MS Visual C++, es necesario instalar Platform SDK
*/

//SE ESPERA DEFINICION COMO PARAMETRO DEL COMPILADOR
#if defined(WIN32) && defined(_GDT_MIDI_)

#include "gd_musik.h"

GDT::Sonido::Musik::Musik()
{

}
GDT::Sonido::Musik::~Musik()
{

  Destruir();
}

bool GDT::Sonido::Musik::Iniciar(MUSIK_STRING ArchivoMIDI)
{

    lpszArchivoMIDI=ArchivoMIDI;

    //Cerrando el comando por si acaso ya esta abierto.
    mciSendCommand(wDeviceID, MCI_CLOSE, 0, (DWORD) &mciGenericParms);

    mciSetParms.dwTimeFormat=MCI_FORMAT_MILLISECONDS;
    mciSendCommand(wDeviceID, MCI_SET,MCI_SET_TIME_FORMAT, (DWORD)&mciSetParms);

    // Open the device by specifying the device and filename.
    // MCI will attempt to choose the MIDI mapper as the output port.
	#ifdef _MSC_VER
	//mciOpenParms.lpstrDeviceType = L"sequencer";
	#else
    //mciOpenParms.lpstrDeviceType = "sequencer";
	#endif
	mciOpenParms.lpstrDeviceType = (MUSIK_STRING)"sequencer";
    mciOpenParms.lpstrElementName = ArchivoMIDI;
	if (dwReturn = mciSendCommand(wDeviceID , MCI_OPEN,
        MCI_OPEN_TYPE | MCI_OPEN_ELEMENT ,
        (DWORD)(LPVOID) &mciOpenParms))
    {
        // Failed to open device. Don't close it; just return error.
        printf("Error al abrir archivo MIDI: %s\n",ArchivoMIDI);
        return false;
    }

    printf("Cargado archivo MIDI: %s\n",ArchivoMIDI);

    // The device opened successfully; get the device ID.
    wDeviceID = mciOpenParms.wDeviceID;

    // Check if the output port is the MIDI mapper.
    mciStatusParms.dwItem = MCI_SEQ_STATUS_PORT;
    if (dwReturn = mciSendCommand(wDeviceID, MCI_STATUS,
        MCI_STATUS_ITEM, (DWORD)(LPVOID) &mciStatusParms))
    {
        mciSendCommand(wDeviceID, MCI_CLOSE, 0, (DWORD) &mciGenericParms);
        return false;
    }

    mciPlayParms.dwCallback = (DWORD) hwnd;
    mciStatusParms.dwCallback=(DWORD)hwnd;

    dwStartVolume=VolumenActual();     // Guarda el volumen inicial del dispositivo

    Volumen(50);

   return true;
}

bool GDT::Sonido::Musik::Cargar(MUSIK_STRING ArchivoMIDI)
{
   return Iniciar(ArchivoMIDI);
}

void GDT::Sonido::Musik::Destruir()
{
   Volumen(dwStartVolume);   // Reestablece el volumen inicial
   mciSendCommand(wDeviceID, MCI_CLOSE, 0, (DWORD) &mciGenericParms);
}

void GDT::Sonido::Musik::Inicio_Fin(int Inicio,int Fin)
{
   mciPlayParms.dwFrom=Inicio;
   mciPlayParms.dwTo=Fin;
}

void GDT::Sonido::Musik::InicioEn(int Inicio)
{
   mciPlayParms.dwFrom=Inicio;
}

void GDT::Sonido::Musik::FinEn(int Fin)
{
      mciPlayParms.dwTo=Fin;
}


void GDT::Sonido::Musik::Play()
{
   mciSendCommand(wDeviceID, MCI_PLAY, MCI_FROM|MCI_NOTIFY,(DWORD) &mciPlayParms);
}

void GDT::Sonido::Musik::Play(int Inicio,int Fin)
{

   Inicio_Fin(Inicio,Fin);
   Play();

}

int GDT::Sonido::Musik::Loop()
{
   if(Ejecutando()==false)
      Play();

   return 0;
}

int GDT::Sonido::Musik::Loop(int Inicio, int Fin)
{
   if(Ejecutando()==false)
      Play(Inicio,Fin);

      return 0;
}

void GDT::Sonido::Musik::Stop()
{
   dwReturn = mciSendCommand(wDeviceID, MCI_PLAY, MCI_STOP | MCI_NOTIFY ,(DWORD)(LPVOID) &mciPlayParms);
}

void GDT::Sonido::Musik::Pause()
{
   dwReturn = mciSendCommand(wDeviceID, MCI_PLAY, MCI_PAUSE | MCI_NOTIFY ,(DWORD)(LPVOID) &mciPlayParms);
}

void GDT::Sonido::Musik::Resume()
{
   dwReturn = mciSendCommand(wDeviceID, MCI_PLAY, MCI_RESUME | MCI_NOTIFY ,(DWORD)(LPVOID) &mciPlayParms);
}

int GDT::Sonido::Musik::Posicion()
{
   mciStatusParms.dwItem=MCI_STATUS_POSITION;

   mciSendCommand(wDeviceID, MCI_STATUS, MCI_STATUS_ITEM |MCI_STATUS_POSITION ,(DWORD)(LPVOID) &mciStatusParms);

   return mciStatusParms.dwReturn;
}

void GDT::Sonido::Musik::Volumen(DWORD dwVolumen)
{
   dwVolumen=dwVolumen * 655;

   if(dwVolumen > 65535)
      dwVolumen=65535;

/*
//siempre es falso
   if(dwVolumen < 0)
      dwVolumen=0;
*/
   midiOutSetVolume(hmidiout,dwVolumen);
}

// STATUS **********************************************************************************************

int GDT::Sonido::Musik::VolumenActual()
{
   DWORD dwVolume;
   midiOutGetVolume(hmidiout,&dwVolume);
   return (int) dwVolume;
}

int GDT::Sonido::Musik::TamMIDI()
{
   mciStatusParms.dwItem=MCI_STATUS_LENGTH;

   mciSendCommand(wDeviceID, MCI_STATUS, MCI_STATUS_ITEM ,(DWORD)(LPVOID) &mciStatusParms);

   return mciStatusParms.dwReturn;
}

char* GDT::Sonido::Musik::ArchivoActual()
{
   char* pszArchivo=NULL;
   sprintf(pszArchivo,"%s",lpszArchivoMIDI);

   return pszArchivo;
}

void GDT::Sonido::Musik::DeviceId()
{
      mciGetDeviceID(lpszDevice);
}

bool GDT::Sonido::Musik::Ejecutando()
{

   mciStatusParms.dwItem=MCI_STATUS_MODE;

   mciSendCommand(wDeviceID,MCI_STATUS,
                                       MCI_NOTIFY|MCI_STATUS_ITEM,
                                       (DWORD)(LPMCI_STATUS_PARMS)&mciStatusParms);

   if(mciStatusParms.dwReturn==MCI_MODE_PLAY)
      return true;

   if(mciStatusParms.dwReturn==MCI_MODE_STOP)
      return false;

   return false;
}

int GDT::Sonido::Musik::StatusEjecutando()
{

   mciStatusParms.dwItem=MCI_STATUS_MODE;

   mciSendCommand(wDeviceID,MCI_STATUS,
                                       MCI_NOTIFY|MCI_STATUS_ITEM,
                                       (DWORD)(LPMCI_STATUS_PARMS)&mciStatusParms);

   return mciStatusParms.dwReturn;
}

#endif // WIN32 && _GDT_MIDI_

