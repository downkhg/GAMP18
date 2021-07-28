#pragma once
#include <iostream>
using namespace std;

class Bike
{
protected: //자식은 접근가능하고 외부에서 접근불가.
	int m_nGear = 0;
	int m_nSpeed = 0;
	int m_nSeats = 1;
public:
	Bike(int seat = 1)
	{
		cout << "Bike[" << this << "]" << endl;
		m_nSeats = seat;
	}
	~Bike() { cout << "~Bike[" << this << "]" << endl; }

	void Accel() { m_nSpeed++; }
	void Break() { m_nSpeed--; }
	void SetGear(int gear) { m_nGear = gear; }
	void SetSeats(int seat) { m_nSeats = seat; }
};

class AutoBike
{
protected: //자식은 접근가능하고 외부에서 접근불가.
	int m_nGear = 0;
	int m_nSpeed = 0;
	int m_nSeats = 1;
	int m_nEngine;
public:
	AutoBike(int seat = 2, int engine = 500)
	{
		cout << "AutoBike[" << this << "]" << endl;
		m_nSeats = seat;
	}
	~AutoBike() 
	{ 
		cout << "~AutoBike[" << this << "]" << endl; 
	}

	void Accel() { m_nSpeed++; }
	void Break() { m_nSpeed--; }
	void SetGear(int gear) { m_nGear = gear; }
	void SetSeats(int seat) { m_nSeats = seat; }
};

class Bus
{
protected: //자식은 접근가능하고 외부에서 접근불가.
	int m_nGear = 0;
	int m_nSpeed = 0;
	int m_nSeats = 20;
	int m_nEngine;
public:
	Bus(int seat = 20, int engine = 10000)
	{
		cout << "Bus[" << this << "]" << endl;
		m_nSeats = seat;
	}
	~Bus()
	{
		cout << "~Bus[" << this << "]" << endl;
	}

	void Accel() { m_nSpeed++; }
	void Break() { m_nSpeed--; }
	void SetGear(int gear) { m_nGear = gear; }
	void SetSeats(int seat) { m_nSeats = seat; }
};

class Truck
{
protected: //자식은 접근가능하고 외부에서 접근불가.
	int m_nGear = 0;
	int m_nSpeed = 0;
	int m_nSeats = 20;
	int m_nEngine;
	int m_nMaxWeight;
public:
	Truck(int weight = 10000, int seat = 4, int engine = 1000)
	{
		cout << "Truck[" << this << "]" << endl;
		m_nSeats = seat;
		m_nMaxWeight = weight;
		m_nEngine = engine;
	}
	~Truck()
	{
		cout << "~Truck[" << this << "]" << endl;
	}

	void Accel() { m_nSpeed++; }
	void Break() { m_nSpeed--; }
	void SetGear(int gear) { m_nGear = gear; }
	void SetSeats(int seat) { m_nSeats = seat; }
	int GetMaxWight()
	{
		return m_nMaxWeight;
	}
};

void CarMain()
{
	//Vihicle cVihvle;
	Bike cBike;
	AutoBike cAutoBike;
	Truck cTruck;
	Bus cBus;
	cTruck.SetGear(0);
	cTruck.GetMaxWight();
}