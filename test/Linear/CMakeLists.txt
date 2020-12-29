# =====
# Memory
# =====
add_executable(memory memory.cpp)
target_link_libraries(memory CashewMath)
add_test(NAME memory_test COMMAND memory)


# =====
# Getter/Setter/Output
# =====
add_executable(get_set_output get_set_output.cpp)
target_link_libraries(get_set_output CashewMath)
add_test(NAME get_set_output_test COMMAND get_set_output)