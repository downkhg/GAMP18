/*##################################
�迭�� �����Ϳ� �Լ�(������)
���ϸ�: ArrayAndPointer.cpp
�ۼ���: ��ȫ�� (downkhg@gmail.com)
������������¥: 2021.06.08
����: 1.10
###################################*/
#include <stdio.h>

void ArrayMain();
void PointerMain();
void ArrayAndPointerMain();

void InitArrayScores(int arr[], int size); //�ʱ�ȭ
void PrintIntArray(const char* msg, const int arr[], int size); //���
void PrintIntArrayPointerAddN(const char* msg, const int* pArr, int size);//���(������+n)
void PrintIntArrayAddPointer(const char* msg, int* pArr, int size);//���(������++)

void FunctionAndArrayMain();

void SwapVal(int a, int b);
void SwapPtr(int* pA, int* pB);
void SwapRef(int& a, int& b);

void FunctionAndPointerMain();

void InitFullRect(char arr2D[][5], int width, int height)
{
	printf("InitFullRect:%d\n", arr2D);
	for (int y = 0; y < height; y++)
	{
		printf("%d\n", arr2D[y]);
		for (int x = 0; x < width; x++)
		{
			//int idx = y * width + x;
			char* ArrayX = arr2D[y] + x;
			printf("%d,", ArrayX);
			*ArrayX = '*';
		}
		printf("\n");
	}
}
void InitStairs(char arr2D[][5], int width, int height)
{
	for (int y = 0; y < height; y++)
		for (int x = 0; x < y; x++)
			arr2D[y][x] = '*';
}
void InitWindow(char arr2D[][5], int width, int height)
{
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			arr2D[y][x] = '*';
}
void InitEmptyRect(char arr2D[][5], int width, int height)
{
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			arr2D[y][x] = '*';
}
//2���� �迭�� 1�����迭�� 2������ ����ŭ ���°��̴�.
//�׷��Ƿ� ���迭�� ���Ҵ� �ᱹ 1�������� �����ȴ�.
//1������ ũ�⸦ �𸣸� 2�������� ���°��� �Ұ����ϱ⶧���� ���� ���� �����Ҽ�����.
void Array2DMain()
{
	const int Width = 5;
	const int Hight = 5;
	//char arrBackGround[Hight][Width];
	char arrBackGround[][Width] = { {'*','*' ,'*' ,'*','*'},
									{'*','*' ,'*' ,'*','*'},
									{'*','*' ,'*' ,'*','*'},
									{'*','*' ,'*' ,'*','*'},
									{'*','*' ,'*' ,'*','*'}, };

	/*for (int y = 0; y < Hight; y++)
		for (int x = 0; x < Width; x++)
			arrBackGround[y][x] = '*';*/
	printf("arrBackGround:%d\n", arrBackGround);
	InitFullRect(arrBackGround, Width, Hight);

	for (int y = 0; y < Hight; y++)
	{
		for (int x = 0; x < Width; x++)
			printf("[%d,%d/%d]%c, ", x, y, &arrBackGround[y][x], arrBackGround[y][x]);
		printf("\n[%d]%d\n", y, arrBackGround[y]);
	}
	printf("\n");
}
//for���� �ߴ� ��� �׸��� �Լ� ������.
void InitFullRect(char arr[], int width, int height)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int idx = y * width + x;
			arr[idx] = '*';
		}
	}
}
void InitStairs(char arr[], int width, int height)
{
	for (int y = 0; y < height; y++)
		for (int x = 0; x < y; x++)
		{
			int idx = y * width + x;
			arr[idx] = '*';
		}
}
void InitWindow(char arr[], int width, int height)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int idx = y * width + x;
			arr[idx] = '*';
		}
	}
}
void InitEmptyRect(char arr[], int width, int height)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int idx = y * width + x;
			arr[idx] = '*';
		}
	}
}

void FakeArray2DMain()
{
	const int Width = 5;
	const int Hight = 5;
	char arrBackGround[Hight * Width];

	/*for (int y = 0; y < Hight; y++)
		for (int x = 0; x < Width; x++)
		{
			int idx = y * Width + x;
			arrBackGround[idx] = '*';
		}*/
	InitFullRect(arrBackGround, Width, Hight);
	printf("arrBackGround:%d\n", arrBackGround);
	for (int y = 0; y < Hight; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			int idx = y * Width + x; //1 * 5 + 0 //0 //6
			printf("%c", arrBackGround[idx]);
		}
		printf("\n");
		//printf("\n[%d]%d\n", y, arrBackGround[y]);
	}
	printf("\n");
}

