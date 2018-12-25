set(OxygEngine_Core_Components_SRC
	"Core/Components/Camera.cpp"
	"Core/Components/GameObjectComponent.cpp"
	"Core/Components/Material.cpp"
	"Core/Components/Renderer.cpp" 
	"Core/Components/Transform")

set(OxygEngine_Core_Components_HEADER
	"Core/Components/Camera.h"
	"Core/Components/GameObjectComponent.h"
	"Core/Components/Material.h"
	"Core/Components/Renderer.h"
	"Core/Components/Transform")

set(OxygEngine_Core_Shader_SRC
	"Core/Shader/ShaderCompilationException.cpp"
	"Core/Shader/ShaderProgramLinkingException.cpp"
	"Core/Shader/Shader.cpp"
	"Core/Shader/ShaderProgram.cpp")

set(OxygEngine_Core_Shader_HEADER
	"Core/Shader/ShaderCompilationException.h"
	"Core/Shader/ShaderProgramLinkingException.h"
	"Core/Shader/Shader.h"
	"Core/Shader/ShaderProgram.h")

set(OxygEngine_Core_NoFilter_SRC
	"Core/Texture.cpp"
	"Core/FileReader.cpp")

set(OxygEngine_Core_NoFilter_HEADER
	"Core/Texture.h"
	"Core/FileReader.h")

set(OxygEngine_Core_GameObject_SRC
	"Core/GameObject/GameObject.cpp")

set(OxygEngine_Core_GameObject_HEADER
	"Core/GameObject/GameObject.h")

set(OxygEngine_Libraries_SRC
	"Libraries/source/glad/glad.c")

set(OxygEngine_Core_Utility_SRC
	"Core/Utility/CameraInputHandler.cpp")

set(OxygEngine_Core_Utility_HEADER
	"Core/Utility/Initializers.h"
	"Core/Utility/Vertices.h"
	"Core/Utility/CameraInputHandler.h")
	
set(OxygEngine_Core_Files
	"Core/CMakeSources.cmake")

source_group("Source Files\\Components" FILES ${OxygEngine_Core_Components_SRC})
source_group("Header Files\\Components" FILES ${OxygEngine_Core_Components_HEADER})
source_group("Source Files\\Shader" FILES ${OxygEngine_Core_Shader_SRC})
source_group("Header Files\\Shader" FILES ${OxygEngine_Core_Shader_HEADER})
source_group("Header Files\\GameObject" FILES ${OxygEngine_Core_GameObject_HEADER})
source_group("Source Files\\GameObject" FILES ${OxygEngine_Core_GameObject_SRC})
source_group("Source Files\\Utility" FILES ${OxygEngine_Core_Utility_SRC})
source_group("Header Files\\Utility" FILES ${OxygEngine_Core_Utility_HEADER})

set(OxygEngine_Core_SRC
	${OxygEngine_Core_Components_SRC}
	${OxygEngine_Core_Components_HEADER}
	${OxygEngine_Core_Shader_SRC}
	${OxygEngine_Core_Shader_HEADER}
	${OxygEngine_Core_NoFilter_SRC}
	${OxygEngine_Core_NoFilter_HEADER}
	${OxygEngine_Core_GameObject_HEADER}
	${OxygEngine_Core_GameObject_SRC}
	${OxygEngine_Core_Utility_SRC}
	${OxygEngine_Core_Utility_HEADER}
	${OxygEngine_Core_Files})