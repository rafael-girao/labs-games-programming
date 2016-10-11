#include "Lifeform.h"


/// <summary>
/// OVERLOADED CONSTRUCTOR:
///		Will create a lifeform based on the passed arguments
/// </summary>
/// <param name = "l_alive"> Will set whether or not the lifeform is alive </param>
/// <param name = "l_health"> Will set the amount of health </param>
/// <param name = "l_mana"> Will set the amount of mana </param>
Lifeform::Lifeform(bool l_alive, int l_health, int l_mana) :
	m_alive(l_alive),
	m_maxHp(l_health),
	m_hp(l_health),
	m_maxMp(l_mana),
	m_mp(l_mana)
{
}

/// <summary>
/// Get Function:
///		Will get whether the lifeform is alive (true) or dead (false)
/// </summary>
/// <returns> Returns true if the lifeform is alive or else false </returns>
bool Lifeform::getAlive() const
{
	return m_alive;
}

/// <summary>
/// Get Function:
///	Will get the lifeform's maximum health value
/// </summary>
/// <returns> Returns as a integer the maximum health of the lifeform </returns>
int Lifeform::getMaxHealth() const
{
	return m_maxHp;
}

/// <summary>
/// Get Function:
///	Will get the lifeform's current health value
/// </summary>
/// <returns> Returns a integer as the lifeform's health </returns>
int Lifeform::getHealth() const
{
	return m_hp;
}

/// <summary>
/// Get Function:
///	Will get the maximum mana value of the lifeform
/// </summary>
/// <returns> Returns as a integer as the maximum mana </returns>
int Lifeform::getMaxMana() const
{
	return m_maxMp;
}

/// <summary>
/// Get Function:
///	Will get the lifeform's current mana value
/// </summary>
/// <returns> Returns as a integer the current mana of the lifeform </returns>
int Lifeform::getMana() const
{
	return m_mp;
}

/// <summary>
///	Set Function:
///		Will set the lifeforms alive var based on the passed bool
/// </summary>
/// <param name = "l_alive"> Defines the lifeforms alive(true) or dead(false) </param>
void Lifeform::setAlive(bool l_alive)
{
	m_alive = l_alive;
}

/// <summary>
/// Will check if the lifeform is still alive by checking if health is the same or below zero
/// </summary>
void Lifeform::checkAlive()
{
	if (m_alive == true)
	{
		setAlive(m_hp <= 0);
	}
}

/// <summary>
/// Will damage the implicit lifeform using the passed argument
/// and the lifeform's health is checked
/// </summary>
/// <param name = "l_damage"> Defines the amount of damage to the health of the lifeform </param>
void Lifeform::damage(int l_damage)
{
	m_hp -= l_damage;
	checkAlive();
}
