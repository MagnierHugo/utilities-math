include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.14.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(tests test_math.cpp test_common.cpp)

target_link_libraries(tests PRIVATE
    math
    Catch2::Catch2WithMain   # gives you a main() for free
)

# Auto-discover and register all TEST_CASE blocks with CTest
list(APPEND CMAKE_MODULE_PATH /extras)
include(Catch)
catch_discover_tests(tests)
