#pragma once

#include <iostream>
using namespace std;

class Vihicle
{
protected: //자식은 접근가능하고 외부에서 접근불가.
	int m_nGear = 0;
	int m_nSpeed = 0;
	int m_nSeats = 1;
public:
	Vihicle(int seat = 1)
	{
		cout << "Vihicle[" << this << "]" << endl;
		m_nSeats = seat;
	}
	~Vihicle() { cout << "~Vihicle[" << this << "]" << endl; }

	void Accel() { m_nSpeed++; }
	void Break() { m_nSpeed--; }
	void SetGear(int gear) { m_nGear = gear; }
	void SetSeats(int seat) { m_nSeats = seat; }
};

class Bike : public Vihicle
{
public:
	Bike() { cout << "Bike[" << this << "]" << endl; }
	~Bike() { cout << "~Bike[" << this << "]" << endl; }
};

class AutoBike : public Vihicle
{
	int m_nEngine;
public:
	AutoBike(int engine = 300)
	{
		cout << "AutoBike[" << this << "]" << endl;
		m_nEngine = engine;
	}
	~AutoBike() { cout << "~AutoBike[" << this << "]" << endl; }
};

class Track : public Vihicle
{
	int m_nEngine;
	int m_nMaxWight;
public:
	Track(int engine = 3000, int wight = 1000)
	{
		cout << "Track[" << this << "]" << endl;
		m_nEngine = engine;
		m_nMaxWight = wight;
	}
	~Track() { cout << "~Track[" << this << "]" << endl; }
};

class Bus : public Vihicle
{
	int m_nEngine;
public:
	Bus(int engine = 7000, int seat = 30) :Vihicle(seat)//부모생성자의 호출: 생성자를 통해 호출하면 부모멤버의 접근제어자와 상관없이 사용가능.
	{
		cout << "Bus[" << this << "]" << endl;
		m_nEngine = engine;
		///m_nSeats = seat; //부모멤버가 private가 아니여야 접근가능.
	}
	~Bus() { cout << "~Bus[" << this << "]" << endl; }
};

void CarMain()
{
	Vihicle cVihvle;
	Bike cBike;
	AutoBike cAutoBike;
	Track cTrack;
	Bus cBus;
}