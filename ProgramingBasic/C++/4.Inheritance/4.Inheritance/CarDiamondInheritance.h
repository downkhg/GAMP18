#pragma once
#include <iostream>

using namespace std;

namespace DiamondInheritance
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

	class Bike : public Vihicle
	{
	public:
		Bike() { cout << "Bike[" << this << "]" << endl; }
		~Bike() { cout << "~Bike[" << this << "]" << endl; }
	};

	class AutoBike : public Bike, public Enginer
	{
	public:
		AutoBike(int engine = 300):Enginer(engine)
		{
			cout << "AutoBike[" << this << "]" << endl;
		
		}
		~AutoBike() { cout << "~AutoBike[" << this << "]" << endl; }
	};

	//�������: �θ� ���� Ŭ������ ��ӹ޴°�.
	class Truck : public Enginer
	{
		int m_nMaxWeight;
	public:
		//�θ�������� ȣ��
		Truck(int engine = 3000, int wight = 1000) :Enginer(engine)
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
	
	//class Bus : public Enginer{ };
	
	void CarMain()
	{
		AutoBike cAutoBike;
	}
}