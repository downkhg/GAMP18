#include <stdio.h>

//�Լ��� ������ �̿��Ͽ� �������� ���ϼ�����.
int Add(int a, int b);//�Լ��� ����: �����Ϸ����� �̷������� �Լ��� �ִٰ� �˸�.
//int Div(int a, int b);
float Div(float a, float b); //������� ������� float�ΰ��� �����Ƿ� ���ϰ��� floatŸ���̴�.
int Max(int a, int b);
void FunctionMain();

void FunctionMain()
{
	int nResult = Add(10, 20);//�Լ��� ȣ��(�Ű�����o)
	printf("Add(10,20):%d\n", nResult);
	
	float fResult = Div(10, 20);
	printf("Div(10,20):%f\n", fResult);

	int nMax = Max(10, 20);//�Լ��� ȣ��(�Ű�����o)
	printf("Max(10,20):%d\n", nMax);
}

void main()
{
	FunctionMain();//�Լ���ȣ��(�Ű�����x)
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