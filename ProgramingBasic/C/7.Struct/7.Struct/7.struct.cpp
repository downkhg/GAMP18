#include <stdio.h>
#include <string.h>

//플레이어
//속성(변경될수있는값:변수):능력치(공격력,방어력,체력),경험치,레벨,이름
//구조체의 정의: 구조체를 구성하는 요소들을 어떻게 구성되는지 저장하는 설계도
///사용자정의 변수: 구조체는 변수들을 정의하고 조합하여 원하는 변수를 만들수있다.
//구조체도 변수이므로 구조체안에 변수를 넣을수있다.(파일입출력 Status구조체 참조)
struct Player //구조체는 4바이트단위로 메모리가 할당된다. 4의배수가 아니면 메모리가 낭비될수있음.
{
	char strName[253];//256 //253과 결과같음. 
	int nAtk; //4
	int nDef; //4
	int nHP; //4
	int nExp; //4
	int nLv; //4
};
//구조체도 변수이므로 값에의한참조가 일어나므로 값을 변경하기위해서 리턴을 사용해야한다.
Player InitPlayerVal(Player player, const char* name, int atk, int def, int hp, int exp, int lv)
{
	//Player player;//구조체의 선언.
	strcpy(player.strName, name);
	player.nAtk = atk;//구조체변수의 멤버변수접근
	player.nDef = def;
	player.nHP = hp;
	player.nExp = exp;
	player.nLv = lv;
	printf("InitPlayerVal:%d\n",&player);
	return player;
}
//포인터로 전달하면 주소값을 전달하므로, 따로 리턴하지않아도 원본의 메모리값을 변경가능하다.
void InitPlayerPtr(Player* pPlayer, const char* name, int atk, int def, int hp, int exp, int lv)
{
	printf("InitPlayerVal:%d\n", pPlayer);
	strcpy(pPlayer->strName, name);
	pPlayer->nAtk = atk;//구조체변수의 멤버변수접근
	pPlayer->nDef = def;
	pPlayer->nHP = hp;
	pPlayer->nExp = exp;
	pPlayer->nLv = lv;
}
void InitPlayerRef(Player& player, const char* name, int atk, int def, int hp, int exp, int lv)
{
	printf("InitPlayerRef:%d\n", &player);
	strcpy(player.strName, name);
	player.nAtk = atk;//구조체변수의 멤버변수접근
	player.nDef = def;
	player.nHP = hp;
	player.nExp = exp;
	player.nLv = lv;
}
//출력시 원본이 손상이 되지않아야하므로 const를 이용한다.
void PrintPlayer(const Player& player)
{
	printf("############ %s ##############\n",player.strName);
	printf("Atk:%d\n",player.nAtk);
	printf("Def:%d\n", player.nDef);
	printf("HP:%d\n", player.nHP);
	printf("Exp:%d\n", player.nExp);
	printf("Lv:%d\n", player.nLv);
}

void StructMain()
{
	Player player;//구조체의 선언.
	player.nAtk = 10;//구조체변수의 멤버변수접근
	player.nDef = 10;
	player.nHP = 100;
	player.nExp = 0;
	player.nLv = 1;
	strcpy(player.strName, "test");//문자열은 다음과같이 함수를 이용하여 초기화한다.
	printf("player[%d]:%d\n", sizeof(player), &player);
	player = InitPlayerVal(player, "testval", 10, 10, 100, 0, 1);
	PrintPlayer(player);
	InitPlayerPtr(&player, "testptr", 10, 10, 100, 50, 1);
	PrintPlayer(player);
	InitPlayerRef(player, "testref", 20, 20, 110, 0, 2);
	PrintPlayer(player);

	//player == player //컴파일오류. 구조체는 집합이므로 메모리가 같다고해서 같다고 정의하긴어렵다.
}

//공용체: 멤버의 메모리가 공유된다.
union IpAdress {
	unsigned long laddr;
	unsigned char saddr[4];
};

void IpAdressMain()
{
	union IpAdress addr;

	//로컬호스트: 컴퓨터 자기자신의 서버에 접속하는 주소.
	addr.saddr[0] = 1;
	addr.saddr[1] = 0;
	addr.saddr[2] = 0;
	addr.saddr[3] = 127;

	printf("[%d]:%x\n", sizeof(IpAdress), addr.laddr);
}

//#define TITLE 0 //전처리기를 이용할수도있다.
enum E_GUISTATUS { TITLE, GAMEOVER, PLAY };
//enum: 정의된숫자를 기억하기 쉽도록 정의하는것.
void EnumTestMain()
{
	int eCurStatus;

	eCurStatus = E_GUISTATUS::PLAY;
	//숫자 0보다 title이라는 의미가 이해하기쉽다.
	//eCurStatus = 0;

	switch (eCurStatus)
	{
	case TITLE:
		printf("타이틀");
		break;
	case GAMEOVER:
		printf("게임오버");
		break;
	case PLAY:
		printf("게임 진행중...");
		break;
	}
}

void main()
{
	//IpAdressMain();
	EnumTestMain();
}