#include "medify.h"

APP_STATE app;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    PWSTR szCmdLine, int iCmdShow)
{
    WNDCLASSEXW wcex;

    app.szClassName = L"medify";
    app.hInstance = hInstance;
    app.lpfnWndProc = WndProc;

    wcex.cbSize = sizeof(wcex);
    wcex.style  = CS_VREDRAW | CS_HREDRAW;
    wcex.lpfnWndProc = app.lpfnWndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = app.hInstance;
    wcex.hIcon = LoadIconW(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursorW(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = app.szClassName;
    wcex.hIconSm = NULL;

    if (!RegisterClassExW(&wcex))
    {
        printf("Error %d: RegisterClassExW failed", GetLastError());
        return 1;
    }

    CreateWindowExW(
        0,
        app.szClassName,
        L"Medify",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    MSG msg;

    while (GetMessageW(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return msg.wParam;

    // open a dialog box at specifc time (6 pm)
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, 
    WPARAM wParam, LPARAM lParam)
{
    return DefWindowProcW(hwnd, message, wParam, lParam);
}