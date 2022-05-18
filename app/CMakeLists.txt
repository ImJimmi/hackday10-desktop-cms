juce_add_gui_app(desktop-cms-demo
    PRODUCT_NAME "Desktop CMS Demo"
    VERSION 1.0.0
)

find_package(Python3)

execute_process(COMMAND
    ${Python3_EXECUTABLE} -m pip install -r "${CMAKE_CURRENT_SOURCE_DIR}/scripts/requirements.txt"
)
execute_process(COMMAND
    ${Python3_EXECUTABLE} "${CMAKE_CURRENT_SOURCE_DIR}/scripts/pull_resources.py" --access_key=${AWS_ACCESS_KEY} --secret_key=${AWS_SECRET_KEY} --repo_directory=${CMAKE_CURRENT_SOURCE_DIR}
)

juce_add_binary_data(desktop-cms-demo-resources
SOURCES
    resources/forest.jpg
)

target_sources(desktop-cms-demo
PRIVATE
    source/main.cpp
    source/Window.h
)

target_compile_definitions(desktop-cms-demo
PRIVATE
    APP_NAME="$<TARGET_PROPERTY:desktop-cms-demo,JUCE_PRODUCT_NAME>"
    APP_VERSION="$<TARGET_PROPERTY:desktop-cms-demo,JUCE_VERSION>"
)

target_link_libraries(desktop-cms-demo
PRIVATE
    desktop-cms-demo-resources
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
