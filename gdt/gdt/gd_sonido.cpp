// Class automatically generated by Dev-C++ New Class wizard

#include "gd_sonido.h" // class's header file

// class constructor
GD_Sonido::GD_Sonido()
{
	// insert your code here
}

// class destructor
GD_Sonido::~GD_Sonido()
{
	// insert your code here
}



char GD_Sonido::Cargar(char *archivo)
{
    Cargar(archivo);
    RelativoOyente(1);
    Posicionar(0.0 , 0.0 , 0.1);
    return 0;
}

void GD_Sonido::Descargar()
{
    Descargar();
}

void GD_Sonido::Reproducir()
{
    Reproducir();
}

void GD_Sonido::Pausa()
{
    Pausa();
}

void GD_Sonido::Detener()
{
    Detener();
}

void GD_Sonido::Rebobinar()
{
    Rebobinar();
}

void GD_Sonido::Play()
{
    Play();
}

void GD_Sonido::Pause()
{
    Pause();
}

void GD_Sonido::Stop()
{
    Stop();
}

void GD_Sonido::Rewind()
{
    Rewind();
}
void GD_Sonido::Bucle(char loop)
{
    Bucle(loop);
}

void GD_Sonido::Pan(float p)
{
   Posicionar(p , 0.0 , 0.1);
}

void GD_Sonido::Tono(float t)
{
   Tono(t);
}

int GD_Sonido::Estado()
{
    //0 esta sonando , 1 esta en pausa, 2 esta parado, cualquier otra cosa es fallo
    return Estado();
}
void GD_Sonido::Volumen(int vol)
{
   float rvol;
   if(vol<0)
   {
      vol=0;
   }
   rvol=(float)vol/100.0;
   //Posicion(0.0,0.0,0.0-rvol);
   //ReferenciaDistancia(rvol);
   VolumenMaximo(rvol);
}
