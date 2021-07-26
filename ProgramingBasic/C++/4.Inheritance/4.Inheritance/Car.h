#pragma once

#include <iostream>
using namespace std;

class Vihicle
{
protected: //�ڽ��� ���ٰ����ϰ� �ܺο��� ���ٺҰ�.
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
	Bus(int engine = 7000, int seat = 30) :Vihicle(seat)//�θ�������� ȣ��: �����ڸ� ���� ȣ���ϸ� �θ����� ���������ڿ� ������� ��밡��.
	{
		cout << "Bus[" << this << "]" << endl;
		m_nEngine = engine;
		///m_nSeats = seat; //�θ����� private�� �ƴϿ��� ���ٰ���.
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