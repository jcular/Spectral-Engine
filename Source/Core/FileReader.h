#pragma once

#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

class FileReader {
public:
	static std::string const ReadFromFile(std::string const path);
};

