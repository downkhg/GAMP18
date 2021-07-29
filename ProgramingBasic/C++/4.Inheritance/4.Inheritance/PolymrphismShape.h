#pragma once

#include <iostream>
using namespace std;
//������ ���� �������� Ư¡�� �Ӽ��� ���� ���۸� �����ϴ� Ŭ������ ���� ��Ӱ���� �����ʿ䰡 ����.
//�������� �̿��Ͽ� �θ��� �����Ϳ����� �ڽ��� ��ü�� ������ �ϱ����ؼ� ����� �̿��Ѵ�.
namespace Polymrphism
{
	//1�����̶�� ��ü�� ��������.
	struct Vector//��ü: ����(2���� ��ġ)
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
	//�߻�Ŭ����: �����Լ��� 1���̻� ���� Ŭ����
	//��üȭ�� �Ҽ�����.
	//���������Լ��� �̿��ϸ� �θ�ü���� �ڽ��� �������̽��� �ݵ�� �����ϵ��� �����Ҽ��ִ�.
	//�������̽�: �Ÿ�������ġ ���� ����ġ�� ����� �Ÿ��Ǵ� ��ġ������ �����Ǵ°�.
	class Shape //����
	{
	public:
		Shape()
		{
			cout << "Shape[" << this << "]" << endl;
		}
		//����Ҹ���: �Ҹ��ڴ� ���������Լ��� ���� ����Ʈ �Ҹ��ڰ� �����ǹǷ� �Ǽ��� ����������.
		virtual ~Shape() = 0
		{
			cout << "~Shape[" << this << "]" << endl;
		}
		void Draw()
		//�����ε�: �Լ��� �Ű������� ������ Ÿ���� �ٸ� �Լ��� �����̸����� �����ϴ°�.
		//�������̵�: �����Լ��� ����� �θ��������Ϳ��� �ڽİ�ü�� �Լ��� ȣ���ϴ°�.
		//virtual void Draw() //�����Լ�: �θ��� �����Ϳ��� �ڽ��� �Լ��� �����ϱ����ؼ� ����Ѵ�.
		//virtual void Draw() = 0 //���������Լ�: �� �Լ��� �ڽĿ��� �������������� �����Ͽ����� �߻��Ѵ�.
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

	//�θ��� �κа� �ڽ��� �κ��� �޸𸮰� �ٸ���. 
	//�ᱹ ����� ���ؼ� �ΰ��� �����̸��� �Լ��� ������.
	void ShapeMain()
	{
		//�߻�Ŭ������ �����̳� �з��̹Ƿ� ��üȭ�� �Ұ����ϴ�.
		//Shape cShape;
		//Shape cOctagon;
		Circle cCrilce({ 1,1 }, 1);
		//cShape.Draw();
		//cShape.Shape::Draw();
		cCrilce.Draw();
		cCrilce.Shape::Draw();
	}
	//���α׷� �����߿� �����Ͽ� ����� �������� �׸����� ����ؾ��ϴ°�?//�������� �޸𸮸� �Ҵ�޾ƾ��Ѵ�.
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
		//Circle* pCircle = (Circle*)new Shape; //�����Լ���� ������ ���� ������ �������ʴ´�.
	}
	//�θ������͸� �̿��Ͽ� �ڽĵ��� �Ҵ��Ͽ�����,
	//�θ������Ϳ����� �ڽ��� �Լ��ۿ� ������ �ȵȴ�.
	//�������̶�? �θ��� �����Ϳ��� �ڽ��� ��ü�� �����Ҵ��Ͽ� �ڽ��� �Լ��� ȣ���ϴ°�.
	void PolymrphismShapeDrawMain()
	{
		Shape* arrShape[3];
		//�������ε�
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
	//����: ���������� ����: ��Ÿ��
	//���ε�: �Լ��� ����� �����Ǵ°�.
	//�������ε�: ��ü�� �Լ��� ����� ���������� ��������.
	//�������ε�: ��ü�� �Լ��� ����� ���α׷� ����ÿ� ��������.

	//�Լ������͸� �̿��ϸ� �����߿� 
	//�Լ��� ������ ���氡���ϴ�.
	void FuncPointerMain()
	{
		void (*fucptr)(Shape*) = ShapeDraw;

		fucptr(new RectAangle);
		fucptr = CirlceDraw;
		fucptr(new Circle);
	}
}