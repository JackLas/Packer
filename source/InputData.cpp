#include "InputData.hpp"
#include <iostream>

InputData::InputData(const InputData &data)
{
	command = data.command;
	mainArgument = data.mainArgument;
	for(auto argument: data.subArguments)
		subArguments.push_back(argument);
}

void InputData::operator=(const InputData &data)
{
	command = data.command;
	mainArgument = data.mainArgument;
	for(auto argument: data.subArguments)
		subArguments.push_back(argument);
}

InputData::InputData()
{
}

InputData::~InputData()
{

}

void InputData::reset()
{
	command.clear();
	mainArgument.clear();
	subArguments.clear();
}

void InputData::print()
{
	std::cout << "cmd: '" << command << "'" << std::endl;
	std::cout << "m_arg: '" << mainArgument << "'" << std::endl;
	std::cout << "s_arg(" << subArguments.size() << "): " << std::endl;
	for(auto argument: subArguments)
		std::cout << "'" << argument << "'" << std::endl;
}