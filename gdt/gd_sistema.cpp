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

/*!\mainpage

\image html logoGDT.png

\section intro Manual de Referencia
Bienvenido a la documentaci&oacute;n de GDT.

Ac&aacute; encontrar&aacute; los detalles de todas las Clases, Propiedades, M&eacute;todos y Definiciones. En la mayor&iacute;a encontrar&aacute;s las definiciones de los par&aacute;metros, el prop&oacute;sito de cada m&eacute;todo y en ocaciones un ejemplos de su uso.

<A HREF="refman.pdf">Ac&aacute; puede encontrar una copia descargable en formato PDF</A>

\section comenzando Comenzando con un esqueleto GDT
Para comenzar, los novatos pueden preferir ocupar una versi&oacute;n 
precompilada de GDT.

Luego, para probar la instalaci&oacute;n, puede ocupar el siguiente programa esqueleto:

\code
#include <gdt.h>

GD_Sistema Sistema;

int main()
{
        Sistema.Inicializar(640,480,16,false,OPENGL);

        GD_Camara Camara;
        Camara.Crear(Tipo_Modelador );

        while(Sistema.EnEjecucion())
        {
                // Cerrar programa con tecla ESC
                if(Sistema.TeclaAbajo(T_ESC)) Sistema.Matarme();

                //Dibujar contenido de la ventana 
                Sistema.Render();
        }

        Sistema.Matarme();

        return 0;
}
\endcode

Para enlazar correctamente con las librer&iacute;as externas, recuerda que se necesitan:

- gdt
- Irrlicht

Y opcionalmente:
- openal
- alut
- ogg
- vorvis
- vorbisenc
- vorbisfile
- lua5.1
- ode
- Newton // No incluído con GDT en ninguna versi&oacute;n.

Dependiendo del compilador y plataforma, el enlazado se configura de diferentes maneras.

\section important Si desea compilar GDT, concidere que...

Antes, era necesario instalar toda las dependencias. Ahora se pueden ocupar
las mismas, pero ya no son todas obligatorias.

En el caso de que no se requiera, o aparezcan problemas, tal vez desee compilar
GDT con menos caracter&iacute;sticas.

Para esto, se han establecido algunas definicione para el preprocesador que permiten 
Compilar:

    - _GDT_SONIDO_ // Incluye soporte para tocar sonido usando Openal + Alut
    - _GDT_SONIDO_OGG_ // Incluye soporte para decodificar OGG + Vorbis. NO sirve de nada si no se define _GDT_SONIDO_.
    - _GDT_MIDI_ // Incluye soporte para tocar sonidos Midi. Este m&oacutelo requiere la WINAPI. Viene desactivado en Linux (por razones obvias) y en MS Visual C++ 2005 Express. En este &uacute;ltimo porque necesita tener instalado el Platform SDK previamente. Si desea usar Midi en MSVC, entonces asegurese de tener el PSDK instalado, y luego agregar esta definici&oacute;n en su proyecto.
    - _GDT_SCRIPTING_ // LUA
    - _GDT_FISICAS_NEWTON_ // Newton Dynamics, desactivado en forma predeterminada
    - _GDT_FISICAS_ODE_ // NO implementado aun, pero irá a futuro.

\section evitar Lo que debe evitar:

Por favor, para no tener problemas, no intente:

- Definir _GDT_DOXYGEN_IGNORAR_. Se ha puesto en ciertas partes del c&oacute;digo fuente, para evitar que aparezca en la documentaci&oacute;n algunas cosas que no son necesarias mostrar. Cuando se define _GDT_DOXYGEN_IGNORAR_ el compilador ignorar&aacute; partes que SI SON NECESARIAS PARA COMPILAR.

- Compilar GDT sin haber instalado Irrlicht. Es la principal dependencia de GDT, ya que provee el motor gr&aacute;fico y la base de muchas otras cosas necesarias. Para mayor informaci&oacute;n lea el siguiente punto.

- Compilar GDT con m&oacute;dulos opcionales si sus dependencias no est&aacute; instaladas, o no est&aacute; disponibles. Aseg&uacute;rese que las cabeceras (.h) de las dependencias est&eacute;n disponibles en algun directorio de inclusi&oacute;n o agregar rutas adicionales, donde se tienen instaladas, al proyecto del IDE escogido.

- Usar una caracter&iacute;stica de GDT en un proyecto propio si GDT no fue compilado con ese soporte. En el mejor de los casos provocar&aacute; inevitablemente una caida del ejecutable. De echo es m&aacute;s probable que ni siquiera deje compilar/enlazar correctamente el proyecto.
*/

