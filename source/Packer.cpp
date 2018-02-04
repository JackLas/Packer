#include "Packer.hpp"
#include <fstream>
#include "iostream"

typedef char byte;

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
	if(files.size() == 0)
	{
		std::cout << "~Error. No files" << std::endl;
		return;
	}

	std::ofstream output(outputFileName, std::ios::binary);
	if(!output.is_open())
	{
		std::cout << "~Error. Can't create file" << std::endl;
		return;
	}

	for(auto currentFile: files)
	{
		std::ifstream file(currentFile, std::ios::binary);
		if(!file.is_open())
		{
			std::cout << "~Error. File '" << currentFile << "' not found" << std::endl;
			continue;
		}

		file.seekg(0, std::ios::end);
		size_t fileSize = file.tellg();
		file.seekg(0, std::ios::beg);

		size_t fileNameSize = currentFile.size();
		//file name size writing
		output.write((byte*)&fileNameSize, sizeof(size_t));

		//file name writting
		for(unsigned int i = 0; i < currentFile.size(); ++i)
			output.write((byte*)&currentFile.c_str()[i], sizeof(byte));

		//file size writting
		output.write((byte*)&fileSize, sizeof(size_t));

		//file writting
		char tmp;
		while(true)
		{
			if(file.read((byte*)&tmp, sizeof(byte)))
				output.write((byte*)&tmp, sizeof(byte));
			else break;
		}
		std::cout << "--File '" << currentFile << "' was packed" << std::endl;
	}
	output.close();
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