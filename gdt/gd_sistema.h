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

#ifndef GD_SISTEMA_H
#define GD_SISTEMA_H


// irrlicht
#include <irrlicht.h>
#include <wchar.h>
#include <string.h>
#include <cassert>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

//#include "gd_camara.h"
//#include "gd_guibarra.h"
//#include "gd_guiboton.h"

//Drivers
#define OPENGL EDT_OPENGL
#define DIRECTX8 EDT_DIRECT3D8
#define DIRECTX9 EDT_DIRECT3D9
#define SOFTWARE EDT_SOFTWARE
#define NULO EDT_NULL

//Camara
#define Tipo_FPS 3
#define Tipo_Modelador 2
#define Tipo_Normal 1

//Materiales

//Flags
#define WIREFRAME EMF_WIREFRAME            //Draw as wireframe or filled triangles? Default: false.
#define SOMBREADO_GOURAUD EMF_GOURAUD_SHADING      //Flat or Gouraud shading? Default: true.
#define ILUMINAR EMF_LIGHTING             //Will this material be lighted? Default: true.
#define CORTAR_CARAS_TRASERAS EMF_BACK_FACE_CULLING    //Is backfaceculling enabled? Default: true.
#define FILTRO_BILINEAR EMF_BILINEAR_FILTER      //Is bilinear filtering enabled? Default: true.
#define FILTRO_TRILINEAR EMF_TRILINEAR_FILTER     //Is trilinear filtering enabled? Default: false If the trilinear filter flag is enabled, the bilinear filtering flag is ignored.
#define NIEBLA EMF_FOG_ENABLE           //Is fog enabled? Default: false.

