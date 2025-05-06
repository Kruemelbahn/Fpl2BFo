#pragma once

#include <afxwin.h>

#ifndef deletenull
  #define deletenull(ptr)     { if(ptr) { delete(ptr); ptr = NULL; }}
#endif
#ifndef releasenull
  #define releasenull(ptr)    { if(ptr) { ptr->Release(); ptr = NULL; }}
#endif

//=============================================================================
static CString ReplaceDecimalPoint_LOCAL(CString s)
{
  if (s.IsEmpty())
    return s;

  CString sForDPCheck;
  sForDPCheck.Format(_T("%1.1f"), 1.1);

  const TCHAR m_chDP(sForDPCheck[1]);												// DP soll
  const TCHAR m_ch(m_chDP == _T('.') ? _T(',') : _T('.'));  // DP zum Tauschen  

  const int i(s.Find(m_ch));
  if (i != -1)
    s.SetAt(i, m_chDP);
  return s;
}

//=============================================================================
static CString GetHResultAsString(long hResult)
{
	CString sHResultAsString;
	switch (hResult)
	{
	  case S_OK:
		  sHResultAsString = _T("[0x00000000]: Funktionsaufruf erfolgreich.");
		  break;
	  case S_FALSE:
		  sHResultAsString = _T("[0x00000001]: Funktionsaufruf mit Fehler beendet.");
		  break;
	  case ERROR_FILE_NOT_FOUND:
		  sHResultAsString = _T("[0x00000002]: Datei nicht gefunden.");
		  break;
    case E_NOINTERFACE:
		  sHResultAsString = _T("[0x80004002]: Schnittstelle nicht verfügbar.");
		  break;
    case DISP_E_MEMBERNOTFOUND:
      sHResultAsString = _T("[0x80020003]: Funktion nicht gefunden.");
      break;
    case CLASS_E_CLASSNOTAVAILABLE:
	    sHResultAsString = _T("[0x80040111]: Funktion nicht verfügbar.");
	    break;
	  case CLASS_E_NOTLICENSED:
		  sHResultAsString = _T("[0x80040112]: Funktion nicht lizenziert.");
		  break;
    case REGDB_E_CLASSNOTREG:
      sHResultAsString = _T("[0x80040154]: CLSID nicht registriert.");
      break;
    case CO_E_APPNOTFOUND:
      sHResultAsString = _T("[0x800401F5]: COM-Server-EXE nicht gefunden");
      break;
    case CO_E_DLLNOTFOUND:
      sHResultAsString = _T("[0x800401F8]: COM-Server-DLL nicht gefunden");
      break;
    case CO_E_ERRORINDLL:
      sHResultAsString = _T("[0x800401F9]: Fehler in COM-Server-Datei");
      break;
    case CO_E_APPDIDNTREG:
      sHResultAsString = _T("[0x800401FE]: Server gestartet, hat sich aber nicht registriert!");
      break;
    case E_ACCESSDENIED:
      sHResultAsString = _T("[0x80070005]: Zugriffsfehler");
      break;
    case E_OUTOFMEMORY:
      sHResultAsString = _T("[0x8007000E]: Kein Speicherplatz verfügbar.");
      break;
    default:
		  sHResultAsString.Format(_T("[0x%08X]: unbekannter Fehlercode."), hResult);
		  break;
	}

	return sHResultAsString;
}
//=============================================================================
