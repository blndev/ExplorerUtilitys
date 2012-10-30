// Test.Shell.Libs.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include "../Lib.AlternateDataStreams/ADSManagement.h";

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "please enter the path to check:" << endl;
	TCHAR buffer[_MAX_PATH];
	wcin  >> buffer;
	vector<ADSInfo> ads = getAlternateDataStreams(buffer);

	cout << endl << "any key for exit"<< endl;
	getch();
	return 0;
}

