using System;

namespace CSClass
{
    public class Player
    {
        private string m_strName;
        private int m_nExp;
        private int m_nLv;
        private int m_nHP;
        private int m_nStr;

        public Player(string name, int hp, int str)
        {
            m_strName = name;
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

        public void Show()
        {
            Console.WriteLine("Name:" + m_strName);
            Console.WriteLine("HP:" + m_nHP);
            Console.WriteLine("STR:" + m_nStr);
            Console.WriteLine("Lv/Exp:{0}/{1}",m_nLv,m_nExp );
        }
    }
    class Program
    {
        static Player m_cPlayer; //객체: 클래스의 인스턴스를 참조할수 있는 객체(클래스의 포인터와 유사)
        static Player m_cMonster = new Player("monster",100,10);//인스턴스: 일회성으로 사용될 객체(클래스의 동적할당된 객체)
        static void Main(string[] args)
        {
            //ObjectTestMain();
            BattleMain();
        }

        static void ObjectTestMain()
        {
            m_cPlayer = new Player("player", 100, 10);
            m_cPlayer.Attack(m_cMonster);

            m_cPlayer.Show();
            m_cMonster.Show();
        }

        static void BattleMain()
        {
            Player cPlayer = new Player("player", 100, 10);
            Player cMonster = new Player("slime",20,10);

            while(true)
            {
                //플레이어가 선빵
                cPlayer.Attack(cMonster);
                cMonster.Show();
                //몬스터가 죽었다면 종료
                if (cMonster.Death())
                {
                    Console.WriteLine("몬스터 사망!");
                    break;
                }
                
                //몬스터가 반격
                cMonster.Attack(cPlayer);
                cPlayer.Show();
                //플레이어가 죽었다면 종효
                if (cPlayer.Death())
                {
                    Console.WriteLine("플레이어 사망!");
                    break;
                }
            }
        }
    }
}
