#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#include <windows.h>
#include <stdio.h>

typedef struct APP_STATE
{
    wchar_t *szClassName;
    HINSTANCE hInstance;
    WNDPROC lpfnWndProc;
} APP_STATE;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, 
    WPARAM wParam, LPARAM lParam);