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

#include "gd_malla.h" // class's header file

// class constructor
GD_Malla::GD_Malla()
{


}


// class destructor
GD_Malla::~GD_Malla()
{
	// insert your code here
}

//!Carga una malla animada.
	/**
filename = archivo a cargar
SceneManager = Manejador de escenas siempre se tiene
               llamando Sistema.smgr

Los formatos soportados son:

    * 3D Studio meshes (.3ds)
    * Alias Wavefront Maya (.obj)
    * Cartography shop 4 (.csm)
    * COLLADA (.xml, .dae)
    * DeleD (.dmf)
    * FSRad oct (.oct)
    * Microsoft DirectX (.x)
    * Milkshape (.ms3d)
    * My3DTools 3 (.my3D)
    * Pulsar LMTools (.lmts)
    * Quake 3 levels (.bsp)
    * Quake 2 models (.md2) 
    * Ogre .mesh
    * Blitz3D. B3D


*/
void GD_Malla::Cargar(char *filename)
{


    RegistrarDevice(GD_Sistema::device); //Asignando el dispositivo principal al dispositivo de esena de la clase nodo.

    mesh_smgr=GD_Sistema::device->getSceneManager(); //Creando un Manejador de esena (Scene Manager)

    mesh = mesh_smgr->getMesh(filename); //Cargando el objetos segun el archivo
    static_mesh=mesh->getMesh(0);// Malla estatica


    //Si la malla es estatica 
    //if(Estatica==true)
    //{
      //nodon = mesh_smgr->addMeshSceneNode(static_mesh); //Creando el nodo del objeto estatico cargado
    //}
    //else
    //{
          
    
    
    nodoAM=mesh_smgr->addAnimatedMeshSceneNode(mesh);    
    nodon=nodoAM;
    
    
    //}
    
    if(!nodon) printf("Problema al cargar la malla. \n");


     coloralphaA = 100;
     coloralphaD = 100;
     coloralphaEm = 100;
     coloralphaE = 100; 
     
    for(s32 i=0; i< nodon->getMaterialCount(); ++i)
    {
            nodon->getMaterial(i).EmissiveColor.set(100,80,80,80);
            nodon->getMaterial(i).DiffuseColor.set(100,100,100,100);
    } 

    intersec_coli_a = mesh_smgr->addEmptySceneNode();
    intersec_coli_b = mesh_smgr->addEmptySceneNode();
    intersec_coli_c = mesh_smgr->addEmptySceneNode();
    intersec_coli_d = mesh_smgr->addEmptySceneNode();
    intersec_coli_e = mesh_smgr->addEmptySceneNode();
    intersec_coli_f = mesh_smgr->addEmptySceneNode();
        DummyNodo = mesh_smgr->addEmptySceneNode();   
        
    
          
 
}


void GD_Malla::CargarTangentes(char *filename)
{
   
    RegistrarDevice(GD_Sistema::device); //Asignando el dispositivo principal al dispositivo de esena de la clase nodo.

    mesh_smgr=GD_Sistema::device->getSceneManager(); //Creando un Manejador de esena (Scene Manager)

    mesh = mesh_smgr->getMesh(filename); //Cargando el objetos segun el archivo
    static_mesh=mesh->getMesh(0);// Malla estatica


   tangentMesh = midevice->getSceneManager()->getMeshManipulator()->createMeshWithTangents(
    	static_mesh);
   nodo_tangentes = mesh_smgr->addMeshSceneNode(tangentMesh); 
   nodon=nodo_tangentes;
   

    intersec_coli_a = mesh_smgr->addEmptySceneNode();
    intersec_coli_b = mesh_smgr->addEmptySceneNode();
    intersec_coli_c = mesh_smgr->addEmptySceneNode();
    intersec_coli_d = mesh_smgr->addEmptySceneNode();
    intersec_coli_e = mesh_smgr->addEmptySceneNode();
    intersec_coli_f = mesh_smgr->addEmptySceneNode();
        DummyNodo = mesh_smgr->addEmptySceneNode();   
}

