#include <iostream>
#include <string>
#include <vector>

#include "ItemManager.h"
#include "Player.h"
#include "Skill.h"

using namespace std;

class GameManager
{
public:
	enum E_STAGE { EXIT = -1, CRATE, IVNETORY, SHOP, TOWN, FILED, BATTLE, GAME_OVER, THE_END, MAX };
	enum E_MONSTER { SILME, SKELETON, BOSS, MON_MAX };

	void Init()
	{
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_ARMOR));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_RING));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::BONE_SOWRD));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::BONE_AMROR));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::BONE_RING));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::HP_POTION));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::MP_POTION));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::STONE));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::BOOM));

		m_cMonster.Set("Slime", 100, 100, 20, 10, 10, 100);
		m_cMonster.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD));
	}

	void EventCreate()
	{
		string name;
		cout << "�ɸ��� �̸��� �Է��ϼ���!:";
		cin >> name;
		m_cPlayer.Set(name, 100, 100, 20, 10, 10, 0);
		m_eStage = E_STAGE::TOWN;
	}
	void EventInvetory()
	{
		m_cPlayer.Show();
		int nSelect;
		cout << "�޴��� �����ϼ���!(1: �����ۻ��. 2: ������� etc: ����):";
		cin >> nSelect;
		if (nSelect == 1)
		{
			cout << "����� �������� ���ϼ���!:";
			cin >> nSelect;
			if (!m_cPlayer.UseItem(nSelect))
				cout << "����Ҽ������ϴ�!" << endl;
		}
		else if (nSelect == 2)
		{
			cout << "��������� ����Կ��� �����ϼ���!:";
			cin >> nSelect;
			m_cPlayer.ReleaseEqument(nSelect);
		}
		else
			m_eStage = E_STAGE::TOWN;
	}
	void EventShop()
	{
		m_cShop.Show();
		int nInput;
		cout << "�����Դϴ�. ������ �Ͻðڽ��ϱ�? 1: ����, 2: �ȱ�, etc:����";
		cin >> nInput;
		switch (nInput)
		{
		case 1:
		{
			cout << "������ �������� ��Ͽ��� �����ϼ���! -1:����";
			cin >> nInput;
			if (nInput != -1)
				m_cPlayer.Buy(m_cShop, nInput);
			else
				m_eStage = E_STAGE::TOWN;
		}
		break;
		case 2:
		{
			m_cPlayer.Show();
			cout << "�Ǹ��� �������� ��Ͽ��� �����ϼ���! -1:����";
			cin >> nInput;
			if (nInput != -1)
				m_cPlayer.Sell(nInput);
			else
				m_eStage = E_STAGE::TOWN;
		}
		break;
		default:
		{
			m_eStage = E_STAGE::TOWN;
		}
		break;
		}
	}
	void EventTown()
	{
		const char* strStageName[] = { "CRATE", "INVENTORY","SHOP","TOWN", "FILED", "BATTLE", "GAME_OVER", "THE_END" };

		cout << "���� �Դϴ�." << endl;
		cout << "���� ���ðڽ��ϱ�?" << endl;
		for (int i = E_STAGE::CRATE + 1; i < E_STAGE::BATTLE; i++)
			cout << i << ":" << strStageName[i] << ",";
		cin >> m_eStage;
	}
	void EventFiled()
	{
		const char* strMonsterName[] = { "SILME", "SKELETON", "BOSS" };
		int nSelect;
		cout << "���� ���ðڽ��ϱ�?";
		for (int i = 0; i < E_MONSTER::MON_MAX; i++)
			cout << i << ":" << strMonsterName[i] << ",";
		cin >> nSelect;
		switch (nSelect)
		{
		case E_MONSTER::SILME:
			m_cMonster.Set("Slime", 100, 100, 20, 10, 10, 100);
			break;
		case E_MONSTER::SKELETON:
			m_cMonster.Set("Skeleton", 200, 200, 30, 10, 10, 100);
			break;
		case E_MONSTER::BOSS:
			m_cMonster.Set("Boss", 300, 100, 50, 10, 10, 100);
			break;
		}
		m_eStage = E_STAGE::BATTLE;
	}
	void EventBattle()
	{
		if (m_cPlayer.Dead() == false)
			m_cPlayer.Attack(m_cMonster);
		else
		{
			m_eStage = GAME_OVER;
		}
		m_cMonster.Show();
		if (m_cMonster.Dead() == false)
			m_cMonster.Attack(m_cPlayer);
		else
		{
			m_cPlayer.StillItem(m_cMonster);
			if (m_cPlayer.LvUp())
				cout << "����!" << endl;
			m_eStage = TOWN;
		}
	}

	void Update()
	{
		switch (m_eStage)
		{
		case E_STAGE::CRATE:
			EventCreate();
			break;
		case E_STAGE::IVNETORY:
			EventInvetory();
			break;
		case E_STAGE::SHOP:
			EventShop();
			break;
		case E_STAGE::TOWN:
			EventTown();
			break;
		case E_STAGE::FILED:
			EventFiled();
			break;
		case E_STAGE::BATTLE:
			EventBattle();
			break;
		case E_STAGE::GAME_OVER:
			printf("GAME\OVER");
			break;
		case E_STAGE::THE_END:
			printf("THE EMD");
			break;
		default:
			break;
		}
	}

	int GetStage()
	{
		return m_eStage;
	}

private:
	int m_eStage = E_STAGE::CRATE;

	ItemManager m_cItemManager;
	Player m_cPlayer;
	Player m_cMonster;
	Player m_cShop;
};

//������ �÷��̸� �̿��Ͽ� ������. //���,�ȱ�
void main()
{
	GameManager cGameManager;
	cGameManager.Init();
	while (cGameManager.GetStage() != GameManager::E_STAGE::EXIT)
	{
		cGameManager.Update();
	}
}