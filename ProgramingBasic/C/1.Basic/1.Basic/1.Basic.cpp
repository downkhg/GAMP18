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
//면적,반지름,3.14->데이터 -> 변수 > 실수
//반지름*반지름*3.14 = 면적 -> 알고리즘
//정수형의로 계산하면 소숫점값이 사라질수있으므로, 실수를 계산할때는 실수를 이용하는것이 좋다.
#define PI 3.14
void CircleAreaMain()
{
	int nRad;
	int nArea;
	const float fPi = 3.14f;//상수 변수: 변수의 초기값을 변경할수 없음.(메모리 사용)
	//fPi = 3;
	printf("Input Radius:");
	scanf("%d",&nRad);

	//nArea = (nRad * nRad) * fPi;
	nArea = (nRad * nRad) * PI; //컴파일러단에서 정의된숫자로 교체해준다(메모리를 사용하지않음)
	printf("%d*%d*%f = %d", nRad, nRad,fPi, nArea);
}

//사각형의 (면적)을 구하기(단, 사각형의 면적은 (넓이)*(높이) 이다)
//데이터: 면적,넓이,높이 -> 변수
//알고리즘(연삼): 면적 = 넓이 * 높이
//넓이와 높이는 지정되어있지않으므로 (입력:scanf)받도록 만들기
//구한 면적을 (출력:printf)해라.
void RectAreaMain()
{
	float fWidth;
	float fHeight;
	printf("RectHW ex) 100 20\n");
	scanf("%f %f",&fWidth, &fHeight);
	float fArea = fWidth * fHeight;
	printf("%f = %f * %f\n", fArea, fWidth, fHeight);
}

void SizeMain()
{
	//int x;//변수를 초기화하지않으면 쓰래기값이 도출된다.
	int x = 0;//변수의 초기화: 변수의 값을 생성시 설정하는것.

	printf("x[%d]:%d\n", sizeof(x),x);
	printf("char: %d\n", sizeof(char));
	printf("int: %d\n", sizeof(int));
	printf("short: %d\n", sizeof(short));
	printf("long: %d\n", sizeof(long));
	printf("float: %d\n", sizeof(float));
	printf("double: %d\n", sizeof(double));
}

void CharTestMain()
{
	//아스키코드: 미국표준 문자
	char cCodeA = 'A';
	int nCodeA = 65;
	char cCodeB = 'B';
	int nCodeB = 66;

	printf("A:%d/%c\n", nCodeA, cCodeA);
	printf("B:%d/%c\n", nCodeB, cCodeB);

	printf("A:%d/%c\n", cCodeA, nCodeA);
	printf("B:%d/%c\n", cCodeB, nCodeB);
}
//빛이 지구에 도착하는 시간을 구하여라.
//단, 빛의 속도는 30만km/s
//태양과 지구사이 거리는 1억4960만이다.
//시간을 초로 구하기
//시간을 분:초로 구하기
//데이터: 태양과지구사이거리,빛의속도 ->실수, 시간(초)->정수
//알고리즘: 태양과 지구사이 거리에 초당 빛의 이동거리가 몇개가 들어가는가? 
//태양과지구사이거리 / 빛의속도 = 빛이 지구에 도달한 시간(초)
void LightSpeedMain()
{
	float fDist = 14960;
	float fLightSpeed = 30;

	int nSec = fDist / fLightSpeed;

	printf("%d sec\n",nSec);
	int nMin = nSec / 60;
	nSec = nSec - nMin * 60;
	nSec = nSec % 60;
	printf("%d:%d\n", nMin, nSec);
}

