#include "Shader.h"
#include "FileReader.h"
#include "Shader/ShaderCompilationException.h"

Shader::Shader(std::string const & filePath, GLenum const type) : type{ type } {
	this->id = glCreateShader(this->type);

	std::string shaderText = FileReader::ReadFromFile(filePath);
	char const * const shaderSourceCstring = shaderText.c_str();

	glShaderSource(this->id, 1, &shaderSourceCstring, NULL);
	glCompileShader(this->id);

	int success;
	glGetShaderiv(this->id, GL_COMPILE_STATUS, &success);

	if (!success) {
		char infoLog[512];
		glGetShaderInfoLog(this->id, sizeof(infoLog), NULL, infoLog);
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
