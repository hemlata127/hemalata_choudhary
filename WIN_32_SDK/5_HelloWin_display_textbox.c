/*
Display text box and labels besides the text box
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
    static TCHAR szAppName[] = TEXT("TEXT BOX DISPLAY");
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
    assert(hWnd);

    HWND hWndText1 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT(""), WS_CHILD | WS_VISIBLE, 
    100, 20, 100, 25, hWnd, NULL, NULL, NULL);

    HWND hWndText2 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT(""), WS_CHILD | WS_VISIBLE, 
    100, 60, 100, 25, hWnd, NULL, NULL, NULL);

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
    #define BUFFER_SIZE 50
    PAINTSTRUCT ps;
    HDC hdc;
    static char buffer[BUFFER_SIZE];
    switch(uMsg)
    {
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            ZeroMemory(buffer, BUFFER_SIZE);
            sprintf(buffer, "First Name");
            TextOut(hdc, 10, 20, buffer, BUFFER_SIZE);
            ZeroMemory(buffer, BUFFER_SIZE);
            sprintf(buffer, "Last Name");
            TextOut(hdc, 10, 60, buffer, BUFFER_SIZE);
            EndPaint(hWnd, &ps);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
