#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#define _WIN32_DCOM

#include <windows.h>
#include <stdio.h>
#include <taskschd.h>
#include <stdbool.h>

typedef struct APP_STATE
{
    wchar_t *szClassName;
    HINSTANCE hInstance;
    WNDPROC lpfnWndProc;
    HWND hwnd;
    wchar_t *szWindowTitle;
} APP_STATE;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, 
    WPARAM wParam, LPARAM lParam);

ATOM MedifyInitializeWndClass(APP_STATE *app);
bool MedifyCreateMainWindow(APP_STATE *app);

bool MedifyInitializeCOM(void);

int MedifyHandleWindowsErrors(void);