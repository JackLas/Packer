#include "Packer.hpp"
#include "iostream"

Packer::Packer()
{
}

void Packer::run(const InputData &data)
{
	if(data.command == "-pack")
		pack(data.mainArgument, data.subArguments);
	else if(data.command == "-extract")
		extract(data.mainArgument);
	else if(data.command == "-inside")
		inside(data.mainArgument);
	else if(data.command == "-extend")
		extend(data.mainArgument, data.subArguments);
	else std::cout << "Command " << data.command << " not found " << std::endl;
}

void Packer::pack(const std::string &outputFileName, const std::vector<std::string> &files)
{

}

void Packer::extract(const std::string &filename)
{

}

void Packer::inside(const std::string &filename)
{

}

void Packer::extend(const std::string &filename, const std::vector<std::string> &files)
{

}