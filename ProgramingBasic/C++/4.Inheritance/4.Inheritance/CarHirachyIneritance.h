#pragma once
#include <iostream>

using namespace std;

namespace HirachyInheritance
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
	//�������: �θ� ���� Ŭ������ ��ӹ޴°�.
	class Truck : public Enginer
	{
		int m_nMaxWeight;
	public:
		//�θ�������� ȣ��
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
	//����Ŭ�������� �߰��� ����� �����Ƿ� ���� ��� ���ʿ䰡����,
	//�ش簴ü�� �����Ҷ� �̸��� �������ָ��.
	//class Bike : public Vihicle{ };
	//class Bus : public Enginer{ };
	//class AutoBike : public Enginer{ };
	void CarMain()
	{
		//Vihicle cVihvle;
		//Bike cBike;
		//����ũ�� Ż�Ͱ� ����� �ٸ����� �����Ƿ� ���� Ŭ����ȭ �� �ʿ䰡 ����.
		//Vihicle cBike;
		//Enginer cAutoBike;
		Truck cTruck;
		//Bus cBus;
		//Enginer cBus;
		cTruck.SetGear(0);
		cTruck.GetMaxWeight();
	}
}