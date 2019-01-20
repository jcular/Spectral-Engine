#pragma once

#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

namespace sp {
	class FileReader {
	public:
		static std::string const ReadFromFile(std::string const path);
	};
}
