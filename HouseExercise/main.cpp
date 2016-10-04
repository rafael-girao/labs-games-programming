/// <summary>
/// @mainpage Phillip's House Exercise
/// @Author Rafael Girao
/// @Version 1.4 (had to redo it 3 times due to how confusing the question was)
/// @brief Program will display a 2D array as a house
///		and will rotate it 90, 180 and 45 degrees
///
/// Time Spent:
///		20th/09/2016 19:00 120min	(02hr)
///		21st/09/2016 18:00 240min	(04hr)
///		22nd/09/2016 12:00 180min	(03hr)
///		23rd/09/2016 14:00 360min	(06hr)
///		24th/09/2016 15:00 540min	(09hr)
///		25th/09/2016 14:00 60min	(01hr)
///
/// Total Time Taken:
///		25hr 00min
/// </summary>

#include <iostream>
#include "house.h"

void display(House * pHouse);
void clearScreen();
void handleInput(unsigned short int input, House * pHouse, bool * pExitProgram);

int main()
{
	House myHouse = House::House();

	bool exitProgram = false;
	unsigned short int userInput;

	while (exitProgram == false)
	{
		clearScreen();
		std::cout << "\tMATRIX:\n" << std::endl;

		display(&myHouse);

		std::cout << "\n\n";
		std::cout << "Enter a value for the following options:\n";
		std::cout << "\t0 - exit program\n";
		std::cout << "\t1 - construct X\n";
		std::cout << "\t2 - construct House\n";
		std::cout << "\t3 - rotate 90\n";
		std::cout << "\t4 - rotate 180\n";
		std::cout << "\t5 - rotate 45\n" << std::endl;
		std::cout << "Option: ";
		std::cin >> userInput;
		std::cout << std::endl;
		
		handleInput(userInput, &myHouse, &exitProgram);
	}
}

/// <summary>
/// Will display the house to the console,
///  through the use of a pointer
/// </summary>
/// <param name = "pHouse">Will hold memory location of House variable</param>
void display(House * pHouse)
{
	const int * width = (pHouse->getWidth());
	const int * height = (pHouse->getHeight());
	int value = 0;

	for (int r = 0; r < *(height); r++)
	{
		std::cout << "\t\t";
		for (int c = 0; c < *(width); c++)
		{
			value = pHouse->getHouse()[r][c];
			std::cout << value;
		}
		std::cout << std::endl;
	}
}

/// <summary>
/// Will enter a loop and enter empty lines,
///  until the entire console screen is emptied
/// </summary>
void clearScreen()
{
	const int EmptySpaces = 400;
	for (int i = 1; i < EmptySpaces; i++)
	{
		std::cout << "\n";
	}
	std::cout << std::endl;
}

/// <summary>
/// Will handle the users input through a switch statement
/// </summary>
/// <param name = "input"> the integer that the user typed in </param>
/// <param name = "pHouse"> a memory address to the passed House variable </param>
/// <param name = "pExitProgram"> a memory address to the passed bool </param>
void handleInput(unsigned short int input, House * pHouse, bool * pExitProgram)
{
	switch (input)
	{
	case 5:
		pHouse->rotate45();
		break;
	case 4:
		pHouse->rotate180();
		break;
	case 3:
		pHouse->rotate90();
		break;
	case 2:
		pHouse->constructHouse();
		break;
	case 1:
		pHouse->constructX();
		break;
	case 0:
		*pExitProgram = true;
		break;
	default:
		break;
	}
}