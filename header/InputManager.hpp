#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include "InputData.hpp"

class InputManager
{
private:
public:
	InputManager(const InputManager &manager) = delete;
	void operator=(const InputManager &manager) = delete;

	InputManager();

	InputData getData();
	InputData getData(int argc, char **argv);
};

#endif //INPUTMANAGER_HPP