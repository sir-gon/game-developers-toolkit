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
* \class GDColisiones3d
*
* Clase Colisiones 3d para mallas.
*
* De ahora en adelante, se tratar&aacute; como "el Nodo" al objeto que
* se sea instanciado a partir de esta clase o una clase hija.
* 
* Por ejemplo As&iacute;:
*
\code
#include "gdt.h"

GD_Sistema Sistema;
GD_Malla Nodo;

int main {

  // el resto del programa

  return 0;
}
\endcode
*
* A su vez, cualquier dato de tipo "ITriangleSelector" se le llamara Escenario.
*
* Cabe distinguir la diferencia, ya que GD_Escenario es una clase de GDT,
* e ITriangleSelector es un tipo definido en el motor gr&aacute;fico Irrlicht.
* Sin embargo, estan relacionados, ya que el Escenario es una propiedad de
* GD_Escenario, as&iacute; que si en algun caso hace falta, se puede obtener
* el ITriangleSelector desde el Escenario, o asignarle un ITriangleSelector
* desde afuera.
*/

#include "gd_colisiones3d.h"

void MoverNodo(ISceneNode* nododumy, float x, float y, float z);

GD_Colisiones3d::GD_Colisiones3d()
{

}

GD_Colisiones3d::~GD_Colisiones3d()
{

}

/*void GD_Colisiones3d::ActivarColisiones(IMesh* static_mesh)
{
   //static_mesh=mesh->getMesh(0);

   if (static_mesh)
      nodon = mesh_smgr->addOctTreeSceneNode(static_mesh);

   if(nodon)
   {
      selector = mesh_smgr->createOctTreeTriangleSelector(static_mesh, nodon, 128);
		nodon->setTriangleSelector(selector);
		selector->drop();
   }
}
*/

/*!
Colisiones simples con el Escenario, con valores predeterminados.
*/
void GD_Colisiones3d::CrearColision(ITriangleSelector* Mundo)
{


   colision = mesh_smgr->createCollisionResponseAnimator(
                                             Mundo, nodon /*, core::vector3df(10,10,10),
                                             core::vector3df(0,-0.0f,0),
                                             core::vector3df(0,1,0)*/);

	anim=colision;

	nodon->addAnimator(anim);
	anim->drop();

}

/*! 
Con este m&eacute;todo se puede hacer que el nodo al colisionar con un GD_Escenario tenga la respuesta de colisi&oacute;n autom&aacute;ticamente es decir no traspase el pol&iacute;gono, cambie la direcci&oacute;n del movimiento, etc., es un completo sistema de colisiones con su respuesta incluyendo gravedad.

\param Mundo son los datos de colisi&oacute;n del GD_Escenario se obtienen con. GD_Escenario::RetornarDatos().
\param Radio vector con los radio del elipsoide que colisiona con el GD_Escenario.
\param Traslacion vector de la translaci&oacute;n de dicho elipse.
\param Gravedad vector de la gravedad en cada eje, si no se desea usar gravedad simplemente se dejan en ceros.
*/
void GD_Colisiones3d::CrearColision(ITriangleSelector* Mundo,core::vector3df Radio, core::vector3df Gravedad,core::vector3df Traslacion)
{


   colision = mesh_smgr->createCollisionResponseAnimator(Mundo, nodon , Radio,Gravedad,Traslacion);

   anim=colision;

	nodon->addAnimator(anim);
	anim->drop();

}

/*!
Con este m&eacute;todo se puede hacer que el nodo al colisionar con un GD_Escenario tenga la respuesta de colisi&oacute;n autom&aacute;ticamente es decir no traspase el pol&iacute;gono, cambie la direcci&oacute;n del movimiento, etc., es un completo sistema de colisiones con su respuesta incluyendo gravedad.

\param selector son los datos de colisi&oacute;n del GD_Escenario se obtienen con GD_Escenario::RetornarDatos().
\param RadioX,RadioY,RadioZ
\param GravedadX,GravedadY,GravedadZ fuerza de gravedad en cada componente. Si no se desea dejar en ceros.
\param TraslacionX,TraslacionY,TraslacionZ coordenadas de la posición de la elipse con respecto al objeto.
*/
void GD_Colisiones3d::CrearColision(ITriangleSelector* selector,
                          float RadioX, float RadioY, float RadioZ,
                          float GravedadX, float GravedadY, float GravedadZ,
                          float TraslacionX, float TraslacionY, float TraslacionZ)
{
   colision = mesh_smgr->createCollisionResponseAnimator(selector, nodon ,
	core::vector3df(RadioX,RadioY,RadioZ), 
	core::vector3df(GravedadX,GravedadY,GravedadZ),
	core::vector3df(TraslacionX,TraslacionY,TraslacionZ));

   anim=colision;

   nodon->addAnimator(anim);
   anim->drop();

}

