#include "stdafx.h"
#include "Win32TextboxDialog.h"


Win32TextboxDialog::Win32TextboxDialog(void)
{
}


Win32TextboxDialog::~Win32TextboxDialog(void)
{
}

void Win32TextboxDialog::Show(LPCTSTR message)
{
	MessageBox(NULL, message, TEXT("Show - Dialog"), MB_ICONERROR);
/*	HWND hWnd;
  //http://www.winprog.org/tutorial/simple_window.html
  if (!(hWnd = CreateWindow(windowClass, windowTitle, WS_OVERLAPPEDWINDOW,
                            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                            CW_USEDEFAULT, NULL, NULL, hInstance, NULL)))
  {
    MessageBox(NULL, TEXT("CreateWindow Failed!"), TEXT("Error"), MB_ICONERROR);
    //return EXIT_FAILURE;
  }

  HWND hWndEdit = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("test"),
                               WS_CHILD | WS_VISIBLE, 100, 20, 140,
                               20, hWnd, NULL, NULL, NULL);

  ShowWindow(hWnd, nCmdShow);
  UpdateWindow(hWnd);

  MSG msg;

  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  //return EXIT_SUCCESS;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  switch (msg)
  {
  case WM_DESTROY:
    PostQuitMessage(EXIT_SUCCESS);
  default:
    return DefWindowProc(hWnd, msg, wParam, lParam);
  }
  return FALSE;
}*/
}

