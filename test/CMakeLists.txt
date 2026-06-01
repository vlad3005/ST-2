include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}.test
  AllTests.cpp
  tests.cpp)
target_link_libraries(${PROJECT_NAME}.test
  ${PROJECT_NAME} gtest)
if(UNIX)
  target_link_libraries(${PROJECT_NAME}.test pthread)
endif()
target_compile_definitions(${PROJECT_NAME}.test 
  PRIVATE TEST_DIR="${CMAKE_CURRENT_LIST_DIR}/test")

install(TARGETS ${PROJECT_NAME}.test
        DESTINATION "${tool_dest}")
