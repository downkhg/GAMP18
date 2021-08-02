#include <iostream>
using namespace std;
//벡터
//속성: x,y
//동작: 더하기(이동하기),빼기(거리),곱하기(스칼라곱: 이동량을 곱함),평준화,스칼라

//다음과 같이 연산자오버로딩인 연산된 결과가 어떻게 되느냐에 따라서 리턴값이나 매개변수가 정해진다.
class Vector
{
	float x;
	float y;
public:
	//연산자오버로딩시 리턴값은 계산될 결과다.
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
	//연산자오버로딩시 객체서로 다른 값을 계산할때, friend함수를 사용해야한다.
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