#pragma once
#include "Attack.h"
class WeaponAtt : public Attack
{
public:
	enum class Weapon { AXE, SWORD, CLUB, WARHAMMER, CLAYMORE, BOW, CROSSBOW, SLING }; // Kind of weapon used
	enum class Direction { UP, MID, LOW }; // Attack Direction
	static Weapon const DEF_WEAPON = Weapon::AXE;
	static Direction const DEF_DIRECTION = Direction::MID;
	/// <summary>
	/// Default Constructor:
	///	Will create a attack with defaulted values
	/// </summary>
	WeaponAtt(Weapon l_weapon = DEF_WEAPON, Direction l_direction = DEF_DIRECTION, Type l_type = DEF_TYPE, int l_damage = DEF_DAMAGE);
	/// <summary>
	/// Default Constructor:
	///	Will construct a weapon attack needing only the creator to be passed
	/// </summary>
	/// <param name = "l_creator"> Defines who is using the attack </param>
	WeaponAtt(Lifeform const &l_creator);
	/// <summary>
	/// Overloaded Constructor:
	///	Used to initialize the weapon attacks parameters
	/// </summary>
	/// <param name = "l_weapon"> Defines the weapon used in the attack </param>
	/// <param name = "l_direction"> Defines the direction of the attack </param>
	/// <param name = "l_creator"> Defines the creator of this attack </param>
	/// <param name = "l_type"> Defines the type of attack (melee, ranged) </param>
	/// <param name = "l_damage"> Defines the amount of damage of the attack </param>
	WeaponAtt(Weapon l_weapon, Direction l_direction, Lifeform &l_creator, Type l_type, int l_damage);
	void target(Lifeform & l_target);
private:
	Weapon m_weapon;
	Direction m_direction;
};

