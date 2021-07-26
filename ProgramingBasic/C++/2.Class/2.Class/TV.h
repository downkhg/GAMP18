#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <stack>

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
		cout << "CShopHouse() 1" << endl;
		listShopHouse["TvA"] = new stack<CTV*>();
		listShopHouse["TvB"] = new stack<CTV*>();
		listShopHouse["TvC"] = new stack<CTV*>();
		cout << "CShopHouse() 2" << endl;
	}
	~CShopHouse()
	{
		//â���ǰ ���
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
		if (stackShopHouse == NULL)
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
		//â�� �� ���� 1���� �����ͼ� �����Ѵ�.
		listShop["TvA"] = _getHouse("TvA");
		_setDisplay("TvB");
		listShop["TvC"] = m_cShopHouse.GetTVBox("TvC");
	}
	~CShop()
	{
		//���õ� tv�� â�� ����ִ´�.
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

//���忡 ���÷��̿� ���� �ְ�, â���� ���ڿ� �� tv�� �ִ�.
//�ش� ���忡�� ���÷��̵� ��ǰ�߿� �ϳ��� �����ϸ�,
//�ش���� ��ǰ�� â���� �����ͼ� ������ ����Ѵ�.
//���� -> 3�� ����,â��->3���� 2���� ,�� -> ������ ��
void TVSimulatorMain()
{
	map<string,CTV*> listShop; //���û�ǰ
	map<string,stack<CTV*>*> listShopHouse; //â��
	CTV* pTVshelf; //���� ����

	//â�� �𵨺� ������ �����.
	listShopHouse["TvA"] = new stack<CTV*>();
	listShopHouse["TvB"] = new stack<CTV*>();
	listShopHouse["TvC"] = new stack<CTV*>();

	//â�� 4���� ��� �״´�.
	for (int i = 0; i < 4; i++)
	{
		listShopHouse["TvA"]->push(new CTV("TvA"));
		listShopHouse["TvB"]->push(new CTV("TvB"));
		listShopHouse["TvC"]->push(new CTV("TvC"));
	}

	//â�� �� ���� 1���� �����ͼ� �����Ѵ�.
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
		//â���� ������
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
	//â���ǰ ���
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