#include <iostream>
//�����ڷᱸ��
#include <vector> //�����迭
#include <list> //���Ḯ��Ʈ
#include <deque> //�յڷ� �ڷᰡ �߰� ������ �ڷᱸ��
#include <queue> //�ڿ��� �ְ� �տ��� ����.
#include <stack> //�ڿ��� �ְ�, �ھ ����.

#include <set> //����
#include <map> //�ؽ����̺�

using namespace std;

void VectorMain();
void ListMain();
void DequeMain();
void QueueMain();
void StackMain();

void SetMain();
void MapMain();

void main()
{
	//Vector2Main();
	VectorMain();
}

void VectorMain()
{
	int nSize = 10;
	vector<int> datastruct(nSize);
	
	//�迭���ʱ�ȭ
	for (int i = 0; i < datastruct.size(); i++)
		datastruct[i] = 10 * nSize - nSize * i;
	//�ε����� �̿��� ���
	cout << "print:";
	for (int i = 0; i < datastruct.size(); i++)
		cout << i << ":" << datastruct[i] << ",";// cout == printf
	cout << endl;//�ٹٲ޹���
	datastruct.resize(5);//�����迭�� ���� ũ�⸦ �߰��� �ø��ų� ���ϼ��ִ�.
	cout << "resize:";
	for (int i = 0; i < datastruct.size(); i++)
		cout << i << ":"<< datastruct[i] << ",";// cout == printf
	cout << endl;//�ٹٲ޹���
	//�߰�
	datastruct.push_back(0);
	datastruct.push_back(-10);
	for (int i = 0; i < datastruct.size(); i++)
		cout << i << ":" << datastruct[i] << ",";// cout == printf
	cout << endl;//�ٹٲ޹���
	//���ͷ����͸� �̿��� �� ���� �����ϱ�
	vector<int>::iterator it;
	cout << "Result:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	//ã��
	vector<int>::iterator itFind = find(datastruct.begin(), datastruct.end(), 70);
	if (itFind != datastruct.end())
		cout << "Find:" << *itFind << endl;
	//����
	vector<int>::iterator itInsert = datastruct.insert(itFind, -20);
	if (itInsert != datastruct.end())
		cout << "Insert:" << *itInsert << endl;
	cout << "InsertResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	//����
	datastruct.erase(itInsert);
	cout << "EraseResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	//������
	reverse(datastruct.begin(), datastruct.end());
	cout << "ReverseResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	//��λ���
	datastruct.clear();
	cout << "ClearResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;	
	if(datastruct.empty())//if (datastruct.end() == datastruct.begin())
		cout << "List is all clear!" << endl;
}
//���Ϳ� �����Ͽ� ����Ʈ�� Ư¡�� �����ϸ� �������� �κ� �����ϰų� �߰��ɸ��Ѻκ� ã�ƺ���
void ListMain()
{
	int nSize = 10;
	list<int> datastruct(nSize);

	////�迭���ʱ�ȭ
	//for (int i = 0; i < datastruct.size(); i++)
	//	datastruct[i] = 10 * nSize - nSize * i;
	////�ε����� �̿��� ���
	//cout << "print:";
	//for (int i = 0; i < datastruct.size(); i++)
	//	cout << i << ":" << datastruct[i] << ",";// cout == printf
	//cout << endl;//�ٹٲ޹���
	//datastruct.resize(5);//�����迭�� ���� ũ�⸦ �߰��� �ø��ų� ���ϼ��ִ�.
	//cout << "resize:";
	//for (int i = 0; i < datastruct.size(); i++)
	//	cout << i << ":" << datastruct[i] << ",";// cout == printf
	//cout << endl;//�ٹٲ޹���
	//�߰�
	datastruct.push_back(0);
	datastruct.push_front(-10);
	list<int>::iterator it;
	cout << "Result:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	cout << endl;//�ٹٲ޹���
	//���ͷ����͸� �̿��� �� ���� �����ϱ�
	list<int>::iterator it;
	cout << "Result:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	//ã��
	list<int>::iterator itFind = find(datastruct.begin(), datastruct.end(), 70);
	if (itFind != datastruct.end())
		cout << "Find:" << *itFind << endl;
	//����
	list<int>::iterator itInsert = datastruct.insert(itFind, -20);
	if (itInsert != datastruct.end())
		cout << "Insert:" << *itInsert << endl;
	cout << "InsertResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	//����
	datastruct.erase(itInsert);
	cout << "EraseResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	//������
	reverse(datastruct.begin(), datastruct.end());
	cout << "ReverseResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	//��λ���
	datastruct.clear();
	cout << "ClearResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
}
//1.����(STL)�� �迭�� ��������?
//2.���ͷ����ʹ� �����Ϳ� �����ϴ� �������� �����ΰ�?
//3.����(STL)���� ���� ���ϴ� �����͸� ã�����Ѵٸ� � ���� ��ȯ�Ǵ°�?
//4.����(STL)���� ����(insert)�� ��� �߰��Ǵ°�? �� ������ �����ΰ�?
//2.����(STL)�� begin()�� ���Ḯ��Ʈ�� pBegin�� ������ end()�� pEnd�� �ٸ��� ������ �ٸ���?
void Vector2Main() //const ���� ������� �ʾƵ� �����Ҵ��� �������� �ۿ�
{
	int nSize = 10; //ũ�� ����
	vector<int> datastruct(nSize); //������ ũ�� ���
	datastruct.resize(5);
	//�ε����� �̿��� ����

	for (int i = 0; i < datastruct.size(); i++)
	{
		datastruct[i] = 10 * nSize - nSize * i;
	}
	for (int i = 0; i < datastruct.size(); i++) //datastruct.size(datastruct �� ������ ũ�⸦ ������)
	{
		cout << i << ":" << datastruct[i] << ", "; //cout == printf
	}
	cout << endl; //�� �ٲ� ���� = \n �� ����

	//�����͸� �߰� �ϴ� ���
	datastruct.push_back(0);//������ 0 �߰�
	datastruct.push_back(-10);//������ -10 �߰�
	for (int i = 0; i < datastruct.size(); i++)
	{
		cout << i << ":" << datastruct[i] << ", ";
	}
	cout << endl;

	//���ͷ����͸� �̿��� �� ���� �����ϱ�
	vector<int>::iterator it = datastruct.begin();
	cout << "Result:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl;

	//�����͸� ã�� ���
	vector<int>::iterator itFind = find(datastruct.begin(), datastruct.end(), 90);
	if (itFind != datastruct.end())
		cout << "Find:" << *itFind << endl;

	//�����͸� �����ϴ� ���
	vector<int>::iterator itInsert = datastruct.insert(itFind, -20);
	if (itInsert != datastruct.end())
		cout << "insert:" << *itInsert << endl;
	cout << "InsertResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl;

	//�����͸� �����ϴ� ���
	datastruct.erase(itInsert);
	cout << "eraseResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl;

	//�����͸� ������ ���
	reverse(datastruct.begin(), datastruct.end());
	cout << "ReverseResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++);
	{
		cout << *it << ",";
	}
	cout << endl;

	//�����͸� ��� �����ϴ� ���
	datastruct.clear();
	cout << "ClearResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl;
}
