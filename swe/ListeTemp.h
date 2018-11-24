#pragma once

template <class T>
class CListe
{

private:
	T* start;


public:
	CListe(T* _t);
	~CListe();

	
	T* getLastEntry(void);
	T* getFirstEntry(void);

	///<summary>
	//Returns 0 on Success
	///</summary>
	int addStart(T* _newEntryPtr);
	///<summary>
	//Returns 0 on Success
	///</summary>
	int addEnd(T* _newEntryPtr);

	void printAllEntrys(void);
	
};
