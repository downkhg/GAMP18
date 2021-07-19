/*##################################
���Ͽ��Ḯ��Ʈ(������)
���ϸ�: LinkedList_empty.cpp
�ۼ���: ��ȫ�� (downkhg@gmail.com)
������������¥: 2019.04.12
����: 1.10
###################################*/

#include <stdio.h>
#include <stdlib.h> //�޸� �����Ҵ� ���
#include <crtdbg.h> //�޸� ���� Ž�� ���
#include "1.1.LinkedList.h"

struct SNode {
	int nData;
	SNode* pNext;
};

SNode* CreateNode(SNode* pNode, int data); //��带 �����Ͽ� �����Ѵ�.
SNode* FindNodeData(SNode* pStart, int data); //�ش� �����͸� ���� ��带 ã�´�.
SNode* InsertNodeData(SNode* const pStart, int data, int insert); //�ش� �����͸� ���� ��� �ڿ� ��带 �߰��Ѵ�.
void DeleteNodeData(SNode* &pStart, int del); //�ش絥���͸� ���� ��带 �����Ѵ�.
void DeleteNodeData(SNode** pStart, int del); //�ش絥���͸� ���� ��带 �����Ѵ�.
void PrintLinkedList(SNode* pStart); //��带 ��ȸ�ϸ� ���������� ����Ѵ�.
void DeleteLinkedList(SNode* pStart); //��带 ��ȸ�ϸ� ��絥���͸� �����Ѵ�.
void ReverseLinkedList(SNode* pStart); //

									   //���Ḯ��Ʈ �������� �Է¹ޱ�.(�����Ҵ� ������)
void InputAdd();

void LinkedListTestMain()
{
	_CrtSetBreakAlloc(85); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 

	SNode* pBegin = NULL;
	SNode* pEnd = NULL;

	//��� �߰� �׽�Ʈ
	pEnd = CreateNode(pEnd, 10);
	pBegin = pEnd; //������ ��带 �˾ƾ� �˻��� �����ϹǷ� �����صд�.

	pEnd = CreateNode(pEnd, 20);
	pEnd = CreateNode(pEnd, 30);
	pEnd = CreateNode(pEnd, 40);
	pEnd = CreateNode(pEnd, 50);

	PrintLinkedList(pBegin);

	SNode* pFind = FindNodeData(pBegin, 40);
	if (pFind != NULL)
		printf("Find:%d\n", pFind->nData);

	SNode* pInsert = InsertNodeData(pBegin, 30, 60);//��� ����
	if (pInsert != NULL)
		printf("Insert:%d\n", pFind->nData);

	PrintLinkedList(pBegin);

	DeleteNodeData(pBegin, 60);//��� ����
	//DeleteNodeData(&pBegin, 10);//��� ����

	PrintLinkedList(pBegin);

	DeleteLinkedList(pBegin); //�������� - �� �Լ��� ȣ������������ �޸𸮰� ������.
}

//�����۵� �׽�Ʈ�� ���ؼ�, ������ ���� �⺻���� ������ ������ Ȯ���Ѵ�.
//�� �ҽ��� ��� ���װ� �����Ѵ�.
//�� �ڵ尡 �����۵� �� �� �߰��غ���!
//main()�Լ� �� �ڵ�� �߰��� ���������� ������ ��������!
void main()
{
	LinkedListSampleTestMain();
	//InputAdd();
}

//���⼭ ���� ����� �����Ѵ�.
//�����ڵ�� �մ�������, �߰��� �Ͽ� �� ���α׷� ���� �۵��ϵ����Ұ�.
SNode* CreateNode(SNode* pNode, int data)
{
	SNode* pTemp = NULL;

	pTemp = (SNode*)malloc(sizeof(SNode));//new SNode(); 
	pTemp->nData = data;
	pTemp->pNext = NULL;
	
	if(pNode != NULL)//0x04 !=  NULL -> T
		pNode->pNext = pTemp;

	return  pTemp;
}

