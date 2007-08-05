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

#ifndef GD_CADENA_H
#define GD_CADENA_H

/*
 * No description
 */

#include "gd_sistema.h"
 
class GD_Cadena// : public core::stringc
{
	public:
		// class constructor
		GD_Cadena();
		// class destructor
		~GD_Cadena();
		
		
		core::stringc mStringC;
//		core::stringw mStringW;


        // Operadores asignacion
        // =
        // +
        
        void operator = (GD_Cadena Cade);
        void operator = (char* CharIgual);
        void operator = (const char* CharIgual);        
        void operator = (int IntIgual);
        //! En caso de que salga un error de compilacion como este: 1503 main.cpp ambiguous overload for 'operator=' in ' ... .Debemos ponerle una f al final del numero para que el compilador lo diferencie de un int ej. 14.235f 
        void operator = (float FloatIgual);
        void operator = (wchar_t* WCharIgual);
        void operator = (const wchar_t* WCharIgual);        
        

/*     //No funciona, sale error de compilacion cuando se llama asi:
       // GD_Cadena Cade;
       // Cade = "Hola" + "Mundo";
       
       por ahora hay que usar el metodo Sumar.
   
    
    GD_Cadena operator + (char* CharIgual);
        void operator + (int IntIgual);
        //! En caso de que salga un error de compilacion como este: 1503 main.cpp ambiguous overload for 'operator=' in ' ... .Debemos ponerle una f al final del numero para que el compilador lo diferencie de un int ej. 14.235f 
        void operator + (float FloatIgual);
        void operator + (wchar_t* WCharIgual); 
        void operator + (GD_Cadena Cade);      
        
GD_Cadena operator + (GD_Cadena Cadena) const
{
          GD_Cadena TempC;
          TempC.Sumar(Cadena);
          return TempC;
}
        
        
*/


        
        void Sumar(GD_Cadena Cade); 
        void Sumar(wchar_t* WChar);
        void Sumar(char* Charc);
        void Sumar(float Float);
        void Sumar(int Entero);
        
 
        // Operadores comparacion
        // ==
        // !=
        
        // Retorna en diferentes tipos
        // int
        // float
        // char*
        // c8*
        // wchar_t*
        
        int RetornarInt();
        float RetornarFloat();
        char* RetornarChar();
        const char* RetornarConstChar();
        c8* RetornarC8();
        const c8* RetornarConstC8();
        const wchar_t* RetornarWChar_t(); // parece que tiene un bug que no reconoce los dos primeros caracteres
        const wchar_t* RetornarConstWChar_t();
        
        
		
		
        /// Otras utilidades --------------------
		
		//! Devuelve el tamano del arreglo char*
		int TamanoChar(char* cade);
		int TamanoChar(const char* cade);	
		
		int TamanoInt(int cade);
        
        //! Convierte int en char* 
        char* ConvertirIntAChar(int numero);
        //! Crea espacio en memoria y asigna el valor de char, con el fin de copiar enteramente el char y no un apuntador a la misma parte como se haria con Cadena1 = Cadena2, al modificar cualquiera de los dos instantaneamente el otro tambien se modifica ya que es un apuntador, lo que hace este metodo es crear un espacio real para asignar el mismo valor y que asi sean independientes.
        char* CopiarCharEnNuevaMemoria(char* Original);
		
};

#endif // GD_CADENA_H
