#include <stdio.h>
#include <string.h>
struct Status
{
	int nHP;
	int nStr;
	int nDef;
};
struct RPGPlayer
{
	char strName[128];
	Status sStatus;
	int nExp;
	int nLv;
};
void InitRPGPlayer(RPGPlayer& player, const char* name, int hp, int str, int def, int exp)
{
	strcpy(player.strName, name);
	player.sStatus.nHP = hp;
	player.sStatus.nStr = str;
	player.sStatus.nDef = def;
	player.nLv = 1;
	player.nExp = exp;
}
void PrintRPGPlayer(RPGPlayer& player)
{
	printf("########### %s ##########\n", player.strName);
	printf("HP:%d\n", player.sStatus.nHP);
	printf("STR:%d\n", player.sStatus.nStr);
	printf("DEF:%d\n", player.sStatus.nDef);
	printf("Lv/Exp:%d/%d\n", player.nLv, player.nExp);
}
void RPGPlayerDataSaveBinary(RPGPlayer& player)
{
	FILE* pFIle;
	char strFileName[1024];
	sprintf(strFileName, "%s.dat", player.strName);
	pFIle = fopen(strFileName, "wb");

	if (pFIle)
	{
		fwrite((void*)&player, sizeof(player), 1, pFIle);
		fclose(pFIle);
	}
}
void RPGPlayerDataLoadBinary(RPGPlayer& player)
{
	FILE* pFIle;
	char strFileName[1024];
	sprintf(strFileName, "%s.dat", player.strName);
	pFIle = fopen(strFileName, "rb");

	if (pFIle)
	{
		fread((void*)&player, sizeof(player), 1, pFIle);
		fclose(pFIle);
	}
}
void RPGDataSaveLoadTestMain()
{
	RPGPlayer sPlayer;
	InitRPGPlayer(sPlayer, "Player", 100, 10, 5, 0);
	printf("### Init ####");
	PrintRPGPlayer(sPlayer);
	printf("### Save ####");
	RPGPlayerDataSaveBinary(sPlayer);
	printf("### Inc Def ####");
	sPlayer.sStatus.nDef += 10;
	PrintRPGPlayer(sPlayer);
	printf("### Load ####");
	RPGPlayerDataLoadBinary(sPlayer);
	PrintRPGPlayer(sPlayer);
}
//텍스트파일: 사용자가 텍스트를 저장해 내용을 확인할수있는 파일.
void TextFileWriteMain()
{
	FILE* pOpenFile;
	pOpenFile = fopen("test.txt", "w+"); //파일열기 쓰기모드
	if (pOpenFile)
	{
		fprintf(pOpenFile, "Gamp14WriteFile");
		fprintf(pOpenFile, "Test");
		fclose(pOpenFile);
	}
}

void TextFileReadMain()
{
	FILE* pOpenFile;
	pOpenFile = fopen("test.txt", "r+"); //파일열기 읽기모드
	char filestream[1024];
	if (pOpenFile)
	{
		fscanf(pOpenFile, "%s", filestream);
		printf("file stream:%s\n", filestream);
		fclose(pOpenFile);
	}
}

void BinaryFileWriteMain()
{
	char strBuffer[1024] = "Gamp14TestBinaryFile";
	FILE* pOpenFile = fopen("test.dat", "wb");

	if (pOpenFile)
	{
		fwrite(strBuffer, sizeof(char), 1024, pOpenFile);
		fclose(pOpenFile);
	}
}
void BinaryFileReadMain()
{
	FILE* pOpenFile;
	pOpenFile = fopen("test.dat", "rb"); //파일열기 바이너리
	char filestream[1024];
	if (pOpenFile)
	{
		fread(filestream, sizeof(char), 1024, pOpenFile);
		printf("file stream:%s\n", filestream);
		fclose(pOpenFile);
	}
}

void main()
{
	//TextFileWriteMain();
	//TextFileReadMain();
	//BinaryFileWriteMain();
	//BinaryFileReadMain();
	RPGDataSaveLoadTestMain();
}