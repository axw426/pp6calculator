###For use with pp6 calculator###


# Requirement for latest generationof CMake
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

# Project Declaration
project(pp6calculator)

# use standard flags when using the GNU compiler
include(CheckCXXCompilerFlag)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
# checking for c++ 11 support and activate if possible
check_cxx_compiler_flag(-std=c++11 HAS_GNUSTYLE_CPP11)
if(HAS_GNUSTYLE_CPP11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")
endif()

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors -Wall -Wextra -Werror -Wfatal-errors -Wwrite-strings -Woverloaded-virtual -fno-nonansi-builtins -fno-gnu-keywords -fstrict-aliasing")
endif()

#add directories to look in
include_directories(PP6Lib)

#Add the PP6Lib library
add_subdirectory(PP6Lib)

#add actual program
add_executable(pp6calculator pp6calculator.cpp)

#Link library to executable
target_link_libraries(pp6calculator pp6lib)

# installs pp6 calculator to the bin directory of CMAKE_INSTALL_PREFIX
install(TARGETS pp6calculator DESTINATION bin)

# package pp6 calculator sources and executable
include(CPack)