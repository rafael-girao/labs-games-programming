#pragma once

namespace str
{
	typedef struct Position
	{
		// member variables
		int x;
		int y;
		// member functions
		void print();
		bool compare(Position pos);
	}Coordinates;
}