/*!
* \class GD_Sistema
*
* Todo depende del Sistema, desde las funciones b&aacute;sicas de entrada
* y salida hasta el control de los nodos y dibujado, incluyendo los 
* c&aacute;lculos 3D necesarios.
*
* Al inicializar el sistema, se generar&aacute; una ventana con un 
* viewport de las dimenciones dadas.
*
* Si lo desea, este viewport puede ser en modo ventana o a pantalla
* completa, y ocupando el modo que desee (OpenGL, DirectX, Software)
*
* Tambi&eacute;n puede en algunos casos si lo desea ocupar un modo de 
* dibujado NULL, de esta manera no se necesita dibujar por pantalla todo
* lo que ocurre. Este modo puede ser &uacute;til para programar un servicio
* compatible con las capacidades de Irrlicht, por ejemplo un servidor para
* un juego en linea.
*
* El Sistema tambi&eacute;n puede ofrecer informaci&oacute;n &uacute;til
* sobre el estado actual de la ejecuci&oacute;n del programa, como los Cuadros
* dibujados por cada segundo (CPS, o FPS en ingl&eacute;s).
*
* Los M&eacute;todos de Entrada-Salida nos permiten acceder a eventos del 
* sistema, como por ejemplo si se ha presionado una tecla.
*/

#include "gd_sistema.h" // class's header file

IrrlichtDevice *GD_Sistema::device=NULL;
int GD_Sistema::ContadorElementosGui;

//    ICameraSceneNode *camaras_n[3];
//	bool camaras_a[3];
//    irr::core::rect< s32 >  camaras_v[3];

// class constructor
GD_Sistema::GD_Sistema()
{
	// insert your code here

} 

// class destructor
GD_Sistema::~GD_Sistema()
{
	// insert your code here
}

/*!
Parametros:

\param ancho,alto resolucion de
\param prof de color (16, 24, 32 bits)
\param full true para Pantalla completa o false para ventana
\param VideoDriver Modo de dibujado
\param StencilBuffer Activa o desactiva el Stencil Buffer, requerido para hacer sombras.
\param Vsync Activa o desactiva Vsync.

VideoDriver puede ser:
 - OPENGL (predeterminado)
 - DIRECTX8
 - DIRECTX9
 - SOFTWARE
 - NULO

Ejemplo 1:
\code
// Ventana 640x480 a 16 bits, sin especificar driver (por defecto OPENGL)
Sistema.Inicializar(640,480,16);
\endcode
Ejemplo 2:
\code
// Ventana 640x480 a 16 bits, renderizado por SOFTWARE
Sistema.Inicializar(640,480,16, SOFTWARE);
\endcode
Ejemplo 3:
\code
// Ventana 640x480 a 16 bits, renderizado por OpenGL, con stencil buffer y vsync activado
Sistema.Inicializar(640,480,16, OPENGL, true, true);
\endcode
*/
void GD_Sistema::Inicializar(int ancho, int alto, int prof, bool full, E_DRIVER_TYPE VideoDriver, bool StencilBuffer, bool Vsync)
	{
	printf("\n+-----------------+------------+");
	printf("\n|GDT v1.3.4-BETA3 | 10.10.2007 |");
	printf("\n+-----------------+------------+\n");
	// Init the Irrlicht engine

	device = createDevice(VideoDriver, dimension2d<s32>(ancho,alto), prof, full, StencilBuffer,Vsync, this);
	
	if(device==NULL) printf("No se Pudo crear el Sistema\n");
	
		driver = device->getVideoDriver();
		smgr = device->getSceneManager();
		guienv = device->getGUIEnvironment();
		colin = smgr->getSceneCollisionManager();
	
	device->setWindowCaption(L"GDT Game Developers Toolkit v1.3.4-BETA3");
	
	skin = guienv->getSkin();
	//skin->setFont(guienv->getFont("fuente_default.bmp"));
	/*
	memset(m_key_buf, 0, 256);
	memset(m_key_buf_old, 0, 256);
	memset(a_key, 0, 256);
	memset(a_key_old, 0, 256);
	memset(m_mouse_button_buf, 0, 3);
	memset(m_mouse_button_buf_old, 0, 3);
	*/
	
	creadoX = ancho;
	creadoY = alto;
	
	/*  device->getTimer()->start();
	device->getTimer()->tick();*/
	milsc_ini = device->getTimer()->getRealTime();
	
	cfa = 0;
	cfr = 130;
	cfg = 60;
	cfb = 150;
	
	ContadorElementosGui=10;
	lasttick = 0;
	cps_deseados=10000;
	
	sR = 0;
	sG = 0;
	sB = 0;
	sT = 100;
	
	ultimatecla=0;
	
}