//Tipos
#define SOLIDO EMT_SOLID  //Standard solid material. Only first texture is used, which is supposed to be the diffuse material.
#define SOLIDO_2_CAPAS EMT_SOLID_2_LAYER  //Solid material with 2 texture layers. The second is blended onto the first using the alpha value of the vertex colors. This material is currently not implemented in OpenGL, but it works with DirectX.
#define LIGHTMAP EMT_LIGHTMAP  //Material type with standard lightmap technique: There should be 2 textures: The first texture layer is a diffuse map, the second is a light map. Vertex light is ignored.
#define LIGHTMAP_ADD EMT_LIGHTMAP_ADD  //Material type with lightmap technique like EMT_LIGHTMAP, but lightmap and diffuse texture are not modulated, but added instead.
#define LIGHTMAP_M2 EMT_LIGHTMAP_M2  //Material type with standard lightmap technique: There should be 2 textures: The first texture layer is a diffuse map, the second is a light map. Vertex light is ignored. The texture colors are effectively multiplyied by 2 for brightening. like known in DirectX as D3DTOP_MODULATE2X.
#define LIGHTMAP_M4 EMT_LIGHTMAP_M4  //Material type with standard lightmap technique: There should be 2 textures: The first texture layer is a diffuse map, the second is a light map. Vertex light is ignored. The texture colors are effectively multiplyied by 4 for brightening. like known in DirectX as D3DTOP_MODULATE4X.
#define LIGHTMAP_ILUMINADO EMT_LIGHTMAP_LIGHTING  //Like EMT_LIGHTMAP, but also supports dynamic lighting.
#define LIGHTMAP_ILUMINADO_M2 EMT_LIGHTMAP_LIGHTING_M2  //Like EMT_LIGHTMAP_M2, but also supports dynamic lighting.
#define LIGHTMAP_ILUMINADO_M4 EMT_LIGHTMAP_LIGHTING_M4  //Like EMT_LIGHTMAP_4, but also supports dynamic lighting.
#define MAPA_ESFERICO EMT_SPHERE_MAP  //Makes the material look like it was reflection the environment around it. To make this possible, a texture called 'sphere map' is used, which must be set as Texture1.
#define REFLECCION_2_CAPAS EMT_REFLECTION_2_LAYER  //A reflecting material with an optional additional non reflecting texture layer. The reflection map should be set as Texture 1. Please note that this material type is currently not 100% implemented in OpenGL. It works in DirectX8 and 9.
#define TRANSPARENTE_MAS_COLOR EMT_TRANSPARENT_ADD_COLOR  //A transparent material. Only the first texture is used. The new color is calculated by simply adding the source color and the dest color. This means if for example a billboard using a texture with black background and a red circle on it is drawed with this material, the result is that only the red circle will be drawn a little bit transparent, and everything which was black is 100% transparent and not visible. This material type is useful for e.g. particle effects.
#define TRANSPARENTE_ALPHA EMT_TRANSPARENT_ALPHA_CHANNEL  //Makes the material transparent based on the texture alpha channel. The final color is blended together from the destination color and the texture color, using the alpha channel value as blend factor. Only first texture is used. If you are using this material with small textures and 3d object, it is a good idea to load the texture in 32 bit mode (video::IVideoDriver::setTextureCreationFlag()).
#define TRANSPARENTE_ALPHA_REF EMT_TRANSPARENT_ALPHA_CHANNEL_REF  //Makes the material transparent based on the texture alpha channel. If the alpha channel value is greater than 127, a pixel is written to the target, otherwise not. This material does not use alpha blending and is a lot faster than EMT_TRANSPARENT_ALPHA_CHANNEL. It is ideal for drawing stuff like leafes of plants, because the borders are not blurry but sharp. Only first texture is used. If you are using this material with small textures and 3d object, it is a good idea to load the texture in 32 bit mode (video::IVideoDriver::setTextureCreationFlag()).
#define TRANSPARENTE_VERTICE_ALPHA EMT_TRANSPARENT_VERTEX_ALPHA  //Makes the material transparent based on the vertex alpha value.
#define TRANSPARENTE_REFLECCION_2_CAPAS EMT_TRANSPARENT_REFLECTION_2_LAYER  //A transparent reflecting material with an optional additional non reflecting texture layer. The reflection map should be set as Texture 1. The transparency depends on the alpha value in the vertex colors. A texture which will not reflect can be set als Texture 2. Please note that this material type is currently not 100% implemented in OpenGL. It works in DirectX8.
#define MAPA_NORMAL_SOLIDO EMT_NORMAL_MAP_SOLID  //A solid normal map renderer. First texture is the color map, the second should be the normal map. Note that you should use this material only when drawing geometry consisting of vertices of type S3DVertexTangents (EVT_TANGENTS). You can convert any mesh into this format using IMeshManipulator::createMeshWithTangents() (See SpecialFX2 Tutorial). This shader runs on vertex shader 1.1 and pixel shader 1.1 capable hardware and falls back on a fixed function lighted material if this hardware is not available. Only two lights are supported by this shader, if there are more, the nearest two are chosen. Currently, this shader is only implemented for the D3D8 and D3D9 renderers.
#define MAPA_NORMAL_TRANSPARENTE_MAS_COLOR EMT_NORMAL_MAP_TRANSPARENT_ADD_COLOR  //A transparent normal map renderer. First texture is the color map, the second should be the normal map. Note that you should use this material only when drawing geometry consisting of vertices of type S3DVertexTangents (EVT_TANGENTS). You can convert any mesh into this format using IMeshManipulator::createMeshWithTangents() (See SpecialFX2 Tutorial). This shader runs on vertex shader 1.1 and pixel shader 1.1 capable hardware and falls back on a fixed function lighted material if this hardware is not available. Only two lights are supported by this shader, if there are more, the nearest two are chosen. Currently, this shader is only implemented for the D3D8 and D3D9 renderers.
#define MAPA_NORMAL_TRANSPARENTE_VERTICE_ALPHA EMT_NORMAL_MAP_TRANSPARENT_VERTEX_ALPHA // A transparent (based on the vertex alpha value) normal map renderer. First texture is the color map, the second should be the normal map. Note that you should use this material only when drawing geometry consisting of vertices of type S3DVertexTangents (EVT_TANGENTS). You can convert any mesh into this format using IMeshManipulator::createMeshWithTangents() (See SpecialFX2 Tutorial). This shader runs on vertex shader 1.1 and pixel shader 1.1 capable hardware and falls back on a fixed function lighted material if this hardware is not available. Only two lights are supported by this shader, if there are more, the nearest two are chosen. Currently, this shader is only implemented for the D3D8 and D3D9 renderers.
#define MAPA_PARALELO_SOLIDO EMT_PARALLAX_MAP_SOLID  //Just like EMT_NORMAL_MAP_SOLID, but uses parallax mapping too, which looks a lot more realistic. This only works when the hardware supports at least vertex shader 1.1 and pixel shader 1.4. First texture is the color map, the second should be the normal map. The normal map texture should contain the height value in the alpha component. The IVideoDriver::makeNormalMapTexture() method writes this value automaticly when creating normal maps from a heightmap when using a 32 bit texture. The height scale of the material (affecting the bumpiness) is being controlled by the SMaterial::MaterialTypeParam member. If set to zero, the default value (0.02f) will be applied. Otherwise the value set in SMaterial::MaterialTypeParam is taken. This value depends on with which scale the texture is mapped on the material. Too high or low values of MaterialTypeParam can result in strange artifacts.
#define MAPA_PARALELO_TRANSPARENTE_MAS_COLOR EMT_PARALLAX_MAP_TRANSPARENT_ADD_COLOR  //A material just like EMT_PARALLAX_MAP_SOLID, but it is transparent, using EMT_TRANSPARENT_ADD_COLOR as base material.
#define MAPA_PARALELO_TRANSPARENTE_VERTICE_ALPHA EMT_PARALLAX_MAP_TRANSPARENT_VERTEX_ALPHA  //A material just like EMT_PARALLAX_MAP_SOLID, but it is transparent, using EMT_TRANSPARENT_VERTEX_ALPHA as base material.

