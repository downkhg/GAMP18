/*##################################
배열과 포인터와 함수(수업용)
파일명: ArrayAndPointer.cpp
작성자: 김홍규 (downkhg@gmail.com)
마지막수정날짜: 2021.06.08
버전: 1.10
###################################*/
#include <stdio.h>

void ArrayMain();
void PointerMain();
void ArrayAndPointerMain();

void InitArrayScores(int arr[], int size); //초기화
void PrintIntArray(const char* msg, const int arr[], int size); //출력
void PrintIntArrayPointerAddN(const char* msg, const int* pArr, int size);//출력(포인터+n)
void PrintIntArrayAddPointer(const char* msg, int* pArr, int size);//출력(포인터++)

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
//2차원 배열은 1차원배열을 2차원의 수만큼 놓는것이다.
//그러므로 각배열의 원소는 결국 1차원으로 생성된다.
//1차원의 크기를 모르면 2차원으로 놓는것이 불가능하기때문에 넓이 값은 생략할수없다.
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
//for문때 했던 모양 그리기 함수 만들어보기.
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
//배열: 변수를 연속적으로 만드는것
//인덱스: 배열의 원소에 접근하기위한 것 0 ~ n-1
//배열의 크기는 상수로만 지정가능하다.
void ArrayMain()
{
	//변수는 컴파일러가 크기를 이용해서 메모리를 충분히 확보할수있다.
	//그러나 컴파일러가 크기를 알수없다면, 미리 메모리를 관리하기 어려우므로,
	//배열을 만들때는 반드시 지정된 상수만 사용가능하다.
	const int SIZE = 4;
	int arrScores[SIZE];
	int arrCopyScores[SIZE];
	//생략되었지만 초기화될 값의 갯수를 세어 컴파일러가 자동으로 처리해준다.
	//int arrScores[] = { 10,20,30,40,50 };
	int nArrayMemorySize = sizeof(arrScores);
	int nSize = nArrayMemorySize / sizeof(arrScores[0]);
	printf("Size:%d/%d\n", nArrayMemorySize, nSize);
	printf("Array:%d, %d\n", arrScores, arrCopyScores);
	//arrCopyScores = arrScores; //배열의 주소값을 가지고 복사를 할수는 없다.
	arrScores[0] = 10; //첫번째원소: 0
	arrScores[1] = 20;
	arrScores[2] = 30;
	arrScores[3] = 40;
	arrScores[4] = 50; //마지막원소: n-1
	//OutOfRange(범위를 벗어남): 없는 원소이므로 함부로 사용해서는 안된다.
	//arrScores[5] = 60; 
	for (int i = 0; i < nSize; i++)
		printf("arrScore[%d:%d]:%d\n", i, &arrScores[i], arrScores[i]);
}
//포인터: 주소값을 가지는 변수
void PointerMain()
{
	int nData = 10;
	float fData = 3.14f;
	int* pIntData = &nData;
	float* pFloatData = &fData;
	//&: 주소값을 가져옴.
	//*: 참조하는 변수가 가진값에 접근함.
	printf("nData[%d]:%d\n", &nData, nData);
	printf("pIntData[%d]:%d\n", *pIntData, pIntData);

	printf("fData[%d]:%f\n", &fData, fData);
	printf("FloatData[%f]:%d\n", *pFloatData, pFloatData);
}
//배열과 포인터: 배열은 포인터연산의 원리를 이용하여 구현되어있음.
void ArrayAndPointerMain()
{
	//컴파일전에 반드시 배열의 크기를 할당해야 랜덤엑세스가 구현가능하다.
	const int SIZE = 4;
	int arrScores[SIZE];

	for (int i = 0; i < SIZE; i++)
		arrScores[i] = i * 25;

	printf("Scores(%d):", arrScores);
	for (int i = 0; i < SIZE; i++)
		printf("[%d]%d,", i, arrScores[i]);
	printf("\n");
	//배열의 이름에서 이름을 가져와 포인터에 저장하고 포인터연산을 한다.
	//포인터연산: 포인터에서 값을 더하면 (메모리의크기*더한숫자) 만큼 증가한다.
	int* pArrScores = arrScores;
	printf("pScores+i:");
	for (int i = 0; i < SIZE; i++)
		printf("[%d/%d]%d,", i, pArrScores + i, *(pArrScores + i));
	printf("\n");
	printf("pScores++:");
	for (int i = 0; i < SIZE; i++)
		printf("[%d/%d]%d,", i, pArrScores++, *pArrScores);
	printf("\n");
	//마지막에 증가된 메모리는 없는 주소이므로 런타임오류가 발생한다.
	//printf("pScore[%d]:%d\n",pArrScores,*pArrScores);
}
//배열을 매개변수로 전달받은경우 크기를 계산할수없다.
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
		//*pData = 0; //원본의 값을 변경할수없다.
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
//배열을 매개변수로 전달하면 배열의 값을 변경이 가능하다.
void FunctionAndArrayMain()
{
	//컴파일전에 반드시 배열의 크기를 할당해야 랜덤엑세스가 구현가능하다.
	const int SIZE = 4;
	int arrScores[SIZE];

	InitArrayScores(arrScores, SIZE); //배열에 점수를 초기화
	PrintIntArray("ArrScores:", arrScores, SIZE); //배열을 인덱스접근으로 출력한다.
	//배열의 이름에서 이름을 가져와 포인터에 저장하고 포인터연산을 한다.
	//포인터연산: 포인터에서 값을 더하면 (메모리의크기*더한숫자) 만큼 증가한다.
	int* pArrScores = arrScores;
	PrintIntArrayPointerAddN("ArrScores+n:", arrScores, SIZE);//배열을 포인터+n을 이용하여 원소를 출력한다.
	PrintIntArrayAddPointer("ArrScores++:", arrScores, SIZE);//배열을 포인터++연산을 이용하여 원소를 출력한다.
	//마지막에 증가된 메모리는 없는 주소이므로 런타임오류가 발생한다.
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
void SwapRef(int& a, int& b)//참조자: 원본을 전달받음.
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