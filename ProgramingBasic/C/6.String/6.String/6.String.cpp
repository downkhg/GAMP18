#include <stdio.h>
#include <string.h>
//���ڿ�: ���ڹ迭. ���������ڿ� �ι��ڸ� ����Ѵ�.
void StringMain()
{
	const int  nSize = 12;
	int i = 0;
	//char str[4] = "abc";//���������� �ʱ�ȭ�ϸ� ���ڿ����� �ڵ����� ����.
	char str[nSize] = "apple";//�ʱ�ȭ�� �����Ǹ� ũ�⸦ �����ִ�. // a/p/p/l/e/\0
																	 // 0/1/2/3/4/5
	/*str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';*/
	//str[3] = '\0';//�ι���: ���ڿ����� �˸�.
	strcpy(str, "d");
	for (int i = 0; i < nSize; i++) printf("%c", str[i]); printf("\n");
	while (str[i] != 0)//'\0' == 0
	{
		printf("%c[%d],",str[i],&str[i]);
		i++;
	}
	printf(":%d\n",i);

	printf("%s\n",str);

	char copyStr[nSize] = "";

	//copyStr = str; //�ּҰ��� ��ġ��ų������.
	strcpy(copyStr, str); //�ι��ڰ� ���������� ����
	memcpy(copyStr, str, sizeof(str)); //������ũ�⸸ŭ�� ����
	//strcpy(str, copyStr); //�ι��ڰ� ���������� ����
	//memcpy(str, copyStr, sizeof(str)); //������ũ�⸸ŭ�� ����
	strcpy(copyStr, "fake"); //���ڿ��� �����ϰ������ ����Ҽ�����.
	printf("%s[%d]/%s[%d]:", copyStr, copyStr, str, str);
}

//���� �̸��� �Է¹޾Ƽ� �ѱ����̸��̳� �̱��� �̸����� ��ȯ�Ͽ� ����ϴ� ���α׷�.
//������: ��, �̸�, Ǯ���� (���ڿ�)
//�˰���: �ѱ���: �� + �̸� = Ǯ����, �̱���: �̸�+�� = Ǯ����
void StringLibraryMain()
{
	char strLastName[100] = "k";
	char strFirstName[100] = "hg";
	char strFullName[200];

	//en: strFullName = strFirstName + strLastName; //���ڿ���ü�� ����ϸ� �����ϴ�.
	//ù�̸��� �����Ͽ� Ǯ���ӿ� �־����.
	strcpy(strFullName, strFirstName);
	//���ڿ��� ���ļ� ���ϴ� Ǯ������ ��������.
	strcat(strFullName, strLastName);

	printf("en: %s\n", strFullName);
	//kr: strFullName = strLastName + strFirstName; 

	strcpy(strFullName, strLastName);
	strcat(strFullName, strFirstName);

	printf("kr: %s\n", strFullName);

	printf("strcmp(%s,%s):%d\n", strFirstName, strLastName, strcmp(strFirstName, strLastName));
	printf("strcmp(%s,%s):%d\n", strLastName, strFirstName, strcmp(strLastName, strFirstName));
	printf("strcmp(%s,%s):%d\n", strFirstName, strFirstName, strcmp(strFirstName, strFirstName));
	//strcmp�� ���� ���ڿ��̸� 0�� ��ȯ�ϹǷ� �̰;ƴ� ����� 1�̵ǹǷ� ��. ���̵ȴ�.
	//������� ���ڿ��� ������ ������ ���´� ������ ����ص��ȴ�.
	if (!strcmp(strFirstName, strFirstName))
		printf("%s == %s", strFirstName, strFirstName);
	else
		printf("%s != %s", strFirstName, strFirstName);
}

void main()
{
	//StringMain();
	StringLibraryMain();
}