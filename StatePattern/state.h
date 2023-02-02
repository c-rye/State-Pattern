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
	}

	~Engine() { delete _state; }

	void transitionTo(State* state) {
		if (_state) delete _state;

		_state = state;
		_state->set_engine(this);
	}

	void requestA() { _state->doActionA(); }
	void requestB() { _state->doActionB(); }
};

class ConcreteStateA : public State {
public:
	void doActionA() override {
		
		std::cout << typeid(this).name() << " called doActionA()\n";
		//_engine->transitionTo(new ConcreteStateA);
	}

	void doActionB() override {
	
		std::cout << typeid(this).name() << " called doActionB()\n";
		
	}
};

class ConcreteStateB : public State {
public:
	void doActionA() override {

		std::cout << typeid(this).name() << " called doActionA()\n";
		_engine->transitionTo(new ConcreteStateA);
	}

	void doActionB() override {

		std::cout << typeid(this).name() << " called doActionB()\n";

	}
};
