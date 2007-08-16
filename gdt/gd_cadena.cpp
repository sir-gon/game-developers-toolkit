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

/*!
* \class GDT::Cadena
* \since 2.0
*
* Permite cargar, retornar, convertir y manipular cadenas de caracteres
* de diferentes tipos.
*
* Permite uniformar el tratamiento de cadenas en GDT, de modo que
* sea sencillo poder hacer las operaciones m&aacute;s comunes con cadenas
* como concatenar, convertir el tipo de cadena, obtener la longitud, etc.
*
* Adem�, se han implementado operadores sobrecargados para hacer que el
* c�igo sea muchos m� legible, de facil entendimiento y que las tareas
* sean mucho m&aacute;s sencillas de realizar.
*
* \author Joropo
* \warning Esta clase es Experimental.
*/

/*!
*/
GDT::Cadena::Cadena()
{
}

/*!
*/
GDT::Cadena::Cadena(char* cadena)
{
    mStringC = cadena;
}

/*!
*/
GDT::Cadena::Cadena(const char* cadena)
{
    mStringC = (char*)cadena;
}

/*!
*/
GDT::Cadena::Cadena(wchar_t* cadena)
{
    mStringC = cadena;
}

/*!
*/
GDT::Cadena::Cadena(const wchar_t* cadena)
{
    mStringC = (wchar_t*)cadena;
}

/*!
*/
GDT::Cadena::~Cadena()
{
}


// OPERADOR DE ASIGNACION
/*!
*
*/
void GDT::Cadena::operator = (char* CharIgual)
{
    mStringC = CharIgual;
}

/*!
*/
void GDT::Cadena::operator = (const char* CharIgual)
{
    mStringC = (char*)CharIgual;
}

/*!
*/
void GDT::Cadena::operator = (int IntIgual)
{
    mStringC = IntIgual;
}

/*!
* En caso de que salga un error de compilacion como este:
* 1503 main.cpp ambiguous overload for 'operator=' in ' ...
*
* Debemos ponerle una f al final del numero para que el * compilador lo diferencie
* de un double ej. 14.235f
*/
void GDT::Cadena::operator = (float FloatIgual)
{
    mStringC = FloatIgual;
}

/*!
*/
void GDT::Cadena::operator = (wchar_t* WCharIgual)
{
    mStringC = WCharIgual;
}

/*!
*/
void GDT::Cadena::operator = (const wchar_t* WCharIgual)
{
    mStringC = (wchar_t*)WCharIgual;
}

/*!
*/
void GDT::Cadena::operator = (Cadena Cade)
{
    mStringC = Cade.mStringC;
}

// RETORNOS
/*!
*/
char* GDT::Cadena::RetornarChar()
{
      const c8* Dato_C = mStringC.c_str();
      return (char*)Dato_C;
}

/*!
*/
const char* GDT::Cadena::RetornarConstChar()
{
      const c8* Dato_C = mStringC.c_str();
      return Dato_C;
}

/*!
*/
u32 GDT::Cadena::RetornarInt()
{
      const c8* Dato_C = mStringC.c_str();
      return (int)core::fast_atof(Dato_C);
}

/*!
*/
float GDT::Cadena::RetornarFloat()
{
      const c8* Dato_C = mStringC.c_str();
      return (float)core::fast_atof(Dato_C);

}

/*!
*/
const c8* GDT::Cadena::RetornarConstC8()
{
      const c8* Dato_C = mStringC.c_str();
      return Dato_C;
}

/*!
*/
c8* GDT::Cadena::RetornarC8()
{
      const c8* Dato_C = mStringC.c_str();
      return (c8*)Dato_C;
}

/*!
*/
const wchar_t* GDT::Cadena::RetornarConstWChar_t()
{
      const c8* Dato_C = mStringC.c_str();
      core::stringw TempoW(Dato_C);
      const wchar_t* Dato_W = TempoW.c_str();
      return Dato_W;
}

wchar_t* GDT::Cadena::RetornarWChar_t()
{
      char* temporal = RetornarChar();
      wchar_t* salida = ConvertirCharEnWchart(temporal);

      return salida;
}

