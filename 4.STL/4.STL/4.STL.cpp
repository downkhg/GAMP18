#include <iostream>
//선형자료구조
#include <vector> //동적배열
#include <list> //연결리스트
#include <deque> //앞뒤로 자료가 추가 가능한 자료구조
#include <queue> //뒤에서 넣고 앞에서 뺀다.
#include <stack> //뒤에서 넣고, 뒤어서 뺀다.

#include <set> //집합
#include <map> //해쉬테이블

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
	VectorMain();
}

void VectorMain()
{
	int nSize = 10;
	vector<int> datastruct(nSize);
	datastruct.resize(5);//동적배열은 만든 크기를 중간에 늘리거나 줄일수있다.
	//인덱스를 이용한 접근
	for (int i = 0; i < datastruct.size(); i++)
		datastruct[i] = 10 * nSize - nSize * i;
	for (int i = 0; i < datastruct.size(); i++)
		cout << i << ":"<< datastruct[i] << ",";// cout == printf
	cout << endl;//줄바꿈문자
	//추가
	datastruct.push_back(0);
	datastruct.push_back(-10);
	for (int i = 0; i < datastruct.size(); i++)
		cout << i << ":" << datastruct[i] << ",";// cout == printf
	cout << endl;//줄바꿈문자
	//이터레이터를 이용한 각 원소 접근하기
	vector<int>::iterator it;
	cout << "Result:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	//찾기
	vector<int>::iterator itFind = find(datastruct.begin(), datastruct.end(), 30);
	if (itFind != datastruct.end())
		cout << "Find:" << *itFind << endl;
	//삽입
	vector<int>::iterator itInsert = datastruct.insert(itFind, -20);
	if (itInsert != datastruct.end())
		cout << "Insert:" << *itInsert << endl;
	cout << "InsertResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	//삭제
	datastruct.erase(itInsert);
	cout << "EraseResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	//뒤집기
	reverse(datastruct.begin(), datastruct.end());
	cout << "ReverseResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;
	//모두삭제
	datastruct.clear();
	cout << "ClearResult:";
	for (it = datastruct.begin(); it != datastruct.end(); it++)
		cout << *it << ",";
	cout << endl;	
}
//1.벡터(STL)와 배열의 차이점은?
//2.이터레이터는 포인터와 유사하다 차이점은 무엇인가?
//3.벡터(STL)에서 만약 원하는 데이터를 찾지못한다면 어떤 값이 반환되는가?
//4.벡터(STL)에서 삽입(insert)시 어디에 추가되는가? 그 이유는 무엇인가?
//2.벡터(STL)에 begin()은 연결리스트의 pBegin과 같지만 end()와 pEnd는 다르다 무엇이 다른가?