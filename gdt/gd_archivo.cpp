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
 * \class GD_Archivo
 *
 * Con esta clase se puede manejar informaci&oacute;n en archivos f&aacute;cilmente.
 *
 * Se puede trabajar con archivos de texto, o con archivos de estructuras.
 *
 * Siempre y cuando el usuario tenga permiso de acceso, el programa podrá
 * leer/escribir en la ruta que necesitemos.
 *
 * Trabajar con archivos nos permite (por ejemplo), salvar el estado actual
 * del juego, puntajes, internacionalizar la interfaz 
 * (ofreciendola en varios idiomas), en fin, todo lo que requiera 
 * leer/guardar información.
 */

#include "gd_archivo.h" // class's header file


// class constructor
GD_Archivo::GD_Archivo()
{
	// insert your code here
}

// class destructor
GD_Archivo::~GD_Archivo()
{
	// insert your code here
}

/*!
* \param strArchivo la ruta al archivo.
* \param bContinuar opcional. Hace que el archivo no se sobrescriba, sino 
* que se escriba a continuaci&oacute;n de lo que ya hay.
* 
* Ejemplo:
* \code
* Archivo.AbrirParaEscribir("datos.txt");
* \endcode
*/
void GD_Archivo::AbrirParaEscribir(const char *strArchivo, bool bContinuar)
{
     FileSystem = GD_Sistema::device->getFileSystem(); 
     
     writeFile = FileSystem->createAndWriteFile(strArchivo, bContinuar);  
     
     bEscribir = true;  
}

/*!
* Ejemplo:
* \code
* Archivo.AbrirParaLeer("datos.txt");
* \endcode
*/
void GD_Archivo::AbrirParaLeer(const char *strArchivo)
{
     FileSystem = GD_Sistema::device->getFileSystem(); 
     
     readFile = FileSystem->createAndOpenFile(strArchivo);   
     
     bEscribir = false; 
}

/*!
* Ejemplo:
* \code
* Archivo.Cerrar();
* \endcode
*/
void GD_Archivo::Cerrar(void)
{
     if(bEscribir)
         writeFile->drop();
     else
         readFile->drop();
}

/*!
* \param strCadena el texto a escribir en el archivo
* \param bytes el n&uacute;mero de bytes que se escribir&aacute;n
* 
* Escribe el nï&uacute;mero de bytes indicados de la cadena.
* 
* \note Se deja este m&eacute;todo con los dos p&aacute;rametros para evitar 
* conflictos con versiones anteriores y para casos especiales donde se necesite
* limitar la salida.
* 
* Ejemplo:
* \code
* Archivo.Escribir("Hola", 4);
* \endcode
*/
void GD_Archivo::Escribir(const char *strCadena, int bytes)
{
     if(bEscribir)
     {
         writeFile->write(strCadena, bytes);
     }
}

/*!
* \param strCadena el texto a escribir en el archivo
*
* La longitud del texto se obtiene de forma autom&aacute;tica.
*
* Ejemplo:
* \code
* Archivo.Escribir("Hola");
* \endcode
*/
void GD_Archivo::Escribir(const char *strCadena)
{
     int bytes;
     GD_Cadena Cadenin;

     bytes = Cadenin.TamanoChar(strCadena);

     if(bEscribir)
     {
         writeFile->write(strCadena, bytes);
     }
}

void GD_Archivo::Escribir(int numero)
{
     GD_Cadena Cadenin;
     int bytes;
     bytes = Cadenin.TamanoInt(numero);

     if(bEscribir)
     {
         writeFile->write((int*)numero, bytes);
     }
}

/*!
Copia en el buffer indicado el n&uacute;mero de bytes que se quieren leer del archivo.

Ejemplo:
\code
char Texto[4];
Archivo.Leer(Texto, 4);
\endcode
*/
void GD_Archivo::Leer( char * buffer, int bytes)
{
     if(!bEscribir)
     {
         readFile->read( buffer, bytes);
     }
}

/*!
\return el n&uacute;mero de bytes totales del archivo se est&aacute; leyendo, devuelve el nÃºmero de bytes totales del archivo.

\code
char Texto[4];
Archivo.Leer(Texto, 4);
\endcode

*/
int GD_Archivo::Bytes(void)
{
     if(!bEscribir)
     {
         readFile->getSize();
		 return true;
     }
	 return false;
}

bool GD_Archivo::CambiarPosicion(int posicion, bool bRelativo)
{
     if(bEscribir)
     {
         return writeFile->seek(posicion, bRelativo);
     }
     else
     {
         return readFile->seek(posicion, bRelativo);
     }
}

int GD_Archivo::Posicion(void)
{
    if(bEscribir)
    {
        return writeFile->getPos();
    }
    else
    {
        return readFile->getPos();
    }
}

const char *GD_Archivo::NombreArchivo(void)
{
    if(bEscribir)
    {
        return writeFile->getFileName();
    }
    else
    {
        return readFile->getFileName();
    }
}
