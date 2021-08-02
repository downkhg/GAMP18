#include <iostream>
#include <stdlib.h> //메모리 동적할당 헤더
#include <crtdbg.h> //메모리 누수 탐지 헤더

using namespace std;
//문자열 클래스를 활용해보고, 해당 함수를 가능한 선까지 구현하고 테스트를 하여
//정상적으로 작동하는지, 확인해보자.
void STDStringMain()
{
	cout << "##### STDStringMain Start######" << endl;
	string strMsg("Test"); //생성자
	string strMsg2("DataTest"); //생성자
	string srtCopyMsg = strMsg; //복사생성자
	string strCopyMsg2;

	cout << strMsg.c_str() << endl; //const char*를 리턴하는 함수
	printf("%d:%s\n", strMsg.c_str(), strMsg.c_str());
	cout << strMsg2.c_str() << endl;
	printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str());
	strCopyMsg2 = strMsg;
	cout << (int)strCopyMsg2.c_str() << endl;
	cout << "##### STDStringMain End######" << endl;
}

namespace Mockup
{
	class string
	{
		char* pStr; //동적할당된 문자열의 주소를 저장할 포인터
	public:
		//생성자에서 동적할당된 메모리는 객체가 소멸될때 호출되어야한다.
		string(const char* str = NULL)
		{
			if (str)
			{
				//매개변수로 받은 문자열을 동적할당(문자열의 길이 +1 만큼)된 문자열에 포인터에 저장하고,
				pStr = new char[strlen(str) + 1];
				//동적할당된메모리에 매개변수의 문자열을 복사한다.
				strcpy(pStr, str);
				cout << "FakeString[" << this << "]:" << (int)pStr << endl;
			}
		}
		string(string& str)
		{
			pStr = str.pStr;
			int nSize = strlen(str.pStr) + 1;
			//*pStr = *str.pStr; //할당되지않은 영역에 첫문자열만 복사함.
			pStr = new char[nSize + 1];
			//strcpy(pStr, str.pStr);
			memcpy((void*)pStr, (void*)str.pStr, nSize);
			cout << "FakeString Copy[" << this << "]:" << (int)pStr << endl;
		}
		//생성자에서 동적할당하였으므로 반드시 소멸자에서 동적할당된 객체를 정리한다.
		~string()
		{
			cout << "~FakeString[" << this << "]:" << (int)pStr << endl;
			delete[] pStr;
		}
		const char* c_str()
		{
			return pStr;
		}
	};
}

void MockupStringMain()
{
	cout << "##### FakeStringMain Start ######" << endl;
	Mockup::string strMsg("Test"); //생성자
	Mockup::string strMsg2("DataTest"); //생성자
	Mockup::string strCopyMsg = strMsg; //복사생성자
	Mockup::string strCopyMsg2;

	cout << (int)strMsg.c_str() <<strMsg.c_str() << endl; //const char*를 리턴하는 함수
	printf("%d:%s\n", strMsg.c_str(), strMsg.c_str());
	cout << (int)strMsg2.c_str() <<strMsg2.c_str() << endl;
	printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str());
	cout << (int)strCopyMsg.c_str() <<  strCopyMsg.c_str() << endl;
	strCopyMsg2 = strMsg;
	cout << (int)strCopyMsg2.c_str() << endl;
	cout << "##### FakeStringMain End######" << endl;
}

void main()
{
	//_CrtSetBreakAlloc(150); //메모리 누수시 번호를 넣으면 할당하는 위치에 브레이크 포인트를 건다.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //메모리 누수 검사 

	//STDStringMain();
	MockupStringMain();
}