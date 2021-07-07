#include "1.1.LinkedList.h"
#include <stdio.h>

CLinkecList::SNode* CLinkecList::CreateNode(int data)
{
	SNode* pTemp = NULL;

	pTemp = new SNode();
	pTemp->nData = data;
	pTemp->pNext = NULL;

	if (m_pEnd != NULL)//0x04 !=  NULL -> T
		m_pEnd->pNext = pTemp;
	else
		m_pBegin = pTemp;

	m_pEnd = pTemp;

	return  pTemp;
}

CLinkecList::SNode* CLinkecList::FindNodeData(int data)
{
	SNode* pNode = m_pBegin;
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

CLinkecList::SNode* CLinkecList::InsertNodeData( int data, int insert)
{
	SNode* pNode = m_pBegin;
	SNode* pInsert = NULL;

	pNode = FindNodeData(data);

	if (pNode)
	{
		pInsert = new SNode();
		pInsert->pNext = pNode->pNext;
		pNode->pNext = pInsert;
		pInsert->nData = insert;
	}

	return pInsert;
}

void  CLinkecList::DeleteNodeData(int del)
{
	SNode* pPre = NULL;
	SNode* pNode = m_pBegin;

	//pNode = FindNodeData(m_pBegin, del);
	//pPre = FindNodeData(m_pBegin, 30);

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
			m_pBegin = pNode->pNext;
		delete pNode;
	}
}

void  CLinkecList::PrintLinkedList()
{
	SNode* pNode = m_pBegin;
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

void  CLinkecList::DeleteLinkedList()
{
	SNode* pNode = m_pBegin;
	SNode* pDel = NULL;
	while (pNode)//0x01:T
	{
		pDel = pNode;
		pNode = pNode->pNext;
		printf("Delete:%d\n", pDel->nData);
		delete pDel;
	}
}

void LinkedListSampleTestMain()
{
	CLinkecList cLinkedList;

	//노드 추가 테스트
	cLinkedList.CreateNode(10);
	cLinkedList.CreateNode(20);
	cLinkedList.CreateNode(30);
	cLinkedList.CreateNode(40);
	cLinkedList.CreateNode(50);

	cLinkedList.PrintLinkedList();

	CLinkecList::SNode* pFind = cLinkedList.FindNodeData(60);
	if (pFind != NULL)
		printf("Find:%d\n", pFind->nData);

	CLinkecList::SNode* pInsert = cLinkedList.InsertNodeData(30, 60);//노드 삽입
	if (pInsert != NULL)
		printf("Insert:%d\n", pInsert->nData);

	cLinkedList.PrintLinkedList();
	cLinkedList.DeleteNodeData(60);
	//DeleteNodeData(&pBegin, 10);//노드 삭제

	cLinkedList.PrintLinkedList();

	cLinkedList.DeleteLinkedList(); //모든노드삭제 - 이 함수를 호출하지않을시 메모리가 누수됨.
}