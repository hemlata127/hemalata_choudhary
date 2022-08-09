/*
Display tables of 1 to 10 on the window
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
    static TCHAR szClassName[] = TEXT("MyClass");
    static TCHAR szAppName[] = TEXT("TABLES FROM 1 to 20");

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
    static char buffer[BUFFER_SIZE];
    PAINTSTRUCT ps;
    HDC hdc;
    switch(uMsg)
    {
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            int i, j;
            for(i = 1;i<=10;i++)
            {
                for(j = 1;j<=10;j++)
                {
                    ZeroMemory(buffer, BUFFER_SIZE);
                    sprintf(buffer, "%d * %d = %d",i, j, i*j);
                    TextOut(hdc, 100*(i-1), (j*20), buffer, BUFFER_SIZE);
                }
            }
            for(i = 11;i<=20;i++)
            {
                for(j = 1;j<=10;j++)
                {
                    ZeroMemory(buffer, BUFFER_SIZE);
                    sprintf(buffer, "%d * %d = %d",i, j, i*j);
                    TextOut(hdc, 100*(i-11), (j*20)+220, buffer, BUFFER_SIZE);
                }
            }
            EndPaint(hWnd, &ps);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
