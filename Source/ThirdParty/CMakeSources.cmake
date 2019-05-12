set(ThirdParty_Glad_SRC
    "Glad/glad.c")
    
set(ThirdParty_Glad_HEADER
    "Glad/include/glad/glad.h")

set(ThirdParty_Include_Dirs
    ${CMAKE_CURRENT_SOURCE_DIR}/GLFW/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Glad/include
    ${CMAKE_CURRENT_SOURCE_DIR}/FreeType/include
    ${CMAKE_CURRENT_SOURCE_DIR}/KHR
    ${CMAKE_CURRENT_SOURCE_DIR}/STB_Image/include)

set(ThirdParty_SRC
    ${ThirdParty_Glad_SRC}
    ${ThirdParty_Glad_HEADER})