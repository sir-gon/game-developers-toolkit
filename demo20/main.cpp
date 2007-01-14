// ////////////////////////////////////////////////////////////////////////////////
// 
//  GDT v1.1.3
//
//  Demo juego en tercera persona
//
////////////////////////////////////////////////////////////////////////////////
//   Aca podemos ver el fucionamiento en conjunto de:
//     
//   Colisiones de Personaje y Camara, con su respuesta(incluyendo gravedad)
//   Escenarios
//   Panorama
//   Musica
//   Sonido    
//   Movimiento
//   Animaciones, con su control de acciones
//   Proyectiles, con sus colisiones
//   Particulas
//   Entrada de comandos
//   Sombras
//
////////////////////////////////////////////////////////////////////////////////
//
//

#include <gdt.h> 

GD_Sistema Sistema;
GD_SistemaSonido SistemaSonido;

GD_Camara Camara;
GD_Panorama Panorama;
GD_Escenario Escenario;
GD_Luz LuzA;

GD_GuiImagen Logo;
GD_GuiTexto Info;

GD_Malla Protagonista, Enemigo;
GD_Malla Bala,Logo3D,Resplandor;

GD_Particula Fuego,FuegoExplosion;
 
GD_Sonido3D SonidoBala,SonidoExplosion; 
//GD_Musik Musica;

GD_Fundido FundidoInicio;
GD_Fundido FundidoDisparo;

// se crean los objetos que mostrara un texto en la pantalla
GD_GuiTexto txtFPS; 
GD_GuiTexto txtNumPolygonos;

void CargarProtagonista();
void CargarEnemigo();
void CargarEscenario();
void CargarHUD();
void MovimientoPersonaje();
void MovimientoCamara( unsigned int AnguloInicial );
void Disparar();
void GenerarExplosion(vector3df posicion);
void ActualizarDisparo();

void IniciarInfo();
void MostrarInfo();


void Publicidad();

int TiempoExplosion;
bool VidaDisparo;

int main()
{
        Sistema.Inicializar(800,600,16, false, OPENGL);
        SistemaSonido.Inicializar();
//        Sistema.LimiteCPS(40);

        Sistema.OcultarPuntero();

        Camara.Crear( Tipo_Normal );
        Camara.Posicionar(100,100,580);

        Publicidad();

        CargarEscenario();
        CargarProtagonista();
        CargarEnemigo();

        CargarHUD();

        FundidoInicio.FundirHaciaDentro(3000);

	IniciarInfo();

	while(Sistema.EnEjecucion())
	{


               if(Sistema.TeclaAbajo(T_ESC)) Sistema.Matarme();

                MovimientoPersonaje();
                ActualizarDisparo();

               if( VidaDisparo ){

                    if(Bala.ColisionConEscenario(Escenario)) {
                            GenerarExplosion( Bala.Posicion() );
                            VidaDisparo = 0;
			//printf("colision con escenario");
                    }

                    if(Bala.Colisiona(Enemigo))
                    {
                           GenerarExplosion( Bala.Posicion() );
                           Enemigo.CicloMD2( DEATH_FALLBACK );
                           VidaDisparo = 0;      
                           FundidoDisparo.FundirHaciaDentro(430);
			//printf("colision con enemigo");
                    }

                    if(Bala.Colisiona( Logo3D ))
                    {
                           GenerarExplosion( Protagonista.Posicion() );
                           VidaDisparo = 0;      
                           FundidoDisparo.FundirHaciaDentro(330);
                    }
			//printf("colision con logo");

                }

                if(Protagonista.Colisiona( Logo3D )){
                     Logo3D.GirarY(-30);
                }
                else
                {
                     Logo3D.GirarY(2); 
                }

                if(Sistema.Milisegundos() > (TiempoExplosion + 800) && TiempoExplosion !=0){ 
                          FuegoExplosion.Posicionar(10000,10000,100000);
                          Enemigo.CicloMD2( STAND );
                }

/*
                if(Protagonista.Colisiona(Logo3D)){

                }
*/

                LuzA.Posicionar(Protagonista.Posicion().X + 30,Protagonista.Posicion().Y + 30,Protagonista.Posicion().Z + 40);
                
		MovimientoCamara( 270 ); // parametro es el angulo inicial
		MostrarInfo();

                Sistema.Render();
	}

	Sistema.Matarme();

	return 0;
} 


