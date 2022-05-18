juce_add_gui_app(desktop-cms-demo
    PRODUCT_NAME "Desktop CMS Demo"
    VERSION 1.0.0
)

target_sources(desktop-cms-demo
PRIVATE
    source/main.cpp
)

target_compile_definitions(desktop-cms-demo
PRIVATE
    APP_NAME="$<TARGET_PROPERTY:desktop-cms-demo,JUCE_PRODUCT_NAME>"
    APP_VERSION="$<TARGET_PROPERTY:desktop-cms-demo,JUCE_VERSION>"
)

target_link_libraries(desktop-cms-demo
PRIVATE
    juce::juce_gui_basics
)

target_include_directories(desktop-cms-demo
PRIVATE
    source
)

target_compile_features(desktop-cms-demo
PRIVATE
    cxx_std_14
)

target_compile_options(desktop-cms-demo
PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)