void main()
{
	//ArrayMain();
	//PointerMain();
	//ArrayAndPointerMain();
	//FunctionAndArrayMain();
	//FunctionAndPointerMain();
	//Array2DMain();
	//FakeArray2DMain();
}
//�迭: ������ ���������� ����°�
//�ε���: �迭�� ���ҿ� �����ϱ����� �� 0 ~ n-1
//�迭�� ũ��� ����θ� ���������ϴ�.
void ArrayMain()
{
	//������ �����Ϸ��� ũ�⸦ �̿��ؼ� �޸𸮸� ����� Ȯ���Ҽ��ִ�.
	//�׷��� �����Ϸ��� ũ�⸦ �˼����ٸ�, �̸� �޸𸮸� �����ϱ� �����Ƿ�,
	//�迭�� ���鶧�� �ݵ�� ������ ����� ��밡���ϴ�.
	const int SIZE = 4;
	int arrScores[SIZE];
	int arrCopyScores[SIZE];
	//�����Ǿ����� �ʱ�ȭ�� ���� ������ ���� �����Ϸ��� �ڵ����� ó�����ش�.
	//int arrScores[] = { 10,20,30,40,50 };
	int nArrayMemorySize = sizeof(arrScores);
	int nSize = nArrayMemorySize / sizeof(arrScores[0]);
	printf("Size:%d/%d\n", nArrayMemorySize, nSize);
	printf("Array:%d, %d\n", arrScores, arrCopyScores);
	//arrCopyScores = arrScores; //�迭�� �ּҰ��� ������ ���縦 �Ҽ��� ����.
	arrScores[0] = 10; //ù��°����: 0
	arrScores[1] = 20;
	arrScores[2] = 30;
	arrScores[3] = 40;
	arrScores[4] = 50; //����������: n-1
	//OutOfRange(������ ���): ���� �����̹Ƿ� �Ժη� ����ؼ��� �ȵȴ�.
	//arrScores[5] = 60; 
	for (int i = 0; i < nSize; i++)
		printf("arrScore[%d:%d]:%d\n", i, &arrScores[i], arrScores[i]);
}
//������: �ּҰ��� ������ ����
void PointerMain()
{
	int nData = 10;
	float fData = 3.14f;
	int* pIntData = &nData;
	float* pFloatData = &fData;
	//&: �ּҰ��� ������.
	//*: �����ϴ� ������ �������� ������.
	printf("nData[%d]:%d\n", &nData, nData);
	printf("pIntData[%d]:%d\n", *pIntData, pIntData);

	printf("fData[%d]:%f\n", &fData, fData);
	printf("FloatData[%f]:%d\n", *pFloatData, pFloatData);
}
//�迭�� ������: �迭�� �����Ϳ����� ������ �̿��Ͽ� �����Ǿ�����.
void ArrayAndPointerMain()
{
	//���������� �ݵ�� �迭�� ũ�⸦ �Ҵ��ؾ� ������������ ���������ϴ�.
	const int SIZE = 4;
	int arrScores[SIZE];

	for (int i = 0; i < SIZE; i++)
		arrScores[i] = i * 25;

	printf("Scores(%d):", arrScores);
	for (int i = 0; i < SIZE; i++)
		printf("[%d]%d,", i, arrScores[i]);
	printf("\n");
	//�迭�� �̸����� �̸��� ������ �����Ϳ� �����ϰ� �����Ϳ����� �Ѵ�.
	//�����Ϳ���: �����Ϳ��� ���� ���ϸ� (�޸���ũ��*���Ѽ���) ��ŭ �����Ѵ�.
	int* pArrScores = arrScores;
	printf("pScores+i:");
	for (int i = 0; i < SIZE; i++)
		printf("[%d/%d]%d,", i, pArrScores + i, *(pArrScores + i));
	printf("\n");
	printf("pScores++:");
	for (int i = 0; i < SIZE; i++)
		printf("[%d/%d]%d,", i, pArrScores++, *pArrScores);
	printf("\n");
	//�������� ������ �޸𸮴� ���� �ּ��̹Ƿ� ��Ÿ�ӿ����� �߻��Ѵ�.
	//printf("pScore[%d]:%d\n",pArrScores,*pArrScores);
}
//�迭�� �Ű������� ���޹������ ũ�⸦ ����Ҽ�����.
//void InitArrayScores(int arr[])
//{
//	int nSize = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < nSize; i++)
//		arr[i] = i * 25;
//}
//void PrintIntArray(const char* msg, int arr[],)
//{
//	int nSize = sizeof(arr) / sizeof(arr[0]);
//	printf("%s(%d):", msg, arr);
//	for (int i = 0; i < nSize; i++)
//		printf("[%d]%d,", i, arr[i]);
//	printf("\n");
//}
void InitArrayScores(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = i * 25;
}
void PrintIntArray(const char* msg, const int arr[], int size)
{
	printf("%s(%d):", msg, arr);
	for (int i = 0; i < size; i++)
		printf("[%d]%d,", i, arr[i]);
	printf("\n");
}
void PrintIntArrayPointerAddN(const char* msg, const int* pArr, int size)
{
	printf("%s(%d):", msg, pArr);
	for (int i = 0; i < size; i++)
	{
		const int* pData = pArr + i;
		printf("[%d/%d]%d,", i, pData, *pData);
		//*pData = 0; //������ ���� �����Ҽ�����.
	}
	printf("\n");
}
void PrintIntArrayAddPointer(const char* msg, int* pArr, int size)
{
	printf("%s(%d):", msg, pArr);
	for (int i = 0; i < size; i++)
		printf("[%d/%d]%d,", i, pArr++, *pArr);
	printf("\n");
}
//�迭�� �Ű������� �����ϸ� �迭�� ���� ������ �����ϴ�.
void FunctionAndArrayMain()
{
	//���������� �ݵ�� �迭�� ũ�⸦ �Ҵ��ؾ� ������������ ���������ϴ�.
	const int SIZE = 4;
	int arrScores[SIZE];

	InitArrayScores(arrScores, SIZE); //�迭�� ������ �ʱ�ȭ
	PrintIntArray("ArrScores:", arrScores, SIZE); //�迭�� �ε����������� ����Ѵ�.
	//�迭�� �̸����� �̸��� ������ �����Ϳ� �����ϰ� �����Ϳ����� �Ѵ�.
	//�����Ϳ���: �����Ϳ��� ���� ���ϸ� (�޸���ũ��*���Ѽ���) ��ŭ �����Ѵ�.
	int* pArrScores = arrScores;
	PrintIntArrayPointerAddN("ArrScores+n:", arrScores, SIZE);//�迭�� ������+n�� �̿��Ͽ� ���Ҹ� ����Ѵ�.
	PrintIntArrayAddPointer("ArrScores++:", arrScores, SIZE);//�迭�� ������++������ �̿��Ͽ� ���Ҹ� ����Ѵ�.
	//�������� ������ �޸𸮴� ���� �ּ��̹Ƿ� ��Ÿ�ӿ����� �߻��Ѵ�.
	//printf("pScore[%d]:%d\n", pArrScores, *pArrScores); 
}