void CargarProtagonista()
{
	Protagonista.Cargar("media_demo/tris.md2"); 
	Protagonista.Posicionar(250,400,50);      
	Protagonista.VelocidadAnimacion(50); 
	Protagonista.GirarY(240); 
	Protagonista.Texturizar("media_demo/ogro.bmp");
	Protagonista.ColorEmisivo(250,220,250);
	
	Protagonista.ProyectarSombra();
	
	Protagonista.CrearColision(Escenario,20,40,20,0,-0.098,0,0,-10,0);

	Protagonista.CicloMD2( STAND );            
	Protagonista.ControlAnimacion(true);
	
	Bala.Cargar("media_demo/muni.my3d"); 
	
	Fuego.Crear(1.6,1.6,-7,0.0,0.0,0.0,40,100,400,800,0, "media_demo/portal1.bmp");
	Fuego.Escalar(4,4);
	
	Bala.Anclar(Fuego);
	
	SonidoBala.Cargar("media_demo/firesound.wav");        
	
	FuegoExplosion.Crear(15,27,15,0.0,0.0,0.0,100,200,400,800,0, "media_demo/portal1.bmp");
	FuegoExplosion.Escalar(20,20);
	
	
	SonidoExplosion.Cargar("media_demo/explode.wav");
	
	FundidoDisparo.Crear();
	FundidoDisparo.Color(200,0,0);
}


void CargarEnemigo()
{
        Enemigo.Cargar("media_demo/tris.md2"); 
        Enemigo.Posicionar(300,400,50);      
        Enemigo.VelocidadAnimacion(50); 
        Enemigo.GirarY(300);
        Enemigo.Texturizar("media_demo/ogro2.bmp");
        Enemigo.ColorEmisivo(250,220,250);

        Enemigo.ProyectarSombra();

        Enemigo.CrearColision(Escenario,10,25,10,0,-0.098,0,0,0,0);

        Enemigo.CicloMD2( STAND );
        Enemigo.ControlAnimacion(true);

}
 
void CargarEscenario()
{
        LuzA.Crear(100,100,100,500,500,500,30000);

//        Musica.Cargar("media_demo/ki2spinal.mid"); // Carga un archivo midi
//        Musica.Play(); // Reproduce el archivo

        Escenario.CargarBSP("media_demo/bdog3dm1.pk3","maps/bdog3dm1.bsp");

        Camara.CrearColision(Escenario,1,1,1,0,0.0,0,0,0,0);

        Panorama.CrearCubico("media_demo/moss_top.jpg", 
                       "media_demo/moss_bot.jpg", 
                       "media_demo/moss_left.jpg",
                       "media_demo/moss_right.jpg",
                       "media_demo/moss_front.jpg",
                       "media_demo/moss_back.jpg");


        Sistema.ColorSombra(10,10,10);

        Logo3D.Posicionar( 128,365,-1058 );

        Resplandor.CrearCilindro(10,10,2);
        Resplandor.Posicionar( Logo3D.Posicion() );

}

void CargarHUD()
{
        Logo.Cargar("media_demo/logoGDT.png");
        Logo.UsarCanalAlpha(true);
        Logo.Posicionar(Sistema.AnchoVentana()-232,Sistema.AltoVentana()-161);

        FundidoInicio.Crear( );
        FundidoInicio.Color( 0,0,0 );
}

void IniciarInfo()
{
	txtFPS.Crear(0,0,800,600, L"");
	txtNumPolygonos.Crear(0,0,800,600, L"");
	txtFPS.Color(255,255,255,0);
	txtNumPolygonos.Color(255,255,255,0);
}

void MostrarInfo()
{
	TCadena CadenaFPS[100];
	TCadena CadenaPoly[100];
	
	/*
	* EN VEZ DE HACER ESTO, ES CONVENIENTE EL SIGUIENTE HACK 
	* PARA QUE FUNCIONE SWPRINTF COMO EN LA DEFINICION PARA LINUX

	#ifdef WIN32
	define swprintf snwprintf

	*/

	#ifdef WIN32
	swprintf(CadenaFPS, L"CPS: %d", Sistema.RetornarCPS());
	swprintf(CadenaPoly, L"Poligonos: %d", Sistema.RetornarTriangulos() );
	#endif
	
	#ifdef LINUX
	swprintf(CadenaFPS, 100, L"CPS: %d", Sistema.RetornarCPS());
	swprintf(CadenaPoly, 100,L"Poligonos: %d", Sistema.RetornarTriangulos() );
	#endif
	
	txtFPS.Texto(CadenaFPS,10,10);
	txtNumPolygonos.Texto(CadenaPoly,10,20);
}

