set(OxygEngine_Core_Components_SRC
	"Components/Camera.cpp"
	"Components/GameObjectComponent.cpp"
	"Components/Material.cpp"
	"Components/Renderer.cpp" 
	"Components/Transform")

set(OxygEngine_Core_Components_HEADER
	"Components/Camera.h"
	"Components/GameObjectComponent.h"
	"Components/Material.h"
	"Components/Renderer.h"
	"Components/Transform")

set(OxygEngine_Core_Shader_SRC
	"Shader/ShaderCompilationException.cpp"
	"Shader/ShaderProgramLinkingException.cpp"
	"Shader/Shader.cpp"
	"Shader/ShaderProgram.cpp")

set(OxygEngine_Core_Shader_HEADER
	"Shader/ShaderCompilationException.h"
	"Shader/ShaderProgramLinkingException.h"
	"Shader/Shader.h"
	"Shader/ShaderProgram.h")

set(OxygEngine_Core_NoFilter_SRC
	"Texture.cpp"
	"FileReader.cpp")

set(OxygEngine_Core_NoFilter_HEADER
	"Texture.h"
	"FileReader.h")

set(OxygEngine_Core_GameObject_SRC
	"GameObject/GameObject.cpp")

set(OxygEngine_Core_GameObject_HEADER
	"GameObject/GameObject.h")

set(OxygEngine_Core_Utility_SRC
	"Utility/CameraInputHandler.cpp")

set(OxygEngine_Core_Utility_HEADER
	"Utility/Initializers.h"
	"Utility/Vertices.h"
	"Utility/CameraInputHandler.h")

set (OxygEngine_Vertex_Shaders_SRC
	"ShaderFiles/vertex_shader.txt"
	"ShaderFiles/vertex_lighting_shader.txt")

set (OxygEngine_Fragment_Shaders_SRC
	"ShaderFiles/fragment_shader.txt"
	"ShaderFiles/fragment_lighting_shader.txt")

	
set(OxygEngine_Core_Files
	"CMakeSources.cmake")

source_group("Source Files\\Components" FILES ${OxygEngine_Core_Components_SRC})
source_group("Header Files\\Components" FILES ${OxygEngine_Core_Components_HEADER})
source_group("Source Files\\Shader" FILES ${OxygEngine_Core_Shader_SRC})
source_group("Header Files\\Shader" FILES ${OxygEngine_Core_Shader_HEADER})
source_group("Header Files\\GameObject" FILES ${OxygEngine_Core_GameObject_HEADER})
source_group("Source Files\\GameObject" FILES ${OxygEngine_Core_GameObject_SRC})
source_group("Source Files\\Utility" FILES ${OxygEngine_Core_Utility_SRC})
source_group("Header Files\\Utility" FILES ${OxygEngine_Core_Utility_HEADER})
source_group("Shader Files\\Vertex" FILES ${OxygEngine_Vertex_Shaders_SRC})
source_group("Shader Files\\Fragment" FILES ${OxygEngine_Fragment_Shaders_SRC})

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
	${OxygEngine_Vertex_Shaders_SRC}
	${OxygEngine_Fragment_Shaders_SRC}
	${OxygEngine_Core_Files})