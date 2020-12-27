# =====
# Generator
# =====
add_executable(generator generator.cpp)
target_link_libraries(generator CashewMath)
add_test(NAME generator_test COMMAND generator)