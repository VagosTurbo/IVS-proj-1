if(EXISTS "/home/boriss/Documents/VUT FIT/IVS/proj1/build/white_box_test[1]_tests.cmake")
  include("/home/boriss/Documents/VUT FIT/IVS/proj1/build/white_box_test[1]_tests.cmake")
else()
  add_test(white_box_test_NOT_BUILT white_box_test_NOT_BUILT)
endif()