#define M_BOTON_IZQUIERDO 1
#define M_BOTON_DERECHO 2
#define M_BOTON_CENTRO 4

#define T_ESC 27

#define T_FLECHA_IZQUIERDA 37
#define T_FLECHA_ARRIBA 38
#define T_FLECHA_DERECHA 39
#define T_FLECHA_ABAJO 40

#define T_TECLA_A 65
#define T_TECLA_B 66
#define T_TECLA_C 67
#define T_TECLA_D 68
#define T_TECLA_E 69
#define T_TECLA_F 70
#define T_TECLA_G 71
#define T_TECLA_H 72
#define T_TECLA_I 73
#define T_TECLA_J 74
#define T_TECLA_K 75
#define T_TECLA_L 76
#define T_TECLA_M 77
#define T_TECLA_N 78
#define T_TECLA_O 79
#define T_TECLA_P 80
#define T_TECLA_Q 81
#define T_TECLA_R 82
#define T_TECLA_S 83
#define T_TECLA_T 84
#define T_TECLA_U 85
#define T_TECLA_V 86
#define T_TECLA_W 87
#define T_TECLA_X 88
#define T_TECLA_Y 89
#define T_TECLA_Z 90

#define T_F1 112
#define T_F2 113
#define T_F3 114
#define T_F4 115
#define T_F5 116
#define T_F6 117
#define T_F7 118
#define T_F8 119
#define T_F9 120
#define T_F10 121
#define T_F11 122
#define T_F12 123

#define T_TECLA_0 48
#define T_TECLA_1 49
#define T_TECLA_2 50
#define T_TECLA_3 51
#define T_TECLA_4 52
#define T_TECLA_5 53
#define T_TECLA_6 54
#define T_TECLA_7 55
#define T_TECLA_8 56
#define T_TECLA_9 57

#define T_BACKSPACE 8
#define T_TAB 9
#define T_ENTER 13
#define T_SHIFT 16
#define T_CONTROL 17
#define T_ALT 18
#define T_PAUSE 19
#define T_CAPSLOCK 20

