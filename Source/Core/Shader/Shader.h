#pragma once

#include <glad/glad.h>
#include <iostream>
#include <string>

namespace sp {
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
}
