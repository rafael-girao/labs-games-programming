#pragma once
#include "Attack.h"
class SpellAtt :
	Attack
{
public:
	enum class AreaOfEffect { BOLT, CIRCLE, CONE };
	enum class Range { LOW, MEDIUM, LONG };
	enum class Element { FIRE, FROST, ELECTRIC, AIR, EARTH };
	static Element const DEF_ELEMENT = Element::FIRE;
	static Range const DEF_RANGE = Range::MEDIUM;
	static AreaOfEffect const DEF_AOE = AreaOfEffect::BOLT;
	static int const DEF_MP_COST = 1;
	static int const DEF_DAMAGE = 10;
//		Constructors		//
	SpellAtt(Element l_element = DEF_ELEMENT, Range l_range = DEF_RANGE, AreaOfEffect l_AoE = DEF_AOE, int l_mpCost = DEF_MP_COST, int l_damage = DEF_DAMAGE);
	/// <summary>
	/// Overloaded Constructor:
	///	Creates a null spell to be set
	/// </summary>
	/// <param name = "l_creator"> Defines who created the spell </param>
	SpellAtt(Lifeform const &l_creator);
	/// <summary>
	/// Overloaded Constructor:
	///	Defines the spell attack using the passed arguments
	/// </summary>
	/// <param name = "l_element"> Defines what element the spell uses </param>
	/// <param name = "l_range"> Defines the max range of the spell </param>
	/// <param name = "l_AoE"> Defines the area of effect of the spell </param>
	/// <param name = "l_creator"> Defines the creator of the spell (will create pointer to creator) </param>
	/// <param name = "l_type"> Defines the type of spell </param>
	/// <param name = "l_damage"> Defines the amount of damage the spell does </param>
	SpellAtt(Element l_element, Range l_range, AreaOfEffect l_AoE, int l_mpCost, Lifeform &l_creator, int l_damage);
//		Functions		//
	/// <summary>
	/// Function Override:
	///	Will attempt to target Lifeform while checking the distance between the two
	/// Note if m_target is equal to nullptr, targeting has missed
	/// </summary>
	/// <param name = "l_target"> Will define the creator </param>
	void target(Lifeform &l_target);

private:
//		Member Variables		//
	int m_mpCost;
	Element m_element;
	Range m_range;
	AreaOfEffect m_AoE;
};

