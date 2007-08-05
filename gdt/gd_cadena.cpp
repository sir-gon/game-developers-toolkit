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

#include "gd_cadena.h" // class's header file

// class constructor
GD_Cadena::GD_Cadena()
{
	//mStringC = "";
}

// class destructor
GD_Cadena::~GD_Cadena()
{
	// insert your code here
}




void GD_Cadena::operator = (char* CharIgual)
{
    mStringC = CharIgual;
}

void GD_Cadena::operator = (const char* CharIgual)
{
    mStringC = (char*)CharIgual;
}


void GD_Cadena::operator = (int IntIgual)
{
    mStringC = IntIgual;
}

void GD_Cadena::operator = (float FloatIgual)
{
    mStringC = FloatIgual;
}

void GD_Cadena::operator = (wchar_t* WCharIgual)
{
    mStringC = WCharIgual;
}

void GD_Cadena::operator = (const wchar_t* WCharIgual)
{
    mStringC = (wchar_t*)WCharIgual;
}

void GD_Cadena::operator = (GD_Cadena Cade)
{
    mStringC = Cade.mStringC;
}


/* //No funciona, sale error de compilacion cuando se llama asi:
// GD_Cadena Cade;
// Cade = "Hola" + "Mundo";
//
//        por ahora hay que usar el metodo Sumar.

GD_Cadena GD_Cadena::operator + (const char* CharIgual) const
{
          GD_Cadena TempC;
          TempC.Sumar(CharIgual);
          return TempC;
}

void GD_Cadena::operator + (int IntIgual)
{
    mStringC + IntIgual;
}

void GD_Cadena::operator + (float FloatIgual)
{
    mStringC + FloatIgual;
}

void GD_Cadena::operator + (wchar_t* WCharIgual)
{
    mStringC + WCharIgual;
}

void GD_Cadena::operator + (GD_Cadena Cade)
{
     mStringC + Cade.mStringC;
}

*/

char* GD_Cadena::RetornarChar()
{
      const c8* Dato_C = mStringC.c_str();
      return (char*)Dato_C;
}

const char* GD_Cadena::RetornarConstChar()
{
      const c8* Dato_C = mStringC.c_str();
      return Dato_C;
}

int GD_Cadena::RetornarInt()
{
      const c8* Dato_C = mStringC.c_str();
      return (int)core::fast_atof(Dato_C);
}


float GD_Cadena::RetornarFloat()
{
      const c8* Dato_C = mStringC.c_str();
      return (float)core::fast_atof(Dato_C);

}

const c8* GD_Cadena::RetornarConstC8()
{
      const c8* Dato_C = mStringC.c_str();
      return Dato_C;
}

c8* GD_Cadena::RetornarC8()
{
      const c8* Dato_C = mStringC.c_str();
      return (c8*)Dato_C;
}

const wchar_t* GD_Cadena::RetornarConstWChar_t()
{
      const c8* Dato_C = mStringC.c_str();
      core::stringw TempoW(Dato_C);
      const wchar_t* Dato_W = TempoW.c_str();
      return Dato_W;
}

// No sirve salen errores
/* Solucion temporal:
      core::stringw String_FileNameMalla(CadenaRutaMallaCargada.RetornarChar());
      const wchar_t* FileNameMalla = String_FileNameMalla.c_str();
*/
const wchar_t* GD_Cadena::RetornarWChar_t()
{

/* Solucion temporal:
      core::stringw String_FileNameMalla(CadenaRutaMallaCargada.RetornarChar());
      const wchar_t* FileNameMalla = String_FileNameMalla.c_str();
*/

      /*
      const c8* Dato_C = mStringC.c_str();
      core::stringw TempoW(Dato_C);

      const wchar_t* Dato_W = TempoW.c_str();

      return (wchar_t*)Dato_W;*/
      return L"RetornarWChar_t NO FUNCIONA BIEN";

}


void GD_Cadena::Sumar(GD_Cadena Cade)
{
     mStringC.append(Cade.mStringC);
}

void GD_Cadena::Sumar(int Entero)
{

    core::stringw TempoC(Entero);
    const wchar_t* Dato_W = TempoC.c_str();
    mStringC.append(Dato_W);
}

void GD_Cadena::Sumar(float Float)
{
    core::stringw TempoC(Float);
    const wchar_t* Dato_W = TempoC.c_str();
    mStringC.append(Dato_W);
}

void GD_Cadena::Sumar(char* Charc)
{
     mStringC.append(Charc);
}

void GD_Cadena::Sumar(wchar_t* WChar)
{
     mStringC.append(WChar);
}

// Otras utilidades

int GD_Cadena::TamanoChar(char* cade)
{
      core::stringw TextoString(L"");
      TextoString.append(cade);
      int TamanoChar;
      TamanoChar = TextoString.size();
      return TamanoChar;
}

int GD_Cadena::TamanoChar(const char* cade)
{
      core::stringw TextoString(L"");
      TextoString.append(cade);
      int TamanoChar;
      TamanoChar = TextoString.size();
      return TamanoChar;
}

int GD_Cadena::TamanoInt(int cade)
{
      core::stringw TextoString(L"");
      TextoString.append(cade);
      int TamanoChar;
      TamanoChar = TextoString.size();
      return TamanoChar;
}

char* GD_Cadena::ConvertirIntAChar(int numero)
{
      int AntiCrash=10;

        char * TempoNumeros2;
        char * TempoNumeros;

        // el 10 del ultimo parametro no estoy seguro que es
	// DESACTIVADO POR GON, ESTA LINEA PRODUCE UN:
	// error: ?itoa? no se declaró en este ámbito

        //TempoNumeros = itoa(numero,TempoNumeros2,AntiCrash);

        return TempoNumeros;

}

char* GD_Cadena::CopiarCharEnNuevaMemoria(char* Original)
{
      char* CopiaMem;
      CopiaMem=(char *)malloc(sizeof(Original));
      strcpy(CopiaMem, Original);
      return CopiaMem;
}
