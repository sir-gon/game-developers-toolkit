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

/**
* \class GDT::Nodo::NodoBase
*
* Ac&aacute; se coleccionan los m&eacute;todos del espacio comunes entre los objetos.
*
* Cada "objeto" del espacio es conciderado un Nodo, las mallas, las luces
* sistemas de particulas, c&aacute;mara, terrenos, etc.
* 
* De aqu&iacute; en adelante, se conciderar&aacute; para todos los ejemplos, a un
* nodo de tipo Malla llamado Cubo, el cual se instancia as&iacute;:
* \code
* #include <gdt.h>
* 
* Sistema System;
* Malla Cubo;
*
* int main()
* {
* 	while(System.EnEjecucion()) {
* 		///// Hacer algo ...
* 	}
* return 0;
* }
* \endcode
*/

#include "gd_nodo.h" // class's header file

// class constructor
GDT::Nodo::NodoBase::NodoBase()
{
	// insert your code here


}

// class destructor
GDT::Nodo::NodoBase::~NodoBase()
{
	// insert your code here
}


void GDT::Nodo::NodoBase::RegistrarDevice(	IrrlichtDevice *device )
{
	midevice = device;
}


/*!
Ejemplo:
\code
Cubo.Posicionar( 10,0,-30 );
\endcode
*/
void GDT::Nodo::NodoBase::Posicionar(float x, float y, float z)
{
     if(nodon) 
     {
      nodon->setPosition(vector3df(x, y, z));
      mi_posicion_x = x;
      mi_posicion_y = y;
      mi_posicion_z = z;
      }
     else
      printf("ERROR: Llamada invalida a la funcion .Posicionar, verifique haber creado/cargado correctamente la entidad.\n ej. CamaraA.Crear(Tipo_Normal);");
}

/*!
Ejemplo:
\code
Cubo.Posicionar( Cosa.Posicion() );
\endcode
*/
void GDT::Nodo::NodoBase::Posicionar(vector3df pos)
{

     nodon->setPosition(pos);
}

/**
Ejemplo:
\code
Cubo.PosicionarX( 10 );
\endcode
*/
void GDT::Nodo::NodoBase::PosicionarX(float x)
{
     vector3df poso;
     poso = nodon->getPosition();
     nodon->setPosition(vector3df(x, poso.Y, poso.Z));

}

/**
Ejemplo:
\code
Cubo.PosicionarY( 10 );
\endcode
*/
void GDT::Nodo::NodoBase::PosicionarY(float y)
{
     vector3df poso;
     poso = nodon->getPosition();
     nodon->setPosition(vector3df(poso.X, y, poso.Z));

}

/**
Ejemplo:
\code
Cubo.PosicionarZ( 10 );
\endcode
*/
void GDT::Nodo::NodoBase::PosicionarZ(float z)
{
     vector3df poso;
     poso = nodon->getPosition();
     nodon->setPosition(vector3df(poso.X, poso.Y, z));

}

/**
\return Vector posici&oacute;n actual.

Ejemplo:
\code
PosActual = Cubo.Posicion( );
\endcode
*/
vector3df GDT::Nodo::NodoBase::Posicion()
{
     vector3df poso;
     poso = nodon->getPosition();
     return poso;
}

/*!
\return Posici&oacute;n X

Ejemplo:
\code
PosX = Cubo.PosicionX( );
\endcode
*/
float GDT::Nodo::NodoBase::PosicionX()
{
     vector3df poso;
     poso = nodon->getPosition();
     return poso.X;
}

/*!
\return Posici&oacute;n Y

Ejemplo:
\code
PosY = Cubo.PosicionY( );
\endcode
*/

float GDT::Nodo::NodoBase::PosicionY()
{
     vector3df poso;
     poso = nodon->getPosition();
     return poso.Y;
}

/*!
\return Posici&oacute;n Z

Ejemplo:
\code
PosZ = Cubo.PosicionZ( );
\endcode
*/
float GDT::Nodo::NodoBase::PosicionZ()
{
     vector3df poso;
     poso = nodon->getPosition();
     return poso.Z;
}

