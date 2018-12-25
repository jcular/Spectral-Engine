#pragma once

#include <glad/glad.h>

#include <string>
#include <iostream>

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

