add_test( BasicTests.TableConstructor [==[/home/boriss/Documents/VUT FIT/IVS/proj1/build/white_box_test]==] [==[--gtest_filter=BasicTests.TableConstructor]==] --gtest_also_run_disabled_tests)
set_tests_properties( BasicTests.TableConstructor PROPERTIES WORKING_DIRECTORY [==[/home/boriss/Documents/VUT FIT/IVS/proj1/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( white_box_test_TESTS BasicTests.TableConstructor)
