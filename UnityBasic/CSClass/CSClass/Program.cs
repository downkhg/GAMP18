using System;
using System.Collections.Generic;

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
            //BattleMain();
            //GameMain();
            PokemonGameMain();
        }

        static void ObjectTestMain()
        {
            //m_cPlayer = new Player("player", 100, 10);
            m_cPlayer.Attack(m_cMonster);

            m_cPlayer.Show();
            m_cMonster.Show();
        }

        static void GameMain()
        {
            Player cPlayer = new Player("player", 100, 10);

            List<Player> listMonster = new List<Player>();
            listMonster.Add(new Player("slime", 20, 10));
            listMonster.Add(new Player("skeleton", 50, 20));
            listMonster.Add(new Player("zomble", 100, 20));
            listMonster.Add(new Player("dragon", 200, 100));

            string strInputText = "";
            Console.WriteLine("이동할 장소를 선택하세요(숲,던전,무덤,둥지)");
            strInputText = Console.ReadLine();

            switch (strInputText)
            {
                case "숲":
                    Console.WriteLine(listMonster[0] + "가 서식 하는 " + strInputText + "입니다.");
                    BattleMain(cPlayer, listMonster[0]);
                    //실제 게임에서는 해당 출력이후 게임에서 필요한 처리를 장소마다 다르게해야한다.
                    break;
                case "던전":
                    Console.WriteLine(listMonster[1] + "가 서식 하는 " + strInputText + "입니다.");
                    BattleMain(cPlayer, listMonster[1]);
                    break;
                case "무덤":
                    Console.WriteLine(listMonster[2] + "가 서식 하는 " + strInputText + "입니다.");
                    BattleMain(cPlayer, listMonster[2]);
                    break;
                case "둥지":
                    Console.WriteLine(listMonster[3] + "가 서식 하는 " + strInputText + "입니다.");
                    BattleMain(cPlayer, listMonster[3]);
                    break;
                default:
                    Console.WriteLine(strInputText + "는 존재하지않습니다.");
                    break;
            }
        }

        static void BattleMain(Player cPlayer, Player cMonster)
        {
            while (true)
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

        static bool BattlePokemon(Pokemon cPlayer, Pokemon cMonster)
        {
            while (true)
            {
                //플레이어가 선빵
                cPlayer.Attack(cMonster);
                cMonster.Show();
                //몬스터가 죽었다면 종료
                if (cMonster.Death())
                {
                    Console.WriteLine("몬스터 사망!");
                    return true;
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
            return false;
        }

        static void PokemonGameMain()
        {
            Trainner trainner = new Trainner();

            Pokemon pokemonA = new Pokemon("Pikacu", 100, 10);

            trainner.Catch(pokemonA);

            Pokemon throwPokemon = trainner.Throw("test");

            if (throwPokemon != null)
            {
                throwPokemon.Show();

                if(BattlePokemon(throwPokemon, new Pokemon("test", 100, 10)))
                {
                    Console.WriteLine("Win!");
                }
                else
                    Console.WriteLine("Lose!");
            }
            else
                Console.WriteLine("Pokemon not Exist!");
        }
    }
}
