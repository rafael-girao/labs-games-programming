/// <summary>
/// @mainpage Text-based Missile Game
/// @Author Rafael Girao
/// @Version 1.0
/// @brief Program will run a text-based missile game
///
///	This exercise will help us learn about structures and
///  legacy c-style programming
///
/// Time Spent:
///		28th/09/2016 15:00 60min (1hr)
///		01st/10/2016 17:00 180min (3hr)
///
/// Total Time Taken:
///		4hr 00min
/// </summary>

#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include "Missile.h"

void typeTitle(const std::string l_Title[], const int l_TitleSize);
void clearScreen();
void debugPause();
void newLine();
str::WarHead selectWarhead(const int * pUserInput);
void waitingDot(const int l_WaitTime, const int l_AmountDots);
bool checkLaunchCode(str::Missile * pMissileToBeArmed, const int * pUserInput);

const int TITLE_SIZE = 8;
const std::string TITLE[TITLE_SIZE] =
{
	" __  __ _         _ _         _____",
	"|  \\/  (_)       (_) |       / ____|",
	"| \\  / |_ ___ ___ _| | ___  | |  __  __ _ _ __ ___   ___ ",
	"| |\\/| | / __/ __| | |/ _ \\ | | |_ |/ _` | '_ ` _ \\ / _ \\",
	"| |  | | \\__ \\__ \\ | |  __/ | |__| | (_| | | | | | |  __/",
	"|_|  |_|_|___/___/_|_|\\___|  \\_____|\\__,_|_| |_| |_|\\___|"
};
const int TARGET_OFFSET_Y = 10;
const int TARGET_OFFSET_X = 5;
const int WARHEAD_WAIT_TIME = 500;			// this is per dot
const int WARHEAD_DOTS = 10;				// this is the amount of dots
const int TARGET_COORDS_WAIT_TIME = 250;	// this is per dot
const int TARGET_COORDS_DOTS = 20;			// this is the amount of dots
const int LAUNCH_CODE = 123;
const int LAUNCH_CODES_WAIT_TIME = 800;		// this is per dot
const int LAUNCH_CODES_DOTS = 5;			// this is the amount of dots
const int ARM_WAIT_TIME = 200;				// this is per dot
const int ARM_DOTS = 20;					// this is the amount of dots

int main()
{
	int userInput = 0;
	bool collided = false;
	bool targetMiss;
	str::Missile missile;
	str::Enemy mexicans;

	clearScreen();

	// Select War Head
	typeTitle(TITLE, TITLE_SIZE);
	newLine();

	std::cout << "Please select a warhead:\n";
	std::cout << " 1 - Explosive Warhead\n";
	std::cout << " 2 - Nuclear Warhead\n";
	newLine();
	std::cout << "Option: ";
	std::cin >> userInput;
	missile.payload = selectWarhead(&userInput);
	newLine();

	std::cout << "  LOADING WARHEAD\n";
	waitingDot(WARHEAD_WAIT_TIME, WARHEAD_DOTS);
	std::cout << "\n  WARHEAD LOADED";
	
	newLine();
	debugPause();

	clearScreen();

	// Acquire Target
	typeTitle(TITLE, TITLE_SIZE);
	newLine();

	std::cout << "Please set the target coordinates:\n";
	newLine();
	std::cout << "Enter X-coordinate: ";
	std::cin >> userInput;
	missile.target.coordinates.x = userInput;
	mexicans.coordinates.x = userInput + TARGET_OFFSET_X;
	missile.coordinates.x = 0;
	std::cout << "Enter Y-coordinate: ";
	std::cin >> userInput;
	missile.target.coordinates.y = userInput;
	mexicans.coordinates.y = userInput + TARGET_OFFSET_Y;
	missile.coordinates.y = 0;
	newLine();
	std::cout << "  SETTING TARGET COORDINATES\n";
	waitingDot(TARGET_COORDS_WAIT_TIME, TARGET_COORDS_DOTS);
	std::cout << "\n  TARGET COORDINATES SET";

	newLine();
	debugPause();

	clearScreen();

	// Launch Code
	typeTitle(TITLE, TITLE_SIZE);
	newLine();

	std::cout << "Please enter the launch codes:\n";
	newLine();
	std::cout << "Launch code: ";
	std::cin >> userInput;
	
	newLine();
	std::cout << "  CHECKING LAUNCH CODES\n";
	waitingDot(LAUNCH_CODES_WAIT_TIME, LAUNCH_CODES_DOTS);
	std::cout << "\n  LAUNCH CODES CHECKED\n";
	newLine();

	if (checkLaunchCode(&missile, &userInput))
	{
		std::cout << "Launch codes are correct" << std::endl;
		newLine();
	}
	else
	{
		std::cout << "Launch codes are incorrect\n";
		std::cout << "\nALARM TRIGGERED !\n";
		std::cout << "SHUTTING DOWN";
		Sleep(3000);
		exit(0); // PROGRAM EXITS IF THIS LINE IS EXECUTED
	}

	// Arm Missile
	std::cout << "Welcome Sir Trump arming missile now\n";
	newLine();
	std::cout << "  MISSILE ARMING\n";
	waitingDot(ARM_WAIT_TIME, ARM_DOTS);
	std::cout << "\n  MISSILE ARMED\n";

	newLine();
	debugPause();

	clearScreen();

	// Collision
	typeTitle(TITLE, TITLE_SIZE);
	newLine();

	while (collided == false)
	{
		int previousCoordX = missile.coordinates.x;
		int previousCoordY = missile.coordinates.y;
		targetMiss = false;
		missile.update();

		if (missile.hitTarget() == true)
		{
			newLine();
			std::cout << "TARGET HAS BEEN HIT\n";
			float predictedCasualties = 4.0f;
			if (missile.payload == str::WarHead::EXPLOSIVE)
			{
				predictedCasualties *= 1000.0f;
				std::cout << " CASUALTIES: " << predictedCasualties << " dead" << std::endl;
			}
			else
			{
				predictedCasualties *= 100000.0f;
				std::cout << " CASUALTIES: " << predictedCasualties << " dead" << std::endl;
			}
			collided = true;
		}
		else if ( (previousCoordX == missile.coordinates.x) || (previousCoordY == missile.coordinates.y) )
		{
			newLine();
			std::cout << "TARGET MISSED\n";
			collided = true;
			targetMiss = true;
		}
		else
		{
			std::cout << "Missile Location: ";
			missile.coordinates.print();
			newLine();
			std::cout << "Target Location: ";
			missile.target.coordinates.print();
			newLine();
			Sleep(100);
		}
	}

	if (targetMiss == false)
	{
		switch (missile.payload)
		{
		case str::WarHead::EXPLOSIVE:
			std::cout << "I love the smell of napalm in the morning";
			break;
		case str::WarHead::NUCLEAR:
			std::cout << "I love the smell of radioactive napalm in the morning";
			break;
		default:
			break;
		}
		newLine();
		std::cout << "MISSION COMPLETE !\n" << std::endl;
	}
	else
	{
		newLine();
		std::cout << "MISSION FAILED !\n" << std::endl;
	}
	
	std::cout << "Leaving";
	waitingDot(2000, 5);
}


