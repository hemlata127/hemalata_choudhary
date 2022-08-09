#include<Windows.h>
#include<assert.h>

#define NUMBER_TEXT_BOX 1
#define BUTTON_FACTORIAL 2


#pragma comment(lib,"kernel32.lib")
#pragma comment(lib,"user32.lib")
#pragma comment(lib,"gdi32.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND hWnd, TextBox, Button1, TextField;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nShowCmd)
{
    static TCHAR szAppName[] = TEXT("Fun with numbers");
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

    hWnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, szAppName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 
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
    PAINTSTRUCT ps;
    HDC hdc;
    char* Label = "Please enter a number";
    char* Text1 = "Please select one of the following options";

    switch(uMsg)
    {
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            TextOut(hdc, 20, 20, Label, 22);
            TextOut(hdc, 20, 50, Text1, 43);
            EndPaint(hWnd, &ps);
            break;

        case WM_CREATE:
            TextBox = CreateWindow("EDIT", "", WS_BORDER | WS_CHILD | WS_VISIBLE, 
            200, 20, 100, 20, hWnd, (HMENU) NUMBER_TEXT_BOX, NULL, NULL);

            Button1 = CreateWindow("button", "Factorial", WS_BORDER | WS_CHILD | WS_VISIBLE, 
            20, 80, 100, 20, hWnd, (HMENU) BUTTON_FACTORIAL, NULL, NULL);

            break;

        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case NUMBER_TEXT_BOX:
                    int num = GetDlgItemInt(hWnd, TextBox, TRUE, TRUE);
                    char buffer[50];
                    sprintf("Entered number is: %d\n",atoi(num));
                    MessageBox(hWnd, buffer, "ENTERED TEXT", MB_OK);
                    break;
                    
                case BUTTON_FACTORIAL:
                    MessageBox(hWnd, "Factorial of the number", "Factorial", MB_OK);
                    break;

            }
            break;
        

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
