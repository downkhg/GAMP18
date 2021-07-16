#include "1.1.LinkedList.h"
#include <stdio.h>



void LinkedListSampleTestMain()
{
	CLinkecList<int> cLinkedList;

	//��� �߰� �׽�Ʈ
	cLinkedList.CreateNode(10);
	cLinkedList.CreateNode(20);
	cLinkedList.CreateNode(30);
	cLinkedList.CreateNode(40);
	cLinkedList.CreateNode(50);

	printf("Begin:%d\n",cLinkedList.GetBegin()->nData);
	printf("End:%d\n",cLinkedList.GetEnd()->nData);

	cLinkedList.PrintLinkedList();

	CLinkecList<int>::SNode* pFind = cLinkedList.FindNodeData(60);
	if (pFind != NULL)
		printf("Find:%d\n", pFind->nData);

	CLinkecList<int>::SNode* pInsert = cLinkedList.InsertNodeData(30, 60);//��� ����
	if (pInsert != NULL)
		printf("Insert:%d\n", pInsert->nData);

	cLinkedList.PrintLinkedList();
	cLinkedList.DeleteNodeData(60);
	//DeleteNodeData(&pBegin, 10);//��� ����

	cLinkedList.PrintLinkedList();

	cLinkedList.DeleteLinkedList(); //�������� - �� �Լ��� ȣ������������ �޸𸮰� ������.
}