/// <summary>
/// Will itterate through the title string to type it on the screen,
///  leaving a new line after each array element
/// </summary>
/// <param name = "l_Title"> string title array to be displayed </param>
/// <param name = "l_TitleSize"> represents the size of the string title array </param>
void typeTitle(const std::string l_Title[], const int l_TitleSize)
{
	for (int i = 0; i < l_TitleSize; i++)
	{
		std::cout << l_Title[i] << "\n";
	}
	std::cout << std::endl;
}

/// <summary>
/// Enters numerous blanklines making it appear as if the screen was cleared
/// </summary>
void clearScreen()
{
	const int BlankLines = 400;
	for (int i = 1; i < BlankLines; i++)
	{
		std::cout << "\n";
	}
	std::cout << std::endl;
}

/// <summary>
/// Will pause the console asking to press any key to continue
/// </summary>
void debugPause()
{
	std::cout << "\n" << std::endl;
	std::system("PAUSE");
}

/// <summary>
/// Will enter a blank new line
/// </summary>
void newLine()
{
	std::cout << std::endl;
}

/// <summary>
/// Will check the user's input and return the appropriately selected warhead
/// </summary>
/// <param name = "pUserInput"> address of users selection (should be 1 or 2) </param>
/// <returns> returns the warhead that the user selected </returns>
str::WarHead selectWarhead(const int * pUserInput)
{
	str::WarHead selectedWarhead;
	switch (*(pUserInput))
	{
	case 2:
		selectedWarhead = str::WarHead::NUCLEAR;
		break;
	case 1:
	default:
		selectedWarhead = str::WarHead::EXPLOSIVE;
		break;
	}
	return selectedWarhead;
}

/// <summary>
/// Will type a waiting dot, with a timed delay,
///  with a set amount of dots
/// </summary>
/// <param name = "l_WaitTime"> Passed integer that defines the delay on the dot </param>
/// <param name = "l_AmountDots"> Passed integer that defines how many delayed dots will appear </param>
void waitingDot(const int l_WaitTime, const int l_AmountDots)
{
	for (int i = 0; i < l_AmountDots; i++)
	{
		Sleep(l_WaitTime); std::cout << ".";
	}
}

/// <summary>
/// Will check if the launch code entered is correct 
/// </summary>
/// <param name = "pMissileToBeArmed"> Address of the missile to be armed </param>
/// <param name = "pUserInput"> Launch code entered </param>
/// <returns> Returns whether or not the correct launch codes were entered </returns>
bool checkLaunchCode(str::Missile * pMissileToBeArmed, const int * pUserInput)
{
	bool correctCodes;
	if (*(pUserInput) == LAUNCH_CODE)
	{
		pMissileToBeArmed->armed = true;
		correctCodes = true;
	}
	else
	{
		correctCodes = false;
	}
	return correctCodes;
}