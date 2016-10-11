#include "Attack.h"

Attack::Attack(Type l_type, int l_damage) :
	m_creator(nullptr),
	m_target(nullptr),
	m_damage(l_damage),
	m_type(l_type)
{
}

Attack::Attack(Lifeform const &l_creator) :
	m_target(nullptr),
	m_damage(DEF_DAMAGE),
	m_type(DEF_TYPE)
{
	*(m_creator) = l_creator;
}


Attack::Attack(Lifeform const &l_creator, Type l_type, int l_damage) :
	m_target(nullptr),
	m_damage(l_damage),
	m_type(l_type)
{
	*(m_creator) = l_creator;
}

/// <summary>
/// Will set the a pointer to the passed Lifeform, as the target for the attack
/// </summary>
/// <param name = "l_target"> Defines the target of which the attack will apply to </param>
void Attack::target(Lifeform &l_target)
{
	*(m_target) = l_target;
}