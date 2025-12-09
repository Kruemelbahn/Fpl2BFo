// Computergenerierte IDispatch-Wrapperklassen, die mit dem Assistenten zum Hinzufügen von Klassen aus der Typbibliothek erstellt wurden

#import "Fpl2BFoServer.tlb" no_namespace
// CFpl2BFoServer Wrapperklasse

class CFpl2BFoServer : public COleDispatchDriver
{
public:
	CFpl2BFoServer() {} // Ruft den COleDispatchDriver-Standardkonstruktor auf.
	CFpl2BFoServer(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFpl2BFoServer(const CFpl2BFoServer& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attribute
public:

	// Vorgänge
public:


	// IFpl2BFoServer Methoden
public:
	STDMETHOD(ReadSupportedFile)(LPCTSTR pzFileName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x60010000, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pzFileName);
		return result;
	}
	STDMETHOD(GetFileinfo)(__int64* pnResult)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x60010001, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnResult);
		return result;
	}
	STDMETHOD(GetCountOfFPLStations)(__int64* pnCountOfFPLStations)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x60010002, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnCountOfFPLStations);
		return result;
	}
	STDMETHOD(GetFPLStationArray)(__int64* pnResult)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x60010003, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnResult);
		return result;
	}
	STDMETHOD(GetCountOfFPLTrains)(__int64* pnCountOfFPLTrains)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x60010004, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnCountOfFPLTrains);
		return result;
	}
	STDMETHOD(GetFPLTrainArray)(__int64* pnResult)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x60010005, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnResult);
		return result;
	}
	STDMETHOD(GetCountOfFPLTimesForOneTrain)(__int64* pnCountOfFplTimesForOneTrain)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x60010006, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnCountOfFplTimesForOneTrain);
		return result;
	}
	STDMETHOD(GetFPLTimeForOneTrainArray)(__int64* pnResult)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x60010007, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnResult);
		return result;
	}
	STDMETHOD(GetCountOfFPLPointsOnTrack)(__int64* pnCountOfPointsOnTrack)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x60010008, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnCountOfPointsOnTrack);
		return result;
	}
	STDMETHOD(GetFPLPointOnTrackArray)(__int64* pnResult)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x60010009, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnResult);
		return result;
	}
	STDMETHOD(GetCountOfBFOStations)(__int64* pnCountOfBFOStations)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x6001000a, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnCountOfBFOStations);
		return result;
	}
	STDMETHOD(GetBFOStationsArray)(__int64* pnResult)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x6001000b, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnResult);
		return result;
	}
	STDMETHOD(GetCountOfBFOScheduleRows)(__int64* pnCountOfBFOScheduleRows)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x6001000c, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnCountOfBFOScheduleRows);
		return result;
	}
	STDMETHOD(GetBFOScheduleRows)(__int64* pnResult)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x6001000d, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnResult);
		return result;
	}
	STDMETHOD(GetCountOfSTAEntries)(__int64* pnCountOfSTAEntries)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x6001000e, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnCountOfSTAEntries);
		return result;
	}
	STDMETHOD(GetSTAGridArray)(__int64* pnResult)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x6001000f, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnResult);
		return result;
	}
	STDMETHOD(GetCountOfBFORoutes)(__int64* pnCountOfRoutes)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x60010010, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnCountOfRoutes);
		return result;
	}
	STDMETHOD(GetBFORouteArray)(__int64* pnResult)
	{
		HRESULT result;
		static BYTE parms[] = VTS_UNKNOWN;
		InvokeHelper(0x60010011, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pnResult);
		return result;
	}
	STDMETHOD(GetElementFromFileinfo)(LPCTSTR pzElementName, BSTR* pzElementValue)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x60010012, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, pzElementName, pzElementValue);
		return result;
	}
	STDMETHOD(GetElementFromFPLStation)(__int64 iIndex, LPCTSTR pzElementName, BSTR* pzElementValue)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I8 VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x60010013, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, iIndex, pzElementName, pzElementValue);
		return result;
	}
	STDMETHOD(GetElementFromFPLStationTrackName)(__int64 iIndex, __int64 iSubIndex, BSTR* pzElementValue)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I8 VTS_I8 VTS_PBSTR;
		InvokeHelper(0x60010014, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, iIndex, iSubIndex, pzElementValue);
		return result;
	}
	STDMETHOD(GetElementFromFPLPointOnTrack)(__int64 iIndex, LPCTSTR pzElementName, BSTR* pzElementValue)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I8 VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x60010015, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, iIndex, pzElementName, pzElementValue);
		return result;
	}
	STDMETHOD(GetElementFromFPLTrain)(__int64 iIndex, LPCTSTR pzElementName, BSTR* pzElementValue)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I8 VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x60010016, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, iIndex, pzElementName, pzElementValue);
		return result;
	}
	STDMETHOD(GetElementFromFPLTimeForOneTrain)(__int64 iIndex, __int64 iSubIndex, LPCTSTR pzElementName, BSTR* pzElementValue)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I8 VTS_I8 VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x60010017, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, iIndex, iSubIndex, pzElementName, pzElementValue);
		return result;
	}
	STDMETHOD(GetElementFromFPLMoveForOneTrain)(__int64 iIndex, __int64 iSubIndex, __int64 iMoveIndex, LPCTSTR pzElementName, BSTR* pzElementValue)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I8 VTS_I8 VTS_I8 VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x60010018, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, iIndex, iSubIndex, iMoveIndex, pzElementName, pzElementValue);
		return result;
	}
	STDMETHOD(GetElementFromBFOStation)(__int64 iIndex, LPCTSTR pzElementName, BSTR* pzElementValue)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I8 VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x60010019, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, iIndex, pzElementName, pzElementValue);
		return result;
	}
	STDMETHOD(GetElementFromBFOStationRouteId)(__int64 iIndex, __int64 iSubIndex, BSTR* pzElementValue)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I8 VTS_I8 VTS_PBSTR;
		InvokeHelper(0x6001001a, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, iIndex, iSubIndex, pzElementValue);
		return result;
	}
	STDMETHOD(GetElementFromBFOStationPositions)(__int64 iIndex, __int64 iSubIndex, LPCTSTR pzElementName, BSTR* pzElementValue)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I8 VTS_I8 VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x6001001b, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, iIndex, iSubIndex, pzElementName, pzElementValue);
		return result;
	}
	STDMETHOD(GetElementFromBFOStationTrackName)(__int64 iIndex, __int64 iSubIndex, BSTR* pzElementValue)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I8 VTS_I8 VTS_PBSTR;
		InvokeHelper(0x6001001c, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, iIndex, iSubIndex, pzElementValue);
		return result;
	}
	STDMETHOD(GetElementFromBFOTimeSchedule)(__int64 iIndex, LPCTSTR pzElementName, BSTR* pzElementValue)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I8 VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x6001001d, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, iIndex, pzElementName, pzElementValue);
		return result;
	}
	STDMETHOD(GetElementFromBFORoute)(__int64 iIndex, LPCTSTR pzElementName, BSTR* pzElementValue)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I8 VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x6001001e, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, iIndex, pzElementName, pzElementValue);
		return result;
	}
	STDMETHOD(GetElementFromSTAEntry)(__int64 iIndex, LPCTSTR pzElementName, BSTR* pzElementValue)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I8 VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x6001001f, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, iIndex, pzElementName, pzElementValue);
		return result;
	}

	// IFpl2BFoServer Eigenschaften
public:

};
