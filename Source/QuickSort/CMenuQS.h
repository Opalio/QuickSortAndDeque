#ifndef _CMENUQS_H__
#define _CMENUQS_H__
#include <iostream>
#include <fstream>
#include "ENUMERATORSQS.h"
#include "CQuickSort.h"

using std::cout;
using std::cin;
using std::endl;

class CMenuQS
{
public:
	CMenuQS();
	~CMenuQS();

	void PrintMainMenu();

	void UpdateFormatMode();

	int* ManageInputs();
	void ManageOutputs(int* _piArrayToBeSorted);

	//EIOFORMATMODE GetFormatMode() const;

private:
	//int* m_piArray;
	int m_iNumberOfElements;
	EIOFORMATMODE m_EFormatMode;
	bool m_bDescendingOrder;
	//EMAINMENUOPTIONSQS m_EMenuOption;


	void PrintHeader();
	void PrintFormatOptionsMenu();
	void PrintArray(int* _piArrayToBePrinted);

	int* ManageConsoleInputs(); // RETURN INT POINTER as pointing to new address on heap in this function
	int* ManageFileInputs();
	
	void ManageConsoleOutputs(int* _piArrayToBeSorted);
	void ManageFileOutputs(int* _piArrayToBeSorted);
};

#endif // !_CMENUQS_H__


