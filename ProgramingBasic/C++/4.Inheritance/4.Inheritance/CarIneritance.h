#pragma once

#include <iostream>
using namespace std;

namespace Inheritance
{
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
		//Bike cBike;
		//바이크는 탈것과 멤버가 다를것이 없으므로 굳이 클래스화 할 필요가 없다.
		Vihicle cBike;
		AutoBike cAutoBike;
		Truck cTruck;
		Bus cBus;
		cTruck.SetGear(0);
		cTruck.GetMaxWeight();
	}
}