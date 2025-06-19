#pragma once

#include <afxwin.h>
#include "UtilParserDefines.h"

//=============================================================================
class CUIntUniqueArray final : public CUIntArray
{
public:
  CUIntUniqueArray() noexcept {};
  virtual ~CUIntUniqueArray() {};
  CUIntUniqueArray& operator= (const CUIntUniqueArray& from)
  {
    RemoveAll();
    BOOL bDummy(FALSE);
    for (INT_PTR i = 0; i < from.GetCount(); i++)
      AddUnique(from.GetAt(i), bDummy);
    return *this;
  } // CUIntUniqueArray& operator= (const CUIntUniqueArray& from)
  INT_PTR AddUnique(UINT uiValue, BOOL& bFound)
  {
    INT_PTR i(0);
    bFound = FALSE;
    while (i < GetSize())
    {
      if (GetAt(i) == uiValue)
      {
        bFound = TRUE;
        return i;
      }
      i++;
    }
    return Add(uiValue);
  } // INT_PTR AddUnique(UINT uiValue, BOOL& bFound)
};

//=============================================================================
// alle Angaben zu einer Position in einer Station
struct _BFO_ONE_POSITION
{
  int RouteId { 0 };
  CString Km;
};

class CBFOPositionsArray final : public CArray <_BFO_ONE_POSITION, _BFO_ONE_POSITION&>
{
public:
  CBFOPositionsArray() {};
  virtual ~CBFOPositionsArray() { RemoveAll(); };
  virtual void RemoveAll() { CArray<_BFO_ONE_POSITION, _BFO_ONE_POSITION&>::RemoveAll(); };
};

//=============================================================================
// minimale Angaben zu einer Station (wird u.a. intern in CRouteArray benötigt)
struct _ONE_STATION
{
  CString Name;
  int Id { 0 };
  double Km { 0.0 };
};

class CStationArray final : public CArray <_ONE_STATION, _ONE_STATION&>
{
public:
  CStationArray() {};
  virtual ~CStationArray() { RemoveAll(); };
  virtual void RemoveAll() { CArray<_ONE_STATION, _ONE_STATION&>::RemoveAll(); };
  INT_PTR AddSorted(_ONE_STATION oneStationToAdd)
  {
    INT_PTR i(CArray<_ONE_STATION, _ONE_STATION&>::GetCount() - 1);
    if (i == -1)
      // erstes Element : einfach anhängen
      return CArray<_ONE_STATION, _ONE_STATION&>::Add(oneStationToAdd);

    // wird der Eintrag am Ende eingefügt ?
    _ONE_STATION oCurrentStation(CArray<_ONE_STATION, _ONE_STATION&>::GetAt(i));
    if (_dpcomp(oneStationToAdd.Km, oCurrentStation.Km) == _FP_GT)
      return CArray<_ONE_STATION, _ONE_STATION&>::Add(oneStationToAdd);

    // nein : Position suchen
    while (i >= 0)
    {
      oCurrentStation = CArray<_ONE_STATION, _ONE_STATION&>::GetAt(i);
      if (_dpcomp(oneStationToAdd.Km, oCurrentStation.Km) == _FP_GT)
      {
        CArray<_ONE_STATION, _ONE_STATION&>::InsertAt(i + 1, oneStationToAdd);
        return i + 1;
      }
      i--;
    } // while (i >= 0)

    CArray<_ONE_STATION, _ONE_STATION&>::InsertAt(0, oneStationToAdd);
    return 0;
  } // INT_PTR AddSorted(_ONE_STATION oneStationToAdd)
};

//=============================================================================
// alle Angaben zu einer Station
struct _BFO_ONE_STATION
{
  CString Name;
  CString d;
  int Id { -1 };
  BOOL IsJunction { FALSE };
  CUIntArray* pRouteIds { NULL };
  CBFOPositionsArray* pPositions { NULL };
  CStringArray* pTracks { NULL };

  // nicht aus der bfo-Datei:
  int X { 0 };
  int Y { 0 };
  CString StationLeft;
  CString StationRight;
  CString StationTyp;
  CString StationShortName;
  CString Info;
  BOOL IsFreeEdit{ FALSE };

