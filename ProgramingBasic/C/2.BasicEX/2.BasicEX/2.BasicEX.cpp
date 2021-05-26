#include <stdio.h>
//1.데이터와 알고리즘을 분리한다.
//2.데이터는 변수 알고리즘은 연산,반복,조건 등이 조합된다.
//3.반복되는 경우는 먼저 반복하고 정답을 출력한다.
/*
void BateriaMain()
{
	int nBateria = 10;
	int nTime = 0;

	nBateria = nBateria * 2;//20
	nTime = 1;

	nBateria = nBateria * 2;//40
	nTime = 2;

	nBateria = nBateria * 2;//80
	nTime = 3;

	nBateria = nBateria * 2;//160
	nTime = 4;

	printf("Time:%d\n", nTime);
}
*/
//4.반복되는 규칙성을 찾아서 무한반복을 돌린후 반복된 과정을 모두 확인한다.
//(프로그래머가 아니라면 여기서 마쳐도 무방함. 그러나 정치질(약점잡아 늘어지기)에 희생량이 될수있음)
/*
void BateriaMain()
{
	int nBateria = 10;
	int nTime = 0;

	while (true)
	{
		nBateria = nBateria * 2;//20
		nTime = nTime + 1;
		printf("Bateria:%d Time:%d\n", nBateria, nTime);
		if (nBateria > 100) break;
	}
}
*/
//5.break문의 조건을 반대로 if문에 넣는다.(초과,미만:불포함  이상,이하:포함)
//세균은 10마리를 배양하고 세균수가 100마리 이상이 되는 시간은?
//세균은 1시간마다 2배씩 증가한다.
//데이터: 세균수,시간
//알고리즘: 세균수*2, 1시간마다, 100마리 이상이될때까지
void BateriaMain()
{
	int nBateria = 10;
	int nTime = 0;

	while (nBateria <= 100)
	{
		nBateria = nBateria * 2;//20
		nTime = nTime + 1;
		printf("Bateria:%d Time:%d\n", nBateria, nTime);
		//if (nBateria > 100) break;
	}
}

//종이를 접으면 (면적)이 (1/2로 줄어)들때,
//(종이면적이 1/10이하)로 줄어들려면, (몇번접)아야하는가?
void PaperAreaMain()
{

}

//(세균:변수) 10마리를 배양하여 (10시간후:조건)의 세균수를 구하여라.
//이때, 세균이 (1시간 마다 4배)찍 증가한다 
//세균수:10 //시간:0  //세균수*=4
void BateriaForMain()
{

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
/* 다음모양을 출력하라.
해당모양의 이름의 함수안에 조건만 변경하여 해당모양이 출력되도록만들기
Full    Rect   Window Stair
y01234x
0#####  #####  #####  #
1#####  #   #  # # #  ##
2#####  #   #  #####  ###
3#####  #   #  # # #  ####
4#####  #####  #####  ##### */
//1.규칙을 찾는다.
//Rect(y,x) (1,1)(1,2)(1,3) (2,1)(2,2)(2,3) (3,1)(3,2)(3,3) 1~3
//Window  (1,1)(1,3) (3,1)(3,3) -> 홀수
//Stair '#' (0,0) (1,0)(1,1) (2,0)(2,1)(2,2) 
//		    (3,0)(3,1)(3,2)(3,3) (4,0)(4,1)(4,2)(4,3)
//2.규칙대로 조건을 모두 준다.
//
//3.규칙에서 줄일만한 부분이 없는지 찾는다.
//(조건문없이가능) -> y가 증가할때마다 x의 값이 증가한다.
void RectMain()
{

}
void WindowMain()
{

}
void StiarMain()
{

}

void main()
{
	BateriaMain();
}