void GD_Malla::CrearCubo(  )
{
    RegistrarDevice(GD_Sistema::GD_Sistema::device); //Asignando el dispositivo principal al dispositivo de esena de la clase nodo.
    mesh_smgr=GD_Sistema::device->getSceneManager(); //Creando un Manejador de esena (Scene Manager)

    static_mesh=DibujarCubo();
    
    
    tangentMesh = midevice->getSceneManager()->getMeshManipulator()->createMeshWithTangents(
    	static_mesh);
   nodo_tangentes = mesh_smgr->addMeshSceneNode(tangentMesh); 
   nodon=nodo_tangentes;
    
    //nodon=mesh_smgr->addMeshSceneNode(static_mesh);    
    
        tangentMesh = midevice->getSceneManager()->getMeshManipulator()->createMeshWithTangents(
    	static_mesh);
   nodo_tangentes = mesh_smgr->addMeshSceneNode(tangentMesh); 
   nodon=nodo_tangentes;
    
    if(!nodon) printf("Problema al Crear el cubo. \n");

     ColorDifuso(100,100,100);
     
     coloralphaA = 100;
     coloralphaD = 100;
     coloralphaEm = 100;
     coloralphaE = 100; 


    intersec_coli_a = mesh_smgr->addEmptySceneNode();
    intersec_coli_b = mesh_smgr->addEmptySceneNode();
    intersec_coli_c = mesh_smgr->addEmptySceneNode();
    intersec_coli_d = mesh_smgr->addEmptySceneNode();
    intersec_coli_e = mesh_smgr->addEmptySceneNode();
    intersec_coli_f = mesh_smgr->addEmptySceneNode();    
    
    DummyNodo = mesh_smgr->addEmptySceneNode();

}

void GD_Malla::CrearCubo(float tamx, float tamy, float tamz )
{
    RegistrarDevice(GD_Sistema::device); //Asignando el dispositivo principal al dispositivo de esena de la clase nodo.
    mesh_smgr=GD_Sistema::device->getSceneManager(); //Creando un Manejador de esena (Scene Manager)

    static_mesh=DibujarCubo();
    
    
        tangentMesh = midevice->getSceneManager()->getMeshManipulator()->createMeshWithTangents(
    	static_mesh);
   nodo_tangentes = mesh_smgr->addMeshSceneNode(tangentMesh); 
   nodon=nodo_tangentes;
   
//    nodon=mesh_smgr->addMeshSceneNode(static_mesh);    
    nodon->setScale(vector3df(tamx,tamy,tamz));
    
    if(!nodon) printf("Problema al Crear el cubo. \n");

     ColorDifuso(100,100,100);
     
     coloralphaA = 100;
     coloralphaD = 100;
     coloralphaEm = 100;
     coloralphaE = 100; 
     

    intersec_coli_a = mesh_smgr->addEmptySceneNode();
    intersec_coli_b = mesh_smgr->addEmptySceneNode();
    intersec_coli_c = mesh_smgr->addEmptySceneNode();
    intersec_coli_d = mesh_smgr->addEmptySceneNode();
    intersec_coli_e = mesh_smgr->addEmptySceneNode();
    intersec_coli_f = mesh_smgr->addEmptySceneNode();
    
        DummyNodo = mesh_smgr->addEmptySceneNode();     

}

void GD_Malla::CrearPlano( int tx, int ty )
{
    RegistrarDevice(GD_Sistema::device); //Asignando el dispositivo principal al dispositivo de esena de la clase nodo.
    mesh_smgr=GD_Sistema::device->getSceneManager(); //Creando un Manejador de esena (Scene Manager)

    static_mesh=DibujarPlano(tx,ty);

    tangentMesh = midevice->getSceneManager()->getMeshManipulator()->createMeshWithTangents(
    	static_mesh);
   nodo_tangentes = mesh_smgr->addMeshSceneNode(tangentMesh); 
   nodon=nodo_tangentes;    
    
//    nodon=mesh_smgr->addMeshSceneNode(static_mesh);    
    
    if(!nodon) printf("Problema al Crear el Plano. \n");

     ColorDifuso(100,100,100);
     
     coloralphaA = 100;
     coloralphaD = 100;
     coloralphaEm = 100;
     coloralphaE = 100; 


    intersec_coli_a = mesh_smgr->addEmptySceneNode();
    intersec_coli_b = mesh_smgr->addEmptySceneNode();
    intersec_coli_c = mesh_smgr->addEmptySceneNode();
    intersec_coli_d = mesh_smgr->addEmptySceneNode();
    intersec_coli_e = mesh_smgr->addEmptySceneNode();
    intersec_coli_f = mesh_smgr->addEmptySceneNode();
    
        DummyNodo = mesh_smgr->addEmptySceneNode();

}

