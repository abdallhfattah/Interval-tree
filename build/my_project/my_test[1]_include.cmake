if(EXISTS "/home/abdallh/Desktop/Third year/ds/Assignments/2/Assign2_AdvancedDataStructures/build/my_project/my_test[1]_tests.cmake")
  include("/home/abdallh/Desktop/Third year/ds/Assignments/2/Assign2_AdvancedDataStructures/build/my_project/my_test[1]_tests.cmake")
else()
  add_test(my_test_NOT_BUILT my_test_NOT_BUILT)
endif()