#define T_ESPACIO 32
#define T_PAGE_UP 33
#define T_PAGE_DOWN 34
#define T_END 35
#define T_HOME 36

#define T_NUMPAD_0 96
#define T_NUMPAD_1 97
#define T_NUMPAD_2 98
#define T_NUMPAD_3 99
#define T_NUMPAD_4 100
#define T_NUMPAD_5 101
#define T_NUMPAD_6 102
#define T_NUMPAD_7 103
#define T_NUMPAD_8 104
#define T_NUMPAD_9 105

#define T_NUMPAD_PLUS   107   // +
#define T_NUMPAD_MINUS  109   // -
#define T_NUMPAD_DIV    111   // /
#define T_NUMPAD_POW    106   // *


#define TCadena wchar_t
#define TCadenaC stringc
#define TCadenaL stringw

// HACK PARA FUNCIONES DE TEXTO ENTRE WINDOWS Y LINUX
#ifdef WIN32
	#define SumarCadenas snwprintf
#else
	#define SumarCadenas swprintf
#endif
//=====================================================================================//

//! Clase Maestra de GDT
/**
Todo depende del Sistema, desde las funciones b&aacute;sicas de entrada y salida hasta el control de los nodos y dibujado, incluyendo los c&aacute;lculos 3D necesarios.

Al inicializar el sistema, se generar&aacute; una ventana con un viewport de las dimenciones dadas.
Si lo desea, este viewport puede ser en modo ventana o a pantalla completa, y ocupando el modo que desee (OpenGL, DirectX, Software)

Tambi&eacute;n puede en algunos casos si lo desea ocupar un modo de dibujado NULL, de esta manera no se necesita dibujar por pantalla todo lo que ocurre. Este modo puede ser &uacute;til para programar un servicio compatible con las capacidades de Irrlicht, por ejemplo un servidor para un juego en linea.

El Sistema tambi&eacute;n puede ofrecer informaci&oacute;n &uacute;til sobre el estado actual de la ejecuci&oacute;n del programa, como los Cuadros dibujados por cada segundo (CPS, o FPS en ingl&eacute;s).

Los M&eacute;todos de Entrada-Salida nos permiten acceder a eventos del sistema, como por ejemplo si se ha presionado una tecla.
*/
class GD_Sistema : public IEventReceiver {
protected:
	// misc
	int lastFPS;
	u32 lasttick;


public:
    // class constructor
    GD_Sistema();
    // class destructor
    ~GD_Sistema();
    
    // Irrlicht  vars
    IVideoDriver* driver;
    ISceneManager* smgr;
    IGUIEnvironment* guienv;
    static IrrlichtDevice *device;
    IGUISkin* skin;
    
    ISceneCollisionManager* colin;
    
    
    bool m_key_buf[256];
    bool m_key_buf_old[256];
    bool m_mouse_button_buf[3];
    bool m_mouse_button_buf_old[3];
    
    int ultimatecla;
    
    bool pulsada[256];
    
    int creadoX,creadoY;
    
    int sR,sG,sB,sT; // colores sombra
    //! Establece el color de las sombras Stencil
    void ColorSombra(int R, int G, int B);
    void TranslucidezSombra(int T); 
    
    int TeclaPrecionada(); // A&ntilde;adido por Astucia 13-04-2006
    //! Retonar true si se esta presionando esta tecla sino retorna false
    bool TeclaAbajo(int index);
    bool TeclaPulsada(int index);
    bool MouseBotonAbajo(int index);
    bool MouseBotonArribaAbajo(int index);
    bool MouseBotonAbajoArriba(int index);
    
    //! Crea un sistema de GDT
    void Inicializar(int ancho=640, int alto=480, int prof=16, bool full=false, E_DRIVER_TYPE VideoDriver=EDT_OPENGL, bool StencilBuffer=false, bool Vsync=false);
    //! Dibuja un cuadro actual de la escena por Pantalla
    void Render();
    
    //! Ancho de la ventana
    int xventana;
    //! Alto de la ventana
    int yventana;
    
