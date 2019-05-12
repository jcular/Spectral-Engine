set(SpectralEngine_Core_Components_SRC
	"Components/Camera.cpp"
	"Components/GameObjectComponent.cpp"
	"Components/Material.cpp"
	"Components/Renderer.cpp" 
	"Components/Transform.cpp"
	"Components/Rotator.cpp"
	"Components/CameraInputHandler.cpp")

set(SpectralEngine_Core_Components_HEADER
	"Components/Camera.h"
	"Components/GameObjectComponent.h"
	"Components/Material.h"
	"Components/Renderer.h"
	"Components/Transform.h"
	"Components/Rotator.h"
	"Components/CameraInputHandler.h")

set(SpectralEngine_Core_Components_Interface_HEADER
	"Components/Interface/IRenderer.h")

set(SpectralEngine_Core_Components_UI_SRC
	"Components/UI/TextRenderer.cpp")

set(SpectralEngine_Core_Components_UI_HEADER
	"Components/UI/TextRenderer.h")

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

set(SpectralEngine_Core_Font_SRC
	"UI/Font/Character.cpp"
	"UI/Font/Font.cpp")

set(SpectralEngine_Core_Font_HEADER
	"UI/Font/Character.h"
	"UI/Font/Font.h")

set(SpectralEngine_Core_NoFilter_SRC
	"Texture.cpp"
	"FileReader.cpp"
	"SpWindow.cpp")

set(SpectralEngine_Core_NoFilter_HEADER
	"Texture.h"
	"FileReader.h"
	"SpWindow.h")

set(SpectralEngine_Core_GameObject_SRC
	"GameObject/GameObject.cpp")

set(SpectralEngine_Core_GameObject_HEADER
	"GameObject/GameObject.h")

set(SpectralEngine_Core_Utility_SRC
	"Utility/VertexData.cpp"
	"Utility/FreeTypeHelper.cpp"
	"Utility/ResourcesPathProvider.cpp")

set(SpectralEngine_Core_Math_SRC
	"Utility/Math/SpMath.cpp"
	"Utility/Math/LinearTransformations.cpp"
	"Utility/Math/Radian.cpp"
	"Utility/Math/Degree.cpp"
	"Utility/Math/Vector3.cpp"
	"Utility/Math/Vector2.cpp"
	"Utility/Math/Quaternion.cpp"
	"Utility/Math/Matrix4x4.cpp")

set(SpectralEngine_Core_Math_HEADER
	"Utility/Math/SpMath.h"
	"Utility/Math/LinearTransformations.h"
	"Utility/Math/Radian.h"
	"Utility/Math/Degree.h"
	"Utility/Math/Vector3.h"
	"Utility/Math/Vector2.h"
	"Utility/Math/Quaternion.h"
	"Utility/Math/Matrix4x4.h")

set(SpectralEngine_Core_Input_SRC
	"Utility/Input/Input.cpp"
	"Utility/Input/KeyInputManager.cpp"
	"Utility/Input/MouseInputManager.cpp")

set(SpectralEngine_Core_Input_HEADER
	"Utility/Input/Input.h"
	"Utility/Input/KeyInputManager.h"
	"Utility/Input/MouseInputManager.h"
	"Utility/Input/KeyCode.h")

set(SpectralEngine_Core_Utility_HEADER
	"Utility/Initializers.h"
	"Utility/Vertices.h"
	"Utility/VertexData.h"
	"Utility/FreeTypeHelper.h"
	"Utility/ResourcesPathProvider.h"
	"Utility/SpString.h")

set (SpectralEngine_Vertex_Shaders_SRC
	"ShaderFiles/vertex_shader.glsl"
	"ShaderFiles/vertex_lighting_shader.glsl"
	"ShaderFiles/vertex_text_shader.glsl")

set (SpectralEngine_Fragment_Shaders_SRC
	"ShaderFiles/fragment_shader.glsl"
	"ShaderFiles/fragment_lighting_shader.glsl"
	"ShaderFiles/fragment_lamp_shader.glsl"
	"ShaderFiles/fragment_text_shader.glsl")
	
set(SpectralEngine_Glad_SRC
	"Glad/glad.c")
	
set(SpectralEngine_Core_Files
	"CMakeSources.cmake"
	"CopyShaderFiles.cmake")

source_group("Source Files\\Components" FILES ${SpectralEngine_Core_Components_SRC})
source_group("Header Files\\Components" FILES ${SpectralEngine_Core_Components_HEADER})
source_group("Header Files\\Components\\Interface" FILES ${SpectralEngine_Core_Components_Interface_HEADER})
source_group("Source Files\\Components\\UI" FILES ${SpectralEngine_Core_Components_UI_SRC})
source_group("Header Files\\Components\\UI" FILES ${SpectralEngine_Core_Components_UI_HEADER})
source_group("Source Files\\Shader" FILES ${SpectralEngine_Core_Shader_SRC})
source_group("Header Files\\Shader" FILES ${SpectralEngine_Core_Shader_HEADER})
source_group("Source Files\\UI\\Font" FILES ${SpectralEngine_Core_Font_SRC})
source_group("Header Files\\UI\\Font" FILES ${SpectralEngine_Core_Font_HEADER})
source_group("Header Files\\GameObject" FILES ${SpectralEngine_Core_GameObject_HEADER})
source_group("Source Files\\GameObject" FILES ${SpectralEngine_Core_GameObject_SRC})
source_group("Source Files\\Utility" FILES ${SpectralEngine_Core_Utility_SRC})
source_group("Header Files\\Utility" FILES ${SpectralEngine_Core_Utility_HEADER})
source_group("Source Files\\Utility\\Math" FILES ${SpectralEngine_Core_Math_SRC})
source_group("Header Files\\Utility\\Math" FILES ${SpectralEngine_Core_Math_HEADER})
source_group("Source Files\\Utility\\Input" FILES ${SpectralEngine_Core_Input_SRC})
source_group("Header Files\\Utility\\Input" FILES ${SpectralEngine_Core_Input_HEADER})
source_group("Shader Files\\Vertex" FILES ${SpectralEngine_Vertex_Shaders_SRC})
source_group("Shader Files\\Fragment" FILES ${SpectralEngine_Fragment_Shaders_SRC})
source_group("Glad" FILES ${SpectralEngine_Glad_SRC})

set(SpectralEngine_Core_SRC
	${SpectralEngine_Core_Components_SRC}
	${SpectralEngine_Core_Components_HEADER}
	${SpectralEngine_Core_Components_Interface_HEADER}
	${SpectralEngine_Core_Components_UI_SRC}
	${SpectralEngine_Core_Components_UI_HEADER}
	${SpectralEngine_Core_Shader_SRC}
	${SpectralEngine_Core_Shader_HEADER}
	${SpectralEngine_Core_Font_SRC}
	${SpectralEngine_Core_Font_HEADER}
	${SpectralEngine_Core_NoFilter_SRC}
	${SpectralEngine_Core_NoFilter_HEADER}
	${SpectralEngine_Core_GameObject_HEADER}
	${SpectralEngine_Core_GameObject_SRC}
	${SpectralEngine_Core_Utility_SRC}
	${SpectralEngine_Core_Utility_HEADER}
	${SpectralEngine_Core_Math_SRC}
	${SpectralEngine_Core_Math_HEADER}
	${SpectralEngine_Core_Input_SRC}
	${SpectralEngine_Core_Input_HEADER}
	${SpectralEngine_Vertex_Shaders_SRC}
	${SpectralEngine_Fragment_Shaders_SRC}
	${SpectralEngine_Glad_SRC}
	${SpectralEngine_Core_Files})