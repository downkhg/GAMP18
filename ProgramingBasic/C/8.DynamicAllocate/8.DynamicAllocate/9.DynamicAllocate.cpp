#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//정적할당: 컴파일 시에 메모리생성이 결정되는 것. -> 이전까지 배웠던 모든 변수를 만드는 방법.
//동적할당: 런타임(프로그램실행)중에 메모리가 할당되는 것 -> malloc이나 new를 이용함.
//void포인터: 무형의 메모리? -> 어떤타입의 변수던 메모리는 존재하므로 공통적으로 처리 할수 있음.
//포인터: 주소값을 저장하는 변수 -> 동적할당할때 포인터를 사용하는 이유?
//변수명에 맞게 메모리가 할당된다. -> 정적할당은 컴파일러가 코드에서 작성된 이름대로 붙여준다.
//동적할당시에는 이름을 부여할수없다. 그러므로 구별하기위해서 주소값이 필요하고 이 주소값을 저장하기 위해서 포인터가 필요하다.
//c++버전의 할당문법이 더 간단하지만, c에 malloc함수를 이용하면 메모리를 할당하는 원리를 이해할 수 있다.
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
	//동적할당
	int* pDynamicVal = new int();// (int*)malloc(sizeof(int));//동적할당된 변수
	int* pDynmicArray = new int[nArraySize];// (int*)malloc(nArraySize * sizeof(int));//동적할당된 배열
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

	//동적할당해제
	delete pDate;
	delete pArrDate;
	delete pDynamicVal;// free(pDynamicVal);
	delete[] pDynmicArray;// free(pDynmicArray);
}

void main()
{
	DynamicAllocMain();
}