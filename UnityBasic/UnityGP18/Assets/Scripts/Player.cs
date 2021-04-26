using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public int m_nHP;
    public int m_nStr;

    public int m_nExp = 0;
    public int m_nLv = 1;
  

    public void Init(string name, int hp, int str)
    {
        gameObject.name = name;
        m_nHP = hp;
        m_nStr = str;
        m_nLv = 1;
        m_nExp = 0;
    }

    public void Attack(Player target)
    {
        target.m_nHP -= this.m_nStr;
    }

    public bool Death()
    {
        if (m_nHP <= 0)
            return true;
        else
            return false;
    }

    public void LvUp()
    {
        //만약, 경험치가 100이상이라면, 랩이 1오르고 모든능력치가 5상승한다.
        if(m_nExp >= 100)
        {
            m_nLv++;
            m_nStr += 5;
            m_nHP += 5;
            m_nExp -= 100;
        }
    }

    private void Update()
    {
        LvUp();
    }

    //플레이어/주머니쥐/독수리:0,1,2
    public int idx;

    private void OnGUI()
    {
        GUI.Box(new Rect(0 + 100 * idx, 0, 100, 20), this.gameObject.name);
        GUI.Box(new Rect(0 + 100 * idx, 20, 100, 20), "HP:"+m_nHP);
        GUI.Box(new Rect(0 + 100 * idx, 40, 100, 20), "Str:" + m_nStr);
        GUI.Box(new Rect(0 + 100 * idx, 60, 100, 20), "Lv/Exp:" + m_nLv +"/"+m_nExp);
    }
}
