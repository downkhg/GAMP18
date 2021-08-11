#pragma once
#define NULL 0

class State;
class StateOne;
class StateTow;
class ScateThree;

class Context;

class State
{
public:
	virtual ~State() {};
	virtual void GoNext(Context* pContext) = 0;
};

class Context
{
	State* m_pState = NULL;
public:
	~Context();
	void SetState(State* pState);
	void GoNext();
};

class StateOne :public State
{
public:
	StateOne();
	~StateOne();
	void GoNext(Context* pContext) override;
};

class StateTow :public State
{
public:
	StateTow();
	~StateTow();
	void GoNext(Context* pContext) override;
};

class StateThree :public State
{
public:
	StateThree();
	~StateThree();
	void GoNext(Context* pContext) override;
};
