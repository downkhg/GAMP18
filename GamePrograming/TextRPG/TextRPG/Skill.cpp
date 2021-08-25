#include "Skill.h"
#include "Player.h"


void Hill::Use(Player& caster, Player& target)
{
	target.GetStatus().nHP += caster.GetStatus().nInt;
}

void Attack::Use(Player& caster, Player& target)
{
	target.GetStatus().nHP -= caster.GetStatus().nStr;
}

void Skill::AddEffect(Effect* effect)
{
	listEffect.push_back(effect);
}

void Skill::Ative(Player& caster, Player& target)
{
	for (int i = 0; listEffect.size(); i++)
		listEffect[i]->Use(caster, target);
}