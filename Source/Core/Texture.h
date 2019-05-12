#pragma once

#include <glad/glad.h>
#include <iostream>
#include <PlatformIndependence/SpString.h>

namespace sp {
	class Texture {
	public:
		Texture(SpString const & path, bool const genMipmap, GLenum format);
		~Texture();
		unsigned int const getId() const;

	private:
		unsigned int id;
		int width;
		int height;
		int nrChannel;
	};
}
