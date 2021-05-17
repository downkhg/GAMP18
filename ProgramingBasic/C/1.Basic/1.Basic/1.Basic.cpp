#include <stdio.h>//표준입출력 라이브러리

//10와 20를 더 하여 계산하는 프로그램만들기
//결과를 사람이 확인할 수 없다.
//그러므로, 결과를 확인하기위해서 출력해야한다.
void AplusBMain()//함수의 정의
{
	////10과 20을 더하여 출력하는 프로그램을 만들기
	//printf("%d",10 + 20);
	////(a:미지수-변수)와 (b:미지수-변수)를 더해서 (출력:printf)하는 프로그램 만들기
	//int a = 0;
	//int b = 0;
	//printf("%d", a + b);
	//(a:미지수-변수)와 (b:미지수-변수)를 더해서 (출력:printf)하는 프로그램 만들기(단, a와 b는 (입력)받는다)
	int a;
	int b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d", a + b);
}
//변수: 데이터를 저장하는 공간.
//데이터, 연산(알고리즘)
//원의 (면적) 구하는 프로그램
//(단, 원의면적은 (반지름)*(반지름)*(3.14) 이다)
//면적,반지름,3.14->데이터
//반지름*반지름*3.14 = 면적 -> 알고리즘
//정수형의로 계산하면 소숫점값이 사라질수있으므로, 실수를 계산할때는 실수를 이용하는것이 좋다.
void CircleAreaMain()
{
	int nRad;
	int nArea;
	float fPi = 3.14f;
	printf("Input Radius:");
	scanf("%d",&nRad);

	nArea = nRad * nRad * fPi;
	printf("%d*%d*%f = %d", nRad, nRad,fPi, nArea);
}

//IDE: 통합개발환경
void main()
{ //구문(블럭)
	//주석: 컴파일러가 분석하지않는 문장.
	//Ctrl+F5: 디버거없이 실행
	//디버거: 프로그램 실행 중지를 하고 해당상태를 확인하는데 사용하는 것.
	//F9/F10/F11: 중단점/한줄씩실행/함수안으로 이동
	//printf("Hello World!!!\n");//\n:줄바꿈문자
	//자신의 이니셜찍기
	//printf("khg\n"); //;세미콜론
	//AplusBMain();//함수의 호출
	CircleAreaMain();
}