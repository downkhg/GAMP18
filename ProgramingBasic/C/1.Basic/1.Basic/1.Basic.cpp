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

void CharTestMain()
{
	//�ƽ�Ű�ڵ�: �̱�ǥ�� ����
	char cCodeA = 'A';
	int nCodeA = 65;
	char cCodeB = 'B';
	int nCodeB = 66;

	printf("A:%d/%c\n", nCodeA, cCodeA);
	printf("B:%d/%c\n", nCodeB, cCodeB);

	printf("A:%d/%c\n", cCodeA, nCodeA);
	printf("B:%d/%c\n", cCodeB, nCodeB);
}
//���� ������ �����ϴ� �ð��� ���Ͽ���.
//��, ���� �ӵ��� 30��km/s
//�¾�� �������� �Ÿ��� 1��4960���̴�.
//�ð��� �ʷ� ���ϱ�
//�ð��� ��:�ʷ� ���ϱ�
//������: �¾���������̰Ÿ�,���Ǽӵ� ->�Ǽ�, �ð�(��)->����
//�˰���: �¾�� �������� �Ÿ��� �ʴ� ���� �̵��Ÿ��� ��� ���°�? 
//�¾���������̰Ÿ� / ���Ǽӵ� = ���� ������ ������ �ð�(��)
void LightSpeedMain()
{
	float fDist = 14960;
	float fLightSpeed = 30;

	int nSec = fDist / fLightSpeed;

	printf("%d sec\n",nSec);
	int nMin = nSec / 60;
	nSec = nSec - nMin * 60;
	nSec = nSec % 60;
	printf("%d:%d\n", nMin, nSec);
}

void OpMain()
{
	int nDataA = 10;
	int nDataB = 20;
	int nResultA;
	int nResultB;

	nResultA = ++nDataA; //11 //���������̵�
	nResultB = nDataB++; //20 //�������� ������ �Ͼ.

	printf("Data/ResultA:%d/%d\n", nDataA, nResultA);//11/11
	printf("Data/ResulaB:%d/%d\n", nDataB, nResultB);//21/20

	//���ʿ� �����ڵ����������� �̷������� ����.
	nDataA++; //12
	nResultA = nDataA; //12
	++nDataB; //22
	nResultB = nDataB; //22

	printf("Data/ResultA:%d/%d\n", nDataA, nResultA);//11/11
	printf("Data/ResulaB:%d/%d\n", nDataB, nResultB);//21/20

	nDataA = nDataA + 1; //12+1 -> 13
	printf("DataA:%d\n", nDataA);//13

	nDataB += 1; //22+1 -> 23
	printf("DataB:%d\n", nDataB);//23

	//��x,y�� �Է¹޾� ���迬���� ����� ����϶�
	//(��, ���迬���� ==,!=,<,>,<=,<=�� �ִ�.)
	//{
	//	float x, y;
	//	//1:�� 0:����
	//	//�������� Ȯ���Ҽ��ֵ��� ���� ��� Ȯ���غ��°��� �߿��ϴ�.
	//	scanf("%f %f", &x, &y); //10 20, 20 10, 10 10
	//	printf("%f == %f = %d\n", x, y, x == y); //10�� 20�� ���� = 0, 0, 1 
	//	printf("%f != %f = %d\n", x, y, x != y); //10�� 20�� �ٸ��� = 1, 1, 0
	//	printf("%f < %f = %d\n", x, y, x < y); //10���� 20�� ũ�� = 1, 0 , 0
	//	printf("%f > %f = %d\n", x, y, x > y); //10���� 20�� �۴� = 0, 1 , 0
	//	printf("%f <= %f = %d\n", x, y, x <= y); //10���� 20�� ũ�ų� ���� = 1 0 , 1
	//	printf("%f >= %f = %d\n", x, y, x >= y); //10���� 20�� �۰ų� ���� = 0 1 , 1
	//}

	//2 < x < 5�� �������� ���α׷��ֿ��� �����ϰ� ����϶�.
	//(��, x�� ���� �Է¹޴´�.)
	{
		int x;
		scanf("%d", &x);//3
		printf("2 < x = %d\n", 2 < x); //2���� 3�� ũ�� O 
		printf("x < 5 = %d\n", x < 5); //2���� 5�� ũ�� X
		printf("2 < x < 5 = %d\n", 2 < x && x < 5); //O && X // &&:�Ѵ� ��
	}
}

void BitMaskMain()
{
	//16����: 0~9 A(10)~F(15)
	unsigned int color = 0x00385555;
	unsigned int result;

	printf("PixelColor:%#08x\n",color);
	result = color & 0x00ffff00;
	printf("Mask:%#08x\n", result);
	result = result >> 16;
	printf("Result:%#08x\n", result);
}
//������ �Է��ϸ� A~F������ ����� ����ϴ� ���α׷� �����
//(��, A: 100~91, B: 90~81, C:80~71, D:70~61, F:60~0)
//������: ����-int, ���-char:
//�˰���: A-100 >= S > 90, B-90 >= S > 80, C-80 >= S > 70, D-70 >= S > 60, F: 60 >= S 
void GradeTestIfMain()
{
	int nScore; //S
	char cGrade;

	if (100 >= nScore && nScore > 90)
		cGrade = 'A';
	if (90 >= nScore && nScore > 80)
		cGrade = 'B';
	if (80 >= nScore && nScore > 70)
		cGrade = 'C';
	if (70 >= nScore && nScore > 60)
		cGrade = 'D';
	if (60 >= nScore)
		cGrade = 'F';

	printf("Score/Grade: %d:%c\n",nScore, cGrade);
}

void GradeTestIfElseMain()
{
	int nScore; //S
	char cGrade;

	
	if (nScore > 90)
		cGrade = 'A';
	else if (nScore > 80)
		cGrade = 'B';
	else if (nScore > 70)
		cGrade = 'C';
	else if (nScore > 60)
		cGrade = 'D';
	else
		cGrade = 'F';

	printf("Score/Grade: %d:%c\n", nScore, cGrade);
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
	//RectAreaMain();
	//CharTestMain();
	//LightSpeedMain();
	//OpMain();
	BitMaskMain();
}