void OpMain()
{
	int nDataA = 10;
	int nDataB = 20;
	int nResultA;
	int nResultB;

	nResultA = ++nDataA; //11 //먼저연산이됨
	nResultB = nDataB++; //20 //대입이후 연산이 일어남.

	printf("Data/ResultA:%d/%d\n", nDataA, nResultA);//11/11
	printf("Data/ResulaB:%d/%d\n", nDataB, nResultB);//21/20

	//애초에 한줄코딩하지않으면 이런문제도 없음.
	nDataA++; //12
	nResultA = nDataA; //12
	++nDataB; //22
	nResultB = nDataB; //22

	printf("Data/ResultA:%d/%d\n", nDataA, nResultA);//11/11
	printf("Data/ResulaB:%d/%d\n", nDataB, nResultB);//21/20

	nDataA = nDataA + 1; //12+1 -> 13
	printf("DataA:%d\n", nDataA);//13

	nDataB += 1; //22+1 -> 23
	printf("DataB:%d\n", nDataB);//23

	//값x,y를 입력받아 관계연산의 결과를 출력하라
	//(단, 관계연산은 ==,!=,<,>,<=,<=가 있다.)
	//{
	//	float x, y;
	//	//1:참 0:거짓
	//	//모든명제를 확인할수있도록 값을 모두 확인해보는것이 중요하다.
	//	scanf("%f %f", &x, &y); //10 20, 20 10, 10 10
	//	printf("%f == %f = %d\n", x, y, x == y); //10은 20과 같다 = 0, 0, 1 
	//	printf("%f != %f = %d\n", x, y, x != y); //10은 20과 다르다 = 1, 1, 0
	//	printf("%f < %f = %d\n", x, y, x < y); //10보다 20이 크다 = 1, 0 , 0
	//	printf("%f > %f = %d\n", x, y, x > y); //10보다 20이 작다 = 0, 1 , 0
	//	printf("%f <= %f = %d\n", x, y, x <= y); //10보다 20이 크거나 같다 = 1 0 , 1
	//	printf("%f >= %f = %d\n", x, y, x >= y); //10보다 20이 작거나 같다 = 0 1 , 1
	//}

	//2 < x < 5의 연산결과를 프로그래밍에서 연산하고 출력하라.
	//(단, x의 값은 입력받는다.)
	{
		int x;
		scanf("%d", &x);//3
		printf("2 < x = %d\n", 2 < x); //2보다 3은 크다 O 
		printf("x < 5 = %d\n", x < 5); //2보다 5는 크다 X
		printf("2 < x < 5 = %d\n", 2 < x && x < 5); //O && X // &&:둘다 참
	}
}

void BitMaskMain()
{
	//16진수: 0~9 A(10)~F(15)
	unsigned int color = 0x00385555;
	unsigned int result;

	printf("PixelColor:%#08x\n",color);
	result = color & 0x00ffff00;
	printf("Mask:%#08x\n", result);
	result = result >> 16;
	printf("Result:%#08x\n", result);
}
//점수를 입력하면 A~F까지의 등급을 출력하는 프로그램 만들기
//(단, A: 100~91, B: 90~81, C:80~71, D:70~61, F:60~0)
//데이터: 점수-int, 등급-char:
//알고리즘: A-100 >= S > 90, B-90 >= S > 80, C-80 >= S > 70, D-70 >= S > 60, F: 60 >= S 
void GradeTestIfMain()
{
	int nScore; //?
	char cGrade; //?

	printf("Socre:");
	scanf("%d", &nScore); //

	//100 >= 50 -> T && 50 > 90 F => F
	if (100 >= nScore && nScore > 90)
	{//중괄호,블럭,구문
		cGrade = 'A';
		printf("Select %c\n",cGrade);
	}
	//90 >= 50 -> T && 50 > 80 F => F
	if (90 >= nScore && nScore > 80)
	{
		cGrade = 'B';
		printf("Select %c\n", cGrade);
	}
	//80 >= 50 -> T && 50 > 80 -> F => F
	if (80 >= nScore && nScore > 70)
	{
		cGrade = 'C';
		printf("Select %c\n", cGrade);
	}
	//70 >= 50 -> T && 50 > 70 -> F => F
	if (70 >= nScore && nScore > 60)
	{
		cGrade = 'D';
		printf("Select %c\n", cGrade);
	}
	//60 <= 50 -> T
	if (60 >= nScore)
	{
		cGrade = 'F';
		printf("Select %c\n", cGrade);
	}

	printf("Score/Grade: %d:%c\n",nScore, cGrade);
}

void GradeTestIfElseMain()
{
	int nScore; //S
	char cGrade;

	printf("Socre:");
	scanf("%d", &nScore);
	
	if (nScore > 90)
	{
		cGrade = 'A';
	}
	else if (nScore > 80)
	{
		cGrade = 'B';
	}
	else if (nScore > 70)
		cGrade = 'C';
	else if (nScore > 60)
		cGrade = 'D';
	else
		cGrade = 'F';

	printf("Score/Grade: %d:%c\n", nScore, cGrade);
}
//1.컵용량이 100ml이상이면 L, 100미만 S를 출력하는 프로그램 만들기
//데이터: 컵용량 -> int 
//알고리즘: 컵용량 >= 100 => L 100 < 컵용량 => S
void CupSizeMain()
{
	int nCupSize = 100;

	if (nCupSize >= 100)
	{
		printf("L:%d\n",nCupSize);
	}
	else
	{
		printf("S:%d\n", nCupSize);
	}
}

