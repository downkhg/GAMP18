#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <list>

using namespace std;

class CTV
{
	string m_strName;
public:
	string GetName() { return m_strName; }
	CTV(string name) { m_strName = name; }
	void Display() { cout << "TVModel:" << m_strName << endl; }
};

class CShopHouse
{
	map<string, stack<CTV*>*> listShopHouse; //â��
public:
	CShopHouse()
	{
		cout << "CShopHouse()" << endl;
		listShopHouse["TvA"] = new stack<CTV*>();
		listShopHouse["TvB"] = new stack<CTV*>();
		listShopHouse["TvC"] = new stack<CTV*>();
	}
	~CShopHouse()
	{
		cout << "~CShopHouse()" << endl;
	}
	void Order(int count)
	{
		cout << "Order("<<count<<") 1" << endl;
		for (int i = 0; i < count; i++)
		{
			listShopHouse["TvA"]->push(new CTV("TvA"));
			listShopHouse["TvB"]->push(new CTV("TvB"));
			listShopHouse["TvC"]->push(new CTV("TvC"));
		}
		cout << "Order(" << listShopHouse["TvA"]->size()<< ") 2" << endl;
	}
	void Disposal()
	{
		//â����ǰ ���
		map<string, stack<CTV*>*>::iterator itShopHouse;
		for (itShopHouse = listShopHouse.begin(); itShopHouse != listShopHouse.end(); itShopHouse++)
		{
			stack<CTV*>* stack = itShopHouse->second;
			while (!stack->empty())
			{
				CTV* pDelTv = stack->top();
				stack->pop();
			}
			delete stack;
		}
	}
	CTV* GetTVBox(CTV* pSelTV)
	{
		CTV* pTemp = NULL;
		if (pSelTV)
		{
			pTemp = listShopHouse[pSelTV->GetName()]->top();
			listShopHouse[pSelTV->GetName()]->pop();
			if (pTemp) cout << "Shop:" << pTemp->GetName() << endl;
			else cout << pSelTV->GetName() << " is empty!" << endl;
		}
		return pTemp;
	}
	CTV* GetTVBox(string name)
	{
		CTV* pTemp = NULL;
		stack<CTV*>* stackShopHouse = listShopHouse[name];
		if (stackShopHouse)
		{
			pTemp = stackShopHouse->top();
			listShopHouse[name]->pop();
			if (pTemp) cout << "Shop:" << pTemp->GetName() << endl;
			else cout << name << " is empty!" << endl;
		}
		return pTemp;
	}
	void SetTVBox(CTV* pTV)
	{
		listShopHouse[pTV->GetName()]->push(pTV);
	}
	void Display()
	{

	}
};

class CShopHouseRef
{
	map<string, stack<CTV*>*>* listShopHouse; //â��
public:
	CShopHouseRef(map<string, stack<CTV*>*>* mapTVStacks)
	{
		cout << "CShopHouse()" << endl;
		listShopHouse = mapTVStacks;
	}
	~CShopHouseRef()
	{
		cout << "~CShopHouse()" << endl;
	}
	void Order(int count)
	{
		cout << "Order(" << count << ") 1" << endl;
		for (int i = 0; i < count; i++)
		{
			((*listShopHouse)["TvA"])->push(new CTV("TvA"));
			((*listShopHouse)["TvB"])->push(new CTV("TvB"));
			((*listShopHouse)["TvC"])->push(new CTV("TvC"));
		}
		cout << "Order(" << ((*listShopHouse)["TvA"])->size() << ") 2" << endl;
	}
	void Disposal()
	{
		//â����ǰ ���
		map<string, stack<CTV*>*>::iterator itShopHouse;
		for (itShopHouse = listShopHouse->begin(); itShopHouse != listShopHouse->end(); itShopHouse++)
		{
			stack<CTV*>* stack = itShopHouse->second;
			while (!stack->empty())
			{
				CTV* pDelTv = stack->top();
				stack->pop();
			}
			delete stack;
		}
	}
	CTV* GetTVBox(CTV* pSelTV)
	{
		CTV* pTemp = NULL;
		if (pSelTV)
		{
			pTemp = ((*listShopHouse)[pSelTV->GetName()])->top();
			(*listShopHouse)[pSelTV->GetName()]->pop();
			if (pTemp) cout << "Shop:" << pTemp->GetName() << endl;
			else cout << pSelTV->GetName() << " is empty!" << endl;
		}
		return pTemp;
	}
	CTV* GetTVBox(string name)
	{
		CTV* pTemp = NULL;

		stack<CTV*>* stackShopHouse = (*listShopHouse)[name];
		if (stackShopHouse)
		{
			pTemp = stackShopHouse->top();
			(*listShopHouse)[name]->pop();
			if (pTemp) cout << "Shop:" << pTemp->GetName() << endl;
			else cout << name << " is empty!" << endl;
		}
		return pTemp;
	}
	void SetTVBox(CTV* pTV)
	{
		(*listShopHouse)[pTV->GetName()]->push(pTV);
	}
};

