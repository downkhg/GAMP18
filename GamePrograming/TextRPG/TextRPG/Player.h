#pragma once
#include <iostream>
#include <vector>
#include <string>

class Item;
class Skill;

using namespace std;

struct Status {
	int nHP;
	int nMP;
	int nStr;
	int nInt;
	int nDef;

	Status(int _hp = 0, int _mp = 0, int _str = 0, int _int = 0, int _def = 0);
	void operator+=(const int value);
	Status operator+(const Status& status);
	Status operator-(const Status& status);
	void Show();
};

class Player {
	string m_strName;
	Status m_sStatus;
	int m_nLv;
	int m_nExp;
	int m_nGold;

	vector<Item*> m_listIventory;
	vector<Item*> m_listEqument;
	vector<Skill*> m_listSkills;
public:
	Player();

	Status& GetStatus();

	void SetIventory(Item* item);
	Item* GetIventoryIdx(int idx);
	void DeleteIventory(int idx);

	bool UseItem(int idx);

	void ReleaseEqument(int idx);

	void Set(string strName, int _hp, int _mp, int _str, int _int, int _def, int _exp);
	void Attack(Player& taget);
	void StillItem(Player& taget);
	bool Buy(Player& target, int idx);
	void Sell(int idx);
	bool LvUp();

	bool Dead();

	void Show();
};