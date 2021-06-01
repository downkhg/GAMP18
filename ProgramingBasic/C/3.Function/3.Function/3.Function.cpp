#include <stdio.h>

//함수의 선언을 이용하여 가독성을 높일수있음.
int Add(int a, int b);//함수의 선언: 컴파일러에게 이런형식의 함수가 있다고 알림.
//int Div(int a, int b);
float Div(float a, float b); //나누기는 결과값이 float인것이 좋으므로 리턴값이 float타입이다.
int Max(int a, int b);
void FunctionMain();

void FunctionMain()
{
	int nResult = Add(10, 20);//함수의 호출(매개변수o)
	printf("Add(10,20):%d\n", nResult);
	
	float fResult = Div(10, 20);
	printf("Div(10,20):%f\n", fResult);

	int nMax = Max(10, 20);//함수의 호출(매개변수o)
	printf("Max(10,20):%d\n", nMax);
}

void main()
{
	FunctionMain();//함수의호출(매개변수x)
}

//리턴값: 함수에서 계산하여 외부로 넘겨주는 값. 리턴을 만나면 함수를 종료된다.
//매개변수: 함수에 외부에서 값을 전달해주는 변수.
//리턴값 함수명(매개변수, 매개변수)
//함수의 정의: 컴파일러에게 함수의 내용을 만드는것.
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
	//a = b;//의미없는 코드
}