/*!
Ejemplo:
\code
Cubo.Rotar( 10,90,10 );
\endcode

\note Esto fija la rotaci&oacute;n, para girar un nodo vea el m&eacute;todo \ref Girar()
*/
void GDT::Nodo::NodoBase::Rotar(float x, float y, float z)
{
     nodon->setRotation(vector3df(x, y, z));
}

/*!
Ejemplo:
\code
Cubo.Rotar( Cosa.Rotacion( ) );
\endcode

\note Esto fija la rotaci&oacute;n, para girar un nodo vea el m&eacute;todo \ref Girar()
*/
void GDT::Nodo::NodoBase::Rotar(vector3df rot)
{
     nodon->setRotation(rot);
}

/*!
Ejemplo:
\code
Cubo.RotarX( 90 );
\endcode

\note Esto fija la rotaci&oacute;n en X, para girar un nodo en X vea el m&eacute;todo \ref GirarX()
*/
void GDT::Nodo::NodoBase::RotarX(float x)
{
     vector3df roto;
     roto = nodon->getRotation();
     nodon->setRotation(vector3df(x, roto.Y, roto.Z));
}

/*!
Ejemplo:
\code
Cubo.RotarY( 90 );
\endcode

\note Esto fija la rotaci&oacute;n en Y, para girar un nodo en Y vea el m&eacute;todo \ref GirarY()
*/
void GDT::Nodo::NodoBase::RotarY(float y)
{
     vector3df roto;
     roto = nodon->getRotation();
     nodon->setRotation(vector3df(roto.X, y, roto.Z));
}

/*!
Ejemplo:
\code
Cubo.RotarZ( 90 );
\endcode

\note Esto fija la rotaci&oacute;n en Z, para girar un nodo en X vea el m&eacute;todo \ref GirarZ()
*/
void GDT::Nodo::NodoBase::RotarZ(float z)
{
     vector3df roto;
     roto = nodon->getRotation();
     nodon->setRotation(vector3df(roto.X, roto.Y, z));
}

/*!
\return Vector con la rotaci&oacute;n en grados

Ejemplo:
\code
RotActual = Cubo.Rotacion( );
\endcode
*/
vector3df GDT::Nodo::NodoBase::Rotacion()
{
   return nodon->getRotation();
}

/*!
\return la rotaci&oacute;n en X, es decir el &aacute;ngulo en X

Ejemplo:
\code
RotX = Cubo.RotacionX( );
\endcode
*/
float GDT::Nodo::NodoBase::RotacionX()
{
     vector3df roto;
     roto = nodon->getRotation();
     return roto.X;
}

/*!
\return la rotaci&oacute;n en Y, es decir el &aacute;ngulo en Y

Ejemplo:
\code
RotY = Cubo.RotacionY( );
\endcode
*/
float GDT::Nodo::NodoBase::RotacionY()
{
     vector3df roto;
     roto = nodon->getRotation();
     return roto.Y;
}

/*!
\return la rotaci&oacute;n en Z, es decir el &aacute;ngulo en Z

Ejemplo:
\code
RotZ = Cubo.RotacionZ( );
\endcode
*/
float GDT::Nodo::NodoBase::RotacionZ()
{
     vector3df roto;
     roto = nodon->getRotation();
     return roto.Z;
}

/*!
Ejemplo:
\code
Cubo.Escalar( 2,10,2 );
\endcode
*/
void GDT::Nodo::NodoBase::Escalar(float x, float y, float z)
{
     nodon->setScale(vector3df(x, y, z));
     nodon->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true);

}

/*!
Ejemplo:
\code
Cubo.Escalar ( Cosa.Tamano( ) );
\endcode
*/
void GDT::Nodo::NodoBase::Escalar(vector3df escala)
{
     nodon->setScale(escala);
     nodon->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true);
}

