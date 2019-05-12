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

set(SpectralEngine_Core_Components_UI_SRC
"Components/UI/TextRenderer.cpp")

set(SpectralEngine_Core_Components_UI_HEADER
"Components/UI/TextRenderer.h")

set(SpectralEngine_Core_Components_Interface_HEADER
	"Components/Interface/IRenderer.h")

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
	"Utility/ResourcesPathProvider.cpp")

set(SpectralEngine_Core_Math_SRC
	"Math/SpMath.cpp"
	"Math/LinearTransformations.cpp"
	"Math/Radian.cpp"
	"Math/Degree.cpp"
	"Math/Vector3.cpp"
	"Math/Vector2.cpp"
	"Math/Quaternion.cpp"
	"Math/Matrix4x4.cpp")

set(SpectralEngine_Core_Math_HEADER
	"Math/SpMath.h"
	"Math/LinearTransformations.h"
	"Math/Radian.h"
	"Math/Degree.h"
	"Math/Vector3.h"
	"Math/Vector2.h"
	"Math/Quaternion.h"
	"Math/Matrix4x4.h")

set(SpectralEngine_Core_Utility_HEADER
	"Utility/Initializers.h"
	"Utility/Vertices.h"
	"Utility/ResourcesPathProvider.h"
	"Utility/SpString.h")
	
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
source_group("Header Files\\GameObject" FILES ${SpectralEngine_Core_GameObject_HEADER})
source_group("Source Files\\GameObject" FILES ${SpectralEngine_Core_GameObject_SRC})
source_group("Source Files\\Utility" FILES ${SpectralEngine_Core_Utility_SRC})
source_group("Header Files\\Utility" FILES ${SpectralEngine_Core_Utility_HEADER})
source_group("Source Files\\Utility\\Math" FILES ${SpectralEngine_Core_Math_SRC})
source_group("Header Files\\Utility\\Math" FILES ${SpectralEngine_Core_Math_HEADER})
source_group("Source Files\\Utility\\Input" FILES ${SpectralEngine_Core_Input_SRC})
source_group("Header Files\\Utility\\Input" FILES ${SpectralEngine_Core_Input_HEADER})
source_group("Glad" FILES ${SpectralEngine_Glad_SRC})

set(SpectralEngine_Core_SRC
	${SpectralEngine_Core_Components_SRC}
	${SpectralEngine_Core_Components_HEADER}
	${SpectralEngine_Core_Components_Interface_HEADER}
	${SpectralEngine_Core_Components_UI_SRC}
	${SpectralEngine_Core_Components_UI_HEADER}
	${SpectralEngine_Core_NoFilter_SRC}
	${SpectralEngine_Core_NoFilter_HEADER}
	${SpectralEngine_Core_GameObject_HEADER}
	${SpectralEngine_Core_GameObject_SRC}
	${SpectralEngine_Core_Utility_SRC}
	${SpectralEngine_Core_Utility_HEADER}
	${SpectralEngine_Core_Math_SRC}
	${SpectralEngine_Core_Math_HEADER}
	${SpectralEngine_Glad_SRC}
	${SpectralEngine_Core_Files})