// CONCATENAR
void GDT::Cadena::Sumar(Cadena Cade)
{
     mStringC.append(Cade.mStringC);
}

void GDT::Cadena::Sumar(int Entero)
{

    core::stringw TempoC(Entero);
    const wchar_t* Dato_W = TempoC.c_str();
    mStringC.append(Dato_W);
}

void GDT::Cadena::Sumar(float numero)
{
    core::stringw TempoC(numero);
    const wchar_t* Dato_W = TempoC.c_str();
    mStringC.append(Dato_W);
}

void GDT::Cadena::Sumar(char* cadena)
{
     mStringC.append(cadena);
}

void GDT::Cadena::Sumar(const char* cadena)
{
     mStringC.append(cadena);
}

void GDT::Cadena::Sumar(wchar_t* cadena)
{
     mStringC.append(cadena);
}

// Otras utilidades
u32 GDT::Cadena::Longitud()
{
	return mStringC.size();
}

u32 GDT::Cadena::Longitud(char* cadena)
{
      core::stringw TextoString(L"");
      TextoString.append(cadena);
      int TamanoChar;
      TamanoChar = TextoString.size();
      return TamanoChar;
}

u32 GDT::Cadena::Longitud(const char* cadena)
{
      core::stringw TextoString(L"");
      TextoString.append(cadena);
      int TamanoChar;
      TamanoChar = TextoString.size();
      return TamanoChar;
}

u32 GDT::Cadena::Longitud(int cadena)
{
      core::stringw TextoString(L"");
      TextoString.append(cadena);
      int TamanoChar;
      TamanoChar = TextoString.size();
      return TamanoChar;
}


/*!
* Con el fin de copiar enteramente el char y no un apuntador a la misma
* parte como se haria con Cadena1 = Cadena2, al modificar cualquiera de los dos
* instantaneamente el otro tambien se modifica ya que es un apuntador, lo que hace este
* metodo es crear un espacio real para asignar el mismo valor y que asi sean independientes.
*/
char* GDT::Cadena::CopiarCharEnNuevaMemoria(char* Original)
{
      char* CopiaMem;
      CopiaMem=(char *)malloc(sizeof(Original));
      strcpy(CopiaMem, Original);
      return CopiaMem;
}

//////// CONVERSORES ESTATICOS

/*!
* \return un puntero a la cadena de texto de tipo char
*
* Ejemplo:
* \code
*  int cantidad_entera = -13245;
*  char* entero_en_palabras = GDT::Cadena::ConvertirNumeroEnChar(cantidad_entera);
*  cout << "El numero entero es: " << entero_en_palabras << endl;
* \endcode
*
* \author sir_gon <sir_gon@users.sourceforge.net>
*/
char* GDT::Cadena::ConvertirNumeroEnChar(int numero)
{

	// Calcular la cantidad de digitos del numero
	int digitos = 1 +
		(int)Matematicas::Logaritmo10(
			Matematicas::Absoluto( numero )
		);
	#ifdef _GDT_DEBUG_
	printf("El entero tiene: %d digitos\n", digitos);
	printf("Se asignara %d bits memoria.", digitos*sizeof(char)+2);
	#endif
	// Asignar la memoria para alojar los digitos m� un signo y
	// el caracter nulo
	char * salida = (char *)malloc(digitos*sizeof(char)+2);
	// Si el salida es nulo, abortar programa
	if (salida == NULL)
	{
	printf ("Memory allocating attempt has failed in"
		"'double_to_char'\n") ;
	exit (-1) ;
	}

	int n;
	n=sprintf (salida, "%d", numero);
	#ifdef _GDT_DEBUG_
	printf ("%s\n",salida);
	#endif

	/*
	// ESTA IMPLEMENTACION POR ALGUN MOTIVO
	// CORROMPE LOS PRIMEROS DIGITOS AL HACER EL RETORNO.

	Cadena temporal;
	temporal = numero;
	const char* salida= temporal.RetornarChar();
	cout <<  "numero por salir:" << salida << endl;
	*/

	// Retornar la cadena
	return salida;

}



