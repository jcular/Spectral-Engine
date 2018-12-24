#pragma once

#include <sstream>
#include <string>

class ShaderProgramLinkingException {
public:
	ShaderProgramLinkingException(unsigned int const programId, char const infoLog[]);
	std::string what();

private:
	unsigned int const programId;
	std::string const infoLog;
};

