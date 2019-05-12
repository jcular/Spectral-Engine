#pragma once

#include "PlatformIndependence/SpString.h"

namespace sp {
	class ShaderProgramLinkingException {
	public:
		ShaderProgramLinkingException(unsigned int const programId, char const infoLog[]);
		SpString what();

	private:
		unsigned int const programId;
		SpString const infoLog;
	};
}
