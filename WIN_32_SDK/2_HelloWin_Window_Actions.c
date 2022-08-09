/*
Demo of some of the window actions
*/
#include<Windows.h>
#include<assert.h>

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nShowCmd)
{
    static TCHAR szAppName[] = TEXT("Window - Let's check the actions");
    static TCHAR szClassName[] = TEXT("MyClass");

    WNDCLASSEX wndEx;
    MSG msg;

    ZeroMemory(&wndEx, sizeof(WNDCLASSEX));
    ZeroMemory(&msg, sizeof(MSG));

    wndEx.cbClsExtra = 0;
    wndEx.cbSize = sizeof(WNDCLASSEX);
    wndEx.cbWndExtra = 0;
    wndEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndEx.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndEx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndEx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wndEx.hInstance = hInstance;
    wndEx.lpfnWndProc = WndProc;
    wndEx.lpszClassName = szClassName;
    wndEx.lpszMenuName = NULL;
    wndEx.style = CS_HREDRAW | CS_VREDRAW;

    ATOM bRet = RegisterClassEx(&wndEx);
    assert(bRet);

    HWND hWnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, szAppName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 
    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

    ShowWindow(hWnd, nShowCmd);
    UpdateWindow(hWnd);

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_CREATE:
            MessageBox(NULL, TEXT("Window is just created"), TEXT("WINDOW CREATE"), MB_OK);
            break;

        case WM_RBUTTONDOWN:
            MessageBox(NULL, TEXT("You just clicked right mouse button"), TEXT("Mouse Action"), MB_OK);
            break;

        case WM_LBUTTONDOWN:
            MessageBox(NULL, TEXT("You just clicked left mouse button"), TEXT("Mouse Action"), MB_OK);
            break;

        case WM_KEYDOWN:
            MessageBox(NULL, TEXT("You just pressed a keyboard key"), TEXT("KEYBOARD ACTION"), MB_OK);
            break;

        case WM_SIZE:
            MessageBox(NULL, TEXT("You just resized the window"), TEXT("WINDOW RESIZE"), MB_OK);
            break;

        case WM_MOVE:
            MessageBox(NULL, TEXT("Window is moved"), TEXT("WINDOW MOVE"), MB_OK);
            break;
        
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
