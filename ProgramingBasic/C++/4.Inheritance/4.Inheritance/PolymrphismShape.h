#pragma once

#include <iostream>
using namespace std;
//도형과 같이 공통적인 특징이 속성이 없고 동작만 존재하는 클래스를 굳이 상속관계로 만들필요가 없다.
//다형성을 이용하여 부모의 포인터에서도 자식의 객체에 접근을 하기위해서 상속을 이용한다.
namespace Polymrphism
{
	//1차원이라면 객체로 볼수없다.
	struct Vector//객체: 벡터(2차원 위치)
	{
		//public:
		float x;
		float y;
		Vector(float x = 0, float y = 0)
		{
			this->x = x;
			this->y = y;
		}
		void Print(const char* msg)
		{
			cout << msg << "(" << x << "," << y << ")" << endl;
		}
	};
	//추상클래스: 가상함수를 1개이상 가진 클래스
	//객체화를 할수없다.
	//순수가상함수를 이용하면 부모객체에서 자식의 인터페이스를 반드시 정의하도록 강제할수있다.
	//인터페이스: 매립형스위치 같이 스위치의 기능은 매립되는 위치에따라 결정되는것.
	class Shape //도형
	{
	public:
		Shape()
		{
			cout << "Shape[" << this << "]" << endl;
		}
		//가상소멸자: 소멸자는 순수가상함수로 만들어도 디폴트 소멸자가 생성되므로 실수를 막을수없다.
		virtual ~Shape() = 0
		{
			cout << "~Shape[" << this << "]" << endl;
		}
		void Draw()
		//오버로딩: 함수의 매개변수의 갯수나 타입이 다른 함수를 같은이름으로 정의하는것.
		//오버라이딩: 가상함수를 만들어 부모의포인터에서 자식객체의 함수를 호출하는것.
		//virtual void Draw() //가상함수: 부모의 포인터에서 자식의 함수에 접근하기위해서 사용한다.
		//virtual void Draw() = 0 //순수가상함수: 이 함수를 자식에서 정의하지않으면 컴파일오류가 발생한다.
		{
			cout << "Shape[" << this << "]::Draw()" << endl;
		};
	};
	//원과 같이 삼각형,사각형을 클래스로 만들기
	class Circle : public Shape
	{
		Vector vPos;
		float fRadius;
	public:
		Circle(Vector pos = Vector(), float rad = 1)
		{
			cout << "Circle[" << this << "]" << endl;
			vPos = pos;
			fRadius = rad;
			
			cout << "Rad:" << fRadius << endl;
		}
		~Circle()
		{
			cout << "~Circle[" << this << "]()" << endl;
		}
		void Draw()
		{
			cout << "Circle[" << this << "]::Draw()" << endl;
			vPos.Print("Pos");
			cout << "Rad:" << fRadius << endl;
		}
	};
	class TriAngle : public Shape
	{
		Vector vA;
		Vector vB;
		Vector vC;
	public:
		TriAngle(Vector a = Vector(), Vector b = Vector(), Vector c = Vector()) { cout << "TriAngle[" << this << "]" << endl; };
		//~TriAngle() { cout << "~TriAngle[" << this << "]" << endl; };
		void Draw()
		{
			cout << "TriAngle[" << this << "]::Draw()" << endl;
			vA.Print("A:");
			vB.Print("B:");
			vC.Print("C:");
		}
	};
	class RectAangle : public Shape
	{
		Vector vTL;
		Vector vTR;
		Vector vBL;
		Vector vBR;
	public:
		RectAangle(Vector tl = Vector(), Vector tr = Vector(), Vector bl = Vector(), Vector br = Vector())
		{
			cout << "RectAangle[" << this << "]" << endl;
			vTL = tl;
			vTR = tr;
			vBL = bl;
			vBR = br;
		}
		~RectAangle()
		{
			cout << "~RectAangle[" << this << "]()" << endl;
		}
		/*void Draw()
		{
			cout << "RectAangle[" << this << "]::Draw()" << endl;
			vTL.Print("TopLeft:");
			vTR.Print("TopRight:");
			vBL.Print("BottomLeft:");
			vBR.Print("BottomRight:");
		}*/
	};

	//부모의 부분과 자식의 부분은 메모리가 다르다. 
	//결국 상속을 통해서 두개의 같은이름의 함수를 가진다.
	void ShapeMain()
	{
		//추상클래스는 개념이나 분류이므로 객체화가 불가능하다.
		//Shape cShape;
		//Shape cOctagon;
		Circle cCrilce({ 1,1 }, 1);
		//cShape.Draw();
		//cShape.Shape::Draw();
		cCrilce.Draw();
		cCrilce.Shape::Draw();
	}
	//프로그램 실행중에 선택하여 모양을 여러개를 그리려면 어떻게해야하는가?//동적으로 메모리를 할당받아야한다.
	void RuntimeShapeDrawMain()
	{
		void** arrShape;
		arrShape = new void*[3];
	
		arrShape[0] = (void*)new Circle();
		arrShape[1] = (void*)new RectAangle();
		arrShape[2] = (void*)new TriAngle();

		//for (int i = 0; i < 3; i++)
		//	(Shape*)arrShape[i]->Draw();
		((Circle*)arrShape[0])->Draw();
		((RectAangle*)(arrShape[0]))->Draw();
		((TriAngle*)(arrShape[0]))->Draw();
	}
	void PolymrphismMain()
	{
		Shape* pShape = new Circle;
		//Circle* pCircle = (Circle*)new Shape; //가상함수라면 다음과 같은 문법이 허용되지않는다.
	}
	//부모포인터를 이용하여 자식들을 할당하였으나,
	//부모포인터에서는 자식의 함수밖에 접근이 안된다.
	//다형성이란? 부모의 포인터에서 자식의 객체를 동적할당하여 자식의 함수를 호출하는것.
	void PolymrphismShapeDrawMain()
	{
		Shape* arrShape[3];
		//동적바인딩
		arrShape[0] = new Circle();
		arrShape[1] = new RectAangle();
		arrShape[2] = new TriAngle();

		for (int i = 0; i < 3; i++)
			arrShape[i]->Draw();

		for (int i = 0; i < 3; i++)
			delete(arrShape[i]);
	}

	void ShapeDraw(Shape* shape)
	{
		shape->Draw();
	}

	void CirlceDraw(Shape* pCircle)
	{
		pCircle->Draw();
	}
	//정적: 컴파일이전 동적: 런타임
	//바인딩: 함수의 기능이 결정되는것.
	//정적바인딩: 객체의 함수의 기능이 컴파일전에 정해진다.
	//동적바인딩: 객체의 함수의 기능이 프로그램 실행시에 정해진다.

	//함수포인터를 이용하면 실행중에 
	//함수의 종류를 변경가능하다.
	void FuncPointerMain()
	{
		void (*fucptr)(Shape*) = ShapeDraw;

		fucptr(new RectAangle);
		fucptr = CirlceDraw;
		fucptr(new Circle);
	}
}