/*!
Puede tener problemas cuando se haya escalado previamente.

Ejemplo:
\code
Cubo.EscalarX( 3 );
\endcode
*/
void GDT::Nodo::NodoBase::EscalarX(float x)
{
     nodon->setScale(vector3df(x, 1, 1));
     nodon->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true);
}

/*!
Puede tener problemas cuando se haya escalado previamente.

Ejemplo:
\code
Cubo.EscalarY( 3 );
\endcode
*/
void GDT::Nodo::NodoBase::EscalarY(float y)
{
     vector3df scal;
     nodon->getScale();
     nodon->setScale(vector3df(1, y, 1));
     nodon->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true);
}

/*!
Puede tener problemas cuando se haya escalado previamente.

Ejemplo:
\code
Cubo.EscalarZ( 3 );
\endcode
*/
void GDT::Nodo::NodoBase::EscalarZ(float z)
{
     vector3df scal;
     nodon->getScale();
     nodon->setScale(vector3df(1, 1, z));
   	 nodon->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true);
}

/*!
Mueve el objeto teniendo en cuenta su orientaci&oacute;n actual, es decir X lateralmente, Y hacia arriba y abajo, y Z al frente o atr&aacute;s. Se usa mucho para el control del personaje.

Ejemplo:
\code
Cubo.Mover( 1, 0, 3 );
\endcode
*/
void GDT::Nodo::NodoBase::Mover(float x, float y, float z)
{
     //void MoveNode(ISceneNode* node, vector3df& dest)
     vector3df destino;
     destino.X = x;
     destino.Y = y;
     destino.Z = z;
	matrix4 matrix = nodon->getRelativeTransformation();
	matrix.transformVect(destino);
     nodon->setPosition(destino);
}


/*!
Ejemplo:
\code
Cubo.MoverX( 1 );
\endcode
*/
void GDT::Nodo::NodoBase::MoverX(float x)
{
     Mover(x,0,0);
}

/*!
Ejemplo:
\code
Cubo.MoverY( 1 );
\endcode
*/
void GDT::Nodo::NodoBase::MoverY(float y)
{
     Mover(0,y,0);
}

/*!
Ejemplo:
\code
Cubo.MoverZ( 1 );
\endcode
*/
void GDT::Nodo::NodoBase::MoverZ(float z)
{
     Mover(0,0,z);
}


/*!
Ejemplo:
\code
Cubo.Girar( 1, 0, 3 );
\endcode
*/
void GDT::Nodo::NodoBase::Girar(float x, float y, float z)
{
     vector3df roto;
     roto = nodon->getRotation();
     nodon->setRotation(vector3df(x+roto.X, y+roto.Y, z+roto.Z));
}

/*!
Ejemplo:
\code
Cubo.GirarX( 1 );
\endcode
*/
void GDT::Nodo::NodoBase::GirarX(float x)
{
     Girar(x,0,0);
}

/*!
Ejemplo:
\code
Cubo.GirarY( 1 );
\endcode
*/
void GDT::Nodo::NodoBase::GirarY(float y)
{
     Girar(0,y,0);
}

/*!
Ejemplo:
\code
Cubo.GirarZ( 1 );
\endcode
*/
void GDT::Nodo::NodoBase::GirarZ(float z)
{
     Girar(0,0,z);
}

/*!
Es decir que el nodo anclado va a tener el mismo comportamiento como si fuera el mismo, se mover&aacute;n igual la rotaci&oacute;n ser&aacute; la misma etc.

\param gdnodito el nodo objetivo al cual anclar nuestro nodo actual.

Ejemplo:
\code
Cubo.Anclar ( Esfera );
\endcode
*/
void GDT::Nodo::NodoBase::Anclar(NodoBase gdnodito)
{
     nodon->addChild(gdnodito.nodon);
}

/*!
\param gdnodito El nodo objetivo previamente anclado.

Ejemplo:
\code
Cubo.DesAnclar ( Esfera );
\endcode
*/
void GDT::Nodo::NodoBase::DesAnclar(NodoBase gdnodito)
{
     nodon->removeChild(gdnodito.nodon);
}

