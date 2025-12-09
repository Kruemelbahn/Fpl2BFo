#pragma once

#include <afxwin.h>
#include "UtilParserDefines.h"

//=============================================================================
// generelle Informationen aus dem Dateikopf 'jTrainGraph_timetable'
// filled from FPL, BFO or STA-File
struct _FPL_FILEINFO
{
  CString file;     // Datei
  CString info;     // Dateibeschreibung
  CString version;  // FPL-Dateiversion
  CString d;        // Verkehrstage
  CString tMin;     // Zeit Fahrplanstart
  CString tMax;     // Zeit Fahrplanende
  CString sFont;
  CString trFont;
  CString hFont;
  CString tFont;

  // nicht aus der fpl-Datei:
  INT_PTR iStationCount { 0 };
  INT_PTR iTrainCount { 0 };
  INT_PTR iPointOnTrackCount { 0 };
  CString fplfile;    // FPL-Datei
  CString bfofile;    // BFO-Datei
  CString stafile;    // STA-Datei
  CString staVersion; // STA-Dateiversion
  CString trackplan;  // Gleisplandatei
  BOOL printData { FALSE };

  // alles löschen:
  void clear(const BOOL bAll) noexcept {
    file.Empty(); info.Empty(); version.Empty(); d.Empty(); tMin.Empty(); tMax.Empty(); fplfile.Empty();
    sFont.Empty(); trFont.Empty(); hFont.Empty(); tFont.Empty();
    iStationCount = iTrainCount = iPointOnTrackCount = 0;
    if (bAll) { bfofile.Empty(); trackplan.Empty(); stafile.Empty(); staVersion.Empty(); }
  }
};

//=============================================================================
// alle Angaben zu einer Station
struct _FPL_ONE_STATION
{
  CString name;     // Stationsname
  int fpl_id { 0 };
  CString fpl_cd;   // Betriebsstellenkürzel
  CString fpl_tp;   // Betriebsstellentyp
  CString fpl_vmax; // Höchstgeschwindigkeit
  CString fpl_wl;   // Wellenlinien
  CString fpl_rt;   // Streckennummer
  CString fpl_rq;   // Bedarfshaltepunkt
  CString fpl_pos;  // Punkt für die grafische Darstellung in FPLEdit
  CString kml;
  CString kmr;
  CString dTi;
  CString dTa;
  CStringArray *pTracklist { NULL };

  // nicht in der fpl-Datei enthalten, wird durch kml oder kmr gesetzt
  CString km;

  // alles löschen:
  void clear() noexcept {
    name.Empty(); fpl_cd.Empty(); fpl_tp.Empty(); fpl_vmax.Empty(); fpl_wl.Empty(); fpl_rt.Empty(); fpl_rq.Empty(); fpl_pos.Empty();
    km.Empty(); kml.Empty(); kmr.Empty(); dTi.Empty(); dTa.Empty();
    fpl_id = -1;
    pTracklist = NULL;
  }
};

// filled from FPL-File
class CFPLStationArray final : public CArray <_FPL_ONE_STATION, _FPL_ONE_STATION&>
{
public:
  CFPLStationArray() {};
  virtual ~CFPLStationArray() { RemoveAll(); };
  virtual void RemoveAll()
  {
    for (INT_PTR i = 0; i < GetCount(); i++)
    {
      _FPL_ONE_STATION oOneStation(GetAt(i));
      if (oOneStation.pTracklist)
      {
        (oOneStation.pTracklist)->RemoveAll();
        deletenull (oOneStation.pTracklist)
      } // if (oOneStation.pTracklist)
    } // for (INT_PTR i = 0; i < GetCount(); i++)
    CArray<_FPL_ONE_STATION, _FPL_ONE_STATION&>::RemoveAll();
  } // virtual void RemoveAll()
  INT_PTR FindStationIndexById(const int iStationIdToFind) const
  {
    if (iStationIdToFind < 0)
      return -1;

    // if not found return -1 else position within array
    INT_PTR i(0);
    while (i < CArray<_FPL_ONE_STATION, _FPL_ONE_STATION&>::GetCount())
    {
      const _FPL_ONE_STATION oOneStation(CArray<_FPL_ONE_STATION, _FPL_ONE_STATION&>::GetAt(i));
      if (iStationIdToFind == oOneStation.fpl_id)
        return i;
      i++;
    }
    return -1;
  } // INT_PTR FindStationIndexById(const int iStationIdToFind) const
};

