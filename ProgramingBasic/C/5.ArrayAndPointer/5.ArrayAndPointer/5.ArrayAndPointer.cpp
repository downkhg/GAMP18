#include <stdio.h>
#define ARRAY_SIZE  5
//배열
void ArrayMain()
{
	//배열의 크기는 미리 공간을 확보해야하므로, 
	//변경이 될수있는 변수를 사용할수없다.
	//그러므로, 상수나 전처리기를 이용하여 배열의 크기를 지정해야한다.
	const int nSize = 4;
	//nSize = 6; //?????
	//int arrScores[4] = {100,90,80,70};//배열을 초기화할때 한꺼번에 초기화가 가능하다.
	int arrScores[nSize] = {100,90,80,70};//배열을 초기화할때 한꺼번에 초기화가 가능하다.
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
	int* pScores = arrScores;
	printf("1. PtrScore[%d]:%d\n", pScores, *pScores);
	for (int i = 0; i < nSize; i++)
	{
		printf("[%d/%d]%d,", (pScores), i, *pScores);
		pScores++;
	}
	printf("\n");
	printf("2. PtrScore[%d]:%d\n", pScores, *pScores);
}

void main()
{
	ArrayMain();
}