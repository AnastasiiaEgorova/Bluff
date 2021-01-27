#pragma once
#include "State.h"
#include "StateIdentifiers.h"
#include "ResourceIdentifiers.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

#include <vector>
#include <utility>
#include <functional>
#include <map>

namespace sf {
	class Event;
	class RenderWindow;
}

class StateStack : private sf::NonCopyable
{
public:
	enum class Action {
		Push,
		Pop,
		Clear,
	};

public:
	explicit			StateStack(State::Context context);	
	
	template <typename T>
	void				registerState(StateID stateID);

	void				update(sf::Time dt);
	void				draw();
	void				handleEvent(const sf::Event& event);	
	
	void				pushState(StateID stateID);
	void				popState();
	void				clearStates();	

	bool				isEmpty() const; 

private:
	State::Ptr			createState(StateID stateID);
	void				applyPendingChanges();

private:
	// to avoid race conditions
	struct PendingChange {

		explicit		PendingChange(Action action, StateID stateID = StateID::None);

		Action			action;
		StateID			stateID;
	};

private:
	std::vector<State::Ptr>								stack;
	std::vector<PendingChange>							pendingList;

	State::Context										context;
	std::map<StateID, std::function<State::Ptr()>>		factories;  // map for stateID, state
};

// factory function for states
// T is for state
template <typename T>
void StateStack::registerState(StateID stateID)
{
	factories[stateID] = [this]()
	{
		// returns pointer to instance of state
		return State::Ptr(new T(*this, context));
	};
}

