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

// Este archivo funciona solo en win32
#ifdef WIN32
#ifndef _GD_MUSIK_H_
#define _GD_MUSIK_H_

#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <string.h>

/**
* Musica Midi (usa la winapi)
*/
class GD_Musik
{
   private:
	HMIDIOUT hmidiout;
	DWORD dwStartVolume;
   public:
	HWND hwnd;
	
	UINT wDeviceID;
	DWORD dwReturn;
	MCI_OPEN_PARMS mciOpenParms;
	MCI_PLAY_PARMS mciPlayParms;
	MCI_STATUS_PARMS mciStatusParms;
	MCI_SET_PARMS mciSetParms;
	MCI_SEQ_SET_PARMS mciSeqSetParms;
	MCI_LOAD_PARMS mciLoadParms;
	MCI_GENERIC_PARMS mciGenericParms;
	
	LPCTSTR lpszDevice;
	
	int length, pos;
	int beats, beat;
	int paused;
	int done;
	
	
	
	HWND hwReturn;
	LPSTR lpszArchivoMIDI;
	
	GD_Musik();
	~GD_Musik();
	bool Iniciar(LPSTR ArchivoMIDI);
	bool Cargar(LPSTR ArchivoMIDI);
	void Destruir();
	void Inicio_Fin(int Inicio,int Fin);
	void InicioEn(int Inicio);
	void FinEn(int Fin);
	void Play();
	void Play(int Inicio,int Fin);
	int Loop();
	int Loop(int Inicio, int Fin);
	void Stop();
	void Pause();
	void Resume();
	int Posicion();
	void Volumen(DWORD dwVolumen);
	// Status
	int VolumenActual();
	bool Ejecutando();
	int TamMIDI();
	char* ArchivoActual();
	void DeviceId();

};

#endif //_GD_MUSIK_H_
// Este archivo funciona solo en win32
#endif
