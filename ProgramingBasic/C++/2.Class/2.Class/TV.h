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