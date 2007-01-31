// Class automatically generated by Dev-C++ New Class wizard

#include "gd_escenario.h" // class's header file

// class constructor
GD_Escenario::GD_Escenario()
{
	// insert your code here
}

// class destructor
GD_Escenario::~GD_Escenario()
{
	// insert your code here
}

void GD_Escenario::CargarBSP(char *filenamePK3, char *filenameBSP)
{
    
        
    
    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=GD_Sistema::device->getSceneManager();

        
     midevice->getFileSystem()->addZipFileArchive(filenamePK3);
		
      mesh = mismgr->getMesh(filenameBSP);
          	
          	   
	if (mesh)
	    nodon = mismgr->addOctTreeSceneNode(mesh->getMesh(0));
	    
	     if(!nodon) printf("ERROR: No se pudo Cargar El Escenario BSP, %s en el paquete %s.\n", filenameBSP ,filenamePK3 );
	    

          	
		selector = mismgr->createOctTreeTriangleSelector(mesh->getMesh(0), nodon);
		nodon->setTriangleSelector(selector);
		//selector->drop();
	
    
     	

}

void GD_Escenario::Cargar(char *filename)
{
           
     
    RegistrarDevice(GD_Sistema::device);
    ISceneManager* mismgr=GD_Sistema::device->getSceneManager();

     IAnimatedMesh* mesha = mismgr->getMesh(filename);
     meshs = mesha->getMesh(0); 
     
     nodon = mismgr->addOctTreeSceneNode(meshs);
     if(!nodon) printf("ERROR: No se pudo Cargar El Escenario, %s.\n", filename);     
	    
		selector = mismgr->createOctTreeTriangleSelector(meshs, nodon);
		nodon->setTriangleSelector(selector);  
	
	ColorDifuso(100,100,100);
}

ITriangleSelector* GD_Escenario::RetornarDatos()
{
     return selector;
}