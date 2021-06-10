#include <stdio.h>
#include <string.h>

//�÷��̾�
//�Ӽ�(����ɼ��ִ°�:����):�ɷ�ġ(���ݷ�,����,ü��),����ġ,����,�̸�
//����ü�� ����: ����ü�� �����ϴ� ��ҵ��� ��� �����Ǵ��� �����ϴ� ���赵
///��������� ����: ����ü�� �������� �����ϰ� �����Ͽ� ���ϴ� ������ ������ִ�.
//����ü�� �����̹Ƿ� ����ü�ȿ� ������ �������ִ�.(��������� Status����ü ����)
struct Player //����ü�� 4����Ʈ������ �޸𸮰� �Ҵ�ȴ�. 4�ǹ���� �ƴϸ� �޸𸮰� ����ɼ�����.
{
	char strName[253];//256 //253�� �������. 
	int nAtk; //4
	int nDef; //4
	int nHP; //4
	int nExp; //4
	int nLv; //4
};
//����ü�� �����̹Ƿ� �������������� �Ͼ�Ƿ� ���� �����ϱ����ؼ� ������ ����ؾ��Ѵ�.
Player InitPlayerVal(Player player, const char* name, int atk, int def, int hp, int exp, int lv)
{
	//Player player;//����ü�� ����.
	strcpy(player.strName, name);
	player.nAtk = atk;//����ü������ �����������
	player.nDef = def;
	player.nHP = hp;
	player.nExp = exp;
	player.nLv = lv;
	printf("InitPlayerVal:%d\n",&player);
	return player;
}
//�����ͷ� �����ϸ� �ּҰ��� �����ϹǷ�, ���� ���������ʾƵ� ������ �޸𸮰��� ���氡���ϴ�.
void InitPlayerPtr(Player* pPlayer, const char* name, int atk, int def, int hp, int exp, int lv)
{
	printf("InitPlayerVal:%d\n", pPlayer);
	strcpy(pPlayer->strName, name);
	pPlayer->nAtk = atk;//����ü������ �����������
	pPlayer->nDef = def;
	pPlayer->nHP = hp;
	pPlayer->nExp = exp;
	pPlayer->nLv = lv;
}
void InitPlayerRef(Player& player, const char* name, int atk, int def, int hp, int exp, int lv)
{
	printf("InitPlayerRef:%d\n", &player);
	strcpy(player.strName, name);
	player.nAtk = atk;//����ü������ �����������
	player.nDef = def;
	player.nHP = hp;
	player.nExp = exp;
	player.nLv = lv;
}
//��½� ������ �ջ��� �����ʾƾ��ϹǷ� const�� �̿��Ѵ�.
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
	Player player;//����ü�� ����.
	player.nAtk = 10;//����ü������ �����������
	player.nDef = 10;
	player.nHP = 100;
	player.nExp = 0;
	player.nLv = 1;
	strcpy(player.strName, "test");//���ڿ��� ���������� �Լ��� �̿��Ͽ� �ʱ�ȭ�Ѵ�.
	printf("player[%d]:%d\n", sizeof(player), &player);
	player = InitPlayerVal(player, "testval", 10, 10, 100, 0, 1);
	PrintPlayer(player);
	InitPlayerPtr(&player, "testptr", 10, 10, 100, 50, 1);
	PrintPlayer(player);
	InitPlayerRef(player, "testref", 20, 20, 110, 0, 2);
	PrintPlayer(player);

	//player == player //�����Ͽ���. ����ü�� �����̹Ƿ� �޸𸮰� ���ٰ��ؼ� ���ٰ� �����ϱ��ƴ�.
}

//����ü: ����� �޸𸮰� �����ȴ�.
union IpAdress {
	unsigned long laddr;
	unsigned char saddr[4];
};

void IpAdressMain()
{
	union IpAdress addr;

	//����ȣ��Ʈ: ��ǻ�� �ڱ��ڽ��� ������ �����ϴ� �ּ�.
	addr.saddr[0] = 1;
	addr.saddr[1] = 0;
	addr.saddr[2] = 0;
	addr.saddr[3] = 127;

	printf("[%d]:%x\n", sizeof(IpAdress), addr.laddr);
}

//#define TITLE 0 //��ó���⸦ �̿��Ҽ����ִ�.
enum E_GUISTATUS { TITLE, GAMEOVER, PLAY };
//enum: ���ǵȼ��ڸ� ����ϱ� ������ �����ϴ°�.
void EnumTestMain()
{
	int eCurStatus;

	eCurStatus = E_GUISTATUS::PLAY;
	//���� 0���� title�̶�� �ǹ̰� �����ϱ⽱��.
	//eCurStatus = 0;

	switch (eCurStatus)
	{
	case TITLE:
		printf("Ÿ��Ʋ");
		break;
	case GAMEOVER:
		printf("���ӿ���");
		break;
	case PLAY:
		printf("���� ������...");
		break;
	}
}

void main()
{
	//IpAdressMain();
	EnumTestMain();
}