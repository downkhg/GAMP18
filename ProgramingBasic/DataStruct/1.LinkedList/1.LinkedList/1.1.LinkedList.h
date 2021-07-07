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

	SNode* CreateNode(int data); //노드를 생성하여 리턴한다.
	SNode* FindNodeData(int data); //해당 데이터를 가진 노드를 찾는다.
	SNode* InsertNodeData(int data, int insert); //해당 데이터를 가진 노드 뒤에 노드를 추가한다.
	void DeleteNodeData(int del); //해당데이터를 가진 노드를 삭제한다.
	void PrintLinkedList(); //노드를 순회하며 끝날때까지 출력한다.
	void DeleteLinkedList(); //노드를 순회하며 모든데이터를 삭제한다.
	void ReverseLinkedList(); //
private:
	SNode* m_pBegin = NULL;
	SNode* m_pEnd = NULL;
};

void LinkedListSampleTestMain();