void GD_Malla::CrearCilindro( int tx, int ty, f32 radio  )
{
    RegistrarDevice(GD_Sistema::device); //Asignando el dispositivo principal al dispositivo de esena de la clase nodo.
    mesh_smgr=GD_Sistema::device->getSceneManager(); //Creando un Manejador de esena (Scene Manager)

    static_mesh=DibujarCilindro( tx, ty, radio);
  
      tangentMesh = midevice->getSceneManager()->getMeshManipulator()->createMeshWithTangents(
    	static_mesh);
   nodo_tangentes = mesh_smgr->addMeshSceneNode(tangentMesh); 
   nodon=nodo_tangentes;
    
//    nodon=mesh_smgr->addMeshSceneNode(static_mesh);    
    
    if(!nodon) printf("Problema al Crear el cilindro. \n");

     ColorDifuso(100,100,100);
     
     coloralphaA = 100;
     coloralphaD = 100;
     coloralphaEm = 100;
     coloralphaE = 100; 
     
     
    intersec_coli_a = mesh_smgr->addEmptySceneNode();
    intersec_coli_b = mesh_smgr->addEmptySceneNode();
    intersec_coli_c = mesh_smgr->addEmptySceneNode();
    intersec_coli_d = mesh_smgr->addEmptySceneNode();
    intersec_coli_e = mesh_smgr->addEmptySceneNode();
    intersec_coli_f = mesh_smgr->addEmptySceneNode();
    
        DummyNodo = mesh_smgr->addEmptySceneNode();
     

}

void GD_Malla::CrearCono( int tx, int ty, f32 radio )       
{
    RegistrarDevice(GD_Sistema::device); //Asignando el dispositivo principal al dispositivo de esena de la clase nodo.
    mesh_smgr=GD_Sistema::device->getSceneManager(); //Creando un Manejador de esena (Scene Manager)

    static_mesh=DibujarCono( tx, ty, radio);
    
    tangentMesh = midevice->getSceneManager()->getMeshManipulator()->createMeshWithTangents(
    	static_mesh);
   nodo_tangentes = mesh_smgr->addMeshSceneNode(tangentMesh); 
   nodon=nodo_tangentes;    
    
//    nodon=mesh_smgr->addMeshSceneNode(static_mesh);    
    
    if(!nodon) printf("Problema al Crear el cilindro. \n");

     ColorDifuso(100,100,100);
     
     coloralphaA = 100;
     coloralphaD = 100;
     coloralphaEm = 100;
     coloralphaE = 100; 
     
     
    intersec_coli_a = mesh_smgr->addEmptySceneNode();
    intersec_coli_b = mesh_smgr->addEmptySceneNode();
    intersec_coli_c = mesh_smgr->addEmptySceneNode();
    intersec_coli_d = mesh_smgr->addEmptySceneNode();
    intersec_coli_e = mesh_smgr->addEmptySceneNode();
    intersec_coli_f = mesh_smgr->addEmptySceneNode();
    
        DummyNodo = mesh_smgr->addEmptySceneNode();

}

