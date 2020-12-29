# =====
# BracketOperator
# =====
add_executable(BracketOperator BracketOperator.cpp)
target_link_libraries(BracketOperator CashewMath)
add_test(NAME BracketOperator_test COMMAND BracketOperator)