  // alles löschen:
  void clear(const int iId) noexcept {
    Name.Empty(); d.Empty(); StationLeft.Empty(); StationRight.Empty(); StationTyp.Empty(); StationShortName.Empty(); Info.Empty();
    Id = iId;
    X = Y = 0;
    IsJunction = IsFreeEdit = FALSE;
    pRouteIds = NULL; pPositions = NULL; pTracks = NULL;
  }
};

// filled from BFO-File
class CBFOStationsArray final : public CArray <_BFO_ONE_STATION, _BFO_ONE_STATION&>
{
public:
  CBFOStationsArray() {};
  virtual ~CBFOStationsArray() { RemoveAll(); };
  virtual void RemoveAll()
  {
    for (INT_PTR i = 0; i < GetCount(); i++)
    {
      _BFO_ONE_STATION oOneStation(GetAt(i));
      if (oOneStation.pRouteIds)
      {
        (oOneStation.pRouteIds)->RemoveAll();
        deletenull(oOneStation.pRouteIds)
      }
      if (oOneStation.pPositions)
      {
        (oOneStation.pPositions)->RemoveAll();
        deletenull(oOneStation.pPositions)
      }
      if (oOneStation.pTracks)
      {
        (oOneStation.pTracks)->RemoveAll();
        deletenull(oOneStation.pTracks)
      }
    }
    CArray<_BFO_ONE_STATION, _BFO_ONE_STATION&>::RemoveAll();
  } // virtual void RemoveAll()
  INT_PTR FindStationIndexById(const int iStationIdToFind) const
  {
    if (iStationIdToFind < 0)
      return -1;

    // if not found return -1 else position within array
    INT_PTR i(0);
    while (i < CArray<_BFO_ONE_STATION, _BFO_ONE_STATION&>::GetCount())
    {
      const _BFO_ONE_STATION oOneStation(CArray<_BFO_ONE_STATION, _BFO_ONE_STATION&>::GetAt(i));
      if (iStationIdToFind == oOneStation.Id)
        return i;
      i++;
    }
    return -1;
  } // INT_PTR FindStationIndexById(const int iStationIdToFind) const
  INT_PTR FindStationIdByName(const CString sStationNameToFind) const
  {
    if (sStationNameToFind.IsEmpty())
      return -1;

    // if not found return -1 else position within array
    INT_PTR i(0);
    while (i < CArray<_BFO_ONE_STATION, _BFO_ONE_STATION&>::GetCount())
    {
      const _BFO_ONE_STATION oOneStation(CArray<_BFO_ONE_STATION, _BFO_ONE_STATION&>::GetAt(i));
      if (!sStationNameToFind.CompareNoCase(oOneStation.Name))
        return oOneStation.Id;  // 1...n
      i++;
    }
    return -1;
  } // INT_PTR FindStationIdByName(const CString sStationNameToFind) const
};

//=============================================================================
// alle Angaben zu einer Zeitplanzeile
struct _BFO_ONE_SCHEDULE_ROW
{
  int iTimeValueForSort { 0 };
  int iTimeValueForSortArrival { 0 };
  int iTimeValueForSortDeparture { 0 };
  CString Arrival;
  CString Departure;
  CString TrainClass;
  CString TrainId;
  CString Track;
  CString NotificationFrom;
  CString NotificationTo;
  CString ChangeId;
  CString ReverseDirection;
  CString Command;
  CString Comment;

  // alles löschen:
  void clear() noexcept {
    iTimeValueForSort = iTimeValueForSortArrival = iTimeValueForSortDeparture = 0;
    Arrival.Empty(); Departure.Empty(); TrainClass.Empty(); TrainId.Empty(); Track.Empty(); NotificationFrom.Empty(); NotificationTo.Empty();
    ChangeId.Empty(); ReverseDirection.Empty(); Command.Empty(); Comment.Empty();
  }
};

