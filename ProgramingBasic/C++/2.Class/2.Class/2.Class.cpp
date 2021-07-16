#include <iostream>
using namespace std;
//�ڵ���(�߻�ȭ)
//�Ӽ�(����): �ӵ�, �����õ�����, ����, ���
//����(�Լ�): ����,�극��ũ,�õ��ɱ�,�õ�����,����
class CCar
{
//private:
	int m_nSpeed = 0;
	bool m_bEngineOn = false;
	string m_strColor = "gray";
	int m_nGear = N;
public:
	//������: Ŭ������ ��ü�� �����ɶ� ȣ��Ǵ� �Լ�.
	CCar(string color)
	{
		cout << "Car[" << this << "]:" << color << endl;
		m_strColor = color;
	}
	//�Ҹ���: Ŭ������ ��ü�� �Ҹ�ɶ� ȣ��Ǵ� �Լ�.
	~CCar()
	{
		cout << "~Car[" << this << "]:" << m_strColor << endl;
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
	CCar cCar("blue");//�ڵ��� ��ü�� �����Ҷ� ������ ���ؾ��Ѵ�.

	cCar.TurnOn(); //�õ����Ǵ�.
	cCar.Display();
	cCar.SetGear(CCar::E_GEAR::D);//�� �������� �����Ѵ�.
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
}

void main()
{
	CarMain();
}