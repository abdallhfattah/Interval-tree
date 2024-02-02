cmake_minimum_required(VERSION 3.8)

set(test for IntervalTree)


add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
gtest_main
interval_tree
)


add_test(
	NAME ${This}
	COMMAND ${This}
)