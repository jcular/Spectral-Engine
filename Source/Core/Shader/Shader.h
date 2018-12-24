#pragma once

#include <glad/glad.h>

#include <string>
#include <iostream>

#include "Core/FileReader.h"
#include "Core/Shader/ShaderCompilationException.h"

class Shader {
public:
	Shader(std::string const & filePath, GLenum const);
	~Shader();
	
public:
	unsigned int getId();
	GLenum getType();

private:
	unsigned int id;
	GLenum type;
};

