#include "FileReader.h"

namespace sp {
	std::string const FileReader::ReadFromFile(std::string const path) throw (char *) {
		std::ifstream inputFileStream(path);

		if (!inputFileStream) {
			throw "File could not be open.";
		}

		return std::string(std::istreambuf_iterator<char>(inputFileStream), std::istreambuf_iterator<char>());
	}
}
