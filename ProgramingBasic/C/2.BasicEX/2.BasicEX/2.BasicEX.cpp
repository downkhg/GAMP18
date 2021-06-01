#include <stdio.h>
//초기의 (세균)의 10마리고 1시간마다 2배씩 늘어난다면 100마리 이상이 되는데 (시간)이 얼마나 걸리는가?
//1.데이터와 알고리즘을 분리한다.
//데이터: 시간, 세균
//알고리즘: 세균수 * 2, 시간+1, 세균수가 100마리이상이 되는 시간을 출력한다.
//2.데이터는 변수 알고리즘은 연산,반복,조건 등이 조합된다.
//3.반복되는 경우는 먼저 반복하고 정답을 출력한다.
void BateriaMain()
{
	int nBateria = 10;
	int nTime = 0;
	/*
	//1. 조건을 만족할때까지 반복을 해본다.
	//nBateria = nBateria * 2; //10*2 = 20
	//nTime++; //0+1 = 1

	//nBateria = nBateria * 2; //20*2 = 40
	//nTime++; //1+1 = 2

	//nBateria = nBateria * 2; //40*2 = 80
	//nTime++; //2+1 = 3

	//nBateria = nBateria * 2; //80*2 = 160
	//nTime++; //3+1 = 4
	*/
	
	//while (true)//2.반복되는 부분을 찾고 무한루프를 돌린다.
	while( nBateria < 100) //3.break문에 조건의 반대경우를 while문의 조건으로 설정한다.
	{
		nBateria = nBateria * 2; //10*2 = 20
		nTime++; //0+1 = 1
		//4.반복문안에서 모든 변수의 값을 확인하여 정상적으로 진행되었는지 확인한다.
		printf("Bateria:%d Time:%d\n", nBateria, nTime);
		//if (nBateria >= 100) break;
	}
	printf("Time:%d\n",nTime);
}

//종이를 접으면 (면적)이 (1/2로 줄어)들때,
//(초기면적의 종이면적이 1/10이하)로 줄어들려면, (몇번접)아야하는가?
//데이터: 면적, 접은횟수
//알고리즘: 종이의 면적이 1/10이하가 되면 몇번 접어야하는가?
//1.반복문을 이용하여 문제를 해결한다.
//2.작동결과와 데이터의 변화를 분석하여 문제점을 찾는다 -> 계산결과가 소숫점은 무시된다 -> 실수로 변경
//3.2와 같은 과정에서 연산결과를 변수에 넣지않아 실수할수 있으므로 연산이되는 값은 무조건 변수에 저장한다.
void PaperAreaMain()
{
	float fArea = 100;
	float fCount = 0;
	float fMinArea = fArea * 0.1f;
	//while (true)
	//while(!(fArea <= fMinArea))
	while (fArea >= fMinArea)
	{
		fArea = fArea * 0.5f;
		fCount++;
		printf("Area:%f, Count:%f, MinArea:%f\n", fArea,fCount,fMinArea);
		if (fArea < fMinArea) break;
	}
	printf("Area:%f\n", fArea);
}

//(세균:변수) 10마리를 배양하여 (10시간후:조건)의 세균수를 구하여라.
//이때, 세균이 (1시간 마다 4배)찍 증가한다 
//세균수:10 //시간:0  //세균수*=4
void BateriaForMain()
{
	int nBateria = 10;
	int nTime = 0;

	//while (true) //3.break문에 조건의 반대경우를 while문의 조건으로 설정한다.
	for(/*초기화생략가능*/; nTime <= 10; nTime++ )//되도록이면 조건을 생략하는것은 하지말것!
	{
		nBateria = nBateria * 2; //10*2 = 20
		//nTime++; //0+1 = 1
		//4.반복문안에서 모든 변수의 값을 확인하여 정상적으로 진행되었는지 확인한다.
		printf("Bateria:%d Time:%d\n", nBateria, nTime);
		//if (nTime == 10) break;
	}
	//printf("Time:%d\n", nTime);
}

//종이를 10 번접으면 면적이 몇이되는가?
//이때, 종이의 면적 100이라고하자.
//(종이면적은 반으로줄어든다)
void PaperForMain()
{

}

//반감기: 방사능물질의양이 1/2가 되는 시간
//방사능 물질의 양이 2000년이 지난후 물질의 양은?
//반감기:400년
//방사능물질의양: 100
//데이터: 방사능물질량, 반감기, 시간
//알고리즘: 방사능물질량*0.5 = 방사능물질량,  시간+반감기
void HalfLifeForMain()
{

}

//반감기: 물질의양이 반으로 줄어드는 시간
//(방사능물질의 양)이 (1/10이하량이 되는데) (몇년)이 걸리는가?
//물질의 반감기: 400년 
//물질량: 100 
void HalfLifeMain()
{

}



//업다운게임: 
//숫자를 제시하면 그 숫자가 정해진수 보다 작으면, down 크면 up 맞추면 끝.
//1.(정답 Q) 은 정해져있다.
//2.정답보다 (큰수)를  (A 입력)받으면 up이라고 출력
//3.정답보다 (작은수)를 (A 입력)받으면 down이라고 출력
//4.정답이 아니라면 다시 입력받음.
//5.정답이라면 게임을 끝낸다.
//정답을 랜덤으로 생성하도록 만들기
void UpDownGameMain()
{




}
/* 
다음모양을 출력하라.
해당모양의 이름의 함수안에 조건만 변경하여 해당모양이 출력되도록만들기
Full    Rect   Window Stair
y01234x y01234xy 01234xy 01234x
0#####  0#####  0#####  0#
1#####  1#   #  1# # #  1##
2#####  2#   #  2#####  2###
3#####  3#   #  3# # #  3####
4#####  4#####  4#####  4##### 
*/
//1.규칙을 찾는다.
//Rect(y,x) 
//(1,1)(1,2)(1,3) 
//(2,1)(2,2)(2,3) 
//(3,1)(3,2)(3,3) 1~3
//Window  
//(1,1)(1,3)
//(3,1)(3,3) -> 홀수
//Stair '#' 
//(0,0) //(0,0)
//(1,0)(1,1) //(1,0)~(1,1) 
//(2,0)(2,1)(2,2) //(2,0)~(2,2) 
//(3,0)(3,1)(3,2)(3,3) //(3,0)~(3,3) 
//(4,0)(4,1)(4,2)(4,3)(4,4) //(4,0)~(4,4) 
//2.규칙대로 조건을 모두 준다.
//3.규칙에서 줄일만한 부분이 없는지 찾는다.
//(조건문없이가능) -> y가 증가할때마다 x의 값이 증가한다.
void RectMain()
{
	/* 
	//반복문을 사용하지않으면 노가다
	//printf("#####\n");
	//printf("#####\n");
	//printf("#####\n");
	//printf("#####\n");
	//printf("#####\n");
	*/

	//반복하여 조건처리가 가능하지만 계단모양은 처리가 어렵다.
	//for (int i = 0; i < 5; i++)
	//	printf("#####\n");

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			if((x > 0 && x < 4) && (y > 0 && y < 4))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
void WindowMain()
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			if ((x % 2 > 0 && y%2 > 0))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
void StiarMain()
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < y+1; x++)
		{
			printf("#");
		}
		printf("\n");
	}
}

void main()
{
	//BateriaMain();
	//PaperAreaMain();
	//BateriaForMain();
	//RectMain();
	//WindowMain();
	StiarMain();
}