class CShopRef
{
	map<string, CTV*> listShop; //���û�ǰ
	CShopHouseRef* m_pShopHouse; //Has-a: ��ü�� ��ü���ο� �������ִ°�.

	CTV* _getHouse(string name)
	{
		return m_pShopHouse->GetTVBox(name);
	}
	void _setDisplay(string name)
	{
		listShop[name] = _getHouse(name);
	}
public:
	CShopRef(CShopHouseRef* pShopHouse )
	{
		m_pShopHouse = pShopHouse;
		
	}
	~CShopRef()
	{
		//���õ� tv�� â���� ����ִ´�.
		map<string, CTV*>::iterator it = listShop.begin();
		for (; it != listShop.end(); it++)
		{
			m_pShopHouse->SetTVBox(it->second);
		}
	}

	void DispalyTV()
	{
		//â���� �� ���� 1���� �����ͼ� �����Ѵ�.
		listShop["TvA"] = _getHouse("TvA");
		_setDisplay("TvB");
		listShop["TvC"] = m_pShopHouse->GetTVBox("TvC");
	}

	CTV* SelectTV(CTV* pTV)
	{
		return m_pShopHouse->GetTVBox(pTV);
	}

	CTV* SelectTV(string name)
	{
		return m_pShopHouse->GetTVBox(name);
	}

	void Delivery(CTV*& address, CTV* cTv)
	{
		address = cTv;
	}
};

class CShop
{
	map<string, CTV*> listShop; //���û�ǰ
	CShopHouse m_cShopHouse; //Has-a: ��ü�� ��ü���ο� �������ִ°�.

	CTV* _getHouse(string name)
	{
		return m_cShopHouse.GetTVBox(name);
	}
	void _setDisplay(string name)
	{
		listShop[name] = _getHouse(name);
	}
public:
	CShop()
	{
		m_cShopHouse.Order(4);
		//â���� �� ���� 1���� �����ͼ� �����Ѵ�.
		listShop["TvA"] = _getHouse("TvA");
		_setDisplay("TvB");
		listShop["TvC"] = m_cShopHouse.GetTVBox("TvC");
	}
	~CShop()
	{
		//���õ� tv�� â���� ����ִ´�.
		map<string, CTV*>::iterator it = listShop.begin();
		for (; it != listShop.end(); it++)
		{
			m_cShopHouse.SetTVBox(it->second);
		}
	}

	CTV* SelectTV(CTV* pTV)
	{
		return m_cShopHouse.GetTVBox(pTV);
	}

	CTV* SelectTV(string name)
	{
		return m_cShopHouse.GetTVBox(name);
	}

	void Delivery(CTV*& address, CTV* cTv)
	{
		address = cTv;
	}
};

