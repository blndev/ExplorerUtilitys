// dllmain.h : Deklaration der Modulklasse.

class CDLLExplorerUtilitysModule : public ATL::CAtlDllModuleT< CDLLExplorerUtilitysModule >
{
public :
	DECLARE_LIBID(LIBID_DLLExplorerUtilitysLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DLLEXPLORERUTILITYS, "{E8C66708-AD3A-4919-8CDD-9375DFC9821F}")
};

extern class CDLLExplorerUtilitysModule _AtlModule;
