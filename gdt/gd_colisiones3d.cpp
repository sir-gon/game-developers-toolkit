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

#include "gd_colisiones3d.h" // class's header file

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

void GD_Colisiones3d::CrearColision(ITriangleSelector* Mundo,core::vector3df Radio,
                                       core::vector3df Gravedad,core::vector3df Traslacion)
{


   colision = mesh_smgr->createCollisionResponseAnimator(Mundo, nodon , Radio,Gravedad,Traslacion);

   anim=colision;

	nodon->addAnimator(anim);
	anim->drop();

}

void GD_Colisiones3d::CrearColision(ITriangleSelector* Mundo, float RadioX,
                                                              float RadioY,
                                                              float RadioZ,
                                                              float GravedadX,
                                                              float GravedadY,
                                                              float GravedadZ, 
                                                              float TraslacionX, 
                                                              float TraslacionY, 
                                                              float TraslacionZ)
{


   colision = mesh_smgr->createCollisionResponseAnimator(Mundo, nodon , core::vector3df(RadioX,RadioY,RadioZ),
                                                                      core::vector3df(GravedadX,GravedadY,GravedadZ),
                                                                      core::vector3df(TraslacionX,TraslacionY,TraslacionZ));

   anim=colision;

	nodon->addAnimator(anim);
	anim->drop();

}
      

void GD_Colisiones3d::ActualizarDatosColision()
{
   //Si se han cambiado los valores de colision, tales como: Radio, Gravedad o Traslacion,
   //con esta funcion se recrea el valor de la animacion.
   anim=colision;
	nodon->addAnimator(anim);
	anim->drop();

}


//Obtencion de valores *******************************************************
core::vector3df GD_Colisiones3d::RetornarRadioElipsoide()
{
   return colision->getEllipsoidRadius();
}

core::vector3df GD_Colisiones3d::RetornarTraslacionElipsoide()
{
   return colision->getEllipsoidTranslation();
}

core::vector3df GD_Colisiones3d::RetornarGravedad()
{
   return colision->getGravity();
}

ITriangleSelector* GD_Colisiones3d::RetornarDatosMundo()
{
   return colision->getWorld();
}

bool GD_Colisiones3d::Callendo()
{
   return colision->isFalling();
}


// Asignacion de valores *****************************************************
void GD_Colisiones3d::AsignarRadioElipsoide(core::vector3df vector_3d)
{
  colision->setEllipsoidRadius(vector_3d);
}

void GD_Colisiones3d::AsignarRadioElipsoide(float x, float y, float z)
{
  colision->setEllipsoidRadius(core::vector3df(x,y,z));
}

void GD_Colisiones3d::AsignarTraslacionElipsoide(core::vector3df vector_3d)
{
   colision->setEllipsoidTranslation(vector_3d);
}

void GD_Colisiones3d::AsignarTraslacionElipsoide(float x, float y, float z)
{
   colision->setEllipsoidTranslation(core::vector3df(x,y,z));
}

void GD_Colisiones3d::AsignarGravedad(core::vector3df vector_3d)
{
   colision->setGravity(vector_3d);
}

void GD_Colisiones3d::AsignarGravedad(float x, float y, float z)
{
   colision->setGravity(core::vector3df(x,y,z));
}

void GD_Colisiones3d::AsignarDatosColision(GD_Escenario scen)
{
     ITriangleSelector *nuevoMundo = scen.RetornarDatos();
   colision->setWorld(nuevoMundo);
}

//****************************************************************************
ITriangleSelector* GD_Colisiones3d::RetornarDatosSelector()
{
     return selector;
}

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

void GD_Colisiones3d::CrearColision(GD_Escenario scen,core::vector3df Radio,
                                       core::vector3df Gravedad,core::vector3df Traslacion)
{

ITriangleSelector* Mundo = scen.RetornarDatos();

   colision = mesh_smgr->createCollisionResponseAnimator(Mundo, nodon , Radio,Gravedad,Traslacion);

   anim=colision;

	nodon->addAnimator(anim);
	anim->drop();

}

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
      

// Colision por cajas limite.
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
      MoverNodo(DummyNodo,0,0,32448763);
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
      MoverNodo(DummyNodo,32448763,0,0);
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
      MoverNodo(DummyNodo,-32448763,0,0);
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
      MoverNodo(DummyNodo,0,-32448763,0);
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
      MoverNodo(DummyNodo,0,0,-32448763);
      vfin = DummyNodo->getPosition();
      
      if(ColisionConRayo( posmiacoli, vfin, trian)){
          intersec_coli_f->setPosition(RetornarInterseccionRayo( posmiacoli, vfin, trian));
          coli = nodon->getTransformedBoundingBox().intersectsWithBox(intersec_coli_f->getTransformedBoundingBox());
    
          if(coli && intersec_coli_f->getPosition().X != 6456.365f && intersec_coli_f->getPosition().Y != 6456.365f && intersec_coli_f->getPosition().Z != 6456.365f){
                  return true;
          } 
      }
      else
              return false;
     
     
}

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
      MoverNodo(DummyNodo,0,0,32448763);
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
      MoverNodo(DummyNodo,32448763,0,0);
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
      MoverNodo(DummyNodo,-32448763,0,0);
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
      MoverNodo(DummyNodo,0,-32448763,0);
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
      MoverNodo(DummyNodo,0,0,-32448763);
      vfin = DummyNodo->getPosition();
      
      if(ColisionConRayo( posmiacoli, vfin, trian)){
          intersec_coli_f->setPosition(RetornarInterseccionRayo( posmiacoli, vfin, trian));
          coli = nodon->getTransformedBoundingBox().intersectsWithBox(intersec_coli_f->getTransformedBoundingBox());
    
          if(coli && intersec_coli_f->getPosition().X != 6456.365f && intersec_coli_f->getPosition().Y != 6456.365f && intersec_coli_f->getPosition().Z != 6456.365f){
                  return intersec_coli_f->getPosition();
          } 
      }
      else
              return vector3df(6456.365f,6456.365f,6456.365f);


}



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

bool GD_Colisiones3d::ColisionConEscenario( GD_Escenario scen )
{
      return ColisionConEscenario( scen.RetornarDatos() );
}

vector3df GD_Colisiones3d::PosicionColisionConEscenario( GD_Escenario scen )
{
     return PosicionColisionConEscenario( scen.RetornarDatos() );
}

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

