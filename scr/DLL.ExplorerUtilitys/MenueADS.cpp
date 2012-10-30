
#include "stdafx.h"
#include "MenueADS.h"
//#include <atlconv.h>
#include <vector>

// CMenueADS

#define IDM_DISPLAY             0  // The command's identifier offset
//declared in dllmain 
//used to access resources very easy 
extern HINSTANCE g_hInst;

HRESULT CMenueADS::Initialize
	(
	LPCITEMIDLIST   pidlFolder,	//itemlist http://msdn.microsoft.com/en-us/library/windows/desktop/bb775094%28v=vs.85%29.aspx
	LPDATAOBJECT    pDataObj,	//the main data container
	HKEY            hProgID 	//regkey for filetype or folder key
	)
{
	HRESULT hr = E_INVALIDARG;
	if (NULL == pDataObj)
		return E_INVALIDARG;

	FORMATETC fmt = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
	STGMEDIUM stg = { TYMED_HGLOBAL };

	HDROP hDrop;

	//Look for CF_HDROP
	if (FAILED (pDataObj->GetData (&fmt, &stg)))
		return E_INVALIDARG; //alternate: if (SUCCEEDED(pDataObj->GetData(&fe, &stm)))

	//try to read data
	hDrop = (HDROP) GlobalLock ( stg.hGlobal );
	if (NULL == hDrop)
		return E_INVALIDARG;

	//make sure there is at least one filename.
	UINT uNumFiles = DragQueryFile (hDrop, 0xFFFFFFFF, NULL, 0);
	//we just work with one selected item because we did not like to check different states
	if (uNumFiles == 1) 
	{
		//so, here we have one file selected
		for (UINT filecount = 0; filecount < uNumFiles; filecount++)
		{
			if (DragQueryFile (hDrop, filecount, m_szFile, MAX_PATH) != 0)
			{
				//DebugWrite (_T ("selected file %s"), m_szFile);
				//TODO: Save vector;
				adsinfos = getAlternateDataStreams(m_szFile);
				if(adsinfos.size()>0)
				{
					hr = S_OK;
				}
				else
				{
					//no stream, no menu
					hr = E_FAIL;
				}
			}//end if filename found
			else
			{
				hr = E_FAIL;
			}
			break;//currently we use only one file
		}//for files in filecount
	}//end if numFiles==1
	GlobalUnlock (stg.hGlobal);
	ReleaseStgMedium (&stg);
	return hr;
}

HRESULT CMenueADS::QueryContextMenu (
	HMENU   hmenu,		//handle to menu
	UINT    uMenuIndex,	//position to add menu entrys
	UINT    uidFirstCmd,	//min menue id we can use
	UINT    uidLastCmd,	//max menu id we can use
	UINT    uFlags
	)		//flags which give some context informations
{
	//create menu entry
	//If the flags include CMF_DEFAULTONLY then we shouldn't do anything.
	if ( uFlags & CMF_DEFAULTONLY )
		return MAKE_HRESULT (SEVERITY_SUCCESS, FACILITY_NULL, 0);

	//http://msdn.microsoft.com/query/dev10.query?appId=Dev10IDEF1&l=EN-US&k=k%28%22WINUSER%2fINSERTMENU%22%29;k%28INSERTMENU%29;k%28DevLang-%22C%2B%2B%22%29;k%28TargetOS-WINDOWS%29&rd=true
	UINT id = uidFirstCmd;

	//add a separator.
	//InsertMenu (hmenu, uMenuIndex, MF_BYPOSITION | MFT_SEPARATOR, uidFirstCmd, L"");

	HMENU hSubmenu = CreateMenu ();
	UINT subMenuIndex=uMenuIndex;
	int mcount=0;
	//insert menus 
	for(vector<ADSInfo>::iterator it = adsinfos.begin(); it < adsinfos.end(); ++it)  
	{  
		ADSInfo ads = *it;  
		wchar_t streamname[MAX_PATH + 32];
		if(ads.Size>1024*1024)
			wsprintf (streamname, L"%s (%d MB)", ads.Name.c_str(), ads.Size/1024/1024);
		else if(ads.Size>1024)
			wsprintf (streamname, L"%s (%d kB)", ads.Name.c_str(), ads.Size/1024);
		else
			wsprintf (streamname, L"%s (%d Byte)", ads.Name.c_str(), ads.Size);
		InsertMenu (hSubmenu, subMenuIndex, MF_BYPOSITION, uidFirstCmd + mcount, streamname);
		mcount++;
		subMenuIndex++;
	}


	//MainMenu
	InsertMenu (hmenu, uMenuIndex + 1, MF_BYPOSITION | MF_POPUP, UINT (hSubmenu), L"Streams");
	//add a separator.
	//InsertMenu (hmenu, uMenuIndex + 2, MF_BYPOSITION | MFT_SEPARATOR, uidFirstCmd + 1, L"");

	return MAKE_HRESULT (SEVERITY_SUCCESS, FACILITY_NULL, uMenuIndex +1/*mainmenu + separators*/ +subMenuIndex +mcount);
}


HRESULT CMenueADS::InvokeCommand
	(
	LPCMINVOKECOMMANDINFO pCmdInfo
	)
{
	// If lpVerb really points to a string, ignore this function call and bail out.
	if (HIWORD ( pCmdInfo->lpVerb ) != 0)
		return E_INVALIDARG;
	//DebugWrite("callback from explorer for menu action");
	//we identify the clicked menu by the index of the adsvector
	UINT vectorpos = (LOWORD(pCmdInfo->lpVerb));
	if(adsinfos.size()-1>=vectorpos)
	{
		wchar_t szCmd[1024];
		wsprintf (szCmd, L"%ls:%ls",m_szFile, adsinfos.at(vectorpos).Name.c_str());
		MessageBox (
			pCmdInfo->hwnd,
			szCmd,
			L"Streams",
			MB_ICONINFORMATION );
		return S_OK;
	}
	else
	{

		TCHAR szMsg[MAX_PATH + 32];
		wsprintf ( szMsg, _T ("wrong callback id \nthe selected file was:\n\n%s"),	m_szFile );
		MessageBox (
			pCmdInfo->hwnd,
			szMsg,
			L"Streams",
			MB_ICONINFORMATION );

		return S_OK;
	}
	return E_FAIL;
}



HRESULT CMenueADS::GetCommandString
	(
	UINT_PTR    idCmd,
	UINT        uFlags,
	UINT        *pwReserved,
	LPSTR       pszName,
	UINT        cchMax
	)
{
	USES_CONVERSION;

	// If Explorer is asking for a help string, copy our string into the buffer.
	if ( uFlags & GCS_HELPTEXT )
	{
		LPCTSTR szText = _T ("not supported");
		if ( uFlags & GCS_UNICODE )
		{
			// We need to cast pszName to a Unicode string, and then use the
			// Unicode string copy API.
			lstrcpynW ( (LPWSTR) pszName, T2CW (szText), cchMax );
		}
		else
		{
			// Use the ANSI string copy API to return the help string.
			lstrcpynA ( pszName, T2CA (szText), cchMax );
		}
		return S_OK;
	}

	if ( uFlags & GCS_VALIDATE )
	{
		return S_OK;
	}
	return S_OK;
	return E_INVALIDARG;
}