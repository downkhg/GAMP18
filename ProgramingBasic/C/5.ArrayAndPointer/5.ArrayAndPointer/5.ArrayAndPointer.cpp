#include <stdio.h>
#include <string.h>
#define ARRAY_SIZE  5

void CopyArray(const int arr[], int copyarr[], int size);
void CopyArrayPtr(const int* arr, int* copyarr, int size);

//배열: 변수를 나열하여 데이터를 순서대로 접근 가능하도록한 것.
void ArrayMain()
{
	//배열의 크기는 미리 공간을 확보해야하므로, 
	//변경이 될수있는 변수를 사용할수없다.
	//그러므로, 상수나 전처리기를 이용하여 배열의 크기를 지정해야한다.
	const int nSize = 4;
	//nSize = 6; //?????
	//int arrScores[4] = {100,90,80,70};//배열을 초기화할때 한꺼번에 초기화가 가능하다.
	int arrScores[nSize] = {100,90,80,70};//배열을 초기화할때 한꺼번에 초기화가 가능하다.
	//int arrScores[] = { 100,90,80,70 };//배열을 초기화할때 갯수를 생략하더라도 초기화 숫자를 지정하면 자동으로 크기를 지정한다.
	int arrSize = sizeof(arrScores) / sizeof(arrScores[0]);//메모리의크기/변수의크기 int * 4 = 16 / 4 = 4
	//arrScores[0] = 100;//시작은 0부터 시작한다. 배열의 시작값에서  0을 더해야 시작주소가 나온다.
	//arrScores[1] = 90;
	//arrScores[2] = 80;
	//arrScores[3] = 70;//길이가 n이라면 n-1마지막 배열의 값.
	//arrScores[4] = 60;//할당되지않은 메모리를 활용함. 가능하지만 해서는 안됨.

	printf("arrScore:%d\n",arrScores);//배열의이름은 배열의 시작주소를 저장한다.
	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]%d,",&arrScores[i], i,arrScores[i]);
	printf("\n");

	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]%d,", (arrScores+i), i, *(arrScores+i));
	printf("\n");
	//포인터: 메모리의 주소값을 저장하는 변수
	//*포인터: 포인터가 가르키는 메모리의 변수값을 가져옴.
	//포인터가 참조하는 변수의 값을 출력한다.
	int* pScores = arrScores;
	printf("1. PtrScore[%d]:%d\n", pScores, *pScores);
	for (int i = 0; i < nSize; i++)
	{
		printf("[%d/%d]%d,", pScores, i, *pScores);
		pScores++;//메모리의 크기만큼 증가
	}
	printf("\n");
	printf("2. PtrScore[%d]:%d\n", pScores, *pScores);//사용하지않는 메모리에 접근하면안된다.

	int arrCopyScore[nSize];
	//arrCopyScore = arrScores;
	printf("%d = %d\n", arrScores, arrCopyScore);

	//memcpy(arrCopyScore, arrScores, sizeof(arrCopyScore)); //메모리카피를 이용하여 더효률적인 복사가 가능하다.
	//for (int i = 0; i < nSize; i++)
	//	arrCopyScore[i] = arrScores[i];
	CopyArrayPtr(arrScores, arrCopyScore, nSize);

	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]%d,", &arrCopyScore[i], i, arrCopyScore[i]);
}
//const배열/포인터: 전달받은 값의 원본대상의 값을 변경할수없다.
void CopyArray(const int arr[], int copyarr[], int size)
{
	printf("CopyArray[%d/%d]\n",arr,copyarr);
	for (int i = 0; i < size; i++)
		copyarr[i] = arr[i];
		//arr[i] = copyarr[i]
		
}

void CopyArrayPtr(const int* arr, int* copyarr, int size)
{
	printf("CopyArray[%d/%d]\n", arr, copyarr);
	for (int i = 0; i < size; i++)
		copyarr[i] = arr[i];
	//arr[i] = copyarr[i]

}

void PointerMain()
{
	int nData = 10;
	float fData = 3.14f;
	int* pIntData = &nData;
	float* pFloatData = &fData;
	//&: 주소값을 가져옴.
	//*: 참조하는 변수가 가진값에 접근함.
	printf("nData[%d]:%d\n", &nData, nData);//0x01,10
	printf("pIntData[%d]:%d\n", *pIntData, pIntData);//10, 0x01

	printf("fData[%d]:%f\n", &fData, fData);//0x05,3.14
	printf("FloatData[%f]:%d\n", *pFloatData, pFloatData);//3.14,0x05
}

void main()
{
	//ArrayMain();
	PointerMain();
}