void SwapVal(int a, int b)
{
	printf("SwapVal[%d]%d<->[%d]%d\n", &a, a, &b, b);
	int temp = a;
	a = b;
	b = temp;
}
void SwapPtr(int* pA, int* pB)
{
	printf("SwapPtr[%d]%d<->[%d]%d\n", pA, *pA, pB, *pB);
	int temp = *pA;
	*pA = *pB;
	*pB = temp;
}
void SwapRef(int& a, int& b)//������: ������ ���޹���.
{
	printf("SwapRef[%d]%d<->[%d]%d\n", &a, a, &b, b);
	int temp = a;
	a = b;
	b = temp;
}
void FunctionAndPointerMain()
{
	int nDataA = 10;
	int nDataB = 20;
	printf("Origin[%d]%d<->[%d]%d\n", &nDataA, nDataA, &nDataB, nDataB);
	SwapVal(nDataA, nDataB);
	printf("SwapVal[%d]%d<->[%d]%d\n", &nDataA, nDataA, &nDataB, nDataB);
	SwapPtr(&nDataA, &nDataB);
	printf("SwapPtr[%d]%d<->[%d]%d\n", &nDataA, nDataA, &nDataB, nDataB);
	SwapRef(nDataA, nDataB);
	printf("SwapRef[%d]%d<->[%d]%d\n", &nDataA, nDataA, &nDataB, nDataB);
}