//���忡 ���÷��̿� ���� �ְ�, â������ ���ڿ� �� tv�� �ִ�.
//�ش� ���忡�� ���÷��̵� ��ǰ�߿� �ϳ��� �����ϸ�,
//�ش���� ��ǰ�� â������ �����ͼ� ������ ����Ѵ�.
//���� -> 3�� ����,â��->3���� 2���� ,�� -> ������ ��
void TVSimulatorMain()
{
	map<string,CTV*> listShop; //���û�ǰ
	map<string,stack<CTV*>*> listShopHouse; //â��
	CTV* pTVshelf; //������ ����

	//â���� �𵨺� ������ �����.
	listShopHouse["TvA"] = new stack<CTV*>();
	listShopHouse["TvB"] = new stack<CTV*>();
	listShopHouse["TvC"] = new stack<CTV*>();

	//â���� 4���� ����� �״´�.
	for (int i = 0; i < 4; i++)
	{
		listShopHouse["TvA"]->push(new CTV("TvA"));
		listShopHouse["TvB"]->push(new CTV("TvB"));
		listShopHouse["TvC"]->push(new CTV("TvC"));
	}

	//â���� �� ���� 1���� �����ͼ� �����Ѵ�.
	listShop["TvA"] = listShopHouse["TvA"]->top(); listShopHouse["TvA"]->pop();
	listShop["TvB"] = listShopHouse["TvB"]->top(); listShopHouse["TvB"]->pop();
	listShop["TvC"] = listShopHouse["TvC"]->top(); listShopHouse["TvC"]->pop();

	//������ ���� ��ġ�Ϸ�. ����
	cout << "##### Display List #####" << endl;
	map<string, CTV*>::iterator itShop;
	for (itShop = listShop.begin(); itShop != listShop.end(); itShop++)
	{
		CTV* Tv = itShop->second;
		Tv->Display();
	}
	cout << "#######################" << endl;
	string strSelectModel;
	cout << "SelectModel:";
	cin >> strSelectModel;
	cout << "SelectCheck:" << strSelectModel << endl;
	//���忡 ���÷��̵ȸ��߿� �Էµ� ���� ã�´�.
	CTV* pSelectTV = listShop[strSelectModel];
	if (pSelectTV)//ã�� ���� ����ǰ �߿� �ִٸ�,
	{
		//â������ ������
		strSelectModel = pSelectTV->GetName();
		CTV* pShopHouseTv = listShopHouse[strSelectModel]->top();
		listShopHouse[strSelectModel]->pop();
		//����Ѵ�.
		pTVshelf = pShopHouseTv;
		cout << strSelectModel << " Delivery Complete!" << endl;
	}
	else//����ǰ�� ����.
	{
		cout << strSelectModel << " is Not Found!" << endl;
	}

	//���
	//�����Ҵ�����
	//���û�ǰ ���
	for (itShop = listShop.begin(); itShop != listShop.end(); itShop++)
	{
		CTV* pDelTv = itShop->second;
		listShop.erase(itShop->first);
		delete pDelTv;
	}
	listShop.clear();
	//â����ǰ ���
	map<string,stack<CTV*>*>::iterator itShopHouse;
	for (itShopHouse = listShopHouse.begin(); itShopHouse != listShopHouse.end(); itShopHouse++)
	{
		stack<CTV*>* stack = itShopHouse->second;
		while (!stack->empty())
		{
			CTV* pDelTv = stack->top();
			stack->pop();
		}
		delete stack;
	}
}

void TVShopTestMain()
{
	CShopHouse m_cShopHouse;

	m_cShopHouse.Order(4);

	CTV* pTV = m_cShopHouse.GetTVBox("TvA");
	
	if (pTV)
		pTV->Display();
	else
		printf("TvA is null");
}


void TVShopClassSimulatorMain()
{
	CShop m_cShop;

	CTV* pTVshelf;

	CTV* pSelectTv = m_cShop.SelectTV("TvA");
	m_cShop.Delivery(pTVshelf, pSelectTv);

	if (pTVshelf)
		pTVshelf->Display();
	else
		printf("TVShelf is Emplty!!!");
}

void TVShopClassSimulatorRefMain()
{
	//TVâ���� ���� ������ ���ÿ� �����Ѵ�.
	map<string, stack<CTV*>*> mapTVStacks;
	mapTVStacks["TvA"] = new stack<CTV*>();
	mapTVStacks["TvB"] = new stack<CTV*>();
	mapTVStacks["TvC"] = new stack<CTV*>();

	mapTVStacks["TvA"]->push(new CTV("TvA"));
	mapTVStacks["TvB"]->push(new CTV("TvB"));
	mapTVStacks["TvC"]->push(new CTV("TvC"));
	//������ ������ â���ȿ� �ִ´�.
	CShopHouseRef cShopHouse(&mapTVStacks);

	CShopRef cShop(&cShopHouse);

}