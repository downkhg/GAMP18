#pragma once
#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

class Item {
public:
	enum E_ITEM_KIND { WEAPON, ARMOR, ACC, POTION, THROW };
	E_ITEM_KIND eItemKind;
	string strName;
	string strComment;
	Status sFuction;
	int nGold;
	Item(E_ITEM_KIND kind = THROW, string name = "none", string comment = "none", Status status = Status(), int gold = 0);
	void Set(E_ITEM_KIND kind, string name, string comment, Status status, int gold);
};

class ItemManager {
	vector<Item> m_listItems;
public:
	enum E_ITEM_LIST { WOOD_SOWRD, BONE_SOWRD, WOOD_ARMOR, BONE_AMROR, WOOD_RING, BONE_RING, HP_POTION, MP_POTION, STONE, BOOM };
	ItemManager();

	void SaveFile();

	void LoadFile();
	Item* GetItem(int idx);
};