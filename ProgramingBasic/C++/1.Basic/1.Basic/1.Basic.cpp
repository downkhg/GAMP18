#include <iostream>

using namespace std;//ǥ�ض��̺귯��

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
	////������̺귯���� ������� �ָ��ϴ�.
	//g_nData = 10;
	//Print();
}
//�Լ��� �����ε�: �Ű������� �ٸ� �����̸��� �Լ��� �����Ͽ� ����ϴ°�.
//����Ʈ�Ű�����: �Ű������� ���� �������������� �����Ǵ� �⺻��.
//inline�Լ�: �Լ��� ȣ�������ʰ�, �����ϴܰ迡�� �ڵ�� ��ü�ؼ� �־��ִ°�(�����Ϸ����� �ؼ� �����ȴ�)
inline int Add(int a, int b = 0, int c = 0) { return  a + b + c; }
//int Add(int a, int b) { return  a + b; }

void FuctionOverloadingMain()
{
	cout << "Add(10,20,30):" << Add(10, 20, 30) << endl;
	cout << "Add(10,20):" << Add(10, 20) << endl;
	cout << "Add(10):" << Add(10) << endl;
}

//�̸��� ���� �Է¹޾� ������ ���� ������ ���߾� Ǯ������ ������ִ� ���α׷�
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
	//1. �� ���������ϱ�
	for (int i = 0; strTest[i] != '\0'; i++)
		cout << strTest[i];
	cout << endl;
	//2. ���ڿ��߰��ϱ� -> �ǵ�
	strTest.append("test2");
	cout << "Append:" << strTest << endl;
	//3. ���ڿ������ϱ� -> ����������.
	strTest.insert(0, "test1");
	cout << "Insert:" << strTest << endl;
	//4. ���ڿ�ã�� -> �ش繮�ڿ�ã��
	int idx = strTest.find("test2", 0);
	cout << "Find:" << idx << endl;
	//5. ���ڿ������ϱ�
	strTest.erase(0, 4);
	cout << "Erase:" << strTest << endl;
	//6. stl�� ����ϴ�. ����ִ°�? ������ ��
	cout << "==:" << (bool)(strTest == strTest) << endl;
	cout << "empty:" << strTest.empty() << endl;
	strTest.reserve();//�迭�� ũ�Ⱑ ���ʿ��ϰ� �Ҵ�����ʵ����Ѵ�.
	//�迭��ũ�Ⱑ ����ǵ��� �غ�����ʰ�, 
	//���������ʴ� ���ڿ��� ����ϸ� ȿ�������� �����Ҽ��ִ�.
	//reverse(strTest[0], strTest[strTest.size() - 1]);
	reverse(strTest.begin(), strTest.end());
	cout << strTest << endl;
}

//�ܾ���߱������ �迭����� �����ʰ�, �Լ��� ȣ���Ͽ� �ۼ��ϱ�
void HangManMain()
{

}

void main()
{
	//NameSpaceMain();
	//FuctionOverloadingMain();
	StringTestMain();
}