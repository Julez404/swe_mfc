#include "stdafx.h"
#include "Bauelement.h"
#include "Liste.h"

/*
template<class T>
CListe<T>::CListe(T* _t)
{
	start = _t;
}


template <class T>
CListe<T>::~CListe()
{
	if (start != NULL)
	{
		delete start; // Cascaded Delete missing
	}
}


template <class T>
T* CListe<T>::getLastEntry(void)
{
	T LastEntryPtr* = start;
	if ((*start).getNext() == NULL)
	{
		LastEntryPtr = start
	}
	else
	{
		while ((*LastEntryPtr).getNext() != NULL)
		{
			LastEntryPtr = (*LastEntryPtr).getNext();
		}
	}
	return LastEntryPtr;
}


template <class T>
T* CListe<T>::getFirstEntry(void)
{
	return T;
}


template <class T>
int CListe<T>::addStart(T* _newEntryPtr)
{

	return 0;
}


template <class T>
int CListe<T>::addEnd(T* _newEntryPtr)
{
	if (_newEntryPtr == NULL)
	{
		return 1;
	}
	else
	{
		if ((*start).getNext() == NULL)
		{
			(*start).setNext(_newEntryPtr);
		}
		else
		{
			T* newEntryTempPtr = (*start).getNext();
			while ((*newEntryTempPtr).getNext() != NULL)
			{
				newEntryTempPtr = (*newEntryTempPtr).getNext();
			}
			(*newEntryTempPtr).setNext(_newEntryPtr);
		}
	}
	return 0;
}


template <class T>
void CListe<T>::printAllEntrys(void)
{

}
*/