/*!
\return True si el sistema est&aacute; en ejecuci&oacute;n, en otro caso false.

Ejemplo:
\code
Sistema.EnEjecucion();
\endcode
*/
bool GD_Sistema::EnEjecucion()
{
	return device->run();
}

/*!
Ejemplo:
\code
ancho = Sistema.AnchoVentana();
\endcode
*/
int GD_Sistema::AnchoVentana()
{
    int tempX;
    tempX = driver->getScreenSize().Width;
    return tempX;
}

/*!
Ejemplo:
\code
ancho = Sistema.AnchoVentana();
\endcode
*/

int GD_Sistema::AltoVentana()
{
    int tempY;
    tempY = driver->getScreenSize().Height;
    return tempY;
}


/*!
\param filename la ruta de la fuente.

Ejemplo:
\code
Sistema.Fuente("media/letras.bmp");
\endcode
*/
void GD_Sistema::Fuente(char* filename)
{
 skin->setFont(guienv->getFont(filename));
}

/**
Maneja los eventos

*/
// lifetree -- to use multi-key and mouse-button
bool GD_Sistema::OnEvent(SEvent event)
{

     switch(event.EventType)
     {
          case EET_KEY_INPUT_EVENT:
               m_key_buf_old[event.KeyInput.Key] = m_key_buf[event.KeyInput.Key];

               m_key_buf[event.KeyInput.Key] = event.KeyInput.PressedDown;

               ultimatecla=event.KeyInput.Key;
            //   if(!event.KeyInput.PressedDown)  m_key_buf_old[event.KeyInput.Key] = 0;
 
          break;
          case EET_MOUSE_INPUT_EVENT:
               if (event.MouseInput.Event < EMIE_MOUSE_MOVED)
               {
                    m_mouse_button_buf_old[event.MouseInput.Event%3] = m_mouse_button_buf[event.MouseInput.Event%3];
                    m_mouse_button_buf[event.MouseInput.Event%3] = ((event.MouseInput.Event/3)?false:true);
               }
          break;
          case EET_GUI_EVENT:
               s32 id = event.GUIEvent.Caller->getID();
			switch(event.GUIEvent.EventType)
			{
                    // Bot?
                	case EGET_BUTTON_CLICKED:
                    {
                         ultimoIdBotonClick = id;
                         break;
                    }

                    // Barra  cambiada
                    case EGET_SCROLL_BAR_CHANGED:
                    {
                         ultimaIdBarraMovida = id;
                         ultimaBarraPosicion = ((IGUIScrollBar*)event.GUIEvent.Caller)->getPos();
                         break;
                    }
                    // DialogoAbrir Archivo Seleccionado
                    case EGET_FILE_SELECTED:
                    {
                         dialogoArchivoSeleccionado = true;
                         NombreArchivoSeleccionado = ((IGUIFileOpenDialog*)event.GUIEvent.Caller)->getFilename();
                         break;
                    }
                    // Selecci? en Menu
                    case EGET_MENU_ITEM_SELECTED:
                    {
                         IGUIContextMenu* menu = (IGUIContextMenu*)event.GUIEvent.Caller;
					     s32 id = menu->getItemCommandId(menu->getSelectedItem());

                         MenuOpcionSeleccionada = id;
                    }

                return true;
               }

          break;
     }

return false;
}


