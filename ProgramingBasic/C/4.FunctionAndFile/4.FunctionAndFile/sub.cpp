#include <stdio.h>

int g_nData; //���������� ����
//������������: �ش����ϳ������� ���ٰ����� ��������
//�����Լ�: �ش����ϳ������� ���ٰ����� �Լ�
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