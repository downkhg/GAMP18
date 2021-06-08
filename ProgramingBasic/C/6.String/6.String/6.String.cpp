#include <stdio.h>
#include <string.h>
//문자열: 문자배열. 마지막문자에 널문자를 사용한다.
void StringMain()
{
	const int  nSize = 12;
	int i = 0;
	//char str[4] = "abc";//다음과같이 초기화하면 문자열끝이 자동으로 들어간다.
	char str[nSize] = "apple";//초기화때 지정되면 크기를 비울수있다. // a/p/p/l/e/\0
																	 // 0/1/2/3/4/5
	/*str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';*/
	//str[3] = '\0';//널문자: 문자열끝을 알림.
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

	//copyStr = str; //주소값을 대치시킬수없음.
	strcpy(copyStr, str); //널문자가 있을때까지 복사
	memcpy(copyStr, str, sizeof(str)); //정해진크기만큼만 복사
	//strcpy(str, copyStr); //널문자가 있을때까지 복사
	//memcpy(str, copyStr, sizeof(str)); //정해진크기만큼만 복사
	strcpy(copyStr, "fake"); //문자열을 변경하고싶을때 사용할수있음.
	printf("%s[%d]/%s[%d]:", copyStr, copyStr, str, str);
}

//성과 이름을 입력받아서 한국형이름이나 미국형 이름으로 변환하여 출력하는 프로그램.
//데이터: 성, 이름, 풀네임 (문자열)
//알고리즘: 한국형: 성 + 이름 = 풀네임, 미국형: 이름+성 = 풀네임
void StringLibraryMain()
{
	char strLastName[100] = "k";
	char strFirstName[100] = "hg";
	char strFullName[200];

	//en: strFullName = strFirstName + strLastName; //문자열객체를 사용하면 가능하다.
	//첫이름을 복사하여 풀네임에 넣어야함.
	strcpy(strFullName, strFirstName);
	//문자열를 합쳐서 원하는 풀네임을 만들어야함.
	strcat(strFullName, strLastName);

	printf("en: %s\n", strFullName);
	//kr: strFullName = strLastName + strFirstName; 

	strcpy(strFullName, strLastName);
	strcat(strFullName, strFirstName);

	printf("kr: %s\n", strFullName);

	printf("strcmp(%s,%s):%d\n", strFirstName, strLastName, strcmp(strFirstName, strLastName));
	printf("strcmp(%s,%s):%d\n", strLastName, strFirstName, strcmp(strLastName, strFirstName));
	printf("strcmp(%s,%s):%d\n", strFirstName, strFirstName, strcmp(strFirstName, strFirstName));
	//strcmp는 같은 문자열이면 0을 반환하므로 이것아닌 경우인 1이되므로 즉. 참이된다.
	//결과값은 문자열이 같으면 거짓이 나온다 정도로 기억해도된다.
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