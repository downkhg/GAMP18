#include <iostream>
using namespace std;
//자동차(추상화)
//속성(변수): 속도, 엔진시동유무, 색깔, 기어
//동작(함수): 엑셀,브레이크,시동걸기,시동끄기,기어변경
class CCar
{
//private:
	int m_nSpeed = 0;
	bool m_bEngineOn = false;
	string m_strColor = "gray";
	int m_nGear = N;
public:
	//생성자: 클래스가 객체가 생성될때 호출되는 함수.
	CCar(string color)
	{
		cout << "Car[" << this << "]:" << color << endl;
		m_strColor = color;
	}
	//소멸자: 클래스의 객체가 소멸될때 호출되는 함수.
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
//자동차를 생선할때 색상을 정하고 주문한다.
//주문된 자동차를 타고 시운전을 하고 주차한다.
void CarMain()
{
	CCar cCar("blue");//자동차 객체를 생성할때 색상을 정해야한다.

	cCar.TurnOn(); //시동을건다.
	cCar.Display();
	cCar.SetGear(CCar::E_GEAR::D);//기어를 주행으로 변경한다.
	cCar.Display();
	cCar.Accel(); //가속페달을 밟는다.
	cCar.Display();
	cCar.Accel();
	cCar.Display();
	cCar.Break(); //브레이크를 밟는다.
	cCar.Display();
	cCar.Break();
	cCar.Display(); //속도 0인지 확인한다.
	cCar.SetGear(CCar::E_GEAR::P);//기어를 주차로 놓는다.
	cCar.Display();
	cCar.TurnOff(); //시동을끈다.
	cCar.Display();
}

void main()
{
	CarMain();
}