// filled from FPL- or BFO-File
class CBFOScheduleRows final : public CArray <_BFO_ONE_SCHEDULE_ROW, _BFO_ONE_SCHEDULE_ROW&>
{
public:
  CBFOScheduleRows() {};
  virtual ~CBFOScheduleRows() { RemoveAll(); };
  virtual void RemoveAll() { CArray<_BFO_ONE_SCHEDULE_ROW, _BFO_ONE_SCHEDULE_ROW&>::RemoveAll(); };
  CBFOScheduleRows& operator= (CBFOScheduleRows& from)
  {
    RemoveAll();
    for (INT_PTR i = 0; i < from.GetCount(); i++)
      AddSorted(from.GetAt(i));
    return *this;
  } // CBFOScheduleRows& operator= (CBFOScheduleRows& from)
  INT_PTR AddSorted(_BFO_ONE_SCHEDULE_ROW oneScheduleRow)
  {
    if (oneScheduleRow.iTimeValueForSort == 0)
      return CArray<_BFO_ONE_SCHEDULE_ROW, _BFO_ONE_SCHEDULE_ROW&>::Add(oneScheduleRow);

    INT_PTR i(CArray<_BFO_ONE_SCHEDULE_ROW, _BFO_ONE_SCHEDULE_ROW&>::GetCount() - 1);
    if (i == -1)
      // erstes Element : einfach anhängen
      return CArray<_BFO_ONE_SCHEDULE_ROW, _BFO_ONE_SCHEDULE_ROW&>::Add(oneScheduleRow);

    if (FindIndexByTimeValue(oneScheduleRow.iTimeValueForSort) == -1)
    { // nicht gefunden : (sortiert) einfügen

      // wird der Eintrag am Ende eingefügt ?
      _BFO_ONE_SCHEDULE_ROW oRow(CArray<_BFO_ONE_SCHEDULE_ROW, _BFO_ONE_SCHEDULE_ROW&>::GetAt(i));
      if (oneScheduleRow.iTimeValueForSort > oRow.iTimeValueForSort)
        return CArray<_BFO_ONE_SCHEDULE_ROW, _BFO_ONE_SCHEDULE_ROW&>::Add(oneScheduleRow);

      // nein : Position suchen
      while (i >= 0)
      {
        oRow = CArray<_BFO_ONE_SCHEDULE_ROW, _BFO_ONE_SCHEDULE_ROW&>::GetAt(i);
        if (oneScheduleRow.iTimeValueForSort > oRow.iTimeValueForSort)
        {
          CArray<_BFO_ONE_SCHEDULE_ROW, _BFO_ONE_SCHEDULE_ROW&>::InsertAt(i + 1, oneScheduleRow);
          return i + 1;
        }
        i--;
      } // while (i >= 0)

      CArray<_BFO_ONE_SCHEDULE_ROW, _BFO_ONE_SCHEDULE_ROW&>::InsertAt(0, oneScheduleRow);
      return 0;

    } // if (Find(oneScheduleRow.iTimeValueForSort) == -1)
    return -1; // gefunden : nicht einfügen
  } // INT_PTR AddSorted(_BFO_ONE_SCHEDULE_ROW oneScheduleRow)
  INT_PTR FindIndexByTimeValue(const int iTimeValueForSort) const
  {
    // if not found return -1 else position within array
    INT_PTR i(0);
    while (i < CArray<_BFO_ONE_SCHEDULE_ROW, _BFO_ONE_SCHEDULE_ROW&>::GetCount())
    {
      const _BFO_ONE_SCHEDULE_ROW oRow(CArray<_BFO_ONE_SCHEDULE_ROW, _BFO_ONE_SCHEDULE_ROW&>::GetAt(i));
      if (iTimeValueForSort == oRow.iTimeValueForSort)
        return i;
      i++;
    }
    return -1;
  } // INT_PTR FindIndexByTimeValue(const int iTimeValueForSort) const
};

//=============================================================================
// alle Angaben zu einer Strecke
struct _ONE_ROUTE
{
  int RouteId{ 0 };
  CString firstStation;
  CString lastStation;
};