void GD_Malla::CrearEsfera( float radio, int polynum )
{
    RegistrarDevice(GD_Sistema::device); //Asignando el dispositivo principal al dispositivo de esena de la clase nodo.
    mesh_smgr=GD_Sistema::device->getSceneManager(); //Creando un Manejador de esena (Scene Manager)
    
    nodon=mesh_smgr->addSphereSceneNode ( radio, polynum );

    if(!nodon) printf("Problema al crear esfera \n");


     coloralphaA = 100;
     coloralphaD = 100;
     coloralphaEm = 100;
     coloralphaE = 100; 
     
    intersec_coli_a = mesh_smgr->addEmptySceneNode();
    intersec_coli_b = mesh_smgr->addEmptySceneNode();
    intersec_coli_c = mesh_smgr->addEmptySceneNode();
    intersec_coli_d = mesh_smgr->addEmptySceneNode();
    intersec_coli_e = mesh_smgr->addEmptySceneNode();
    intersec_coli_f = mesh_smgr->addEmptySceneNode();
    
        DummyNodo = mesh_smgr->addEmptySceneNode();

}

void GD_Malla::ProyectarSombra()
{
     nodoAM->addShadowVolumeSceneNode();
}

//! Devuelve el cuadro de la animacion.
/**
Devuelve el cuadro instantaneo en el que en ese momento esta la malla
*/
int GD_Malla::RetornarCuadro()
{
   return nodoAM->getFrameNr();
}

//! Establece la velocidad de la animacion de la malla.
void GD_Malla::VelocidadAnimacion(int CuadrosPorSegundo)
{
      RegistrarVelAni(CuadrosPorSegundo);
      nodoAM->setAnimationSpeed(velani);
}

//! Establece el cuadro actual de la animacion
void GD_Malla::CuadroActual(int cuadro)
{
    nodoAM-> setCurrentFrame(cuadro);
    nodoAM->setAnimationSpeed(velani);
}

//! Establece el ciclo de la animacion.
void GD_Malla::CicloCuadros(int ini, int fin)
{
     if(controlani){
          if(ini=old_ini && fin!=old_fin){
              nodoAM->setFrameLoop(ini, fin);
              old_ini = ini;
              old_fin = fin;     
//              printf("Cambiando\n");         
          }
     }
     else
           nodoAM->setFrameLoop(ini, fin);

     nodoAM->setAnimationSpeed(velani);
}

void GD_Malla::CicloMD2(irr::scene::EMD2_ANIMATION_TYPE tipoAnimacionMD2 )
{
     
//     printf("tipoAnimacionMD2 = %d, old = %d\n",tipoAnimacionMD2,old_aniTipoActual);   
     
     if(controlani){
          if(tipoAnimacionMD2 != old_aniTipoActual){     
               nodoAM->setMD2Animation( tipoAnimacionMD2 );
               old_aniTipoActual = tipoAnimacionMD2;
                   
          }
     }
     else
          nodoAM->setMD2Animation( tipoAnimacionMD2 );

     nodoAM->setAnimationSpeed(velani);          
          
}

void GD_Malla::Repeticion(bool enCiclo)
{
     nodoAM->setLoopMode( enCiclo );
}

void GD_Malla::ControlAnimacion(bool control)
{
     controlani=control;
}

void GD_Malla::Reemplazar(ISceneNode* nod_R)
{
     nodon=nod_R;
}

ISceneNode* GD_Malla::RetornarNodoHuesoX(c8* Nombre )
{
     
   ISceneNode* nodo_hueso = nodoAM->getXJointNode(Nombre);
   return nodo_hueso;
}

ISceneNode* GD_Malla::RetornarNodoHuesoMS3D(c8* Nombre )
{
     
   ISceneNode* nodo_hueso = nodoAM->getMS3DJointNode(Nombre);
   return nodo_hueso;
}

