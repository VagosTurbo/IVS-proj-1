add_test( EmptyTable.contains [==[/home/boriss/Documents/VUT FIT/IVS/proj1/build/white_box_test]==] [==[--gtest_filter=EmptyTable.contains]==] --gtest_also_run_disabled_tests)
set_tests_properties( EmptyTable.contains PROPERTIES WORKING_DIRECTORY [==[/home/boriss/Documents/VUT FIT/IVS/proj1/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( EmptyTable.get [==[/home/boriss/Documents/VUT FIT/IVS/proj1/build/white_box_test]==] [==[--gtest_filter=EmptyTable.get]==] --gtest_also_run_disabled_tests)
set_tests_properties( EmptyTable.get PROPERTIES WORKING_DIRECTORY [==[/home/boriss/Documents/VUT FIT/IVS/proj1/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( EmptyTable.size [==[/home/boriss/Documents/VUT FIT/IVS/proj1/build/white_box_test]==] [==[--gtest_filter=EmptyTable.size]==] --gtest_also_run_disabled_tests)
set_tests_properties( EmptyTable.size PROPERTIES WORKING_DIRECTORY [==[/home/boriss/Documents/VUT FIT/IVS/proj1/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( NonEmptyTable.contains [==[/home/boriss/Documents/VUT FIT/IVS/proj1/build/white_box_test]==] [==[--gtest_filter=NonEmptyTable.contains]==] --gtest_also_run_disabled_tests)
set_tests_properties( NonEmptyTable.contains PROPERTIES WORKING_DIRECTORY [==[/home/boriss/Documents/VUT FIT/IVS/proj1/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( NonEmptyTable.get [==[/home/boriss/Documents/VUT FIT/IVS/proj1/build/white_box_test]==] [==[--gtest_filter=NonEmptyTable.get]==] --gtest_also_run_disabled_tests)
set_tests_properties( NonEmptyTable.get PROPERTIES WORKING_DIRECTORY [==[/home/boriss/Documents/VUT FIT/IVS/proj1/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( NonEmptyTable.size [==[/home/boriss/Documents/VUT FIT/IVS/proj1/build/white_box_test]==] [==[--gtest_filter=NonEmptyTable.size]==] --gtest_also_run_disabled_tests)
set_tests_properties( NonEmptyTable.size PROPERTIES WORKING_DIRECTORY [==[/home/boriss/Documents/VUT FIT/IVS/proj1/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( white_box_test_TESTS EmptyTable.contains EmptyTable.get EmptyTable.size NonEmptyTable.contains NonEmptyTable.get NonEmptyTable.size)
