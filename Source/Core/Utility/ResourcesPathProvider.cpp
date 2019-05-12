#include "ResourcesPathProvider.h"


SpString sp::ResourcesPathProvider::resourcesDirectoryPath;
SpString sp::ResourcesPathProvider::shaderFilesDirectoryPath;

SpString const & sp::ResourcesPathProvider::getResourcesDirectoryPath() {
	return resourcesDirectoryPath;
}

SpString const & sp::ResourcesPathProvider::getShaderFilesDirectoryPath() {
	return shaderFilesDirectoryPath;
}

void sp::ResourcesPathProvider::initializePaths(SpString const & rootPath) {
	resourcesDirectoryPath = rootPath + SpString{ "/../../../Resources/Resources" };
	shaderFilesDirectoryPath = rootPath + SpString{ "/../../../Source/Render/ShaderFiles" };
}
