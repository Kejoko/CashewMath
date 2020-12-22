add_executable(good good.cpp)
add_test(NAME good_test COMMAND good)

add_executable(bad bad.cpp)
add_test(NAME bad_test COMMAND bad)