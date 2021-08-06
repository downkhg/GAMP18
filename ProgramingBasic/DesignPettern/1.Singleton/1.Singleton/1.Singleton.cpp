#include <iostream>

using namespace std;

class SingleObject
{
	static SingleObject* m_pInstance;
	int m_nData = 10;

	SingleObject(){  }
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
	void Release()
	{
		delete m_pInstance;
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
}