/*!
Es decir lo rota para que quede mir&aacute;ndolo.
Es muy usado para Inteligencia Artificial.

\param gdnodito El nodo objetivo hacia donde queremos que se oriente nuestro nodo.

Ejemplo:
\code
Cubo.Orientar( Enemigo );
\endcode
*/
vector3df GDT::Nodo::NodoBase::Orientar(NodoBase gdnodito)
{

     // hallamos vector de posicion actual
     vector3df pos_mia;
     vector3df destino;

     pos_mia = nodon->getPosition();
     destino = gdnodito.nodon->getPosition();;

     // lo restamos con el destino
     vector3df vectorRestado;
     vectorRestado = destino - pos_mia;

     float GradosX,GradosY,GradosZ;
     vectorRestado = vectorRestado.getHorizontalAngle();

     GradosX = vectorRestado.X;
     GradosY = vectorRestado.Y;
     GradosZ = vectorRestado.Z;


     Rotar(GradosX,GradosY,GradosZ);
	 return vectorRestado;
}

/*!
\param destino Vector hacia donde orientar el nodo.

Ejemplo:
\code
Cubo.Orientar( vector3df( 10,20,14 ) );
\endcode
*/
vector3df GDT::Nodo::NodoBase::Orientar(vector3df destino)
{
     // hallamos vector de posicion actual
     vector3df pos_mia;
     pos_mia = nodon->getPosition();

     // lo restamos con el destino
     vector3df vectorRestado;
     vectorRestado = destino - pos_mia;

    /*
     // hallamos la magnitud del vector
     double Magnitud;

     double A2,B2,C2, Suma;

     A2 = vectorRestado.X * vectorRestado.X;
     B2 = vectorRestado.Y * vectorRestado.Y;
     C2 = vectorRestado.Z * vectorRestado.Z;

     Suma = A2 + B2 + C2;

     Magnitud = sqrt(Suma);

     // hallamos los angulos :)

     float AngX, AngY, AngZ;

     AngX = acos(vectorRestado.X/Magnitud);
     AngY = atan2(vectorRestado.Y/Magnitud);
     AngZ = acos(vectorRestado.Z/Magnitud);



     GradosX = 0;//X*180.0f)/3.14159f;
     GradosY = (AngY*180.0f)/3.14159f;
     GradosZ = 0;//Z*180.0f)/3.14159f;

     */
     float GradosX,GradosY,GradosZ;
     vectorRestado = vectorRestado.getHorizontalAngle();

     GradosX = vectorRestado.X;
     GradosY = vectorRestado.Y;
     GradosZ = vectorRestado.Z;

//     printf("X: %f, Y: %f, Z: %f\n",GradosX,GradosY,GradosZ);

     Rotar(GradosX,GradosY,GradosZ);
	 return vectorRestado;
}

/*!
\param x,y,z Coordenadas hacia donde orientar el nodo.

Ejemplo:
\code
Cubo.Orientar( 10,20,14 );
\endcode
*/
vector3df GDT::Nodo::NodoBase::Orientar(float x, float y, float z) {
	return GDT::Nodo::NodoBase::Orientar( vector3df(x, y, z) );
}

/*!
Ejemplo:
\code
Tam = Cubo.Tamano( );
\endcode
*/
vector3df GDT::Nodo::NodoBase::Tamano()
{
       vector3df vect;
       vect = nodon->getTransformedBoundingBox().getExtent();
       return vect;
}

/*!
Ejemplo:
\code
TamX = Cubo.TamanoX( );
\endcode
*/
float GDT::Nodo::NodoBase::TamanoX()
{
      float x;
      x = nodon->getTransformedBoundingBox().getExtent().X;
      return x;
}

/*!
Ejemplo:
\code
TamY = Cubo.TamanoY( );
\endcode
*/
float GDT::Nodo::NodoBase::TamanoY()
{
      float y;
      y = nodon->getTransformedBoundingBox().getExtent().Y;
      return y;
}

