set(ThirdParty_Glad_SRC
    "Glad/glad.c")
    
set(ThirdParty_Glad_HEADER
    "Glad/include/glad/glad.h")

set(ThirdParty_Include_Dirs
    "GLFW/include"
    "Glad/include"
    "FreeType/include"
    "KHR"
    "STB_Image/include")

set(ThirdParty_SRC
    ${ThirdParty_Glad_SRC}
    ${ThirdParty_Glad_HEADER})