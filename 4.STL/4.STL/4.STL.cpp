#include <iostream>
//�����ڷᱸ��
#include <vector> //�����迭
#include <list> //���Ḯ��Ʈ
#include <deque> //�յڷ� �ڷᰡ �߰� ������ �ڷᱸ��
#include <queue> //�ڿ��� �ְ� �տ��� ����.
#include <stack> //�ڿ��� �ְ�, �ھ ����.

#include <set> //����
#include <map> //��
#include <unordered_map> //�ؽ����̺�

using namespace std;

void VectorMain();
void ListMain();
void DequeMain();
void QueueMain();
void StackMain();

void SetMain();
void MapMain();
void HashMapMain();
void PriorityQueueMain();//�ִ밪���� ���´�.

void main()
{
	//Vector2Main();
	//VectorMain();
	//ListMain();
	//DequeMain();
	//QueueMain();
	//StackMain();
	//SetMain();
	//MapMain();
	PriorityQueueMain();
}

void VectorMain()
{
	int nSize = 10;
	vector<int> datastruct(nSize);
	
	//�迭���ʱ�ȭ
	for (int i = 0; i < datastruct.size(); i++)
		datastruct[i] = 10 * nSize - nSize * i; //10 * 10 - 10 * 0 = 100
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
	//�̵�: ���������� - ���ͷ����͸� �������� ���� ���ٰ����ϴ�.
	vector<int>::iterator itMove = datastruct.begin();
	if (itMove != datastruct.end())
		cout << "itMove(begin):" << *itMove << endl;
	itMove++;
	if (itMove != datastruct.end())
		cout << "itMove(begin next):" << *itMove << endl;
	itMove--;
	if (itMove != datastruct.end())
		cout << "itMove(begin next prev):" << *itMove << endl;
	itMove += 4;
	if (itMove != datastruct.end())
		cout << "itMove(+4):" << *itMove << endl;
	itMove = datastruct.begin() + 4;
	if (itMove != datastruct.end())
		cout << "itMove(begin()+4):" << *itMove << endl;
	itMove = --datastruct.end();
	if (itMove != datastruct.end())
		cout << "itMove(end()--):" << *itMove << endl;
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
	list<int>::iterator it;
	//�ʱ�ȭ
	int i = 0;
	for (it = datastruct.begin(); it != datastruct.end(); it++)
	{
		*it = 10 * nSize - nSize * i; i++;
	}
	//�ε����� �̿��� ���
	cout << "Init:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	datastruct.resize(5);//�����迭�� ���� ũ�⸦ �߰��� �ø��ų� ���ϼ��ִ�.
	cout << "resizeResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	//�߰�
	datastruct.push_back(0);
	datastruct.push_front(-10);
	cout << "PushResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;//�ٹٲ޹���
	//�̵�: ���߿��Ḯ��Ʈ�̹Ƿ�, �������� �̵��Ҷ��� ++ ���� --
	list<int>::iterator itMove = datastruct.begin();
	if (itMove != datastruct.end())
		cout << "itMove(begin):" << *itMove << endl;
	itMove++;
	if (itMove != datastruct.end())
		cout << "itMove(begin next):" << *itMove << endl;
	itMove++;
	if (itMove != datastruct.end())
		cout << "itMove(begin next next):" << *itMove << endl;
	itMove--;
	if (itMove != datastruct.end())
		cout << "itMove(begin next next prev):" << *itMove << endl;
	//���ͷ����͸� �̿��� �� ���� �����ϱ�
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
	if (datastruct.empty())//if (datastruct.end() == datastruct.begin())
		cout << "List is all clear!" << endl;
}
void DequeMain()
{
	int nSize = 10;
	deque<int> datastruct(nSize);

	//�迭���ʱ�ȭ
	for (int i = 0; i < datastruct.size(); i++)
		datastruct[i] = 10 * nSize - nSize * i; //10 * 10 - 10 * 0 = 100
	//�ε����� �̿��� ���
	cout << "print:";
	for (int i = 0; i < datastruct.size(); i++)
		cout << i << ":" << datastruct[i] << ",";// cout == printf
	cout << endl;//�ٹٲ޹���
	datastruct.resize(5);//�����迭�� ���� ũ�⸦ �߰��� �ø��ų� ���ϼ��ִ�.
	cout << "resize:";
	for (int i = 0; i < datastruct.size(); i++)
		cout << i << ":" << datastruct[i] << ",";// cout == printf
	cout << endl;//�ٹٲ޹���
	//�߰�
	datastruct.push_back(0);
	datastruct.push_back(-10);
	datastruct.push_front(-30);
	for (int i = 0; i < datastruct.size(); i++)
		cout << i << ":" << datastruct[i] << ",";// cout == printf
	cout << endl;//�ٹٲ޹���
	//�̵�: ���������� - ���ͷ����͸� �������� ���� ���ٰ����ϴ�.
	deque<int>::iterator itMove = datastruct.begin();
	if (itMove != datastruct.end())
		cout << "itMove(begin):" << *itMove << endl;
	itMove++;
	if (itMove != datastruct.end())
		cout << "itMove(begin next):" << *itMove << endl;
	itMove--;
	if (itMove != datastruct.end())
		cout << "itMove(begin next prev):" << *itMove << endl;
	itMove += 4;
	if (itMove != datastruct.end())
		cout << "itMove(+4):" << *itMove << endl;
	itMove = datastruct.begin() + 4;
	if (itMove != datastruct.end())
		cout << "itMove(begin()+4):" << *itMove << endl;
	itMove = --datastruct.end();
	if (itMove != datastruct.end())
		cout << "itMove(end()--):" << *itMove << endl;
	//���ͷ����͸� �̿��� �� ���� �����ϱ�
	deque<int>::iterator it;
	cout << "Result:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	//ã��
	deque<int>::iterator itFind = find(datastruct.begin(), datastruct.end(), 70);
	if (itFind != datastruct.end())
		cout << "Find:" << *itFind << endl;
	//����
	deque<int>::iterator itInsert = datastruct.insert(itFind, -20);
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
	if (datastruct.empty())//if (datastruct.end() == datastruct.begin())
		cout << "List is all clear!" << endl;
}
void QueueMain()
{
	queue<int> que;

	que.push(10);
	que.push(20);
	que.push(30);
	que.push(40);
	que.push(50);
	cout << "front:" << que.front() << endl;
	cout << "back: "<< que.back() << endl;

	que.pop();
	cout << "front:" << que.front() << endl;
	cout << "back: " << que.back() << endl;

	while (true)
	{
		cout << "front:" << que.front() << endl;
		que.pop();
		if (que.empty()) break;
	}
}
void StcakMain()
{

}
void SetMain()
{
	set<int> datastruct;
	datastruct.insert(10);
	datastruct.insert(20);
	datastruct.insert(30);

	set<int>::iterator it;
	it = datastruct.find(10);
	cout <<"find:"<< *it << endl;

	for (it = datastruct.begin(); it != datastruct.end(); it++)
	{
		cout << *it << endl;
	}
}
void MapMain()
{
	map<string, int> datastruct;

	datastruct["zero"] = 0;
	datastruct["one"] = 1;
	datastruct["two"] = 2;

	map<string, int>::iterator it;
	it = datastruct.find("zero");
	cout << "find:" << it->first <<"/"<< it->second << endl;

	for (it = datastruct.begin(); it != datastruct.end(); it++)
	{
		cout << it->first << ":"<< it->second << endl;
	}
}
void HashMapMain()
{
	unordered_map<string, int> datastruct;

	datastruct["zero"] = 0;
	datastruct["one"] = 1;
	datastruct["two"] = 2;

	unordered_map<string, int>::iterator it;
	it = datastruct.find("zero");
	cout << "find:" << it->first << "/" << it->second << endl;

	for (it = datastruct.begin(); it != datastruct.end(); it++)
	{
		cout << it->first << ":" << it->second << endl;
	}
}
void PriorityQueueMain()
{
	priority_queue<int> que;
	que.push(10);
	que.push(20);
	que.push(30);
	que.push(40);
	que.push(50);
	cout << "top:" << que.top()<< endl;

	while (true)
	{
		cout << "top:" << que.top() << endl;
		que.pop();
		if (que.empty()) break;
	}
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
