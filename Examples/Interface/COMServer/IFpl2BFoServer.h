// IFpl2BFoServer.h : Header-Datei
//

#pragma once

interface IFpl2BFoServer : public IUnknown
{
public:
	virtual HRESULT STDMETHODCALLTYPE ReadSupportedFile(BSTR pzFileName) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetFileinfo(LONGLONG* pnResult) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCountOfFPLStations(LONGLONG* pnCountOfFPLStations) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetFPLStationArray(LONGLONG* pnResult) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCountOfFPLTrains(LONGLONG* pnCountOfFPLTrains) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetFPLTrainArray(LONGLONG* pnResult) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCountOfFPLTimesForOneTrain(LONGLONG* pnCountOfFplTimesForOneTrain) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetFPLTimeForOneTrainArray(LONGLONG* pnResult) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCountOfFPLPointsOnTrack(LONGLONG* pnCountOfPointsOnTrack) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetFPLPointOnTrackArray(LONGLONG* pnResult) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCountOfBFOStations(LONGLONG* pnCountOfBFOStations) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetBFOStationsArray(LONGLONG* pnResult) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCountOfBFOScheduleRows(LONGLONG* pnCountOfBFOScheduleRows) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetBFOScheduleRows(LONGLONG* pnResult) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCountOfSTAEntries(LONGLONG* pnCountOfSTAEntries) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetSTAGridArray(LONGLONG* pnResult) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCountOfBFORoutes(LONGLONG* pnCountOfRoutes) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetBFORouteArray(LONGLONG* pnResult) const = 0;

	virtual HRESULT STDMETHODCALLTYPE GetElementFromFileinfo(BSTR pzElementName, BSTR* pzElementValue) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementFromFPLStation(LONGLONG iIndex, BSTR pzElementName, BSTR* pzElementValue) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementFromFPLStationTrackName(LONGLONG iIndex, LONGLONG iSubIndex, BSTR* pzElementValue) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementFromFPLPointOnTrack(LONGLONG iIndex, BSTR pzElementName, BSTR* pzElementValue) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementFromFPLTrain(LONGLONG iIndex, BSTR pzElementName, BSTR* pzElementValue) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementFromFPLTimeForOneTrain(LONGLONG iIndex, LONGLONG iSubIndex, BSTR pzElementName, BSTR* pzElementValue) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementFromFPLMoveForOneTrain(LONGLONG iIndex, LONGLONG iSubIndex, LONGLONG iMoveIndex, BSTR pzElementName, BSTR* pzElementValue) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementFromBFOStation(LONGLONG iIndex, BSTR pzElementName, BSTR* pzElementValue) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementFromBFOStationRouteId(LONGLONG iIndex, LONGLONG iSubIndex, BSTR* pzElementValue) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementFromBFOStationPositions(LONGLONG iIndex, LONGLONG iSubIndex, BSTR pzElementName, BSTR* pzElementValue) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementFromBFOStationTrackName(LONGLONG iIndex, LONGLONG iSubIndex, BSTR* pzElementValue) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementFromBFOTimeSchedule(LONGLONG iIndex, BSTR pzElementName, BSTR* pzElementValue) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementFromBFORoute(LONGLONG iIndex, BSTR pzElementName, BSTR* pzElementValue) const = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementFromSTAEntry(LONGLONG iIndex, BSTR pzElementName, BSTR* pzElementValue) const = 0;

};
