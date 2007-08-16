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
* \class GDT::Sistema
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

IrrlichtDevice *GDT::Sistema::device=NULL;
int GDT::Sistema::ContadorElementosGui;

//    ICameraSceneNode *camaras_n[3];
//	bool camaras_a[3];
//    irr::core::rect< s32 >  camaras_v[3];

// class constructor
GDT::Sistema::Sistema()
{
	// insert your code here

} 

// class destructor
GDT::Sistema::~Sistema()
{
	// insert your code here
}

/*!
*Parametros:
*
* \param ancho,alto resolucion de
* \param prof de color (16, 24, 32 bits)
* \param full true para Pantalla completa o false para ventana
* \param VideoDriver Modo de dibujado
* \param StencilBuffer Activa o desactiva el Stencil Buffer, requerido para hacer sombras.
* \param Vsync Activa o desactiva Vsync.
*
* VideoDriver puede ser:
* - OPENGL (predeterminado)
* - DIRECTX8
* - DIRECTX9
* - SOFTWARE
* - NULO
*
* Ejemplo 1:
* \code
* // Ventana 640x480 a 16 bits, sin especificar driver (por defecto OPENGL)
* System.Inicializar(640,480,16);
* \endcode
* Ejemplo 2:
* \code
* // Ventana 640x480 a 16 bits, renderizado por SOFTWARE
* System.Inicializar(640,480,16, SOFTWARE);
* \endcode
* Ejemplo 3:
* \code
* // Ventana 640x480 a 16 bits, renderizado por OpenGL, con stencil buffer y vsync activado
* System.Inicializar(640,480,16, OPENGL, true, true);
* \endcode
*/
void GDT::Sistema::Inicializar(int ancho, int alto, int prof, bool full, E_DRIVER_TYPE VideoDriver, bool StencilBuffer, bool Vsync)
	{
	printf("\n+----------+");
	printf("\n| GDT v2.0 |");
	printf("\n+----------+\n");
	// Init the Irrlicht engine

	device = createDevice(VideoDriver, 
           dimension2d<s32>(ancho,alto), 
           prof, 
           full, 
           StencilBuffer, 
           Vsync, 
           this);
	
	if (device==NULL)
    {
       printf("No se Pudo crear el Sistema\n");
       exit(-1);
    };
	
		driver = device->getVideoDriver();
		smgr = device->getSceneManager();
		guienv = device->getGUIEnvironment();
		colin = smgr->getSceneCollisionManager();
	
	device->setWindowCaption(L"GDT Game Developers Toolkit v2.0");
	
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
* \return True si el sistema est&aacute; en ejecuci&oacute;n, en otro caso false.
* 
* Ejemplo:
* \code
* System.EnEjecucion();
* \endcode
*/
bool GDT::Sistema::EnEjecucion()
{
	return device->run();
}

/*!
* Ejemplo:
* \code
* ancho = System.AnchoVentana();
* \endcode
*/
int GDT::Sistema::AnchoVentana()
{
    int tempX;
    tempX = driver->getScreenSize().Width;
    return tempX;
}

/*!
* Ejemplo:
* \code
* vancho = System.AnchoVentana();
* \endcode
*/

int GDT::Sistema::AltoVentana()
{
    int tempY;
    tempY = driver->getScreenSize().Height;
    return tempY;
}


/*!
* \param filename la ruta de la fuente.
* 
* Ejemplo:
* \code
* System.Fuente("media/letras.bmp");
* \endcode
*/
void GDT::Sistema::Fuente(char* filename)
{
 skin->setFont(guienv->getFont(filename));
}

/*!
*/
// lifetree -- to use multi-key and mouse-button
bool GDT::Sistema::OnEvent(SEvent event)
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
       					UltimoDialogoSeleccionado = (IGUIFileOpenDialog*)event.GUIEvent.Caller;
    					ActualizarArchivoSeleccionadoDialogoAbrir(core::stringc(UltimoDialogoSeleccionado->getFilename()).c_str());
                        break;
                    }
                    // Seleccion en Menu
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


