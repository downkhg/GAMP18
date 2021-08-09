#include  <iostream>
#include  <list>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Unit; //클래스의 선언

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

Marin::Marin()
{
}

Marin::~Marin()
{
}

void Marin::Move(int x, int y)
{
	cout << typeid(*this).name() << "::Move("<<x<<","<<y<<")" << endl;
}

void Marin::Attack(int x, int y)
{
	cout << typeid(*this).name() << "::Attack(" << x << "," << y << ")" << endl;
}

class Medic : public Unit
{
public:
	Medic();
	~Medic();
	void Move(int x, int y) override;
	void Attack(int, int y) override;
private:

};

Medic::Medic()
{
}

Medic::~Medic()
{
}

void Medic::Move(int x, int y)
{
	cout << typeid(*this).name() << "::Move(" << x << "," << y << ")" << endl;
}

void Medic::Attack(int x, int y)
{
	Move(x, y);
}


void Commonder::Move(int x, int y)
{
	list<Unit*>::iterator it = listUnitCollection.begin();
	for (; it != listUnitCollection.end(); it++)
	{
		//Unit* pUnit = *it;
		//pUnit->Move(x, y);
		(*it)->Move(x, y);
	}
}

void Commonder::Attack(int x, int y)
{
	list<Unit*>::iterator it = listUnitCollection.begin();
	for (; it != listUnitCollection.end(); it++)
	{
		//Unit* pUnit = *it;
		//pUnit->Move(x, y);
		(*it)->Attack(x, y);
	}
}


void CommederMain()
{
	Commonder cCommonder;
	vector<Unit*> vecUnits;

	vecUnits.push_back(new Marin());
	vecUnits.push_back(new Marin());
	vecUnits.push_back(new Marin());
	vecUnits.push_back(new Marin());
	vecUnits.push_back(new Medic());
	vecUnits.push_back(new Medic());

	for (int i = 0; i < vecUnits.size(); i++)
		cCommonder.SelectUnit(vecUnits[i]);

	cCommonder.Move(10, 10);
	cCommonder.Deselect(vecUnits[3]);
	cCommonder.Attack(10, 10);

	for (int i = 0; i < vecUnits.size(); i++)
	{
		delete vecUnits[i];
	}
	vecUnits.clear();
}

void main()
{
	CommederMain();
}