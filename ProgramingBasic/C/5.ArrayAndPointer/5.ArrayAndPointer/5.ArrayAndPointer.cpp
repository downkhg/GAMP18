#include <stdio.h>
#include <string.h>
#define ARRAY_SIZE  5
//�迭: ������ �����Ͽ� �����͸� ������� ���� �����ϵ����� ��.
void ArrayMain()
{
	//�迭�� ũ��� �̸� ������ Ȯ���ؾ��ϹǷ�, 
	//������ �ɼ��ִ� ������ ����Ҽ�����.
	//�׷��Ƿ�, ����� ��ó���⸦ �̿��Ͽ� �迭�� ũ�⸦ �����ؾ��Ѵ�.
	const int nSize = 4;
	//nSize = 6; //?????
	//int arrScores[4] = {100,90,80,70};//�迭�� �ʱ�ȭ�Ҷ� �Ѳ����� �ʱ�ȭ�� �����ϴ�.
	int arrScores[nSize] = {100,90,80,70};//�迭�� �ʱ�ȭ�Ҷ� �Ѳ����� �ʱ�ȭ�� �����ϴ�.
	//int arrScores[] = { 100,90,80,70 };//�迭�� �ʱ�ȭ�Ҷ� ������ �����ϴ��� �ʱ�ȭ ���ڸ� �����ϸ� �ڵ����� ũ�⸦ �����Ѵ�.
	int arrSize = sizeof(arrScores) / sizeof(arrScores[0]);//�޸���ũ��/������ũ�� int * 4 = 16 / 4 = 4
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
	//*������: �����Ͱ� ����Ű�� �޸��� �������� ������.
	//�����Ͱ� �����ϴ� ������ ���� ����Ѵ�.
	int* pScores = arrScores;
	printf("1. PtrScore[%d]:%d\n", pScores, *pScores);
	for (int i = 0; i < nSize; i++)
	{
		printf("[%d/%d]%d,", pScores, i, *pScores);
		pScores++;//�޸��� ũ�⸸ŭ ����
	}
	printf("\n");
	printf("2. PtrScore[%d]:%d\n", pScores, *pScores);//��������ʴ� �޸𸮿� �����ϸ�ȵȴ�.

	int arrCopyScore[nSize];
	//arrCopyScore = arrScores;
	printf("%d = %d\n", arrScores, arrCopyScore);

	//memcpy(arrCopyScore, arrScores, sizeof(arrCopyScore)); //�޸�ī�Ǹ� �̿��Ͽ� ��ȿ������ ���簡 �����ϴ�.
	for (int i = 0; i < nSize; i++)
		arrCopyScore[i] = arrScores[i];

	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]%d,", &arrCopyScore[i], i, arrCopyScore[i]);
}

void main()
{
	ArrayMain();
}