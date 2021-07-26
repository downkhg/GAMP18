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
	map<string, stack<CTV*>*> listShopHouse; //창고
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
		//창고상품 폐기
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
	map<string, CTV*> listShop; //전시상품
	CShopHouse m_cShopHouse; //Has-a: 객체를 객체내부에 가지고있는것.

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
		//창고에 각 물건 1개씩 꺼내와서 전시한다.
		listShop["TvA"] = _getHouse("TvA");
		_setDisplay("TvB");
		listShop["TvC"] = m_cShopHouse.GetTVBox("TvC");
	}
	~CShop()
	{
		//전시된 tv를 창고에 집어넣는다.
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

//매장에 디스플레이용 모델이 있고, 창고에는 상자에 든 tv가 있다.
//해당 매장에서 디스플레이된 제품중에 하나를 선택하면,
//해당모델의 제품을 창고에서 꺼나와서 집으로 배달한다.
//매장 -> 3종 전시,창고->3종이 2개씩 ,집 -> 선택한 모델
void TVSimulatorMain()
{
	map<string,CTV*> listShop; //전시상품
	map<string,stack<CTV*>*> listShopHouse; //창고
	CTV* pTVshelf; //고객의 선반

	//창고에 모델별 스택을 만든다.
	listShopHouse["TvA"] = new stack<CTV*>();
	listShopHouse["TvB"] = new stack<CTV*>();
	listShopHouse["TvC"] = new stack<CTV*>();

	//창고에 4개씩 재고를 쌓는다.
	for (int i = 0; i < 4; i++)
	{
		listShopHouse["TvA"]->push(new CTV("TvA"));
		listShopHouse["TvB"]->push(new CTV("TvB"));
		listShopHouse["TvC"]->push(new CTV("TvC"));
	}

	//창고에 각 물건 1개씩 꺼내와서 전시한다.
	listShop["TvA"] = listShopHouse["TvA"]->top(); listShopHouse["TvA"]->pop();
	listShop["TvB"] = listShopHouse["TvB"]->top(); listShopHouse["TvB"]->pop();
	listShop["TvC"] = listShopHouse["TvC"]->top(); listShopHouse["TvC"]->pop();

	//상점에 물건 배치완료. 오픈
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
	//매장에 디스플레이된모델중에 입력된 모델을 찾는다.
	CTV* pSelectTV = listShop[strSelectModel];
	if (pSelectTV)//찾는 모델이 전시품 중에 있다면,
	{
		//창고에서 꺼내와
		strSelectModel = pSelectTV->GetName();
		CTV* pShopHouseTv = listShopHouse[strSelectModel]->top();
		listShopHouse[strSelectModel]->pop();
		//배달한다.
		pTVshelf = pShopHouseTv;
		cout << strSelectModel << " Delivery Complete!" << endl;
	}
	else//전시품이 없다.
	{
		cout << strSelectModel << " is Not Found!" << endl;
	}

	//페업
	//동적할당해제
	//전시상품 폐기
	for (itShop = listShop.begin(); itShop != listShop.end(); itShop++)
	{
		CTV* pDelTv = itShop->second;
		listShop.erase(itShop->first);
		delete pDelTv;
	}
	listShop.clear();
	//창고상품 폐기
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