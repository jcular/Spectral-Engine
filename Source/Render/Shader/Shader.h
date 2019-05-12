#pragma once

#include <glad/glad.h>
#include <iostream>
#include "PlatformIndependence/SpString.h"

namespace sp {
	class Shader {
	public:
		Shader(SpString const & filePath, GLenum const);
		~Shader();
	
	public:
		unsigned int getId();
		GLenum getType();

	private:
		unsigned int id;
		GLenum type;
	};
}
