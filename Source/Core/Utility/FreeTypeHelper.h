#pragma once

#include <string>
#include <ft2build.h>
#include FT_FREETYPE_H

#define DEFAULT_FONT_SIZE 48

namespace sp {
	class Font;

	int createFace(std::string const & path, FT_Face & face);
	void loadFontCharacters(Font & font, FT_Face const & face);
}
