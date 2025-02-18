#include "medify.h"

APP_STATE app;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    PWSTR szCmdLine, int iCmdShow)
{
    app.szClassName = L"medify";
    app.szWindowTitle = L"Medify";
    app.hInstance = hInstance;
    app.lpfnWndProc = WndProc;

    if (!MedifyInitializeWndClass(&app))
    {
        return MedifyHandleWindowsErrors();
    }

    if (!MedifyCreateMainWindow(&app))
    {
        return MedifyHandleWindowsErrors();
    }

    if (!MedifyInitializeCOM())
    {
        return 1;
    }

    MSG msg;

    while (GetMessageW(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return msg.wParam;

    // TODO: open a dialog box at specifc time (e.g. 6 pm)
    //       use task scheduler for this
    //       Do this for every medicine, read data file first
    //       Main Window is for CRUD operations not reminding

    // TODO: Should the ITaskService open this program or another one?
    //       And should I add code to initialize this all on system startup
    //       or build as DLL? (Would a DLL change anything?)
}

ATOM MedifyInitializeWndClass(APP_STATE *app)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(wcex);
    wcex.style  = CS_VREDRAW | CS_HREDRAW;
    wcex.lpfnWndProc = app->lpfnWndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = app->hInstance;
    wcex.hIcon = LoadIconW(NULL, IDI_APPLICATION); // TODO: app icon
    wcex.hCursor = LoadCursorW(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = app->szClassName;
    wcex.hIconSm = NULL; // TODO: add app small icon

    return RegisterClassExW(&wcex);
}

bool MedifyCreateMainWindow(APP_STATE *app)
{
    app->hwnd = CreateWindowExW(
        0,
        app->szClassName,
        app->szWindowTitle,
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        app->hInstance,
        NULL
    );

    return (app->hwnd != NULL);
}

bool MedifyInitializeCOM(void)
{
    HRESULT hRes = CoInitializeEx(NULL, COINIT_MULTITHREADED);

    if (FAILED(hRes))
    {
        printf("CoInitializeEx failed: %x\n", hRes);
        return false;
    }

    hRes = CoInitializeSecurity(
        NULL,
        -1,
        NULL,
        NULL,
        RPC_C_AUTHN_LEVEL_PKT_PRIVACY,
        RPC_C_IMP_LEVEL_IMPERSONATE,
        NULL,
        0,
        NULL
    );

    if (FAILED(hRes))
    {
        printf("\nCoInitializeSecurity failed: %x", hRes);
        CoUninitialize();
        return false;
    }

    return true;
}

int MedifyHandleWindowsErrors(void)
{
    int errorCode = GetLastError();

    printf("Error: Windows Code %d, check MS Docs.\n", errorCode);
    return errorCode;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, 
    WPARAM wParam, LPARAM lParam)
{
    // TODO: use child windows to build a CRUD interface with medicines list
    //       listbox control? to display list, buttons for delete (and edit?)
    //       edit control and button to add
    // TODO: use local file to store list
    switch(message)
    {
        case WM_CREATE:
        {
            RECT rc;
            GetClientRect(hwnd, &rc);
            InvalidateRect(hwnd, &rc, TRUE);
        }

        case WM_PAINT:
        {
            HDC hdc = GetDC(hwnd);
            ReleaseDC(hwnd, hdc);
        }
    }

    return DefWindowProcW(hwnd, message, wParam, lParam);
}