#include <stdio.h>

extern int g_nData; //���� ����������� ��������
extern int g_nStaticData;//�������������� �ܺο��� ����Ҽ�����.
extern void PrintData();

void StaticCountMain();
void PrintStaticData();
extern void StaticPrintData();

void main()
{
	g_nData = 10;
	PrintData();
	//g_nStaticData = 20; //�����Ͽ���
	PrintStaticData();
	//StaticPrintData(); //�����Ͽ���
	StaticCountMain();
}