#pragma once
#define NULL 0



class CLinkecList
{
public:
	struct SNode {
		int nData;
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

	SNode* CreateNode(int data); //��带 �����Ͽ� �����Ѵ�.
	SNode* FindNodeData(int data); //�ش� �����͸� ���� ��带 ã�´�.
	SNode* InsertNodeData(int data, int insert); //�ش� �����͸� ���� ��� �ڿ� ��带 �߰��Ѵ�.
	void DeleteNodeData(int del); //�ش絥���͸� ���� ��带 �����Ѵ�.
	void PrintLinkedList(); //��带 ��ȸ�ϸ� ���������� ����Ѵ�.
	void DeleteLinkedList(); //��带 ��ȸ�ϸ� ��絥���͸� �����Ѵ�.
	void ReverseLinkedList(); //
private:
	SNode* m_pBegin = NULL;
	SNode* m_pEnd = NULL;
};

void LinkedListSampleTestMain();