/*!
Ejemplo:
\code
TamZ = Cubo.TamanoZ( );
\endcode
*/
float GDT::Nodo::NodoBase::TamanoZ()
{
      float z;
      z = nodon->getTransformedBoundingBox().getExtent().Z;
      return z;
}

/*!
\param filename la ruta del archivo de imagen
\param capa se refiere al material en donde se texturizara. Por defecto los texturiza todos, si desea especificar el material a texturizar usar el numero del material.

Si no desea especificar el material simplemente ignore el par&aacute;metro capa y coloque solo la ruta de la imagen.

Ejemplos:
\code
Cubo.Texturizar( "texturas/caja.bmp" );
\endcode
\code
Cubo.Texturizar( "texturas/caja.bmp", 2);
\endcode
*/
void GDT::Nodo::NodoBase::Texturizar(char* filename, int capa)
{
     //nodon->setMaterialTexture(capa, midevice->getVideoDriver()->getTexture(filename));
     if(capa == -1) // agregado por Habatar
     {
         for(u32 i=0; i< nodon->getMaterialCount(); ++i)
         {
                 nodon->setMaterialTexture(i, midevice->getVideoDriver()->getTexture(filename));
         }
     }
     else
     {
         nodon->setMaterialTexture(capa, midevice->getVideoDriver()->getTexture(filename));
     }

}

/*!
\param textu Objeto Textura
\param capa se refiere al material en donde se texturizara. Por defecto los texturiza todos, si desea especificar el material a texturizar usar el numero del material.

Si no desea especificar el material simplemente ignore el par&aacute;metro capa y coloque solo la ruta de la imagen.

Ejemplo:
\code
Cubo.Texturizar(Madera);
\endcode
\code
Cubo.Texturizar(Madera, 2);
\endcode
*/
void GDT::Nodo::NodoBase::Texturizar(Textura textu, int capa)
{
     //nodon->setMaterialTexture(capa, textu);
     if(capa == -1) // agregado por Habatar
     {
         for(u32 i=0; i< nodon->getMaterialCount(); ++i)
         {
                 nodon->setMaterialTexture(i, textu.tex);
         }
     }
     else
     {
         nodon->setMaterialTexture(capa, textu.tex);
     }
}

/*!
\param cual Material
\param enable true para activar el material, false para desactivarlo

Los materiales son:

    - WIREFRAME
      Wireframe, o alambrado, hace que se vean las l&iacute;neas de los pol&iacute;gonos, por defecto: false
    - SOMBREADO_GOURAUD
      Sombreado suavizado o plano, por defecto: true
    - ILUMINAR
      Hace que le afecte la luz, por defecto: true
    - CORTAR_CARAS_TRASERAS
      Se dibujan las caras traseras, por defecto: false
    - FILTRO_BILINEAR
      Se aplica filtro bilinear, por defecto: true
    - FILTRO_TRILINEAR
      Se aplica filtro trilinear, por defecto: false
    - NIEBLA
      Hace que le afecte la niebla, por defecto: false

Ejemplo:
\code
Cubo.MaterialFlag( WIREFRAME, true );
\endcode
*/
void GDT::Nodo::NodoBase::MaterialFlag(E_MATERIAL_FLAG cual, bool enable)
{
     nodon->setMaterialFlag(cual, enable);
}

