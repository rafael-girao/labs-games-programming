#include "Missile.h"

/// <summary>
/// Will flip the boolean of armed true to false (and vice-versa)
/// </summary>
void str::Missile::arm()
{
	if (armed == true)
	{
		armed = false;
	}
	else
	{
		armed = true;
	}
}

/// <summary>
/// Will update the missile's coordinates
/// </summary>
void str::Missile::update()
{
	coordinates.x += static_cast<int>(target.coordinates.x * 0.1f);
	coordinates.y += static_cast<int>(target.coordinates.y * 0.1f);
}

//bool hit(Target lTarget);
/// <summary>
/// Will check if the target is hit
/// </summary>
/// <returns> Returns true if target is hit else false </returns>
bool str::Missile::hitTarget()
{
	bool hitTarget;
	if ( (coordinates.x > target.coordinates.x) && (coordinates.y > target.coordinates.y) )
	{
		hitTarget = true;
	}
	else
	{
		hitTarget = false;
	}
	return hitTarget;
}