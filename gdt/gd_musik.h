#ifndef _GD_MUSIK_H_
#define _GD_MUSIK_H_

// Este archivo funciona solo en win32
#ifdef WIN32
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <string.h>


#define MUSIK_NOT_READY MCI_MODE_NOT_READY
#define MUSIK_PAUSE     MCI_MODE_PAUSE
#define MUSIK_PLAY      MCI_MODE_PLAY
#define MUSIK_STOP      MCI_MODE_STOP
#define MUSIK_OPEN      MCI_MODE_OPEN
#define MUSIK_RECORD    MCI_MODE_RECORD
#define MUSIK_SEEK      MCI_MODE_SEEK



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
	int StatusEjecutando();
	int TamMIDI();
	char* ArchivoActual();
	void DeviceId();


};

#endif //_GD_MUSIK_H_

// Este archivo funciona solo en win32
#endif

