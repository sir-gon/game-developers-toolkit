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

#include "gd_sistema.h" // class's header file

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

//! Inicializa el sistema
/**
Parametros:

    ancho,alto,prof => resolucion
    fullscreen => true o false
    Driver => OPENGL DIRECTX8 DIRECTX9 SOFTWARE

*/
void GD_Sistema::Inicializar(int ancho, int alto, int prof, bool full=false, E_DRIVER_TYPE VideoDriver)
{
     printf("\n        ---------------------- \n-------| GDT v1.1.3..11.08.06 |-------\n        ---------------------- \n\n\n");

	// Init the Irrlicht engine

	device = createDevice(VideoDriver, dimension2d<s32>(ancho,alto), prof, full, true,true, this);

	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
	guienv = device->getGUIEnvironment();
	colin = smgr->getSceneCollisionManager();

     device->setWindowCaption(L"GDT Game Developers Toolkit v1.1.3");

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

/**
Devuelve true o false segun si el sistema esta ejecutandoce

*/
bool GD_Sistema::EnEjecucion()
{
	return device->run();
}


int GD_Sistema::AnchoVentana()
{
    int tempX;
    tempX = driver->getScreenSize().Width;
    return tempX;
}
     
int GD_Sistema::AltoVentana()
{
    int tempY;
    tempY = driver->getScreenSize().Height;
    return tempY;
}


/**
Cambia la fuente del sistema basado en BMP
mirar en herramientas para encontrar el programa para crear las fuentes BMP

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
                    // Botón
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
                    
                    // Selección en Menu
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


    while(device->getTimer()->getTime() < curTime + (1000.00/cps_deseados)){
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



/**
Cierra el sistema

*/
void GD_Sistema::Matarme()
{
device->closeDevice();
}

/**
Establece el titulo de la ventana

*/
void GD_Sistema::TituloVentana(wchar_t* textoso)
{
     device->setWindowCaption(textoso);
}

IrrlichtDevice* GD_Sistema::RetornarDevice()
{
    return device;
}

int GD_Sistema::RetornarCPS()
{
    return _CPS;
}


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

int GD_Sistema::TeclaPrecionada() //Añadido por Astucia 13-04-2006
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

int GD_Sistema::MouseMovimientoX(){
   static int iOldPosX,iCresPosX;
   int posX;
   //Obtiene el valor acutal de la posicion del cursor en el eje X
   posX=MousePosicionX();
   //Reposiciona el cursor si llega al final de la pantalla
   /* Esto con el propocito de que el raton siga recibiendo la informacion de
      movimiento.*/
   if(posX==799){
      MousePosicionar(798,MousePosicionY());
      iOldPosX=0;
   }
   //Lo mismo pero al inicio de la pantalla
   if(posX==0){
      MousePosicionar(2,MousePosicionY());
      iOldPosX=1;
   }

   //Devuelve el valor relativo al movimiento del raton en el eje X
   if(posX>iOldPosX){
      iOldPosX=posX;
      iCresPosX++;
      return iCresPosX;
   }
   if(posX<iOldPosX){
      iOldPosX=posX;
      iCresPosX--;
      return iCresPosX;
   }
   // Anula el valor del movimiento si no hay movimiento del cursor.
   if(posX==iOldPosX){
      iCresPosX=0;
   }

   return 0;
}

int GD_Sistema::MouseMovimientoY(){
   static int iOldPosY,iCresPosY;
   int posY;
   //Obtiene el valor acutal de la posicion del cursor en el eje Y
   posY=MousePosicionY();
   //Reposiciona el cursor si llega al final de la pantalla
   /* Esto con el propocito de que el raton siga recibiendo la informacion de
      movimiento.*/
   if(posY==599){
      MousePosicionar(MousePosicionX(),598);
      iOldPosY=0;
   }
   //Lo mismo pero al inicio de la pantalla
   if(posY==0){
      MousePosicionar(MousePosicionX(),1);
      iOldPosY=1;
   }

   //Devuelve el valor relativo al movimiento del raton en el eje Y
   if(posY>iOldPosY){
      iOldPosY=posY;
      iCresPosY++;
      return iCresPosY;
   }
   if(posY<iOldPosY){
      iOldPosY=posY;
      iCresPosY--;
      return iCresPosY;
   }
   // Anula el valor del movimiento si no hay movimiento del cursor.
   if(posY==iOldPosY){
      iCresPosY=0;
   }
   return 0;
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

int GD_Sistema::MilisegundosSistema()
{
   int milsc = device->getTimer()->getTime();
   return milsc;
}
       
int GD_Sistema::Milisegundos()
{
    milsc_act = device->getTimer()->getRealTime() - milsc_ini;
    return milsc_act;
}

void GD_Sistema::ReiniciarReloj()
{
   milsc_ini = device->getTimer()->getRealTime();
}
       

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
