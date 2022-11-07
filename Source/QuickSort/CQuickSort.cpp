#include "CQuickSort.h"

void CQuickSort::SwapValues(int* _piA, int* _piB)
{
	int iTemp = *_piA;

	*_piA = *_piB;
	*_piB = iTemp;

	return;
}

void CQuickSort::AssessBetterInitialPivot(int* _piArray, int _iArrayLength)
{
	if (_iArrayLength > 2)
	{
		int iASubB = _piArray[0] - _piArray[1]; // will be negative if B > A and positive if A > B
		int iBsubC = _piArray[1] - _piArray[2];
		int iASubC = _piArray[0] - _piArray[2];

		if (iASubB * iBsubC > 0) // if both are positive - means A>B and B>C (both negative means B>A and C>B; so B still middle value)
		{
			SwapValues(_piArray, _piArray + 1);
		}
		else if (iASubB * iASubC > 0) // True if Both negative( B>A and C>A ) or Both positive( A>B and A>C); hence, given B is not the middle - C is the middle (including if B and C are same value)
		{
			SwapValues(_piArray, _piArray + 2);
		}
		else
		{
			// Do nothing as A is middle value because B and C are not
			// Other case is if A == B and/or A == C and no swap is needed
		}
	}
	// Do nothing if <3 elements as there is no middle

	return;
}

void CQuickSort::Sort(int* _piArrayStart, int* _piArrayEnd, bool _bDescendingOrder)
{
	if (_bDescendingOrder)
	{
		SortDescending(_piArrayStart, _piArrayEnd);
	}
	else
	{
		SortAscending(_piArrayStart, _piArrayEnd);
	}

	return;
}

void CQuickSort::SortAscending(int* _piArrayStart, int* _piArrayEnd)
{
	// Using first element in array as pivot

	if (_piArrayStart != _piArrayEnd) // Check to see if only one element
	{
		if (_piArrayStart + 1 != _piArrayEnd) // Checking if >2 elements in Array/SubArray
		{
			int* piUpCounter = _piArrayStart + 1;
			int* piDownCounter = _piArrayEnd;
			
			while (piUpCounter < piDownCounter) // UpCounter is Left of DownCounter in memory
			{
				while (*_piArrayStart >= *piUpCounter && // Find first element moving right that is larger than pivot
					piUpCounter != piDownCounter) // Dont go past DownCounter
				{
					piUpCounter++;
				}
				while (*_piArrayStart < *piDownCounter && // Find first element moving left that is smaller than pivot
					piUpCounter != piDownCounter)
				{
					piDownCounter--;
				}

				if (piUpCounter == piDownCounter)
				{
					// No need to swap if ==; and if that is the case, decrement will cause array bounds to be violated below when passing (piDownCounter - 1)
					if (_piArrayStart != piDownCounter - 1)
					{
						piDownCounter--;
						SwapValues(_piArrayStart, piDownCounter); // Shift pivot to correct position; Ready to partition
					}
				}
				else // *UpCounter is greater than pivot, *DownCounter is less than pivot
				{
					SwapValues(piUpCounter, piDownCounter);
				}
			}

			// Partition
			SortAscending(_piArrayStart, (piDownCounter - 1));
			SortAscending(piUpCounter, _piArrayEnd);

			piUpCounter = nullptr;
			piDownCounter = nullptr;
		}
		else
		{
			// Special case; 2 left in Array/SubArray - final comparison for this partition
			if (*_piArrayStart > *_piArrayEnd)
			{
				SwapValues(_piArrayStart, _piArrayEnd);
			}
		}
	}
	
	return;
}

void CQuickSort::SortDescending(int* _piArrayStart, int* _piArrayEnd)
{
	// Using first element in array as pivot

	if (_piArrayStart != _piArrayEnd)
	{
		if (_piArrayStart + 1 != _piArrayEnd)
		{
			int* piUpCounter = _piArrayStart + 1;
			int* piDownCounter = _piArrayEnd;

			while (piUpCounter < piDownCounter)
			{
				while (*_piArrayStart <= *piUpCounter && // Find first element moving right that is smaller than pivot
					piUpCounter != piDownCounter)
				{
					piUpCounter++;
				}
				while (*_piArrayStart > *piDownCounter && // Find first element moving left that is larger than pivot
					piUpCounter != piDownCounter)
				{
					piDownCounter--;
				}

				if (piUpCounter == piDownCounter)
				{
					// No need to swap if ==; and if that is the case, decrement will cause array bounds to be violated below when passing (piDownCounter - 1)
					if (_piArrayStart != piDownCounter - 1)
					{
						piDownCounter--;
						SwapValues(_piArrayStart, piDownCounter); // Shift pivot to correct position; Ready to partition
					}
				}
				else // *UpCounter is greater than pivot, *DownCounter is less than pivot
				{
					SwapValues(piUpCounter, piDownCounter);
				}
			}

			// Partition
			SortDescending(_piArrayStart, (piDownCounter - 1)); //_piArrayStart, (piDownCounter - 1)
			SortDescending(piUpCounter, _piArrayEnd); 

			piUpCounter = nullptr;
			piDownCounter = nullptr;
		}
		else
		{
			// Special case; 2 left in Array/SubArray - final comparison for this partition
			if (*_piArrayStart < *_piArrayEnd)
			{
				SwapValues(_piArrayStart, _piArrayEnd);
			}
		}
	}

	return;
}

