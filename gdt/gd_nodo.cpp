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


#include "gd_nodo.h" // class's header file

// class constructor
GD_Nodo::GD_Nodo()
{
	// insert your code here


}

// class destructor
GD_Nodo::~GD_Nodo()
{
	// insert your code here
}


void GD_Nodo::RegistrarDevice(	IrrlichtDevice *device )
{
	midevice = device;
}


//! Posiciona el objeto en las cordenadas X,Y,Z globales
void GD_Nodo::Posicionar(float x, float y, float z)
{

     nodon->setPosition(vector3df(x, y, z));
}

//! Posiciona el objeto en las cordenadas X,Y,Z dadas por un vector
void GD_Nodo::Posicionar(vector3df pos)
{

     nodon->setPosition(pos);
}

//! Posiciona el objeto en X conservando su posicion en Y , Z
void GD_Nodo::PosicionarX(float x)
{
     vector3df poso;
     poso = nodon->getPosition();
     nodon->setPosition(vector3df(x, poso.Y, poso.Z));

}

//! Posiciona el objeto en Y conservando su posicion en X , Z
void GD_Nodo::PosicionarY(float y)
{
     vector3df poso;
     poso = nodon->getPosition();
     nodon->setPosition(vector3df(poso.X, y, poso.Z));

}

//! Posiciona el objeto en Z conservando su posicion en X , Y
void GD_Nodo::PosicionarZ(float z)
{
     vector3df poso;
     poso = nodon->getPosition();
     nodon->setPosition(vector3df(poso.X, poso.Y, z));

}

//! Devuelve la posicion actual del objeto como vector
vector3df GD_Nodo::Posicion()
{
     vector3df poso;
     poso = nodon->getPosition();
     return poso;
}

//! Devuelve la posicion X actual del objeto
float GD_Nodo::PosicionX()
{
     vector3df poso;
     poso = nodon->getPosition();
     return poso.X;
}

//! Devuelve la posicion Y actual del objeto
float GD_Nodo::PosicionY()
{
     vector3df poso;
     poso = nodon->getPosition();
     return poso.Y;
}

//! Devuelve la posicion Z actual del objeto
float GD_Nodo::PosicionZ()
{
     vector3df poso;
     poso = nodon->getPosition();
     return poso.Z;
}


//! Cambia la rotacion del objeto en X,Y,Z
void GD_Nodo::Rotar(float x, float y, float z)
{
     nodon->setRotation(vector3df(x, y, z));
}

//! Cambia la rotacion X
void GD_Nodo::RotarX(float x)
{
     vector3df roto;
     roto = nodon->getRotation();
     nodon->setRotation(vector3df(x, roto.Y, roto.Z));
}

//! Cambia la rotacion Y
void GD_Nodo::RotarY(float y)
{
     vector3df roto;
     roto = nodon->getRotation();
     nodon->setRotation(vector3df(roto.X, y, roto.Z));
}

//! Cambia la rotacion Z
void GD_Nodo::RotarZ(float z)
{
     vector3df roto;
     roto = nodon->getRotation();
     nodon->setRotation(vector3df(roto.X, roto.Y, z));
}

//! Devuelve la rotacion X actual
float GD_Nodo::RotacionX()
{
     vector3df roto;
     roto = nodon->getRotation();
     return roto.X;
}

//! Devuelve la rotacion Y actual
float GD_Nodo::RotacionY()
{
     vector3df roto;
     roto = nodon->getRotation();
     return roto.Y;
}

//! Devuelve la rotacion Z actual
float GD_Nodo::RotacionZ()
{
     vector3df roto;
     roto = nodon->getRotation();
     return roto.Z;
}

//! Cambia la rotacion del objeto por vector
void GD_Nodo::Rotar(vector3df rot)
{
     nodon->setRotation(rot);
}

//! Devuelve la rotacion actual en un vector
vector3df GD_Nodo::Rotacion()
{
   return nodon->getRotation();
}


//! Cambia el tamaño del objeto en X,Y,Z
void GD_Nodo::Escalar(float x, float y, float z)
{
     nodon->setScale(vector3df(x, y, z));
     nodon->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true);
     
}

