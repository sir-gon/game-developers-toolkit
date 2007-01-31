/*///////////////////////////////////////////////////////////////////

GD_Agua 

Este archivo hace parte de GDT Game Developers Toolkit.
Para informacion de distribucion o uso dirigase a el archivo gdt.h
o en la web http://www.gdtoolkit.8m.net

*////////////////////////////////////////////////////////////////////


#include "gd_agua.h" // class's header file

// class constructor
GD_Agua::GD_Agua()
{
}

// class destructor
GD_Agua::~GD_Agua()
{
}
 
/*//////////////////////////////////////////////////////////////////////////
Crea una superficie de agua con su movimiento que se actualiza automáticamente, 

x, y tamaño de cada cuadro del mosaico.
ny, nz numero de cuadros que componen el mosaico.
tx, ty, mapeo de textura, es decir las veces que se repite la textura.
AlturaOnda, altura de la onda.
VelocidadOnda velocidad de la onda.
LongitudOnda la longitud de la onda.
t es la ruta de la textura. La textura se aplica y queda la superficie transparente.
*/////////////////////////////////////////////////////////////////////////////
void GD_Agua::CrearNormal(float x, float y, int nx, int ny,int tx,int ty,f32 AlturaOnda,f32 VelocidadOnda, f32 LongitudOnda, char* t)
{
     
    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=midevice->getSceneManager();

    // Se crea el plano
    mesh = mismgr->addHillPlaneMesh("myHill",
	core::dimension2d<f32>(x,y),
	core::dimension2d<s32>(nx,ny), 0, 0,
	core::dimension2d<f32>(0,0),
	core::dimension2d<f32>(tx,ty));
    
    // Se crea el nodo y se le agrega el plano
	nodon = mismgr->addWaterSurfaceSceneNode(mesh->getMesh(0), AlturaOnda, VelocidadOnda, LongitudOnda);

    if(!nodon) printf("ERROR: No se pudo crear Agua Normal\n");
    
    // Se carga la textura
	nodon->setMaterialTexture(0, mismgr->getVideoDriver()->getTexture(t));
	
	// Se establece el material transparente
	nodon->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
     
}


/*//////////////////////////////////////////////////////////////////////////
Es igual que CrearNormal pero realista, los parámetros son los mismos sino que t2 es la textura del piso.
Entonces la textura1 se vuelve reflexión esférica transparente y la textura2 es la base es decir el piso.
*///////////////////////////////////////////////////////////////////////////
void GD_Agua::CrearRealista(float x, float y, int nx, int ny, int tx,int ty, f32 AlturaOnda,f32 VelocidadOnda, f32 LongitudOnda, char* t1, char* t2)
{

    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=midevice->getSceneManager();

    // Se crea el plano
    mesh = mismgr->addHillPlaneMesh("myHill",
	core::dimension2d<f32>(x,y), //tamano mosaico
	core::dimension2d<s32>(nx,ny), 0, 0,//numero mosaicos
	core::dimension2d<f32>(0,0),
	core::dimension2d<f32>(tx,ty));

    // Se crea el nodo y se le agrega el plano
	nodon = mismgr->addWaterSurfaceSceneNode(mesh->getMesh(0), AlturaOnda, VelocidadOnda, LongitudOnda);

    if(!nodon) printf("ERROR: No se pudo crear Agua Realista\n");

    // Se carga las texturas
	nodon->setMaterialTexture(1,	mismgr->getVideoDriver()->getTexture(t1));
	nodon->setMaterialTexture(0,	mismgr->getVideoDriver()->getTexture(t2));

	// Se establece el material de refleccion de la segunda capa
	nodon->setMaterialType(EMT_REFLECTION_2_LAYER);
     
}

