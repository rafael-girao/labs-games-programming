#pragma once
#include "Lifeform.h"
#include "WeaponAtt.h"
#include "SpellAtt.h"

class Orc :
	protected Lifeform
{
private:
	WeaponAtt::Direction const DEF_DIR = WeaponAtt::Direction::MID;
	WeaponAtt::Weapon const DEF_AXE_WEP = WeaponAtt::Weapon::AXE;
	WeaponAtt::Type const DEF_AXE_TYPE = WeaponAtt::Type::MELEE;
	int const DEF_AXE_DAMAGE = 20;
	WeaponAtt::Weapon const DEF_SWORD_WEP = WeaponAtt::Weapon::SWORD;
	WeaponAtt::Type const DEF_SWORD_TYPE = WeaponAtt::Type::MELEE;
	int const DEF_SWORD_DAMAGE = 15;
	WeaponAtt::Weapon const DEF_WARHAMMER_WEP = WeaponAtt::Weapon::WARHAMMER;
	WeaponAtt::Type const DEF_WARHAMMER_TYPE = WeaponAtt::Type::MELEE;
	int const DEF_WARHAMMER_DAMAGE = 25;
	WeaponAtt::Weapon const DEF_BOW_WEP = WeaponAtt::Weapon::BOW;
	WeaponAtt::Type const DEF_BOW_TYPE = WeaponAtt::Type::RANGED;
	int const DEF_BOW_DAMAGE = 15;
//		Constructors		//
public:
	Orc();
	Orc(int l_health, int l_mana, bool l_alive = true);
//		Functions		//

protected:
	// Weapon attacks
	WeaponAtt wepAxeChop;
	WeaponAtt wepSwordSlice;
	WeaponAtt wepWarhammerSwing;
	WeaponAtt wepBowString;
	// Spell attacks
	SpellAtt splFrostbolt;
	SpellAtt splFireball;
	SpellAtt splAirCone;
	SpellAtt splBoulderCrush;
	
private:
	

};

