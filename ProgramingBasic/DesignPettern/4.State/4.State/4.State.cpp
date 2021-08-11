#include "State.h"
#include <iostream>

using namespace std;

void main()
{
	Context cContext;

	cContext.SetState(new StateOne());
	cContext.GoNext();
	cContext.GoNext();
	cContext.GoNext();
	cContext.GoNext();
	cContext.GoNext();
}