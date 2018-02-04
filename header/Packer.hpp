#ifndef PACKER_HPP
#define PACKER_HPP

#include "InputData.hpp"
#include <string>
#include <vector>

class Packer
{
private:
public:
	Packer(const Packer &packer) = delete;
	void operator=(const Packer &packer) = delete;

	Packer();
	void run(const InputData &data);

private:
	void pack(const std::string &outputFileName, const std::vector<std::string> &files);
	void extract(const std::string &inputFileName);
	void inside(const std::string &fileName);
};

#endif //PACKER_HPP