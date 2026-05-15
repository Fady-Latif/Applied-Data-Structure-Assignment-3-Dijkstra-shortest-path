project(Google_tests)

add_executable(Google_Tests_run Testcases.cpp)

# Link the library and GoogleTest targets built via add_subdirectory
target_link_libraries(Google_Tests_run
        PRIVATE
        Code_library
        gtest
        gtest_main
)
