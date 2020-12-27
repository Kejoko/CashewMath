# =====
# Uint128_t
# =====
add_executable(uint128_t uint128_t.cpp)
target_link_libraries(uint128_t CashewMath)
add_test(NAME uint128_t_test COMMAND uint128_t)