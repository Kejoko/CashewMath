# =====
# AdditionOperators
# =====
add_executable(AdditionOperators AdditionOperators.cpp)
target_link_libraries(AdditionOperators CashewMath)
add_test(NAME AdditionOperators_test COMMAND AdditionOperators)

# =====
# BracketOperators
# =====
add_executable(BracketOperators BracketOperators.cpp)
target_link_libraries(BracketOperators CashewMath)
add_test(NAME BracketOperators_test COMMAND BracketOperators)

# =====
# ComparisonOperators
# =====
add_executable(ComparisonOperators ComparisonOperators.cpp)
target_link_libraries(ComparisonOperators CashewMath)
add_test(NAME ComparisonOperators_test COMMAND ComparisonOperators)