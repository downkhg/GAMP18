using System;
using System.Collections.Generic;

namespace CSBasic
{
    class Program //클래스
    {
        static void Main(string[] args)//ctrl+F5
        {//블록(중괄호)
         //Console.WriteLine("TEST!");//라이브러리함수
         //Console.WriteLine("Add:" + Add(10, 20));//30 //5
         //ValMain();//함수의 호출
         //PlayerAttackMonsterMain();
         // CriticalAttackMain();
         // StageMain();
         //AttackWihleMain();
         //BattleMain();
         //MonsterListMain();
         // SeletStageMonsterMain();
            CriticalAttackWihleMain();
        }
        //사용자정의함수.
        //함수: 기능. 괄호안에 넣은 값들을 조합해서 결과를 만듦.
        static int Add(int a, int b)//1. 10 20
        {
            int c = a + b; //2. 30 = 10  + 20
            return c; //3. 30
        }

       static void ValMain() 
       {
            int nScore = 0;
            float fRat = 1.0f / 4.0f;//실수형끼리 계산해야 실수로 나온다.
            Console.WriteLine("Score:" + nScore);
            Console.WriteLine("Rat:" + fRat);
       }

        //플레이어가 몬스터를 공격하기.
        //1.플레이어? 몬스터? 공격?
        //1.1.공격: 데미지를 입음. 체력이 감소.
        //1.2.플레이어의 공격력만큼 몬스터의 hp가 감소한다.
        //데이터: 공격력, 체력 -> 변수 (정수)
        //알고리즘(연산): 체력이 공격력만큼 감소한다. 체력 - 공격력 = 체력
        //2. 공격인가 자해인가? -> 대상이 없으면 구별할수 없음. 그러므로 대상이 무엇인지 명확하게 표현해야한다.
        static void PlayerAttackMonsterMain()
        {
            //데이터를 변수로 만든다.
            int nPlayerAttack = 10;
            int nMonsterHP = 100;
            Console.WriteLine("MonsterHP - PlayerAtk:" + nMonsterHP + " - " + nPlayerAttack);
            //변수의 값을 분석한 결과대로 나오도록 연산한다.
            nMonsterHP = nMonsterHP - nPlayerAttack;
            //다음값을 확인가능하도록 출력하기
            Console.WriteLine("MonsterHP:" + nMonsterHP);
        }
        //크리티컬공격 추가하기
        //1.크리티컬? 약점 더많은 피해를 준다. 일정확률로 발생한다.
        //1.1. 확률? 내가 준비한 물건중에 1개를 가져올 확률.
        static void CriticalAttackMain()
        {
            //데이터를 변수로 만든다.
            int nPlayerAttack = 10;
            int nMonsterHP = 100;
            //랜덤을 객체를 이용하여 범위를 설정하고, 랜덤값을 구한다.
            //구한 랜덤값이 특정 값이라면 크리티컬이 발생하고, 아니라면 발생하지않도록한다.
            //---------------------------------------------
            Random cRandom = new Random();
            int nRandom = cRandom.Next(1, 3);//마지막 숫자는 나오지않음.
            Console.WriteLine("Random:"+nRandom);
            if(nRandom == 1)
            {
                nMonsterHP = nMonsterHP - (int)(nPlayerAttack * 1.5f);
                Console.WriteLine("Critical Attack!");
            }
            else
            {
                nMonsterHP = nMonsterHP - nPlayerAttack;
                Console.WriteLine("MonsterHP - PlayerAtk:" + nMonsterHP + " - " + nPlayerAttack);
            }
            //---------------------------------------------
            //다음값을 확인가능하도록 출력하기
            Console.WriteLine("MonsterHP:" + nMonsterHP);
        }

