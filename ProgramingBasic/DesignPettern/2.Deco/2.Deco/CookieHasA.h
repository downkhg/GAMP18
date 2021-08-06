#pragma once
#include <iostream>

using namespace std;

namespace HasA
{
	class Cookie
	{
		int m_nFlour;
		int m_nSugar;
	public:
		Cookie(int flour = 0, int sugar = 0)
		{
			cout << "Cookie:" << this << endl;
			m_nFlour = flour;
			m_nSugar = sugar;
		}
		~Cookie()
		{
			cout << "~Cookie:" << this << endl;
		}
	};

	class MilkCookie
	{
		Cookie cCookie;
		int m_nMilk;
	public:
		MilkCookie(int flour, int sugar, int milk)
		{
			cCookie = Cookie(flour, sugar);
			cout << "MilkCookie:" << this << endl;
			m_nMilk = milk;
		}
		~MilkCookie()
		{
			cout << "~MilkCookie:" << this << endl;
		}
	};

	class ChocoCookie
	{
		Cookie m_cCookie;
		int m_nChoco;
	public:
		ChocoCookie(int flour = 0, int sugar = 0, int choco = 0)
		{
			m_cCookie = Cookie(flour, sugar);
			cout << "ChocoCookie:" << this << endl;
			m_nChoco = choco;
		}
		~ChocoCookie()
		{
			cout << "~ChocoCookie:" << this << endl;
		}
	};

	class AmondChocoCookie
	{
		ChocoCookie m_cChocoCookie;
		int m_nAmond;
	public:
		AmondChocoCookie(int flour, int sugar, int choco, int amond) 
		{
			m_cChocoCookie = ChocoCookie(flour, sugar, choco);
			cout << "AmondChocoCookie:" << this << endl;
			m_nAmond = amond;
		}
		~AmondChocoCookie()
		{
			cout << "~AmondChocoCookie:" << this << endl;
		}
	};
}