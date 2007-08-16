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

/*
 * Esta cabecera fue extraída de un archivo fuente de G3D.
 * El objetivo principal es contar con un detector de Plataforma,
 * es decir, poder conocer en que Sistema Operativo/Compilador se
 * esta trabajando.
 */

#ifndef GDT_PLATFORM_H
#define GDT_PLATFORM_H

//#define GDT_VER 20

#if defined(GDT_RELEASEDEBUG)
#   define GDT_DEBUGRELEASE
#endif

#if defined(GDT_DEBUGRELEASE) && defined(_DEBUG)
#   undef _DEBUG
#endif

#if !defined(GDT_DEBUG) && (defined(_DEBUG) || defined(GDT_DEBUGRELEASE))
#   define GDT_DEBUG
#endif

#ifdef _MSC_VER
    #define GDT_WIN32
#elif __MINGW32__
    #define GDT_WIN32
    #define GDT_MINGW32
#elif __linux__
    #define GDT_LINUX
#elif __APPLE__
    #define GDT_OSX
#else
    #error Unknown platform
#endif


// Default to compiling with SSE, but if you want to compile
// without installing SP5.0 and the Processor Pack on Windows, compile with NO_SSE
// defined (can be passed to the compiler command line with /D "NO_SSE")
#if !defined(NO_SSE)
   #define SSE
#endif

#ifdef GDT_WIN32
// Turn off warnings about deprecated C routines (TODO: revisit)
//#       pragma warning (disable : 4996)
#endif

// On g++, recognize cases where the -msse2 flag was not specified
#if defined(SSE) && defined(__GNUC__) && ! defined (__SSE__)
#   undef SSE
#endif

#if defined(__GNUC__)
#    if __STDC_VERSION__ < 199901
#        define restrict __restrict__
#    endif
#endif


// Verify that the supported compilers are being used and that this is a known
// processor.

#ifdef GDT_LINUX
#   ifndef __GNUC__
#       error GDT only supports the gcc compiler on Linux.
#   endif

#   ifndef __i386__
#       error GDT only supports x86 machines on Linux.
#   endif

#   define GDT_DEPRECATED __attribute__((__deprecated__))

#   ifndef __cdecl
#       define __cdecl __attribute__((cdecl))
#   endif

#   ifndef __stdcall
#       define __stdcall __attribute__((stdcall))
#   endif

#   define GDT_CHECK_PRINTF_METHOD_ARGS   __attribute__((__format__(__printf__, 2, 3)))
#   define GDT_CHECK_VPRINTF_METHOD_ARGS  __attribute__((__format__(__printf__, 2, 0)))
#   define GDT_CHECK_PRINTF_ARGS          __attribute__((__format__(__printf__, 1, 2)))
#   define GDT_CHECK_VPRINTF_ARGS         __attribute__((__format__(__printf__, 1, 0)))
#endif


#ifdef GDT_OSX
    #ifndef __GNUC__
        #error GDT only supports the gcc compiler on OS X.
    #endif

        #if defined(__i386__)
                #define GDT_OSX_INTEL
        #elif defined(__PPC__)
                #define GDT_OSX_PPC
        #else
                #define GDT_OSX_UNKNOWN
        #endif

#   ifndef __cdecl
#       define __cdecl __attribute__((cdecl))
#   endif

#   ifndef __stdcall
#       define __stdcall __attribute__((stdcall))
#   endif

#   define GDT_DEPRECATED __attribute__((__deprecated__))

#   define GDT_CHECK_PRINTF_METHOD_ARGS   __attribute__((__format__(__printf__, 2, 3)))
#   define GDT_CHECK_VPRINTF_METHOD_ARGS  __attribute__((__format__(__printf__, 2, 0)))
#   define GDT_CHECK_PRINTF_ARGS          __attribute__((__format__(__printf__, 1, 2)))
#   define GDT_CHECK_VPRINTF_ARGS         __attribute__((__format__(__printf__, 1, 0)))
#endif


#ifdef GDT_WIN32
// Microsoft Visual C++ 7.1     _MSC_VER = 1310
// Microsoft Visual C++ 7.0     _MSC_VER = 1300
// Microsoft Visual C++ 6.0     _MSC_VER = 1200
// Microsoft Visual C++ 5.0     _MSC_VER = 1100

    // Old versions of MSVC (6.0 and previous) don't
    // support C99 for loop scoping rules.  This fixes them.
