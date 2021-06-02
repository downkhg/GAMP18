#include <stdio.h>

int g_nData; //지역변수의 선언
//정적지역변수: 해당파일내에서만 접근가능한 전역변수
//정적함수: 해당파일내에서만 접근가능한 함수
static int g_nStaticData;

void PrintStaticData()
{
	printf("Data:%d\n",g_nStaticData);
}

static void StaticPrintData()
{
	printf("Data:%d\n", g_nData);
}

void PrintData()
{
	printf("Data:%d\n",g_nData);
}