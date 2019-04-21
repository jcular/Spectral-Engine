#include <sstream>

#include "Shader/ShaderCompilationException.h"

namespace sp {
	ShaderCompilationException::ShaderCompilationException(unsigned int const shaderId, GLenum shaderType, char infoLog[512])
		: shaderId{ shaderId }, shaderType{ shaderType }, infoLog{ SpString{infoLog} } {
	}

	SpString ShaderCompilationException::what() {
		std::stringstream ss;
		ss << "Error: shader with id: " << shaderId << ", type: " << shaderType << " failed to compile." << std::endl << infoLog;
		return ss.str();
	}
}