#   if (_MSC_VER <= 1200)
        // This trick will generate a warning; disable the warning
//#       pragma warning (disable : 4127)
#       define for if (false) {} else for
#    endif

#   if (_MSC_VER <= 1200)
//      Nothing we can do on VC6 for deprecated functions
#      define GDT_DEPRECATED
#   else
#      define GDT_DEPRECATED __declspec(deprecated)
#   endif

// Prevent Winsock conflicts by hiding the winsock API
#ifndef _WINSOCKAPI_
#   define _GDT_INTERNAL_HIDE_WINSOCK_
#   define _WINSOCKAPI_
#   endif

// Disable 'name too long for browse information' warning
//#   pragma warning (disable : 4786)
// TODO: remove
//#   pragma warning (disable : 4244)

#       if defined(_MSC_VER) && (_MSC_VER <= 1200)
                //      VC6 std:: has signed problems in it
#               pragma warning (disable : 4018)
#       endif

#   define ZLIB_WINAPI

// Mingw32 defines restrict
#   ifndef GDT_MINGW32
#          define restrict
#   endif

#   define GDT_CHECK_PRINTF_ARGS
#   define GDT_CHECK_VPRINTF_ARGS
#   define GDT_CHECK_PRINTF_METHOD_ARGS
#   define GDT_CHECK_VPRINTF_METHOD_ARGS

    // On MSVC, we need to link against the multithreaded DLL version of
    // the C++ runtime because that is what SDL and ZLIB are compiled
    // against.  This is not the default for MSVC, so we set the following
    // defines to force correct linking.
    //
    // For documentation on compiler options, see:
    //  http://msdn.microsoft.com/library/default.asp?url=/library/en-us/vccore/html/_core_.2f.md.2c_2f.ml.mt.2c_2f.ld.asp
    //  http://msdn.microsoft.com/library/default.asp?url=/library/en-us/vccore98/HTML/Compiler_Reference.asp
    //

    // DLL runtime
    #ifndef _DLL
            #define _DLL
    #endif

    // Multithreaded runtime
    #ifndef _MT
            #define _MT 1
    #endif

    // Ensure that we aren't forced into the static lib
    #ifdef _STATIC_CPPLIB
            #undef _STATIC_CPPLIB
    #endif

    #ifdef _DEBUG
        //#pragma comment (linker, "/NODEFAULTLIB:LIBCMTD.LIB")
        //#pragma comment (linker, "/NODEFAULTLIB:LIBCPMTD.LIB")
        //#pragma comment (linker, "/NODEFAULTLIB:LIBCPD.LIB")
        //#pragma comment (linker, "/DEFAULTLIB:MSVCPRTD.LIB")
        //#pragma comment(linker, "/NODEFAULTLIB:LIBCD.LIB")
        //#pragma comment(linker, "/DEFAULTLIB:MSVCRTD.LIB")
    #else
        //#pragma comment(linker, "/NODEFAULTLIB:LIBC.LIB")
        //#pragma comment(linker, "/DEFAULTLIB:MSVCRT.LIB")
        //#pragma comment (linker, "/NODEFAULTLIB:LIBCMT.LIB")
        //#pragma comment (linker, "/NODEFAULTLIB:LIBCPMT.LIB")
        //#pragma comment(linker, "/NODEFAULTLIB:LIBCP.LIB")
        //#pragma comment (linker, "/DEFAULTLIB:MSVCPRT.LIB")
    #endif

    // Now set up external linking

    #ifdef _DEBUG
        // zlib and SDL were linked against the release MSVCRT; force
        // the debug version.
        //#pragma comment(linker, "/NODEFAULTLIB:MSVCRT.LIB")
#       endif


#   ifndef WIN32_LEAN_AND_MEAN
#       define WIN32_LEAN_AND_MEAN 1
#   endif


#   define NOMINMAX 1
#   include <windows.h>
#   undef WIN32_LEAN_AND_MEAN
#   undef NOMINMAX

#ifdef _GDT_INTERNAL_HIDE_WINSOCK_
#   undef _GDT_INTERNAL_HIDE_WINSOCK_
#   undef _WINSOCKAPI_
#endif


#   if defined(_MSC_VER) && (_MSC_VER <= 1200)
        // VC6 std:: has signed/unsigned problems
#       pragma warning (disable : 4018)
#   endif

#endif

#define STR(x) #x

// Header guard
#endif
