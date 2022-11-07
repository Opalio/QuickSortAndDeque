#ifndef _CQUICKSORT_H__
#define _CQUICKSORT_H__
#include "ENUMERATORSQS.h"



class CQuickSort
{
public:

	static void SwapValues(int* _piA, int* _piB);
	static void AssessBetterInitialPivot(int* _piArray, int _iArrayLength); // Array must have >2 elements

	static void Sort(int* _piArrayStart, int* _iArrayEnd, bool _bDescendingOrder);

private:
	static void SortAscending(int* _piArrayStart, int* _piArrayEnd);
	static void SortDescending(int* _piArrayStart, int* _piArrayEnd);

};

#endif // !_CQUICKSORT_H__