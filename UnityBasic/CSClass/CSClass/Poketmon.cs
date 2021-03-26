using System;
using System.Collections.Generic;
using System.Text;
/*
 * 포켓몬 유사게임 모작하기
1.트레이너는 처음 포켓몬이 하나 주어진다.
2.트레이너가 가고 싶은 지역을 선택하고,
3.해당지역에 포켓몬을 만나고 쓰러뜨리면, 해당포켓몬을 획득할수있다.
4.획득한 포켓몬은 싸우기 전에 결정이 가능하다.
*/
namespace CSClass
{
    class Pokemon
    {
        string m_strName;
        private int m_nExp;
        private int m_nLv;
        private int m_nHP;
        private int m_nStr;

        public string Name
        {
            get { return m_strName; }
        }

        public int HP { get { return m_nHP; } set { m_nHP = value; } }

        public Pokemon(string name, int hp, int str)
        {
            m_strName = name;
            m_nHP = hp;
            m_nStr = str;
            m_nLv = 1;
            m_nExp = 0;
        }

        public void Attack(Pokemon target)
        {
            target.HP = target.HP - this.m_nStr;
        }

        public bool Death()
        {
            if (m_nHP <= 0)
                return true;
            else
                return false;
        }

        public void Show()
        {
            Console.WriteLine("Name:" + m_strName);
            Console.WriteLine("HP:" + m_nHP);
            Console.WriteLine("STR:" + m_nStr);
            Console.WriteLine("Lv/Exp:{0}/{1}", m_nLv, m_nExp);
        }
    }
    class Trainner
    {
        List<Pokemon> pokemons = new List<Pokemon>();

        public void Catch(Pokemon target)
        {
            pokemons.Add(target);
        }

        public Pokemon Throw(string name)
        {
            //람다식, 델리게이트
            return pokemons.Find(pokemon => pokemon.Name == name);
        }
    }

    
}
