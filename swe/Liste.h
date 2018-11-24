#pragma once
#include "Bauelement.h"
#include "ImpedanzRechner.h"

class CListe
{
protected:
	CBauelement* start;
	ImpedanzRechner* ImpPtr;


public:
	CListe();
	CListe(CBauelement* _bauelement);
	~CListe();
	
	CBauelement* CListe::getStart(void) const;
	int  getEntryCount(void)const;
	void printAllElements(void) const;
	CBauelement* searchName(const std::string& _nameToFind) const;
	CComplex getSerialImpedanz(double _f) const;
	CComplex getImpedanzOfList(double _f) const;

	bool setStart(CBauelement* _newStartPtr);
	bool addToStart(CBauelement* _newStartPtr);
	bool addToEnd(CBauelement* _newStartPtr);
	bool delAtStart(void);
	void setImpPtr(ImpedanzRechner* _ImpPtr);






	/*
	template<class T, class K>
	CListe search(T _searchObj, T (*fktPtr)(K&)) const;
	*/
	friend std::ostream& operator<<(std::ostream& stream, const CListe& _list);
};


/*
//Will move to .cpp with polymorphie
template<class T, class K>
CBauelement** CListe::search(T _searchObj, T(*fktPtr)(K&)) const
{
	CListe listOfItemsToReturn;
	CBauelement* searchPtr = start;
	while (searchPtr != NULL)
	{
		if ((*fktPtr)(*searchPtr) == _searchObj)
		{
			listOfItemsToReturn.addToStart(new CBauelement(*searchPtr));
		}
		searchPtr = searchPtr->getNext();
	}
	return listOfItemsToReturn;
}
*/


