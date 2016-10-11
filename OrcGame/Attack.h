#pragma once
#include "Lifeform.h"

class Attack
{
public:
//		Constructor Dependant Declarations		//
	// Defines the type of attack
	enum class Type { MELEE, RANGED };
	static int const DEF_DAMAGE = 1;
	static Type const DEF_TYPE = Type::MELEE;
//		Constructors		//
	/// <summary>
	/// Default Constructor:
	///	Will construct a Attack with defaulted arguments
	/// </summary>
	/// <param name = "l_type"> Defines the type of attack (melee, ranged) </param>
	/// <param name = "l_damage"> Defines the amount of damage of the attack </param>
	Attack(Type l_type = DEF_TYPE, int l_damage = DEF_DAMAGE);
	/// <summary>
	/// Overloaded Constructor:
	///	Will construct a Attack object
	/// </summary>
	/// <param name = "l_creator"> Defines who created the attack object </param>
	Attack(Lifeform const &l_creator);
	/// <summary>
	/// Overloaded Constructor:
	///	Will create a Attack object using the passed arguments
	/// </summary>
	/// <param name = "l_creator"> Defines who created the attack object </param>
	/// <param name = "l_type"> Defines the type of attack using Attack::Type (MELEE, RANGED) </param>
	/// <param name = "l_damage"> Defines the amount of damage the attack will inflict </param>
	Attack(Lifeform const &l_creator, Type l_type, int l_damage = DEF_DAMAGE);
//		Functions		//
	void target(Lifeform &l_target);

protected:
//		Variables		//
	Lifeform * m_creator;
	Lifeform * m_target;
	int m_damage;
	Type m_type;
};

