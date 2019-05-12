file(GLOB shaders "${CMAKE_CURRENT_SOURCE_DIR}/ShaderFiles/*")
message(status Copy shaders)
foreach(shader ${shaders})
    message(status "From ${shader}")
    get_filename_component(outputFileName ${shader} NAME)
    message(status "To ${CMAKE_CURRENT_BINARY_DIR}/ShaderFiles/${outputFileName}")
    configure_file(${shader} ${CMAKE_CURRENT_BINARY_DIR}/ShaderFiles/${outputFileName} COPYONLY)
endforeach()