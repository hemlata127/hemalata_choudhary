/*
Capture window resize event. Display current window size on right mouse click
*/

#include<Windows.h>
#include<assert.h>
#include<stdio.h>

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nShowCmd)
{
    static TCHAR szAppName[] = TEXT("Capture Window Resize Event");
    static TCHAR szClassName[] = TEXT("MyClass");

    WNDCLASSEX wndEx;
    MSG msg;

    ZeroMemory(&wndEx, sizeof(WNDCLASSEX));
    ZeroMemory(&msg, sizeof(MSG));

    wndEx.cbClsExtra = 0;
    wndEx.cbSize = sizeof(WNDCLASSEX);
    wndEx.cbWndExtra = 0;
    wndEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndEx.hCursor = LoadCursor(NULL, IDC_HAND);
    wndEx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndEx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wndEx.hInstance = hInstance;
    wndEx.lpfnWndProc = WndProc;
    wndEx.lpszClassName = szClassName;
    wndEx.lpszMenuName = NULL;
    wndEx.style = CS_VREDRAW | CS_HREDRAW;

    ATOM bRet = RegisterClassEx(&wndEx);
    assert(bRet);

    HWND hWnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, szAppName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 
    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
    assert(hWnd);

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
    #define BUFFER_SIZE 100
    static int cxScreen;
    static int cyScreen;
    static char buffer[BUFFER_SIZE];

    switch(uMsg)
    {
        case WM_SIZE:
            cxScreen = LOWORD(lParam);
            cyScreen = HIWORD(lParam);
            ZeroMemory(buffer, BUFFER_SIZE);
            sprintf(buffer, "Width = %d\nHeight = %d",cxScreen, cyScreen);
            break;

        case WM_RBUTTONDOWN:
            MessageBox(NULL, TEXT(buffer), TEXT("Current window size"), MB_OK);
            break;
        
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
