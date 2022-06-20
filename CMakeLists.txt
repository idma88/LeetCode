cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)

if(WIN32 AND DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

project(LeetCode
    VERSION 1.0.0
    LANGUAGES CXX
)

enable_testing()

################################################################################
# Library
################################################################################
find_package(GTest REQUIRED)

if(NOT GTEST_FOUND)
    message(FATAL_ERROR "GTest NOT found!")
endif()

add_subdirectory("0001")
add_subdirectory("0002")
add_subdirectory("0003")