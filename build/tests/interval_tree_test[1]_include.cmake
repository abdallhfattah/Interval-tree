if(EXISTS "/home/abdallh/Desktop/Third year/ds/Assignments/2/Assign2_AdvancedDataStructures/build/tests/interval_tree_test[1]_tests.cmake")
  include("/home/abdallh/Desktop/Third year/ds/Assignments/2/Assign2_AdvancedDataStructures/build/tests/interval_tree_test[1]_tests.cmake")
else()
  add_test(interval_tree_test_NOT_BUILT interval_tree_test_NOT_BUILT)
endif()
