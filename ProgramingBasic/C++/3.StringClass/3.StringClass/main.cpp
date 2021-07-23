#include <iostream>
#include <stdlib.h> //�޸� �����Ҵ� ���
#include <crtdbg.h> //�޸� ���� Ž�� ���

using namespace std;
//���ڿ� Ŭ������ Ȱ���غ���, �ش� �Լ��� ������ ������ �����ϰ� �׽�Ʈ�� �Ͽ�
//���������� �۵��ϴ���, Ȯ���غ���.
void STDStringMain()
{
	cout << "##### STDStringMain Start######" << endl;
	string strMsg("Test"); //������
	string strMsg2("DataTest"); //������
	string srtCopyMsg = strMsg; //���������

	cout << strMsg.c_str() << endl; //const char*�� �����ϴ� �Լ�
	printf("%d:%s\n", strMsg.c_str(), strMsg.c_str());
	cout << strMsg2.c_str() << endl;
	printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str());
	cout << "##### STDStringMain End######" << endl;
}

namespace Mockup
{
	class string
	{
		char* pStr; //�����Ҵ�� ���ڿ��� �ּҸ� ������ ������
	public:
		//�����ڿ��� �����Ҵ�� �޸𸮴� ��ü�� �Ҹ�ɶ� ȣ��Ǿ���Ѵ�.
		string(const char* str)
		{
			//�Ű������� ���� ���ڿ��� �����Ҵ�(���ڿ��� ���� +1 ��ŭ)�� ���ڿ��� �����Ϳ� �����ϰ�,
			pStr = new char[strlen(str) + 1];
			//�����Ҵ�ȸ޸𸮿� �Ű������� ���ڿ��� �����Ѵ�.
			strcpy(pStr, str);
			cout << "FakeString[" << this << "]:" << (int)pStr << endl;
		}
		string(string& str)
		{
			pStr = str.pStr;
			int nSize = strlen(str.pStr) + 1;
			//*pStr = *str.pStr; //�Ҵ�������� ������ ù���ڿ��� ������.
			pStr = new char[nSize + 1];
			//strcpy(pStr, str.pStr);
			memcpy((void*)pStr, (void*)str.pStr, nSize);
			cout << "FakeString Copy[" << this << "]:" << (int)pStr << endl;
		}
		//�����ڿ��� �����Ҵ��Ͽ����Ƿ� �ݵ�� �Ҹ��ڿ��� �����Ҵ�� ��ü�� �����Ѵ�.
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
	Mockup::string strMsg("Test"); //������
	Mockup::string strMsg2("DataTest"); //������
	Mockup::string strCopyMsg = strMsg; //���������

	cout << (int)strMsg.c_str() <<strMsg.c_str() << endl; //const char*�� �����ϴ� �Լ�
	printf("%d:%s\n", strMsg.c_str(), strMsg.c_str());
	cout << (int)strMsg2.c_str() <<strMsg2.c_str() << endl;
	printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str());
	cout << (int)strCopyMsg.c_str() <<  strCopyMsg.c_str() << endl;
	cout << "##### FakeStringMain End######" << endl;
}

void main()
{
	//_CrtSetBreakAlloc(150); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 

	//STDStringMain();
	MockupStringMain();
}