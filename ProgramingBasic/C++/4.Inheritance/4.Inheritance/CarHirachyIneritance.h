#pragma once
#include <iostream>

using namespace std;

namespace HirachyInheritance
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

	class Enginer : public Vihicle
	{
		int m_nEngine;
	public:
		Enginer(int engine = 300)
		{
			cout << "Enginer[" << this << "]" << endl;
			m_nEngine = engine;
		}
		~Enginer() { cout << "~Enginer[" << this << "]" << endl; }
	};
	//계층상속: 부모를 가진 클래스를 상속받는것.
	class Truck : public Enginer
	{
		int m_nMaxWeight;
	public:
		//부모생성자의 호출
		Truck(int engine = 3000, int wight = 1000):Enginer(engine)
		{
			cout << "Truck[" << this << "]" << endl;
			m_nMaxWeight = wight;
		}
		~Truck() { cout << "~Truck[" << this << "]" << endl; }
		int GetMaxWeight()
		{
			return m_nMaxWeight;
		}
	};
	//다음클래스들은 추가된 멤버가 없으므로 굳이 상속 할필요가없고,
	//해당객체를 생성할때 이름을 변경해주면됨.
	//class Bike : public Vihicle{ };
	//class Bus : public Enginer{ };
	//class AutoBike : public Enginer{ };
	void CarMain()
	{
		//Vihicle cVihvle;
		//Bike cBike;
		//바이크는 탈것과 멤버가 다를것이 없으므로 굳이 클래스화 할 필요가 없다.
		//Vihicle cBike;
		//Enginer cAutoBike;
		Truck cTruck;
		//Bus cBus;
		//Enginer cBus;
		cTruck.SetGear(0);
		cTruck.GetMaxWeight();
	}
}