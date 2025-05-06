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
  CString version;  // Dateiversion
  CString d;
  CString tMin;
  CString tMax;
  CString sFont;
  CString trFont;
  CString hFont;
  CString tFont;

  // nicht aus der fpl-Datei:
  INT_PTR iStationCount { 0 };
  INT_PTR iTrainCount { 0 };
  CString fplfile;    // FPL-Datei
  CString bfofile;    // BFO-Datei
  CString stafile;    // STA-Datei
  CString staVersion; // STA-Dateiversion
  CString trackplan;  // Gleisplandatei
  BOOL printData { FALSE }; // kommt aus 'INT_PTR CFpl2BFoDoc::AskForMissingInformations()'

  // alles löschen:
  void clear(const BOOL bAll) noexcept {
    file.Empty(); info.Empty(); version.Empty(); d.Empty(); tMin.Empty(); tMax.Empty(); fplfile.Empty();
    sFont.Empty(); trFont.Empty(); hFont.Empty(); tFont.Empty();
    iStationCount = iTrainCount = 0;
    if (bAll) { bfofile.Empty(); trackplan.Empty(); stafile.Empty(); staVersion.Empty(); }
  }
};

//=============================================================================
// alle Angaben zu einer Station
struct _FPL_ONE_STATION
{
  CString name;
  int fpl_id { 0 };
  CString fpl_cd;
  CString fpl_tp;
  CString fpl_vmax;
  CString fpl_rt;
  CString km;
  CString dTi;
  CString dTa;
  CStringArray *pTracklist { NULL };
};

// filled from FPL-File
class CFPLStationArray : public CArray <_FPL_ONE_STATION, _FPL_ONE_STATION&>
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
      }
    }
    CArray<_FPL_ONE_STATION, _FPL_ONE_STATION&>::RemoveAll();
  } // virtual void RemoveAll()
  INT_PTR findStationById(const int iStationIdToFind) const
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
  } // INT_PTR findStationById(const int iStationIdToFind) const
};

//=============================================================================
// alle Angaben zu einer Strecke
struct _FPL_ONE_STATION_ON_TRACK
{
  CString name;
  CString km;
  CString fpl_rt;
  CString fpl_vmax;
  CString fpl_wl;
  CString fpl_dir;
  CString fpl_cd;
  CString fpl_tp;
};

// filled from FPL-File
class CFPLStationTrackArray : public CArray <_FPL_ONE_STATION_ON_TRACK, _FPL_ONE_STATION_ON_TRACK&>
{
public:
  CFPLStationTrackArray() {};
  virtual ~CFPLStationTrackArray() { RemoveAll(); };
  virtual void RemoveAll() { CArray<_FPL_ONE_STATION_ON_TRACK, _FPL_ONE_STATION_ON_TRACK&>::RemoveAll(); };
  INT_PTR AddUnique(_FPL_ONE_STATION_ON_TRACK oOneStationOnTrack, BOOL& bFound)
  {
    INT_PTR i(0);
    bFound = FALSE;
    while (i < GetSize())
    {
      if (!oOneStationOnTrack.km.CompareNoCase(CArray<_FPL_ONE_STATION_ON_TRACK, _FPL_ONE_STATION_ON_TRACK&>::GetAt(i).km))
      {
        bFound = TRUE;
        return i;
      }
      i++;
    }
    return CArray<_FPL_ONE_STATION_ON_TRACK, _FPL_ONE_STATION_ON_TRACK&>::Add(oOneStationOnTrack);
  } // INT_PTR AddUnique(_FPL_ONE_STATION_ON_TRACK oOneStationOnTrack, BOOL& bFound)
  BOOL SortByKm()
  {
    BOOL bChange(FALSE);
    for (INT_PTR i = 0; i < GetCount(); i++)
    {
      const _FPL_ONE_STATION_ON_TRACK oOuterStation(GetAt(i));
      for (INT_PTR j = i + 1; j < GetCount(); j++)
      {
        _FPL_ONE_STATION_ON_TRACK oInnerStation(GetAt(j));

        double dOuterStation(0.0);
        try { dOuterStation = atof(ReplaceDecimalPoint_LOCAL(oOuterStation.km)); }
        catch (...) {}
        double dInnerStation(0.0);
        try { dInnerStation = atof(ReplaceDecimalPoint_LOCAL(oInnerStation.km)); }
        catch (...) {}

        if (_dpcomp(dOuterStation, dInnerStation) == _FP_GT)
        {
          _FPL_ONE_STATION_ON_TRACK oTempStation(GetAt(i));
          SetAt(i, oInnerStation);
          SetAt(j, oTempStation);
          bChange = TRUE;
        } // if(oOuterTrain.name > oInnerTrain.name)
      } // for (INT_PTR j = i + 1; j < GetCount(); j++)
    } // for (INT_PTR i = 0; i < GetCount(); i++)
    return bChange;
  } // BOOL SortByKm()
};

//=============================================================================
// alle Zeitangaben zu einem Zug
struct _FPL_TIME_FOR_ONE_TRAIN
{
  int fpl_id { 0 };
  CString d;  // destination time
  CString dt; // destination track
  CString a;  // arrival time
  CString at; // arrival track
};

// filled from FPL-File
class CFPLTimeForOneTrainArray : public CArray <_FPL_TIME_FOR_ONE_TRAIN, _FPL_TIME_FOR_ONE_TRAIN&>
{
public:
  CFPLTimeForOneTrainArray() {};
  virtual ~CFPLTimeForOneTrainArray() { RemoveAll(); };
  virtual void RemoveAll() { CArray<_FPL_TIME_FOR_ONE_TRAIN, _FPL_TIME_FOR_ONE_TRAIN&>::RemoveAll(); }
};

//=============================================================================
// alle Angaben zu einem Zug
struct _FPL_ONE_TRAIN
{
  CString name;
  CString d;
  CString fpl_tfz;
  CString fpl_last;
  CString cm;
  int id { 0 };
  CString direction;   // 'ta', 'ti' or 'tr' used for direction of train <ti>='down', <ta>='up', <tr>= use fpl_id-order 
  CFPLTimeForOneTrainArray* pTrainTimeArray { NULL };
};

// filled from FPL-File
class CFPLTrainArray : public CArray <_FPL_ONE_TRAIN, _FPL_ONE_TRAIN&>
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
  BOOL SortByName()
  {
    BOOL bChange(FALSE);
    for (INT_PTR i = 0; i < GetCount(); i++)
    {
      const _FPL_ONE_TRAIN oOuterTrain(GetAt(i));
      for (INT_PTR j = i + 1; j < GetCount(); j++)
      {
        _FPL_ONE_TRAIN oInnerTrain(GetAt(j));
        if (oOuterTrain.name > oInnerTrain.name)
        {
          _FPL_ONE_TRAIN oTempTrain(GetAt(i));
          SetAt(i, oInnerTrain);
          SetAt(j, oTempTrain);
          bChange = TRUE;
        } // if(oOuterTrain.name > oInnerTrain.name)
      } // for (INT_PTR j = i + 1; j < GetCount(); j++)
    } // for (INT_PTR i = 0; i < GetCount(); i++)
    return bChange;
  } // BOOL SortByName()
};
//=============================================================================