void MovimientoPersonaje()
{
	// Hay muchas formas de hacer esto y seguramente mucho mejores. Pero vale para el ejemplo
	// mira si esta haciendo alguna accion , valga la rebusnancia  :)
	
	if (Sistema.TeclaAbajo(T_FLECHA_ARRIBA) || Sistema.TeclaAbajo(T_FLECHA_ABAJO) || 
		Sistema.TeclaAbajo(T_FLECHA_DERECHA) ||Sistema.TeclaAbajo(T_FLECHA_IZQUIERDA)){
	
			if(Sistema.TeclaAbajo(T_FLECHA_ARRIBA))  Protagonista.MoverX(3.5);
			if(Sistema.TeclaAbajo(T_FLECHA_ABAJO))   Protagonista.MoverX(-2.5);
			if(Sistema.TeclaAbajo(T_FLECHA_DERECHA)) Protagonista.GirarY(5);
			if(Sistema.TeclaAbajo(T_FLECHA_IZQUIERDA)) Protagonista.GirarY(-5);
	
			Protagonista.CicloMD2(RUN);
	}
	else // si no esta haciendo nada
			Protagonista.CicloMD2( STAND );
	
	if (Sistema.TeclaPulsada(T_ESPACIO)){
		Disparar();
		Protagonista.CicloMD2(ATTACK);
	}
}

void MovimientoCamara( unsigned int AnguloInicial ) {

	static unsigned int angulo=AnguloInicial;
    
	if(Sistema.TeclaAbajo(T_TECLA_A)) {
		angulo=angulo+10;
		if(angulo > 360) angulo = angulo%360;
		//cout << "Angulo: " << angulo << "\n";
	}

	if(Sistema.TeclaAbajo(T_TECLA_S)) {
		if(angulo == 0) angulo = 360;
		angulo=angulo-10;
		//cout << "Angulo: " << angulo << "\n";
	}
     
	Camara.Perseguir(Protagonista,100,70,angulo,5);
}


void Disparar()
{
     // orientar y posicionar 
     Bala.Posicionar(Protagonista.Posicion());
     Bala.Rotar(Protagonista.Rotacion());
     Bala.MoverY(20);
     Bala.GirarY(90);

     SonidoBala.Play();

     VidaDisparo = 1; 
}

void ActualizarDisparo()
{
     if(VidaDisparo == 1){
          Bala.MoverZ(5);
     }
     else  
     {
          Bala.Posicionar(100000,100000,100000);
     }
}

void GenerarExplosion(vector3df posicion)
{
	FuegoExplosion.Posicionar( posicion );
	FuegoExplosion.Visible(true);
	TiempoExplosion = Sistema.Milisegundos();
	SonidoExplosion.Play();
}

void Publicidad()
{

	GD_Fundido FundidoLogo;
	GD_Luz LuzX;
	GD_GuiImagen LogoLetras;
	
	Sistema.ColorFondo(0,0,0);
	
	LuzX.Crear(100,100,100,100,100,100,1);
	
	Logo3D.Cargar("media_demo/logogdt3d.my3d");
	Logo3D.ColorDifuso(200,10,200);
	Logo3D.ColorEmisivo(40,5,40);      
	Logo3D.ColorEspecular(40,5,40);        
	

	LogoLetras.Cargar("media_demo/logoletras.png");    
	LogoLetras.Posicionar(200,400);
	
	FundidoLogo.Crear();
	FundidoLogo.Color(0,0,0);
	
	Camara.Posicionar(0,0,100);
	Camara.Orientar(0,0,0);
	
	int tiempoini=Sistema.Milisegundos();
	
	FundidoLogo.FundirHaciaDentro(3000);

	while(Sistema.EnEjecucion())
	{

              Logo3D.GirarY(2);

              if(Sistema.Milisegundos() > (tiempoini + 8000)) {
                     LogoLetras.Visible(false);
                     return;
              }

                Sistema.Render();
	}

        Logo3D.Visible(false);

}
