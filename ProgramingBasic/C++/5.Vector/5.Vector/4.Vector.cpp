#include <iostream>
using namespace std;
//����
//�Ӽ�: x,y
//����: ���ϱ�(�̵��ϱ�),����(�Ÿ�),���ϱ�(��Į���: �̵����� ����),����ȭ,��Į��

//������ ���� �����ڿ����ε��� ����� ����� ��� �Ǵ��Ŀ� ���� ���ϰ��̳� �Ű������� ��������.
class Vector
{
	float x;
	float y;
public:
	Vector(float x = 0, float y = 0)
	{
		
	}
	Vector operator+(Vector vDist)
	{
		
	}
	Vector operator-(Vector vPos)
	{
		
	}
	Vector operator*(float fDist)
	{
		
	}
	float Scalar()
	{
		
	}
	Vector Normalize()
	{
		
	}
	void Display(const char* msg)
	{
		cout << msg << "(" << x << "," << y << ")" << endl;
	}
};

void VectorMian()
{
	Vector vPos;
	Vector vEndPos(1, 2);
	Vector vDist;

	vPos.Display("Pos");
	vEndPos.Display("EndPos");

	vDist = vEndPos - vPos;
	vEndPos = vPos + vDist;

	float fDist = vDist.Scalar();
	Vector vDir = vDist.Normalize();

	cout << "Dist:" << fDist << endl;
	vDir.Display("Dir");

	vDist.Display("Dist");
}

void main()
{
	VectorMian();
}