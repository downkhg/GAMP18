#pragma once

#include <iostream>
using namespace std;

//1차원이라면 객체로 볼수없다.
struct Vector//객체: 벡터(2차원 위치)
{
	//public:
	float x;
	float y;
};

class Shape //도형:
{
public:
	Shape()
	{
		cout << "Shape[" << this << "]" << endl;
	}
	~Shape()
	{
		cout << "~Shape[" << this << "]" << endl;
	}
	void Draw()
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
	Circle(Vector pos, float rad)
	{
		cout << "Circle[" << this << "]" << endl;
		vPos = pos;
		fRadius = rad;
		cout << "Pos(" << vPos.x << "," << vPos.y << ")";
		cout << "Rad:" << fRadius << endl;
	}
	~Circle()
	{
		cout << "~Circle[" << this << "]()" << endl;
	}
	void Draw()
	{
		cout << "Circle[" << this << "]::Draw()" << endl;
		cout << "Pos(" << vPos.x << "," << vPos.y << ")";
		cout << "Rad:" << fRadius << endl;
	}
};

void ShapeMain()
{
	Shape cShape;
	Circle cCrilce({ 1,1 }, 1);
	cShape.Draw();
	cCrilce.Draw();
}