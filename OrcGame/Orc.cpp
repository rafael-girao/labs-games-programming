#include "Orc.h"

Orc::Orc() :
	Lifeform(),
	wepAxeChop(this),
	wepSwordSlice(this),
	wepWarhammerSwing(this),
	wepBowString(this),
	splFrostbolt(this),
	splFireball(this),
	splAirCone(this),
	splBoulderCrush(this)
{
}

Orc::Orc(int l_health, int l_mana, bool l_alive) :
	Lifeform(l_alive, l_health, l_mana),
	wepAxeChop(DEF_AXE_WEP, DEF_DIR, static_cast<Lifeform>(this), DEF_AXE_TYPE, DEF_AXE_DAMAGE),
	wepSwordSlice(DEF_SWORD_WEP, DEF_DIR, static_cast<Lifeform>(this), DEF_SWORD_TYPE, DEF_SWORD_DAMAGE),
	wepWarhammerSwing(DEF_WARHAMMER_WEP, DEF_DIR, static_cast<Lifeform>(this), DEF_WARHAMMER_TYPE, DEF_WARHAMMER_DAMAGE),
	wepBowString(DEF_BOW_WEP, DEF_DIR, static_cast<Lifeform>(this), DEF_BOW_TYPE, DEF_BOW_DAMAGE),
	splFrostbolt(this),
	splFireball(this),
	splAirCone(this),
	splBoulderCrush(this)
{
}
