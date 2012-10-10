// Test.Shell.Libs.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include "../Lib.AlternateDataStreams/ADSManagement.h";

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	HalloWelt();
	cout << "any key for exit"<< endl;
	getch();
	return 0;
}

