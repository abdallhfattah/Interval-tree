if(BUILD_TESTING)
	add_executable(interval_tree_test interval_tree_test.cpp)
	target_link_libraries(interval_tree_test PRIVATE GTest::gtest_main)
	# target_include_directories(interval_tree_test )
	target_include_directories(interval_tree_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src)  # Include the directory containing IntervalTree.hpp

	include(GoogleTest)
	gtest_discover_tests(interval_tree_test)
endif()