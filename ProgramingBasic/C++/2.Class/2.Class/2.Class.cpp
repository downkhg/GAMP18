#include <iostream>
#include "TV.h"
using namespace std;
//자동차(추상화)
//속성(변수): 속도, 엔진시동유무, 색깔, 기어
//동작(함수): 엑셀,브레이크,시동걸기,시동끄기,기어변경
class CCar
{
//private://물리적이나 규법적으로 제한적으로 변경할수 있는 것들이므로, 함수를 통해서만 변경가능하다.
	int m_nSpeed = 0;
	bool m_bEngineOn = false;
	string m_strColor = "gray";
	int m_nGear = N;
public:
	//생성자: 클래스가 객체가 생성될때 호출되는 (함수).
	//객체(인스턴스): 클래스의 실체가되는 메모리
	//디폴트매개변수: 매개변수의 값을 지정하지않으면, 기본으로 들어가는 변수값.
	//생성자가 private이면 객체생성이 불가능하다.? -> 싱글톤
	CCar(string color = "gray")
	{
		cout << "Car[" << this << "]:" << color << endl;
		m_strColor = color;
	}
	////함수의오버로딩
	//CCar(string color, bool engineon, int speed, int gear)//다음과 같이 차의정보를 설정 할 수 없다.
	//{
	//	cout << "Car[" << this << "]:" << color << endl;
	//	m_strColor = color;
	//}
	////디폴트생성자: 매개변수없이 호출되는 생성자.
	//CCar()
	//{
	//	cout << "Car[" << this <<"]" << endl;
	//}
	//소멸자: 클래스의 객체가 소멸될때 호출되는 함수. 소멸자없음.
	~CCar()
	{
		cout << "~Car[" << this << "]:" << m_strColor << endl;
	}
	//복사생성자: 객체가 복사될때 호출되는 함수
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
//자동차를 생선할때 색상을 정하고 주문한다.
//주문된 자동차를 타고 시운전을 하고 주차한다.
void CarMain()
{
	cout << "CarMain Start" << endl;
	CCar cCar("blue");//자동차 객체를 생성할때 색상을 정해야한다.
	//cCar.m_nSpeed; //private멤버에는 객체외부에서 접근할수없다.
	cCar.TurnOn(); //시동을건다.
	cCar.Display();
	cCar.SetGear(CCar::E_GEAR::D);//기어를 주행으로 변경한다.//변속기
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

	cout << "CarMain End" << endl;
}
//※C#/Java의 클래스는 반드시 동적할당된다.
//※C#에서 구조체를 활용하면 정적할당된다.
void ClassTestMain()
{
	CCar cCarA;
	CCar cCarB("red");
	CCar arrCar[3];// = { CCar("red"),  CCar("green"), CCar("blue") };
	for (int i = 0; i < 3; i++)
		arrCar[i].Display();
	cout << "Class Pointer 1" << endl;
	CCar* pCar = NULL;//c++포인터 //c# 객체
	cout << "Class Pointer DynmicAlloc 1" << endl;
	pCar = new CCar("green");//c++ 동적할당 //c# 인스턴스
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