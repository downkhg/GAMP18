#include "Commender.h"
using namespace std;

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