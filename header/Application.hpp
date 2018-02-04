#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "InputData.hpp"
#include "InputManager.hpp"
#include "Packer.hpp"

class Application
{
private:
	InputData inputData;
	InputManager inputManager;
	Packer packer;

	bool isRunning;
	bool isQuick;
public:
	Application(const Application &app) = delete;
	void operator=(const Application &app) = delete;

	Application(int argc, char **argv);
	~Application();
	void run();
};

#endif //APPLICATION_HPP