bool GDT::Sistema::ClickBoton(int id2)
{
     if(id2 == ultimoIdBotonClick)
        return true;
     else
        return false;
}

/*!
* \param id2 GD_GuiBarra
* 
* Ejemplo:
* \code
* if( System.BarraMovida ( miBarra ) ) {
*     // Aqu&iacute; lo que haga
* }
* \endcode
*/
bool GDT::Sistema::BarraMovida(int id2)
{
     if(id2 == ultimaIdBarraMovida)
     return true;
     else
     return false;
}


const wchar_t* GDT::Sistema::ArchivoSeleccionado(void)
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
* \param index Tecla a determinar si est&aacute; presionada.
* \return true si se est&aacute; presionando la tecla, sino retorna false.
* 
* Las teclas son:
*     - T_ESC
*     - T_FLECHA_IZQUIERDA
*     - T_FLECHA_ARRIBA
*     - T_FLECHA_DERECHA
*     - T_FLECHA_ABAJO
*     - T_TECLA_A
*     - T_TECLA_B
*     - T_TECLA_C
*     - T_TECLA_D
*     - T_TECLA_E
*     - T_TECLA_F
*     - T_TECLA_G
*     - T_TECLA_H
*     - T_TECLA_I
*     - T_TECLA_J
*     - T_TECLA_K
*     - T_TECLA_L
*     - T_TECLA_M
*     - T_TECLA_N
*     - T_TECLA_O
*     - T_TECLA_P
*     - T_TECLA_Q
*     - T_TECLA_R
*     - T_TECLA_S
*     - T_TECLA_T
*     - T_TECLA_U
*     - T_TECLA_V
*     - T_TECLA_W
*     - T_TECLA_X
*     - T_TECLA_Y
*     - T_TECLA_Z
*     - T_F1
*     - T_F2
*     - T_F3
*     - T_F4
*     - T_F5
*     - T_F6
*     - T_F7
*     - T_F8
*     - T_F9
*     - T_F10
*     - T_F11
*     - T_F12
*     - T_TECLA_0
*     - T_TECLA_1
*     - T_TECLA_2
*     - T_TECLA_3
*     - T_TECLA_4
*     - T_TECLA_5
*     - T_TECLA_6
*     - T_TECLA_7
*     - T_TECLA_8
*     - T_TECLA_9
*     - T_BACKSPACE
*     - T_TAB
*     - T_ENTER
*     - T_SHIFT
*     - T_CONTROL
*     - T_ALT
*     - T_PAUSE
*     - T_CAPSLOCK
*     - T_ESPACIO
*     - T_PAGE_UP
*     - T_PAGE_DOWN
*     - T_END
*     - T_HOME
*     - T_NUMPAD_0
*     - T_NUMPAD_1
*     - T_NUMPAD_2
*     - T_NUMPAD_3
*     - T_NUMPAD_4
*     - T_NUMPAD_5
*     - T_NUMPAD_6
*     - T_NUMPAD_7
*     - T_NUMPAD_8
*     - T_NUMPAD_9
* 
* Ejemplo:
* \code
* if( System.TeclaAbajo( T_ESC ) ) {
*     // Ac&aacute; lo que haga
* }
* \endcode
*/
bool GDT::Sistema::TeclaAbajo(int index)
{
     return m_key_buf[index];
}

/*!
*/
bool GDT::Sistema::TeclaPulsada(int index)
{
  if(m_key_buf[index] && m_key_buf_old[index] != m_key_buf[index])
       return true;
  else
       return false;
}

bool GDT::Sistema::MouseBotonAbajo(int index)
{
return m_mouse_button_buf[index];
}

bool GDT::Sistema::MouseBotonArribaAbajo(int index)
{
return (m_mouse_button_buf[index] && !m_mouse_button_buf_old[index]);
}

bool GDT::Sistema::MouseBotonAbajoArriba(int index)
{
return (!m_mouse_button_buf[index] && m_mouse_button_buf_old[index]);
}


