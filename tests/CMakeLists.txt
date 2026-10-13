# add the test executable
add_executable(run_tests sample_test.cpp)

# link your tests with GoogleTest
target_link_libraries(run_tests PRIVATE GTest::gtest_main) 

# tell CTest to discover individual GoogleTest cases inside the executable
include(GoogleTest)
gtest_discover_tests(run_tests)