/*!
Si se han cambiado los valores de colisión, tales como: Radio, Gravedad o Traslacion, con este m&eacute;todo se recrea el valor de la animacion.
*/
void GD_Colisiones3d::ActualizarDatosColision()
{
	anim=colision;
	nodon->addAnimator(anim);
	anim->drop();
}


//Obtencion de valores *******************************************************
/*!
\return un vector, cuyas componentes son los radios del elipsoide.
*/
core::vector3df GD_Colisiones3d::RetornarRadioElipsoide()
{
   return colision->getEllipsoidRadius();
}

/*!
\return un vector, cuyas componentes son las traslaciones del elipsoide.
*/
core::vector3df GD_Colisiones3d::RetornarTraslacionElipsoide()
{
   return colision->getEllipsoidTranslation();
}

/*!
\return un vector, cuyas componentes son la gravedad en cada eje
*/
core::vector3df GD_Colisiones3d::RetornarGravedad()
{
   return colision->getGravity();
}

/*!
*/
ITriangleSelector* GD_Colisiones3d::RetornarDatosMundo()
{
   return colision->getWorld();
}

/*!
\return true si el Nodo est&aacute; cayendo (no est&aacute; apoyado sobre el escenario)
*/
bool GD_Colisiones3d::Callendo()
{
   return colision->isFalling();
}


// Asignacion de valores *****************************************************
/*!
\param vector_3d vector cuyas componentes son los radios del elipsoide.
*/
void GD_Colisiones3d::AsignarRadioElipsoide(core::vector3df vector_3d)
{
  colision->setEllipsoidRadius(vector_3d);
}

/*!
\param x,y,z son los radios del elipsoide.
*/
void GD_Colisiones3d::AsignarRadioElipsoide(float x, float y, float z)
{
  colision->setEllipsoidRadius(core::vector3df(x,y,z));
}

/*!
\param vector_3d vector cuyas componentes son las traslaciones del elipsoide.
*/
void GD_Colisiones3d::AsignarTraslacionElipsoide(core::vector3df vector_3d)
{
   colision->setEllipsoidTranslation(vector_3d);
}

/*!
\param x,y,z son las traslaciones del elipsoide.
*/
void GD_Colisiones3d::AsignarTraslacionElipsoide(float x, float y, float z)
{
   colision->setEllipsoidTranslation(core::vector3df(x,y,z));
}

/*!
\param vector_3d vector cuyas componentes son la gravedad en cada eje.
*/
void GD_Colisiones3d::AsignarGravedad(core::vector3df vector_3d)
{
   colision->setGravity(vector_3d);
}

/*!
\param x,y,z son la gravedad en cada eje.
*/
void GD_Colisiones3d::AsignarGravedad(float x, float y, float z)
{
   colision->setGravity(core::vector3df(x,y,z));
}

/*!
\param scen es el GD_Escenario que se reemplazara.
*/
void GD_Colisiones3d::AsignarDatosColision(GD_Escenario scen)
{
   ITriangleSelector *nuevoMundo = scen.RetornarDatos();
   colision->setWorld(nuevoMundo);
}

//****************************************************************************
/* ESTA FUNCION ESTA DEMAS
// YA EXISTE en GD_Nodo y que se hereda
ITriangleSelector* GD_Colisiones3d::RetornarDatosSelector()
{
     return selector;
}
*/

/*!
\param scen es un GD_Escenario

Crea un sistema de colisiones entre una elipse y un GD_Escenario con su respuesta, es decir, evita autom&aacute;ticamente que traspase pol&iacute;gonos y dem&aacute;s respuestas. Incluye tambi&eacute;n gravedad.

Ejemplo:
\code
Protagonista.CrearColision( Escenario );
\endcode
*/
void GD_Colisiones3d::CrearColision(GD_Escenario scen)
{

ITriangleSelector* Mundo = scen.RetornarDatos();

   colision = mesh_smgr->createCollisionResponseAnimator(
                                             Mundo, nodon /*, core::vector3df(10,10,10),
                                             core::vector3df(0,-0.0f,0),
                                             core::vector3df(0,1,0)*/);

   anim=colision;

	nodon->addAnimator(anim);
	anim->drop();

}