//From Irrforge.org
IMesh* GD_Malla::DibujarCubo()
{
      SMesh* msh = new SMesh();      
      SMeshBuffer* mb = new SMeshBuffer();
      msh->addMeshBuffer(mb);  
      S3DVertex vtx[12];
      vtx[0]  = S3DVertex(-1,-1,-1, -1,-1,-1, SColor(255,255,255,255), 0, 1); 
      vtx[1]  = S3DVertex( 1,-1,-1,  1,-1,-1, SColor(255,255,255,255), 1, 1); 
      vtx[2]  = S3DVertex( 1, 1,-1,  1, 1,-1, SColor(255,255,255,255), 1, 0); 
      vtx[3]  = S3DVertex(-1, 1,-1, -1, 1,-1, SColor(255,255,255,255), 0, 0); 
      vtx[4]  = S3DVertex( 1,-1, 1,  1,-1, 1, SColor(255,255,255,255), 0, 1); 
      vtx[5]  = S3DVertex( 1, 1, 1,  1, 1, 1, SColor(255,255,255,255), 0, 0); 
      vtx[6]  = S3DVertex(-1, 1, 1, -1, 1, 1, SColor(255,255,255,255), 1, 0); 
      vtx[7]  = S3DVertex(-1,-1, 1, -1,-1, 1, SColor(255,255,255,255), 1, 1); 
      vtx[8]  = S3DVertex(-1, 1, 1, -1, 1, 1, SColor(255,255,255,255), 0, 1); 
      vtx[9]  = S3DVertex(-1, 1,-1, -1, 1,-1, SColor(255,255,255,255), 1, 1); 
      vtx[10] = S3DVertex( 1,-1, 1,  1,-1, 1, SColor(255,255,255,255), 1, 0); 
      vtx[11] = S3DVertex( 1,-1,-1,  1,-1,-1, SColor(255,255,255,255), 0, 0);           


      for(int i=0;i<12;i++)mb->Vertices.push_back(vtx[i]);
      u16 indices[36] = {   0,2,1,   0,3,2,   1,5,4,   1,2,5,   
                            4,6,7,   4,5,6,   7,3,0,   7,6,3,   
                            9,5,2,   9,8,5,   0,11,10, 0,10,7
                        };
      for(int i=0;i<36;i++)mb->Indices.push_back(indices[i]); 

      return msh;
}


IMesh* GD_Malla::DibujarPlano(int gridX, int gridY)
{
  SMesh* msh = new SMesh();      
  SMeshBuffer* mb = new SMeshBuffer();
  msh->addMeshBuffer(mb);
  int vertCnt = 0;
  for (int x = 0; x < gridX; x++)
      for (int y = 0; y < gridY; y++)
       {
           f32 xx   = (0.5-(float)x/(gridX-1))*2;
           f32 yy   = (0.5-(float)y/(gridY-1))*2;
           f32 xcord = 1-(float)x/(gridX-1);
           f32 ycord = (float)y/(gridY-1)-1;
           mb->Vertices.push_back(S3DVertex(xx,yy,0, 0,0,0,SColor(255,255,255,255),xcord,ycord));

           if (x < gridX - 1 && y < gridY - 1)
            {
               mb->Indices.push_back(vertCnt + 0);
               mb->Indices.push_back(vertCnt + 1);
               mb->Indices.push_back(vertCnt + 1 + gridY);
               mb->Indices.push_back(vertCnt + 1 + gridY);
               mb->Indices.push_back(vertCnt + gridY);
               mb->Indices.push_back(vertCnt + 0);
            }
          vertCnt++; 
       }     
  return msh;
} 

IMesh* GD_Malla::DibujarCilindro(int gridX, int gridY,f32 ridus)
{
          SMesh* msh = new SMesh();      
          SMeshBuffer* mb = new SMeshBuffer();
          msh->addMeshBuffer(mb);
          f32 Tstp = 2*3.14/(float)(gridX-1);
          int vertCnt = 0;
          for (int x = 0; x < gridX; x++)
              for (int y = 0; y < gridY; y++)
               {
                   f32 yy   = (0.5-(float)y/(gridY-1))*2;
                   f32 xx   = sin((f32)x*Tstp)*ridus;  
                   f32 zz   = cos((f32)x*Tstp)*ridus;
                   f32 xcord = 1-(float)x/(gridX-1);
                   f32 ycord = (float)y/(gridY-1)-1;
                   if (x < gridX-1)
                    {
                       mb->Vertices.push_back(S3DVertex(xx,yy,zz, 0,0,0,SColor(255,255,255,255),xcord,ycord));

                    }    
                   else
                    {  
                       f32 yy   = (0.5-(float)y/(gridY-1))*2;
                       f32 xx   = sin(0.0)*ridus;  
                       f32 zz   = cos(0.0)*ridus;
                       mb->Vertices.push_back(S3DVertex(xx,yy,zz, 0,0,0,SColor(255,255,255,255),xcord,ycord));

                    }
                   if (x < gridX - 1 && y < gridY - 1)
                    {
                       mb->Indices.push_back(vertCnt + 0);
                       mb->Indices.push_back(vertCnt + 1);
                       mb->Indices.push_back(vertCnt + 1 + gridY);
                       mb->Indices.push_back(vertCnt + 1 + gridY);
                       mb->Indices.push_back(vertCnt + gridY);
                       mb->Indices.push_back(vertCnt + 0);
                    }
                  vertCnt++; 
               }       
          return msh;
}   


