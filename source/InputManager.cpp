#include "InputManager.hpp"
#include <iostream>

InputManager::InputManager()
{
}


InputData InputManager::getData()
{
	InputData data;

	std::string inputStr;
	std::getline(std::cin, inputStr);

	unsigned int i;
	//command reading
	for(i = 0; i < inputStr.length() && inputStr[i] != '(' && inputStr[i] != ' '; ++i)
		data.command += inputStr[i];

	//mainArgument reading
	if(inputStr[i] == '(')
		for(++i; i < inputStr.length() && inputStr[i] != ')'; ++i)
			data.mainArgument += inputStr[i];

	//subArgument reading
	std::string tmp;
	for(i += inputStr[i] == ')' ? 2 : 1; i < inputStr.length(); ++i)
	{
		if(inputStr[i] != ' ')
			tmp += inputStr[i];

		if(inputStr[i] == ' ' || i+1 >= inputStr.length())
			data.subArguments.push_back(std::move(tmp));
	}

	return data;
}

InputData InputManager::getData(int argc, char **argv)
{
	InputData data;

	std::string tmpCommand(argv[0]);
	unsigned int i;
	for(i = 0; i < tmpCommand.length() && tmpCommand[i] != '(' && tmpCommand[i] != ' '; ++i)
		data.command += tmpCommand[i];

	if(tmpCommand[i] == '(')
		for(++i; i < tmpCommand.length() && tmpCommand[i] != ')'; ++i)
			data.mainArgument += tmpCommand[i];

	for(int j = 1; j < argc; ++j)
		data.subArguments.push_back(argv[j]);
	return data;
}