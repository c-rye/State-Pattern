# include "state.h"

int main() {
	Engine engine1(new ConcreteStateB);
	engine1.requestA();
	engine1.requestA();

}