/*!
\param scen es el escenario.
\param Radio los radios de la elipse.
\param Gravedad si no se desea dejar en ceros.
\param Traslacion la posición de la elipse con respecto al objeto

Crea un sistema de colisiones entre una elipse y un GD_Escenario con su respuesta, es decir, evita autom&aacute;ticamente que traspase pol&iacute;gonos y dem&aacute;s respuestas. Incluye tambi&eacute;n gravedad.

Ejemplo:
\code
Protagonista.CrearColision( Escenario,vectElipse, vectGravedad, vectTranslacionElipse);
\endcode
*/
void GD_Colisiones3d::CrearColision(GD_Escenario scen,core::vector3df Radio,
                                       core::vector3df Gravedad,core::vector3df Traslacion)
{

ITriangleSelector* Mundo = scen.RetornarDatos();

   colision = mesh_smgr->createCollisionResponseAnimator(Mundo, nodon , Radio,Gravedad,Traslacion);

   anim=colision;

	nodon->addAnimator(anim);
	anim->drop();

}

/*!
\param scen es el escenario (un GD_Escenario)
\param RadioX,RadioY,RadioZ
\param GravedadX,GravedadY,GravedadZ fuerza de gravedad en cada componente. Si no se desea dejar en ceros.
\param TraslacionX,TraslacionY,TraslacionZ coordenadas de la posición de la elipse con respecto al objeto.

Ejemplo:
\code
Protagonista.CrearColision( Escenario,1,1,1,0,-0.1,0,0,0,0 );
\endcode
*/
void GD_Colisiones3d::CrearColision(GD_Escenario scen, float RadioX,
                                                              float RadioY,
                                                              float RadioZ,
                                                              float GravedadX,
                                                              float GravedadY,
                                                              float GravedadZ, 
                                                              float TraslacionX, 
                                                              float TraslacionY, 
                                                              float TraslacionZ)
{

ITriangleSelector* Mundo = scen.RetornarDatos();

   colision = mesh_smgr->createCollisionResponseAnimator(Mundo, nodon , core::vector3df(RadioX,RadioY,RadioZ),
                                                                      core::vector3df(GravedadX,GravedadY,GravedadZ),
                                                                      core::vector3df(TraslacionX,TraslacionY,TraslacionZ));

   anim=colision;

	nodon->addAnimator(anim);
	anim->drop();

}
      

/*!
*/
aabbox3d<f32> GD_Colisiones3d::RetornarCaja()
{
   return nodon->getTransformedBoundingBox();
}

bool GD_Colisiones3d::ColisionConCaja(aabbox3d<f32> Cajon)
{
     bool coli;
     coli = nodon->getTransformedBoundingBox().intersectsWithBox(Cajon);
     return coli;
}

