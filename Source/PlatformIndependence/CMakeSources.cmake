set(SpectralEngine_PlatformIndependence_NoFilter_SRC
    "SpWindow.cpp")

set(SpectralEngine_PlatformIndependence_NoFilter_HEADER
    "SpWindow.h"
    "SpString.h")

set(SpectralEngine_Core_Input_SRC
"Utility/Input/Input.cpp"
"Utility/Input/KeyInputManager.cpp"
"Utility/Input/MouseInputManager.cpp")

set(SpectralEngine_Core_Input_HEADER
"Utility/Input/Input.h"
"Utility/Input/KeyInputManager.h"
"Utility/Input/MouseInputManager.h"
"Utility/Input/KeyCode.h")


set(SpectralEngine_Core_SRC
    ${SpectralEngine_PlatformIndependence_NoFilter_SRC}
    ${SpectralEngine_PlatformIndependence_NoFilter_HEADER}
    ${SpectralEngine_Core_Input_SRC}
    ${SpectralEngine_Core_Input_HEADER}
