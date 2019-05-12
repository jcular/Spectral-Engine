set(SpectralEngine_PlatformIndependence_NoFilter_SRC
    "SpWindow.cpp")

set(SpectralEngine_PlatformIndependence_NoFilter_HEADER
    "SpWindow.h"
    "SpString.h")

set(SpectralEngine_Core_Input_SRC
    "Input/Input.cpp"
    "Input/KeyInputManager.cpp"
    "Input/MouseInputManager.cpp")

set(SpectralEngine_Core_Input_HEADER
    "Input/Input.h"
    "Input/KeyInputManager.h"
    "Input/MouseInputManager.h"
    "Input/KeyCode.h")


set(SpectralEngine_Core_SRC
    ${SpectralEngine_PlatformIndependence_NoFilter_SRC}
    ${SpectralEngine_PlatformIndependence_NoFilter_HEADER}
    ${SpectralEngine_Core_Input_SRC}
    ${SpectralEngine_Core_Input_HEADER})
