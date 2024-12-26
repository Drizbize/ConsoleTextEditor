# CMakeList.txt : CMake project for TextEditor, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (TextEditor "SETTINGS.h" "Utils/ConsoleColors.h" "Utils/Vector2.h" "Utils/Direction.h" "Console/Console_Char.h" "Console/Console.h" "Console/Console.cpp" "main.cpp" "Utils/ConsoleColors.cpp" "Console/Console_Char.cpp")

include_directories(${CMAKE_SOURCE_DIR}/TextEditor)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TextEditor PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
