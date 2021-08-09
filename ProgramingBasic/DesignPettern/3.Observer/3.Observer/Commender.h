#pragma once
#include  <iostream>
#include  <list>
#include <vector>
class Unit; //클래스의 선언

using namespace std;


class Unit //클래스의 정의
{
	int x;
	int y;
public:
	virtual void Move(int x, int y) = 0;
	virtual void Attack(int x, int y) = 0;
};

class Marin : public Unit
{
public:
	Marin();
	~Marin();
	void Move(int x, int y) override;
	void Attack(int, int y) override;
private:

};

class Medic : public Unit
{
public:
	Medic();
	~Medic();
	void Move(int x, int y) override;
	void Attack(int, int y) override;
private:

};

class Commonder
{
	list<Unit*> listUnitCollection;
public:
	void SelectUnit(Unit* pUnit)
	{
		listUnitCollection.push_back(pUnit);
	}
	void Deselect(Unit* pUnit)
	{
		listUnitCollection.remove(pUnit);
	}
	void Move(int x, int y);
	void Attack(int x, int y);
};
