# =====
# Memory
# =====
add_executable(memory memory.cpp)
target_link_libraries(memory CashewMath)
add_test(NAME memory_test COMMAND memory)


# =====
# Output
# =====
add_executable(output output.cpp)
target_link_libraries(output CashewMath)
add_test(NAME output_test COMMAND output)