#include <stdio.h>//ǥ������� ���̺귯��

//10�� 20�� �� �Ͽ� ����ϴ� ���α׷������
//����� ����� Ȯ���� �� ����.
//�׷��Ƿ�, ����� Ȯ���ϱ����ؼ� ����ؾ��Ѵ�.
void AplusBMain()//�Լ��� ����
{
	////10�� 20�� ���Ͽ� ����ϴ� ���α׷��� �����
	//printf("%d",10 + 20);
	////(a:������-����)�� (b:������-����)�� ���ؼ� (���:printf)�ϴ� ���α׷� �����
	//int a = 0;
	//int b = 0;
	//printf("%d", a + b);
	//(a:������-����)�� (b:������-����)�� ���ؼ� (���:printf)�ϴ� ���α׷� �����(��, a�� b�� (�Է�)�޴´�)
	int a;
	int b;
	scanf("%d", &a); 
	scanf("%d", &b);
	printf("%d", a + b);
}
//����: �����͸� �����ϴ� ����.
//������, ����(�˰���)
//���� (����) ���ϴ� ���α׷�
//(��, ���Ǹ����� (������)*(������)*(3.14) �̴�)
//����,������,3.14->������ -> ���� > �Ǽ�
//������*������*3.14 = ���� -> �˰���
//�������Ƿ� ����ϸ� �Ҽ������� ������������Ƿ�, �Ǽ��� ����Ҷ��� �Ǽ��� �̿��ϴ°��� ����.
#define PI 3.14
void CircleAreaMain()
{
	int nRad;
	int nArea;
	const float fPi = 3.14f;//��� ����: ������ �ʱⰪ�� �����Ҽ� ����.(�޸� ���)
	//fPi = 3;
	printf("Input Radius:");
	scanf("%d",&nRad);

	//nArea = (nRad * nRad) * fPi;
	nArea = (nRad * nRad) * PI; //�����Ϸ��ܿ��� ���ǵȼ��ڷ� ��ü���ش�(�޸𸮸� �����������)
	printf("%d*%d*%f = %d", nRad, nRad,fPi, nArea);
}

//�簢���� (����)�� ���ϱ�(��, �簢���� ������ (����)*(����) �̴�)
//������: ����,����,���� -> ����
//�˰���(����): ���� = ���� * ����
//���̿� ���̴� �����Ǿ����������Ƿ� (�Է�:scanf)�޵��� �����
//���� ������ (���:printf)�ض�.
void RectAreaMain()
{
	float fWidth;
	float fHeight;
	printf("RectHW ex) 100 20\n");
	scanf("%f %f",&fWidth, &fHeight);
	float fArea = fWidth * fHeight;
	printf("%f = %f * %f\n", fArea, fWidth, fHeight);
}

void SizeMain()
{
	//int x;//������ �ʱ�ȭ���������� �����Ⱚ�� ����ȴ�.
	int x = 0;//������ �ʱ�ȭ: ������ ���� ������ �����ϴ°�.

	printf("x[%d]:%d\n", sizeof(x),x);
	printf("char: %d\n", sizeof(char));
	printf("int: %d\n", sizeof(int));
	printf("short: %d\n", sizeof(short));
	printf("long: %d\n", sizeof(long));
	printf("float: %d\n", sizeof(float));
	printf("double: %d\n", sizeof(double));
}

//IDE: ���հ���ȯ��
void main()
{ //����(��)
	//�ּ�: �����Ϸ��� �м������ʴ� ����.
	//Ctrl+F5: ����ž��� ����
	//�����: ���α׷� ���� ������ �ϰ� �ش���¸� Ȯ���ϴµ� ����ϴ� ��.
	//F9/F10/F11: �ߴ���/���پ�����/�Լ������� �̵�
	//printf("Hello World!!!\n");//\n:�ٹٲ޹���
	//�ڽ��� �̴ϼ����
	//printf("khg\n"); //;�����ݷ�
	//AplusBMain();//�Լ��� ȣ��
	//CircleAreaMain();
	//SizeMain();
	RectAreaMain();
}