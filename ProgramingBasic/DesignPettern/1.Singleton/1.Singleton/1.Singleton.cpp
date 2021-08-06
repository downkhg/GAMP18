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
}