/*!
* \return un puntero a la cadena de texto de tipo char
*
* Ejemplo:
* \code
* // Convertir Double a cadena
* double cantidad_real = -1234.5678;
* char* real_en_palabras = GDT::Cadena::ConvertirNumeroEnChar(cantidad_real);
* cout << "El numero real es: " << real_en_palabras << endl;
* \endcode
*
* \bug con float es impreciso
*
* \author sir_gon <sir_gon@users.sourceforge.net>
*/
char * GDT::Cadena::ConvertirNumeroEnChar(double numero)
{
   char *salida,
        *temp ;

   int  decimal_spot,
        sign,
        count,
        current_location = 0 ;

   temp = fcvt (numero, PRECISION, &decimal_spot, &sign) ;

   if (strlen (temp) > PRECISION)
      salida = (char *) malloc (strlen (temp) + 3) ;
   else
      salida = (char *) malloc (PRECISION + 3) ;

   if (salida == NULL)
   {
      printf ("Memory allocating attempt has failed in"
              "'double_to_char'\n") ;
      exit (-1) ;
   }

// Add negative sign if required

   if (sign)
      salida [current_location++] = '-' ;

// Place decimal point in the correct location

   if (decimal_spot > 0)
   {
      strncpy (&salida [current_location], temp, decimal_spot) ;
      salida [decimal_spot + current_location] = '.' ;
      strcpy (&salida [decimal_spot + current_location + 1],
                      &temp [decimal_spot]) ;
   }
   else
   {
      salida [current_location] = '.' ;
      for(count = current_location;
             count<abs(decimal_spot)+current_location; count++)
         salida [count + 1] = '0' ;
      strcpy (&salida [count + 1], temp) ;
   }

	/*
	// ESTA IMPLEMENTACION POR ALGUN MOTIVO
	// CORROMPE LOS PRIMEROS DIGITOS AL HACER EL RETORNO.

	Cadena temporal;
	temporal = (float)numero;
	char* salida= temporal.RetornarChar();
	cout <<  "numero por salir:" << salida << endl;
	*/

	return salida;
}

/*!
* \bug NO implementado
*/
wchar_t * GDT::Cadena::ConvertirNumeroEnWchart(int numero)
{
    wchar_t *salida=NULL;

    return salida;
}

/*!
* \bug NO implementado
*/
wchar_t * GDT::Cadena::ConvertirNumeroEnWchart(double numero)
{
    wchar_t *salida=NULL;

    return salida;
}


/*!
* \return un puntero a la cadena de texto de tipo char*.
*
* \code
* char* texto;
* texto = GDT::Cadena::ConvertirWchartEnChar(L"Cadena wchar_t convertida en char");
* cout << texto << endl;
* \endcode
*
* \author sir_gon <sir_gon@users.sourceforge.net>
*/
char * GDT::Cadena::ConvertirWchartEnChar(wchar_t *cadena)
{
    int x;
    char *salida = (char *)malloc(
	sizeof(wchar_t)* std::char_traits<wchar_t>::length(cadena)
    );
    // Si el salida es nulo, abortar programa
    if (salida == NULL)
    {
    printf ("Fallo la reserva de memoria en"
     "'ConvertirWchartEnChar'\n") ;
    exit (-1) ;
    }

    #ifdef _GDT_DEBUG_
    printf( "MB_CUR_MAX = %d\n\n", MB_CUR_MAX );
    printf( "Convertir a una cadena multibyte:\n" );
    #endif

    //return salida;
    x = wcstombs(
        salida,
        cadena,
        sizeof(wchar_t)* std::char_traits<wchar_t>::length(cadena)
    );
    #ifdef _GDT_DEBUG_
    printf( "\tCaracteres convertidos %u\n", x );
    printf( "\tValor hexadecimal del primer" );
    printf( " caracter multibyte: %#.4x\n\n", salida );
    printf( "\tCADENA FINAL: %s\n", salida );
    #endif
    return salida;
}

