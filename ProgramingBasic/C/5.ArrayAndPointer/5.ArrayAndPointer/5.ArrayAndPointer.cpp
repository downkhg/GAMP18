#include <stdio.h>
#define ARRAY_SIZE  5
//�迭
void ArrayMain()
{
	//�迭�� ũ��� �̸� ������ Ȯ���ؾ��ϹǷ�, 
	//������ �ɼ��ִ� ������ ����Ҽ�����.
	//�׷��Ƿ�, ����� ��ó���⸦ �̿��Ͽ� �迭�� ũ�⸦ �����ؾ��Ѵ�.
	const int nSize = 4;
	//nSize = 6; //?????
	//int arrScores[4] = {100,90,80,70};//�迭�� �ʱ�ȭ�Ҷ� �Ѳ����� �ʱ�ȭ�� �����ϴ�.
	int arrScores[nSize] = {100,90,80,70};//�迭�� �ʱ�ȭ�Ҷ� �Ѳ����� �ʱ�ȭ�� �����ϴ�.
	//arrScores[0] = 100;//������ 0���� �����Ѵ�. �迭�� ���۰�����  0�� ���ؾ� �����ּҰ� ���´�.
	//arrScores[1] = 90;
	//arrScores[2] = 80;
	//arrScores[3] = 70;//���̰� n�̶�� n-1������ �迭�� ��.
	//arrScores[4] = 60;//�Ҵ�������� �޸𸮸� Ȱ����. ���������� �ؼ��� �ȵ�.

	printf("arrScore:%d\n",arrScores);//�迭���̸��� �迭�� �����ּҸ� �����Ѵ�.
	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]%d,",&arrScores[i], i,arrScores[i]);
	printf("\n");

	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]%d,", (arrScores+i), i, *(arrScores+i));
	printf("\n");
	//������: �޸��� �ּҰ��� �����ϴ� ����
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