        //마을에서 이동구현하기
        //플레이어가 이동할수 있는 영역은, 마을,상점, 필드가 있으며,
        //해당 위치를 선택하면 ~입니다 라고 출력하기.
        //(입력된 값:데이터-스트링)을 (출력:알고리즘)한다.
        //이 경우 잘못된 값을 입력해도 값이 정상적으로 출력된다. 다른경우에는 처리하지않아야한다.
        //다중 if문을 이용한경우 출력은 같으나 실제 게임에서는 마을마다 다른 처리를 해줘야한다.
        //switch문을 이용하여 처리하면 각 값마다 특정한 처리를 하고, 가독성이 좋다.
        static void StageMain()
        {
            Console.WriteLine("이동할 장소를 선택하세요(마을,상점,필드)");
            string strInputText = Console.ReadLine();

            switch(strInputText)
            {
                case "마을":
                    Console.WriteLine(strInputText + "입니다.");
                    //실제 게임에서는 해당 출력이후 게임에서 필요한 처리를 장소마다 다르게해야한다.
                    break;
                case "상점":
                    Console.WriteLine(strInputText + "입니다.");
                    break;
                case "필드":
                    Console.WriteLine(strInputText + "입니다.");
                    break;
                default:
                    Console.WriteLine(strInputText + "는 존재하지않습니다.");
                    break;
            }

            //if (strInputText == "마을" || strInputText == "상점" || strInputText == "필드")
            //{
            //    Console.WriteLine(strInputText + "입니다.");
            //}
            //else
            //    Console.WriteLine(strInputText + "는 존재하지않습니다.");
        }

        //몬스터가 사망할때까지 공격한다. -> 사망X아닐때 공격
        //사망? 체력이 0이되면 죽는다. if( 체력 == 0) 죽음.
        //사망판단? 체력이 0이되면 죽고 그만해야함.
        // if( 체력 == 0) 보다 작은 수가 되면 안죽음. 0보다 작아도 죽음.
        //처음부터 완벽한 코드를 만들지말고 만들면서 부족한 부분을 채워보기!
        static void AttackWihleMain()
        {
            //데이터를 변수로 만든다.
            int nPlayerAttack = 11;
            int nMonsterHP = 100;
            //while ((nMonsterHP < 0)) //100 < 0 //F
            //while (!(nMonsterHP < 0)) //100 < 0 //F -> T
            while ((nMonsterHP >= 0)) //100 < 0 //T
            {
                Console.WriteLine("MonsterHP - PlayerAtk:" + nMonsterHP + " - " + nPlayerAttack);
                //변수의 값을 분석한 결과대로 나오도록 연산한다.
                nMonsterHP = nMonsterHP - nPlayerAttack;
                //다음값을 확인가능하도록 출력하기
                Console.WriteLine("MonsterHP:" + nMonsterHP);
                if (nMonsterHP < 0)
                {
                    Console.WriteLine("몬스터 사망");
                    break;
                }
            }
        }

        static void CriticalAttackWihleMain()
        {
            //데이터를 변수로 만든다.
            int nPlayerAttack = 11;
            int nMonsterHP = 100;
            Random cRandom = new Random();
            //while ((nMonsterHP < 0)) //100 < 0 //F
            //while (!(nMonsterHP < 0)) //100 < 0 //F -> T
            while ((nMonsterHP >= 0)) //100 < 0 //T
            {
                int nRandom = cRandom.Next(1, 3);
                if (nRandom == 1)
                {
                    int nCritcalHit = (int)(nPlayerAttack * 1.5f);
                    Console.WriteLine("Critical! MonsterHP - PlayerAtk:" + nMonsterHP + " - " + nCritcalHit);
                    //변수의 값을 분석한 결과대로 나오도록 연산한다.
                    nMonsterHP = nMonsterHP - nCritcalHit;
                }
                else
                {
                    Console.WriteLine("MonsterHP - PlayerAtk:" + nMonsterHP + " - " + nPlayerAttack);
                    //변수의 값을 분석한 결과대로 나오도록 연산한다.
                    nMonsterHP = nMonsterHP - nPlayerAttack;
                }
                //다음값을 확인가능하도록 출력하기
                Console.WriteLine("MonsterHP:" + nMonsterHP);
                if (nMonsterHP < 0)
                {
                    Console.WriteLine("몬스터 사망");
                    break;
                }
            }
        }