//컵용량이150초과면 L,150이하 100초과 M,100이하 S를 출력하는 프로그램 만들기
//데이터: 컵용량 -> int 
//알고리즘: 컵용량 > 150 => L 컵용량 <= 150,컵용량 > 100 => M  컵용량 <= 100 => S
void CupSizePlusMain()
{

}
//예) 
// 1+1      //1-1
// 1+1 = 2  //1-1 = 0
//위와 같이 입력하면 과같이 사칙연산이 가능한 계산기 만들기
//데이터: 계산값2개(실수),연산기호(문자)
//알고리즘: 연산기호(+,-,/,*)를 입력하면, 입력받은 두수를 더하여 출력하기
//*입력방법을 모르겠다면 일단 알수있는 방법으로 만들어보기
void CalculatorMain()
{
	float fDataA;
	float fDataB;
	float fResult;
	char cOp;

	printf("Input ex)1+1, 2-2\n");
	scanf("%f%c%f", &fDataA, &cOp, &fDataB);
	/*scanf("%c", &cOp);
	scanf("%f", &fDataA);
	scanf("%f", &fDataB);

	if (cOp == '+')
		fResult = fDataA + fDataB;
	else if (cOp == '-')
		fResult = fDataA - fDataB;
	else if (cOp == '/')
		fResult = fDataA / fDataB;
	else if (cOp == '*')
		fResult = fDataA * fDataB;
	else
	{
		printf("!?!?!?!?!!?!?!?");
		return;
	}*/

	switch (cOp)
	{
	case '+':
		fResult = fDataA + fDataB;
		break;
	case '-':
		fResult = fDataA + fDataB;
		break;
	case '*':
		fResult = fDataA + fDataB;
		break;
	case '/':
		fResult = fDataA + fDataB;
		break;
	default:
		printf("!?!?!?!?!!?!?!?");
		return;
		break;
	}

	printf("%f %c %f = %f", fDataA, cOp, fDataB, fResult);
}

void MounthMain()
{
	int month, days;

	printf("달을 입력하시오: ");
	scanf("%d", &month);

	switch (month)
	{
	case 2:
		days = 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		days = 30;
		break;
	default:
		days = 31;
		break;
	}
	printf("%d월의 일수는 %d입니다.\n", month, days);

}

//(문자:변수)를 (입력:scanf)받으면 
//대문자,소문자,숫자,기타를 종류에 
//따라 보여주는 프로그램
//(단, 알파벳이 뒤에 올수록 숫자가 크다)
void CheckCharMain()
{
	char cInput;
	printf("A~Z: %d~%d\n", 'A', 'Z');
	printf("a~z: %d~%d\n", 'a', 'z');
	printf("0~9: %d~%d\n", '0', '9');
	scanf("%c", &cInput);

	if (cInput >= 'A' && cInput <= 'Z')
		printf("%d~%d  %c is L\n", 'A', 'Z', cInput);
	else if (cInput >= 'a' && cInput <= 'z')
		printf("%d~%d  %c is S\n", 'a', 'z', cInput);
	else if (cInput >= '0' && cInput <= '9')
		printf("%d~%d  %c is Num\n", '0', '9', cInput);
	else
		printf("%c(%d) etc .\n", cInput, cInput);
}

//마일을 미터로 변환하는 프로그램(0~2마일까지 변환한다.)
//데이터: 마일, 미터
//알고리즘: 마일*1609 = 미터
//0.알고리즘 순서대로 모든 작동이 완료될때까지 작성한다. -> 어렵다면 여기까지라도 해보자.
//1.반복하는 구문을 찾음
//2.반복하는 조건을 찾는다. 
//3.끝나는 조건을 찾는다 -> 마일 == 2
//4.조건을 만족하게 변수를 연산한다 -> 마일++
//5.만약 조건에 맞다면 break를 한다.
//6.반복되는 조건을 찾는다 -> 마일 != 2, 마일 < 2
void MailtoMetterMain()
{
	
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
	//CircleAreaMain();
	//SizeMain();
	//RectAreaMain();
	//CharTestMain();
	//LightSpeedMain();
	//OpMain();
	//BitMaskMain();
	//GradeTestIfMain();
	//GradeTestIfElseMain();
	//CupSizeMain();
	//CalculatorMain();
	CheckCharMain();
}