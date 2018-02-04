#include "Application.hpp"
#include "iostream"

Application::Application(int argc, char **argv):
isRunning(true), 
isQuick(false)
{
	--argc; ++argv;
	if(argc >= 1 && argv[0][0] == '-')
	{
		inputData = inputManager.getData(argc, argv);
		isQuick = true;
	}
}

Application::~Application()
{
}

void Application::run()
{
	if(isQuick)
	{
		packer.run(inputData);
	}
	else while(isRunning)
	{
		inputData = inputManager.getData();

		if(inputData.command == "-exit")
			isRunning = false;
		else if(inputData.command == "-help")
			std::cout << "help" << std::endl;
		else packer.run(inputData);

		inputData.reset();
	}
}