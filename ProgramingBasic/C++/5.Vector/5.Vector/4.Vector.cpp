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
	//�����ڿ����ε��� ���ϰ��� ���� �����.
	Vector(float x = 0, float y = 0)
	{
		this->x = x;
		this->y = y;
	}
	Vector operator+(Vector vDist)
	{
		return Vector(x + vDist.x, y + vDist.y);
	}
	Vector operator-(Vector vPos)
	{
		return Vector(x - vPos.x, y - vPos.y);
	}
	Vector operator*(float fDist)
	{
		return Vector(x * fDist, y * fDist);
	}
	//�����ڿ����ε��� ��ü���� �ٸ� ���� ����Ҷ�, friend�Լ��� ����ؾ��Ѵ�.
	friend Vector operator*(float dist, Vector vec)
	{
		return Vector(vec.x * dist, vec.y * dist);
	}
	float Scalar()
	{
		return sqrt(x * x + y * y);
	}
	Vector Normalize()
	{
		float fDist = Scalar();
		return Vector(x/fDist, y/fDist);
	}
	void Display(const char* msg)
	{
		cout << msg << "(" << x << "," << y << ")" << endl;
	}
	float operator[](int idx)
	{
		if (idx == 0)
			return x;
		else
			return y;
	}
	bool operator==(Vector vec)
	{
		return (x == vec.x && y == vec.y) ? true: false;
	}
	bool operator!=(Vector vec)
	{
		return !(*this == vec);
	}
	friend ostream& operator<<(ostream& os, Vector vec)
	{
		return os << vec.x << "," << vec.y ;
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

	vDist = vDir * fDist;
	vDist = fDist * vDir;

	vDist.Display("Dist");

	cout << vDist[0] << "," << vDist[1] << endl;

	if (vDir == vDist)
		cout << vDist << "==" << vDir << endl;
}

void main()
{
	VectorMian();
}