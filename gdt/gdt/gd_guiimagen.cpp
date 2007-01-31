// Class automatically generated by Dev-C++ New Class wizard

#include "gd_guiimagen.h" // class's header file

// class constructor
GD_GuiImagen::GD_GuiImagen()
{
	// insert your code here
}

// class destructor
GD_GuiImagen::~GD_GuiImagen()
{
	// insert your code here
}

void GD_GuiImagen::Cargar(char *filename)
{

    RegistrarDevice(GD_Sistema::device);

    driver = midevice->getVideoDriver();
    guienv = midevice->getGUIEnvironment();

    //irr::core::dimension2d< s32 > tam;
    //irr::video::ITexture* textura;

    textura=driver->getTexture(filename);

    tam = textura->getOriginalSize();

    // printf("TAMX = %d, TAMY = %d",tam.Width, tam.Height);

  //  int tamx = tam.Width+40;
  //  int tamy = tam.Height+2;
  //
//	img = guienv->addImage(rect<s32>(0,0,tam.Width,tam.Height));
//	img->setImage(textura);

	img = guienv->addImage(driver->getTexture(filename),core::position2d<s32>(5,5));


    guiele=img;
}

void GD_GuiImagen::UsarCanalAlpha(bool uso)
{
    img->setUseAlphaChannel(uso);
}

void GD_GuiImagen::Visible(bool estado)
{
    img->setVisible(estado);
}