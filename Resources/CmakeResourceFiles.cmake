set(OxygEngine_ResourceFiles_Art
	"Art/awesomeface.png"
	"Art/wall.png"
	"Art/wall.jpg")

set(OxygEngine_ResourceFiles_Shaders
	"Shaders/fragment_shader.txt"
	"Shaders/vertex_lighting_shader.txt"
	"Shaders/vertex_shader.txt")

set(OxygEngine_ResourceFiles
	${OxygEngine_ResourceFiles_Art}
	${OxygEngine_ResourceFiles_Shader})

source_group("Art" FILES ${OxygEngine_ResourceFiles_Art})
source_group("Shaders" FILES ${OxygEngine_ResourceFiles_Shaders})