/*!
* Para generar la animaci&oacute;n este m&eacute;todo debe ser llamado
* tan seguido como sea posible.
*
* Es por esto que suele usarse dentro de un ciclo principal, de tal modo
* que los cambios que ocurran de un cuadro a otro sean visibles.
*/
void GDT::Sistema::Render()
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
Se usa cuando se quiere terminar la aplicaci&oacute;n. En versiones anteriores a la 1.3.5 se llamaba System.Matarme()

Ejemplo:
\code
System.Finalizar();
\endcode
*/
void GDT::Sistema::Finalizar()
{
     device->closeDevice();
}

/*!
\deprecated Use Finalizar() en su lugar
*/
void GDT::Sistema::Matarme()
{
     Finalizar();
}

/*!
* Ejemplo:
* \code
* System.TituloVentana("Mi primera aplicaci&oacute;n en GDT");
* \endcode
*/
void GDT::Sistema::TituloVentana(wchar_t* textoso)
{
     device->setWindowCaption(textoso);
}

IrrlichtDevice* GDT::Sistema::RetornarDevice()
{
    return device;
}

/*!
* Ejemplo:
* \code
* FPS = System.RetornarCPS();
* \endcode
*/
int GDT::Sistema::RetornarCPS()
{
    return _CPS;
}

/*!
* Ejemplo:
* \code
* NumPoly = System.RetornarTriangulos();
* \endcode
*/
int GDT::Sistema::RetornarTriangulos()
{
    return Triangulos;
}

void GDT::Sistema::RenderizarSoloConVentanaActiva(bool activa)
{
    _RenderVentana = activa;
}

void GDT::Sistema::VentanaEscalable(bool escalable)
{
    _VentanaEscalable = escalable;
    device->setResizeAble(escalable);
}

/*!
* Ejemplo:
* \code
* System.ColorFondo(200,255,0):
* \endcode
*/
void GDT::Sistema::ColorFondo(int r,int g,int b)
{
    cfa = 0;
    cfr = r;
    cfg = g;
    cfb = b;
}

void GDT::Sistema::LimiteCPS(int lcps)
{
    cps_deseados=lcps;
}

/*!
*/
void GDT::Sistema::Dormir(int milisecs)
{
       u32 curTime = device->getTimer()->getTime();

       while(device->getTimer()->getTime() < curTime + milisecs){
               device->getTimer()->tick();
       }
}

/*!
* \return el n&uacute;mero de la &uacute;ltima tecla precionada.
*
* \author Astucia
* \since 13-04-2006
*/
int GDT::Sistema::TeclaPrecionada()
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
/*!
*/
void GDT::Sistema::MousePosicionar(int X,int Y)
{
   //Estructura de tipo coordenada.
   position2d<s32> Pos;
   //Asignacion de valores a las variables de la estructura
   Pos.X=X; Pos.Y=Y;
   //Moviendo el cursor.
   device->getCursorControl()->setPosition(Pos);
}

/*!
*/
int GDT::Sistema::MousePosicionX(){
   //Crea la estructura MousePosX y obtiene el valor del tipo coordenada
   position2d<s32> MousePosX = device->getCursorControl()->getPosition();
   //Asigna el valor de la coordenada X
   return MousePosX.X;
}

/*!
*/
int GDT::Sistema::MousePosicionY(){
   //Crea la estructura MousePosY y obtiene el valor del tipo coordenada
   position2d<s32> MousePosY = device->getCursorControl()->getPosition();
   //Asigna el valor de la coordenada Y
   return MousePosY.Y;
}

/*!
*/
f32 GDT::Sistema::MouseMovimientoX(f32 sensibilidad){

   f32 posY;
   //Obtiene la posicion relativa acutal del mouse X
   position2d<f32> MousePos = device->getCursorControl()->getRelativePosition();
   posY= MousePos.Y; //MousePosicionX();
   device->getCursorControl()->setPosition(0.5f,posY ); //centrar posicion
   return (MousePos.X-0.5f) * sensibilidad;

}

