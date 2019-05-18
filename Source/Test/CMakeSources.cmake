set(SpectralEngine_Test_Main
    "main.cpp")

set(SpectralEngine_Test_Core_Utility_Math_Source
    "Core/Utility/Math/DegreeTest.cpp"
    "Core/Utility/Math/LinearTransformationsTest.cpp"
    "Core/Utility/Math/Matrix4x4Test.cpp"
    "Core/Utility/Math/QuaternionTest.cpp"
    "Core/Utility/Math/RadianTest.cpp"
    "Core/Utility/Math/DegreeTest.cpp"
    "Core/Utility/Math/Vector3Test.cpp"
    "Core/Utility/Math/Vector2Test.cpp")

set(SpectralEngine_Test_Files
    "CMakeSources.cmake")

source_group("Core\\Utility\\Math" FILES ${SpectralEngine_Test_Core_Utility_Math_Source})

set(SpectralEngine_Test_SRC
    ${SpectralEngine_Test_Main}
    ${SpectralEngine_Test_Core_Utility_Math_Source}
    ${SpectralEngine_Test_Files})