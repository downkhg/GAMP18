#include <stdio.h>
#include <string.h>
#define ARRAY_SIZE  5

void CopyArray(const int arr[], int copyarr[], int size);
void CopyArrayPtr(const int* arr, int* copyarr, int size);

//�迭: ������ �����Ͽ� �����͸� ������� ���� �����ϵ����� ��.
void ArrayMain()
{
	const int nSize = 3;
	int arrScores[nSize];
	int arrSize = sizeof(arrScores) / sizeof(arrScores[0]);
	for (int i = 0; i < nSize; i++)
		arrScores[i] = 100 - i * 10;
	printf("arrScore[%d]:%d\n",&arrScores,arrScores);
	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]%d,",&arrScores[i], i,arrScores[i]);
	printf("\n");

	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]%d,", (arrScores+i), i, *(arrScores+i));
	printf("\n");

	int* pScores = arrScores;
	printf("1. PtrScore[%d]:%d\n", pScores, *pScores);
	for (int i = 0; i < nSize; i++)
	{
		printf("[%d/%d]%d,", pScores, i, *pScores);
		pScores++;
	}
	printf("\n");
	int arrCopyArray[nSize];
	for (int i = 0; i < nSize; i++)
		arrCopyArray[i] = arrScores[i];
	memcpy(arrCopyArray, arrScores, nSize);
}
//const�迭/������: ���޹��� ���� ��������� ���� �����Ҽ�����.
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
	//&: �ּҰ��� ������.
	//*: �����ϴ� ������ �������� ������.
	printf("nData[%d]:%d\n", &nData, nData);//0x01,10
	printf("pIntData[%d]:%d\n", *pIntData, pIntData);//10, 0x01

	printf("fData[%d]:%f\n", &fData, fData);//0x05,3.14
	printf("FloatData[%f]:%d\n", *pFloatData, pFloatData);//3.14,0x05
}

void main()
{
	ArrayMain();
	//PointerMain();
}