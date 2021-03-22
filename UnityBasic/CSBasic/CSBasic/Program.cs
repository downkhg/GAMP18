using System;

namespace CSBasic
{
    class Program //클래스
    {
        static void Main(string[] args)//ctrl+F5
        {//블록(중괄호)
            Console.WriteLine("TEST!");//라이브러리함수
            Console.WriteLine("Add:" + Add(10, 20));//30 //5
            ValMain();//함수의 호출
            PlayerAttackMonsterMain();
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
            float fRat = 1.0f / 4.0f;
            Console.WriteLine("Score:" + nScore);
            Console.WriteLine("Rat:" + fRat);
       }

        //플레이어가 몬스터를 공격하기.
        //1.플레이어? 몬스터? 공격?
        //1.1.공격: 데미지를 입음. 체력이 감소.
        //1.2.플레이어의 공격력만큼 몬스터의 hp가 감소한다.
        //데이터: 공격력, 체력 -> 변수 (정수)
        //알고리즘(연산): 체력이 공격력만큼 감소한다. 체력 - 공격력 = 체력
        static void PlayerAttackMonsterMain()
        {
            //데이터를 변수로 만든다.
            int nAttack = 10;
            int nHP = 100;
            //변수의 값을 분석한 결과대로 나오도록 연산한다.
            nHP = nHP - nAttack;
            //다음값을 확인가능하도록 출력하기
        }
    }
}
