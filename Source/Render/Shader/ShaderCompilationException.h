#pragma once

#include <glad/glad.h>
#include <Utility/SpString.h>

namespace sp {
	class ShaderCompilationException {
	public:
		ShaderCompilationException(unsigned int const shaderId, GLenum shaderType, char infoLog[512]);

	public:
		SpString what();

	private:
		unsigned int const shaderId;
		GLenum const shaderType;
		SpString const infoLog;
	};
}
