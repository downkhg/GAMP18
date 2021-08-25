#include "Player.h"
#include <iostream>
#include "ItemManager.h"

using namespace std;

Status::Status(int _hp, int _mp, int _str, int _int, int _def)
{
	nHP = _hp;
	nMP = _mp;
	nStr = _str;
	nInt = _int;
	nDef = _def;
}
void Status::operator+=(const int value)
{
	this->nHP += value;
	this->nMP += value;
	this->nStr += value;
	this->nDef += value;
	this->nInt += value;
}
Status Status::operator+(const Status& status)
{
	Status sResult;
	sResult.nHP = nHP + status.nHP;
	sResult.nMP = nMP + status.nMP;
	sResult.nStr = nStr + status.nStr;
	sResult.nDef = nDef + status.nDef;
	sResult.nInt = nInt + status.nInt;
	return sResult;
}
Status Status::operator-(const Status& status)
{
	Status sResult;
	sResult.nHP = nHP - status.nHP;
	sResult.nMP = nMP - status.nMP;
	sResult.nStr = nStr - status.nStr;
	sResult.nDef = nDef - status.nDef;
	sResult.nInt = nInt - status.nInt;
	return sResult;
}
void Status::Show()
{
	cout << "HP:" << nHP << endl;
	cout << "MP:" << nMP << endl;
	cout << "STR:" << nStr << endl;
	cout << "INT:" << nInt << endl;
	cout << "DEF:" << nDef << endl;
}

Player::Player()
{
	m_listEqument.resize(3);
}

Status& Player::GetStatus()
{
	return m_sStatus;
}

void Player::SetIventory(Item* item)
{
	m_listIventory.push_back(item);
}
Item* Player::GetIventoryIdx(int idx)
{
	return m_listIventory[idx];
}
void Player::DeleteIventory(int idx)
{
	m_listIventory.erase(m_listIventory.begin() + idx);
}

bool Player::UseItem(int idx)
{
	Item* pItem = GetIventoryIdx(idx);

	if (pItem->eItemKind == Item::E_ITEM_KIND::THROW)
		return false;

	int nIdx = pItem->eItemKind;
	m_listEqument[nIdx] = pItem;
	m_sStatus = m_sStatus + pItem->sFuction;
	DeleteIventory(idx);

	return true;
}

void Player::ReleaseEqument(int idx)
{
	Item* pItem = m_listEqument[idx];
	m_sStatus = m_sStatus - pItem->sFuction;
	SetIventory(pItem);
}

void Player::Set(string strName, int _hp, int _mp, int _str, int _int, int _def, int _exp)
{
	m_strName = strName;
	m_sStatus.nHP = _hp;
	m_sStatus.nMP = _mp;
	m_sStatus.nStr = _str;
	m_sStatus.nInt = _int;
	m_sStatus.nDef = _def;
	m_nExp = _exp;
	m_nLv = 1;
}
void Player::Attack(Player& taget)
{
	taget.m_sStatus.nHP -= m_sStatus.nStr - m_sStatus.nDef;
}
void Player::StillItem(Player& taget)
{
	//타겟이 가지고 있는 아이템 중 첫번째 아이템을 뺏어오고,
	//타겟의 경험치를 가져와서 내 경험치에 올린다.
	this->SetIventory(taget.GetIventoryIdx(0));
	taget.DeleteIventory(0);
	this->m_nExp = taget.m_nExp;
}
bool Player::Buy(Player& target, int idx)
{
	Item* item = target.GetIventoryIdx(idx);
	if (item->nGold <= m_nGold)
	{
		SetIventory(item);
		m_nGold -= item->nGold;
		return true;
	}
	return false;
}
void Player::Sell(int idx)
{
	Item* item = GetIventoryIdx(idx);
	DeleteIventory(idx);
	m_nGold += item->nGold;
}
bool Player::LvUp()
{
	//만약 경험치가 100 이상되면, 레벨+1, 모든 능력치 10증가, 경험치 초기화.
	if (m_nExp >= 100)
	{
		m_sStatus += 10;
		m_nLv++;
		m_nExp -= 100;
		return true;
	}
	return false;
}

bool Player::Dead()
{
	if (m_sStatus.nHP <= 0)
		return true;
	return false;
}

void Player::Show()
{
	cout << "######### " << m_strName << "######### " << endl;
	m_sStatus.Show();
	cout << "######### Equment #########" << endl;
	for (int i = 0; i < m_listEqument.size(); i++)
		if (m_listEqument[i])
			cout << i << ":" << m_listEqument[i]->strName << endl;
		else
			cout << i << ": null" << endl;
	cout << "######### Inventory ######### " << endl;
	for (int i = 0; i < m_listIventory.size(); i++)
		cout << i << ":" << m_listIventory[i]->strName << endl;
}