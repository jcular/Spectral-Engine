#pragma once

#include <glad/glad.h>
#include <string>

class ShaderCompilationException {
public:
	ShaderCompilationException(unsigned int const shaderId, GLenum shaderType, char infoLog[512]);

public:
	std::string what();

private:
	unsigned int const shaderId;
	GLenum const shaderType;
	std::string const infoLog;
};

