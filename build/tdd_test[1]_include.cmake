if(EXISTS "/home/boriss/Documents/VUT FIT/IVS/proj1/build/tdd_test[1]_tests.cmake")
  include("/home/boriss/Documents/VUT FIT/IVS/proj1/build/tdd_test[1]_tests.cmake")
else()
  add_test(tdd_test_NOT_BUILT tdd_test_NOT_BUILT)
endif()