/*!
\param cual Material

Los tipos de materiales son:

    - SOLIDO
      Est&aacute;ndar s&oacute;lido, s&oacute;lo se usa la primera textura.
    - SOLIDO_2_CAPAS
      S&oacute;lido con 2 capas de textura. La segunda textura es aplicada por transparencia
    - LIGHTMAP
      Lightmap est&aacute;ndar.
    - LIGHTMAP_ADD
    - LIGHTMAP_M2
    - LIGHTMAP_M4
    - LIGHTMAP_ILUMINADO
    - LIGHTMAP_ILUMINADO_M2
    - LIGHTMAP_ILUMINADO_M4
    - MAPA_ESFERICO
      Mapa de reflexi&oacute;n esf&eacute;rica est&aacute;ndar.
    - REFLECCION_2_CAPAS
      La primera textura normal, la segunda de reflexi&oacute;n esf&eacute;rica.
    - TRANSPARENTE_MAS_COLOR
      Transparencia est&aacute;ndar.
    - TRANSPARENTE_ALPHA
      Transparencia usando el canal alpha de la textura.
    - TRANSPARENTE_ALPHA_REF
    - TRANSPARENTE_VERTICE_ALPHA
      Crea la transparencia a partir de el valor alpha de cada v&eacute;rtice
    - TRANSPARENTE_REFLECCION_2_CAPAS
    - MAPA_NORMAL_SOLIDO
    - MAPA_NORMAL_TRANSPARENTE_MAS_COLOR
      M&aacute;s conocido como normal mapping o bump mapping, para sacar relieve y que cambie la iluminaci&oacute;n para dar el efecto de relieve en una geometr&iacute;a a partir de una textura.
    - MAPA_NORMAL_TRANSPARENTE_VERTICE_ALPHA
    - MAPA_PARARELO_SOLIDO
      M&aacute;s conocido como Parallax Mapping, la evoluci&oacute;n del normal mapping
    - MAPA_PARARELO_TRANSPARENTE_MAS_COLOR
    - MAPA_PARARELO_TRANSPARENTE_VERTICE_ALPHA

Ejemplo:
\code
Cubo.MaterialTipo( MAPA_ESFERICO );
\endcode
*/
void GDT::Nodo::NodoBase::MaterialTipo(E_MATERIAL_TYPE cual)
{
     nodon->setMaterialType(cual);
}

/*!
Se usa para normal mapping y parallax mapping.

Ejemplo:
\code
Cubo.MaterialRelieve(0.035);
\endcode
*/
void GDT::Nodo::NodoBase::MaterialRelieve(float alt)
{
     	nodon->getMaterial(0).MaterialTypeParam = alt; // adjust height for parallax effect
}

/*!
\author Habatar

\param r,g,b Rojo, Verde, Azul. De 0 a 255.
\param capa se aplica si se quiere especificar un material en especial del objeto, si no es as&iacute; ignorarlo.

Ejemplo:
\code
Cubo.ColorAmbiente(200,100,100);
\endcode
*/
void GDT::Nodo::NodoBase::ColorAmbiente(s32 r,s32 g,s32 b, int capa )
{
	if(capa == -1)
	{
		for(u32 i=0; i< nodon->getMaterialCount(); ++i)
		{
			nodon->getMaterial(i).AmbientColor.setRed(r);
			nodon->getMaterial(i).AmbientColor.setGreen(g);
			nodon->getMaterial(i).AmbientColor.setBlue(b);
		}
	}
	else
	{
			nodon->getMaterial(capa).AmbientColor.setRed(r);
			nodon->getMaterial(capa).AmbientColor.setGreen(g);
			nodon->getMaterial(capa).AmbientColor.setBlue(b);
	}
}

/*!
\param r,g,b Rojo, Verde, Azul. De 0 a 255.
\param capa se aplica si se quiere especificar un material en especial del objeto, si no es as&iacute; ignorarlo.

Ejemplo:
\code
Cubo.ColorDifuso(200,100,100);
\endcode
*/
void GDT::Nodo::NodoBase::ColorDifuso(s32 r,s32 g,s32 b,  int capa)
{
     if(capa == -1)
     {
         for(u32 i=0; i< nodon->getMaterialCount(); ++i)
         {
                 nodon->getMaterial(i).DiffuseColor.setRed(r);
                 nodon->getMaterial(i).DiffuseColor.setGreen(g);
                 nodon->getMaterial(i).DiffuseColor.setBlue(b);
         }
     }
     else
     {
             nodon->getMaterial(capa).DiffuseColor.setRed(r);
             nodon->getMaterial(capa).DiffuseColor.setGreen(g);
             nodon->getMaterial(capa).DiffuseColor.setBlue(b);
     }
}

