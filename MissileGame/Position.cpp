#include "Position.h"
#include <iostream>

/// <summary>
/// Will print the position to the screen
/// </summary>
void str::Position::print()
{
	std::cout << "(" << x << "," << y << ")";
}

//bool compare(Position pos);
/// <summary>
/// Will compare the implicit position with
///  the passed position.
/// </summary>
/// <param name = "pos"> Passed position to be compared to </param>
/// <returns> Returns true if positions are equal else false </returns>
bool str::Position::compare(str::Position pos)
{
	return ((x == pos.x) && (y == pos.y));
}