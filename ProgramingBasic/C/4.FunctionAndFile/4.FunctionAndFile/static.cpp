#include <stdio.h>
//������������: �Լ��� ����Ǵ��� �ش簪�� �����ִ� ����
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