//=============================================================================
// alle Angaben zu einem Punkt (keine Bahnhof, Abzweig, Anst., AwAnst. o.ä.) auf der Strecke
struct _FPL_ONE_POINT_ON_TRACK
{
  CString name;       // Streckenpunktname
  CString kml;
  CString kmr;
  CString fpl_rt;     // Streckennummer
  CString fpl_vmax;   // Höchstgeschwindigkeit
  CString fpl_wl;     // Wellenlinien
  CString fpl_dir;    // definiert, in welche Streckenrichtung die Geschwindigkeitsbegrenzung gilt
  CString fpl_cd;     // Streckenpunktkürzel
  CString fpl_tp;     // Streckenpunkttyp

  // nicht in der fpl-Datei enthalten, wird durch kml oder kmr gesetzt
  CString km;

  // alles löschen:
  void clear() noexcept {
    name.Empty(); fpl_cd.Empty(); fpl_tp.Empty(); fpl_vmax.Empty(); fpl_rt.Empty(); km.Empty(); kml.Empty();
    kmr.Empty(); fpl_wl.Empty(); fpl_dir.Empty();
  }
};

// filled from FPL-File
// contains all additional trackpoints from <bfpl_attrs>
// button 'Vmax' leads to 'Change maximum velocities'
// and buttons 'Add Vmax change' resp. 'Delete Vmax change' will add/remove speed-change-points
class CFPLPointOnTrackArray final : public CArray <_FPL_ONE_POINT_ON_TRACK, _FPL_ONE_POINT_ON_TRACK&>
{
public:
  CFPLPointOnTrackArray() {};
  virtual ~CFPLPointOnTrackArray() { RemoveAll(); };
  virtual void RemoveAll() { CArray<_FPL_ONE_POINT_ON_TRACK, _FPL_ONE_POINT_ON_TRACK&>::RemoveAll(); };
  INT_PTR AddUniqueSortedByKm(_FPL_ONE_POINT_ON_TRACK oNewPointOnTrack, BOOL& bFound)
  {
    bFound = FALSE;
    const INT_PTR n(GetSize() - 1);
    if (n == -1)
      // erstes Element : einfach anhängen
      return CArray<_FPL_ONE_POINT_ON_TRACK, _FPL_ONE_POINT_ON_TRACK&>::Add(oNewPointOnTrack);
    
    // Element schon vorhanden?
    INT_PTR iSearch(0);
    while (iSearch < GetSize())
    {
      if (!oNewPointOnTrack.km.CompareNoCase(CArray<_FPL_ONE_POINT_ON_TRACK, _FPL_ONE_POINT_ON_TRACK&>::GetAt(iSearch).km))
      {
        bFound = TRUE;
        return iSearch;
      }
      iSearch++;
    }
    
    // nicht gefunden : (sortiert) einfügen

    // wird das Element am Ende eingefügt ?
    double dNewStation(0.0);
    try { dNewStation = atof(ReplaceDecimalPoint_LOCAL(oNewPointOnTrack.km)); }
    catch (...) {}
    _FPL_ONE_POINT_ON_TRACK oInnerStation(CArray<_FPL_ONE_POINT_ON_TRACK, _FPL_ONE_POINT_ON_TRACK&>::GetAt(n));
    double dInnerStation(0.0);
    try { dInnerStation = atof(ReplaceDecimalPoint_LOCAL(oInnerStation.km)); }
    catch (...) {}
    if (_dpcomp(dNewStation, dInnerStation) == _FP_GT)
      return CArray<_FPL_ONE_POINT_ON_TRACK, _FPL_ONE_POINT_ON_TRACK&>::Add(oNewPointOnTrack);

    // nein : Position suchen
    INT_PTR iLast(n);
    while (iLast >= 0)
    {
      oInnerStation = CArray<_FPL_ONE_POINT_ON_TRACK, _FPL_ONE_POINT_ON_TRACK&>::GetAt(iLast);
      dInnerStation = 0.0;
      try { dInnerStation = atof(ReplaceDecimalPoint_LOCAL(oInnerStation.km)); }
      catch (...) {}
      if (_dpcomp(dNewStation, dInnerStation) == _FP_GT)
      {
        CArray<_FPL_ONE_POINT_ON_TRACK, _FPL_ONE_POINT_ON_TRACK&>::InsertAt(iLast + 1, oNewPointOnTrack);
        return iLast + 1;
      }
      iLast--;
    } // while (iLast >= 0)
    
    // nicht gefunden, dann wird das Neue zum ersten Element
    CArray<_FPL_ONE_POINT_ON_TRACK, _FPL_ONE_POINT_ON_TRACK&>::InsertAt(0, oNewPointOnTrack);
    return 0;
  } // INT_PTR AddUniqueSorted(_FPL_ONE_POINT_ON_TRACK oNewPointOnTrack, BOOL& bFound)
};

