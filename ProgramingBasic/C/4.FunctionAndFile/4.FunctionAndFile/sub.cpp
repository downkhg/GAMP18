#include <stdio.h>

int g_nData; //���������� ����
//������������: �ش����ϳ������� ���ٰ����� ��������

static int g_nStaticData;//������������: �ش����Ͽ����� ���ٰ����� ��������

void PrintStaticData()
{
	printf("Data:%d\n",g_nStaticData);
}
//�����Լ�: �ش����ϳ������� ���ٰ����� �Լ�
static void StaticPrintData()
{
	printf("Data:%d\n", g_nData);
}

void PrintData()
{
	printf("Data:%d\n",g_nData);
}