//! Cambia el tamaño en X (ancho)
// puede tener problemas cuando se haya escalado previamente
void GD_Nodo::EscalarX(float x)
{
     nodon->setScale(vector3df(x, 1, 1));
   	 nodon->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true);     
}

//! Cambia el tamaño en Y (alto)
// puede tener problemas cuando se haya escalado previamente
void GD_Nodo::EscalarY(float y)
{
     vector3df scal;
     nodon->getScale();
     nodon->setScale(vector3df(1, y, 1));
   	 nodon->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true);     
}

//! Cambia el tamaño en Z (largo)
// puede tener problemas cuando se haya escalado previamente
void GD_Nodo::EscalarZ(float z)
{
     vector3df scal;
     nodon->getScale();
     nodon->setScale(vector3df(1, 1, z));
   	 nodon->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true);     
}

//! Mueve el objeto segun su orientacion actual en X(izquierda,derecha),Y(arriba,abajo),Z(frente,atras)
/**

*/
//Jedive	C++ code for a hypothetical MoveNode() function :)
void GD_Nodo::Mover(float x, float y, float z)
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

//! Mueve el objeto segun su orientacion actual en X(izquierda,derecha)
void GD_Nodo::MoverX(float x)
{
     Mover(x,0,0);
}

//! Mueve el objeto segun su orientacion actual en Y(arriba,abajo)
void GD_Nodo::MoverY(float y)
{
     Mover(0,y,0);
}

//! Mueve el objeto segun su orientacion actual en Z(frente,atras)
void GD_Nodo::MoverZ(float z)
{
     Mover(0,0,z);
}

//! Gira el objeto segun su orientacion actual en X,Y,Z
void GD_Nodo::Girar(float x, float y, float z)
{
     vector3df roto;
     roto = nodon->getRotation();
     nodon->setRotation(vector3df(x+roto.X, y+roto.Y, z+roto.Z));
}
//! Gira el objeto segun su orientacion actual en X
void GD_Nodo::GirarX(float x)
{
     Girar(x,0,0);
}
//! Gira el objeto segun su orientacion actual en Y
void GD_Nodo::GirarY(float y)
{
     Girar(0,y,0);
}
//! Gira el objeto segun su orientacion actual en Z
void GD_Nodo::GirarZ(float z)
{
     Girar(0,0,z);
}


void GD_Nodo::Anclar(GD_Nodo gdnodito)
{
     nodon->addChild(gdnodito.nodon);
}

void GD_Nodo::DesAnclar(GD_Nodo gdnodito)
{
     nodon->removeChild(gdnodito.nodon);
}



//! Aplica una textura al objeto
void GD_Nodo::Texturizar(char* filename, int capa)
{
     //nodon->setMaterialTexture(capa, midevice->getVideoDriver()->getTexture(filename));
     if(capa == -1) // agregado por Habatar
     {
         for(s32 i=0; i< nodon->getMaterialCount(); ++i)
         {
                 nodon->setMaterialTexture(i, midevice->getVideoDriver()->getTexture(filename));
         }
     }
     else
     {
         nodon->setMaterialTexture(capa, midevice->getVideoDriver()->getTexture(filename));
     }  
          
}

//! Aplica una textura al objeto
void GD_Nodo::Texturizar(GD_Textura textu, int capa)
{
     //nodon->setMaterialTexture(capa, textu);
     if(capa == -1) // agregado por Habatar
     {
         for(s32 i=0; i< nodon->getMaterialCount(); ++i)
         {
                 nodon->setMaterialTexture(i, textu.tex);
         }
     }
     else
     {
         nodon->setMaterialTexture(capa, textu.tex);
     }  
}


//! Activa o desactiva un material de renderizado
void GD_Nodo::MaterialFlag(E_MATERIAL_FLAG cual, bool enable)
{
     nodon->setMaterialFlag(cual, enable);
}

//! Cambia el tipo material de renderizado
void GD_Nodo::MaterialTipo(E_MATERIAL_TYPE cual)
{
     nodon->setMaterialType(cual);
}

