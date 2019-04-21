#pragma once

#include <Utility/SpString.h>
#include <fstream>
#include <streambuf>
#include <sstream>

namespace sp {
	class FileReader {
	public:
		static SpString const ReadFromFile(SpString const path);
	};
}
