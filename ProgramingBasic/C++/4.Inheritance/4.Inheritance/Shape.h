#pragma once

#include <iostream>
using namespace std;

//1�����̶�� ��ü�� ��������.
struct Vector//��ü: ����(2���� ��ġ)
{
	//public:
	float x;
	float y;
};

class Shape //����:
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
//���� ���� �ﰢ��,�簢���� Ŭ������ �����
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