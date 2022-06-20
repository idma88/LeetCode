cmake_minimum_required(VERSION 3.9)

project(LeetCode_0004
    VERSION 1.0.0
    LANGUAGES CXX
)

################################################################################
# Sources
################################################################################
file(GLOB src_cpp *.cpp)
file(GLOB src_h *.h)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/../Test/Main.cpp ${src_cpp} ${src_h})

target_include_directories(${PROJECT_NAME} PRIVATE
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_BINARY_DIR}

  ${PROJECT_SOURCE_DIR}/../Test
)
target_link_libraries(${PROJECT_NAME} 
  PRIVATE
    GTest::gtest
    GTest::gtest_main
)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})