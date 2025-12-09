#pragma once

#include <afxwin.h>

//=============================================================================
// alle Angaben zu einer Startzeile
struct _STA_ONE_LINE
{
  CString trainname;
  CString loco;
  CString waggon;
  CString track;
  CString departure;
  CString destination;

	// alles löschen:
	void clear() noexcept {
		trainname.Empty(); loco.Empty(); waggon.Empty(); track.Empty(); departure.Empty(); destination.Empty();
	}
};

// filled from BFO or STA-File
class CSTAGridArray final : public CArray <_STA_ONE_LINE, _STA_ONE_LINE&>
{
public:
  CSTAGridArray() {};
  virtual ~CSTAGridArray() { RemoveAll(); };
  CSTAGridArray& operator= (CSTAGridArray& from)
	{
		RemoveAll();
		for (INT_PTR i = 0; i < from.GetCount(); i++)
			Add(from.GetAt(i));
		return *this;
	} // CSTAGridArray& operator= (CSTAGridArray& from)
	virtual void RemoveAll() { CArray<_STA_ONE_LINE, _STA_ONE_LINE&>::RemoveAll(); }
	INT_PTR findElementByTrainName(const CString sTrainNameToFind) const
	{
		if (sTrainNameToFind.IsEmpty())
			return -1;

		// if not found return -1 else position within array
		INT_PTR i(0);
		while (i < CArray<_STA_ONE_LINE, _STA_ONE_LINE&>::GetCount())
		{
			const _STA_ONE_LINE oOneLine(CArray<_STA_ONE_LINE, _STA_ONE_LINE&>::GetAt(i));
			if (!sTrainNameToFind.CompareNoCase(oOneLine.trainname))
				return i;
			i++;
		}
		return -1;
	} // INT_PTR findElementByTrainName(const CString sTrainNameToFind) const
};
//=============================================================================
