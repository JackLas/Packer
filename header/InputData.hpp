#ifndef INPUTDATA_HPP
#define INPUTDATA_HPP

#include <string>
#include <vector>

class InputData
{
public:
	std::string command;
	std::string mainArgument;
	std::vector<std::string> subArguments;
public:
	InputData(const InputData &data);
	void operator=(const InputData &data);

	InputData();
	~InputData();

	void reset();
	void print();
};

#endif //INPUT_HPP