set(SpectralEngine_Core_Components_SRC
	"Components/Camera.cpp"
	"Components/GameObjectComponent.cpp"
	"Components/Material.cpp"
	"Components/Renderer.cpp" 
	"Components/Transform.cpp"
	"Components/Light.cpp"
	"Components/Rotator.cpp")

set(SpectralEngine_Core_Components_HEADER
	"Components/Camera.h"
	"Components/GameObjectComponent.h"
	"Components/Material.h"
	"Components/Renderer.h"
	"Components/Transform.h"
	"Components/Light.h"
	"Components/Rotator.h")

set(SpectralEngine_Core_Shader_SRC
	"Shader/ShaderCompilationException.cpp"
	"Shader/ShaderProgramLinkingException.cpp"
	"Shader/Shader.cpp"
	"Shader/ShaderProgram.cpp")

set(SpectralEngine_Core_Shader_HEADER
	"Shader/ShaderCompilationException.h"
	"Shader/ShaderProgramLinkingException.h"
	"Shader/Shader.h"
	"Shader/ShaderProgram.h")

set(SpectralEngine_Core_NoFilter_SRC
	"Texture.cpp"
	"FileReader.cpp")

set(SpectralEngine_Core_NoFilter_HEADER
	"Texture.h"
	"FileReader.h")

set(SpectralEngine_Core_GameObject_SRC
	"GameObject/GameObject.cpp")

set(SpectralEngine_Core_GameObject_HEADER
	"GameObject/GameObject.h")

set(SpectralEngine_Core_Utility_SRC
	"Utility/CameraInputHandler.cpp"
	"Utility/VertexData.cpp")

set(SpectralEngine_Core_Utility_HEADER
	"Utility/Initializers.h"
	"Utility/Vertices.h"
	"Utility/CameraInputHandler.h"
	"Utility/VertexData.h")

set (SpectralEngine_Vertex_Shaders_SRC
	"ShaderFiles/vertex_shader.txt"
	"ShaderFiles/vertex_lighting_shader.txt")

set (SpectralEngine_Fragment_Shaders_SRC
	"ShaderFiles/fragment_shader.txt"
	"ShaderFiles/fragment_lighting_shader.txt"
	"ShaderFiles/fragment_lamp_shader.txt")

	
set(SpectralEngine_Core_Files
	"CMakeSources.cmake")

source_group("Source Files\\Components" FILES ${SpectralEngine_Core_Components_SRC})
source_group("Header Files\\Components" FILES ${SpectralEngine_Core_Components_HEADER})
source_group("Source Files\\Shader" FILES ${SpectralEngine_Core_Shader_SRC})
source_group("Header Files\\Shader" FILES ${SpectralEngine_Core_Shader_HEADER})
source_group("Header Files\\GameObject" FILES ${SpectralEngine_Core_GameObject_HEADER})
source_group("Source Files\\GameObject" FILES ${SpectralEngine_Core_GameObject_SRC})
source_group("Source Files\\Utility" FILES ${SpectralEngine_Core_Utility_SRC})
source_group("Header Files\\Utility" FILES ${SpectralEngine_Core_Utility_HEADER})
source_group("Shader Files\\Vertex" FILES ${SpectralEngine_Vertex_Shaders_SRC})
source_group("Shader Files\\Fragment" FILES ${SpectralEngine_Fragment_Shaders_SRC})

set(SpectralEngine_Core_SRC
	${SpectralEngine_Core_Components_SRC}
	${SpectralEngine_Core_Components_HEADER}
	${SpectralEngine_Core_Shader_SRC}
	${SpectralEngine_Core_Shader_HEADER}
	${SpectralEngine_Core_NoFilter_SRC}
	${SpectralEngine_Core_NoFilter_HEADER}
	${SpectralEngine_Core_GameObject_HEADER}
	${SpectralEngine_Core_GameObject_SRC}
	${SpectralEngine_Core_Utility_SRC}
	${SpectralEngine_Core_Utility_HEADER}
	${SpectralEngine_Vertex_Shaders_SRC}
	${SpectralEngine_Fragment_Shaders_SRC}
	${SpectralEngine_Core_Files})