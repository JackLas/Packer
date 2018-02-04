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
	std::cout << "--Done" << std::endl;
}

void Packer::extract(const std::string &inputFileName)
{
	std::ifstream input(inputFileName, std::ios::binary);
	if(!input.is_open())
	{
		std::cout << "~Error. File " << inputFileName << "not found" << std::endl;
		return; 
	}

	while(true)
	{
		size_t fileNameSize;
		if(!input.read((byte*)&fileNameSize, sizeof(size_t)))
			break; // loop exit

		char tmp;
		std::string fileName;
		for(unsigned int i = 0; i < fileNameSize; ++i)
		{
			input.read((byte*)&tmp, sizeof(byte));
			fileName += tmp;
		}

		size_t fileSize;
		input.read((byte*)&fileSize, sizeof(size_t));

		std::ofstream file(fileName, std::ios::binary);
		for(unsigned int i = 0; i < fileSize; ++i)
		{
			input.read((byte*)&tmp, sizeof(byte));
			file.write((byte*)&tmp, sizeof(byte));
		}
		std::cout << "--File '" << fileName << "' was extracted" << std::endl;
	}
	input.close();
	std::cout << "--Done" << std::endl;
}

void Packer::inside(const std::string &inputFileName)
{
	std::ifstream input(inputFileName, std::ios::binary);
	if(!input.is_open())
	{
		std::cout << "~Error. File '" << inputFileName << "' not found" << std::endl;
		return;
	}

	while(true)
	{
		size_t fileNameSize;
		if(!input.read((byte*)&fileNameSize, sizeof(size_t)))
			break; //loop exit

		char buffer;
		std::string fileName;
		for(unsigned int i = 0; i < fileNameSize; ++i)
		{
			input.read((byte*)&buffer, sizeof(char));
			fileName += buffer;
		}

		size_t fileSize;
		input.read((byte*)&fileSize, sizeof(size_t));
		input.seekg(fileSize, std::ios::cur);

		std::cout << "'" << fileName << "' (" << fileSize << "b)" << std::endl;
	}	
	input.close();
	std::cout << "--Done" << std::endl;
}