#include <stdio.h>
//정적지역변수: 함수가 종료되더라도 해당값이 남아있는 변수
void sub()
{
	int nAutoCount = 0;
	static int nStaticCount = 0;

	nAutoCount++;
	nStaticCount++;

	printf("nAutoCount:%d\n", nAutoCount);
	printf("nStaticCount:%d\n", nStaticCount);
}

void StaticCountMain()
{
	for (int i = 0; i < 3; i++)
		sub();
}
