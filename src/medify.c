#include "medify.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    PWSTR szCmdLine, int iCmdShow)
{
    WNDCLASSEXW wcex;

    wchar_t szClassName[] = L"medify";

    wcex.cbSize = sizeof(wcex);
    wcex.style  = CS_VREDRAW | CS_HREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIconW(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursorW(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szClassName;
    wcex.hIconSm = NULL;

    if (!RegisterClassExW(&wcex))
    {
        printf("Error %d: RegisterClassExW failed", GetLastError());
        return 1;
    }

    // CreateWindowExW(
    //     0,
    //     szClassName,
    //     [in, optional] LPCWSTR   lpWindowName,
    //     [in]           DWORD     dwStyle,
    //     [in]           int       X,
    //     [in]           int       Y,
    //     [in]           int       nWidth,
    //     [in]           int       nHeight,
    //     [in, optional] HWND      hWndParent,
    //     [in, optional] HMENU     hMenu,
    //     [in, optional] HINSTANCE hInstance,
    //     [in, optional] LPVOID    lpParam
    // );

    // open a dialog box at specifc time (6 pm)
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, 
    WPARAM wParam, LPARAM lParam)
{
    return DefWindowProcW(hwnd, message, wParam, lParam);
}