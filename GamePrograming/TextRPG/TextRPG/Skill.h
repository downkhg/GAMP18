#pragma once

#include <vector>

using namespace std;

struct Player;

class Effect
{
public:
	virtual void Use(Player& caster, Player& target) = 0;
};

class Hill : public Effect
{
public:
	void Use(Player& caster, Player& target);
};

class Attack : public Effect
{
public:
	void Use(Player& caster, Player& target);
};

class Skill
{
public:
	vector<Effect*> listEffect;
	void AddEffect(Effect* effect);
	virtual void Ative(Player& caster, Player& Target) = 0;
};

class HoliAttack : public Skill
{
	void Ative(Player& caster, Player& target);
};

class EffectHill : public Skill
{
	void Ative(Player& caster, Player& Target);
};