/*!
\return true si esta colisionando el objeto con el escenario, o false en caso contrario.
*/
bool GD_Colisiones3d::ColisionConEscenario( ITriangleSelector* trian )
{
     
  /*   if(!AntiBug){
          AntiBug = 1;
          return false;
     }   */

      coli=0;
      posmiacoli = nodon->getPosition();

     // punto E
      DummyNodo->setPosition(nodon->getPosition());
      DummyNodo->setRotation(nodon->getRotation());
      MoverNodo(DummyNodo,0.f,0.f,32448763.f);
      vfin = DummyNodo->getPosition();
      
      if(ColisionConRayo( posmiacoli, vfin, trian)){
          intersec_coli_e->setPosition(RetornarInterseccionRayo( posmiacoli, vfin, trian));
          coli = nodon->getTransformedBoundingBox().intersectsWithBox(intersec_coli_e->getTransformedBoundingBox());
    
          if(coli && intersec_coli_e->getPosition().X != 6456.365f && intersec_coli_e->getPosition().Y != 6456.365f && intersec_coli_e->getPosition().Z != 6456.365f){
                  return true;
          } 
      }
      // punto A
      DummyNodo->setPosition(nodon->getPosition());
      DummyNodo->setRotation(nodon->getRotation());
      MoverNodo(DummyNodo,32448763.f,0.f,0.f);
      vfin = DummyNodo->getPosition();
      
      if(ColisionConRayo( posmiacoli, vfin, trian)){
          intersec_coli_a->setPosition(RetornarInterseccionRayo( posmiacoli, vfin, trian));
          coli = nodon->getTransformedBoundingBox().intersectsWithBox(intersec_coli_a->getTransformedBoundingBox());
    
          if(coli && intersec_coli_a->getPosition().X != 6456.365f && intersec_coli_a->getPosition().Y != 6456.365f && intersec_coli_a->getPosition().Z != 6456.365f){
                  return true;
          }
      }

      // punto B
      DummyNodo->setPosition(nodon->getPosition());
      DummyNodo->setRotation(nodon->getRotation());
      MoverNodo(DummyNodo,-32448763.f,0.f,0.f);
      vfin = DummyNodo->getPosition();

      if(ColisionConRayo( posmiacoli, vfin, trian)){      
          intersec_coli_b->setPosition(RetornarInterseccionRayo( posmiacoli, vfin, trian));
          coli = nodon->getTransformedBoundingBox().intersectsWithBox(intersec_coli_b->getTransformedBoundingBox());
    
          if(coli && intersec_coli_b->getPosition().X != 6456.365f && intersec_coli_b->getPosition().Y != 6456.365f && intersec_coli_b->getPosition().Z != 6456.365f){
                  return true;
          }
      }
/*
     // punto C
      vfin = posmiacoli;
      vfin.Y += 32448763;
      
      intersec_coli_c->setPosition(RetornarInterseccionRayo( posmiacoli, vfin, trian));
      coli = nodon->getTransformedBoundingBox().intersectsWithBox(intersec_coli_c->getTransformedBoundingBox());

      if(coli && intersec_coli_c->getPosition().X != 6456.365f && intersec_coli_c->getPosition().Y != 6456.365f && intersec_coli_c->getPosition().Z != 6456.365f){
              return true;
      } 
*/
     // punto D
      DummyNodo->setPosition(nodon->getPosition());
      DummyNodo->setRotation(nodon->getRotation());
      MoverNodo(DummyNodo,0.f,-32448763.f,0.f);
      vfin = DummyNodo->getPosition();

      if(ColisionConRayo( posmiacoli, vfin, trian)){      
          intersec_coli_d->setPosition(RetornarInterseccionRayo( posmiacoli, vfin, trian));
          coli = nodon->getTransformedBoundingBox().intersectsWithBox(intersec_coli_d->getTransformedBoundingBox());
    
          if(coli && intersec_coli_d->getPosition().X != 6456.365f && intersec_coli_d->getPosition().Y != 6456.365f && intersec_coli_d->getPosition().Z != 6456.365f){
                  return true;
          }           
      }



     // punto F
      DummyNodo->setPosition(nodon->getPosition());
      DummyNodo->setRotation(nodon->getRotation());
      MoverNodo(DummyNodo,0.f,0.f,-32448763.f);
      vfin = DummyNodo->getPosition();
      
      if(ColisionConRayo( posmiacoli, vfin, trian)){
          intersec_coli_f->setPosition(RetornarInterseccionRayo( posmiacoli, vfin, trian));
          coli = nodon->getTransformedBoundingBox().intersectsWithBox(intersec_coli_f->getTransformedBoundingBox());
    
          if(coli && intersec_coli_f->getPosition().X != 6456.365f && intersec_coli_f->getPosition().Y != 6456.365f && intersec_coli_f->getPosition().Z != 6456.365f){
                  return true;
          }
      }
      
	  return false;     
}

/*!
\return el punto en donde se intersección.

\param ini el vector del punto inicial del rayo.
\param fin el vector del punto final del rayo.
\param scen el escenario
*/
vector3df GD_Colisiones3d::RetornarInterseccionRayo( vector3df ini, vector3df fin, GD_Escenario scen )
{

        ITriangleSelector* trian = scen.RetornarDatos();

	core::line3d<f32> line;
	line.start = ini;
	line.end = fin; //line.start +  (poso2 - line.start).normalize() * 1000.0f;

	core::vector3df intersection;
	core::triangle3df tri;

	if (GD_Sistema::device->getSceneManager()->getSceneCollisionManager()->getCollisionPoint(
			line, trian, intersection, tri))
	{
		return intersection;
        }
        else
		return vector3df(6456.365f,6456.365f,6456.365f);
      
}	

