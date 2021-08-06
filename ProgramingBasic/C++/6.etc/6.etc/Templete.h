#pragma once

#include <iostream>
#include <stack>

using namespace std;

template<typename Type>
void Swap(Type& a, Type& b)
{
	Type temp = a;
	a = b;
	b = temp;
}
//���ø�: ���������� ����� ���� ó���Ҽ��ֵ��� �Ϲ�ȭ �ϴ°�.
void FunctionTempletMain()
{
	int nDataA = 10;
	int nDataB = 20;
	float fDataA = 3.14f;
	float fDataB = 0.1f;
	printf("Origin(int):%d/%d\n", nDataA, nDataB);
	Swap(nDataA, nDataB);
	printf("Swap(int):%d/%d\n", nDataA, nDataB);
	printf("Origin(float):%f/%f\n", fDataA, fDataB);
	Swap(fDataA, fDataB);
	printf("Swap(float):%f/%f\n", fDataA, fDataB);
}
template<typename Type>
class Box
{
	Type data;
public:
	void SetData(Type data) { this->data = data; }
	Type GetData() { return data; }
	void Display()
	{
		cout << typeid(*this).name() << "(" << typeid(data).name() << "):" << data << endl;
	}
};
//���÷��� Ÿ���� ���� �ٸ�Ÿ���� ������ �����Ҽ��ִ�.
template <typename TypeKey, typename TypeData>
class MapData
{
	TypeKey key;
	TypeData data;
public:
	MapData(TypeKey key, TypeData data)
	{
		this->key = key;
		this->data = data;
	}
	TypeData operator[](TypeKey) { return data; }
};
void TempletClassMain()
{
	//Ŭ���� ������ ������ Ÿ���� �ܺο��� �����Ҽ��ֵ��� ����°�.
	Box<int> box;
	box.SetData(10);
	box.Display();

	MapData<std::string, float> data("Pi", 3.14f);
	cout << data["Pi"] << endl;
}
//STL�����
//����: �ڿ��� �߰��ǰ� �ڿ��� ����.
//����Լ����� ���� �Լ��� ȣ���Ҷ����� ���ÿ� ����.
//���ڿ������� -> ���ڹ迭 -> apple -> elppa
void StackMain()
{
	char strApple[] = "apple";
	char strRevApple[6] = {};
	stack<char> stackReverse;

	for (int i = 0; strApple[i] != '\0'; i++)
		stackReverse.push(strApple[i]);
	int idx = 0;
	while (true)
	{
		strRevApple[idx] = stackReverse.top();
		stackReverse.pop();
		idx++;
		if (stackReverse.empty()) break;
	}

	cout << "Origin:" << strApple << endl;
	cout << "Reverse:" << strRevApple << endl;
}

namespace Mokeup
{
	template<typename DataType>
	class stack
	{
		DataType array[128] = {};
		int nTopIdx = -1;
	public:
		void push(DataType data)
		{
			nTopIdx++;
			array[nTopIdx] = data;
			//cout << "push[" << nTopIdx << "]:" << array[nTopIdx] << endl;
		}
		DataType top()
		{
			//cout << "top[" << nTopIdx <<"]:"<< array[nTopIdx]<< endl;
			return array[nTopIdx];
		}
		void pop()
		{
			array[nTopIdx] = 0;
			nTopIdx--;
			//cout << "pop(" << nTopIdx << ")"  << endl;
		}
		bool empty()
		{
			if (nTopIdx < 0)
				return true;
			return false;
		}
	};

	void StackMain()
	{
		char strApple[] = "apple";
		char strRevApple[6] = {};
		stack<char> stackReverse;

		for (int i = 0; strApple[i] != '\0'; i++)
			stackReverse.push(strApple[i]);
		int idx = 0;
		while (true)
		{
			strRevApple[idx] = stackReverse.top();
			stackReverse.pop();
			idx++;
			if (stackReverse.empty()) break;
		}

		cout << "Origin:" << strApple << endl;
		cout << "Reverse:" << strRevApple << endl;
	}
}

//void main()
//{
//	FunctionTempletMain();
//	//TempletClassMain();
//	//Mokeup::StackMain();
//}