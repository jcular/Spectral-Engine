#include "ResourcesPathProvider.h"


std::string sp::ResourcesPathProvider::resourcesDirectoryPath;
std::string sp::ResourcesPathProvider::shaderFilesDirectoryPath;

std::string const & sp::ResourcesPathProvider::getResourcesDirectoryPath() {
	return resourcesDirectoryPath;
}

std::string const & sp::ResourcesPathProvider::getShaderFilesDirectoryPath() {
	return shaderFilesDirectoryPath;
}

void sp::ResourcesPathProvider::initializePaths(std::string const & rootPath) {
	resourcesDirectoryPath = rootPath + std::string{ "/../../../Resources/Resources" };
	shaderFilesDirectoryPath = rootPath + std::string{ "/../../../Source/Core/ShaderFiles" };
}