    //! Obtiene el ancho de la ventana
    int AnchoVentana();
    //! Obtiene el alto de la ventana
    int AltoVentana();
    
    //! Destruye el sistema
    void Matarme();
    
    int _CPS;
    //! Retorna los Cuadros Por Segundo, conocido mundialmente como FPS.
    int RetornarCPS();

    int Triangulos;
    //! Retornar el numero de pol&iacute;gonos que se est&aacute;n renderizando
    int RetornarTriangulos();
    
    bool _RenderVentana;
    void RenderizarSoloConVentanaActiva(bool activa);
    
    bool _VentanaEscalable;
    void VentanaEscalable(bool escalable);
    
    //! Obtiene el tiempo virtual del sistema, es decir cuanto tiempo a estado en ejecuci&oacute;n.
    int Milisegundos();
    //! Obtiene el tiempo virtual del sistema, sin interrupciones.
    int MilisegundosSistema();
    
    int milsc_act;
    int milsc_ini;
    //! Establece el tiempo de inicio del timer como el tiempo actual.
    void ReiniciarReloj();
    
    int cfa;
    int cfr;
    int cfg;
    int cfb;
    //! Establece el color de fondo
    void ColorFondo(int r,int g,int b);
    
    void ConfigurarNiebla(int r, int g, int  b, bool lineal, float inicio, float fin,float densidad);
    //! Establece el titulo de la ventana
    void TituloVentana(wchar_t* textoso);
    //! Cambia la fuente del sistema basado en Bitmap
    void Fuente(char* filename);
    
    virtual bool OnEvent(SEvent event);
    //! Comprueba si el Sistema aun est&aacute; en ejecuci&oacute;n
    bool EnEjecucion();
    
    static int ContadorElementosGui;
    
    // Bot&oacute;n
    int ultimoIdBotonClick;
    bool ClickBoton(int id2);
    //	bool MouseClick( GD_GuiBoton botoni );
    
    
    // Barra
    //     bool BarraMovida( GD_GuiBarra barrin );
    int ultimaIdBarraMovida;
    int ultimaBarraPosicion;
    //! Retorna true si se mueve la barra
    bool BarraMovida(int id2);
    
    
    
    // DialogoAbrirArchivo
    bool dialogoArchivoSeleccionado;
    const wchar_t* NombreArchivoSeleccionado;
    const wchar_t* ArchivoSeleccionado(void);
    
    // Menu
    int MenuOpcionSeleccionada;
    
    ITimer *tiempo_actual;
    //! Detiene la ejecuci&oacute;n del programa tantos milisegunos
    void Dormir(int milisecs);
    
    // camaras
    void ActivarCamara( ICameraSceneNode* cam ); //GD_Camara cam );
    void AreaRenderizado(int x1, int y1, int x2, int y2);
    
    void Limpiar();
    
    IrrlichtDevice* RetornarDevice();
    
    int cps_deseados;
    void LimiteCPS(int lcps);
    
    
    
    
    //funciones de Raton
    void MousePosicionar(int X,int Y); //Coloca el cursor en un punto de la pantalla
    int MousePosicionX();              //Devuelve la posicion en X del curso
    int MousePosicionY();              //Devuelve la posicion en Y del cursor
    f32 MouseMovimientoX(f32 sensibilidad);             //Devuelve el movimiento en el eje X del cursor
    f32 MouseMovimientoY(f32 sensibilidad);             //Devuelve el movimiento en el eje Y del cursor
    void OcultarPuntero();         //Oculta el cursor
    
    //Archivos
    //! Cambia la ruta actual del directorio de ejecuci&oacute;n
    void CambiarDirectorio(const char *strDir);
    const char *Directorio(void);
    bool ArchivoExiste(const char *strArchivo);
    
    // Escenas en formato Irr , XML, hechas con irrEdit o guardas en tiemporeal
    
    void CargarEscena(char* file);
    void GuardarEscena(char* file);

};



#endif // GD_SISTEMA_H
