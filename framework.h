// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once
#define _WIN32_WINNT _WIN32_WINNT_WINXP
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers


// // Including SDKDDKVer.h defines the highest available Windows platform.
// If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
// set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.
#include <SDKDDKVer.h>

//#define _WIN64
//#define _AMD64_
// Windows Header Files
#include <windows.h>
//// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
//#include <tchar.h>
