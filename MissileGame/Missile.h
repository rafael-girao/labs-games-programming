#pragma once
#include "Enemy.h"
#include "Position.h"

namespace str
{
	enum class WarHead
	{
		EXPLOSIVE, NUCLEAR
	};

	struct Missile
	{
		// Member variables
		WarHead payload;
		Coordinates coordinates;
		Target target;
		bool armed;
		
		// Member functions
		void arm();
		void update();
		bool hitTarget();
	};
}