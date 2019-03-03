#include <ft2build.h>
#include FT_FREETYPE_H
#include <iostream>

#include "GLFW/glfw3.h"
#include "UI/Font/Font.h"
#include "UI/Font/Character.h"
#include "Utility/FreeTypeHelper.h"

std::shared_ptr<sp::Font const> const sp::Font::getFont(std::string const & path) {
	FT_Face face;
	if (createFace(path, face)) {
		return nullptr;
	}

	std::shared_ptr<Font> font = std::shared_ptr<Font>(new Font);
	loadFontCharacters(*font, face);

	return font;
}

void sp::Font::insertCharacter(unsigned char key, Character const & character) {
	std::pair<unsigned char, Character const> const pair{ key, character };
	this->characterMap.insert(pair);
}
