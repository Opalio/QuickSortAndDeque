Oliver Webb-Speight
MDS00002OF
06/04/2022

Deque:
	Has Main Menu; program will return here after each operation is complete and will not terminate
	program until exit option is chosen
	Current Deque is always displayed above the menu
		Main menu choices are
		Enqueue Front
			Prompts User to enter value to input, Enqueues at Front, displays Deque then returns to main menu
		Enqueue Back
			Prompts User to enter value to input, Enqueues at Back, displays Deque then returns to main menu
		Dequeue Front
			Checks if anything to Deque and gives feedback if there is nothing
			Dequeues from Front, displays Dequeued Value, displays Deque then returns to main menu
		Dequeue Back
			Checks if anything to Deque and gives feedback if there is nothing
			Dequeues from Back, displays Dequeued Value, displays Deque then returns to main menu
		Peek Front
			Checks if anything to Peek and gives feedback if there is nothing
			Displays value Peeked at Front, then returns to main menu
		Peek Back
			Checks if anything to Peek and gives feedback if there is nothing
			Displays value Peeked at Back, then returns to main menu
		Is Empty
			Gives Feedback on if the Deque is empty or not and returns to main menu
		Size
			Gives Feedback on how many Elements there are in the Deque and returns to main menu
		Exit
			Quits the main menu and allows program to terminate

QuickSort
	Has Main Menu; program will return here after each operation is complete and will not terminate
	program until exit option is chosen
	The current input/output format is displayed above main menu options
		Main menu choices are
		I/O Format Options
			Prompts User to choose a format option out of
			Console In/Console Out
			Console In/File Out
			File In/Console Out
			File In/File Out
			Then returns to main menu
		QuickSort
			Behaves differently depending on format option
				Console In/Console Out
					Requests input from user through console inputs then outputs to the console
				Console In/File Out
					Requests input from user through console inputs then outputs to Output.txt
				File In/Console Out
					Requests input from user via Input.txt then outputs to the console
				File In/File Out
					Requests input from user via Input.txt then outputs to Output.txt
			Then returns to main menu
		Quit
			Allows program to leave main menu and terminate

Both programs have full validaty checks for all inputs; not allowing any unwanted datatypes or values outside
of accepted ranges; and will deal with accidental additional inputs