/*!
\param r,g,b Rojo, Verde, Azul. De 0 a 255.
\param capa se aplica si se quiere especificar un material en especial del objeto, si no es as&iacute; ignorarlo.

Ejemplo:
\code
Cubo.ColorEmisivo(200,100,100);
\endcode
*/
void GDT::Nodo::NodoBase::ColorEmisivo(s32 r,s32 g,s32 b,  int capa)
{
     if(capa == -1)
     {
         for(u32 i=0; i< nodon->getMaterialCount(); ++i)
         {
                 nodon->getMaterial(i).EmissiveColor.setRed(r);
                 nodon->getMaterial(i).EmissiveColor.setGreen(g);
                 nodon->getMaterial(i).EmissiveColor.setBlue(b);
         }
     }
     else
     {
                 nodon->getMaterial(capa).EmissiveColor.setRed(r);
                 nodon->getMaterial(capa).EmissiveColor.setGreen(g);
                 nodon->getMaterial(capa).EmissiveColor.setBlue(b);
     }
}

/*!
\param r,g,b Rojo, Verde, Azul. De 0 a 255.
\param capa se aplica si se quiere especificar un material en especial del objeto, si no es as&iacute; ignorarlo.

Ejemplo:
\code
Cubo.ColorEmisivo(200,100,100);
\endcode
*/
void GDT::Nodo::NodoBase::ColorEspecular(s32 r,s32 g,s32 b,  int capa)
{
     if(capa == -1)
     {
         for(u32 i=0; i< nodon->getMaterialCount(); ++i)
         {
                 nodon->getMaterial(i).SpecularColor.setRed(r);
                 nodon->getMaterial(i).SpecularColor.setGreen(g);
                 nodon->getMaterial(i).SpecularColor.setBlue(b);
         }
     }
     else
     {
                 nodon->getMaterial(capa).SpecularColor.setRed(r);
                 nodon->getMaterial(capa).SpecularColor.setGreen(g);
                 nodon->getMaterial(capa).SpecularColor.setBlue(b);
     }
}

/*!
\param v Visivilidad, entre 0 y 255
\param capa
Ejemplo:
\code
Cubo.NivelTransparencia( 155 );
\endcode
*/
void GDT::Nodo::NodoBase::NivelTransparencia(s32 v,  int capa)
{
    
    coloralphaD = v;
    coloralphaEm = v;
    coloralphaE = v;


     if(capa == -1)
     {
         for(u32 i=0; i< nodon->getMaterialCount(); ++i)
         {
                 nodon->getMaterial(i).DiffuseColor.setAlpha (v);
                 nodon->getMaterial(i).EmissiveColor.setAlpha(v);
                 nodon->getMaterial(i).SpecularColor.setAlpha (v);
         }
     }
     else
     {
                 nodon->getMaterial(capa).DiffuseColor.setAlpha (v);
                 nodon->getMaterial(capa).EmissiveColor.setAlpha(v);
                 nodon->getMaterial(capa).SpecularColor.setAlpha (v);
     }
}

/*!
Con este m&eacute;todo se puede hacer que el nodo al colisionar con un Escenario tenga la respuesta de colisi&oacute;n autom&aacute;ticamente es decir no traspase el pol&iacute;gono, cambie la direcci&oacute;n del movimiento, etc., es un completo sistema de colisiones con su respuesta incluyendo gravedad.

\param selector son los datos de colisi&oacute;n del Escenario se obtienen con RetornarDatos.
\param RadioX,RadioY,RadioZ son los valores de la elipse que colisiona con el Escenario
\param TraslacionX,TraslacionY,TraslacionZ es la translaci&oacute;n de dicho elipse
\param GravedadX,GravedadY,GravedadZ es la gravedad, si no se desea usar gravedad simplemente se dejan en cero.

Ejemplo:
\code
Cubo.CrearColision( Escenario.RetornarDatos(), 3,3,3,0,0,0,0,-0.1,0 );
\endcode
*/
void GDT::Nodo::NodoBase::CrearColision(ITriangleSelector* selector, float RadioX, float RadioY, float RadioZ, float GravedadX, float GravedadY, float GravedadZ, float TraslacionX, float TraslacionY, float TraslacionZ)
{
	ISceneManager* mismgr=midevice->getSceneManager();
	scene::ISceneNodeAnimator* anim = mismgr->createCollisionResponseAnimator(
		selector, nodon, core::vector3df(RadioX,RadioY,RadioZ),
		core::vector3df(TraslacionX,TraslacionY,TraslacionZ),
		core::vector3df(GravedadX,GravedadY,GravedadZ));
	nodon->addAnimator(anim);
	//anim->drop();
}


