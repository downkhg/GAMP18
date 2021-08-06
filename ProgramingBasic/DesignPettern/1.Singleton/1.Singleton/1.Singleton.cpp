#include <iostream>

using namespace std;

class SingleObject
{
	static SingleObject* m_pInstance;
	int m_nData = 10;

	SingleObject() { cout << "SingleObject:"<<this<< endl; }
public:

	static SingleObject* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new SingleObject();
		return m_pInstance;
	}
	void ShowMassage()
	{
		cout << "SingleObject["<<this<<"]:" << m_nData << endl;
	}
	static void Release()
	{
		cout << "SingleObject::Relase()" << endl;
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}
};

SingleObject* SingleObject::m_pInstance = NULL;

void main()
{
	//SingleObject cObject;
	SingleObject* pObjectA = NULL;
	//pObjectA = new SingleObject();
	//�����ɹ��ΰ�� �����Ϸ��� ���������, ���ΰ�ü�� �����ٛ����Ƿ� ȥ���� �߱��Ҽ��ִ�.
	//pObjectA = pObjectA->GetInstance(); 
	pObjectA = SingleObject::GetInstance();
	pObjectA->ShowMassage();

	SingleObject* pArrObject[2];

	pArrObject[0] = SingleObject::GetInstance();
	pArrObject[1] = SingleObject::GetInstance();

	for (int i = 0; i < 2; i++)
	{
		pArrObject[i]->ShowMassage();
	}
	for (int i = 0; i < 2; i++)
		pArrObject[i]->Release();

	pObjectA->Release();//�̷��� �������̽��� ����ڿ��� ȥ���� �ټ�����.
	SingleObject::Release();
}