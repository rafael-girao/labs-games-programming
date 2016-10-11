#include "WeaponAtt.h"


WeaponAtt::WeaponAtt(
	Weapon l_weapon, Direction l_direction, Type l_type, int l_damage) :
	Attack(l_type, l_damage),
	m_weapon(l_weapon),
	m_direction(l_direction)
{
}

WeaponAtt::WeaponAtt(Lifeform const &l_creator) :
	Attack(l_creator)
{
	*(m_creator) = l_creator;
}

/// <summary>
/// Overloaded Constructor:
///	Used to initialize the weapon attacks parameters
/// </summary>
/// <param name = "l_weapon"> Defines the weapon used in the attack </param>
/// <param name = "l_direction"> Defines the direction of the attack </param>
/// <param name = "l_creator"> Defines the creator of this attack </param>
/// <param name = "l_type"> Defines the type of attack (melee, ranged) </param>
/// <param name = "l_damage"> Defines the amount of damage of the attack </param>
WeaponAtt::WeaponAtt(Weapon l_weapon, Direction l_direction, Lifeform &l_creator, Type l_type, int l_damage) :
	Attack(l_creator, l_type, l_damage),
	m_weapon(l_weapon),
	m_direction(l_direction)
{
}

/// <summary>
/// Override Function:
///	Will aim weapon at target and attempt to damage it,
/// Note if m_target is nullptr attack missed
/// </summary>
void WeaponAtt::target(Lifeform & l_target)
{
	Attack::target(l_target);
	if (m_target->getAlive() == true)
	{
		switch (m_type)
		{
		case Attack::Type::MELEE:
			switch (m_weapon)
			{
			case WeaponAtt::Weapon::AXE:
			case WeaponAtt::Weapon::SWORD:
			case WeaponAtt::Weapon::CLUB:
			case WeaponAtt::Weapon::WARHAMMER:
			case WeaponAtt::Weapon::CLAYMORE:
				m_target->damage(m_damage);
				break;
			case WeaponAtt::Weapon::BOW:
			case WeaponAtt::Weapon::CROSSBOW:
			case WeaponAtt::Weapon::SLING:
			default:
				m_target = nullptr;
				break;
			}
			break;
		case Attack::Type::RANGED:
			switch (m_weapon)
			{
			case WeaponAtt::Weapon::BOW:
			case WeaponAtt::Weapon::CROSSBOW:
			case WeaponAtt::Weapon::SLING:
				m_target->damage(m_damage);
				break;
			case WeaponAtt::Weapon::AXE:
			case WeaponAtt::Weapon::SWORD:
			case WeaponAtt::Weapon::CLUB:
			case WeaponAtt::Weapon::WARHAMMER:
			case WeaponAtt::Weapon::CLAYMORE:
			default:
				m_target = nullptr;
				break;
			}
			break;
		default:
			break;
		}
	}
	else
	{
		m_target = nullptr;
	}
}