SNode* FindNodeData(SNode* const pStart, int data)
{
	SNode* pNode = pStart;
	//while (true)
	while (pNode)
	{
		if (pNode->nData != data)
			pNode = pNode->pNext;
		else
			break;
	}
	return pNode;
}

SNode* InsertNodeData(SNode* const pStart, int data, int insert)
{
	SNode* pNode = pStart;
	SNode* pInsert = NULL;

	pNode = FindNodeData(pStart, data);

	if (pNode)
	{
		pInsert = new SNode();
		pInsert->pNext = pNode->pNext;
		pNode->pNext = pInsert;
		pInsert->nData = insert;
	}

	return pInsert;
}

void DeleteNodeData(SNode* &pStart, int del)
{
	SNode* pPre = NULL;
	SNode* pNode = pStart;

	//pNode = FindNodeData(pStart, del);
	//pPre = FindNodeData(pStart, 30);

	while (pNode)//0x01!=N:T
	{
		if (pNode->nData != del)//10!=10:F
		{
			pPre = pNode;
			pNode = pNode->pNext;
		}
		else
			break;
	}

	if (pNode)
	{
		if (pPre)
			pPre->pNext = pNode->pNext;
		else
			pStart = pNode->pNext;
		delete pNode;
	}
}
//���������͸� �̿��Ͽ� ���������� ���� ������.
void DeleteNodeData(SNode** pStart, int del)
{
	SNode* pPre = NULL;
	SNode* pNode = *pStart;

	//pNode = FindNodeData(pStart, del);
	//pPre = FindNodeData(pStart, 30);

	while (pNode)//0x01!=N:T
	{
		if (pNode->nData != del)//10!=10:F
		{
			pPre = pNode;
			pNode = pNode->pNext;
		}
		else
		{
			if (pNode)
			{
				if (pPre)
					pPre->pNext = pNode->pNext;
				else
					*pStart = pNode->pNext;
			}
			delete pNode;
		}
	}
	
	
}

void PrintLinkedList(SNode* pStart)
{
	SNode* pNode = pStart;
	printf("data:");
	while (pNode)
	{
		printf("%d", pNode->nData);
		pNode = pNode->pNext;

		if (pNode != NULL)
			printf(",");
	}
	printf("\n");
}

void DeleteLinkedList(SNode* pStart)
{
	SNode* pNode = pStart;
	SNode* pDel = NULL;
	while (pNode)//0x01:T
	{
		pNode = pNode->pNext;	
		delete pNode;
	}
}

void InputAdd()
{
	SNode* pStart = NULL;
	SNode* pNode = NULL;
	int nData = 0;

	//�����Ҵ��� �ϸ� ���α׷��� ����ڿ� ���ؼ� ���Ǵ� �޸𸮰� �����ȴ�.
	//���Ը��ؼ�, �����ϴܰ迡�� 100���� ����� ���ٸ�, 
	//��������ʴ��� 100���� �޸𸮸� ����Ҽ��ۿ�����.
	//�׸���, 100�� �̻��� �޸𸮵� ����Ҽ�����.
	//�׷���, �����Ҵ��� �ϸ� ����ڰ� �߰��� �޸𸮸�ŭ�� �޸𸮰� ���ǰ� 
	//�޸𸮿뷮�� ����ϴ� �� �߰��� �ȴ�.
	while (nData != -1)
	{
		scanf("%d", &nData);
		pNode = CreateNode(pNode, nData);

		if (pNode == NULL)
		{
			printf("�� �̻� ����Ҽ� �ִ� �޸𸮰� �����ϴ�!");
		}

		if (pStart == NULL)
			pStart = pNode;

		PrintLinkedList(pStart);
	}

	DeleteLinkedList(pStart); //�������� - �� �Լ��� ȣ������������ �޸𸮰� ������.
}