void GD_Nodo::MaterialRelieve(float alt)
{
     	nodon->getMaterial(0).MaterialTypeParam = alt; // adjust height for parallax effect
}

void GD_Nodo::ColorAmbiente(s32 r,s32 g,s32 b, int capa )
{
     if(capa == -1)
     {
         for(s32 i=0; i< nodon->getMaterialCount(); ++i)
         {
                 nodon->getMaterial(i).AmbientColor.set(coloralphaA,r,b,g);
         }
     }
     else
     {
         nodon->getMaterial(capa).AmbientColor.set(coloralphaA,r,b,g);
     }     
}

void GD_Nodo::ColorDifuso(s32 r,s32 g,s32 b,  int capa)
{
     if(capa == -1)
     {
         for(s32 i=0; i< nodon->getMaterialCount(); ++i)
         {
                 nodon->getMaterial(i).DiffuseColor.set(coloralphaD,r,b,g);
         }
     }
     else
     {
         nodon->getMaterial(capa).DiffuseColor.set(coloralphaD,r,b,g);
     }
}

void GD_Nodo::ColorEmisivo(s32 r,s32 g,s32 b,  int capa)
{
     if(capa == -1)
     {
         for(s32 i=0; i< nodon->getMaterialCount(); ++i)
         {
                 nodon->getMaterial(i).EmissiveColor.set(coloralphaEm,r,b,g);
         }
     }
     else
     {
         nodon->getMaterial(capa).EmissiveColor.set(coloralphaEm,r,b,g);
     }
}

void GD_Nodo::ColorEspecular(s32 r,s32 g,s32 b,  int capa)
{
     if(capa == -1)
     {
         for(s32 i=0; i< nodon->getMaterialCount(); ++i)
         {
                 nodon->getMaterial(i).SpecularColor.set(coloralphaE,r,b,g);
         }
     }
     else
     {
         nodon->getMaterial(capa).SpecularColor.set(coloralphaE,r,b,g);
     }
}

void GD_Nodo::NivelTransparencia(s32 v)
{
    coloralphaA = 100;
    coloralphaD = 100;
    coloralphaEm = 100;
    coloralphaE = 100;
    
    /*nodon->getMaterial(0).AmbientColor.set(coloralphaA,100,100,100);
    nodon->getMaterial(0).DiffuseColor.set(coloralphaD,100,100,100);
    nodon->getMaterial(0).EmissiveColor.set(coloralphaEm,100,100,100);
    nodon->getMaterial(0).SpecularColor.set(coloralphaE,100,100,100);   */
    
    
    
}



void GD_Nodo::CrearColision( ITriangleSelector* selector,float radiox, float radioy,float radioz,float transx,float transy,float transz,float grax,float gray, float graz)
{

    ISceneManager* mismgr=midevice->getSceneManager();

	scene::ISceneNodeAnimator* anim = mismgr->createCollisionResponseAnimator(
		selector, nodon, core::vector3df(radiox,radioy,radioz),
		core::vector3df(transx,transy,transz),
		core::vector3df(grax,gray,graz));
	nodon->addAnimator(anim);
	//anim->drop();
}

void GD_Nodo::Visible(bool estado)
{
   nodon->setVisible(estado);
}

bool GD_Nodo::EsVisible()
{
     return nodon->isVisible();
}

vector3df GD_Nodo::Orientar(vector3df destino)
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

}

void GD_Nodo::Destruir(void)
{
      nodon->remove();
}

vector3df GD_Nodo::Orientar(GD_Nodo gdnodito)
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
}

float GD_Nodo::TamanoX()
{
      float x;
      x = nodon->getTransformedBoundingBox().getExtent().X;
      return x;
}

float GD_Nodo::TamanoY()
{
      float y;
      y = nodon->getTransformedBoundingBox().getExtent().Y;
      return y;
}

float GD_Nodo::TamanoZ()
{
      float z;
      z = nodon->getTransformedBoundingBox().getExtent().Z;
      return z;
}

vector3df GD_Nodo::Tamano()
{
       vector3df vect;
       vect = nodon->getTransformedBoundingBox().getExtent();
       return vect;
}
