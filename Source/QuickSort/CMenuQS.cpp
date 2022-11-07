#include "CMenuQS.h"

CMenuQS::CMenuQS()
{
	//m_piArray = nullptr;
	m_iNumberOfElements = 0;
	m_EFormatMode = EIOFORMATMODE::CONSOLE_CONSOLE;
	m_bDescendingOrder = false;
	//m_EMenuOption = EMAINMENUOPTIONSQS::FORMATMODE; // Just initialising; ensure assignment of new value before utilising
}

CMenuQS::~CMenuQS()
{
	/*if (m_piArray != nullptr)
	{
		delete[] m_piArray;
		m_piArray = nullptr;
	}*/
}

void CMenuQS::PrintMainMenu()
{
	PrintHeader();
	cout << "Menu:" << endl;
	cout << endl;
	cout << "1. In/Out Format Options" << endl;
	cout << "2. QuickSort" << endl;
	cout << "3. Quit" << endl;
	cout << endl;
	cout << "Select Option(1-3): ";

	return;
}



void CMenuQS::UpdateFormatMode()
{
	system("cls");
	PrintFormatOptionsMenu();

	int iFormatChoice;
	bool bSelectionInvalid = false;

	do
	{
		while (!(cin >> iFormatChoice))
		{
			cout << endl;
			cout << "Please input an integer: ";

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		switch (EIOFORMATMODE(iFormatChoice)) // Static cast int to EIOFORMATMODE
		{
		case EIOFORMATMODE::CONSOLE_CONSOLE:

			m_EFormatMode = EIOFORMATMODE::CONSOLE_CONSOLE;
			bSelectionInvalid = false;
			break;

		case EIOFORMATMODE::CONSOLE_FILE:

			m_EFormatMode = EIOFORMATMODE::CONSOLE_FILE;
			bSelectionInvalid = false;
			break;

		case EIOFORMATMODE::FILE_CONSOLE:

			m_EFormatMode = EIOFORMATMODE::FILE_CONSOLE;
			bSelectionInvalid = false;
			break;

		case EIOFORMATMODE::FILE_FILE:

			m_EFormatMode = EIOFORMATMODE::FILE_FILE;
			bSelectionInvalid = false;
			break;

		default:

			bSelectionInvalid = true;
			cout << endl;
			cout << "Please input an integer in the range(1-4)" << endl;
			system("pause");

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}

	} while (bSelectionInvalid);
	


	return;
}

int* CMenuQS::ManageInputs()
{
	switch (m_EFormatMode)
	{
	case EIOFORMATMODE::CONSOLE_CONSOLE:
		// Intentional Fallthrough; both console inputs
	case EIOFORMATMODE::CONSOLE_FILE:
		return(ManageConsoleInputs());
		// Now ready to sort
		break;

	case EIOFORMATMODE::FILE_CONSOLE:
		// Intentional Fallthrough; both file inputs
	case EIOFORMATMODE::FILE_FILE:
		return(ManageFileInputs());
		break;
	default:
		// Should never hit default case
		break;
	}

	return (nullptr);
}

void CMenuQS::ManageOutputs(int* _piArrayToBeSorted)
{
	switch (m_EFormatMode)
	{
	case EIOFORMATMODE::CONSOLE_CONSOLE:
		// Intentional Fallthrough; both console outputs
	case EIOFORMATMODE::FILE_CONSOLE:
		ManageConsoleOutputs(_piArrayToBeSorted);
		// Array is now sorted and has been output to console
		break;

	case EIOFORMATMODE::CONSOLE_FILE:
		// Intentional Fallthrough; both file outputs
	case EIOFORMATMODE::FILE_FILE:
		ManageFileOutputs(_piArrayToBeSorted);
		// Array is now sorted and has been ouput to file
		break;
	default:
		break;
	}

	return;
}

//
// Private Member functions below here
//

void CMenuQS::PrintHeader()
{
	system("cls");

	cout << "   >>>----- Quick Sort! ----->" << endl;
	cout << endl;
	cout << "Current Format Mode: ";
	switch (m_EFormatMode)
	{
	case EIOFORMATMODE::CONSOLE_CONSOLE:
		cout << "Console/Console" << endl;
		break;
	case EIOFORMATMODE::CONSOLE_FILE:
		cout << "Console/File" << endl;
		break;
	case EIOFORMATMODE::FILE_CONSOLE:
		cout << "File/Console" << endl;
		break;
	case EIOFORMATMODE::FILE_FILE:
		cout << "File/File" << endl;
		break;
	default:
		break;
	}
	cout << endl;
	cout << endl;
}

void CMenuQS::PrintFormatOptionsMenu()
{
	PrintHeader();
	cout << "In/Out Format Options:" << endl;
	cout << endl;
	cout << "1. Console In, Console Out" << endl;
	cout << "2. Console In, File Out" << endl;
	cout << "3. File In, Console Out" << endl;
	cout << "4. File In, File Out" << endl;
	cout << endl;
	cout << "Select Format(1-4): ";

	return;
}

void CMenuQS::PrintArray(int* _piArrayToBePrinted)
{
	for (int i = 0; i < m_iNumberOfElements; i++)
	{
		cout << "| " << *(_piArrayToBePrinted + i) << " |";
	}
	cout << endl;

	return;
}

int* CMenuQS::ManageConsoleInputs() // RETURN INT POINTER as pointing to new address on heap in this function
{
	bool bSuccessfulInput = false;

	PrintHeader();
	cout << "Sorting Order Options:" << endl;
	cout << endl;
	cout << "0. Ascending" << endl;
	cout << "1. Descending" << endl;
	cout << endl;
	cout << "Select Order: ";
	while (!(cin >> m_bDescendingOrder))
	{
		cout << endl;
		cout << "Please input valid integer(0/1): ";

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	cout << endl;
	cout << endl;
	cout << "Please input the number of elements that will be in Array(Positive Integer): ";

	do
	{
		m_iNumberOfElements = 0;
		while (!(cin >> m_iNumberOfElements)) // Checking for integer
		{
			bSuccessfulInput = false;

			cout << endl;
			cout << "Please input a positive integer(>0): ";

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		if (m_iNumberOfElements > 0) // Checking for positive integer
		{
			bSuccessfulInput = true;
		}
		else
		{
			cout << "Please input a positive integer(>0): ";
		}

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // In case of additional inputs after successful input

	} while (!bSuccessfulInput);
	bSuccessfulInput = false; // Reset so usable for future Inputs

	int* piInputedArray = new int[m_iNumberOfElements]; // Actually create the array

	cout << endl;
	cout << endl;
	cout << "Please input " << m_iNumberOfElements <<" integer elements. This can be on one line, seperated by a space." << endl;
	cout << "Once all elements are entered they will be sorted." << endl;
	cout << "Additional inputs beyond specified number will be discarded." << endl;
	cout << endl;
	cout << "Input Array to be sorted(integers): ";

		
	do
	{
		bSuccessfulInput = true; // Although reset above we are only flagging if there is a failure here

		for (int i = 0; i < m_iNumberOfElements; i++)
		{
			if (!(cin >> piInputedArray[i])) // Each iteration request cin; if all inputted on a line it will automattically take inputs from that line each deliminator hit
			{
				bSuccessfulInput = false;
				cout << endl;
				cout << "Invalid input found; Please input Array again from start: ";
				i = m_iNumberOfElements; // Exit for loop prematurely
			}
		}

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clearing in case of need for rerun if !bSuccessfulIput AND also disregarding additional elements not specified
	} while (!bSuccessfulInput);

	return (piInputedArray);
}

int* CMenuQS::ManageFileInputs()
{
	bool bSuccessfulInput = true;
	int* piInputedArray = nullptr;

	do
	{
		bSuccessfulInput = true; // Flag as flase if bad input

		PrintHeader();
		cout << "File Input:" << endl;
		cout << endl;
		cout << "Navigate file explorer to find QuickSort>Input.txt" << endl;
		cout << "Open the file," << endl;
		cout << endl;
		cout << "On the first line input(0/1)" << endl;
		cout << "     0. Sort in Ascending Order" << endl;
		cout << "     1. Sort in Descending Order" << endl;
		cout << endl;
		cout << "On the second line input how many elements the Array to be sorted has(positive integer)" << endl;
		cout << endl;
		cout << "On the third line input each element of the Array to be sorted, seperated by a space" << endl;
		cout << endl;
		cout << "Continue once you have saved the txt file" << endl;
		cout << endl;
		system("pause");


		std::ifstream fileInput("Input.txt");
		if (fileInput.is_open())
		{
			if (fileInput >> m_bDescendingOrder)
			{
				if (fileInput >> m_iNumberOfElements)
				{
					piInputedArray = new int[m_iNumberOfElements];
					for (int i = 0; i < m_iNumberOfElements; i++)
					{
						if (!(fileInput >> piInputedArray[i]))
						{
							bSuccessfulInput = false;
							cout << "Error reading Array to be sorted, please input integers seperated by spaces and try again" << endl;
							system("pause");
							delete[] piInputedArray;
							piInputedArray = nullptr;

							i = m_iNumberOfElements; // Force exit from loop
						}
					}
				}
				else
				{
					bSuccessfulInput = false;
					cout << "Error reading Number Of Elements value, please input a valid integer(>0) and try again" << endl;
					system("pause");
				}
			}
			else
			{
				bSuccessfulInput = false;
				cout << "Error reading Ascending/Descending value, please input a valid value(0/1) and try again" << endl;
				system("pause");
			}
		}
		else
		{
			cout << "Unable to open file";
		}




	} while (!bSuccessfulInput);
	// Everything Input correctly

	return (piInputedArray);
}

void CMenuQS::ManageConsoleOutputs(int* _piArrayToBeSorted)
{
	PrintHeader();

	cout << "Initial Array: ";
	PrintArray(_piArrayToBeSorted);
	cout << endl;

	CQuickSort::AssessBetterInitialPivot(_piArrayToBeSorted, m_iNumberOfElements);
	CQuickSort::Sort(_piArrayToBeSorted, (_piArrayToBeSorted + (m_iNumberOfElements - 1)), m_bDescendingOrder);

	if (m_bDescendingOrder)
	{
		cout << "Sorted in Descending Order:" << endl;
	}
	else
	{
		cout << "Sorted in Ascending Order:" << endl;
	}

	PrintArray(_piArrayToBeSorted);
	system("pause");

	return;
}

void CMenuQS::ManageFileOutputs(int* _piArrayToBeSorted)
{
	PrintHeader();

	cout << "Outputting to file..." << endl;
	cout << "Navigate file explorer to find QuickSort>Output.txt" << endl;

	CQuickSort::AssessBetterInitialPivot(_piArrayToBeSorted, m_iNumberOfElements);
	CQuickSort::Sort(_piArrayToBeSorted, (_piArrayToBeSorted + (m_iNumberOfElements - 1)), m_bDescendingOrder);

	std::ofstream fileOutput("Output.txt");
	if (fileOutput.is_open())
	{
		if (m_bDescendingOrder)
		{
			fileOutput << "Sorted in Descending Order:\n";
		}
		else
		{
			fileOutput << "Sorted in Ascending Order:\n";
		}

		for (int i = 0; i < m_iNumberOfElements; i++)
		{
			fileOutput << _piArrayToBeSorted[i] << " ";
		}
		fileOutput.close();
	}
	else
	{
		cout << "Unable to open file";
	}

	system("pause");

	return;
}

