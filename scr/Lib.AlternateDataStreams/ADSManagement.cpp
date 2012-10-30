#include "ADSManagement.h"
#include <Windows.h>
#include <tchar.h>
#include <string>

#include <strsafe.h>	//to display error (StringCchPrintf)

#ifdef _DEBUG
void HandleError(LPTSTR lpszFunction) 
{ 
	// Retrieve the system error message for the last-error code
	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = GetLastError(); 

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0, NULL );

	// Display the error message and exit the process
	lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT, (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR)); 
	StringCchPrintf((LPTSTR)lpDisplayBuf,  LocalSize(lpDisplayBuf) / sizeof(TCHAR),  TEXT("%s failed with error %d\n\n%s"), lpszFunction, dw, lpMsgBuf); 
	WriteDebug((LPCTSTR)lpDisplayBuf);
	MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK); 

	LocalFree(lpMsgBuf);
	LocalFree(lpDisplayBuf);
	//ExitProcess(dw); 
}
#else
void HandleError(LPTSTR lpszFunction) { }
#endif

vector<ADSInfo> getAlternateDataStreams(LPCWSTR  path)
{
	vector<ADSInfo> ret; 

	WIN32_FIND_STREAM_DATA fsd;
	HANDLE result = FindFirstStreamW(path,FindStreamInfoStandard, &fsd,0);
	if(result==INVALID_HANDLE_VALUE)
	{
		HandleError(TEXT("find streams"));
		//LPTSTR err; DWORD errv = GetLastError(); 
		return ret;
	}
	do 
	{
		WriteDebug(fsd.cStreamName);

		//we have to check and remove the ads type. see http://msdn.microsoft.com/en-us/library/windows/desktop/aa364404%28v=vs.85%29.aspx
		//::$DATA
		if(wcscmp(fsd.cStreamName,L"::$DATA")!=0)
		{
			ADSInfo info;
			info.Name = fsd.cStreamName;
			info.Size=fsd.StreamSize.LowPart;
			info.Name.replace(info.Name.find(L":$DATA"),6 , L"");
			info.Name = info.Name.substr(1, info.Name.length()-1); //remove the first ":"
			ret.push_back(info);
		}
	}
	while(FindNextStreamW (result, &fsd));
	return ret;
}