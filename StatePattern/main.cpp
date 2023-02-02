# include "state.h"

int main() {

	// create an engine object that is in the given state
	Engine engine1(new ConcreteStateB);

	// request that our engine perform function A and transition to state A
	engine1.requestA();

	// at this point, the engine should already be in state A, but will still execute function A
	engine1.requestA();

	
}