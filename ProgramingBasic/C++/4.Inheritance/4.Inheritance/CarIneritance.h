#pragma once

#include <iostream>
using namespace std;

namespace Inheritance
{
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

	class Truck : public Vihicle
	{
		int m_nEngine;
		int m_nMaxWeight;
	public:
		Truck(int engine = 3000, int wight = 1000)
		{
			cout << "Truck[" << this << "]" << endl;
			m_nEngine = engine;
			m_nMaxWeight = wight;
		}
		~Truck() { cout << "~Truck[" << this << "]" << endl; }
		int GetMaxWeight()
		{
			return m_nMaxWeight;
		}
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
		//Bike cBike;
		//����ũ�� Ż�Ͱ� ����� �ٸ����� �����Ƿ� ���� Ŭ����ȭ �� �ʿ䰡 ����.
		Vihicle cBike;
		AutoBike cAutoBike;
		Truck cTruck;
		Bus cBus;
		cTruck.SetGear(0);
		cTruck.GetMaxWeight();
	}
}