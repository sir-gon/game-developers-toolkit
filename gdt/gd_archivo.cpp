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
 * \class GDT::Archivo
 *
 * Con esta clase se puede manejar informaci&oacute;n en archivos f&aacute;cilmente.
 *
 * Se puede trabajar con archivos de texto, o con archivos de estructuras.
 *
 * Siempre y cuando el usuario tenga permiso de acceso, el programa podr� * leer/escribir en la ruta que necesitemos.
 *
 * Trabajar con archivos nos permite (por ejemplo), salvar el estado actual
 * del juego, puntajes, internacionalizar la interfaz
 * (ofreciendola en varios idiomas), en fin, todo lo que requiera
 * leer/guardar informaci�.
 */

#include "gd_archivo.h" // class's header file


// class constructor
GDT::Archivo::Archivo()
{
	// insert your code here
}

// class destructor
GDT::Archivo::~Archivo()
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
void GDT::Archivo::AbrirParaEscribir(const char *strArchivo, bool bContinuar)
{
     FileSystem = Sistema::device->getFileSystem();

     writeFile = FileSystem->createAndWriteFile(strArchivo, bContinuar);

     bEscribir = true;
}

/*!
* Ejemplo:
* \code
* Archivo.AbrirParaLeer("datos.txt");
* \endcode
*/
void GDT::Archivo::AbrirParaLeer(const char *strArchivo)
{
     FileSystem = Sistema::device->getFileSystem();

     readFile = FileSystem->createAndOpenFile(strArchivo);

     bEscribir = false;
}

/*!
* Ejemplo:
* \code
* Archivo.Cerrar();
* \endcode
*/
void GDT::Archivo::Cerrar(void)
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
* Escribe el n�uacute;mero de bytes indicados de la cadena.
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
void GDT::Archivo::Escribir(const char *strCadena, int bytes)
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
void GDT::Archivo::Escribir(const char *strCadena)
{
     int bytes;
     Cadena Cadenin;

     bytes = Cadenin.Longitud(strCadena);

     if(bEscribir)
     {
         writeFile->write(strCadena, bytes);
     }
}

void GDT::Archivo::Escribir(int numero)
{
     Cadena Cadenin;
     int bytes;
     bytes = Cadenin.Longitud(numero);

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
void GDT::Archivo::Leer( char * buffer, int bytes)
{
     if(!bEscribir)
     {
         readFile->read( buffer, bytes);
     }
}

/*!
\return el n&uacute;mero de bytes totales del archivo se est&aacute; leyendo, devuelve el número de bytes totales del archivo.

\code
char Texto[4];
Archivo.Leer(Texto, 4);
\endcode

*/
int GDT::Archivo::Bytes(void)
{
     if(!bEscribir)
     {
         readFile->getSize();
		 return true;
     }
	 return false;
}

bool GDT::Archivo::CambiarPosicion(int posicion, bool bRelativo)
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

int GDT::Archivo::Posicion(void)
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

const char *GDT::Archivo::NombreArchivo(void)
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
