add_executable(output output.cpp)
target_link_libraries(output CashewMath)
add_test(NAME output_test COMMAND output)