IMesh* GD_Malla::DibujarCono(int gridX, int gridY,f32 ridus)
{
  SMesh* msh = new SMesh();      
  SMeshBuffer* mb = new SMeshBuffer();
  msh->addMeshBuffer(mb); 
  f32 vstp = ridus/(float)(gridY-1);
  f32 Tstp = 2*3.14/(float)(gridX-1);
  int vertCnt = 0;
  for (int x = 0; x < gridX; x++)
      for (int y = 0; y < gridY; y++)
       {
           f32 yy   = (0.5-(float)y/(gridY-1))*2;
           f32 xx   = sin((f32)x*Tstp)*((f32)y*vstp);  
           f32 zz   = cos((f32)x*Tstp)*((f32)y*vstp);
           f32 xcord = 1-(float)x/(gridX-1);
           f32 ycord = (float)y/(gridY-1)-1;
           if (x < gridX-1)
            {
               mb->Vertices.push_back(S3DVertex(xx,yy,zz, 0,0,0,SColor(255,255,255,255),xcord,ycord));

            }    
           else
            {  
               f32 yy   = (0.5-(float)y/(gridY-1))*2;
               f32 xx   = sin((f32)x*Tstp)*((f32)y*vstp);  
               f32 zz   = cos((f32)x*Tstp)*((f32)y*vstp);
               mb->Vertices.push_back(S3DVertex(xx,yy,zz, 0,0,0,SColor(255,255,255,255),xcord,ycord));

            }
           if (x < gridX - 1 && y < gridY - 1)
            {
               mb->Indices.push_back(vertCnt + 0);
               mb->Indices.push_back(vertCnt + 1);
               mb->Indices.push_back(vertCnt + 1 + gridY);
               mb->Indices.push_back(vertCnt + 1 + gridY);
               mb->Indices.push_back(vertCnt + gridY);
               mb->Indices.push_back(vertCnt + 0);
            }
          vertCnt++; 
       }       
       
  return msh;
}   


IMesh* GD_Malla::DibujarEsfera()
{
   
   
    //  return msh;
}

void GD_Malla::RegistrarVelAni(int va)
{
    velani = va;     
}

void GD_Malla::CalibrarColisionConEscenario(float x, float y, float z)
{     
    intersec_coli_a->setScale(vector3df(x,y,z));
    intersec_coli_b->setScale(vector3df(x,y,z));
    intersec_coli_c->setScale(vector3df(x,y,z));
    intersec_coli_d->setScale(vector3df(x,y,z));
    intersec_coli_e->setScale(vector3df(x,y,z));
    intersec_coli_f->setScale(vector3df(x,y,z));         
}

void GD_Malla::CalibrarColisionConEscenarioX(float x, float y, float z)
{     
    intersec_coli_a->setScale(vector3df(x,y,z));
    intersec_coli_b->setScale(vector3df(x,y,z));
      
}

void GD_Malla::CalibrarColisionConEscenarioY(float x, float y, float z)
{     
    intersec_coli_c->setScale(vector3df(x,y,z));
    intersec_coli_d->setScale(vector3df(x,y,z));
      
}

void GD_Malla::CalibrarColisionConEscenarioZ(float x, float y, float z)
{     
    intersec_coli_e->setScale(vector3df(x,y,z));
    intersec_coli_f->setScale(vector3df(x,y,z));
      
}