bool GD_Sistema::ClickBoton(int id2)
{
     if(id2 == ultimoIdBotonClick)
        return true;
     else
        return false;
}

/*!
\param id2 GD_GuiBarra

Ejemplo:
\code
if( Sistema.BarraMovida ( miBarra ) ) {
    // Aqu&iacute; lo que haga
}
\endcode
*/
bool GD_Sistema::BarraMovida(int id2)
{
     if(id2 == ultimaIdBarraMovida)
     return true;
     else
     return false;
}


const wchar_t* GD_Sistema::ArchivoSeleccionado(void)
{
      if(dialogoArchivoSeleccionado == true)
      { 
         dialogoArchivoSeleccionado = false;
         return NombreArchivoSeleccionado;
      }
      else
          return NULL;
      
}

/*!
\param index Tecla a determinar si est&aacute; presionada.

Las teclas son:
    - T_ESC
    - T_FLECHA_IZQUIERDA
    - T_FLECHA_ARRIBA
    - T_FLECHA_DERECHA
    - T_FLECHA_ABAJO
    - T_TECLA_A
    - T_TECLA_B
    - T_TECLA_C
    - T_TECLA_D
    - T_TECLA_E
    - T_TECLA_F
    - T_TECLA_G
    - T_TECLA_H
    - T_TECLA_I
    - T_TECLA_J
    - T_TECLA_K
    - T_TECLA_L
    - T_TECLA_M
    - T_TECLA_N
    - T_TECLA_O
    - T_TECLA_P
    - T_TECLA_Q
    - T_TECLA_R
    - T_TECLA_S
    - T_TECLA_T
    - T_TECLA_U
    - T_TECLA_V
    - T_TECLA_W
    - T_TECLA_X
    - T_TECLA_Y
    - T_TECLA_Z
    - T_F1
    - T_F2
    - T_F3
    - T_F4
    - T_F5
    - T_F6
    - T_F7
    - T_F8
    - T_F9
    - T_F10
    - T_F11
    - T_F12
    - T_TECLA_0
    - T_TECLA_1
    - T_TECLA_2
    - T_TECLA_3
    - T_TECLA_4
    - T_TECLA_5
    - T_TECLA_6
    - T_TECLA_7
    - T_TECLA_8
    - T_TECLA_9
    - T_BACKSPACE
    - T_TAB
    - T_ENTER
    - T_SHIFT
    - T_CONTROL
    - T_ALT
    - T_PAUSE
    - T_CAPSLOCK
    - T_ESPACIO
    - T_PAGE_UP
    - T_PAGE_DOWN
    - T_END
    - T_HOME
    - T_NUMPAD_0
    - T_NUMPAD_1
    - T_NUMPAD_2
    - T_NUMPAD_3
    - T_NUMPAD_4
    - T_NUMPAD_5
    - T_NUMPAD_6
    - T_NUMPAD_7
    - T_NUMPAD_8
    - T_NUMPAD_9

Ejemplo:
\code
if( Sistema.TeclaAbajo( T_ESC ) ) {
    // Ac&aacute; lo que haga
}
\endcode
*/
bool GD_Sistema::TeclaAbajo(int index)
{
return m_key_buf[index];
}


bool GD_Sistema::TeclaPulsada(int index)
{  
    
   
     if(m_key_buf[index] && m_key_buf_old[index] != m_key_buf[index])
          return true;
     else
          return false;
          

}

bool GD_Sistema::MouseBotonAbajo(int index)
{
return m_mouse_button_buf[index];
}

bool GD_Sistema::MouseBotonArribaAbajo(int index)
{
return (m_mouse_button_buf[index] && !m_mouse_button_buf_old[index]);
}

bool GD_Sistema::MouseBotonAbajoArriba(int index)
{
return (!m_mouse_button_buf[index] && m_mouse_button_buf_old[index]);
}


