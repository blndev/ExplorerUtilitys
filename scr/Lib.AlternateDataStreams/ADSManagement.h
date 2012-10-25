#include <Windows.h>
#include <vector>
#include <tchar.h>

#ifdef _DEBUG
#  define WriteDebug(str) OutputDebugStringW(str)
#else
#  define WriteDebug(str) void(0)
#endif 

using namespace std;
struct ADSInfo
{
	wstring Name;
	long Size;
};

vector<ADSInfo> getAlternateDataStreams(LPCWSTR  path);

