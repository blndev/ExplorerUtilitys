========================================================================
    AKTIVE VORLAGENBIBLIOTHEK: DLL.ExplorerUtilitys-Projektübersicht
========================================================================

Der Anwendungs-Assistent hat dieses DLL.ExplorerUtilitys-Projekt als Ausgangspunkt zum Schreiben der DLL (Dynamic Link Library) erstellt.

Diese Datei bietet eine Übersicht über den Inhalt der einzelnen Dateien, aus denen Ihr Projekt besteht.

DLL.ExplorerUtilitys.vcxproj
    Dies ist die Hauptprojektdatei für VC++-Projekte, die mit dem Anwendungs-Assistenten generiert werden. Sie enthält Informationen über die Version von Visual C++, mit der die Datei generiert wurde, sowie über die Plattformen, Konfigurationen und Projektfunktionen, die im Anwendungs-Assistenten ausgewählt wurden.

DLL.ExplorerUtilitys.vcxproj.filters
    Dies ist die Filterdatei für VC++-Projekte, die mithilfe eines Anwendungs-Assistenten erstellt werden. Sie enthält Informationen über die Zuordnung zwischen den Dateien im Projekt und den Filtern. Diese Zuordnung wird in der IDE zur Darstellung der Gruppierung von Dateien mit ähnlichen Erweiterungen unter einem bestimmten Knoten verwendet (z. B. sind CPP-Dateien dem Filter "Quelldateien" zugeordnet).

DLLExplorerUtilitys.idl
    Diese Datei enthält die IDL-Definitionen der Typbibliothek, Schnittstellen und Co-Klassen, die im Projekt definiert sind.
    Diese Datei wird vom MIDL-Compiler verarbeitet, um Folgendes zu generieren:
        C++-Schnittstellendefinitionen und GUID-Deklarationen (DLLExplorerUtilitys.h)
        GUID-Definitionen                                (DLLExplorerUtilitys_i.c)
        Eine Typbibliothek                                  (DLLExplorerUtilitys.tlb)
        Marshallingcode                                 (DLLExplorerUtilitys_p.c und dlldata.c)

DLLExplorerUtilitys.h
    Diese Datei enthält die C++-Schnittstellendefinitionen und GUID-Deklarationen der in DLLExplorerUtilitys.idl definierten Elemente. Sie wird von MIDL während der Kompilierung erneut generiert.

DLL.ExplorerUtilitys.cpp
    Diese Datei enthält die Objekttabelle und die Implementierung der DLL-Exporte.

DLL.ExplorerUtilitys.rc
    Dies ist eine Auflistung aller vom Programm verwendeten Microsoft Windows-Ressourcen.

DLL.ExplorerUtilitys.def
    Diese Moduldefinitionsdatei stellt dem Linker die für die DLL erforderlichen Informationen über die Exporte bereit. Sie enthält Exporte für:
        DllGetClassObject
        DllCanUnloadNow
        DllRegisterServer
        DllUnregisterServer
        DllInstall

/////////////////////////////////////////////////////////////////////////////
Andere Standarddateien:

StdAfx.h, StdAfx.cpp
    Mit diesen Dateien werden eine vorkompilierte Headerdatei (PCH) mit dem Namen DLL.ExplorerUtilitys.pch und eine vorkompilierte Typendatei mit dem Namen StdAfx.obj erstellt.

Resource.h
    Dies ist die Standardheaderdatei, die Ressourcen-IDs definiert.

/////////////////////////////////////////////////////////////////////////////
Proxy/Stub-DLL-Projekt und Moduldefinitionsdatei:

DLL.ExplorerUtilitysps.vcxproj
    Dies ist die Projektdatei zum Erstellen einer Proxy/Stub-DLL.
	Die IDL-Datei im Hauptprojekt muss mindestens eine Schnittstelle enthalten. Die IDL-Datei muss vor dem Erstellen der Proxy/Stub-DLL kompiliert werden.
	Dieser Prozess erstellt dlldata.c, DLLExplorerUtilitys_i.c und DLLExplorerUtilitys_p.c. Diese sind zum Erstellen der Proxy/Stub-DLL erforderlich.

DLL.ExplorerUtilitysps.vcxproj.filters
    Dies ist die Filterdatei für das Proxy-/Stubprojekt. Sie enthält Informationen über die Zuordnung zwischen den Dateien im Projekt und den Filtern. Diese Zuordnung wird in der IDE zur Darstellung der Gruppierung von Dateien mit ähnlichen Erweiterungen unter einem bestimmten Knoten verwendet (z. B. sind CPP-Dateien dem Filter "Quelldateien" zugeordnet).

DLL.ExplorerUtilitysps.def
    Diese Moduldefinitionsdatei stellt dem Linker die für den Proxy/Stub erforderlichen Informationen über die Exporte bereit.

/////////////////////////////////////////////////////////////////////////////
