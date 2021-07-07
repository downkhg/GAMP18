#pragma once
#include <stdio.h>

template <typename Type> 
class CLinkecList
{
public:
	struct SNode {
		Type nData;
		SNode* pNext;
	};

	SNode* GetBegin()
	{
		return m_pBegin;
	}
	SNode* GetEnd()
	{
		return m_pEnd;
	}

	SNode* CreateNode(Type data) //��带 �����Ͽ� �����Ѵ�.
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
	SNode* FindNodeData(Type data) //�ش� �����͸� ���� ��带 ã�´�.
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
	SNode* InsertNodeData(Type data, Type insert)
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

 //�ش� �����͸� ���� ��� �ڿ� ��带 �߰��Ѵ�.
	void DeleteNodeData(Type del) //�ش絥���͸� ���� ��带 �����Ѵ�.
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
	void PrintLinkedList() //��带 ��ȸ�ϸ� ���������� ����Ѵ�.
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
	void DeleteLinkedList()//��带 ��ȸ�ϸ� ��絥���͸� �����Ѵ�.
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
	void ReverseLinkedList(); //
private:
	SNode* m_pBegin = NULL;
	SNode* m_pEnd = NULL;
};

void LinkedListSampleTestMain();
