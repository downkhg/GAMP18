#include <stdio.h>
//������������: �Լ��� ����Ǵ��� �ش簪�� �����ִ� ����
void sub()
{
	int nAutoCount = 0; //0
	static int nStaticCount = 0; //0 //1 //2

	nAutoCount++; // 0++ = 1 // 0++ = 1 // 0++ = 1
	nStaticCount++; //0++ = 1 //1++ = 2 //2++ = 3

	printf("nAutoCount:%d\n", nAutoCount); //1 //1 //1
	printf("nStaticCount:%d\n", nStaticCount);//1 //2 //3
}

void StaticCountMain()
{
	for (int i = 0; i < 3; i++)
		sub();//0 //1 //2
}
