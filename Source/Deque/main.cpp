#include <iostream>
#include "ENUMERATORS.h"
#include "CDeque.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int iOption = 0;
	CDeque dequeOne;

	while (iOption != EDEQUEOPTIONS::EXIT) // Note EXIT != 1
	{
		system("cls");

		cout << "Current Deque:" << endl;
		cout << endl;
		dequeOne.Display();
		cout << endl;
		cout << endl;

		cout << "Options: " << endl;
		cout << endl;
		cout << "1. Enqueue Front" << endl;
		cout << "2. Enqueue Back" << endl;
		cout << "3. Dequeue Front" << endl;
		cout << "4. Dequeue Back" << endl;
		cout << "5. Peek Front" << endl;
		cout << "6. Peek Back" << endl;
		cout << "7. Is Empty?" << endl;
		cout << "8. Size" << endl;
		cout << "9. Exit" << endl;
		cout << endl;

		cout << "Select an option(1-8): ";
		cin >> iOption;
		cout << endl;
		cout << endl;

		if (!cin) // Validity check to see if User inputed an integer
		{
			// Reset the stream state and clear the buffer
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid input: Please input an integer" << endl;
			cout << endl;
			system("pause");

			iOption = 0;
		}
		else
		{
			// Reset the stream state and clear the buffer in case of unintended additional inputs from option selection
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			int iInput;
			int iOutput;

			switch (iOption)
			{
			case ENQUEUE_FRONT:

				system("cls");
				cout << "Enqueue Front" << endl;
				cout << endl;
				cout << "Enter integer to Enqueue at the Front: ";

				while (!(cin >> iInput)) // Validity check to see if User inputed an integer and also taking input in the check
				{
					cout << endl;

					// Reset the stream state and clear the buffer
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					cout << "Invalid input: Please input an integer to Enqueue at the Front: ";
				}

				cout << endl;
				cout << iInput << " Enqueued at Front of the Deque" << endl;
				cout << endl;

				dequeOne.EnqueueFront(iInput);

				cout << "Updated Deque:" << endl;
				dequeOne.Display();
				cout << endl;
				system("pause");

				// Reset the stream state and clear the buffer in case of unintended additional inputs from Enqueue input
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;

			case ENQUEUE_BACK:

				system("cls");
				cout << "Enqueue Back" << endl;
				cout << endl;
				cout << "Enter integer to Enqueue at the Back: ";

				while (!(cin >> iInput))
				{
					cout << endl;

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					cout << "Invalid input: Please input an integer to Enqueue at the Back: ";
				}

				cout << endl;
				cout << iInput << " Enqueued at Back of the Deque" << endl;
				cout << endl;

				dequeOne.EnqueueBack(iInput);

				cout << "Updated Deque:" << endl;
				dequeOne.Display();
				cout << endl;
				system("pause");

				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;

			case DEQUEUE_FRONT:

				system("cls");
				cout << "Dequeue Front" << endl;
				cout << endl;

				// Dequeue returns true if there was an element to dequeue 
				if (dequeOne.DequeueFront(iOutput)) // Passed iOutput by referance to hold value that was Dequeued
				{
					cout << iOutput << " Dequeued from Front of the Deque" << endl;
					cout << endl;
					cout << "Updated Deque:" << endl;
					dequeOne.Display();
					cout << endl;
					system("pause");
				}
				else
				{
					cout << "There are no elements in the Deque; can not Dequeue from Front" << endl;
					cout << endl;
					system("pause");
				}
				break;

			case DEQUEUE_BACK:

				system("cls");
				cout << "Dequeue Back" << endl;
				cout << endl;

				if (dequeOne.DequeueBack(iOutput))
				{
					cout << iOutput << " Dequeued from Back of the Deque" << endl;
					cout << endl;
					cout << "Updated Deque:" << endl;
					dequeOne.Display();
					cout << endl;
					system("pause");
				}
				else
				{
					cout << "There are no elements in the Deque; can not Dequeue from Back" << endl;
					cout << endl;
					system("pause");
				}
				break;

			case PEEK_FRONT:

				system("cls");
				cout << "Peek Front" << endl;
				cout << endl;

				// Peek returns true if there was an element to Peek 
				if (dequeOne.PeekFront(iOutput)) // Passed iOutput by referance to hold value that was Peeked
				{
					cout << iOutput << " Peeked from Front of the Deque" << endl;
					cout << endl;

					// Dont display whole Deque, only the peeked data of the first node
					system("pause");
				}
				else
				{
					cout << "There are no elements in the Deque; can not Peek Front" << endl;
					cout << endl;
					system("pause");
				}
				break;

			case PEEK_BACK:

				system("cls");
				cout << "Peek Back" << endl;
				cout << endl;

				if (dequeOne.PeekBack(iOutput))
				{
					cout << iOutput << " Peeked from Back of the Deque" << endl;
					cout << endl;
					system("pause");
				}
				else
				{
					cout << "There are no elements in the Deque; can not Peek Back" << endl;
					cout << endl;
					system("pause");
				}
				break;

			case IS_EMPTY:

				system("cls");
				cout << "Is Empty?" << endl;
				cout << endl;

				if (dequeOne.IsEmpty())
				{
					cout << "True" << endl;
					cout << "The Deque is empty!" << endl;
				}
				else
				{
					cout << "False" << endl;
					cout << "The Deque is not empty!" << endl;
				}
				cout << endl;
				system("pause");
				break;

			case SIZE:

				system("cls");
				cout << "Size" << endl;
				cout << endl;
				cout << "The Deque has " << dequeOne.Size() << " element(s)." << endl;
				cout << endl;
				system("pause");
				break;

			case EXIT:

				// Do nothing, will exit while loop and allow main function to return
				break;

			default:
				
				// User entered an integer <1 or >8
				cout << "Please enter a valid integer within the range(1-8)" << endl;
				cout << endl;
				system("pause");

				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
		}
	}

	return (0);
}