        //플레이어가 몬스터를 공격하고 몬스터는 공격한다.
        //플레이어가 몬스터를 공격하고 몬스터는 반격한다.
        //플레이어가 몬스터를 공격하고 공격받은 몬스터는 플레이어를 공격한다.
        //몬스터의 데미지만큼 플레이어의 체력을 깍는다.
        //데이터: 몬스터의 데미지, 플레이어의 체력
        static void BattleMain()
        {
            //데이터를 변수로 만든다.
            int nPlayerAttack = 11;
            int nMonsterHP = 100;

            int nMonsterAttack = 11;
            int nPlayerHP = 100;

            //while ((nMonsterHP < 0)) //100 < 0 //F
            //while (!(nMonsterHP < 0)) //100 < 0 //F -> T
            while ((nMonsterHP >= 0)) //100 < 0 //T
            {
                Console.WriteLine("MonsterHP - PlayerAtk:" + nMonsterHP + " - " + nPlayerAttack);
                //변수의 값을 분석한 결과대로 나오도록 연산한다.
                nMonsterHP = nMonsterHP - nPlayerAttack;
                //다음값을 확인가능하도록 출력하기
                Console.WriteLine("MonsterHP:" + nMonsterHP);
                if (nMonsterHP < 0)
                {
                    Console.WriteLine("몬스터 사망");
                    break;
                }

                nPlayerHP = nPlayerHP - nMonsterAttack;
                Console.WriteLine("PlayerHP:" + nPlayerHP);
                if (nPlayerHP < 0)
                {
                    Console.WriteLine("플레이어 사망");
                    break;
                }
            }
        }
        //리스트를 만들어 슬라임,스켈레톤,좀비,드래곤을 추가하고,
        //리스트의 0,3을 각각 출력하고,
        //리스트를 모두 출력하기
        static void MonsterListMain()
        {
            List<string> listMonster = new List<string>();

            listMonster.Add("Slime");
            listMonster.Add("Skeleton");
            listMonster.Add("Zombie");
            listMonster.Add("Dragon");

            Console.WriteLine(0 + ":" + listMonster[0]);
            Console.WriteLine(3 + ":" + listMonster[3]);

            for (int i = 0; i < listMonster.Count; i++)
                Console.WriteLine(i + ":" + listMonster[i]);
        }

        static void SeletStageMonsterMain()
        {
            List<string> listMonster = new List<string>();

            listMonster.Add("Slime");
            listMonster.Add("Skeleton");
            listMonster.Add("Zombie");
            listMonster.Add("Dragon");

            string strInputText = "";
            Console.WriteLine("이동할 장소를 선택하세요(숲,던전,무덤,둥지)");
            strInputText = Console.ReadLine();

            switch (strInputText)
            {
                case "숲":
                    Console.WriteLine(listMonster[0] + "가 서식 하는 " + strInputText + "입니다." );
                    //실제 게임에서는 해당 출력이후 게임에서 필요한 처리를 장소마다 다르게해야한다.
                    break;
                case "던전":
                    Console.WriteLine(listMonster[1] + "가 서식 하는 " + strInputText + "입니다.");
                    break;
                case "무덤":
                    Console.WriteLine(listMonster[2] + "가 서식 하는 " + strInputText + "입니다.");
                    break;
                case "둥지":
                    Console.WriteLine(listMonster[3] + "가 서식 하는 " + strInputText + "입니다.");
                    break;
                default:
                    Console.WriteLine(strInputText + "는 존재하지않습니다.");
                    break;
            }
        }
    }
}