/*!
\param estado true para visible, false para invisible

Ejemplo:
\code
Cubo.Visible( false );
\endcode
*/
void GDT::Nodo::NodoBase::Visible(bool estado)
{
   nodon->setVisible(estado);
}

/*!
\return Estado de visibilidad

Devuelve true ( 1 ) o false ( 0 ) seg&uacute;n si se esta mostrando el nodo o no.

Ejemplo:
\code
Esta = Cubo.EsVisible( );
\endcode
*/
bool GDT::Nodo::NodoBase::EsVisible()
{
     return nodon->isVisible();
}

void GDT::Nodo::NodoBase::Destruir(void)
{
      nodon->remove();
}

void GDT::Nodo::NodoBase::Brillo(float intensidad)
{
        nodon->getMaterial(0).Shininess = intensidad;
}


int GDT::Nodo::NodoBase::RetornarColorEmisivoR()
{
       SColor Amb = nodon->getMaterial(0).EmissiveColor;
       return int(Amb.getRed() );
}

int GDT::Nodo::NodoBase::RetornarColorEmisivoG()
{
       SColor Amb = nodon->getMaterial(0).EmissiveColor;
       return int(Amb.getGreen());
}

int GDT::Nodo::NodoBase::RetornarColorEmisivoB()                
{
       SColor Amb = nodon->getMaterial(0).EmissiveColor;
       return int(Amb.getBlue());
}

int GDT::Nodo::NodoBase::RetornarColorDifusoR()
{
       SColor Dif = nodon->getMaterial(0).DiffuseColor;
       return int(Dif.getRed());
}

int GDT::Nodo::NodoBase::RetornarColorDifusoG()
{
       SColor Dif = nodon->getMaterial(0).DiffuseColor;
       return int(Dif.getGreen());
}

int GDT::Nodo::NodoBase::RetornarColorDifusoB()                
{
       SColor Dif = nodon->getMaterial(0).DiffuseColor;
       return int(Dif.getBlue());
}
      

int GDT::Nodo::NodoBase::RetornarColorEspecularR()
{
       SColor Dif = nodon->getMaterial(0).SpecularColor;
       return int(Dif.getRed());
}

int GDT::Nodo::NodoBase::RetornarColorEspecularG()
{
       SColor Dif = nodon->getMaterial(0).SpecularColor;
       return int(Dif.getGreen());
}

int GDT::Nodo::NodoBase::RetornarColorEspecularB()        
{
       SColor Dif = nodon->getMaterial(0).SpecularColor;
       return int(Dif.getBlue());
}        


int GDT::Nodo::NodoBase::RetornarColorAmbienteR()
{
       SColor Dif = nodon->getMaterial(0).AmbientColor;
       return int(Dif.getRed());
}

int GDT::Nodo::NodoBase::RetornarColorAmbienteG()
{
       SColor Dif = nodon->getMaterial(0).AmbientColor;
       return int(Dif.getGreen());
}

int GDT::Nodo::NodoBase::RetornarColorAmbienteB()                
{
       SColor Dif = nodon->getMaterial(0).AmbientColor;
       return int(Dif.getBlue());
}        

int GDT::Nodo::NodoBase::RetornarBrillo()                
{        
      return (int)nodon->getMaterial(0).Shininess;
}

void GDT::Nodo::NodoBase::AgregarAnimador(Animador Animate)
{
     nodon->addAnimator(Animate.Retornar());
}
