#include <iostream>

#include "FileReader.h"
#include "Shader/Shader.h"
#include "Shader/ShaderCompilationException.h"

namespace sp {
	Shader::Shader(SpString const & filePath, GLenum const type) : type{ type } {
		this->id = glCreateShader(this->type);

		SpString shaderText = FileReader::ReadFromFile(filePath);
		char const * const shaderSourceCstring = shaderText.c_str();

		glShaderSource(this->id, 1, &shaderSourceCstring, NULL);
		glCompileShader(this->id);

		int success;
		glGetShaderiv(this->id, GL_COMPILE_STATUS, &success);

		if (!success) {
			char infoLog[512];
			glGetShaderInfoLog(this->id, sizeof(infoLog), NULL, infoLog);
			std::cout << infoLog;
			throw ShaderCompilationException{ this->id, this->type, infoLog };
		}
	}


	Shader::~Shader() {
	}

	unsigned int Shader::getId() {
		return this->id;
	}

	GLenum Shader::getType() {
		return this->type;
	}
}