vector3df GD_Colisiones3d::PosicionColisionConEscenario( ITriangleSelector* trian)
{

      coli=0;
      posmiacoli = nodon->getPosition();

     // punto E
      DummyNodo->setPosition(nodon->getPosition());
      DummyNodo->setRotation(nodon->getRotation());
      MoverNodo(DummyNodo,0.f,0.f,32448763.f);
      vfin = DummyNodo->getPosition();
      
      if(ColisionConRayo( posmiacoli, vfin, trian)){
          intersec_coli_e->setPosition(RetornarInterseccionRayo( posmiacoli, vfin, trian));
          coli = nodon->getTransformedBoundingBox().intersectsWithBox(intersec_coli_e->getTransformedBoundingBox());
    
          if(coli && intersec_coli_e->getPosition().X != 6456.365f && intersec_coli_e->getPosition().Y != 6456.365f && intersec_coli_e->getPosition().Z != 6456.365f){
                  return intersec_coli_e->getPosition();
          } 
      }
      
      // punto A
      DummyNodo->setPosition(nodon->getPosition());
      DummyNodo->setRotation(nodon->getRotation());
      MoverNodo(DummyNodo,32448763.f,0.f,0.f);
      vfin = DummyNodo->getPosition();

      if(ColisionConRayo( posmiacoli, vfin, trian)){      
          intersec_coli_a->setPosition(RetornarInterseccionRayo( posmiacoli, vfin, trian));
          coli = nodon->getTransformedBoundingBox().intersectsWithBox(intersec_coli_a->getTransformedBoundingBox());
    
          if(coli && intersec_coli_a->getPosition().X != 6456.365f && intersec_coli_a->getPosition().Y != 6456.365f && intersec_coli_a->getPosition().Z != 6456.365f){
                  return intersec_coli_a->getPosition();
          }
      }

      // punto B
      DummyNodo->setPosition(nodon->getPosition());
      DummyNodo->setRotation(nodon->getRotation());
      MoverNodo(DummyNodo,-32448763.f,0.f,0.f);
      vfin = DummyNodo->getPosition();
      
      if(ColisionConRayo( posmiacoli, vfin, trian)){
          intersec_coli_b->setPosition(RetornarInterseccionRayo( posmiacoli, vfin, trian));
          coli = nodon->getTransformedBoundingBox().intersectsWithBox(intersec_coli_b->getTransformedBoundingBox());
    
          if(coli && intersec_coli_b->getPosition().X != 6456.365f && intersec_coli_b->getPosition().Y != 6456.365f && intersec_coli_b->getPosition().Z != 6456.365f){
                  return intersec_coli_a->getPosition();
          }
      }
/*
     // punto C
      vfin = posmiacoli;
      vfin.Y += 32448763;
      
      intersec_coli_c->setPosition(RetornarInterseccionRayo( posmiacoli, vfin, trian));
      coli = nodon->getTransformedBoundingBox().intersectsWithBox(intersec_coli_c->getTransformedBoundingBox());

      if(coli && intersec_coli_c->getPosition().X != 6456.365f && intersec_coli_c->getPosition().Y != 6456.365f && intersec_coli_c->getPosition().Z != 6456.365f){
              return intersec_coli_c->getPosition();
      } 
*/      
     // punto D
      DummyNodo->setPosition(nodon->getPosition());
      DummyNodo->setRotation(nodon->getRotation());
      MoverNodo(DummyNodo,0.f,-32448763.f,0.f);
      vfin = DummyNodo->getPosition();

      if(ColisionConRayo( posmiacoli, vfin, trian)){      
          intersec_coli_d->setPosition(RetornarInterseccionRayo( posmiacoli, vfin, trian));
          coli = nodon->getTransformedBoundingBox().intersectsWithBox(intersec_coli_d->getTransformedBoundingBox());
    
          if(coli && intersec_coli_d->getPosition().X != 6456.365f && intersec_coli_d->getPosition().Y != 6456.365f && intersec_coli_d->getPosition().Z != 6456.365f){
                  return intersec_coli_d->getPosition();
          }           
      }



     // punto F
      DummyNodo->setPosition(nodon->getPosition());
      DummyNodo->setRotation(nodon->getRotation());
      MoverNodo(DummyNodo,0.f,0.f,-32448763.f);
      vfin = DummyNodo->getPosition();
      
      if(ColisionConRayo( posmiacoli, vfin, trian)){
          intersec_coli_f->setPosition(RetornarInterseccionRayo( posmiacoli, vfin, trian));
          coli = nodon->getTransformedBoundingBox().intersectsWithBox(intersec_coli_f->getTransformedBoundingBox());
    
          if(coli && intersec_coli_f->getPosition().X != 6456.365f && intersec_coli_f->getPosition().Y != 6456.365f && intersec_coli_f->getPosition().Z != 6456.365f){
                  return intersec_coli_f->getPosition();
          } 
      }

	  return vector3df(6456.365f,6456.365f,6456.365f);

}

