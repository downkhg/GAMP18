#include <stdio.h>

//�Լ��� ������ �̿��Ͽ� �������� ���ϼ�����.
int Add(int a, int b);//�Լ��� ����: �����Ϸ����� �̷������� �Լ��� �ִٰ� �˸�.
//int Div(int a, int b);
float Div(float a, float b); //������� ������� float�ΰ��� �����Ƿ� ���ϰ��� floatŸ���̴�.
int Max(int a, int b);
int Square(int a);

int Factorial(int n);
//�Լ��� �ʿ��Ҷ����� �������� �Ѳ����� ���� �־ ȣ���ص��ȴ�.
int Combination(int n, int r);

void FunctionMain();

//��������: ��Լ������� ���ٰ����� ����
//���������� ����
extern int g_nData;

void main()
{
	g_nData++;
	printf("Data:%d\n",g_nData);
	FunctionMain();//�Լ���ȣ��(�Ű�����x)
}

int g_nData;//���������� ���� //0���� �ʱ�ȭ�ȴ�.

void FunctionMain()
{
	g_nData++;
	printf("Data:%d\n", g_nData);

	int nResult = Combination(3, 3);
	printf("Combination(3,3):%d\n", nResult);


	nResult = Add(10, 20);//�Լ��� ȣ��(�Ű�����o)
	printf("Add(10,20):%d\n", nResult);

	float fResult = Div(10, 20);
	printf("Div(10,20):%f\n", fResult);

	int nMax = Max(10, 20);//�Լ��� ȣ��(�Ű�����o)
	printf("Max(10,20):%d\n", nMax);

	nResult = 3;
	//������ �����ϴ��� ������ ������ �������� �Ű������� ����Ǿ� ���޵ǹǷ�,
	//������ Result�� ���� ��������ʴ´�.
	Square(nResult);
	//nResult = Square(nResult);
	printf("Sauare:[%d]%d\n", &nResult, nResult);


}



//���ϰ�: �Լ����� ����Ͽ� �ܺη� �Ѱ��ִ� ��. ������ ������ �Լ��� ����ȴ�.
//�Ű�����: �Լ��� �ܺο��� ���� �������ִ� ����.
//���ϰ� �Լ���(�Ű�����, �Ű�����)
//�Լ��� ����: �����Ϸ����� �Լ��� ������ ����°�.
int Add(int a, int b)//10 20
{
	return a + b; //30
}

float Div(float a, float b)
{
	return a / b;
}

int Max(int a, int b)//10,20
{
	if (a > b) //10 > 20 -> F
		return a;
	else
		return b; //20
	//a = b;//�ǹ̾��� �ڵ�
}

int Square(int a)
{
	printf("1.SquareCall:[%d]%d\n", &a, a);
	a = a * a;
	printf("2.SquareCall:[%d]%d\n", &a, a);
	return a;
}

//��������: �Լ�(��)�ȿ����� �����ϴ� ����, �Լ��ȿ��� �����ǰ� ȣ���� ������ �Ҹ�ȴ�. //nResult,i,n(�Ű������� ���������� ����)
int Factorial(int n)//3 //0
{//�Լ��ȿ� ����
	int nResult = 1; //1 //1
	for (int i = 1; i <= n; i++)//1,1<=3->T//2,2<=3->T//3,3<=3 ->T //1 <= 0 ->F
	{
		nResult *= i;//1*1 = 1 // 1*2 = 2 // 2*3 = 6
	}
	return nResult;//6 //1
}//�Լ��� ������ �Ҹ�

//�Լ��� �ʿ��Ҷ����� �������� �Ѳ����� ���� �־ ȣ���ص��ȴ�.
int Combination(int n, int r)//3, 3
{
	//3->6/(3->6*0->1)
	return Factorial(n) / (Factorial(r) * Factorial(n - r));//1
}