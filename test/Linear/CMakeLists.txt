# =====
# ArithmeticOperators
# =====
add_executable(ArithmeticOperators ArithmeticOperators.cpp)
target_link_libraries(ArithmeticOperators CashewMath)
add_test(NAME ArithmeticOperators_test COMMAND ArithmeticOperators)

# =====
# BracketOperator
# =====
add_executable(BracketOperator BracketOperator.cpp)
target_link_libraries(BracketOperator CashewMath)
add_test(NAME BracketOperator_test COMMAND BracketOperator)

# =====
# ComparisonOperators
# =====
add_executable(ComparisonOperators ComparisonOperators.cpp)
target_link_libraries(ComparisonOperators CashewMath)
add_test(NAME ComparisonOperators_test COMMAND ComparisonOperators)