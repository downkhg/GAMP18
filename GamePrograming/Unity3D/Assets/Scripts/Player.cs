using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//c#에서 구조체는 정적할당된다.
public struct Status  //플레이어의 증가능력치를 구조체로 만들어 사용한다.
{
    public int m_nHP;
    public int m_nMP;
    public int m_nStr;
    public int m_nDef;
    public int m_nInt;

    public Status(int nStr = 0, int nDef = 0, int nInt = 0, int nHP = 0, int nMP = 0)
    {
        m_nHP = nHP;
        m_nMP = nMP;
        m_nStr = nStr;
        m_nDef = nDef;
        m_nInt = nInt;
    }
    public void AddStatus(int var)
    {
        m_nHP += var;
        m_nMP += var;
        m_nStr += var;
        m_nInt += var;
        m_nDef += var;
    }
    public static Status operator +(Status a, Status b)
    {
        return new Status(a.m_nHP + b.m_nHP, a.m_nMP + b.m_nMP,
                                a.m_nStr + b.m_nStr, a.m_nDef + b.m_nDef, a.m_nInt + b.m_nInt);
    }
    public static Status operator -(Status a, Status b)
    {
        return new Status(a.m_nHP - b.m_nHP, a.m_nMP - b.m_nMP,
                                a.m_nStr - b.m_nStr, a.m_nDef - b.m_nDef, a.m_nInt - b.m_nInt);
    }
}

public class Player : MonoBehaviour
{
    //스텟
    Status m_cStatus;

    public int m_nMaxHP;
    public int m_nMaxMP;
    //이름
    string m_strName;
    int m_nLv;
    int m_nExp;

    int m_nGold; //소지금

    List<Item> m_listIventory = new List<Item>(); //인벤토리.
    List<Item> m_listEqument = new List<Item>((int)eEqumentKind.MAX); //장비함.
    public enum eEqumentKind { Weapon, Armor, Acc, MAX }

    public List<Item> Invetory
    {
        get { return m_listIventory; }
    }
    public int HP
    {
        get { return m_cStatus.m_nHP; }
    }
    public int MP
    {
        get { return m_cStatus.m_nMP; }
    }
    public int MaxHP { get { return m_nMaxHP; } }
    public int MaxMP
    {
        get { return m_nMaxMP; }
    }
    public string Name
    {
        get { return m_strName; }
    }
    public Player(string name, int nHP = 100, int nMP = 100, int nStr = 10, int nInt = 10, int nDef = 10, int nExp = 10, int nGold = 0)
    {
        m_cStatus = new Status(nStr, nDef, nInt, nHP, nMP);
        m_nMaxHP = nHP;
        m_nMaxMP = nMP;
        m_strName = name;
        m_nExp = nExp;
        m_nGold = nGold;
        m_nLv = 1;
        m_listEqument = new List<Item>((int)eEqumentKind.MAX); //장비함.
        for (int i = 0; i < (int)eEqumentKind.MAX; i++)
            m_listEqument.Add(null);
    }
    public void Attack(Player cTarget)
    {
        cTarget.Demaged(m_cStatus.m_nStr);
    }
    public void Demaged(int dem) //데미지를 받아 HP감소
    {
        m_cStatus.m_nHP = m_cStatus.m_nHP - (dem - m_cStatus.m_nDef);
    }
    public bool Dead()
    {
        if (m_cStatus.m_nHP <= 0)
        {
            return true;
        }
        return false;
    }
    public void StillItem(Player cTarget)
    {
        SetInvetory(cTarget.GetInvetory(0));
        m_nExp += cTarget.m_nExp;
    }
    public void Recovery()
    {
        m_cStatus.m_nHP = m_nMaxHP;
        m_cStatus.m_nMP = m_nMaxMP;
    }

    public bool LvUp(int var = 10, int maxexp = 100)
    {
        if (m_nExp > maxexp)
        {
            m_cStatus.AddStatus(var);
            m_nExp -= maxexp;
            m_nMaxHP += var;
            m_nMaxMP += var;
            return true;
        }

        return false;
    }

    public void SetInvetory(Item item)
    {
        m_listIventory.Add(item);
    }
    public Item GetInvetory(int idx)
    {
        return m_listIventory[idx];
    }
    public void DeleteInventory(Item item)
    {
        m_listIventory.Remove(item);
    }

    public bool Buy(int nIventoryIdx, Player cTarget)
    {
        Item cItem = cTarget.GetInvetory(nIventoryIdx);

        if (cItem.Gold <= m_nGold)
        {
            SetInvetory(cItem);
            m_nGold -= cItem.Gold;
            return true;
        }

        return false;
    }
    public void Sell(int nIventoryIdx)
    {
        Item cItem = GetInvetory(nIventoryIdx);
        DeleteInventory(cItem);
        m_nGold += cItem.Gold;
    }

    public void SetEquemnt(Item item) //아이템장착
    {
        //장비아이템일때만 해당 아이템을 셋팅한다.
        if (item.ItemKind <= Item.eItemKind.Acc)
        {
            ReleaseEquemnt((eEqumentKind)item.ItemKind);
            //장비할아이템을 장착하고, 능력치를 증가시킨다.
            m_listEqument[(int)eEqumentKind.Weapon] = item;
            m_cStatus += item.Function;

            DeleteInventory(item);
        }
    }
    public void ReleaseEquemnt(eEqumentKind eEqument)
    {
        Item cEqumentItem = m_listEqument[(int)eEqument];

        if (cEqumentItem != null)
        {
            SetInvetory(cEqumentItem);
            m_cStatus -= cEqumentItem.Function;
        }
    } //아이템해제
    public void ItemUse(Item item, Player cTarget)
    {
        //장비아이템일때만 해당 아이템을 셋팅한다.
        if (item.ItemKind >= Item.eItemKind.Potion)
        {
            if (item.ItemKind == Item.eItemKind.Potion)
            {
                m_cStatus += item.Function;
                if (m_cStatus.m_nHP > m_nMaxHP)
                    m_cStatus.m_nHP = cTarget.m_nMaxHP;
                if (m_cStatus.m_nMP > m_nMaxMP)
                    m_cStatus.m_nMP = m_nMaxMP;
            }
            else if (item.ItemKind == Item.eItemKind.Throw)
            {
                cTarget.Demaged(item.Function.m_nStr);
            }
            DeleteInventory(item);
        }
    }

    private void OnGUI()
    {
        int nWidth = 100;
        int nHeight = 20;
        for (int i = 0; i < m_listIventory.Count; i++)
        {
            string strMsg =  string.Format("{0}:{1}", i, m_listIventory[i].Name);
            GUI.Box(new Rect(0, i * nHeight, nWidth, nHeight), strMsg);   
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
