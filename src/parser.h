#pragma once

#include <iostream>
#include <fstream>

class Parser
{
public:
	Parser(std::string path);
	~Parser();
private:
	std::string path;
	std::ifstream file;
};
