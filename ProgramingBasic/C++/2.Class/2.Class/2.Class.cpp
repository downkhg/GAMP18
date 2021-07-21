#include <iostream>
#include "TV.h"
using namespace std;
//�ڵ���(�߻�ȭ)
//�Ӽ�(����): �ӵ�, �����õ�����, ����, ���
//����(�Լ�): ����,�극��ũ,�õ��ɱ�,�õ�����,����
class CCar
{
//private://�������̳� �Թ������� ���������� �����Ҽ� �ִ� �͵��̹Ƿ�, �Լ��� ���ؼ��� ���氡���ϴ�.
	int m_nSpeed = 0;
	bool m_bEngineOn = false;
	string m_strColor = "gray";
	int m_nGear = N;
public:
	//������: Ŭ������ ��ü�� �����ɶ� ȣ��Ǵ� (�Լ�).
	//��ü(�ν��Ͻ�): Ŭ������ ��ü���Ǵ� �޸�
	//����Ʈ�Ű�����: �Ű������� ���� ��������������, �⺻���� ���� ������.
	//�����ڰ� private�̸� ��ü������ �Ұ����ϴ�.? -> �̱���
	CCar(string color = "gray")
	{
		cout << "Car[" << this << "]:" << color << endl;
		m_strColor = color;
	}
	////�Լ��ǿ����ε�
	//CCar(string color, bool engineon, int speed, int gear)//������ ���� ���������� ���� �� �� ����.
	//{
	//	cout << "Car[" << this << "]:" << color << endl;
	//	m_strColor = color;
	//}
	////����Ʈ������: �Ű��������� ȣ��Ǵ� ������.
	//CCar()
	//{
	//	cout << "Car[" << this <<"]" << endl;
	//}
	//�Ҹ���: Ŭ������ ��ü�� �Ҹ�ɶ� ȣ��Ǵ� �Լ�. �Ҹ��ھ���.
	~CCar()
	{
		cout << "~Car[" << this << "]:" << m_strColor << endl;
	}
	//���������: ��ü�� ����ɶ� ȣ��Ǵ� �Լ�
	CCar(CCar& car)
	{
		cout << "Copy Car[" << this << "]" << endl;
		*this = car;
	}

	enum E_GEAR { P= -4, N = -2, R = -1, D = 0 };

	void Accel()
	{
		m_nSpeed++;
	}
	void Break()
	{
		m_nSpeed--;
	}
	void TurnOn()
	{
		m_bEngineOn = true;
	}
	void TurnOff()
	{
		m_bEngineOn = false;
	}
	void SetColor(string color)
	{
		m_strColor = color;
	}
	void SetGear(E_GEAR gear)
	{
		m_nGear = gear;
	}
	void Display()
	{
		cout << "####" << m_strColor << "####" << endl;
		cout << "Speed:" << m_nSpeed << endl;
		cout << "Gear:" << m_nGear << endl;
		cout << "Engine:" << m_bEngineOn << endl;
	}
};
//�ڵ����� �����Ҷ� ������ ���ϰ� �ֹ��Ѵ�.
//�ֹ��� �ڵ����� Ÿ�� �ÿ����� �ϰ� �����Ѵ�.
void CarMain()
{
	cout << "CarMain Start" << endl;
	CCar cCar("blue");//�ڵ��� ��ü�� �����Ҷ� ������ ���ؾ��Ѵ�.
	//cCar.m_nSpeed; //private������� ��ü�ܺο��� �����Ҽ�����.
	cCar.TurnOn(); //�õ����Ǵ�.
	cCar.Display();
	cCar.SetGear(CCar::E_GEAR::D);//�� �������� �����Ѵ�.//���ӱ�
	cCar.Display();
	cCar.Accel(); //��������� ��´�.
	cCar.Display();
	cCar.Accel();
	cCar.Display();
	cCar.Break(); //�극��ũ�� ��´�.
	cCar.Display();
	cCar.Break();
	cCar.Display(); //�ӵ� 0���� Ȯ���Ѵ�.
	cCar.SetGear(CCar::E_GEAR::P);//�� ������ ���´�.
	cCar.Display();
	cCar.TurnOff(); //�õ�������.
	cCar.Display();

	cout << "CarMain End" << endl;
}
//��C#/Java�� Ŭ������ �ݵ�� �����Ҵ�ȴ�.
//��C#���� ����ü�� Ȱ���ϸ� �����Ҵ�ȴ�.
void ClassTestMain()
{
	CCar cCarA;
	CCar cCarB("red");
	CCar arrCar[3];// = { CCar("red"),  CCar("green"), CCar("blue") };
	for (int i = 0; i < 3; i++)
		arrCar[i].Display();
	cout << "Class Pointer 1" << endl;
	CCar* pCar = NULL;//c++������ //c# ��ü
	cout << "Class Pointer DynmicAlloc 1" << endl;
	pCar = new CCar("green");//c++ �����Ҵ� //c# �ν��Ͻ�
	pCar->Display();
	delete pCar;
	cout << "Class Pointer DynmicAlloc 2" << endl;
	cout << "Class Pointer 2" << endl;
}

void SwapCarVal(CCar carA, CCar carB)
{
	cout << "SwapCarVal:" << &carA << "," << &carB << endl;
	CCar temp = carA;
	carA = carB;
	carB = temp;
}

void SwapCarRef(CCar& carA, CCar& carB)
{
	cout << "SwapCarRef:" << &carA << "," << &carB << endl;
	CCar temp = carA;
	carA = carB;
	carB = temp;
}

void SwapCarMain()
{
	CCar cCarA("red");
	CCar cCarB("bule");
	cCarA.Display();
	cCarB.Display();
	cout << "##################" << endl;
	SwapCarVal(cCarA, cCarB);
	cCarA.Display();
	cCarB.Display();
	cout << "##################" << endl;
	SwapCarRef(cCarA, cCarB);
	cCarA.Display();
	cCarB.Display();
}


void main()
{
	//CarMain();
	//ClassTestMain();
	//SwapCarMain();
	TVSimulatorMain();
}