/**
Renderiza todo el sistema
*/
void GD_Sistema::Render()
{


    u32 curTime = device->getTimer()->getTime();
 

    while(device->getTimer()->getTime() < curTime + (1000.00f/cps_deseados)){
//        printf("SKIP -> %d < %d \n",device->getTimer()->getTime(),curTime + 3);
        device->getTimer()->tick();
    }

 

            if(_RenderVentana){
                     if(device->isWindowActive())
                     {



                	        driver->beginScene(true, true, video::SColor(cfa,cfr,cfg,cfb));

                            smgr->drawAll();
                            guienv->drawAll();

                            driver->endScene();
                     }
            }
            else
            {
                            driver->beginScene(true, true, video::SColor(cfa,cfr,cfg,cfb));

                            smgr->drawAll();
                            guienv->drawAll();

                            driver->endScene();
            }

                            int fps = driver->getFPS();

                        	if (lastFPS != fps)
                        	{
                        		//wchar_t tmp[1024];
                        		//swprintf(tmp, 1024, L" [fps:%d] [triangulos:%d]", fps, driver->getPrimitiveCountDrawn());
                        		//device->setWindowCaption(tmp);
                        		Triangulos = driver->getPrimitiveCountDrawn();
                        		lastFPS = fps;
                        		_CPS = fps;
                        	}


                        	// Actulaliza
                        	ultimoIdBotonClick=-1;
                        	ultimaIdBarraMovida=-1;
                        	MenuOpcionSeleccionada=-1;
                        	
                       	m_key_buf_old[ultimatecla] = TeclaAbajo(ultimatecla);




}



/*!
Se usa cuando se quiere terminar la aplicaci&oacute;n

Ejemplo:
\code
Sistema.Matarme();
\endcode
*/
void GD_Sistema::Matarme()
{
device->closeDevice();
}

/*!
Ejemplo:
\code
Sistema.TituloVentana("Mi primera aplicaci&oacute;n en GDT");
\endcode
*/
void GD_Sistema::TituloVentana(wchar_t* textoso)
{
     device->setWindowCaption(textoso);
}

IrrlichtDevice* GD_Sistema::RetornarDevice()
{
    return device;
}

/*!
Ejemplo:
\code
FPS = Sistema.RetornarCPS();
\endcode
*/
int GD_Sistema::RetornarCPS()
{
    return _CPS;
}

/*!
Ejemplo:
\code
NumPoly = Sistema.RetornarTriangulos();
\endcode
*/
int GD_Sistema::RetornarTriangulos()
{
    return Triangulos;
}

void GD_Sistema::RenderizarSoloConVentanaActiva(bool activa)
{
    _RenderVentana = activa;
}

void GD_Sistema::VentanaEscalable(bool escalable)
{
    _VentanaEscalable = escalable;
    device->setResizeAble(escalable);
}

/*!
Ejemplo:
\code
Sistema.ColorFondo(200,255,0):
\endcode
*/
void GD_Sistema::ColorFondo(int r,int g,int b)
{
    cfa = 0;
    cfr = r;
    cfg = g;
    cfb = b;
}

void GD_Sistema::LimiteCPS(int lcps)
{
    cps_deseados=lcps;
}


void GD_Sistema::Dormir(int milisecs)
{
       u32 curTime = device->getTimer()->getTime();

       while(device->getTimer()->getTime() < curTime + milisecs){
               device->getTimer()->tick();
       }
}

int GD_Sistema::TeclaPrecionada() //A?dido por Astucia 13-04-2006
{
   int iTecla;
   for(iTecla=0;iTecla<=256;iTecla++)
   {
      if(m_key_buf[iTecla]!=0)
         return iTecla;
   }
   return 0;
}

// MOUSE ***********************************************************
// Posiciona el cursor en algun punto de la pantalla.
void GD_Sistema::MousePosicionar(int X,int Y)
{
   //Estructura de tipo coordenada.
   position2d<s32> Pos;
   //Asignacion de valores a las variables de la estructura
   Pos.X=X; Pos.Y=Y;
   //Moviendo el cursor.
   device->getCursorControl()->setPosition(Pos);
}

