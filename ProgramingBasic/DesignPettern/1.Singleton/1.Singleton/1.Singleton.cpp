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
	//정적맴버인경우 컴파일러가 통과되지만, 널인객체서 가져다썻으므로 혼란을 야기할수있다.
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

	pObjectA->Release();//이러한 인터페이스는 사용자에게 혼란을 줄수있음.
	SingleObject::Release();
}