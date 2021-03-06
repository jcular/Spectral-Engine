set(SpectralEngine_PlatformIndependence_NoFilter_SRC
    "SpWindow.cpp")

set(SpectralEngine_PlatformIndependence_NoFilter_HEADER
    "SpWindow.h"
    "SpString.h")

set(SpectralEngine_PlatformIndependence_Input_SRC
    "Input/Input.cpp"
    "Input/KeyInputManager.cpp"
    "Input/MouseInputManager.cpp")

set(SpectralEngine_PlatformIndependence_Input_HEADER
    "Input/Input.h"
    "Input/KeyInputManager.h"
    "Input/MouseInputManager.h"
    "Input/KeyCode.h")

source_group("Source Files" ${SpectralEngine_PlatformIndependence_NoFilter_SRC})
source_group("Header Files" ${SpectralEngine_PlatformIndependence_NoFilter_HEADER})
source_group("Source Files\\Input" ${SpectralEngine_PlatformIndependence_Input_SRC})
source_group("Header Files\\Input" ${SpectralEngine_PlatformIndependence_Input_HEADER})

set(SpectralEngine_PlatformIndependence_SRC
    ${SpectralEngine_PlatformIndependence_NoFilter_SRC}
    ${SpectralEngine_PlatformIndependence_NoFilter_HEADER}
    ${SpectralEngine_PlatformIndependence_Input_SRC}
    ${SpectralEngine_PlatformIndependence_Input_HEADER})