struct _FPL_MOVE_FOR_ONE_TRAIN
{
  // Rangierbewegung
  CString ti;   // Zeit
  CString so;   // Startgleis
  CString ta;   // Zielgleis
  CString ea;   // alle Wagen (Gleis ist anschließend leer)

  // alles löschen:
  void clear() noexcept {
    ti.Empty(); ta.Empty(); so.Empty(); ea.Empty();
  }
};

// filled from FPL-File
// contains all switch-instructions for one train from <shmove>
class CFPLMoveForOneTrainArray final : public CArray <_FPL_MOVE_FOR_ONE_TRAIN, _FPL_MOVE_FOR_ONE_TRAIN&>
{
public:
  CFPLMoveForOneTrainArray() {};
  virtual ~CFPLMoveForOneTrainArray() { RemoveAll(); };
  virtual void RemoveAll() { CArray<_FPL_MOVE_FOR_ONE_TRAIN, _FPL_MOVE_FOR_ONE_TRAIN&>::RemoveAll(); }
};

//=============================================================================
// alle Zeitangaben zu einem Zug
struct _FPL_TIME_FOR_ONE_TRAIN
{
  int fpl_id { -1 };
  CString d;  // Abfahrtszeit
  CString dt; // Abfahrtsgleis
  CString a;  // Ankunftszeit
  CString at; // Ankunftsgleis
  
  CString fpl_tr;   // Halt vor Trapeztafel
  CString fpl_rq;   // Bedarfshalt, wird durch 'x' vor der Ankunftszeit gekennzeichnet
  CString fpl_zlm;  // Zuglaufmeldung durch ...

  CFPLMoveForOneTrainArray* pMovelist{ NULL };

  // alles löschen:
  void clear() noexcept {
    d.Empty(); dt.Empty(); a.Empty(); at.Empty(); fpl_tr.Empty(); fpl_rq.Empty(); fpl_zlm.Empty();
    fpl_id = -1;
    pMovelist = NULL;
  }
};

// filled from FPL-File
class CFPLTimeForOneTrainArray final : public CArray <_FPL_TIME_FOR_ONE_TRAIN, _FPL_TIME_FOR_ONE_TRAIN&>
{
public:
  CFPLTimeForOneTrainArray() {};
  virtual ~CFPLTimeForOneTrainArray() { RemoveAll(); };
  virtual void RemoveAll()
  {
    for (INT_PTR i = 0; i < GetCount(); i++)
    {
      _FPL_TIME_FOR_ONE_TRAIN oOneTime(GetAt(i));
      if (oOneTime.pMovelist)
      {
        (oOneTime.pMovelist)->RemoveAll();
        deletenull(oOneTime.pMovelist)
      } // if (oOneTime.pMovelist)
    } // for (INT_PTR i = 0; i < GetCount(); i++)
    CArray<_FPL_TIME_FOR_ONE_TRAIN, _FPL_TIME_FOR_ONE_TRAIN&>::RemoveAll();
  } // virtual void RemoveAll()
};

