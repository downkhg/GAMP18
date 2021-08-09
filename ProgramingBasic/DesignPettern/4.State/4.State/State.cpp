#include "State.h"
#include <iostream>

using namespace std;

StateOne::StateOne() { cout << typeid(*this).name() << endl; }
StateOne::~StateOne() { cout << "~" << typeid(*this).name() << endl; }

StateTow::StateTow() { cout << typeid(*this).name() << endl; }
StateTow::~StateTow() { cout << "~" << typeid(*this).name() << endl; }

StateThree::StateThree() { cout << typeid(*this).name() << endl; }
StateThree::~StateThree() { cout << "~" << typeid(*this).name() << endl; }

void Context::SetState(State* pState)
{
	m_pState = pState;
}
void Context::GoNext()
{
	m_pState->GoNext(this);
}

void StateOne::GoNext(Context* pContext)
{
	pContext->SetState(new StateTow);
}

void StateTow::GoNext(Context* pContext)
{
	pContext->SetState(new StateThree);
}

void StateThree::GoNext(Context* pContext)
{
	pContext->SetState(new StateOne);
}