/*!
*/
f32 GDT::Sistema::MouseMovimientoY(f32 sensibilidad){
    f32 posX;
   //Obtiene la posicion relativa acutal del mouse X
   position2d<f32> MousePos = device->getCursorControl()->getRelativePosition();
   posX= MousePos.X; //MousePosicionX();
   device->getCursorControl()->setPosition(posX, 0.5f); //centrar posicion en y
   return (MousePos.Y-0.5f) * sensibilidad;

}

/*!
*/
void GDT::Sistema::OcultarPuntero()
{
   device->getCursorControl()->setVisible(false);
}

/*!
*/
void GDT::Sistema::ColorSombra(int R, int G, int B)
{
     sR = R;
     sG = G;
     sB = B;

   smgr->setShadowColor(video::SColor(sT,R,G,B));
}

/*!
*/
void GDT::Sistema::TranslucidezSombra(int T)
{
   sT = T;
   smgr->setShadowColor(video::SColor(T,sR,sG,sB));
}

/*!
*/
void GDT::Sistema::ConfigurarNiebla(int r, int g, int  b, bool lineal, float inicio, float fin,float densidad)
{
     driver->setFog(SColor(0, r, g, b), lineal, inicio, fin, densidad, false, false);
}

/*!
* Depende de varios otros hechos, como por ejemplo haber detenido el tiempo 
* del sistema en algun punto, o cambiar la rapidez del Reloj.
* 
* Para Obtener el tiempo completo, ocupe Milisegundos()
*/
int GDT::Sistema::MilisegundosSistema()
{
   int milsc = device->getTimer()->getTime();
   return milsc;
}

/*!
* Esta funcion es independiente de cualquier interrupci&oacute;n del Timer, excepto
* al reiniciar el Reloj con ReiniciarReloj()
*/
int GDT::Sistema::Milisegundos()
{
    milsc_act = device->getTimer()->getRealTime() - milsc_ini;
    return milsc_act;
}

/*!
* As&iacute; la diferencia el tiempo de ejecuci&oacute;n se reinicia a 0 en adelante.
*/
void GDT::Sistema::ReiniciarReloj()
{
   milsc_ini = device->getTimer()->getRealTime();
}

/*!
*/
void GDT::Sistema::CambiarDirectorio(const char *strDir)
{
     device->getFileSystem()->changeWorkingDirectoryTo(strDir);
}

/*!
*/
const char *GDT::Sistema::Directorio(void)
{
      return device->getFileSystem()->getWorkingDirectory();
}

/*!
*/
bool GDT::Sistema::ArchivoExiste(const char *strArchivo)
{
     return device->getFileSystem()->existFile(strArchivo);
}

/*!
*/
void GDT::Sistema::CargarEscena(char* file)
{
     smgr->loadScene(file);
}

/*!
*/
void GDT::Sistema::GuardarEscena(char* file)
{
     smgr->saveScene(file);
}

/*!
*/
void GDT::Sistema::ActivarCamara(  ICameraSceneNode* cam )//Camara cam )
{
     smgr->setActiveCamera( cam );
}

/*!
*/
void GDT::Sistema::AreaRenderizado(int x1, int y1, int x2, int y2)
{
     driver->setViewPort(rect<s32>(x1,y1,x2,y2));
}

/*!
*/
void GDT::Sistema::Limpiar()
{
     smgr->clear();
}

/*!
*/
void GDT::Sistema::ActualizarArchivoSeleccionadoDialogoAbrir(const c8* fn)
{
	strcpy(RutaArchivoSeleccionado, fn);
}

/*!
*/
void GDT::Sistema::TransparenciaGUI(int valor)
{     
    for (s32 i=0; i<EGDC_COUNT ; ++i)
    {
        SColor col = guienv->getSkin()->getColor((EGUI_DEFAULT_COLOR)i);
        col.setAlpha(valor);
        guienv->getSkin()->setColor((EGUI_DEFAULT_COLOR)i, col);

    }
}
