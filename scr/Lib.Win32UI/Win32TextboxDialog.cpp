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
}

