#include <stdio.h>

//함수의 선언을 이용하여 가독성을 높일수있음.
int Add(int a, int b);//함수의 선언: 컴파일러에게 이런형식의 함수가 있다고 알림.
//int Div(int a, int b);
float Div(float a, float b); //나누기는 결과값이 float인것이 좋으므로 리턴값이 float타입이다.
int Max(int a, int b);
int Square(int a);

int Factorial(int n);
//함수는 필요할때마다 여러번을 한꺼번에 값을 넣어서 호출해도된다.
int Combination(int n, int r);

void FunctionMain();

//전역변수: 어떤함수에서든 접근가능한 변수
//전역변수의 선언
extern int g_nData;

void main()
{
	g_nData++;
	printf("Data:%d\n",g_nData);
	FunctionMain();//함수의호출(매개변수x)
}

int g_nData;//전역변수의 선언 //0으로 초기화된다.

void FunctionMain()
{
	g_nData++;
	printf("Data:%d\n", g_nData);

	int nResult = Combination(3, 3);
	printf("Combination(3,3):%d\n", nResult);


	nResult = Add(10, 20);//함수의 호출(매개변수o)
	printf("Add(10,20):%d\n", nResult);

	float fResult = Div(10, 20);
	printf("Div(10,20):%f\n", fResult);

	int nMax = Max(10, 20);//함수의 호출(매개변수o)
	printf("Max(10,20):%d\n", nMax);

	nResult = 3;
	//변수를 전달하더라도 실제로 변수가 가진값을 매개변수에 복사되어 전달되므로,
	//원본인 Result의 값은 변경되지않는다.
	Square(nResult);
	//nResult = Square(nResult);
	printf("Sauare:[%d]%d\n", &nResult, nResult);


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

int Square(int a)
{
	printf("1.SquareCall:[%d]%d\n", &a, a);
	a = a * a;
	printf("2.SquareCall:[%d]%d\n", &a, a);
	return a;
}

//지역변수: 함수(블럭)안에서만 존재하는 변수, 함수안에서 생성되고 호출이 끝나면 소멸된다. //nResult,i,n(매개변수도 지역변수의 일종)
int Factorial(int n)//3 //0
{//함수안에 생성
	int nResult = 1; //1 //1
	for (int i = 1; i <= n; i++)//1,1<=3->T//2,2<=3->T//3,3<=3 ->T //1 <= 0 ->F
	{
		nResult *= i;//1*1 = 1 // 1*2 = 2 // 2*3 = 6
	}
	return nResult;//6 //1
}//함수가 끝날때 소멸

//함수는 필요할때마다 여러번을 한꺼번에 값을 넣어서 호출해도된다.
int Combination(int n, int r)//3, 3
{
	//3->6/(3->6*0->1)
	return Factorial(n) / (Factorial(r) * Factorial(n - r));//1
}