/*!
* \return un puntero a la cadena de texto de tipo char*.
*
* \code
* // Convertir wchar_t* en char*
* wchar_t* otrotexto;
* otrotexto = GDT::Cadena::ConvertirCharEnWchart("Cadena char convertida en wchar_t");
* #ifndef MINGW32
* // wcout no funciona en mingw32
* wcout << otrotexto << endl;
* #endif
* \endcode
*
* \author sir_gon <sir_gon@users.sourceforge.net>
*/
wchar_t * GDT::Cadena::ConvertirCharEnWchart(char* cadena)
{
    int x;

    wchar_t *salida =
       (wchar_t *)malloc(
          strlen(cadena) * sizeof(wchar_t) + 1
       );

    if (salida == NULL)
    {
    printf ("Fallo la reserva de memoria en"
     "'ConvertirCharEnWchart'\n") ;
    exit (-1) ;
    }

    x = mbstowcs( salida, cadena, strlen(cadena) + 1 );
    return salida;
}




// OPERADORES:
// OPERADOR == (Comparacion verdadera)

bool GDT::Cadena::operator == (GDT::Cadena cadena)
{
	return mStringC == cadena.mStringC;
}

bool GDT::Cadena::operator == (char* cadena)
{
	Cadena temp(cadena);
	return mStringC == temp.mStringC;
}

bool GDT::Cadena::operator == (wchar_t* cadena)
{
	Cadena temp(cadena);
	return mStringC == temp.mStringC;
}

// OPERADOR == (Comparacion falsa)
bool GDT::Cadena::operator != (GDT::Cadena cadena)
{
	return mStringC != cadena.mStringC;
}

bool GDT::Cadena::operator != (char* cadena)
{
	Cadena temp(cadena);
	return mStringC != temp.mStringC;
}

bool GDT::Cadena::operator != (wchar_t* cadena)
{
	Cadena temp(cadena);
	return mStringC != temp.mStringC;
}

// OPERADOR + (SUMA BINARIA)
/*!
* Ejemplo:
* \code
* // Sumar Cadena con char
* Cadena MiTexto("Hola");
* MiTexto = MiTexto + " Mundo!!!";
* \endcode
*/
GDT::Cadena GDT::Cadena::operator + (const char* cadena)
{
    // Falta optimizar, para evitar la copia del objeto
    Cadena Salida;
    Salida.mStringC = mStringC;
    Salida.Sumar(cadena);
    return Salida;
}

/*!
* Ejemplo:
* \code
* // Sumar Cadena con char
* Cadena MiTexto(L"Hola");
* MiTexto = MiTexto + L" Mundo!!!";
* \endcode
*/
GDT::Cadena GDT::Cadena::operator + (const wchar_t* cadena)
{
    // Falta optimizar, para evitar la copia del objeto
    Cadena Salida;
    //Salida.mStringC = mStringC;
    //Salida.Sumar(cadena);
    return Salida;
}

/*!
* Ejemplo:
* \code
* // Sumar Cadena con char
* Cadena MiTexto1("Hola");
* Cadena MiTexto2(" Mundo!!!");
* Cadena MiTexto3;
*
* MiTexto3 = MiTexto1 + MiTexto2;
* \endcode
*/
GDT::Cadena GDT::Cadena::operator + (Cadena cadena)
{
    // Falta optimizar, para evitar la copia del objeto

    Cadena Salida;
    Salida.mStringC = mStringC;
	Salida.Sumar(cadena.RetornarChar());
    return Salida;
}


// Suma-asignaci�

/*!
*/
void GDT::Cadena::operator+= (int numero)
{
	Sumar(numero);
}

/*!
*/
void GDT::Cadena::operator+= (float numero)
{
	Sumar(numero);
}

/*!
*/
/*
void GDT::Cadena::operator+= (double numero)
{
	//Sumar(numero);
}
*/

/*!
*/
void GDT::Cadena::operator+= (Cadena cadena)
{
	Sumar(cadena);
}

/*!
*/
void GDT::Cadena::operator+= (const char* cadena)
{
	Sumar(cadena);
}

/*!
*/
void GDT::Cadena::operator+= (const wchar_t* cadena)
{
	Sumar(cadena);
}



