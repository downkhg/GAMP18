#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�����Ҵ�: ������ �ÿ� �޸𸮻����� �����Ǵ� ��. -> �������� ����� ��� ������ ����� ���.
//�����Ҵ�: ��Ÿ��(���α׷�����)�߿� �޸𸮰� �Ҵ�Ǵ� �� -> malloc�̳� new�� �̿���.
//void������: ������ �޸�? -> �Ÿ���� ������ �޸𸮴� �����ϹǷ� ���������� ó�� �Ҽ� ����.
//������: �ּҰ��� �����ϴ� ���� -> �����Ҵ��Ҷ� �����͸� ����ϴ� ����?
//������ �°� �޸𸮰� �Ҵ�ȴ�. -> �����Ҵ��� �����Ϸ��� �ڵ忡�� �ۼ��� �̸���� �ٿ��ش�.
//�����Ҵ�ÿ��� �̸��� �ο��Ҽ�����. �׷��Ƿ� �����ϱ����ؼ� �ּҰ��� �ʿ��ϰ� �� �ּҰ��� �����ϱ� ���ؼ� �����Ͱ� �ʿ��ϴ�.
//c++������ �Ҵ繮���� �� ����������, c�� malloc�Լ��� �̿��ϸ� �޸𸮸� �Ҵ��ϴ� ������ ������ �� �ִ�.
struct SDate
{
	int nYear;
	int nMounth;
	int nDay;
};

void StaticAllocMain()
{
	int nData;
	const int nArraySize = 5;
	int arrDatas[nArraySize];
	SDate sDate = {2021,6,11};
	SDate arrDates[nArraySize] = { {2021,6,11},{2021,6,10} ,{2021,6,9} ,{2021,6,8}, {2021,6,7} };

	nData = 10;
	printf("Val[%d]:%d\n", &nData, nData);

	for (int i = 0; i < nArraySize; i++)
	{
		arrDates[i].nYear = 2021;
		arrDates[i].nMounth = 6;
		arrDates[i].nDay = 11 - i;
		arrDatas[i] = i * 10;
		printf("[%d]%d,", i, arrDatas[i]);
	}
}

void DynamicAllocMain()
{
	int nArraySize = 5;
	//�����Ҵ�
	int* pDynamicVal = new int();// (int*)malloc(sizeof(int));//�����Ҵ�� ����
	int* pDynmicArray = new int[nArraySize];// (int*)malloc(nArraySize * sizeof(int));//�����Ҵ�� �迭
	SDate* pDate = new SDate();// (SDate*)malloc(sizeof(SDate));
	SDate* pArrDate = new SDate[nArraySize];//(SDate*)malloc(nArraySize*sizeof(SDate));
	*pDynamicVal = 10;
	printf("DynmicVal[%d]:%d\n",pDynamicVal,*pDynamicVal);

	for (int i = 0; i < nArraySize; i++)
	{
		(pArrDate + i)->nYear = 2021;
		(pArrDate + i)->nMounth = 6;
		(pArrDate + i)->nDay = 11 - i;
		pDynmicArray[i] = i * 10;
		printf("[%d]%d,",i,pDynmicArray[i]);
	}

	//�����Ҵ�����
	delete pDate;
	delete pArrDate;
	delete pDynamicVal;// free(pDynamicVal);
	delete[] pDynmicArray;// free(pDynmicArray);
}

void main()
{
	DynamicAllocMain();
}