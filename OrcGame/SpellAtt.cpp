#include "SpellAtt.h"

SpellAtt::SpellAtt(Element l_element, Range l_range, AreaOfEffect l_AoE, int l_mpCost, int l_damage) :
	Attack(Type::RANGED, l_damage),
	m_element(l_element),
	m_range(l_range),
	m_AoE(l_AoE),
	m_mpCost(l_mpCost)
{
}

SpellAtt::SpellAtt(Lifeform const &l_creator) :
	Attack(l_creator)
{
}

SpellAtt::SpellAtt(Element l_element, Range l_range, AreaOfEffect l_AoE, int l_mpCost, Lifeform &l_creator, int l_damage) :
	Attack(l_creator, Type::RANGED, l_damage),
	m_mpCost(l_mpCost),
	m_element(l_element),
	m_range(l_range),
	m_AoE(l_AoE)
{
}

void SpellAtt::target(Lifeform & l_target)
{
	Attack::target(l_target);
	if (m_target->getAlive() == true &&
		m_target->getMana() >= m_mpCost)
	{
		switch (m_range)
		{
		case SpellAtt::Range::LOW:
			switch (m_AoE)
			{
			case SpellAtt::AreaOfEffect::CONE:
				m_target->damage(m_damage);
				break;
			case SpellAtt::AreaOfEffect::CIRCLE:
				m_target->damage(m_damage);
				m_creator->damage(m_damage);
				break;
			case SpellAtt::AreaOfEffect::BOLT:
			default:
				m_target = nullptr;
				break;
			}
			break;
		case SpellAtt::Range::MEDIUM:
			switch (m_AoE)
			{
			case SpellAtt::AreaOfEffect::BOLT:
			case SpellAtt::AreaOfEffect::CIRCLE:
			case SpellAtt::AreaOfEffect::CONE:
				m_target->damage(m_damage);
				break;
			default:
				m_target = nullptr;
				break;
			}
			break;
		case SpellAtt::Range::LONG:
			switch (m_AoE)
			{
			case SpellAtt::AreaOfEffect::BOLT:
			case SpellAtt::AreaOfEffect::CIRCLE:
				m_target->damage(m_damage);
				break;
			case SpellAtt::AreaOfEffect::CONE:
			default:
				m_target = nullptr;
				break;
			}
			break;
		default:
			m_target = nullptr;
			break;
		}
	}
	else
	{
		m_target = nullptr;
	}
}
