#pragma once

#include <ThirdParty/Glad/include/glad/glad.h>
#include <PlatformIndependence/SpString.h>

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
