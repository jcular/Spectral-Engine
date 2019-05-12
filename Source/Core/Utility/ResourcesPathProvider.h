#pragma once

#include <PlatformIndependence/SpString.h>

namespace sp {
	class ResourcesPathProvider {
	public:
		static SpString const & getResourcesDirectoryPath();
		static SpString const & getShaderFilesDirectoryPath();
		static void initializePaths(SpString const & rootPath);

	private:
		static SpString resourcesDirectoryPath;
		static SpString shaderFilesDirectoryPath;

	private:
		ResourcesPathProvider() = delete;
	};
}