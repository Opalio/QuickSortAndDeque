#include <iostream>
#include "CMenuQS.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int iMainMenuInput = 0;
	CMenuQS menuController;
	 
	

	while (iMainMenuInput != QUIT)
	{
		int* piArray = nullptr;
		//system("cls");
		menuController.PrintMainMenu();

		while (!(cin >> iMainMenuInput)) // Validity check to see if User inputed an integer and also taking input in the check
		{
			
			cout << endl;
			cout << "Please input an integer: ";

			// Reset the stream state and clear the buffer
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		switch (iMainMenuInput)
		{
		case FORMATMODE:

			menuController.UpdateFormatMode();
			break;

		case SORT:

			piArray = menuController.ManageInputs();
			menuController.ManageOutputs(piArray);
			break;

		case QUIT:
			break;

		// Default case if an integer <1 or >3 is entered
		default:

			cout << endl;
			cout << "Please input a valid integer(1-3)" << endl;
			cout << endl;
			system("pause");

			// Reset the stream state and clear the buffer in case of multiple inputs
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			break;
		}

		if (piArray != nullptr) // Delete Array if it exists so that when new array is created there is no old array lost in memory by overwritting the pointer
		{
			delete[] piArray;
			piArray = nullptr;
		}
	}

	

	return (0);
}