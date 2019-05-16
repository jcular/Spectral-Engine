set(ThirdParty_Glad_SRC
    "Glad/glad.c")
    
set(ThirdParty_Glad_HEADER
    "Glad/include/glad/glad.h")

source_group("Source Files" ${ThirdParty_Glad_SRC})
source_group("Header Files" ${ThirdParty_Glad_HEADER})

set(ThirdParty_SRC
    ${ThirdParty_Glad_SRC}
    ${ThirdParty_Glad_HEADER})

set(ThirdParty_Include_Dirs
    "GLFW/include"
    "Glad/include"
    "FreeType/include/freetype2"
    "KHR"
    "STB_Image/include")