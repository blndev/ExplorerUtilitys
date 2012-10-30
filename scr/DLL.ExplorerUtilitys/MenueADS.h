/*
this is the definition of the menu for alternate data streams
*/

#pragma once
#include "resource.h"       
#include <shlobj.h>
#include <comdef.h>
#include "../Lib.AlternateDataStreams/ADSManagement.h"

#include "DLLExplorerUtilitys_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Singlethread-COM-Objekte werden auf der Windows CE-Plattform nicht vollständig unterstützt. Windows Mobile-Plattformen bieten beispielsweise keine vollständige DCOM-Unterstützung. Definieren Sie _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA, um ATL zu zwingen, die Erstellung von Singlethread-COM-Objekten zu unterstützen und die Verwendung eigener Singlethread-COM-Objektimplementierungen zu erlauben. Das Threadmodell in der RGS-Datei wurde auf 'Free' festgelegt, da dies das einzige Threadmodell ist, das auf Windows CE-Plattformen ohne DCOM unterstützt wird."
#endif

using namespace ATL;


// CMenueADS

class ATL_NO_VTABLE CMenueADS :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMenueADS, &CLSID_MenueADS>,
	public IDispatchImpl<IMenueADS, &IID_IMenueADS, &LIBID_DLLExplorerUtilitysLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IShellExtInit,
	public IContextMenu

{
public:
	CMenueADS()
	{
	}

protected:
	//we have to save the filename to read the content after click
	WCHAR m_szFile[MAX_PATH];
	//here we save the stream infos
	vector<ADSInfo> adsinfos;
public:
	// IShellExtInit
	STDMETHODIMP Initialize(LPCITEMIDLIST, LPDATAOBJECT, HKEY);

	// IContextMenu
	STDMETHODIMP GetCommandString(UINT_PTR, UINT, UINT*, LPSTR, UINT);
	STDMETHODIMP InvokeCommand(LPCMINVOKECOMMANDINFO);
	STDMETHODIMP QueryContextMenu(HMENU, UINT, UINT, UINT, UINT);

	DECLARE_REGISTRY_RESOURCEID(IDR_MENUEADS)


	BEGIN_COM_MAP(CMenueADS)
		COM_INTERFACE_ENTRY(IMenueADS)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IShellExtInit)
		COM_INTERFACE_ENTRY(IContextMenu)
	END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

};

OBJECT_ENTRY_AUTO(__uuidof(MenueADS), CMenueADS)