//=============================================================================
// alle Angaben zu einem Zug
struct _FPL_ONE_TRAIN
{
  CString name;     // Name das Zuges, Format aus der FPL-Datei: "<Typ> <Name>"
  CString d;        // Verkehrstage
  CString fpl_tfz;  // verwendetes Triebfahrzeug
  CString fpl_last; // Zuglast (in t)
  CString fpl_mbr;  // Mindestbremshundertstel
  CString cm;       // Kommentar
  int id { 0 };     // Zug-Id
  CString direction;   // 'ta', 'ti' oder 'tr' gibt die Fahrtrichtung des Zuges an <ti>='down', <ta>='up', <tr>=bei Netzfahrplänen
  CFPLTimeForOneTrainArray* pTrainTimeArray { NULL };

  // alles löschen:
  void clear() noexcept {
    name.Empty(); d.Empty(); fpl_tfz.Empty(); fpl_last.Empty(); fpl_mbr.Empty(); cm.Empty(); direction.Empty();
    id = 0;
    pTrainTimeArray = NULL;
  }
};

// filled from FPL-File
class CFPLTrainArray final : public CArray <_FPL_ONE_TRAIN, _FPL_ONE_TRAIN&>
{
public:
  CFPLTrainArray() {};
  virtual ~CFPLTrainArray() { RemoveAll(); };
  virtual void RemoveAll()
  {
    for (INT_PTR i = 0; i < GetCount(); i++)
    {
      _FPL_ONE_TRAIN oOneTrain(GetAt(i));
      if (oOneTrain.pTrainTimeArray)
      {
        (oOneTrain.pTrainTimeArray)->RemoveAll();
        deletenull(oOneTrain.pTrainTimeArray)
      }
    }
    CArray<_FPL_ONE_TRAIN, _FPL_ONE_TRAIN&>::RemoveAll();
  } // virtual void RemoveAll()
  void SortByName()
  {
    const INT_PTR n(GetCount());
    for (INT_PTR i = 0; i < n - 1; i++)
    {
      for (INT_PTR j = 0; j < n - i - 1; j++)
      {
        _FPL_ONE_TRAIN oInnerTrain(GetAt(j));
        _FPL_ONE_TRAIN oOuterTrain(GetAt(j + 1));
        if (oInnerTrain.name > oOuterTrain.name)
        {
          SetAt(j, oOuterTrain);
          SetAt(j + 1, oInnerTrain);
        } // if (oInnerTrain.name > oOuterTrain.name)
      } // for (INT_PTR j = 0; j < n - i - 1; j++)
    } // for (INT_PTR i = 0; i < n - 1; i++)
  } // void SortByName()
  INT_PTR FindTrainByName(const CString sTrainToFind) const
  {
    if (sTrainToFind.IsEmpty())
      return -1;

    // if not found return -1 else position within array
    INT_PTR i(0);
    while (i < CArray<_FPL_ONE_TRAIN, _FPL_ONE_TRAIN&>::GetCount())
    {
      const _FPL_ONE_TRAIN oOneTrain(CArray<_FPL_ONE_TRAIN, _FPL_ONE_TRAIN&>::GetAt(i));
      if (!sTrainToFind.CompareNoCase(oOneTrain.name))
        return i;
      i++;
    } // while (i < CArray<_FPL_ONE_TRAIN, _FPL_ONE_TRAIN&>::GetCount())
    return -1;
  } // INT_PTR FindTrainByName(const CString sTrainToFind) const
  INT_PTR FindTrainByTrainId(const CString sTrainIdToFind) const
  {
    if (sTrainIdToFind.IsEmpty())
      return -1;

    // if not found return -1 else position within array
    INT_PTR i(0);
    while (i < CArray<_FPL_ONE_TRAIN, _FPL_ONE_TRAIN&>::GetCount())
    {
      const _FPL_ONE_TRAIN oOneTrain(CArray<_FPL_ONE_TRAIN, _FPL_ONE_TRAIN&>::GetAt(i));
      if (oOneTrain.name.Find(sTrainIdToFind) > 0)
        return i;
      i++;
    } // while (i < CArray<_FPL_ONE_TRAIN, _FPL_ONE_TRAIN&>::GetCount())
    return -1;
  } // INT_PTR FindTrainByTrainId(const CString sTrainIdToFind) const
};

//=============================================================================