int GD_Sistema::MousePosicionX(){
   //Crea la estructura MousePosX y obtiene el valor del tipo coordenada
   position2d<s32> MousePosX = device->getCursorControl()->getPosition();
   //Asigna el valor de la coordenada X
   return MousePosX.X;
}

int GD_Sistema::MousePosicionY(){
   //Crea la estructura MousePosY y obtiene el valor del tipo coordenada
   position2d<s32> MousePosY = device->getCursorControl()->getPosition();
   //Asigna el valor de la coordenada Y
   return MousePosY.Y;
}

f32 GD_Sistema::MouseMovimientoX(f32 sensibilidad){

   f32 posY;
   //Obtiene la posicion relativa acutal del mouse X
   position2d<f32> MousePos = device->getCursorControl()->getRelativePosition();
   posY= MousePos.Y; //MousePosicionX();
   device->getCursorControl()->setPosition(0.5f,posY ); //centrar posicion
   return (MousePos.X-0.5f) * sensibilidad;

}

f32 GD_Sistema::MouseMovimientoY(f32 sensibilidad){
    f32 posX;
   //Obtiene la posicion relativa acutal del mouse X
   position2d<f32> MousePos = device->getCursorControl()->getRelativePosition();
   posX= MousePos.X; //MousePosicionX();
   device->getCursorControl()->setPosition(posX, 0.5f); //centrar posicion en y
   return (MousePos.Y-0.5f) * sensibilidad;

}

void GD_Sistema::OcultarPuntero()
{
   device->getCursorControl()->setVisible(false);
}

void GD_Sistema::ColorSombra(int R, int G, int B)
{
     sR = R;
     sG = G;
     sB = B;

   smgr->setShadowColor(video::SColor(sT,R,G,B));
}

void GD_Sistema::TranslucidezSombra(int T)
{
   sT = T;
   smgr->setShadowColor(video::SColor(T,sR,sG,sB));
}


void GD_Sistema::ConfigurarNiebla(int r, int g, int  b, bool lineal, float inicio, float fin,float densidad)
{
     driver->setFog(SColor(0, r, g, b), lineal, inicio, fin, densidad, false, false);
}

/*!
Depende de varios otros hechos, como por ejemplo haber detenido el tiempo del sistema en algun punto, o cambiar la rapidez del Reloj.

Para Obtener el tiempo completo, ocupe Milisegundos()
*/
int GD_Sistema::MilisegundosSistema()
{
   int milsc = device->getTimer()->getTime();
   return milsc;
}

/*!
Esta funcion es independiente de cualquier interrupci&oacute;n del Timer, excepto al reiniciar el Reloj con ReiniciarReloj()
*/
int GD_Sistema::Milisegundos()
{
    milsc_act = device->getTimer()->getRealTime() - milsc_ini;
    return milsc_act;
}

/*!
As&iacute; la diferencia el tiempo de ejecuci&oacute;n se reinicia a 0 en adelante.
*/
void GD_Sistema::ReiniciarReloj()
{
   milsc_ini = device->getTimer()->getRealTime();
}

/*!

*/
void GD_Sistema::CambiarDirectorio(const char *strDir)
{
     device->getFileSystem()->changeWorkingDirectoryTo(strDir);
}

const char *GD_Sistema::Directorio(void)
{
      return device->getFileSystem()->getWorkingDirectory();
}

bool GD_Sistema::ArchivoExiste(const char *strArchivo)
{
     return device->getFileSystem()->existFile(strArchivo);
}

void GD_Sistema::CargarEscena(char* file)
{
     smgr->loadScene(file);
}

void GD_Sistema::GuardarEscena(char* file)
{
     smgr->saveScene(file);
}

void GD_Sistema::ActivarCamara(  ICameraSceneNode* cam )//GD_Camara cam )
{
     smgr->setActiveCamera( cam );
}

void GD_Sistema::AreaRenderizado(int x1, int y1, int x2, int y2)
{
     driver->setViewPort(rect<s32>(x1,y1,x2,y2));
}

void GD_Sistema::Limpiar()
{
     smgr->clear();
}