/*!
\param ini el vector del punto inicial del rayo.
\param fin el vector del punto final del rayo.
\param trian el escenario.

\return el punto en donde se intersección.
*/
vector3df GD_Colisiones3d::RetornarInterseccionRayo( vector3df ini, vector3df fin, ITriangleSelector* trian )
{

    	core::line3d<f32> line;
    	
		line.start = ini;
		line.end = fin; //line.start +  (poso2 - line.start).normalize() * 1000.0f;

		core::vector3df intersection;
		core::triangle3df tri;

		if (GD_Sistema::device->getSceneManager()->getSceneCollisionManager()->getCollisionPoint(
			line, trian, intersection, tri))
		{
			return intersection;
        }
        else
            return vector3df(6456.365f,6456.365f,6456.365f);
      
}	

/*!
\param ini el vector del punto inicial del rayo.
\param fin el vector del punto final del rayo.
\param trian el escenario.

\return true si esta colisionando el objeto con el rayo, o false en caso contrario.
*/
bool GD_Colisiones3d::ColisionConRayo( vector3df ini, vector3df fin, ITriangleSelector* trian )
{

    	core::line3d<f32> line;
    	
		line.start = ini;
		line.end = fin; //line.start +  (poso2 - line.start).normalize() * 1000.0f;

		core::vector3df intersection;
		core::triangle3df tri;

		if (GD_Sistema::device->getSceneManager()->getSceneCollisionManager()->getCollisionPoint(
			line, trian, intersection, tri))
		{
			return true;
        }
        else
            return false;
      
}

/*!
\param scen es el GD_Escenario
\return true si esta colisionando el objeto con el escenario, o false en caso contrario.

Ejemplo:
\code
Colision = Protagonista.ColisionConEscenario( Escenario ):
\endcode
*/
bool GD_Colisiones3d::ColisionConEscenario( GD_Escenario scen )
{
      return ColisionConEscenario( scen.RetornarDatos() );
}

/*!
\param scen es el GD_Escenario
\return la posición en donde esta colisionando el objeto con el escenario.

Ejemplo:
\code
PosColision = Protagonista. PosicionColisionConEscenario ( Escenario ):
\endcode
*/
vector3df GD_Colisiones3d::PosicionColisionConEscenario( GD_Escenario scen )
{
     return PosicionColisionConEscenario( scen.RetornarDatos() );
}

/*!
\param nodocoli es el GD_Nodo con el que estamos comparando la colisión.
\return true si esta colisionando con otro objeto.

Esta colisión se calcula mediante boundingboxes.

Ejemplo:
\code
Colision = Protagonista.Colisiona( Enemigo );
\endcode
*/
bool GD_Colisiones3d::Colisiona(GD_Nodo nodocoli)
{
     bool coli;
     aabbox3d<f32> Cajon;
     Cajon = nodocoli.nodon->getTransformedBoundingBox();
     coli = nodon->getTransformedBoundingBox().intersectsWithBox(Cajon);
     return coli;
}

void MoverNodo(ISceneNode* nododumy, float x, float y, float z)
{
     vector3df destino;
     destino.X = x;
     destino.Y = y;
     destino.Z = z;
	matrix4 matrix = nododumy->getRelativeTransformation();
	matrix.transformVect(destino);
     nododumy->setPosition(destino);
}

