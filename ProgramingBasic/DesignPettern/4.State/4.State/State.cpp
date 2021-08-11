#include "State.h"
#include <iostream>

using namespace std;

//State::~State() { cout << "~" <<typeid(*this).name() << endl; }

StateOne::StateOne() { cout << typeid(*this).name() << endl; }
StateOne::~StateOne() { cout << "~" << typeid(*this).name() << endl; }

StateTow::StateTow() { cout << typeid(*this).name() << endl; }
StateTow::~StateTow() { cout << "~" << typeid(*this).name() << endl; }

StateThree::StateThree() { cout << typeid(*this).name() << endl; }
StateThree::~StateThree() { cout << "~" << typeid(*this).name() << endl; }

Context::~Context()
{
	if (m_pState)
		delete m_pState;
}

void Context::SetState(State* pState)
{
	if (m_pState) delete m_pState;
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