// Class automatically generated by Dev-C++ New Class wizard

#include "gd_listaarchivos.h" // class's header file

// class constructor
GD_ListaArchivos::GD_ListaArchivos()
{
	// insert your code here
}

// class destructor
GD_ListaArchivos::~GD_ListaArchivos()
{
	// insert your code here
}

void GD_ListaArchivos::Crear(void)
{
     FileSystem = GD_Sistema::device->getFileSystem(); 
     
     FileList= FileSystem->createFileList();
}

int GD_ListaArchivos::Numero(void)
{
    return FileList->getFileCount();
}

const c8* GD_ListaArchivos::Nombre(int id)
{
      return FileList->getFileName(id);
}

const c8* GD_ListaArchivos::NombreCompleto(int id)
{
      return FileList->getFullFileName(id);
}

bool GD_ListaArchivos::EsDirectorio(int id)
{
      return FileList->isDirectory(id);
}