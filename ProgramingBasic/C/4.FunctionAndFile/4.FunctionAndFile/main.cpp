#include <stdio.h>

extern int g_nData; //아직 선언되지않은 지역변수
extern int g_nStaticData;//정적지역변수는 외부에서 사용할수없다.
extern void PrintData();

void StaticCountMain();
void PrintStaticData();
extern void StaticPrintData();

void main()
{
	g_nData = 10;
	PrintData();
	//g_nStaticData = 20; //컴파일오류
	PrintStaticData();
	//StaticPrintData(); //컴파일오류
	StaticCountMain();
}