#pragma once

class Lifeform
{
//		Constructor Dependant Declarations		//
private:
	static bool const DEF_ALIVE = true;		// default alive state
	static int const DEF_HEALTH = 10;		// default health values
	static int const DEF_MANA = 4;			// default mana values

//		Constructors		//
public:
	Lifeform(bool l_alive = DEF_ALIVE, int l_health = DEF_HEALTH, int l_mana = DEF_MANA);
//		Functions		//

	// Get functions
	bool getAlive() const;
	int getMaxHealth() const;
	int getHealth() const;
	int getMaxMana() const;
	int getMana() const;
	// Set functions
	void setAlive(bool l_alive);
private:
	void checkAlive();
public:
	void damage(int l_damage);

protected:
	// member variables
	bool m_alive;		// True if alive else false
	int m_maxHp;	// largest amount of health possible
	int m_hp;		// number damage it can take before dying
	int m_maxMp;		// largest amount of mana possible
	int m_mp;			// resource expended when spells are cast
};

