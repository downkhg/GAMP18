#include <iostream>

using namespace std;//표준라이브러리

namespace A
{
	int g_nData;
	void Print() { cout << "A:" << g_nData << endl; }
}

namespace B
{
	int g_nData;
	void Print() { cout << "B:" << g_nData << endl; }
}

using namespace A;
using namespace B;

void NameSpaceMain()
{
	A::g_nData = 10;
	A::Print();

	B::g_nData = 20;
	B::Print();
	////어느라이브러리를 사용할지 애매하다.
	//g_nData = 10;
	//Print();
}
//함수의 오버로딩: 매개변수가 다른 같은이름의 함수를 선언하여 사용하는것.
//디폴트매개변수: 매개변수의 값을 지정하지않으면 설정되는 기본값.
//inline함수: 함수를 호출하지않고, 컴파일단계에서 코드로 교체해서 넣어주는것(컴파일러에의 해서 결정된다)
inline int Add(int a, int b = 0, int c = 0) { return  a + b + c; }
//int Add(int a, int b) { return  a + b; }

void FuctionOverloadingMain()
{
	cout << "Add(10,20,30):" << Add(10, 20, 30) << endl;
	cout << "Add(10,20):" << Add(10, 20) << endl;
	cout << "Add(10):" << Add(10) << endl;
}

//이름과 성을 입력받아 선택한 국가 종류에 맞추어 풀네임을 만들어주는 프로그램
void StringMain()
{
	string strFirstName, strLastName, strFullName;
	cout << "Input First/LastName:";
	cin >> strFirstName;
	cin >> strLastName;

	int nSelectType;
	cout << "SelectFullNameType(1:kr, 2:en):";
	cin >> nSelectType;
	switch (nSelectType)
	{
	case 1:
		cout << "kr-";
		strFullName = strLastName + strFirstName;
		break;
	case 2:
		cout << "en-";
		strFullName = strFirstName + strLastName;
		break;
	default:
		cout << "Type is null!!!" << endl;
		break;
	}
	cout << strFullName << endl;
}
void StringTestMain()
{
	string strTest = "Test";
	//1. 각 문자접근하기
	for (int i = 0; strTest[i] != '\0'; i++)
		cout << strTest[i];
	cout << endl;
	//2. 문자열추가하기 -> 맨뒤
	strTest.append("test2");
	cout << "Append:" << strTest << endl;
	//3. 문자열삽입하기 -> 어디든상관없음.
	strTest.insert(0, "test1");
	cout << "Insert:" << strTest << endl;
	//4. 문자열찾기 -> 해당문자열찾기
	int idx = strTest.find("test2", 0);
	cout << "Find:" << idx << endl;
	//5. 문자열삭제하기
	strTest.erase(0, 4);
	cout << "Erase:" << strTest << endl;
	//6. stl과 비슷하다. 비어있는가? 뒤집기 비교
	cout << "==:" << (bool)(strTest == strTest) << endl;
	cout << "empty:" << strTest.empty() << endl;
	strTest.reserve();//배열의 크기가 불필요하게 할당되지않도록한다.
	//배열의크기가 변경되도록 준비되지않고, 
	//변경하지않는 문자열에 사용하면 효율적으로 관리할수있다.
	//reverse(strTest[0], strTest[strTest.size() - 1]);
	reverse(strTest.begin(), strTest.end());
	cout << strTest << endl;
}

//단어맞추기게임을 배열방식을 쓰지않고, 함수를 호출하여 작성하기
void HangManMain()
{

}

void main()
{
	//NameSpaceMain();
	//FuctionOverloadingMain();
	StringTestMain();
}