// filled from BFO-File
class CRouteArray final : public CArray <_ONE_ROUTE, _ONE_ROUTE&>
{
public:
  CRouteArray(CBFOStationsArray* pBFOStationsArray)
  {
    if (!pBFOStationsArray)
      return;
    // count Routes:
    CUIntUniqueArray aNetsListRouteId{};
    BOOL bFound(FALSE);
    for (INT_PTR iIndex = 0; iIndex < pBFOStationsArray->GetCount(); iIndex++)
    {
      const _BFO_ONE_STATION oBFOStation(pBFOStationsArray->GetAt(iIndex));
      if (oBFOStation.pRouteIds)
      {
        for (INT_PTR iIndexRoute = 0; iIndexRoute < (oBFOStation.pRouteIds)->GetCount(); iIndexRoute++)
          aNetsListRouteId.AddUnique((oBFOStation.pRouteIds)->GetAt(iIndexRoute), bFound);
      } // if (oBFOStation.pRouteIds)
    } // for (INT_PTR iIndex = 0; iIndex < m_pBFOStations->GetCount(); iIndex++)

    // collect Routes
    for (INT_PTR iRouteId = 0; iRouteId < aNetsListRouteId.GetCount(); iRouteId++)
    {
      // filter and sort stations for current RouteId
      CStationArray oStationArray{};
      for (INT_PTR iIndex = 0; iIndex < pBFOStationsArray->GetCount(); iIndex++)
      {
        const _BFO_ONE_STATION oBFOStation(pBFOStationsArray->GetAt(iIndex));
        if (oBFOStation.pPositions)
        {
          for (INT_PTR iIndexPosition = 0; iIndexPosition < (oBFOStation.pPositions)->GetCount(); iIndexPosition++)
          {
            const _BFO_ONE_POSITION oBFOPosition((oBFOStation.pPositions)->GetAt(iIndexPosition));
            if (oBFOPosition.RouteId == aNetsListRouteId.GetAt(iRouteId))
            {
              _ONE_STATION oneStation{};
              oneStation.Name = oBFOStation.Name;
              oneStation.Id = oBFOStation.Id;
              oneStation.Km = -1.0;
              try { oneStation.Km = atof(ReplaceDecimalPoint_LOCAL(oBFOPosition.Km)); }
              catch (...) {}
              oStationArray.AddSorted(oneStation);
            } // if (oBFOPosition.RouteId == aNetsListRouteId.GetAt(iRouteId))
          } // for (INT_PTR iIndexPosition = 0; iIndexPosition < (oBFOStation.pPositions)->GetCount(); iIndexPosition++)
        } // if (oBFOStation.pPositions)
      } // for (INT_PTR iIndex = 0; iIndex < m_pBFOStations->GetCount(); iIndex++)

      _ONE_ROUTE oneRoute{};
      oneRoute.RouteId = aNetsListRouteId.GetAt(iRouteId);
      oneRoute.firstStation = oStationArray.GetAt(0).Name;
      oneRoute.lastStation = oStationArray.GetAt(oStationArray.GetCount() - 1).Name;
      CArray<_ONE_ROUTE, _ONE_ROUTE&>::Add(oneRoute);
    } // for (INT_PTR iRouteId = 0; iRouteId < aNetsListRouteId.GetCount(); iRouteId++)
  } // CRouteArray(CBFOStationsArray* pBFOStationsArray)
  virtual ~CRouteArray() { RemoveAll(); };
  virtual void RemoveAll() { CArray<_ONE_ROUTE, _ONE_ROUTE&>::RemoveAll(); };
  INT_PTR Find(const int iValue) const
  {
    // if not found return -1 else position within array
    INT_PTR i(0);
    while (i < CArray<_ONE_ROUTE, _ONE_ROUTE&>::GetCount())
    {
      const _ONE_ROUTE oRoute(CArray<_ONE_ROUTE, _ONE_ROUTE&>::GetAt(i));
      if (iValue == oRoute.RouteId)
        return i;
      i++;
    }
    return -1;
  } // INT_PTR Find(const int iValue) const
  CString GetAsString(const INT_PTR iRoute)
  {
    const _ONE_ROUTE oneRoute(CArray<_ONE_ROUTE, _ONE_ROUTE&>::GetAt(iRoute));
    CString sRoute;
    sRoute.Format(_T("%i: %s %c=%c %s"), oneRoute.RouteId, oneRoute.firstStation, unsigned char{ 0xAB }, unsigned char{ 0xBB }, oneRoute.lastStation);
    return sRoute;
  } // CString GetAsString(const INT_PTR iRoute)
};
//=============================================================================
