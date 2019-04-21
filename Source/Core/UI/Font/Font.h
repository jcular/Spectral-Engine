#pragma once

#include <map>
#include <memory>
#include <Utility/SpString.h>

#include "UI/Font/Character.h"

namespace sp {
	class Font {
	public:
		static std::shared_ptr<Font const> const getFont(SpString const & path);
		void insertCharacter(unsigned char key, Character const & character);
		Character const getCharacter(unsigned char const c) const;

	private:
		Font() = default;

	private:
		std::map<unsigned char, Character const> characterMap;
	};
}
