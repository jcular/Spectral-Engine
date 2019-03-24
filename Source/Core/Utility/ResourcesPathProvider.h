#pragma once

#include <string>

namespace sp {
	class ResourcesPathProvider {
	public:
		static std::string const & getResourcesDirectoryPath();
		static std::string const & getShaderFilesDirectoryPath();
		static void initializePaths(std::string const & rootPath);

	private:
		static std::string resourcesDirectoryPath;
		static std::string shaderFilesDirectoryPath;

	private:
		ResourcesPathProvider() = delete;

	};
}