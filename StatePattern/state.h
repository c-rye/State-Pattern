#pragma once
#include <iostream>
#include <typeinfo>

class Engine;

class State {
protected:
	Engine* _engine;

public:
	virtual ~State() {}

	void set_engine(Engine* engine) {
		_engine = engine;
	}

	virtual void doActionA() = 0;
	virtual void doActionB() = 0;

};

class Engine {
private:
	State* _state;

public:
	Engine(State* state) : _state(nullptr) {
		transitionTo(state);
		std::cout << "Engine constructed of type: " << typeid(this).name() << "\n";
	}

	~Engine() { delete _state; }

	// main function for transitioning between states
	void transitionTo(State* state) {
		std::cout << "transitionTo function called...\n";
		// if a state already exists for this engine, delete it
		
		if (_state) delete _state;

		// replace the newly deleted _state variable with the new state
		_state = state;

		// set the engine to the new state
		std::cout << "Calling set_engine...\n";
		_state->set_engine(this);
		std::cout << "set_engine complete.\n";
		std::cout << "Transition successful!\n";
	}

	void requestA() { _state->doActionA(); }
	void requestB() { _state->doActionB(); }
};

// define our first "actual" state we can be in
class ConcreteStateA : public State {
public:

	// define two functions that our state can perform
	void doActionA() override {
		
		std::cout << typeid(this).name() << " called doActionA()\n";
		//_engine->transitionTo(new ConcreteStateA);
	}

	void doActionB() override {
	
		std::cout << typeid(this).name() << " called doActionB()\n";
		//_engine->transitionTo(new ConcreteStateB);
	}
};

// define our second "actual" state we can be in
class ConcreteStateB : public State {
public:

	//define two functions our state can perform
	void doActionA() override {

		// this action will transition us from state B to A
		std::cout << typeid(this).name() << " called doActionA()\n";
		_engine->transitionTo(new ConcreteStateA);
	}

	void doActionB() override {

		std::cout << typeid(this).name() << " called doActionB()\n";
		_engine->transitionTo(new ConcreteStateB);
	}
};
