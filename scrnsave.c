/*
 * PROJECT:         ReactOS Screen Saver Library
 * LICENSE:         GPL v2 or any later version
 * FILE:            lib/sdk/scrnsave/scrnsave.c
 * PURPOSE:         Library for writing screen savers, compatible with
 *                  MS' scrnsave.lib without Win9x support.
 * PROGRAMMERS:     Anders Norlander <anorland@hem2.passagen.se>
 *                  Colin Finck <mail@colinfinck.de>
 */
#include "framework.h"
#include <stdarg.h>
#include <windef.h>
#include <winbase.h>
#include <wingdi.h>
#include <winuser.h>
#include <tchar.h>
#include <scrnsave.h>

// Screen Saver window class
#define CLASS_SCRNSAVE TEXT("WindowsScreenSaverClass")

// Globals
HWND        hMainWindow = NULL;
BOOL        fChildPreview = FALSE;
HINSTANCE   hMainInstance;
TCHAR       szName[TITLEBARNAMELEN];
TCHAR       szAppName[APPNAMEBUFFERLEN];
TCHAR       szIniFile[MAXFILELEN];
TCHAR       szScreenSaver[22];
TCHAR       szHelpFile[MAXFILELEN];
TCHAR       szNoHelpMemory[BUFFLEN];
UINT        MyHelpMessage;

// Local house keeping
static POINT pt_orig;

static int ISSPACE(TCHAR c)
{
    return (c == ' ' || c == '\t');
}

#define ISNUM(c) ((c) >= '0' && (c) <= '9')

static ULONG_PTR _toulptr(const TCHAR *s)
{
    ULONG_PTR res;
    ULONG_PTR n;
    const TCHAR *p;

    for (p = s; *p; p++)
        if (!ISNUM(*p))
            break;

    p--;
    res = 0;

    for (n = 1; p >= s; p--, n *= 10)
        res += (*p - '0') * n;

    return res;
}

